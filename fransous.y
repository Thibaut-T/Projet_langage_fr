%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <string>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);
  
  map<string,double> variables ;

  class maClasse{
  public: 
    maClass (const string &t="", const string &n="", const double &v=0) {type = t; nom = n; valeur = v;};  
    string type;
    string nom;
    double valeur;
  };

  vector <maClasse> uneClasse;    

  int add_paramClass(const string &t="", const string &n="", const double &v=0) {
      uneClasse.push_back(maClasse(t,n,v)); 
      return 0; 
   }; 
%}

%union {
  double valeur;
  char nom[50];
}

%token classe
%token <valeur> NUM
%token <nom> VAR
%type <valeur> expr 
%token DACCOLADE
%token FACCOLADE

%left '+' '-'
%left '*' '/

%%
bloc:  /* Epsilon */
     | bloc classe '\n'   

classe:   /* Epsilon, ligne vide */
            DACCOLADE { }
            | '(' expr expr expr ')' '\n' { }
              bloc
            FACCOLADE { }

expr:

%%

string print_code(int ins) {
  switch (ins) {
    case ADD      : return "ADD";
    case MULT     : return "MUL";    
    case NUM      : return "NUM";
    case VAR      : return "VAR";
    default : return "";
  }
}

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

int main(int argc, char **argv) {
  printf("Calculette V1.0\n");

  // Code pour traiter un fichier au lieu de l'entrée clavier
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();	

  return 0;
}