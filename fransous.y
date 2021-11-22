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

    map<string,double> variables;
    map<double, string> variablesString;
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
    } type_adresse;
  }

%union {
  double valeur;
  char nom[50];
  type_adresse adresse;  
}

%token <valeur> NUM
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
%token SWITCH
%token ENDSWITCH
%token <adresse> CASE
%token BREAK
%token EXP
%token SQRT
%token POW
%token OPENFR
%token OPENFW
%token SUPPR
%token NEWNAME
%token TOLOWER
%token FIRST
%token LAST
%token SIZE
%token WAIT
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


%token ADD
%token SUB
%token MULT
%token DIV

%right ADD SUB   // N'oubliez pas de remettre left !
%left MULT DIV

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
        | case {$1.jmp = ic-1;}
        CASE expr SEPARATOR {add_instruction(EGAL);
                            $3.jc = ic; 
                            add_instruction(JMPCOND);}
        instruction 
        BREAK '\n' { code_genere[$3.jc].value = ic;
                    add_instruction(VARID, 0, code_genere[$1.jmp].name);}

instruction: {}
        | expr         { }
        | fonction     { }
        | VAR '=' expr { add_instruction(ASSIGN, 0, $1); }

        
        | GOTO LABEL   {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, $2); 
                        }
        |IF condition separateur {$1.jc = ic; add_instruction(JMPCOND); }
        THEN separateur
        lignes            { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
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
                                                              code_genere[$1.jc].value = ic;}
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
                                                                add_instruction(INF);
                                                                $1.jc = ic;
                                                                add_instruction(JMPCOND);}
            lignes
        ENDFOR                                          {add_instruction(JMP);
                                                              code_genere[ic-1].value = $1.jmp;
                                                              code_genere[$1.jc].value = ic;}
        
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
        WHILE condition                                { add_instruction(NON);
                                                         add_instruction(JMPCOND, $1.jc);}
        |FOREACH expr
          lignes
        ENDFOR
        |SWITCH expr separateur
            case
        ENDSWITCH
expr: NUM {add_instruction (NUM, $1); } 
     |VARAPO {add_instruction(VARAPO, 0, $1);}
     |VAR {add_instruction (VAR, 0, $1); }
     |VRAI {$$ = true; }
     |FAUX {$$  = false; }
     |SIN '(' expr ')'  {add_instruction(SIN);/*$$ = sin($3); printf ("sin(%g) = %g\n", $3, $$ );*/ }
     |COS '(' expr ')'  {add_instruction(COS);/*$$ = cos($3); printf ("cos(%g) = %g\n", $3, $$ );*/  }
     |TAN '(' expr ')'  {add_instruction(TAN);/*$$ = tan($3); printf ("tan(%g) = %g\n", $3, $$ );*/ }    
     |EXP '('expr ')'   {add_instruction(EXP);/*$$ = exp($3); printf ("exp(%g) = %g\n", $3, $$ );*/ }
     |SQRT '(' expr ')' {add_instruction(SQRT);/*$$ = sqrt($3); printf ("sqrt(%g) = %g\n", $3, $$ );*/ }
     |POW '('expr ',' expr')' {add_instruction(POW);}
     | '(' expr ')'      { $$ = $2; }
     |expr ADD expr {add_instruction(ADD); } 
     |expr SUB expr {add_instruction(SUB); } 
     |expr MULT expr {add_instruction(MULT); }
     |expr DIV expr { add_instruction(DIV); }

    
fonction : OPENFR expr {add_instruction(OPENFR);}
        |OPENFW expr {add_instruction(OPENFW);}
        |SUPPR expr DANS expr JUSQUE expr {add_instruction(SUPPR);}
        |NEWNAME expr EN expr{add_instruction(NEWNAME);}
        |TOLOWER VAR {add_instruction(TOLOWER);}
        |FIRST DE VAR {add_instruction(FIRST);}
        |LAST DE VAR {add_instruction(LAST);}
        |SIZE DE VAR {add_instruction(SIZE);}
        |WAIT VAR {add_instruction(WAIT);}
        |PRINT expr   { add_instruction(PRINT); }



condition  : expr
          |expr SUP expr {add_instruction(SUP);}
          |expr INF expr {add_instruction(INF);}
          |expr SUPEG expr {add_instruction(SUPEG);}
          |expr INFEG expr {add_instruction(INFEG);}
          |expr DIFF expr {add_instruction(DIFF);}
          |expr EGAL expr {add_instruction(EGAL);}
          |NON '('condition')' {add_instruction(NON);}

var : {}
%%


int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}



// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
    case ADD      : return "ADD"; break;
    case SUB      : return "SUB"; break;
    case MULT     : return "MUL"; break;
    case DIV      : return "DIV"; break;
    case NUM      : return "NUM"; break;
    case VAR      : return "VAR"; break;
    case VARID    : return "VARID"; break;
    case VARAPO   : return "VARAPO"; break;
    case PRINT    : return "PRINT"; break;
    case ASSIGN   : return "MOV"; break;
    case JMP      : return "JMP"; break;
    case JMPCOND  : return "JC "; break;
    case INF      : return "INF"; break;
    case SUP      : return "SUP"; break;
    case SUPEG    : return "SUPEG"; break;
    case INFEG    : return "INFEG"; break;
    case EGAL     : return "EGAL"; break;
    case DIFF     : return "DIFF"; break;
    case NON      : return "NON"; break;
    case OPENFR   : return "OPENFR"; break;
    case OPENFW   : return "OPENFW"; break;
    case TOLOWER  : return "TOLOWER"; break;
    case FIRST    : return "FIRST"; break;
    case LAST     : return "LAST"; break;
    case SIZE     : return "SIZE"; break;
    case SIN      : return "SIN"; break;
    case COS      : return "COS"; break;
    case TAN      : return "TAN"; break;
    case EXP      : return "EXP"; break;
    case POW      : return "POW"; break;
    case SQRT     : return "SQRT"; break;
    default : return ""; break;
  }
}

