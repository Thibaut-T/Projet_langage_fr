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
  YYSYMBOL_OPENFR = 42,                    /* OPENFR  */
  YYSYMBOL_OPENFW = 43,                    /* OPENFW  */
  YYSYMBOL_SUPPR = 44,                     /* SUPPR  */
  YYSYMBOL_NEWNAME = 45,                   /* NEWNAME  */
  YYSYMBOL_TOLOWER = 46,                   /* TOLOWER  */
  YYSYMBOL_TOLOWERVAR = 47,                /* TOLOWERVAR  */
  YYSYMBOL_TOLOWERVARAPO = 48,             /* TOLOWERVARAPO  */
  YYSYMBOL_UPPER = 49,                     /* UPPER  */
  YYSYMBOL_UPPERVAR = 50,                  /* UPPERVAR  */
  YYSYMBOL_UPPERVARAPO = 51,               /* UPPERVARAPO  */
  YYSYMBOL_FIRST = 52,                     /* FIRST  */
  YYSYMBOL_LAST = 53,                      /* LAST  */
  YYSYMBOL_SIZE = 54,                      /* SIZE  */
  YYSYMBOL_WAIT = 55,                      /* WAIT  */
  YYSYMBOL_VARAPO = 56,                    /* VARAPO  */
  YYSYMBOL_VRAI = 57,                      /* VRAI  */
  YYSYMBOL_FAUX = 58,                      /* FAUX  */
  YYSYMBOL_INF = 59,                       /* INF  */
  YYSYMBOL_SUP = 60,                       /* SUP  */
  YYSYMBOL_INFEG = 61,                     /* INFEG  */
  YYSYMBOL_SUPEG = 62,                     /* SUPEG  */
  YYSYMBOL_EGAL = 63,                      /* EGAL  */
  YYSYMBOL_DIFF = 64,                      /* DIFF  */
  YYSYMBOL_NON = 65,                       /* NON  */
  YYSYMBOL_commentaire = 66,               /* commentaire  */
  YYSYMBOL_DANS = 67,                      /* DANS  */
  YYSYMBOL_DE = 68,                        /* DE  */
  YYSYMBOL_JUSQUE = 69,                    /* JUSQUE  */
  YYSYMBOL_EN = 70,                        /* EN  */
  YYSYMBOL_INCREMENTER = 71,               /* INCREMENTER  */
  YYSYMBOL_DECREMENTER = 72,               /* DECREMENTER  */
  YYSYMBOL_ORCOND = 73,                    /* ORCOND  */
  YYSYMBOL_ANDCOND = 74,                   /* ANDCOND  */
  YYSYMBOL_CONCAT = 75,                    /* CONCAT  */
  YYSYMBOL_ENDL = 76,                      /* ENDL  */
  YYSYMBOL_TAB = 77,                       /* TAB  */
  YYSYMBOL_TABADD = 78,                    /* TABADD  */
  YYSYMBOL_A = 79,                         /* A  */
  YYSYMBOL_INDICE = 80,                    /* INDICE  */
  YYSYMBOL_ASSIGNINDICE = 81,              /* ASSIGNINDICE  */
  YYSYMBOL_ADD = 82,                       /* ADD  */
  YYSYMBOL_SUB = 83,                       /* SUB  */
  YYSYMBOL_MULT = 84,                      /* MULT  */
  YYSYMBOL_DIV = 85,                       /* DIV  */
  YYSYMBOL_MOD = 86,                       /* MOD  */
  YYSYMBOL_87_n_ = 87,                     /* '\n'  */
  YYSYMBOL_88_ = 88,                       /* ':'  */
  YYSYMBOL_89_ = 89,                       /* '='  */
  YYSYMBOL_90_ = 90,                       /* '('  */
  YYSYMBOL_91_ = 91,                       /* ')'  */
  YYSYMBOL_92_ = 92,                       /* ','  */
  YYSYMBOL_YYACCEPT = 93,                  /* $accept  */
  YYSYMBOL_lignes = 94,                    /* lignes  */
  YYSYMBOL_label = 95,                     /* label  */
  YYSYMBOL_separateur = 96,                /* separateur  */
  YYSYMBOL_case = 97,                      /* case  */
  YYSYMBOL_98_1 = 98,                      /* $@1  */
  YYSYMBOL_99_2 = 99,                      /* $@2  */
  YYSYMBOL_instruction = 100,              /* instruction  */
  YYSYMBOL_101_3 = 101,                    /* $@3  */
  YYSYMBOL_102_4 = 102,                    /* $@4  */
  YYSYMBOL_103_5 = 103,                    /* $@5  */
  YYSYMBOL_104_6 = 104,                    /* $@6  */
  YYSYMBOL_105_7 = 105,                    /* $@7  */
  YYSYMBOL_106_8 = 106,                    /* $@8  */
  YYSYMBOL_107_9 = 107,                    /* $@9  */
  YYSYMBOL_108_10 = 108,                   /* $@10  */
  YYSYMBOL_109_11 = 109,                   /* $@11  */
  YYSYMBOL_110_12 = 110,                   /* $@12  */
  YYSYMBOL_expr = 111,                     /* expr  */
  YYSYMBOL_fonction = 112,                 /* fonction  */
  YYSYMBOL_concatenation = 113,            /* concatenation  */
  YYSYMBOL_condition = 114                 /* condition  */
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
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   341


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
      87,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      90,    91,     2,     2,    92,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,     2,
       2,    89,     2,     2,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   159,   159,   160,   162,   163,   168,   171,   172,   175,
     176,   175,   185,   186,   187,   188,   189,   190,   191,   192,
     196,   198,   196,   209,   209,   230,   230,   252,   253,   256,
     252,   260,   260,   266,   266,   289,   289,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   325,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   347,   350,   351,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365
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
  "DEFAULT", "BREAK", "EXP", "SQRT", "POW", "OPENFR", "OPENFW", "SUPPR",
  "NEWNAME", "TOLOWER", "TOLOWERVAR", "TOLOWERVARAPO", "UPPER", "UPPERVAR",
  "UPPERVARAPO", "FIRST", "LAST", "SIZE", "WAIT", "VARAPO", "VRAI", "FAUX",
  "INF", "SUP", "INFEG", "SUPEG", "EGAL", "DIFF", "NON", "commentaire",
  "DANS", "DE", "JUSQUE", "EN", "INCREMENTER", "DECREMENTER", "ORCOND",
  "ANDCOND", "CONCAT", "ENDL", "TAB", "TABADD", "A", "INDICE",
  "ASSIGNINDICE", "ADD", "SUB", "MULT", "DIV", "MOD", "'\\n'", "':'",
  "'='", "'('", "')'", "','", "$accept", "lignes", "label", "separateur",
  "case", "$@1", "$@2", "instruction", "$@3", "$@4", "$@5", "$@6", "$@7",
  "$@8", "$@9", "$@10", "$@11", "$@12", "expr", "fonction",
  "concatenation", "condition", YY_NULLPTR
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
    -179,     9,  -179,   -71,   167,  -179,  -179,   -69,    37,   225,
      43,    69,   -18,   225,   -14,   -11,    11,  -179,    73,   283,
      17,    25,    35,    -3,     0,     1,     2,     8,    93,  -179,
    -179,  -179,   108,   111,   283,  -179,   121,   283,   283,   283,
     283,    40,   209,  -179,   283,  -179,  -179,    46,   283,   225,
      79,    73,   107,    62,   132,  -179,   283,   283,   283,   225,
      57,  -179,    26,   283,   283,   283,  -179,   283,  -179,  -179,
    -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,   -17,
    -179,   355,    38,     3,   176,  -179,   283,   283,   283,   283,
     283,   209,   225,   149,   285,   -23,   283,   283,   283,   283,
     283,   283,  -179,   142,   147,    64,   136,   295,   305,   315,
      73,  -179,  -179,  -179,   325,   335,    65,   234,   283,   153,
     154,  -179,     3,     3,  -179,  -179,  -179,    76,   163,   225,
     225,   209,   209,   209,   209,   209,   209,   155,   151,    73,
      73,   225,  -179,  -179,  -179,  -179,    -5,  -179,  -179,  -179,
     283,   168,   -59,  -179,    85,  -179,  -179,    87,    88,    73,
     173,  -179,  -179,  -179,  -179,    94,     6,   345,  -179,   177,
     283,  -179,  -179,  -179,    67,  -179,     7,   158,  -179,   161,
     160,  -179,  -179,   209,    66,   180,   188,    10,   169,   225,
     167,   283,   183,    73,    73,  -179,  -179,  -179,   164,    49,
      73,  -179,  -179,   116,  -179,  -179,  -179,  -179,  -179,   167,
       5,    23,    30,   166,  -179,  -179,  -179,   122,  -179
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
      42,    55,    66,   118,     3,    68,    70,    72,   169,     2,
     146,   102,   198,    74,     3,    62,     3,     5,     3,     3,
      44,   214,   113,    86,    87,    88,    89,    90,   165,   195,
      79,   213,     3,    81,    82,    83,    84,    95,   -29,     3,
      91,   178,   215,   179,    93,    94,    45,   110,    52,   216,
     129,   130,   107,   108,   109,    60,    69,    71,    73,   114,
     115,   116,   176,   117,    75,    86,    87,    88,    89,    90,
     145,   184,    54,   187,    53,     3,    56,    67,   204,    57,
     127,   -21,   122,   123,   124,   125,   126,    88,    89,    90,
     185,   186,   131,   132,   133,   134,   135,   136,    76,   161,
     162,    58,    60,   210,   211,   212,   120,    63,    86,    87,
      88,    89,    90,    77,   152,    64,    78,   157,   158,   173,
      86,    87,    88,    89,    90,    65,    80,    85,   103,   163,
     104,    86,    87,    88,    89,    90,    92,   105,    96,    97,
      98,    99,   100,   101,   111,   138,   167,    86,    87,    88,
      89,    90,   139,   201,   202,   140,   141,   150,   153,   154,
     205,    86,    87,    88,    89,    90,   183,   155,   156,   159,
       6,   160,     7,   168,   170,     8,   174,   197,   171,   172,
       9,   177,   182,   193,    10,    11,    42,   199,   189,    12,
     190,   194,    13,    14,    15,    16,   191,    17,   200,    18,
     196,    19,   203,   208,   217,    42,    20,    21,    22,   218,
       0,    23,     0,    24,     0,     0,    25,   128,     0,    26,
      27,    28,     0,    29,    30,    31,     0,     0,     6,     0,
      46,    86,    87,    88,    89,    90,     0,     0,    32,    33,
       0,     0,    34,    35,    36,    37,     0,    38,     0,     0,
      39,    14,    15,    16,     0,     0,     0,    40,    86,    87,
      88,    89,    90,     0,    20,    21,    22,   121,     0,    23,
       0,    24,     0,     0,    25,     0,     0,    26,    27,    28,
       0,    29,    30,    31,     0,     0,     6,     0,    46,     0,
      47,    86,    87,    88,    89,    90,    32,    33,     0,     0,
      34,    35,   151,    37,     0,    48,     0,     0,    39,    14,
      15,    16,     0,     0,     0,    49,    86,    87,    88,    89,
      90,     0,    20,    21,    22,     0,     0,    23,     0,    24,
       0,     0,    25,     0,     0,    26,    27,    28,     0,    29,
      30,    31,     0,     0,    96,    97,    98,    99,   100,   101,
       0,     0,     0,     0,    32,    33,     0,     0,    34,    35,
       0,    37,     0,    48,     0,     0,    39,    86,    87,    88,
      89,    90,     0,    40,     0,     0,   121,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   142,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   143,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   144,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   148,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   149,    86,    87,    88,
      89,    90,     0,     0,   119,     0,   181,    86,    87,    88,
      89,    90
};

