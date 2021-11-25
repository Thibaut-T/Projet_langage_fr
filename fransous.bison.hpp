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
    ENDDO = 286,                   /* ENDDO  */
    SWITCH = 287,                  /* SWITCH  */
    ENDSWITCH = 288,               /* ENDSWITCH  */
    CASE = 289,                    /* CASE  */
    DEFAULT = 290,                 /* DEFAULT  */
    BREAK = 291,                   /* BREAK  */
    EXP = 292,                     /* EXP  */
    SQRT = 293,                    /* SQRT  */
    POW = 294,                     /* POW  */
    OPENFR = 295,                  /* OPENFR  */
    OPENFW = 296,                  /* OPENFW  */
    SUPPR = 297,                   /* SUPPR  */
    NEWNAME = 298,                 /* NEWNAME  */
    TOLOWER = 299,                 /* TOLOWER  */
    FIRST = 300,                   /* FIRST  */
    LAST = 301,                    /* LAST  */
    SIZE = 302,                    /* SIZE  */
    WAIT = 303,                    /* WAIT  */
    VARAPO = 304,                  /* VARAPO  */
    VRAI = 305,                    /* VRAI  */
    FAUX = 306,                    /* FAUX  */
    INF = 307,                     /* INF  */
    SUP = 308,                     /* SUP  */
    INFEG = 309,                   /* INFEG  */
    SUPEG = 310,                   /* SUPEG  */
    EGAL = 311,                    /* EGAL  */
    DIFF = 312,                    /* DIFF  */
    NON = 313,                     /* NON  */
    commentaire = 314,             /* commentaire  */
    DANS = 315,                    /* DANS  */
    DE = 316,                      /* DE  */
    JUSQUE = 317,                  /* JUSQUE  */
    EN = 318,                      /* EN  */
    INCREMENTER = 319,             /* INCREMENTER  */
    DECREMENTER = 320,             /* DECREMENTER  */
    ADD = 321,                     /* ADD  */
    SUB = 322,                     /* SUB  */
    MULT = 323,                    /* MULT  */
    DIV = 324                      /* DIV  */
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

#line 150 "fransous.bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_FRANSOUS_BISON_HPP_INCLUDED  */