// Fonction qui exécute le code généré sur un petit émulateur
void execution ( const vector <instruction> &code_genere, 
                 map<string,double> &variables )
{
  printf("\n------- Exécution du programme ---------\n");
  stack<double> pile;

  int ic = 0;  // compteur instruction
  double r1, r2, r3;  // des registres
  char r4[50], r5[50];


  printf("C'est quoi la réponse à la grande question sur la vie, l'univers et le reste ?\n");

  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
    auto ins = code_genere[ic];
    switch (ins.code){
      case OPENFR :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        fopen(r4,"r");
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        ic++;
      break;
      case OPENFW :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        fopen(r4,"w");
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        ic++;
      break;
      /*case SUPPR :
        r1=pile.top();
        pile.pop();
        r2=pile.top();
        pile.pop();
        r3=pile.top();
        pile.pop();
        remove(r3,r2,r1); /*Enleve "A" dans camion jusque M*/
        /*ic++;
      break;*/
      case NEWNAME :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        r2=pile.top();
        pile.pop();
        strcpy(r5, variablesString[r2].c_str());
        rename(r5,r4);
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        variables.erase( variables.find(variablesString[r2]));
        variablesString.erase( variablesString.find(r2));
        ic++;
      break;
      /*case TOLOWER :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        variablesString[r1] = tolower(r4);
        ic++;
      break;
      case FIRST :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        front(r4);
        ic++;
      break;

      case LAST :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        back(r4);
        ic++;
      break;
      case SIZE : 
        r1=pile.top();
        pile.pop();
        size(r1);
        ic++;
      break;
      case WAIT :
        r1=pile.top();
        pile.pop();
        wait(r1);
        ic++;
      break;*/
      case ADD:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1+r2);
        ic++;
      break;
      case SUB:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2-r1);
        ic++;
      break;
      case MULT:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1*r2);
        ic++;
      break;
      case DIV:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2/r1);
        ic++;
      break;
      case ASSIGN:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();
        variables[ins.name] = r1;
        ic++;
      break;

      case PRINT:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();
        cout << "$ " << r1 << endl; 
        ic++;
      break;

      case NUM:   // pour un nombre, on empile
        pile.push(ins.value);
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
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();
        if ( r1 != 0 ) 
          ic++;
        else 
          ic = (int)ins.value;             
      break;

      case VAR:    // je consulte la table de symbole et j'empile la valeur de la VARS
          // Si elle existe bien sur... 
        try {
            pile.push(variables.at(ins.name));
            ic++;
        }
        catch(...) {
            variables[ins.name] = 0;
            pile.push(variables.at(ins.name));
            ic++;
        }
      break;
      case VARID:
            pile.push(variables[ins.name]);
            ic++;
      break;
      case VARAPO:
        r1 = variablesString.size();
        variables[ins.name] = r1;
        variablesString[r1] = ins.name;
        pile.push(variables.at(ins.name));
        ic++;
      break;
      case SUP:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2>r1);
        ic++;
      break;
      case SUPEG:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2>=r1);
        ic++;
      break;
      case INF:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2<r1);
        ic++;
      break;
      case INFEG:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2<=r1);
        ic++;
      break;
      case EGAL:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1==r2);
        ic++;
      break;
      case DIFF:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1!=r2);
        ic++;
      break;
      case NON:
        r1 = pile.top();
        pile.pop();

        pile.push(!r1);
        ic++;
      break;
      case SIN:
        r1 = pile.top();
        pile.pop();
        pile.push(sin(r1));
        ic++;
      break;
      case COS:
        r1 = pile.top();
        pile.pop();
        pile.push(cos(r1));
        cout << "$ cos(" << r1 << ") = " << cos(r1) << " : " << pile.top() << "\n";
        ic++;
      break;
      case TAN: 
        r1 = pile.top();
        pile.pop();
        pile.push(tan(r1));
        ic++;
      break;
      case EXP:
        r1 = pile.top();
        pile.pop();
        pile.push(exp(r1));
        ic++;
      break;
      case POW:
        r1 = pile.top();
        pile.pop();
        r2 = pile.top();
        pile.pop();
        pile.push(pow(r2, r1));
        ic++;
      break;
      case SQRT:
        r1 = pile.top();
        pile.pop();
        pile.push(sqrt(r1));
        ic++;
      break;
    }
  }
}










int main(int argc, char **argv){

  yyin = (argc > 1) ? fopen(argv[1], "r") : stdin;

  yyparse();

  for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    cout << i 
         << '\t'
         << print_code(instruction.code) 
         << '\t'
         << instruction.value 
         << '\t' 
         << instruction.name 
         << endl;
  }

  execution(code_genere, variables);

  return 0;
}
