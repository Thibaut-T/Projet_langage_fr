/* A Bison parser, made by GNU Bison 3.8.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30801

/* Bison version string.  */
#define YYBISON_VERSION "3.8.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "fransous.y"

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

#line 119 "fransous.bison.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "fransous.bison.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_NUMNEG = 4,                     /* NUMNEG  */
  YYSYMBOL_VAR = 5,                        /* VAR  */
  YYSYMBOL_VARID = 6,                      /* VARID  */
  YYSYMBOL_SI = 7,                         /* SI  */
  YYSYMBOL_GOTO = 8,                       /* GOTO  */
  YYSYMBOL_LABEL = 9,                      /* LABEL  */
  YYSYMBOL_JMP = 10,                       /* JMP  */
  YYSYMBOL_JMPCOND = 11,                   /* JMPCOND  */
  YYSYMBOL_ASSIGN = 12,                    /* ASSIGN  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_THEN = 14,                      /* THEN  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_ENDIF = 16,                     /* ENDIF  */
  YYSYMBOL_FOR = 17,                       /* FOR  */
  YYSYMBOL_FOREACH = 18,                   /* FOREACH  */
  YYSYMBOL_ENDFOR = 19,                    /* ENDFOR  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_BETWEEN = 21,                   /* BETWEEN  */
  YYSYMBOL_FONCTION = 22,                  /* FONCTION  */
  YYSYMBOL_DECR = 23,                      /* DECR  */
  YYSYMBOL_INCR = 24,                      /* INCR  */
  YYSYMBOL_PRINT = 25,                     /* PRINT  */
  YYSYMBOL_SIN = 26,                       /* SIN  */
  YYSYMBOL_COS = 27,                       /* COS  */
  YYSYMBOL_TAN = 28,                       /* TAN  */
  YYSYMBOL_SEPARATOR = 29,                 /* SEPARATOR  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_ENDWHILE = 31,                  /* ENDWHILE  */
  YYSYMBOL_DO = 32,                        /* DO  */
  YYSYMBOL_ENDDO = 33,                     /* ENDDO  */
  YYSYMBOL_SWITCH = 34,                    /* SWITCH  */
  YYSYMBOL_ENDSWITCH = 35,                 /* ENDSWITCH  */
  YYSYMBOL_CASE = 36,                      /* CASE  */
  YYSYMBOL_DEFAULT = 37,                   /* DEFAULT  */
  YYSYMBOL_BREAK = 38,                     /* BREAK  */
  YYSYMBOL_EXP = 39,                       /* EXP  */
  YYSYMBOL_SQRT = 40,                      /* SQRT  */
  YYSYMBOL_POW = 41,                       /* POW  */
  YYSYMBOL_SUPPR = 42,                     /* SUPPR  */
  YYSYMBOL_TOLOWER = 43,                   /* TOLOWER  */
  YYSYMBOL_TOLOWERVAR = 44,                /* TOLOWERVAR  */
  YYSYMBOL_TOLOWERVARAPO = 45,             /* TOLOWERVARAPO  */
  YYSYMBOL_UPPER = 46,                     /* UPPER  */
  YYSYMBOL_UPPERVAR = 47,                  /* UPPERVAR  */
  YYSYMBOL_UPPERVARAPO = 48,               /* UPPERVARAPO  */
  YYSYMBOL_FIRST = 49,                     /* FIRST  */
  YYSYMBOL_LAST = 50,                      /* LAST  */
  YYSYMBOL_SIZE = 51,                      /* SIZE  */
  YYSYMBOL_VARAPO = 52,                    /* VARAPO  */
  YYSYMBOL_VRAI = 53,                      /* VRAI  */
  YYSYMBOL_FAUX = 54,                      /* FAUX  */
  YYSYMBOL_INF = 55,                       /* INF  */
  YYSYMBOL_SUP = 56,                       /* SUP  */
  YYSYMBOL_INFEG = 57,                     /* INFEG  */
  YYSYMBOL_SUPEG = 58,                     /* SUPEG  */
  YYSYMBOL_EGAL = 59,                      /* EGAL  */
  YYSYMBOL_DIFF = 60,                      /* DIFF  */
  YYSYMBOL_NON = 61,                       /* NON  */
  YYSYMBOL_commentaire = 62,               /* commentaire  */
  YYSYMBOL_DANS = 63,                      /* DANS  */
  YYSYMBOL_DE = 64,                        /* DE  */
  YYSYMBOL_JUSQUE = 65,                    /* JUSQUE  */
  YYSYMBOL_EN = 66,                        /* EN  */
  YYSYMBOL_INCREMENTER = 67,               /* INCREMENTER  */
  YYSYMBOL_DECREMENTER = 68,               /* DECREMENTER  */
  YYSYMBOL_ORCOND = 69,                    /* ORCOND  */
  YYSYMBOL_ANDCOND = 70,                   /* ANDCOND  */
  YYSYMBOL_CONCAT = 71,                    /* CONCAT  */
  YYSYMBOL_ENDL = 72,                      /* ENDL  */
  YYSYMBOL_TAB = 73,                       /* TAB  */
  YYSYMBOL_TABADD = 74,                    /* TABADD  */
  YYSYMBOL_A = 75,                         /* A  */
  YYSYMBOL_INDICE = 76,                    /* INDICE  */
  YYSYMBOL_ASSIGNINDICE = 77,              /* ASSIGNINDICE  */
  YYSYMBOL_ADD = 78,                       /* ADD  */
  YYSYMBOL_SUB = 79,                       /* SUB  */
  YYSYMBOL_MULT = 80,                      /* MULT  */
  YYSYMBOL_DIV = 81,                       /* DIV  */
  YYSYMBOL_MOD = 82,                       /* MOD  */
  YYSYMBOL_83_n_ = 83,                     /* '\n'  */
  YYSYMBOL_84_ = 84,                       /* ':'  */
  YYSYMBOL_85_ = 85,                       /* '='  */
  YYSYMBOL_86_ = 86,                       /* '('  */
  YYSYMBOL_87_ = 87,                       /* ')'  */
  YYSYMBOL_88_ = 88,                       /* ','  */
  YYSYMBOL_YYACCEPT = 89,                  /* $accept  */
  YYSYMBOL_lignes = 90,                    /* lignes  */
  YYSYMBOL_label = 91,                     /* label  */
  YYSYMBOL_separateur = 92,                /* separateur  */
  YYSYMBOL_case = 93,                      /* case  */
  YYSYMBOL_94_1 = 94,                      /* $@1  */
  YYSYMBOL_95_2 = 95,                      /* $@2  */
  YYSYMBOL_instruction = 96,               /* instruction  */
  YYSYMBOL_97_3 = 97,                      /* $@3  */
  YYSYMBOL_98_4 = 98,                      /* $@4  */
  YYSYMBOL_99_5 = 99,                      /* $@5  */
  YYSYMBOL_100_6 = 100,                    /* $@6  */
  YYSYMBOL_101_7 = 101,                    /* $@7  */
  YYSYMBOL_102_8 = 102,                    /* $@8  */
  YYSYMBOL_103_9 = 103,                    /* $@9  */
  YYSYMBOL_104_10 = 104,                   /* $@10  */
  YYSYMBOL_105_11 = 105,                   /* $@11  */
  YYSYMBOL_106_12 = 106,                   /* $@12  */
  YYSYMBOL_expr = 107,                     /* expr  */
  YYSYMBOL_fonction = 108,                 /* fonction  */
  YYSYMBOL_concatenation = 109,            /* concatenation  */
  YYSYMBOL_condition = 110                 /* condition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   337


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      83,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      86,    87,     2,     2,    88,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    84,     2,
       2,    85,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   156,   158,   159,   164,   167,   168,   171,
     172,   171,   181,   182,   183,   184,   185,   186,   187,   188,
     192,   194,   192,   205,   205,   226,   226,   248,   249,   252,
     248,   256,   256,   262,   262,   285,   285,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   321,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   343,   346,   347,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "NUMNEG", "VAR",
  "VARID", "SI", "GOTO", "LABEL", "JMP", "JMPCOND", "ASSIGN", "IF", "THEN",
  "ELSE", "ENDIF", "FOR", "FOREACH", "ENDFOR", "AND", "BETWEEN",
  "FONCTION", "DECR", "INCR", "PRINT", "SIN", "COS", "TAN", "SEPARATOR",
  "WHILE", "ENDWHILE", "DO", "ENDDO", "SWITCH", "ENDSWITCH", "CASE",
  "DEFAULT", "BREAK", "EXP", "SQRT", "POW", "SUPPR", "TOLOWER",
  "TOLOWERVAR", "TOLOWERVARAPO", "UPPER", "UPPERVAR", "UPPERVARAPO",
  "FIRST", "LAST", "SIZE", "VARAPO", "VRAI", "FAUX", "INF", "SUP", "INFEG",
  "SUPEG", "EGAL", "DIFF", "NON", "commentaire", "DANS", "DE", "JUSQUE",
  "EN", "INCREMENTER", "DECREMENTER", "ORCOND", "ANDCOND", "CONCAT",
  "ENDL", "TAB", "TABADD", "A", "INDICE", "ASSIGNINDICE", "ADD", "SUB",
  "MULT", "DIV", "MOD", "'\\n'", "':'", "'='", "'('", "')'", "','",
  "$accept", "lignes", "label", "separateur", "case", "$@1", "$@2",
  "instruction", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "$@12", "expr", "fonction", "concatenation", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -179,     5,  -179,   -77,   167,  -179,  -179,   -72,    19,   221,
      38,    41,   -38,   221,   -36,    -5,    27,  -179,    40,   275,
      29,    42,    59,    -2,    -1,     3,     4,    20,    93,  -179,
    -179,  -179,   111,   115,   275,  -179,   122,   275,   275,   275,
     275,    72,   205,  -179,   275,  -179,  -179,    71,   275,   221,
     253,    40,   117,    92,   154,  -179,   275,   275,   275,   221,
      84,  -179,    -3,   275,   275,   275,  -179,   275,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,   -14,
    -179,   176,    62,    55,   258,  -179,   275,   275,   275,   275,
     275,   205,   221,    83,    52,    32,   275,   275,   275,   275,
     275,   275,  -179,   165,   164,    86,   151,   277,   287,   297,
      40,  -179,  -179,  -179,   307,   317,    70,   150,   275,   169,
     171,  -179,    55,    55,  -179,  -179,  -179,    91,   174,   221,
     221,   205,   205,   205,   205,   205,   205,   168,   161,    40,
      40,   221,  -179,  -179,  -179,  -179,     8,  -179,  -179,  -179,
     275,   178,    43,  -179,   103,  -179,  -179,   104,   109,    40,
     187,  -179,  -179,  -179,  -179,   119,   -17,   327,  -179,   193,
     275,  -179,  -179,  -179,    34,  -179,    -7,   170,  -179,   175,
     179,  -179,  -179,   205,    12,   200,   208,    10,   181,   221,
     167,   275,   207,    40,    40,  -179,  -179,  -179,   185,     9,
      40,  -179,  -179,   142,  -179,  -179,  -179,  -179,  -179,   167,
       7,    23,    30,   189,  -179,  -179,  -179,   153,  -179
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     1,     0,    12,     5,    37,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      40,    41,     0,     0,     0,    70,     0,     0,     0,     0,
       0,     0,    13,    14,     0,    19,    39,     0,     0,     0,
      75,     0,     0,     0,     0,    73,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,    60,     0,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    55,    56,     0,
      15,     0,     0,    52,     0,     3,     0,     0,     0,     0,
       0,    16,     0,     0,    75,     0,     0,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    72,     0,     0,     0,
       0,     6,     2,    35,     0,     0,     0,     0,     0,     0,
       0,    48,    50,    51,    53,    54,    49,     0,     0,     0,
       0,    77,    76,    79,    78,    81,    80,     0,     0,     0,
       0,     0,    42,    43,    44,    28,     4,     7,    45,    46,
       0,     0,     0,    57,    58,    82,    58,     0,     0,     0,
       0,    33,    18,    74,     2,     0,     9,     0,    59,     0,
       0,    83,    84,     2,     0,     2,     4,     0,    36,     0,
       0,    47,    71,    17,     4,     0,     0,     4,     0,     0,
      12,     0,     0,     0,     0,    34,    30,    32,     0,     0,
       0,    25,    23,     0,    10,     2,     2,     2,     8,    12,
       4,     4,     4,     0,    22,    26,    24,     0,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -102,  -179,   -40,  -179,  -179,  -179,  -178,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,    -4,  -179,
    -179,   -12
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     4,    61,   166,   180,   209,    41,   137,   192,
     207,   206,    59,   164,   188,   112,   175,   147,    50,    43,
     106,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    55,     3,    66,    68,     2,   118,     5,    70,    72,
     146,   102,   198,    44,     3,    62,     3,     3,   178,     3,
     179,     3,   113,   214,   -29,    74,    60,   -21,    45,   195,
      79,   213,     3,    81,    82,    83,    84,    95,   204,     3,
      91,   165,   215,    52,    93,    94,    53,   110,    54,   216,
      56,    69,   107,   108,   109,    71,    73,   185,   186,   114,
     115,   116,   176,   117,    86,    87,    88,    89,    90,    60,
     145,   184,    75,   187,    67,    86,    87,    88,    89,    90,
     127,    57,   122,   123,   124,   125,   126,    86,    87,    88,
      89,    90,   131,   132,   133,   134,   135,   136,    76,   161,
     162,   129,   130,   210,   211,   212,   169,    96,    97,    98,
      99,   100,   101,    58,   152,    63,    77,   157,   158,   173,
      78,    86,    87,    88,    89,    90,   120,    80,    64,   163,
      86,    87,    88,    89,    90,    88,    89,    90,   103,   121,
      86,    87,    88,    89,    90,    65,   167,   128,    86,    87,
      88,    89,    90,   201,   202,    85,   104,    92,   150,   105,
     205,    86,    87,    88,    89,    90,   183,   111,   138,   139,
       6,   141,     7,   140,   153,     8,   154,   197,   155,   156,
       9,   160,   159,   168,    10,    11,    42,   199,   170,    12,
     174,   171,    13,    14,    15,    16,   172,    17,   182,    18,
     189,    19,   177,   193,   190,    42,    20,    21,    22,    23,
      24,   194,   196,    25,   151,   191,    26,    27,    28,    29,
      30,    31,   200,   203,     6,   208,    46,   217,    86,    87,
      88,    89,    90,     0,    32,    33,   218,     0,    34,    35,
      36,    37,     0,    38,     0,     0,    39,    14,    15,    16,
       0,   119,     0,    40,    86,    87,    88,    89,    90,     0,
      20,    21,    22,    23,    24,     0,     0,    25,     0,     0,
      26,    27,    28,    29,    30,    31,     0,     0,     6,     0,
      46,     0,    47,    86,    87,    88,    89,    90,    32,    33,
       0,     0,    34,    35,     0,    37,     0,    48,     0,     0,
      39,    14,    15,    16,     0,     0,     0,    49,    96,    97,
      98,    99,   100,   101,    20,    21,    22,    23,    24,     0,
       0,    25,     0,     0,    26,    27,    28,    29,    30,    31,
       0,    86,    87,    88,    89,    90,    86,    87,    88,    89,
      90,     0,    32,    33,     0,   121,    34,    35,     0,    37,
       0,    48,     0,     0,    39,    86,    87,    88,    89,    90,
       0,    40,     0,     0,   142,    86,    87,    88,    89,    90,
       0,     0,     0,     0,   143,    86,    87,    88,    89,    90,
       0,     0,     0,     0,   144,    86,    87,    88,    89,    90,
       0,     0,     0,     0,   148,    86,    87,    88,    89,    90,
       0,     0,     0,     0,   149,    86,    87,    88,    89,    90,
       0,     0,     0,     0,   181
};

static const yytype_int16 yycheck[] =
{
       4,    13,     9,     5,     5,     0,    20,    84,     5,     5,
     112,    51,   190,    85,     9,    19,     9,     9,    35,     9,
      37,     9,    62,    16,    31,     5,    29,    15,     9,    19,
      34,   209,     9,    37,    38,    39,    40,    49,    29,     9,
      44,    33,    19,     5,    48,    49,     5,    59,    86,    19,
      86,    52,    56,    57,    58,    52,    52,    23,    24,    63,
      64,    65,   164,    67,    78,    79,    80,    81,    82,    29,
     110,   173,    52,   175,    76,    78,    79,    80,    81,    82,
      92,    86,    86,    87,    88,    89,    90,    78,    79,    80,
      81,    82,    96,    97,    98,    99,   100,   101,     5,   139,
     140,    69,    70,   205,   206,   207,    63,    55,    56,    57,
      58,    59,    60,    86,   118,    86,     5,   129,   130,   159,
       5,    78,    79,    80,    81,    82,    64,     5,    86,   141,
      78,    79,    80,    81,    82,    80,    81,    82,    21,    87,
      78,    79,    80,    81,    82,    86,   150,    64,    78,    79,
      80,    81,    82,   193,   194,    83,    64,    86,    88,     5,
     200,    78,    79,    80,    81,    82,   170,    83,     3,     5,
       3,    20,     5,    87,     5,     8,     5,   189,    87,     5,
      13,    20,    14,     5,    17,    18,   190,   191,    85,    22,
       3,    87,    25,    26,    27,    28,    87,    30,     5,    32,
      30,    34,    83,     3,    29,   209,    39,    40,    41,    42,
      43,     3,    31,    46,    64,    36,    49,    50,    51,    52,
      53,    54,    15,    38,     3,    83,     5,    38,    78,    79,
      80,    81,    82,    -1,    67,    68,    83,    -1,    71,    72,
      73,    74,    -1,    76,    -1,    -1,    79,    26,    27,    28,
      -1,    75,    -1,    86,    78,    79,    80,    81,    82,    -1,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    -1,    -1,     3,    -1,
       5,    -1,    61,    78,    79,    80,    81,    82,    67,    68,
      -1,    -1,    71,    72,    -1,    74,    -1,    76,    -1,    -1,
      79,    26,    27,    28,    -1,    -1,    -1,    86,    55,    56,
      57,    58,    59,    60,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      -1,    78,    79,    80,    81,    82,    78,    79,    80,    81,
      82,    -1,    67,    68,    -1,    87,    71,    72,    -1,    74,
      -1,    76,    -1,    -1,    79,    78,    79,    80,    81,    82,
      -1,    86,    -1,    -1,    87,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    87,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    87,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    87,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    87,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    90,     0,     9,    91,    84,     3,     5,     8,    13,
      17,    18,    22,    25,    26,    27,    28,    30,    32,    34,
      39,    40,    41,    42,    43,    46,    49,    50,    51,    52,
      53,    54,    67,    68,    71,    72,    73,    74,    76,    79,
      86,    96,   107,   108,    85,     9,     5,    61,    76,    86,
     107,   110,     5,     5,    86,   110,    86,    86,    86,   101,
      29,    92,   107,    86,    86,    86,     5,    76,     5,    52,
       5,    52,     5,    52,     5,    52,     5,     5,     5,   107,
       5,   107,   107,   107,   107,    83,    78,    79,    80,    81,
      82,   107,    86,   107,   107,   110,    55,    56,    57,    58,
      59,    60,    92,    21,    64,     5,   109,   107,   107,   107,
     110,    83,   104,    92,   107,   107,   107,   107,    20,    75,
      64,    87,   107,   107,   107,   107,   107,   110,    64,    69,
      70,   107,   107,   107,   107,   107,   107,    97,     3,     5,
      87,    20,    87,    87,    87,    92,    90,   106,    87,    87,
      88,    64,   107,     5,     5,    87,     5,   110,   110,    14,
      20,    92,    92,   110,   102,    33,    93,   107,     5,    63,
      85,    87,    87,    92,     3,   105,    90,    83,    35,    37,
      94,    87,     5,   107,    90,    23,    24,    90,   103,    30,
      29,    36,    98,     3,     3,    19,    31,   110,    96,   107,
      15,    92,    92,    38,    29,    92,   100,    99,    83,    95,
      90,    90,    90,    96,    16,    19,    19,    38,    83
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    89,    90,    90,    91,    91,    92,    93,    93,    94,
      95,    93,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    98,    96,    99,    96,   100,    96,   101,   102,   103,
      96,   104,    96,   105,    96,   106,    96,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   108,   109,   109,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     2,     0,     6,     0,
       0,     9,     0,     1,     1,     2,     3,     6,     5,     2,
       0,     0,    12,     0,    12,     0,    12,     0,     0,     0,
       8,     0,     8,     0,     8,     0,     6,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     6,     3,     3,
       3,     3,     2,     3,     3,     2,     2,     4,     4,     5,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       1,     6,     3,     0,     3,     1,     3,     3,     3,     3,
       3,     3,     4,     5,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* lignes: %empty  */
