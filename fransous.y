%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include <string.h>
    #include <algorithm>
    #include <cmath>   
    #include <map>
    #include <vector>
    #include <iostream>
    #include <stack>
    #include <tuple>
    #include <sstream>

    using namespace std;

    extern int yylex ();
    extern char* yytext;
    extern FILE* yyin;
    int yyerror(char *s);

    class instruction{
        public:
        instruction (const int &c, const double &v=0, const string &n="") {code = c; value = v; name = n;};  
        int code; 
        double value;     // éventuellement une valeur si besoin
        string name;      // ou une référence pour la table des données 
    };


    map<string,tuple<int, double, string>> variables;
    map<string, vector<tuple<int, double, string>>> variablesTables;


    vector<vector<double>> adresseBreak;
    vector<double> breakN;

    int ic = 0;
    map<string,int> adresses;
    vector <instruction> code_genere;

    int add_instruction(const int &c, const double &v=0, const string &n="") {
        code_genere.push_back(instruction(c,v,n)); 
        ic++;
        return 0; 
    }; 
%}

%code requires
  {
    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
        int save;
    } type_adresse;
  }

%union {
  double valeur;
  char nom[50];
  type_adresse adresse;  
}

%token <valeur> NUM
%token <valeur> NUMNEG
%token <nom> VAR
%token VARID
%type <valeur> expr 
%type <valeur> condition 
%type <adresse> case
%token <adresse> SI
%token GOTO
%token <nom> LABEL
%token JMP
%token JMPCOND
%token ASSIGN
%token <adresse> IF
%token THEN
%token ELSE
%token ENDIF
%token <adresse> FOR
%token <adresse> FOREACH
%token ENDFOR
%token AND
%token BETWEEN
%token FONCTION
%token DECR
%token INCR
%token PRINT
%token SIN
%token COS
%token TAN
%token SEPARATOR
%token <adresse> WHILE
%token ENDWHILE
%token <adresse> DO
%token ENDDO
%token SWITCH
%token ENDSWITCH
%token <adresse> CASE
%token DEFAULT
%token BREAK
%token EXP
%token SQRT
%token POW
%token SUPPR
%token TOLOWER
%token TOLOWERVAR
%token TOLOWERVARAPO
%token UPPER
%token UPPERVAR
%token UPPERVARAPO
%token FIRST
%token LAST
%token SIZE
%token <nom>VARAPO
%token VRAI
%token FAUX
%token INF
%token SUP
%token INFEG
%token SUPEG
%token EGAL
%token DIFF
%token NON
%token commentaire
%token DANS
%token DE
%token JUSQUE
%token EN
%token INCREMENTER
%token DECREMENTER
%token ORCOND
%token ANDCOND
%token CONCAT
%token ENDL


%token TAB
%token TABADD
%token A
%token INDICE
%token ASSIGNINDICE

%token ADD
%token SUB
%token MULT
%token DIV
%token MOD

%left ADD SUB
%left MULT DIV MOD

%%
lignes:{ }
     | lignes label instruction '\n'

label : // Epsilon
      | LABEL ':'  { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [$1] = ic;}

separateur : SEPARATOR '\n'


case : {}
        | case DEFAULT SEPARATOR instruction BREAK '\n' { breakN.push_back(ic);
                                                          add_instruction(JMP);
                                                        }
        | case {$1.save = ic-1;}
        CASE expr SEPARATOR {add_instruction(EGAL);
                            $3.jc = ic; 
                            add_instruction(JMPCOND);}
        instruction 
        BREAK '\n' {breakN.push_back(ic) ;
                    add_instruction(JMP);
                    code_genere[$3.jc].value = ic;
                    add_instruction(VARID, 0, code_genere[$1.save].name);}