static const yytype_int16 yycheck[] =
{
       4,    13,     5,    20,     9,     5,     5,     5,    67,     0,
     112,    51,   190,     5,     9,    19,     9,    88,     9,     9,
      89,    16,    62,    82,    83,    84,    85,    86,    33,    19,
      34,   209,     9,    37,    38,    39,    40,    49,    31,     9,
      44,    35,    19,    37,    48,    49,     9,    59,     5,    19,
      73,    74,    56,    57,    58,    29,    56,    56,    56,    63,
      64,    65,   164,    67,    56,    82,    83,    84,    85,    86,
     110,   173,    90,   175,     5,     9,    90,    80,    29,    90,
      92,    15,    86,    87,    88,    89,    90,    84,    85,    86,
      23,    24,    96,    97,    98,    99,   100,   101,     5,   139,
     140,    90,    29,   205,   206,   207,    68,    90,    82,    83,
      84,    85,    86,     5,   118,    90,     5,   129,   130,   159,
      82,    83,    84,    85,    86,    90,     5,    87,    21,   141,
      68,    82,    83,    84,    85,    86,    90,     5,    59,    60,
      61,    62,    63,    64,    87,     3,   150,    82,    83,    84,
      85,    86,     5,   193,   194,    91,    20,    92,     5,     5,
     200,    82,    83,    84,    85,    86,   170,    91,     5,    14,
       3,    20,     5,     5,    89,     8,     3,   189,    91,    91,
      13,    87,     5,     3,    17,    18,   190,   191,    30,    22,
      29,     3,    25,    26,    27,    28,    36,    30,    15,    32,
      31,    34,    38,    87,    38,   209,    39,    40,    41,    87,
      -1,    44,    -1,    46,    -1,    -1,    49,    68,    -1,    52,
      53,    54,    -1,    56,    57,    58,    -1,    -1,     3,    -1,
       5,    82,    83,    84,    85,    86,    -1,    -1,    71,    72,
      -1,    -1,    75,    76,    77,    78,    -1,    80,    -1,    -1,
      83,    26,    27,    28,    -1,    -1,    -1,    90,    82,    83,
      84,    85,    86,    -1,    39,    40,    41,    91,    -1,    44,
      -1,    46,    -1,    -1,    49,    -1,    -1,    52,    53,    54,
      -1,    56,    57,    58,    -1,    -1,     3,    -1,     5,    -1,
      65,    82,    83,    84,    85,    86,    71,    72,    -1,    -1,
      75,    76,    68,    78,    -1,    80,    -1,    -1,    83,    26,
      27,    28,    -1,    -1,    -1,    90,    82,    83,    84,    85,
      86,    -1,    39,    40,    41,    -1,    -1,    44,    -1,    46,
      -1,    -1,    49,    -1,    -1,    52,    53,    54,    -1,    56,
      57,    58,    -1,    -1,    59,    60,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    71,    72,    -1,    -1,    75,    76,
      -1,    78,    -1,    80,    -1,    -1,    83,    82,    83,    84,
      85,    86,    -1,    90,    -1,    -1,    91,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    82,    83,    84,
      85,    86,    -1,    -1,    -1,    -1,    91,    82,    83,    84,
      85,    86,    -1,    -1,    79,    -1,    91,    82,    83,    84,
      85,    86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    94,     0,     9,    95,    88,     3,     5,     8,    13,
      17,    18,    22,    25,    26,    27,    28,    30,    32,    34,
      39,    40,    41,    44,    46,    49,    52,    53,    54,    56,
      57,    58,    71,    72,    75,    76,    77,    78,    80,    83,
      90,   100,   111,   112,    89,     9,     5,    65,    80,    90,
     111,   114,     5,     5,    90,   114,    90,    90,    90,   105,
      29,    96,   111,    90,    90,    90,     5,    80,     5,    56,
       5,    56,     5,    56,     5,    56,     5,     5,     5,   111,
       5,   111,   111,   111,   111,    87,    82,    83,    84,    85,
      86,   111,    90,   111,   111,   114,    59,    60,    61,    62,
      63,    64,    96,    21,    68,     5,   113,   111,   111,   111,
     114,    87,   108,    96,   111,   111,   111,   111,    20,    79,
      68,    91,   111,   111,   111,   111,   111,   114,    68,    73,
      74,   111,   111,   111,   111,   111,   111,   101,     3,     5,
      91,    20,    91,    91,    91,    96,    94,   110,    91,    91,
      92,    68,   111,     5,     5,    91,     5,   114,   114,    14,
      20,    96,    96,   114,   106,    33,    97,   111,     5,    67,
      89,    91,    91,    96,     3,   109,    94,    87,    35,    37,
      98,    91,     5,   111,    94,    23,    24,    94,   107,    30,
      29,    36,   102,     3,     3,    19,    31,   114,   100,   111,
      15,    96,    96,    38,    29,    96,   104,   103,    87,    99,
      94,    94,    94,   100,    16,    19,    19,    38,    87
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    93,    94,    94,    95,    95,    96,    97,    97,    98,
      99,    97,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   102,   100,   103,   100,   104,   100,   105,   106,   107,
     100,   108,   100,   109,   100,   110,   100,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   112,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114
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
#line 159 "fransous.y"
       { }
#line 1408 "fransous.bison.cpp"
    break;

  case 5: /* label: LABEL ':'  */
#line 163 "fransous.y"
                   { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1417 "fransous.bison.cpp"
    break;

  case 7: /* case: %empty  */
#line 171 "fransous.y"
       {}
#line 1423 "fransous.bison.cpp"
    break;

  case 8: /* case: case DEFAULT SEPARATOR instruction BREAK '\n'  */
#line 172 "fransous.y"
                                                        { breakN.push_back(ic);
                                                          add_instruction(JMP);
                                                        }
#line 1431 "fransous.bison.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 175 "fransous.y"
               {(yyvsp[0].adresse).save = ic-1;}
#line 1437 "fransous.bison.cpp"
    break;

  case 10: /* $@2: %empty  */
#line 176 "fransous.y"
                            {add_instruction(EGAL);
                            (yyvsp[-2].adresse).jc = ic; 
                            add_instruction(JMPCOND);}
#line 1445 "fransous.bison.cpp"
    break;

  case 11: /* case: case $@1 CASE expr SEPARATOR $@2 instruction BREAK '\n'  */
#line 180 "fransous.y"
                   {breakN.push_back(ic) ;
                    add_instruction(JMP);
                    code_genere[(yyvsp[-6].adresse).jc].value = ic;
                    add_instruction(VARID, 0, code_genere[(yyvsp[-8].adresse).save].name);}
#line 1454 "fransous.bison.cpp"
    break;

  case 12: /* instruction: %empty  */
#line 185 "fransous.y"
             {}
#line 1460 "fransous.bison.cpp"
    break;

  case 13: /* instruction: expr  */
#line 186 "fransous.y"
                       { }
#line 1466 "fransous.bison.cpp"
    break;

  case 14: /* instruction: fonction  */
#line 187 "fransous.y"
                       { }
#line 1472 "fransous.bison.cpp"
    break;

  case 15: /* instruction: TAB VAR  */
#line 188 "fransous.y"
                  {add_instruction(TAB, 0, (yyvsp[0].nom));}
#line 1478 "fransous.bison.cpp"
    break;

  case 16: /* instruction: VAR '=' expr  */
#line 189 "fransous.y"
                       { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1484 "fransous.bison.cpp"
    break;

  case 17: /* instruction: INDICE expr DE VAR '=' expr  */
#line 190 "fransous.y"
                                      {add_instruction(ASSIGNINDICE, 0, (yyvsp[-2].nom));}
#line 1490 "fransous.bison.cpp"
    break;

  case 18: /* instruction: FONCTION '(' VAR ')' separateur  */
#line 191 "fransous.y"
                                          { add_instruction(FONCTION); }
#line 1496 "fransous.bison.cpp"
    break;

  case 19: /* instruction: GOTO LABEL  */
#line 192 "fransous.y"
                       {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, (yyvsp[0].nom)); 
                        }
#line 1505 "fransous.bison.cpp"
    break;

  case 20: /* $@3: %empty  */
#line 196 "fransous.y"
                                 {(yyvsp[-2].adresse).jc = ic; add_instruction(JMPCOND); }
#line 1511 "fransous.bison.cpp"
    break;

  case 21: /* $@4: %empty  */
#line 198 "fransous.y"
                          { // Je sauvegarde l'endroit actuel pour revenir modifier l'adresse 
                          // lorsqu'elle sera connue (celle du JMP)
                          (yyvsp[-6].adresse).jmp = ic;
                          add_instruction(JMP);
                          // Je mets à jour l'adresse du saut conditionnel
                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                        }
#line 1523 "fransous.bison.cpp"
    break;

  case 22: /* instruction: IF condition separateur $@3 THEN separateur lignes $@4 ELSE separateur lignes ENDIF  */
#line 207 "fransous.y"
                        { // Je mets à jour l'adresse du saut inconditionnel
                        code_genere[(yyvsp[-11].adresse).jmp].value = ic;}
#line 1530 "fransous.bison.cpp"
    break;

  case 23: /* $@5: %empty  */
#line 209 "fransous.y"
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
#line 1551 "fransous.bison.cpp"
    break;

  case 24: /* instruction: FOR VAR BETWEEN NUM AND NUM INCR NUM separateur $@5 lignes ENDFOR  */
#line 226 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;
                                                              add_instruction(SUPPR, 0, (yyvsp[-10].nom));}
#line 1560 "fransous.bison.cpp"
    break;

  case 25: /* $@6: %empty  */
#line 230 "fransous.y"
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
#line 1581 "fransous.bison.cpp"
    break;

  case 26: /* instruction: FOR VAR BETWEEN NUM AND NUM DECR NUM separateur $@6 lignes ENDFOR  */
#line 247 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;
                                                              add_instruction(SUPPR, 0, (yyvsp[-10].nom));}