#line 155 "fransous.y"
       { }
#line 1396 "fransous.bison.cpp"
    break;

  case 5: /* label: LABEL ':'  */
#line 159 "fransous.y"
                   { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1405 "fransous.bison.cpp"
    break;

  case 7: /* case: %empty  */
#line 167 "fransous.y"
       {}
#line 1411 "fransous.bison.cpp"
    break;

  case 8: /* case: case DEFAULT SEPARATOR instruction BREAK '\n'  */
#line 168 "fransous.y"
                                                        { breakN.push_back(ic);
                                                          add_instruction(JMP);
                                                        }
#line 1419 "fransous.bison.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 171 "fransous.y"
               {(yyvsp[0].adresse).save = ic-1;}
#line 1425 "fransous.bison.cpp"
    break;

  case 10: /* $@2: %empty  */
#line 172 "fransous.y"
                            {add_instruction(EGAL);
                            (yyvsp[-2].adresse).jc = ic; 
                            add_instruction(JMPCOND);}
#line 1433 "fransous.bison.cpp"
    break;

  case 11: /* case: case $@1 CASE expr SEPARATOR $@2 instruction BREAK '\n'  */
#line 176 "fransous.y"
                   {breakN.push_back(ic) ;
                    add_instruction(JMP);
                    code_genere[(yyvsp[-6].adresse).jc].value = ic;
                    add_instruction(VARID, 0, code_genere[(yyvsp[-8].adresse).save].name);}
#line 1442 "fransous.bison.cpp"
    break;

  case 12: /* instruction: %empty  */
#line 181 "fransous.y"
             {}
#line 1448 "fransous.bison.cpp"
    break;

  case 13: /* instruction: expr  */
#line 182 "fransous.y"
                       { }
#line 1454 "fransous.bison.cpp"
    break;

  case 14: /* instruction: fonction  */
#line 183 "fransous.y"
                       { }
#line 1460 "fransous.bison.cpp"
    break;

  case 15: /* instruction: TAB VAR  */
#line 184 "fransous.y"
                  {add_instruction(TAB, 0, (yyvsp[0].nom));}
#line 1466 "fransous.bison.cpp"
    break;

  case 16: /* instruction: VAR '=' expr  */
#line 185 "fransous.y"
                       { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1472 "fransous.bison.cpp"
    break;

  case 17: /* instruction: INDICE expr DE VAR '=' expr  */
#line 186 "fransous.y"
                                      {add_instruction(ASSIGNINDICE, 0, (yyvsp[-2].nom));}
#line 1478 "fransous.bison.cpp"
    break;

  case 18: /* instruction: FONCTION '(' VAR ')' separateur  */
#line 187 "fransous.y"
                                          { add_instruction(FONCTION); }
#line 1484 "fransous.bison.cpp"
    break;

  case 19: /* instruction: GOTO LABEL  */
#line 188 "fransous.y"
                       {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, (yyvsp[0].nom)); 
                        }
#line 1493 "fransous.bison.cpp"
    break;

  case 20: /* $@3: %empty  */
#line 192 "fransous.y"
                                 {(yyvsp[-2].adresse).jc = ic; add_instruction(JMPCOND); }
#line 1499 "fransous.bison.cpp"
    break;

  case 21: /* $@4: %empty  */
#line 194 "fransous.y"
                          { // Je sauvegarde l'endroit actuel pour revenir modifier l'adresse 
                          // lorsqu'elle sera connue (celle du JMP)
                          (yyvsp[-6].adresse).jmp = ic;
                          add_instruction(JMP);
                          // Je mets à jour l'adresse du saut conditionnel
                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                        }
#line 1511 "fransous.bison.cpp"
    break;

  case 22: /* instruction: IF condition separateur $@3 THEN separateur lignes $@4 ELSE separateur lignes ENDIF  */
#line 203 "fransous.y"
                        { // Je mets à jour l'adresse du saut inconditionnel
                        code_genere[(yyvsp[-11].adresse).jmp].value = ic;}
#line 1518 "fransous.bison.cpp"
    break;

  case 23: /* $@5: %empty  */
#line 205 "fransous.y"
                                                         { add_instruction(VAR, 0, (yyvsp[-7].nom));
                                                                add_instruction(NUM, (yyvsp[-5].valeur));
                                                                add_instruction(NUM, (yyvsp[-1].valeur));
                                                                add_instruction(SUB);
                                                                add_instruction(ASSIGN, 0, (yyvsp[-7].nom));

                                                                (yyvsp[-8].adresse).jmp = ic;
                                                                add_instruction(VAR, 0, (yyvsp[-7].nom));
                                                                add_instruction(NUM, (yyvsp[-1].valeur));
                                                                add_instruction(ADD);
                                                                add_instruction(ASSIGN, 0, (yyvsp[-7].nom));
                                                                add_instruction(VAR, 0, (yyvsp[-7].nom));
                                                                add_instruction(NUM, (yyvsp[-3].valeur));
                                                                add_instruction(INF);
                                                                (yyvsp[-8].adresse).jc = ic;
                                                                add_instruction(JMPCOND);}
#line 1539 "fransous.bison.cpp"
    break;

  case 24: /* instruction: FOR VAR BETWEEN NUM AND NUM INCR NUM separateur $@5 lignes ENDFOR  */
#line 222 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;
                                                              add_instruction(SUPPR, 0, (yyvsp[-10].nom));}
