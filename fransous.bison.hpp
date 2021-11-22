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
    VARID = 260,                   /* VARID  */
    SI = 261,                      /* SI  */
    GOTO = 262,                    /* GOTO  */
    LABEL = 263,                   /* LABEL  */
    JMP = 264,                     /* JMP  */
    JMPCOND = 265,                 /* JMPCOND  */
    ASSIGN = 266,                  /* ASSIGN  */
    IF = 267,                      /* IF  */
    THEN = 268,                    /* THEN  */
    ELSE = 269,                    /* ELSE  */
    ENDIF = 270,                   /* ENDIF  */
    FOR = 271,                     /* FOR  */
    FOREACH = 272,                 /* FOREACH  */
    ENDFOR = 273,                  /* ENDFOR  */
    AND = 274,                     /* AND  */
    BETWEEN = 275,                 /* BETWEEN  */
    DECR = 276,                    /* DECR  */
    INCR = 277,                    /* INCR  */
    PRINT = 278,                   /* PRINT  */
    SIN = 279,                     /* SIN  */
    COS = 280,                     /* COS  */
    TAN = 281,                     /* TAN  */
    SEPARATOR = 282,               /* SEPARATOR  */
    WHILE = 283,                   /* WHILE  */
    ENDWHILE = 284,                /* ENDWHILE  */
    DO = 285,                      /* DO  */
    SWITCH = 286,                  /* SWITCH  */
    ENDSWITCH = 287,               /* ENDSWITCH  */
    CASE = 288,                    /* CASE  */
    BREAK = 289,                   /* BREAK  */
    EXP = 290,                     /* EXP  */
    SQRT = 291,                    /* SQRT  */
    POW = 292,                     /* POW  */
    OPENFR = 293,                  /* OPENFR  */
    OPENFW = 294,                  /* OPENFW  */
    SUPPR = 295,                   /* SUPPR  */
    NEWNAME = 296,                 /* NEWNAME  */
    TOLOWER = 297,                 /* TOLOWER  */
    FIRST = 298,                   /* FIRST  */
    LAST = 299,                    /* LAST  */
    SIZE = 300,                    /* SIZE  */
    WAIT = 301,                    /* WAIT  */
    VARAPO = 302,                  /* VARAPO  */
    VRAI = 303,                    /* VRAI  */
    FAUX = 304,                    /* FAUX  */
    INF = 305,                     /* INF  */
    SUP = 306,                     /* SUP  */
    INFEG = 307,                   /* INFEG  */
    SUPEG = 308,                   /* SUPEG  */
    EGAL = 309,                    /* EGAL  */
    DIFF = 310,                    /* DIFF  */
    NON = 311,                     /* NON  */
    commentaire = 312,             /* commentaire  */
    DANS = 313,                    /* DANS  */
    DE = 314,                      /* DE  */
    JUSQUE = 315,                  /* JUSQUE  */
    EN = 316,                      /* EN  */
    ADD = 317,                     /* ADD  */
    SUB = 318,                     /* SUB  */
    MULT = 319,                    /* MULT  */
    DIV = 320                      /* DIV  */
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

#line 145 "fransous.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_FRANSOUS_BISON_HPP_INCLUDED  */
