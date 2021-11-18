%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <cmath>   
  #include <map>
  #include <string>
  #include <algorithm>

  using namespace std;

  extern int yylex ();
  extern char* yytext;
  extern FILE* yyin;
  int yyerror(char *s);

  // Déclaration de la map qui associe
  // les noms des variables à leur valeur
  map<string, float> variables ;

%}

%union {
  float nombre; //Les float
  char texte[50]; //Les string
  bool booleen; //Les bool
  class classe;
}

%token <nombre> NUM
%token <texte> TEXT
%type <nombre> expr 

%token SIN
%token COS
%token FOR
%token VRAI
%token FAUX

%left "plus" "moins"
%left "fois" "divise"
%left '\n'

%%
ligne:  /* Epsilon */
     | ligne instruction '\n' 

instruction : expr { printf("Résultat du calcul : %g\n", $1); }

expr:  NUM               { $$ = $1; }
     | TEXT               { try { 
                                  $$ = variables.at($1);
                               }
                           catch(...){
                               printf ("La variable %s est utilisée mais jamais initialisée\n",$1);
                               variables[$1]=0;
                               $$ = 0.;
                               } 
                          }
     | FOR '(' expr ';' expr ';' expr ')' {printf( "le for marche"); }
     | SIN '(' expr ')'  { $$ = sin($3); printf ("sin(%g) = %g\n", $3, $$ ); }
     | COS '(' expr ')'  { $$ = cos($3); printf ("cos(%g) = %g\n", $3, $$ ); }
     | VRAI {$$ = true; }
     | FAUX {$$  = false; }
     | '(' expr ')'      { $$ = $2; }
     | expr '+' expr     { $$ = $1 + $3; printf ("%g + %g = %g\n", $1, $3, $$ );}
     | expr '-' expr     { $$ = $1 - $3; printf ("%g - %g = %g\n", $1, $3, $$ );}   		
     | expr '*' expr     { $$ = $1 * $3; printf ("%g * %g = %g\n", $1, $3, $$ );}		
     | expr '/' expr     { $$ = $3 / $1; printf ("%g / %g = %g\n", $3, $1, $$ );}
     | expr '=' expr     { $1 = $3; printf ("%g = %g\n", $1, $3);}
%%

int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
}

int main(int argc, char **argv) {
  printf("Test V1.0\n");

  // Code pour traiter un fichier au lieu de l'entrée clavier
  if ( argc > 1 )
    yyin = fopen( argv[1], "r" );
  else
    yyin = stdin;

  yyparse();						

  return 0;
}