#line 1548 "fransous.bison.cpp"
    break;

  case 25: /* $@6: %empty  */
#line 226 "fransous.y"
                                                         { add_instruction(VAR, 0, (yyvsp[-7].nom));
                                                            add_instruction(NUM, (yyvsp[-5].valeur));
                                                            add_instruction(NUM, (yyvsp[-1].valeur));
                                                            add_instruction(ADD);
                                                            add_instruction(ASSIGN, 0, (yyvsp[-7].nom));

                                                            (yyvsp[-8].adresse).jmp = ic;
                                                            add_instruction(VAR, 0, (yyvsp[-7].nom));
                                                            add_instruction(NUM, (yyvsp[-1].valeur));
                                                            add_instruction(SUB);
                                                            add_instruction(ASSIGN, 0, (yyvsp[-7].nom));
                                                            add_instruction(VAR, 0, (yyvsp[-7].nom));
                                                            add_instruction(NUM, (yyvsp[-3].valeur));
                                                            add_instruction(SUP);
                                                            (yyvsp[-8].adresse).jc = ic;
                                                            add_instruction(JMPCOND);}
#line 1569 "fransous.bison.cpp"
    break;

  case 26: /* instruction: FOR VAR BETWEEN NUM AND NUM DECR NUM separateur $@6 lignes ENDFOR  */