#line 1590 "fransous.bison.cpp"
    break;

  case 27: /* $@7: %empty  */
#line 252 "fransous.y"
                                                      { (yyvsp[0].adresse).jmp = ic;}
#line 1596 "fransous.bison.cpp"
    break;

  case 28: /* $@8: %empty  */
#line 253 "fransous.y"
                                                      {(yyvsp[-3].adresse).jc = ic;
                                                        add_instruction(JMPCOND);
                                                      }
#line 1604 "fransous.bison.cpp"
    break;

  case 29: /* $@9: %empty  */
#line 256 "fransous.y"
                                                      { add_instruction(JMP, (yyvsp[-5].adresse).jmp);
                                                        code_genere[(yyvsp[-5].adresse).jc].value = ic;
                                                      }
#line 1612 "fransous.bison.cpp"
    break;

  case 31: /* $@10: %empty  */
#line 260 "fransous.y"
                                                      {(yyvsp[-1].adresse).jc = ic;}
#line 1618 "fransous.bison.cpp"
    break;

  case 32: /* instruction: DO separateur $@10 lignes ENDDO '\n' WHILE condition  */
#line 263 "fransous.y"
                                                      { add_instruction(NON);
                                                        add_instruction(JMPCOND, (yyvsp[-7].adresse).jc);}