instruction: {}
        | expr         { }
        | fonction     { }
        | TAB VAR {add_instruction(TAB, 0, $2);}
        | VAR '=' expr { add_instruction(ASSIGN, 0, $1); }
        | INDICE expr DE VAR '=' expr {add_instruction(ASSIGNINDICE, 0, $4);}
        | FONCTION '(' VAR ')' separateur { add_instruction(FONCTION); }
        | GOTO LABEL   {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, $2); 
                        }
        |IF condition separateur {$1.jc = ic; add_instruction(JMPCOND); }
        THEN separateur
        lignes            { // Je sauvegarde l'endroit actuel pour revenir modifier l'adresse 
                          // lorsqu'elle sera connue (celle du JMP)
                          $1.jmp = ic;
                          add_instruction(JMP);
                          // Je mets à jour l'adresse du saut conditionnel
                          code_genere[$1.jc].value = ic;
                        }
        ELSE separateur
        lignes 
        ENDIF           { // Je mets à jour l'adresse du saut inconditionnel
                        code_genere[$1.jmp].value = ic;} 
        |FOR VAR BETWEEN NUM AND NUM INCR NUM separateur { add_instruction(VAR, 0, $2);
                                                                add_instruction(NUM, $4);
                                                                add_instruction(NUM, $8);
                                                                add_instruction(SUB);
                                                                add_instruction(ASSIGN, 0, $2);

                                                                $1.jmp = ic;
                                                                add_instruction(VAR, 0, $2);
                                                                add_instruction(NUM, $8);
                                                                add_instruction(ADD);
                                                                add_instruction(ASSIGN, 0, $2);
                                                                add_instruction(VAR, 0, $2);
                                                                add_instruction(NUM, $6);
                                                                add_instruction(INF);
                                                                $1.jc = ic;
                                                                add_instruction(JMPCOND);}
            lignes
        ENDFOR                                          {add_instruction(JMP);
                                                              code_genere[ic-1].value = $1.jmp;
                                                              code_genere[$1.jc].value = ic;
                                                              add_instruction(SUPPR, 0, $2);}
        |FOR VAR BETWEEN NUM AND NUM DECR NUM separateur { add_instruction(VAR, 0, $2);
                                                            add_instruction(NUM, $4);
                                                            add_instruction(NUM, $8);
                                                            add_instruction(ADD);
                                                            add_instruction(ASSIGN, 0, $2);

                                                            $1.jmp = ic;
                                                            add_instruction(VAR, 0, $2);
                                                            add_instruction(NUM, $8);
                                                            add_instruction(SUB);
                                                            add_instruction(ASSIGN, 0, $2);
                                                            add_instruction(VAR, 0, $2);
                                                            add_instruction(NUM, $6);
                                                            add_instruction(SUP);
                                                            $1.jc = ic;
                                                            add_instruction(JMPCOND);}
            lignes
        ENDFOR                                          {add_instruction(JMP);
                                                              code_genere[ic-1].value = $1.jmp;
                                                              code_genere[$1.jc].value = ic;
                                                              add_instruction(SUPPR, 0, $2);}
        
        |WHILE                                        { $1.jmp = ic;}
          condition separateur                        {$1.jc = ic;
                                                        add_instruction(JMPCOND);
                                                      }
            lignes                                    { add_instruction(JMP, $1.jmp);
                                                        code_genere[$1.jc].value = ic;
                                                      }
        ENDWHILE                 
        |DO separateur                                {$1.jc = ic;}
          lignes
        ENDDO '\n'
        WHILE condition                               { add_instruction(NON);
                                                        add_instruction(JMPCOND, $1.jc);}
        
        |FOREACH VAR DE VAR separateur                { add_instruction(VAR, 0, "1");
                                                        add_instruction(VAR, 0, $2);
                                                        $1.jmp = ic;
                                                        add_instruction(VAR, 0, "1");
                                                        add_instruction(SIZE, 0, $4);
                                                        add_instruction(INF);
                                                        $1.jc = ic;
                                                        add_instruction(JMPCOND);
                                                        add_instruction(VAR, 0, "1");
                                                        add_instruction(NUM, 1);
                                                        add_instruction(ADD);
                                                        add_instruction(ASSIGN, 0, "1");
                                                        add_instruction(VAR, 0, "1");
                                                        add_instruction(INDICE, 0, $4);
                                                        add_instruction(ASSIGN, 0, $2);
                                                      }
          lignes
        ENDFOR                                        { add_instruction(JMP);
                                                        code_genere[ic-1].value = $1.jmp;
                                                        code_genere[$1.jc].value = ic;
                                                        add_instruction(SUPPR, 0, $2);
                                                        add_instruction(SUPPR, 0, "1");
                                                      }
        |SWITCH expr separateur                       { if(!breakN.empty()){
                                                          adresseBreak.push_back(breakN);
                                                          breakN.clear();
                                                        }}
            case
        ENDSWITCH                                     {for(auto itr : breakN){
                                                          code_genere[itr].value = ic;
                                                        }
                                                        breakN.clear();
                                                        if(!adresseBreak.empty()){
                                                          breakN = adresseBreak.back();
                                                          adresseBreak.pop_back();
                                                        } 
                                                      }