#line 243 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;
                                                              add_instruction(SUPPR, 0, (yyvsp[-10].nom));}
#line 1578 "fransous.bison.cpp"
    break;

  case 27: /* $@7: %empty  */
#line 248 "fransous.y"
                                                      { (yyvsp[0].adresse).jmp = ic;}
#line 1584 "fransous.bison.cpp"
    break;

  case 28: /* $@8: %empty  */
#line 249 "fransous.y"
                                                      {(yyvsp[-3].adresse).jc = ic;
                                                        add_instruction(JMPCOND);
                                                      }
#line 1592 "fransous.bison.cpp"
    break;

  case 29: /* $@9: %empty  */
#line 252 "fransous.y"
                                                      { add_instruction(JMP, (yyvsp[-5].adresse).jmp);
                                                        code_genere[(yyvsp[-5].adresse).jc].value = ic;
                                                      }
#line 1600 "fransous.bison.cpp"
    break;

  case 31: /* $@10: %empty  */
#line 256 "fransous.y"
                                                      {(yyvsp[-1].adresse).jc = ic;}
#line 1606 "fransous.bison.cpp"
    break;

  case 32: /* instruction: DO separateur $@10 lignes ENDDO '\n' WHILE condition  */
#line 259 "fransous.y"
                                                      { add_instruction(NON);
                                                        add_instruction(JMPCOND, (yyvsp[-7].adresse).jc);}
