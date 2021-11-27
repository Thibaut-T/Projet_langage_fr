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
#line 44 "fransous.y"

    typedef struct adr {
        int jmp;  // adresse du jmp
        int jc;  // adrese  du jc
        int save;
    } type_adresse;
  

#line 58 "fransous.bison.hpp"

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
    NUMNEG = 259,                  /* NUMNEG  */
    VAR = 260,                     /* VAR  */
    VARID = 261,                   /* VARID  */
    SI = 262,                      /* SI  */
    GOTO = 263,                    /* GOTO  */
    LABEL = 264,                   /* LABEL  */
    JMP = 265,                     /* JMP  */
    JMPCOND = 266,                 /* JMPCOND  */
    ASSIGN = 267,                  /* ASSIGN  */
    IF = 268,                      /* IF  */
    THEN = 269,                    /* THEN  */
    ELSE = 270,                    /* ELSE  */
    ENDIF = 271,                   /* ENDIF  */
    FOR = 272,                     /* FOR  */
    FOREACH = 273,                 /* FOREACH  */
    ENDFOR = 274,                  /* ENDFOR  */
    AND = 275,                     /* AND  */
    BETWEEN = 276,                 /* BETWEEN  */
    FONCTION = 277,                /* FONCTION  */
    DECR = 278,                    /* DECR  */
    INCR = 279,                    /* INCR  */
    PRINT = 280,                   /* PRINT  */
    SIN = 281,                     /* SIN  */
    COS = 282,                     /* COS  */
    TAN = 283,                     /* TAN  */
    SEPARATOR = 284,               /* SEPARATOR  */
    WHILE = 285,                   /* WHILE  */
    ENDWHILE = 286,                /* ENDWHILE  */
    DO = 287,                      /* DO  */
    ENDDO = 288,                   /* ENDDO  */
    SWITCH = 289,                  /* SWITCH  */
    ENDSWITCH = 290,               /* ENDSWITCH  */
    CASE = 291,                    /* CASE  */
    DEFAULT = 292,                 /* DEFAULT  */
    BREAK = 293,                   /* BREAK  */
    EXP = 294,                     /* EXP  */
    SQRT = 295,                    /* SQRT  */
    POW = 296,                     /* POW  */
    OPENFR = 297,                  /* OPENFR  */
    OPENFW = 298,                  /* OPENFW  */
    SUPPR = 299,                   /* SUPPR  */
    NEWNAME = 300,                 /* NEWNAME  */
    TOLOWER = 301,                 /* TOLOWER  */
    FIRST = 302,                   /* FIRST  */
    LAST = 303,                    /* LAST  */
    SIZE = 304,                    /* SIZE  */
    WAIT = 305,                    /* WAIT  */
    VARAPO = 306,                  /* VARAPO  */
    VRAI = 307,                    /* VRAI  */
    FAUX = 308,                    /* FAUX  */
    INF = 309,                     /* INF  */
    SUP = 310,                     /* SUP  */
    INFEG = 311,                   /* INFEG  */
    SUPEG = 312,                   /* SUPEG  */
    EGAL = 313,                    /* EGAL  */
    DIFF = 314,                    /* DIFF  */
    NON = 315,                     /* NON  */
    commentaire = 316,             /* commentaire  */
    DANS = 317,                    /* DANS  */
    DE = 318,                      /* DE  */
    JUSQUE = 319,                  /* JUSQUE  */
    EN = 320,                      /* EN  */
    INCREMENTER = 321,             /* INCREMENTER  */
    DECREMENTER = 322,             /* DECREMENTER  */
    ORCOND = 323,                  /* ORCOND  */
    ANDCOND = 324,                 /* ANDCOND  */
    TAB = 325,                     /* TAB  */
    ADD = 326,                     /* ADD  */
    SUB = 327,                     /* SUB  */
    MULT = 328,                    /* MULT  */
    DIV = 329                      /* DIV  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 52 "fransous.y"

  double valeur;
  char nom[50];
  type_adresse adresse;  

#line 155 "fransous.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_FRANSOUS_BISON_HPP_INCLUDED  */