#line 1625 "fransous.bison.cpp"
    break;

  case 33: /* $@11: %empty  */
#line 266 "fransous.y"
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
#line 1646 "fransous.bison.cpp"
    break;

  case 34: /* instruction: FOREACH VAR DE VAR separateur $@11 lignes ENDFOR  */
#line 283 "fransous.y"
                                                      { add_instruction(JMP);
                                                        code_genere[ic-1].value = (yyvsp[-7].adresse).jmp;
                                                        code_genere[(yyvsp[-7].adresse).jc].value = ic;
                                                        add_instruction(SUPPR, 0, (yyvsp[-6].nom));
                                                        add_instruction(SUPPR, 0, "1");
                                                      }
#line 1657 "fransous.bison.cpp"
    break;

  case 35: /* $@12: %empty  */
#line 289 "fransous.y"
                                                      { if(!breakN.empty()){
                                                          adresseBreak.push_back(breakN);
                                                          breakN.clear();
                                                        }}
#line 1666 "fransous.bison.cpp"
    break;

  case 36: /* instruction: SWITCH expr separateur $@12 case ENDSWITCH  */
#line 294 "fransous.y"
                                                      {for(auto itr : breakN){
                                                          code_genere[itr].value = ic;
                                                        }
                                                        breakN.clear();
                                                        if(!adresseBreak.empty()){
                                                          breakN = adresseBreak.back();
                                                          adresseBreak.pop_back();
                                                        } 
                                                      }