#line 1613 "fransous.bison.cpp"
    break;

  case 33: /* $@11: %empty  */
#line 262 "fransous.y"
                                                      { add_instruction(VAR, 0, "1");
                                                        add_instruction(VAR, 0, (yyvsp[-3].nom));
                                                        (yyvsp[-4].adresse).jmp = ic;
                                                        add_instruction(VAR, 0, "1");
                                                        add_instruction(SIZE, 0, (yyvsp[-1].nom));
                                                        add_instruction(INF);
                                                        (yyvsp[-4].adresse).jc = ic;
                                                        add_instruction(JMPCOND);
                                                        add_instruction(VAR, 0, "1");
                                                        add_instruction(NUM, 1);
                                                        add_instruction(ADD);
                                                        add_instruction(ASSIGN, 0, "1");
                                                        add_instruction(VAR, 0, "1");
                                                        add_instruction(INDICE, 0, (yyvsp[-1].nom));
                                                        add_instruction(ASSIGN, 0, (yyvsp[-3].nom));
                                                      }
#line 1634 "fransous.bison.cpp"
    break;

  case 34: /* instruction: FOREACH VAR DE VAR separateur $@11 lignes ENDFOR  */
#line 279 "fransous.y"
                                                      { add_instruction(JMP);
                                                        code_genere[ic-1].value = (yyvsp[-7].adresse).jmp;
                                                        code_genere[(yyvsp[-7].adresse).jc].value = ic;
                                                        add_instruction(SUPPR, 0, (yyvsp[-6].nom));
                                                        add_instruction(SUPPR, 0, "1");
                                                      }