expr: NUM {add_instruction (NUM, $1);}
     |VARAPO {add_instruction(VARAPO, 0, $1);}
     |VAR {add_instruction (VAR, 0, $1); }
     |VRAI {add_instruction (NUM, true);} 
     |FAUX {add_instruction (NUM, false);} 
     |SIN '(' expr ')'  {add_instruction(SIN);}
     |COS '(' expr ')'  {add_instruction(COS);}
     |TAN '(' expr ')'  {add_instruction(TAN);}
     |EXP '('expr ')'   {add_instruction(EXP);}
     |SQRT '(' expr ')' {add_instruction(SQRT);}
     |POW '('expr ',' expr')' {add_instruction(POW);}
     | '(' expr ')'      { $$ = $2;}
     |expr MOD expr {add_instruction(MOD);}
     |expr ADD expr {add_instruction(ADD);} 
     |expr SUB expr {add_instruction(SUB);} 
     | SUB expr {add_instruction(NUM, -1); add_instruction(MULT);}
     |expr MULT expr {add_instruction(MULT);}
     |expr DIV expr {add_instruction(DIV);}
     |INCREMENTER VAR {add_instruction(VAR, 0, $2); 
                       add_instruction(NUM, 1); 
                       add_instruction(ADD); 
                       add_instruction(ASSIGN, 0, $2);}
     |DECREMENTER VAR {add_instruction(VAR, 0, $2); 
                       add_instruction(NUM, 1); 
                       add_instruction(SUB);
                       add_instruction(ASSIGN, 0, $2);}
      |TABADD expr A VAR {add_instruction(TABADD, 0, $4);}
      |INDICE expr DE VAR {add_instruction(INDICE, 0, $4);}
      |SUPPR INDICE expr DE VAR {add_instruction(SUPPR, 1, $5);}
      |SUPPR VAR {add_instruction(SUPPR, 0, $2);}
      |TOLOWER VAR {add_instruction(TOLOWERVAR, 0, $2);}
      |TOLOWER VARAPO {add_instruction(TOLOWERVARAPO, 0, $2);}
      |UPPER VAR {add_instruction(UPPERVAR, 0, $2);}
      |UPPER VARAPO {add_instruction(UPPERVARAPO, 0, $2);}
      |FIRST VAR {add_instruction(FIRST, 0, $2);}
      |FIRST VARAPO {add_instruction(FIRST, 0, $2);}
      |LAST VAR {add_instruction(LAST, 0, $2);}
      |LAST VARAPO {add_instruction(LAST, 0, $2);}
      |SIZE VAR {add_instruction(SIZE, 0, $2);}
      |ENDL {add_instruction(ENDL);}
      |CONCAT expr AND expr DANS VAR { add_instruction(CONCAT); add_instruction(ASSIGN, 0, $6);}

    
fonction :
          PRINT condition concatenation {add_instruction(PRINT);}


concatenation : {}
              | concatenation AND condition {add_instruction(CONCAT);}




condition  : expr
          |expr SUP expr {add_instruction(SUP);}
          |expr INF expr {add_instruction(INF);}
          |expr SUPEG expr {add_instruction(SUPEG);}
          |expr INFEG expr {add_instruction(INFEG);}
          |expr DIFF expr {add_instruction(DIFF);}
          |expr EGAL expr {add_instruction(EGAL);}
          |NON '('condition')' {add_instruction(NON);}
          |'('condition ORCOND condition')' {add_instruction(ORCOND);}
          |'('condition ANDCOND condition')' {add_instruction(ANDCOND);}
%%


int yyerror(char *s) {					
    printf("%s : \"%s\"\n", s, yytext);
}



// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
/*  switch (ins) {
    case SUPPR    : return "SUPPR"; break;
    case MOD      : return "MOD"; break;
    case ADD      : return "ADD"; break;
    case SUB      : return "SUB"; break;
    case MULT     : return "MULT"; break;
    case DIV      : return "DIV"; break;
    case NUM      : return "NUM"; break;
    case VAR      : return "VAR"; break;
    case VARID    : return "VARID"; break;
    case VARAPO   : return "VARAPO"; break;
    case PRINT    : return "PRINT"; break;
    case ASSIGN   : return "ASSIGN"; break;
    case JMP      : return "JMP"; break;
    case JMPCOND  : return "JC "; break;
    case INF      : return "INF"; break;
    case SUP      : return "SUP"; break;
    case SUPEG    : return "SUPEG"; break;
    case INFEG    : return "INFEG"; break;
    case EGAL     : return "EGAL"; break;
    case DIFF     : return "DIFF"; break;
    case NON      : return "NON"; break;
    case ANDCOND  : return "ANDCOND"; break;
    case ORCOND   : return "ORCOND"; break;
    case TOLOWERVAR  : return "TOLOWERVAR"; break;
    case TOLOWERVARAPO  : return "TOLOWERVARAPO"; break;
    case UPPERVAR : return "UPPERVAR"; break;
    case UPPERVARAPO : return "UPPERVARAPO"; break;
    case FIRST    : return "FIRST"; break;
    case LAST     : return "LAST"; break;
    case SIZE     : return "SIZE"; break;
    case SIN      : return "SIN"; break;
    case COS      : return "COS"; break;
    case TAN      : return "TAN"; break;
    case EXP      : return "EXP"; break;
    case POW      : return "POW"; break;
    case SQRT     : return "SQRT"; break;
    case FONCTION : return "FUN"; break;
    case TAB      : return "TAB"; break;
    case TABADD   : return "TADADD"; break;
    case INDICE   : return "INDICE"; break;
    case ASSIGNINDICE : return "ASSIGNINDICE"; break;
    case CONCAT   : return "CONCAT"; break;
    case ENDL     : return "ENDL"; break;
    default : return ""; break;
  }*/
}