#line 1680 "fransous.bison.cpp"
    break;

  case 37: /* expr: NUM  */
#line 303 "fransous.y"
          {add_instruction (NUM, (yyvsp[0].valeur));}
#line 1686 "fransous.bison.cpp"
    break;

  case 38: /* expr: VARAPO  */
#line 304 "fransous.y"
             {add_instruction(VARAPO, 0, (yyvsp[0].nom));}
#line 1692 "fransous.bison.cpp"
    break;

  case 39: /* expr: VAR  */
#line 305 "fransous.y"
          {add_instruction (VAR, 0, (yyvsp[0].nom)); }
#line 1698 "fransous.bison.cpp"
    break;

  case 40: /* expr: VRAI  */
#line 306 "fransous.y"
           {add_instruction (NUM, true);}
#line 1704 "fransous.bison.cpp"
    break;

  case 41: /* expr: FAUX  */
#line 307 "fransous.y"
           {add_instruction (NUM, false);}
#line 1710 "fransous.bison.cpp"
    break;

  case 42: /* expr: SIN '(' expr ')'  */
#line 308 "fransous.y"
                        {add_instruction(SIN);}
#line 1716 "fransous.bison.cpp"
    break;

  case 43: /* expr: COS '(' expr ')'  */
#line 309 "fransous.y"
                        {add_instruction(COS);}