#line 1645 "fransous.bison.cpp"
    break;

  case 35: /* $@12: %empty  */
#line 285 "fransous.y"
                                                      { if(!breakN.empty()){
                                                          adresseBreak.push_back(breakN);
                                                          breakN.clear();
                                                        }}
#line 1654 "fransous.bison.cpp"
    break;

  case 36: /* instruction: SWITCH expr separateur $@12 case ENDSWITCH  */
#line 290 "fransous.y"
                                                      {for(auto itr : breakN){
                                                          code_genere[itr].value = ic;
                                                        }
                                                        breakN.clear();
                                                        if(!adresseBreak.empty()){
                                                          breakN = adresseBreak.back();
                                                          adresseBreak.pop_back();
                                                        } 
                                                      }
#line 1668 "fransous.bison.cpp"
    break;

  case 37: /* expr: NUM  */
#line 299 "fransous.y"
          {add_instruction (NUM, (yyvsp[0].valeur));}
#line 1674 "fransous.bison.cpp"
    break;

  case 38: /* expr: VARAPO  */
#line 300 "fransous.y"
             {add_instruction(VARAPO, 0, (yyvsp[0].nom));}
#line 1680 "fransous.bison.cpp"
    break;

  case 39: /* expr: VAR  */
#line 301 "fransous.y"
          {add_instruction (VAR, 0, (yyvsp[0].nom)); }