// Fonction qui exécute le code généré sur un petit émulateur
void execution ( const vector <instruction> &code_genere, 
                 map<string,tuple<int, double, string>> &variables, map<string, vector<tuple<int, double, string>>> &variablesTables )
{
  printf("\n------- Exécution du programme ---------\n");
  stack<tuple<int, double, string>> pile;

  int ic = 0;  // compteur instruction
  int type1 = 0, type2 = 0;
  double r1, r2, r3;  // des registres
  string r6, r7;
  stringstream r8;

  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
    auto ins = code_genere[ic];
    switch (ins.code){
      case SUPPR :

        if(ins.value == 0 && variables.find(ins.name) != variables.end()){
          variables.erase(variables.find(ins.name));
        }
        else if(ins.value == 1 && variablesTables.find(ins.name) != variablesTables.end()){
          type1 = get<0>(pile.top());
          r1 = get<1>(pile.top())-1;
          pile.pop();
          if(type1 == 1) variablesTables[ins.name].erase(variablesTables[ins.name].begin()+r1);
        }

        ic++;
      break;
      case TOLOWERVAR :
        if(variables.find(ins.name) != variables.end()){
          r6 = get<2>(variables[ins.name]);
          for_each(r6.begin(), r6.end(), [](char & c) {
            c = tolower(c);
          });
          variables[ins.name] = make_tuple(-1, 0, r6);
        }
        ic++; 
      break;
      case TOLOWERVARAPO :
        r6 = ins.name.substr(1,ins.name.size()-2);
        for_each(r6.begin(), r6.end(), [](char & c) {
          c = tolower(c);
        });
        pile.push(make_tuple(-1, 0, r6));
        ic++; 
      break;
      case UPPERVAR :
        if(variables.find(ins.name) != variables.end()){
          r6 = get<2>(variables[ins.name]);
          for_each(r6.begin(), r6.end(), [](char & c) {
            c = toupper(c);
          });
          variables[ins.name] = make_tuple(-1, 0, r6);
        }
        ic++; 
      break;
      case UPPERVARAPO :
          r6 = ins.name.substr(1,ins.name.size()-2);
          for_each(r6.begin(), r6.end(), [](char & c) {
            c = toupper(c);
          });
          pile.push(make_tuple(-1, 0, r6));
        ic++; 
      break;

      case FIRST :
        if(variablesTables.find(ins.name) != variablesTables.end()) pile.push(variablesTables[ins.name].front());
        else if(variables.find(ins.name) != variables.end()){
          type1 = get<0>(variables[ins.name]);
          r6 = get<2>(variables[ins.name]);
          if(type1 == -1) pile.push(make_tuple(-1, 0, r6.substr(0,1)));
        }
        else pile.push(make_tuple(-1, 0, ins.name.substr(1,1)));

        ic++;
      break;
      case LAST :
        if(variablesTables.find(ins.name) != variablesTables.end()) pile.push(variablesTables[ins.name].back());
        else if(variables.find(ins.name) != variables.end()){
          type1 = get<0>(variables[ins.name]);
          r6 = get<2>(variables[ins.name]);
          if(type1 == -1) pile.push(make_tuple(-1, 0, r6.substr(r6.size()-1,1)));
        }
        else  pile.push(make_tuple(-1, 0, ins.name.substr(ins.name.size()-2, 1)));

        ic++;
      break;
      case SIZE :
        if(variablesTables.find(ins.name) != variablesTables.end()){
            pile.push(make_tuple(1,variablesTables[ins.name].size(), ""));
            ic++;
          }
        else if(variables.find(ins.name) != variables.end()){
            pile.push(make_tuple(1, get<2>(variables.at(ins.name)).size(), ""));
            ic++;
         }
        else{
          cout << ins.name << " non déclaré.\n";
          ic = code_genere.size();
        }
      break;
      case ADD:
        if(get<0>(pile.top()) == 1) r1=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        if(get<0>(pile.top()) == 1) r2=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r1+r2,""));
        ic++;
      break;
      case MOD:
        if(get<0>(pile.top()) == 1) r1=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        if(get<0>(pile.top()) == 1) r2=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,(int)round(r2)%(int)round(r1),""));
        ic++;
      break;
      case SUB:
        if(get<0>(pile.top()) == 1) r1=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        if(get<0>(pile.top()) == 1) r2=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r2-r1,""));
        ic++;
      break;
      case MULT:
        if(get<0>(pile.top()) == 1) r1=get<1>(pile.top());   // Rrécupérer la tête de pile;
        pile.pop();

        if(get<0>(pile.top()) == 1) r2=get<1>(pile.top());   // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r1*r2,""));
        ic++;
      break;
      case DIV:
        if(get<0>(pile.top()) == 1) r1=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        if(get<0>(pile.top()) == 1) r2=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r2/r1,""));
        ic++;
      break;
      case ASSIGN:
        type1 = get<0>(pile.top());
        r1 = get<1>(pile.top());
        r6 = get<2>(pile.top());
        pile.pop();

        variables[ins.name] = make_tuple(type1, r1, r6);
        ic++;
      break;

      case PRINT:
        type1 = get<0>(pile.top());
        r1 = get<1>(pile.top());
        r6 = get<2>(pile.top());

        pile.pop();
        if(type1 == 1) cout << "$ " << r1 << endl; 
        else cout << "$ " << r6 << endl;
        ic++;
      break;
      case CONCAT :
        if(get<0>(pile.top()) == 1){
          r8 << get<1>(pile.top());
          r6 = r8.str();
          r8.str("");
        }
        else r6 = get<2>(pile.top());
        pile.pop();
        
        if(get<0>(pile.top()) == 1){
          r8 << get<1>(pile.top());
          r7 = r8.str();
          r8.str("");
        } 
        else r7 = get<2>(pile.top());
        pile.pop();

        pile.push(make_tuple(-1, 0, r7 + r6));
        ic++;
      break;
      case ENDL:
        pile.push(make_tuple(-1, 0, "\n$ "));
        ic++;
      break;

      case NUM:   // pour un nombre, on empile
        pile.push(make_tuple(1,ins.value, ""));
        ic++;
      break;

      case JMP:
        if (ins.value != -999) // Est-ce un GoTo ?
          ic = ins.value;
        else
          // je récupère l'adresse à partir de la table
          ic = adresses[ins.name];
      break;

      case JMPCOND: 
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();
        if ( r1 != 0 ) 
          ic++;
        else 
          ic = (int)ins.value;             
      break;

      case VAR:    // je consulte la table de symbole et j'empile la valeur de la VARS
        if(variables.find(ins.name) == variables.end()){
          variables[ins.name] = make_tuple(1,0,"");
        }
        pile.push(variables.at(ins.name));
        ic++;
      break;
      case VARID:
        pile.push(variables[ins.name]);
        ic++;
      break;
      case VARAPO:
        pile.push(make_tuple(-1, 0, ins.name.substr(1,ins.name.size()-2)));
        ic++;
      break;
      case SUP:
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r2>r1, ""));
        ic++;
      break;
      case SUPEG:
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r2>=r1, ""));
        ic++;
      break;
      case INF:
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r2<r1, ""));
        ic++;
      break;
      case INFEG:
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r2<=r1, ""));
        ic++;
      break;
      case EGAL:
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r1==r2, ""));
        ic++;
      break;
      case DIFF:
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r1!=r2, ""));
        ic++;
      break;
      case NON:
        r1 = get<1>(pile.top());
        pile.pop();

        pile.push(make_tuple(1,!r1, ""));
        ic++;
      break;
      case ANDCOND:
        r1 = get<1>(pile.top());
        pile.pop();
        r2 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,r1 && r2, ""));
        ic++;
      break;
      case ORCOND:
        r1 = get<1>(pile.top());
        pile.pop();
        r2 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,r1 || r2, ""));
        ic++;
      break;
      case SIN:
        r1 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,sin(r1), ""));
        ic++;
      break;
      case COS:
        r1 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,cos(r1), ""));
        ic++;
      break;
      case TAN: 
        r1 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,tan(r1), ""));
        ic++;
      break;
      case EXP:
        r1 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,exp(r1), ""));
        ic++;
      break;
      case POW:
        r1 = get<1>(pile.top());
        pile.pop();
        r2 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,pow(r2, r1), ""));
        ic++;
      break;
      case SQRT:
        r1 = get<1>(pile.top());
        pile.pop();
        pile.push(make_tuple(1,sqrt(r1), ""));
        ic++;
      break;
      case TAB : 
        variablesTables[ins.name];
        ic++;
      break;
      case TABADD:
        type1 = get<0>(pile.top());
        r1 = get<1>(pile.top());
        r6 = get<2>(pile.top());
        pile.pop();
        if(variablesTables.find(ins.name) != variablesTables.end()){
          variablesTables[ins.name].push_back(make_tuple(type1, r1, r6));
          ic++;
        }
        else{
          cout << "Tableau non déclaré.\n";
          ic = code_genere.size();
        }
      break;
      case INDICE:
        r1 = get<1>(pile.top()) - 1;
        pile.pop();
        if(variablesTables.find(ins.name) != variablesTables.end()){
          pile.push(variablesTables[ins.name].at(r1));
          ic++;
        }
        else{
          cout << "Tableau " << ins.name << " non déclaré.\n";
          ic = code_genere.size();
        }
      break;
      case ASSIGNINDICE :
        type1 = get<0>(pile.top());
        r1 = get<1>(pile.top());
        r6 = get<2>(pile.top());
        pile.pop();

        type2 = get<0>(pile.top());
        r2 = get<1>(pile.top())-1;
        pile.pop();

        if(variablesTables.find(ins.name) != variablesTables.end()){
          if(r2 < variablesTables[ins.name].size()){
            variablesTables[ins.name].at(r2) = make_tuple(type1,r1,r6);
            ic++;
          }
          else{
            cout << "Impossible d'ajouter à " << ins.name << " un élément à l'indice numéro : " << r2 + 1 << '.\n';
            ic = code_genere.size();
          }
        }
        else{
          cout << ins.name << " non déclaré.\n";
          ic = code_genere.size();
        }
      break;
    }
  }
}










int main(int argc, char **argv){

  yyin = (argc > 1) ? fopen(argv[1], "r") : stdin;

  yyparse();

  execution(code_genere, variables, variablesTables);

  return 0;
}