#line 1722 "fransous.bison.cpp"
    break;

  case 44: /* expr: TAN '(' expr ')'  */
#line 310 "fransous.y"
                        {add_instruction(TAN);}
#line 1728 "fransous.bison.cpp"
    break;

  case 45: /* expr: EXP '(' expr ')'  */
#line 311 "fransous.y"
                        {add_instruction(EXP);}
#line 1734 "fransous.bison.cpp"
    break;

  case 46: /* expr: SQRT '(' expr ')'  */
#line 312 "fransous.y"
                        {add_instruction(SQRT);}
#line 1740 "fransous.bison.cpp"
    break;

  case 47: /* expr: POW '(' expr ',' expr ')'  */
#line 313 "fransous.y"
                              {add_instruction(POW);}
#line 1746 "fransous.bison.cpp"
    break;

  case 48: /* expr: '(' expr ')'  */
#line 314 "fransous.y"
                         { (yyval.valeur) = (yyvsp[-1].valeur);}
#line 1752 "fransous.bison.cpp"
    break;

  case 49: /* expr: expr MOD expr  */
#line 315 "fransous.y"
                    {add_instruction(MOD);}
#line 1758 "fransous.bison.cpp"
    break;

  case 50: /* expr: expr ADD expr  */
#line 316 "fransous.y"
                    {add_instruction(ADD);}