#line 1686 "fransous.bison.cpp"
    break;

  case 40: /* expr: VRAI  */
#line 302 "fransous.y"
           {add_instruction (NUM, true);}
#line 1692 "fransous.bison.cpp"
    break;

  case 41: /* expr: FAUX  */
#line 303 "fransous.y"
           {add_instruction (NUM, false);}
#line 1698 "fransous.bison.cpp"
    break;

  case 42: /* expr: SIN '(' expr ')'  */
#line 304 "fransous.y"
                        {add_instruction(SIN);}
#line 1704 "fransous.bison.cpp"
    break;

  case 43: /* expr: COS '(' expr ')'  */
#line 305 "fransous.y"
                        {add_instruction(COS);}
#line 1710 "fransous.bison.cpp"
    break;

  case 44: /* expr: TAN '(' expr ')'  */
#line 306 "fransous.y"
                        {add_instruction(TAN);}
#line 1716 "fransous.bison.cpp"
    break;

  case 45: /* expr: EXP '(' expr ')'  */
#line 307 "fransous.y"
                        {add_instruction(EXP);}
#line 1722 "fransous.bison.cpp"
    break;

  case 46: /* expr: SQRT '(' expr ')'  */
#line 308 "fransous.y"
                        {add_instruction(SQRT);}
#line 1728 "fransous.bison.cpp"
    break;

  case 47: /* expr: POW '(' expr ',' expr ')'  */
#line 309 "fransous.y"
                              {add_instruction(POW);}
#line 1734 "fransous.bison.cpp"
    break;

  case 48: /* expr: '(' expr ')'  */
#line 310 "fransous.y"
                         { (yyval.valeur) = (yyvsp[-1].valeur);}
#line 1740 "fransous.bison.cpp"
    break;

  case 49: /* expr: expr MOD expr  */
#line 311 "fransous.y"
                    {add_instruction(MOD);}
#line 1746 "fransous.bison.cpp"
    break;

  case 50: /* expr: expr ADD expr  */
#line 312 "fransous.y"
                    {add_instruction(ADD);}
#line 1752 "fransous.bison.cpp"
    break;

  case 51: /* expr: expr SUB expr  */
#line 313 "fransous.y"
                    {add_instruction(SUB);}
#line 1758 "fransous.bison.cpp"
    break;

  case 52: /* expr: SUB expr  */
#line 314 "fransous.y"
                {add_instruction(NUM, -1); add_instruction(MULT);}
#line 1764 "fransous.bison.cpp"
    break;

  case 53: /* expr: expr MULT expr  */
#line 315 "fransous.y"
                     {add_instruction(MULT);}
#line 1770 "fransous.bison.cpp"
    break;

  case 54: /* expr: expr DIV expr  */
#line 316 "fransous.y"
                    {add_instruction(DIV);}
#line 1776 "fransous.bison.cpp"
    break;

  case 55: /* expr: INCREMENTER VAR  */
#line 317 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(ADD); 
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1785 "fransous.bison.cpp"
    break;

  case 56: /* expr: DECREMENTER VAR  */
#line 321 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(SUB);
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1794 "fransous.bison.cpp"
    break;

  case 57: /* expr: TABADD expr A VAR  */
#line 325 "fransous.y"
                         {add_instruction(TABADD, 0, (yyvsp[0].nom));}
#line 1800 "fransous.bison.cpp"
    break;

  case 58: /* expr: INDICE expr DE VAR  */
#line 326 "fransous.y"
                          {add_instruction(INDICE, 0, (yyvsp[0].nom));}
#line 1806 "fransous.bison.cpp"
    break;

  case 59: /* expr: SUPPR INDICE expr DE VAR  */
