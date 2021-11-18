%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string>
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
%type <valeur> expr 
%token <adresse> SI
%token GOTO
%token <nom> LABEL
%token JMP
%token JMPCOND
%token ASSIGN
%token IF
%token THEN
%token ELSE
%token ENDIF
%token FOR
%token ENDFOR
%token PRINT
%token SIN
%token COS
%token TAN
%token SEPARATOR
%token WHILE
%token ENDWHILE
%token SWITCH
%token ENDSWITCH
%token CASE
%token BREAK
%token exp
%token sqrt
%token pow
%token openFileRead
%token openFileWrite
%token remove
%token rename
%token tolower
%token first
%token last
%token size
%token wait
%token VARS
%token VARAPO

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
        | case CASE condition SEPARATOR instruction BREAK '\n'

instruction: {}
        | expr         {  }
        | PRINT expr   { add_instruction(PRINT); }
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

        |FOR expr separateur
            lignes
        ENDFOR
        |WHILE condition separateur
            lignes
        ENDWHILE
        |SWITCH var separateur
            case
        ENDSWITCH
expr: NUM {add_instruction (NUM, $1); } 
     |VARS {}
     |VARAPO {}
     |VAR {add_instruction (VAR, 0, $1); }
     |SIN '(' expr ')'  {$$ = sin($3); printf ("sin(%g) = %g\n", $3, $$ ); }
     |COS '(' expr ')'  {$$ = cos($3); printf ("cos(%g) = %g\n", $3, $$ );  }
     |TAN '(' expr ')'  {$$ = tan($3); printf ("tan(%g) = %g\n", $3, $$ ); }    
     |exp '('expr ')'   {$$ = exp($3); printf ("exp(%g) = %g\n", $3, $$ ); }
     |sqrt '(' expr ')' { $$ = sqrt($3); printf ("sqrt(%g) = %g\n", $3, $$ ); }
     |expr ADD expr {add_instruction(ADD); } 
     |expr SUB expr {add_instruction(SUB); } 
     |expr MULT expr {add_instruction(MULT); }
     |expr DIV expr { add_instruction(DIV); }

    
fonction : openFileRead expr {add_instruction(OPENFR);}
        |openFileWrite expr {add_instruction(OPENFW);}
        |remove expr "dans" expr "jusque" expr {add_instruction(REMOVE);}
        |rename expr "en" expr{add_instruction(RENAME);}
        |tolower VARS {add_instruction(LOWER);}
        |first "de" VARS {add_instruction(FIRST);}
        |last "de" VARS {add_instruction(LAST);}
        |size "de" VARS {add_instruction(SIZE);}
        |wait VARS {add_instruction(WAIT);}



condition  : {}
var : {}
varapo : {}
vars : {}
%%


int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}



// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
    case ADD      : return "ADD";
    case MULT     : return "MUL";    
    case NUM      : return "NUM";
    case VAR      : return "VAR";
    case PRINT    : return "OUT";
    case ASSIGN   : return "MOV";
    case JMP      : return "JMP";
    case JMPCOND  : return "JC ";
    default : return "";
  }
}

// Fonction qui exécute le code généré sur un petit émulateur
void execution ( const vector <instruction> &code_genere, 
                 map<string,double> &variables )
{
printf("\n------- Exécution du programme ---------\n");
stack<int> pile;

int ic = 0;  // compteur instruction
double r1, r2;  // des registres

printf("C'est quoi la réponse à la grande question sur la vie, l'univers et le reste ?\n");

while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
    auto ins = code_genere[ic];
    switch (ins.code){
        case OPENFR :
            r1=pile.top();
            pile.pop();
            fopen(r1,r)
            ic++
            break;
        case OPENFW :
            r1=pile.top();
            pile.pop();
            fopen(r1,w)
            ic++
            break;
        case REMOVE :
            r1=pile.top();
            pile.pop();
            r2=pile.top();
            pile.pop();
            r3=pile.top();
            pile.pop();
            remove(r3,r2,r1);} /*Enleve "A" dans camion jusque M*/
            ic++;
            break;
        case RENAME :
            r1=pile.top();
            pile.pop();
            r2=pile.top();
            pile.pop();
            rename(r1,r2);
            ic++
            break;
        case LOWER :
            r1=pile.top();
            pile.pop();
            tolower(r1);
            ic++
            break;
        case FIRST :
            r1=pile.top();
            pile.pop();
            front(r1);
            ic++
            break;

        case LAST :
            r1=pile.top();
            pile.pop();
            back(r1);
            ic++
            break;
        case SIZE : 
            r1=pile.top();
            pile.pop();
            size(r1);
            ic++
            break;
        case WAIT :
            r1=pile.top();
            pile.pop();
            wait(r1);
            ic++
            break;
        case ADD:
            r1 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            r2 = pile.top();    // Rrécupérer la tête de pile;
            pile.pop();

            pile.push(r1+r2);
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