#line 1764 "fransous.bison.cpp"
    break;

  case 51: /* expr: expr SUB expr  */
#line 317 "fransous.y"
                    {add_instruction(SUB);}
#line 1770 "fransous.bison.cpp"
    break;

  case 52: /* expr: SUB expr  */
#line 318 "fransous.y"
                {add_instruction(NUM, -1); add_instruction(MULT);}
#line 1776 "fransous.bison.cpp"
    break;

  case 53: /* expr: expr MULT expr  */
#line 319 "fransous.y"
                     {add_instruction(MULT);}
#line 1782 "fransous.bison.cpp"
    break;

  case 54: /* expr: expr DIV expr  */
#line 320 "fransous.y"
                    {add_instruction(DIV);}
#line 1788 "fransous.bison.cpp"
    break;

  case 55: /* expr: INCREMENTER VAR  */
#line 321 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(ADD); 
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1797 "fransous.bison.cpp"
    break;

  case 56: /* expr: DECREMENTER VAR  */
#line 325 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(SUB);
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1806 "fransous.bison.cpp"
    break;

  case 57: /* expr: TABADD expr A VAR  */
#line 329 "fransous.y"
                         {add_instruction(TABADD, 0, (yyvsp[0].nom));}
#line 1812 "fransous.bison.cpp"
    break;

  case 58: /* expr: INDICE expr DE VAR  */
#line 330 "fransous.y"
                          {add_instruction(INDICE, 0, (yyvsp[0].nom));}
#line 1818 "fransous.bison.cpp"
    break;

  case 59: /* expr: SUPPR INDICE expr DE VAR  */
#line 331 "fransous.y"
                                {add_instruction(SUPPR, 1, (yyvsp[0].nom));}
#line 1824 "fransous.bison.cpp"
    break;

  case 60: /* expr: SUPPR VAR  */
#line 332 "fransous.y"
                 {add_instruction(SUPPR, 0, (yyvsp[0].nom));}
#line 1830 "fransous.bison.cpp"
    break;

  case 61: /* expr: TOLOWER VAR  */
#line 333 "fransous.y"
                   {add_instruction(TOLOWERVAR, 0, (yyvsp[0].nom));}
#line 1836 "fransous.bison.cpp"
    break;

  case 62: /* expr: TOLOWER VARAPO  */
#line 334 "fransous.y"
                      {add_instruction(TOLOWERVARAPO, 0, (yyvsp[0].nom));}
#line 1842 "fransous.bison.cpp"
    break;

  case 63: /* expr: UPPER VAR  */
#line 335 "fransous.y"
                 {add_instruction(UPPERVAR, 0, (yyvsp[0].nom));}
#line 1848 "fransous.bison.cpp"
    break;

  case 64: /* expr: UPPER VARAPO  */
#line 336 "fransous.y"
                    {add_instruction(UPPERVARAPO, 0, (yyvsp[0].nom));}
#line 1854 "fransous.bison.cpp"
    break;

  case 65: /* expr: FIRST VAR  */
#line 337 "fransous.y"
                 {add_instruction(FIRST, 0, (yyvsp[0].nom));}
#line 1860 "fransous.bison.cpp"
    break;

  case 66: /* expr: FIRST VARAPO  */
#line 338 "fransous.y"
                    {add_instruction(FIRST, 0, (yyvsp[0].nom));}
#line 1866 "fransous.bison.cpp"
    break;

  case 67: /* expr: LAST VAR  */
#line 339 "fransous.y"
                {add_instruction(LAST, 0, (yyvsp[0].nom));}
