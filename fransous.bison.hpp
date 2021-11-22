/* A Bison parser, made by GNU Bison 3.8.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_FRANSOUS_BISON_HPP_INCLUDED
# define YY_YY_FRANSOUS_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 42 "fransous.y"

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
    } type_adresse;
  

#line 57 "fransous.bison.hpp"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    VAR = 259,                     /* VAR  */
    SI = 260,                      /* SI  */
    GOTO = 261,                    /* GOTO  */
    LABEL = 262,                   /* LABEL  */
    JMP = 263,                     /* JMP  */
    JMPCOND = 264,                 /* JMPCOND  */
    ASSIGN = 265,                  /* ASSIGN  */
    IF = 266,                      /* IF  */
    THEN = 267,                    /* THEN  */
    ELSE = 268,                    /* ELSE  */
    ENDIF = 269,                   /* ENDIF  */
    FOR = 270,                     /* FOR  */
    ENDFOR = 271,                  /* ENDFOR  */
    AND = 272,                     /* AND  */
    BETWEEN = 273,                 /* BETWEEN  */
    DECR = 274,                    /* DECR  */
    INCR = 275,                    /* INCR  */
    PRINT = 276,                   /* PRINT  */
    SIN = 277,                     /* SIN  */
    COS = 278,                     /* COS  */
    TAN = 279,                     /* TAN  */
    SEPARATOR = 280,               /* SEPARATOR  */
    WHILE = 281,                   /* WHILE  */
    ENDWHILE = 282,                /* ENDWHILE  */
    DO = 283,                      /* DO  */
    SWITCH = 284,                  /* SWITCH  */
    ENDSWITCH = 285,               /* ENDSWITCH  */
    CASE = 286,                    /* CASE  */
    BREAK = 287,                   /* BREAK  */
    EXP = 288,                     /* EXP  */
    SQRT = 289,                    /* SQRT  */
    POW = 290,                     /* POW  */
    OPENFR = 291,                  /* OPENFR  */
    OPENFW = 292,                  /* OPENFW  */
    SUPPR = 293,                   /* SUPPR  */
    NEWNAME = 294,                 /* NEWNAME  */
    TOLOWER = 295,                 /* TOLOWER  */
    FIRST = 296,                   /* FIRST  */
    LAST = 297,                    /* LAST  */
    SIZE = 298,                    /* SIZE  */
    WAIT = 299,                    /* WAIT  */
    VARAPO = 300,                  /* VARAPO  */
    VRAI = 301,                    /* VRAI  */
    FAUX = 302,                    /* FAUX  */
    INF = 303,                     /* INF  */
    SUP = 304,                     /* SUP  */
    INFEG = 305,                   /* INFEG  */
    SUPEG = 306,                   /* SUPEG  */
    EGAL = 307,                    /* EGAL  */
    DIFF = 308,                    /* DIFF  */
    NON = 309,                     /* NON  */
    commentaire = 310,             /* commentaire  */
    DANS = 311,                    /* DANS  */
    DE = 312,                      /* DE  */
    JUSQUE = 313,                  /* JUSQUE  */
    EN = 314,                      /* EN  */
    ADD = 315,                     /* ADD  */
    SUB = 316,                     /* SUB  */
    MULT = 317,                    /* MULT  */
    DIV = 318                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "fransous.y"

  double valeur;
  char nom[50];
  type_adresse adresse;  

#line 143 "fransous.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_FRANSOUS_BISON_HPP_INCLUDED  */