#line 327 "fransous.y"
                                {add_instruction(SUPPR, 1, (yyvsp[0].nom));}
#line 1812 "fransous.bison.cpp"
    break;

  case 60: /* expr: SUPPR VAR  */
#line 328 "fransous.y"
                 {add_instruction(SUPPR, 0, (yyvsp[0].nom));}
#line 1818 "fransous.bison.cpp"
    break;

  case 61: /* expr: TOLOWER VAR  */
#line 329 "fransous.y"
                   {add_instruction(TOLOWERVAR, 0, (yyvsp[0].nom));}
#line 1824 "fransous.bison.cpp"
    break;

  case 62: /* expr: TOLOWER VARAPO  */
#line 330 "fransous.y"
                      {add_instruction(TOLOWERVARAPO, 0, (yyvsp[0].nom));}
#line 1830 "fransous.bison.cpp"
    break;

  case 63: /* expr: UPPER VAR  */
#line 331 "fransous.y"
                 {add_instruction(UPPERVAR, 0, (yyvsp[0].nom));}
#line 1836 "fransous.bison.cpp"
    break;

  case 64: /* expr: UPPER VARAPO  */
#line 332 "fransous.y"
                    {add_instruction(UPPERVARAPO, 0, (yyvsp[0].nom));}
#line 1842 "fransous.bison.cpp"
    break;

  case 65: /* expr: FIRST VAR  */
#line 333 "fransous.y"
                 {add_instruction(FIRST, 0, (yyvsp[0].nom));}
#line 1848 "fransous.bison.cpp"
    break;

  case 66: /* expr: FIRST VARAPO  */
#line 334 "fransous.y"
                    {add_instruction(FIRST, 0, (yyvsp[0].nom));}
#line 1854 "fransous.bison.cpp"
    break;

  case 67: /* expr: LAST VAR  */
#line 335 "fransous.y"
                {add_instruction(LAST, 0, (yyvsp[0].nom));}
#line 1860 "fransous.bison.cpp"
    break;

  case 68: /* expr: LAST VARAPO  */
#line 336 "fransous.y"
                   {add_instruction(LAST, 0, (yyvsp[0].nom));}
#line 1866 "fransous.bison.cpp"
    break;

  case 69: /* expr: SIZE VAR  */
#line 337 "fransous.y"
                {add_instruction(SIZE, 0, (yyvsp[0].nom));}
#line 1872 "fransous.bison.cpp"
    break;

  case 70: /* expr: ENDL  */
#line 338 "fransous.y"
            {add_instruction(ENDL);}
#line 1878 "fransous.bison.cpp"
    break;

  case 71: /* expr: CONCAT expr AND expr DANS VAR  */
#line 339 "fransous.y"
                                     { add_instruction(CONCAT); add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1884 "fransous.bison.cpp"
    break;

  case 72: /* fonction: PRINT condition concatenation  */
#line 343 "fransous.y"
                                        {add_instruction(PRINT);}
#line 1890 "fransous.bison.cpp"
    break;

  case 73: /* concatenation: %empty  */
#line 346 "fransous.y"
                {}
#line 1896 "fransous.bison.cpp"
    break;

  case 74: /* concatenation: concatenation AND condition  */
#line 347 "fransous.y"
                                            {add_instruction(CONCAT);}
#line 1902 "fransous.bison.cpp"
    break;

  case 76: /* condition: expr SUP expr  */
#line 353 "fransous.y"
                         {add_instruction(SUP);}
#line 1908 "fransous.bison.cpp"
    break;

  case 77: /* condition: expr INF expr  */
#line 354 "fransous.y"
                         {add_instruction(INF);}
#line 1914 "fransous.bison.cpp"
    break;

  case 78: /* condition: expr SUPEG expr  */
#line 355 "fransous.y"
                           {add_instruction(SUPEG);}
#line 1920 "fransous.bison.cpp"
    break;

  case 79: /* condition: expr INFEG expr  */
#line 356 "fransous.y"
                           {add_instruction(INFEG);}
#line 1926 "fransous.bison.cpp"
    break;

  case 80: /* condition: expr DIFF expr  */
#line 357 "fransous.y"
                          {add_instruction(DIFF);}
#line 1932 "fransous.bison.cpp"
    break;

  case 81: /* condition: expr EGAL expr  */
#line 358 "fransous.y"
                          {add_instruction(EGAL);}
#line 1938 "fransous.bison.cpp"
    break;

  case 82: /* condition: NON '(' condition ')'  */
#line 359 "fransous.y"
                               {add_instruction(NON);}
#line 1944 "fransous.bison.cpp"
    break;

  case 83: /* condition: '(' condition ORCOND condition ')'  */
#line 360 "fransous.y"
                                            {add_instruction(ORCOND);}
#line 1950 "fransous.bison.cpp"
    break;

  case 84: /* condition: '(' condition ANDCOND condition ')'  */
#line 361 "fransous.y"
                                             {add_instruction(ANDCOND);}
#line 1956 "fransous.bison.cpp"
    break;


#line 1960 "fransous.bison.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 362 "fransous.y"



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