#line 1872 "fransous.bison.cpp"
    break;

  case 68: /* expr: LAST VARAPO  */
#line 340 "fransous.y"
                   {add_instruction(LAST, 0, (yyvsp[0].nom));}
#line 1878 "fransous.bison.cpp"
    break;

  case 69: /* expr: SIZE VAR  */
#line 341 "fransous.y"
                {add_instruction(SIZE, 0, (yyvsp[0].nom));}
#line 1884 "fransous.bison.cpp"
    break;

  case 70: /* expr: ENDL  */
#line 342 "fransous.y"
            {add_instruction(ENDL);}
#line 1890 "fransous.bison.cpp"
    break;

  case 71: /* expr: CONCAT expr AND expr DANS VAR  */
#line 343 "fransous.y"
                                     { add_instruction(CONCAT); add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1896 "fransous.bison.cpp"
    break;

  case 72: /* fonction: PRINT condition concatenation  */
#line 347 "fransous.y"
                                        {add_instruction(PRINT);}
#line 1902 "fransous.bison.cpp"
    break;

  case 73: /* concatenation: %empty  */
#line 350 "fransous.y"
                {}
#line 1908 "fransous.bison.cpp"
    break;

  case 74: /* concatenation: concatenation AND condition  */
#line 351 "fransous.y"
                                            {add_instruction(CONCAT);}
#line 1914 "fransous.bison.cpp"
    break;

  case 76: /* condition: expr SUP expr  */
#line 357 "fransous.y"
                         {add_instruction(SUP);}
#line 1920 "fransous.bison.cpp"
    break;

  case 77: /* condition: expr INF expr  */
#line 358 "fransous.y"
                         {add_instruction(INF);}
#line 1926 "fransous.bison.cpp"
    break;

  case 78: /* condition: expr SUPEG expr  */
#line 359 "fransous.y"
                           {add_instruction(SUPEG);}
#line 1932 "fransous.bison.cpp"
    break;

  case 79: /* condition: expr INFEG expr  */
#line 360 "fransous.y"
                           {add_instruction(INFEG);}
#line 1938 "fransous.bison.cpp"
    break;

  case 80: /* condition: expr DIFF expr  */
#line 361 "fransous.y"
                          {add_instruction(DIFF);}
#line 1944 "fransous.bison.cpp"
    break;

  case 81: /* condition: expr EGAL expr  */
#line 362 "fransous.y"
                          {add_instruction(EGAL);}
#line 1950 "fransous.bison.cpp"
    break;

  case 82: /* condition: NON '(' condition ')'  */
#line 363 "fransous.y"
                               {add_instruction(NON);}
#line 1956 "fransous.bison.cpp"
    break;

  case 83: /* condition: '(' condition ORCOND condition ')'  */
#line 364 "fransous.y"
                                            {add_instruction(ORCOND);}
#line 1962 "fransous.bison.cpp"
    break;

  case 84: /* condition: '(' condition ANDCOND condition ')'  */
#line 365 "fransous.y"
                                             {add_instruction(ANDCOND);}
#line 1968 "fransous.bison.cpp"
    break;


#line 1972 "fransous.bison.cpp"

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

#line 366 "fransous.y"



int yyerror(char *s) {					
    printf("%s : \"%s\"\n", s, yytext);
}



// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
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
    case OPENFR   : return "OPENFR"; break;
    case OPENFW   : return "OPENFW"; break;
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
  }
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
  char r4[50], r5[50];
  string r6, r7;
  stringstream r8;


  //printf("C'est quoi la réponse à la grande question sur la vie, l'univers et le reste ?\n");

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
          // Si elle existe bien sur... 
        if(variables.find(ins.name) == variables.end()){
          variables[ins.name] = make_tuple(1,0,"");
        }
        pile.push(variables.at(ins.name));
        ic++;
      break;
      case VARID:
        pile.push(variables[ins.name]);
        //pile.push(make_tuple(1,get<1>(variables.at(ins.name)),"" ));
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
      case FONCTION:                    ///////// /!\ A REFAIRE
        r1 = get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = get<1>(pile.top());
        pile.top();
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

  /*for (int i = 0; i < code_genere.size(); i++){
    auto instruction = code_genere [i];
    cout << i 
         << '\t'
         << print_code(instruction.code) 
         << '\t'
         << instruction.value 
         << '\t' 
         << instruction.name 
         << endl;
  }*/

  execution(code_genere, variables, variablesTables);

  return 0;
}
