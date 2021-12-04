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
    map<double, string> variablesString;
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

#line 117 "fransous.bison.cpp"

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
  YYSYMBOL_FIRST = 47,                     /* FIRST  */
  YYSYMBOL_LAST = 48,                      /* LAST  */
  YYSYMBOL_SIZE = 49,                      /* SIZE  */
  YYSYMBOL_WAIT = 50,                      /* WAIT  */
  YYSYMBOL_VARAPO = 51,                    /* VARAPO  */
  YYSYMBOL_VRAI = 52,                      /* VRAI  */
  YYSYMBOL_FAUX = 53,                      /* FAUX  */
  YYSYMBOL_INF = 54,                       /* INF  */
  YYSYMBOL_SUP = 55,                       /* SUP  */
  YYSYMBOL_INFEG = 56,                     /* INFEG  */
  YYSYMBOL_SUPEG = 57,                     /* SUPEG  */
  YYSYMBOL_EGAL = 58,                      /* EGAL  */
  YYSYMBOL_DIFF = 59,                      /* DIFF  */
  YYSYMBOL_NON = 60,                       /* NON  */
  YYSYMBOL_commentaire = 61,               /* commentaire  */
  YYSYMBOL_DANS = 62,                      /* DANS  */
  YYSYMBOL_DE = 63,                        /* DE  */
  YYSYMBOL_JUSQUE = 64,                    /* JUSQUE  */
  YYSYMBOL_EN = 65,                        /* EN  */
  YYSYMBOL_INCREMENTER = 66,               /* INCREMENTER  */
  YYSYMBOL_DECREMENTER = 67,               /* DECREMENTER  */
  YYSYMBOL_ORCOND = 68,                    /* ORCOND  */
  YYSYMBOL_ANDCOND = 69,                   /* ANDCOND  */
  YYSYMBOL_CONCAT = 70,                    /* CONCAT  */
  YYSYMBOL_ENDL = 71,                      /* ENDL  */
  YYSYMBOL_TAB = 72,                       /* TAB  */
  YYSYMBOL_TABADD = 73,                    /* TABADD  */
  YYSYMBOL_A = 74,                         /* A  */
  YYSYMBOL_INDICE = 75,                    /* INDICE  */
  YYSYMBOL_ASSIGNINDICE = 76,              /* ASSIGNINDICE  */
  YYSYMBOL_ADD = 77,                       /* ADD  */
  YYSYMBOL_SUB = 78,                       /* SUB  */
  YYSYMBOL_MULT = 79,                      /* MULT  */
  YYSYMBOL_DIV = 80,                       /* DIV  */
  YYSYMBOL_81_n_ = 81,                     /* '\n'  */
  YYSYMBOL_82_ = 82,                       /* ':'  */
  YYSYMBOL_83_ = 83,                       /* '='  */
  YYSYMBOL_84_ = 84,                       /* '('  */
  YYSYMBOL_85_ = 85,                       /* ')'  */
  YYSYMBOL_86_ = 86,                       /* ','  */
  YYSYMBOL_YYACCEPT = 87,                  /* $accept  */
  YYSYMBOL_lignes = 88,                    /* lignes  */
  YYSYMBOL_label = 89,                     /* label  */
  YYSYMBOL_separateur = 90,                /* separateur  */
  YYSYMBOL_case = 91,                      /* case  */
  YYSYMBOL_92_1 = 92,                      /* $@1  */
  YYSYMBOL_93_2 = 93,                      /* $@2  */
  YYSYMBOL_instruction = 94,               /* instruction  */
  YYSYMBOL_95_3 = 95,                      /* $@3  */
  YYSYMBOL_96_4 = 96,                      /* $@4  */
  YYSYMBOL_97_5 = 97,                      /* $@5  */
  YYSYMBOL_98_6 = 98,                      /* $@6  */
  YYSYMBOL_99_7 = 99,                      /* $@7  */
  YYSYMBOL_100_8 = 100,                    /* $@8  */
  YYSYMBOL_101_9 = 101,                    /* $@9  */
  YYSYMBOL_102_10 = 102,                   /* $@10  */
  YYSYMBOL_103_11 = 103,                   /* $@11  */
  YYSYMBOL_104_12 = 104,                   /* $@12  */
  YYSYMBOL_expr = 105,                     /* expr  */
  YYSYMBOL_fonction = 106,                 /* fonction  */
  YYSYMBOL_concatenation = 107,            /* concatenation  */
  YYSYMBOL_condition = 108                 /* condition  */
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
#define YYLAST   351

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  217

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   335


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
      81,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      84,    85,     2,     2,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    82,     2,
       2,    83,     2,     2,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   151,   151,   152,   154,   155,   160,   163,   164,   166,
     167,   166,   176,   177,   178,   179,   180,   181,   182,   183,
     187,   189,   187,   201,   201,   221,   221,   242,   243,   246,
     242,   250,   250,   256,   256,   279,   279,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   313,   317,   318,   319,   320,
     321,   322,   323,   326,   327,   328,   329,   330,   331,   334,
     335,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347
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
  "NEWNAME", "TOLOWER", "FIRST", "LAST", "SIZE", "WAIT", "VARAPO", "VRAI",
  "FAUX", "INF", "SUP", "INFEG", "SUPEG", "EGAL", "DIFF", "NON",
  "commentaire", "DANS", "DE", "JUSQUE", "EN", "INCREMENTER",
  "DECREMENTER", "ORCOND", "ANDCOND", "CONCAT", "ENDL", "TAB", "TABADD",
  "A", "INDICE", "ASSIGNINDICE", "ADD", "SUB", "MULT", "DIV", "'\\n'",
  "':'", "'='", "'('", "')'", "','", "$accept", "lignes", "label",
  "separateur", "case", "$@1", "$@2", "instruction", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "expr", "fonction",
  "concatenation", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -175,     3,  -175,   -78,   126,  -175,  -175,   -66,    51,   185,
      59,    62,    -7,   238,     2,     5,    12,  -175,    56,   238,
      13,    22,    25,   238,   238,   238,   238,    75,    45,    52,
     109,   123,  -175,  -175,  -175,   125,   127,  -175,   130,   238,
     238,   238,   238,    57,   220,  -175,   238,  -175,  -175,    49,
     238,   185,   -29,    56,   121,    83,   144,   220,   238,   238,
     238,   185,    69,  -175,    -6,   238,   238,   238,   220,   220,
      43,   170,  -175,   150,   152,  -175,  -175,  -175,  -175,  -175,
      39,    47,   -36,   142,  -175,   238,   238,   238,   238,   220,
     185,   128,   216,     7,   238,   238,   238,   238,   238,   238,
    -175,   156,   157,    76,   166,   203,   240,   249,    56,  -175,
    -175,  -175,   253,   262,   103,   238,   238,  -175,  -175,   182,
     189,  -175,   -36,   -36,  -175,  -175,   110,   191,   185,   185,
     220,   220,   220,   220,   220,   220,   186,   194,    56,    56,
     238,  -175,  -175,  -175,  -175,    -2,  -175,  -175,  -175,   238,
     138,   220,  -175,   140,  -175,  -175,   124,   143,    56,   226,
    -175,  -175,   220,  -175,   149,     4,   266,   238,   238,  -175,
    -175,  -175,    46,  -175,     1,   209,  -175,   211,   206,  -175,
     220,   220,    50,   241,   243,    -3,   222,   185,   126,   238,
     239,    56,    56,  -175,  -175,  -175,   217,    24,    56,  -175,
    -175,   176,  -175,  -175,  -175,  -175,  -175,   126,    36,    -1,
      15,   221,  -175,  -175,  -175,   180,  -175
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     1,     0,    12,     5,    37,    39,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    40,    41,     0,     0,    62,     0,     0,
       0,     0,     0,     0,    13,    14,     0,    19,    39,     0,
       0,     0,    71,     0,     0,     0,     0,    69,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,    63,    64,
       0,     0,    58,     0,     0,    61,    67,    54,    55,    15,
       0,     0,    51,     0,     3,     0,     0,     0,     0,    16,
       0,     0,    71,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,    68,     0,     0,     0,     0,     6,
       2,    35,     0,     0,     0,     0,     0,    59,    60,     0,
       0,    48,    49,    50,    52,    53,     0,     0,     0,     0,
      73,    72,    75,    74,    77,    76,     0,     0,     0,     0,
       0,    42,    43,    44,    28,     4,     7,    45,    46,     0,
       0,    66,    56,    57,    78,    57,     0,     0,     0,     0,
      33,    18,    70,     2,     0,     9,     0,     0,     0,    79,
      80,     2,     0,     2,     4,     0,    36,     0,     0,    47,
      65,    17,     4,     0,     0,     4,     0,     0,    12,     0,
       0,     0,     0,    34,    30,    32,     0,     0,     0,    25,
      23,     0,    10,     2,     2,     2,     8,    12,     4,     4,
       4,     0,    22,    26,    24,     0,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -105,  -175,   -51,  -175,  -175,  -175,  -174,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,    -4,  -175,
    -175,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     4,    63,   165,   178,   207,    43,   136,   190,
     205,   204,    61,   163,   186,   110,   173,   146,    52,    45,
     104,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    93,   100,     2,     5,   145,     3,     3,     3,    57,
       3,   108,     3,   111,   196,    64,   193,    46,   213,    68,
      69,    70,    71,    62,     3,    94,    95,    96,    97,    98,
      99,   164,   -29,   211,   214,    80,    81,    82,    83,   176,
     126,   177,    89,    87,    88,     3,    91,    92,    85,    86,
      87,    88,   212,   202,   105,   106,   107,   144,   174,     3,
      47,   112,   113,   114,    54,   -21,   182,    55,   185,   183,
     184,    85,    86,    87,    88,   128,   129,    56,   156,   157,
      72,   122,   123,   124,   125,    62,    58,   160,   161,    59,
     130,   131,   132,   133,   134,   135,    60,    65,   208,   209,
     210,    85,    86,    87,    88,   115,    66,   171,    73,    67,
     120,   150,   151,   119,    75,    74,    85,    86,    87,    88,
      85,    86,    87,    88,    85,    86,    87,    88,    76,     6,
      77,     7,    78,    90,     8,    79,   162,   195,    84,     9,
     199,   200,   101,    10,    11,   166,   102,   203,    12,   103,
     109,    13,    14,    15,    16,   117,    17,   118,    18,   137,
      19,   139,   138,   180,   181,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      85,    86,    87,    88,    44,   197,   140,   152,     6,   149,
      48,   127,    35,    36,   153,   154,   155,    37,    38,    39,
     158,    40,   167,    44,    41,    85,    86,    87,    88,   169,
      42,    14,    15,    16,   159,    85,    86,    87,    88,    85,
      86,    87,    88,   168,    20,    21,    22,   121,   170,   172,
     175,    27,    28,    29,    30,   116,    32,    33,    34,   187,
     188,     6,   189,    48,   191,    49,   192,    85,    86,    87,
      88,    35,    36,   194,   198,   201,    37,   206,    39,   215,
      50,   216,     0,    41,    14,    15,    16,     0,     0,    51,
      94,    95,    96,    97,    98,    99,     0,    20,    21,    22,
      85,    86,    87,    88,    27,    28,    29,    30,   141,    32,
      33,    34,     0,    85,    86,    87,    88,    85,    86,    87,
      88,   121,     0,     0,    35,    36,     0,     0,     0,    37,
       0,    39,     0,    50,     0,     0,    41,    85,    86,    87,
      88,     0,    42,     0,     0,   142,    85,    86,    87,    88,
      85,    86,    87,    88,   143,     0,     0,     0,   147,    85,
      86,    87,    88,    85,    86,    87,    88,   148,     0,     0,
       0,   179
};

static const yytype_int16 yycheck[] =
{
       4,    51,    53,     0,    82,   110,     9,     9,     9,    13,
       9,    61,     9,    64,   188,    19,    19,    83,    19,    23,
      24,    25,    26,    29,     9,    54,    55,    56,    57,    58,
      59,    33,    31,   207,    19,    39,    40,    41,    42,    35,
      90,    37,    46,    79,    80,     9,    50,    51,    77,    78,
      79,    80,    16,    29,    58,    59,    60,   108,   163,     9,
       9,    65,    66,    67,     5,    15,   171,     5,   173,    23,
      24,    77,    78,    79,    80,    68,    69,    84,   128,   129,
       5,    85,    86,    87,    88,    29,    84,   138,   139,    84,
      94,    95,    96,    97,    98,    99,    84,    84,   203,   204,
     205,    77,    78,    79,    80,    62,    84,   158,    63,    84,
      63,   115,   116,    74,     5,    63,    77,    78,    79,    80,
      77,    78,    79,    80,    77,    78,    79,    80,     5,     3,
       5,     5,     5,    84,     8,     5,   140,   187,    81,    13,
     191,   192,    21,    17,    18,   149,    63,   198,    22,     5,
      81,    25,    26,    27,    28,     5,    30,     5,    32,     3,
      34,    85,     5,   167,   168,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      77,    78,    79,    80,   188,   189,    20,     5,     3,    86,
       5,    63,    66,    67,     5,    85,     5,    71,    72,    73,
      14,    75,    64,   207,    78,    77,    78,    79,    80,    85,
      84,    26,    27,    28,    20,    77,    78,    79,    80,    77,
      78,    79,    80,    83,    39,    40,    41,    85,    85,     3,
      81,    46,    47,    48,    49,    65,    51,    52,    53,    30,
      29,     3,    36,     5,     3,    60,     3,    77,    78,    79,
      80,    66,    67,    31,    15,    38,    71,    81,    73,    38,
      75,    81,    -1,    78,    26,    27,    28,    -1,    -1,    84,
      54,    55,    56,    57,    58,    59,    -1,    39,    40,    41,
      77,    78,    79,    80,    46,    47,    48,    49,    85,    51,
      52,    53,    -1,    77,    78,    79,    80,    77,    78,    79,
      80,    85,    -1,    -1,    66,    67,    -1,    -1,    -1,    71,
      -1,    73,    -1,    75,    -1,    -1,    78,    77,    78,    79,
      80,    -1,    84,    -1,    -1,    85,    77,    78,    79,    80,
      77,    78,    79,    80,    85,    -1,    -1,    -1,    85,    77,
      78,    79,    80,    77,    78,    79,    80,    85,    -1,    -1,
      -1,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    88,     0,     9,    89,    82,     3,     5,     8,    13,
      17,    18,    22,    25,    26,    27,    28,    30,    32,    34,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    66,    67,    71,    72,    73,
      75,    78,    84,    94,   105,   106,    83,     9,     5,    60,
      75,    84,   105,   108,     5,     5,    84,   105,    84,    84,
      84,    99,    29,    90,   105,    84,    84,    84,   105,   105,
     105,   105,     5,    63,    63,     5,     5,     5,     5,     5,
     105,   105,   105,   105,    81,    77,    78,    79,    80,   105,
      84,   105,   105,   108,    54,    55,    56,    57,    58,    59,
      90,    21,    63,     5,   107,   105,   105,   105,   108,    81,
     102,    90,   105,   105,   105,    62,    65,     5,     5,    74,
      63,    85,   105,   105,   105,   105,   108,    63,    68,    69,
     105,   105,   105,   105,   105,   105,    95,     3,     5,    85,
      20,    85,    85,    85,    90,    88,   104,    85,    85,    86,
     105,   105,     5,     5,    85,     5,   108,   108,    14,    20,
      90,    90,   105,   100,    33,    91,   105,    64,    83,    85,
      85,    90,     3,   103,    88,    81,    35,    37,    92,    85,
     105,   105,    88,    23,    24,    88,   101,    30,    29,    36,
      96,     3,     3,    19,    31,   108,    94,   105,    15,    90,
      90,    38,    29,    90,    98,    97,    81,    93,    88,    88,
      88,    94,    16,    19,    19,    38,    81
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    87,    88,    88,    89,    89,    90,    91,    91,    92,
      93,    91,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    96,    94,    97,    94,    98,    94,    99,   100,   101,
      94,   102,    94,   103,    94,   104,    94,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     2,     0,     6,     0,
       0,     9,     0,     1,     1,     2,     3,     6,     5,     2,
       0,     0,    12,     0,    12,     0,    12,     0,     0,     0,
       8,     0,     8,     0,     8,     0,     6,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     6,     3,     3,
       3,     2,     3,     3,     2,     2,     4,     4,     2,     3,
       3,     2,     1,     2,     2,     6,     4,     2,     3,     0,
       3,     1,     3,     3,     3,     3,     3,     3,     4,     5,
       5
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
#line 151 "fransous.y"
       { }
#line 1380 "fransous.bison.cpp"
    break;

  case 5: /* label: LABEL ':'  */
#line 155 "fransous.y"
                   { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1389 "fransous.bison.cpp"
    break;

  case 7: /* case: %empty  */
#line 163 "fransous.y"
       {}
#line 1395 "fransous.bison.cpp"
    break;

  case 8: /* case: case DEFAULT SEPARATOR instruction BREAK '\n'  */
#line 164 "fransous.y"
                                                        { breakN.push_back(ic);
                                                          add_instruction(JMP);}
#line 1402 "fransous.bison.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 166 "fransous.y"
               {(yyvsp[0].adresse).save = ic-1;}
#line 1408 "fransous.bison.cpp"
    break;

  case 10: /* $@2: %empty  */
#line 167 "fransous.y"
                            {add_instruction(EGAL);
                            (yyvsp[-2].adresse).jc = ic; 
                            add_instruction(JMPCOND);}
#line 1416 "fransous.bison.cpp"
    break;

  case 11: /* case: case $@1 CASE expr SEPARATOR $@2 instruction BREAK '\n'  */
#line 171 "fransous.y"
                   {breakN.push_back(ic) ;
                    add_instruction(JMP);
                    code_genere[(yyvsp[-6].adresse).jc].value = ic;
                    add_instruction(VARID, 0, code_genere[(yyvsp[-8].adresse).save].name);}
#line 1425 "fransous.bison.cpp"
    break;

  case 12: /* instruction: %empty  */
#line 176 "fransous.y"
             {}
#line 1431 "fransous.bison.cpp"
    break;

  case 13: /* instruction: expr  */
#line 177 "fransous.y"
                       { }
#line 1437 "fransous.bison.cpp"
    break;

  case 14: /* instruction: fonction  */
#line 178 "fransous.y"
                       { }
#line 1443 "fransous.bison.cpp"
    break;

  case 15: /* instruction: TAB VAR  */
#line 179 "fransous.y"
                  {add_instruction(TAB, 0, (yyvsp[0].nom));}
#line 1449 "fransous.bison.cpp"
    break;

  case 16: /* instruction: VAR '=' expr  */
#line 180 "fransous.y"
                       { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1455 "fransous.bison.cpp"
    break;

  case 17: /* instruction: INDICE expr DE VAR '=' expr  */
#line 181 "fransous.y"
                                      {add_instruction(ASSIGNINDICE, 0, (yyvsp[-2].nom));}
#line 1461 "fransous.bison.cpp"
    break;

  case 18: /* instruction: FONCTION '(' VAR ')' separateur  */
#line 182 "fransous.y"
                                          { add_instruction(FONCTION); }
#line 1467 "fransous.bison.cpp"
    break;

  case 19: /* instruction: GOTO LABEL  */
#line 183 "fransous.y"
                       {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, (yyvsp[0].nom)); 
                        }
#line 1476 "fransous.bison.cpp"
    break;

  case 20: /* $@3: %empty  */
#line 187 "fransous.y"
                                 {(yyvsp[-2].adresse).jc = ic; add_instruction(JMPCOND); }
#line 1482 "fransous.bison.cpp"
    break;

  case 21: /* $@4: %empty  */
#line 189 "fransous.y"
                          { // Je sauvegarde l'endroit actuel pour revenir modifier l'adresse 
                          // lorsqu'elle sera connue (celle du JMP)
                          (yyvsp[-6].adresse).jmp = ic;
                          add_instruction(JMP);
                          // Je mets à jour l'adresse du saut conditionnel
                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                        }
#line 1494 "fransous.bison.cpp"
    break;

  case 22: /* instruction: IF condition separateur $@3 THEN separateur lignes $@4 ELSE separateur lignes ENDIF  */
#line 198 "fransous.y"
                        { // Je mets à jour l'adresse du saut inconditionnel
                        code_genere[(yyvsp[-11].adresse).jmp].value = ic;}
#line 1501 "fransous.bison.cpp"
    break;

  case 23: /* $@5: %empty  */
#line 201 "fransous.y"
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
#line 1522 "fransous.bison.cpp"
    break;

  case 24: /* instruction: FOR VAR BETWEEN NUM AND NUM INCR NUM separateur $@5 lignes ENDFOR  */
#line 218 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;}
#line 1530 "fransous.bison.cpp"
    break;

  case 25: /* $@6: %empty  */
#line 221 "fransous.y"
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
#line 1551 "fransous.bison.cpp"
    break;

  case 26: /* instruction: FOR VAR BETWEEN NUM AND NUM DECR NUM separateur $@6 lignes ENDFOR  */
#line 238 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;}
#line 1559 "fransous.bison.cpp"
    break;

  case 27: /* $@7: %empty  */
#line 242 "fransous.y"
                                                      { (yyvsp[0].adresse).jmp = ic;}
#line 1565 "fransous.bison.cpp"
    break;

  case 28: /* $@8: %empty  */
#line 243 "fransous.y"
                                                      {(yyvsp[-3].adresse).jc = ic;
                                                        add_instruction(JMPCOND);
                                                      }
#line 1573 "fransous.bison.cpp"
    break;

  case 29: /* $@9: %empty  */
#line 246 "fransous.y"
                                                      { add_instruction(JMP, (yyvsp[-5].adresse).jmp);
                                                        code_genere[(yyvsp[-5].adresse).jc].value = ic;
                                                      }
#line 1581 "fransous.bison.cpp"
    break;

  case 31: /* $@10: %empty  */
#line 250 "fransous.y"
                                                      {(yyvsp[-1].adresse).jc = ic;}
#line 1587 "fransous.bison.cpp"
    break;

  case 32: /* instruction: DO separateur $@10 lignes ENDDO '\n' WHILE condition  */
#line 253 "fransous.y"
                                                      { add_instruction(NON);
                                                        add_instruction(JMPCOND, (yyvsp[-7].adresse).jc);}
#line 1594 "fransous.bison.cpp"
    break;

  case 33: /* $@11: %empty  */
#line 256 "fransous.y"
                                                      { add_instruction(VAR, 0, "1");
                                                        //add_instruction(NUM, -1);
                                                        //add_instruction(ASSIGN, 0, "1");
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
#line 1617 "fransous.bison.cpp"
    break;

  case 34: /* instruction: FOREACH VAR DE VAR separateur $@11 lignes ENDFOR  */
#line 275 "fransous.y"
                                                      { add_instruction(JMP);
                                                        code_genere[ic-1].value = (yyvsp[-7].adresse).jmp;
                                                        code_genere[(yyvsp[-7].adresse).jc].value = ic;
                                                      }
#line 1626 "fransous.bison.cpp"
    break;

  case 35: /* $@12: %empty  */
#line 279 "fransous.y"
                                                      { if(!breakN.empty()){
                                                          adresseBreak.push_back(breakN);
                                                          breakN.clear();
                                                        }}
#line 1635 "fransous.bison.cpp"
    break;

  case 36: /* instruction: SWITCH expr separateur $@12 case ENDSWITCH  */
#line 284 "fransous.y"
                                                      {for(auto itr : breakN){
                                                          code_genere[itr].value = ic;
                                                          }
                                                        breakN.clear();
                                                        if(!adresseBreak.empty()){
                                                          breakN = adresseBreak.back();
                                                          adresseBreak.pop_back();
                                                        } }
#line 1648 "fransous.bison.cpp"
    break;

  case 37: /* expr: NUM  */
#line 292 "fransous.y"
          {add_instruction (NUM, (yyvsp[0].valeur));}
#line 1654 "fransous.bison.cpp"
    break;

  case 38: /* expr: VARAPO  */
#line 293 "fransous.y"
             {add_instruction(VARAPO, 0, (yyvsp[0].nom));}
#line 1660 "fransous.bison.cpp"
    break;

  case 39: /* expr: VAR  */
#line 294 "fransous.y"
          {add_instruction (VAR, 0, (yyvsp[0].nom)); }
#line 1666 "fransous.bison.cpp"
    break;

  case 40: /* expr: VRAI  */
#line 295 "fransous.y"
           {add_instruction (NUM, true);}
#line 1672 "fransous.bison.cpp"
    break;

  case 41: /* expr: FAUX  */
#line 296 "fransous.y"
           {add_instruction (NUM, false);}
#line 1678 "fransous.bison.cpp"
    break;

  case 42: /* expr: SIN '(' expr ')'  */
#line 297 "fransous.y"
                        {add_instruction(SIN);}
#line 1684 "fransous.bison.cpp"
    break;

  case 43: /* expr: COS '(' expr ')'  */
#line 298 "fransous.y"
                        {add_instruction(COS);}
#line 1690 "fransous.bison.cpp"
    break;

  case 44: /* expr: TAN '(' expr ')'  */
#line 299 "fransous.y"
                        {add_instruction(TAN);}
#line 1696 "fransous.bison.cpp"
    break;

  case 45: /* expr: EXP '(' expr ')'  */
#line 300 "fransous.y"
                        {add_instruction(EXP);}
#line 1702 "fransous.bison.cpp"
    break;

  case 46: /* expr: SQRT '(' expr ')'  */
#line 301 "fransous.y"
                        {add_instruction(SQRT);}
#line 1708 "fransous.bison.cpp"
    break;

  case 47: /* expr: POW '(' expr ',' expr ')'  */
#line 302 "fransous.y"
                              {add_instruction(POW);}
#line 1714 "fransous.bison.cpp"
    break;

  case 48: /* expr: '(' expr ')'  */
#line 303 "fransous.y"
                         { (yyval.valeur) = (yyvsp[-1].valeur);}
#line 1720 "fransous.bison.cpp"
    break;

  case 49: /* expr: expr ADD expr  */
#line 304 "fransous.y"
                    {add_instruction(ADD);}
#line 1726 "fransous.bison.cpp"
    break;

  case 50: /* expr: expr SUB expr  */
#line 305 "fransous.y"
                    {add_instruction(SUB);}
#line 1732 "fransous.bison.cpp"
    break;

  case 51: /* expr: SUB expr  */
#line 306 "fransous.y"
                {add_instruction(NUM, -1); add_instruction(MULT);}
#line 1738 "fransous.bison.cpp"
    break;

  case 52: /* expr: expr MULT expr  */
#line 307 "fransous.y"
                     {add_instruction(MULT);}
#line 1744 "fransous.bison.cpp"
    break;

  case 53: /* expr: expr DIV expr  */
#line 308 "fransous.y"
                    {add_instruction(DIV);}
#line 1750 "fransous.bison.cpp"
    break;

  case 54: /* expr: INCREMENTER VAR  */
#line 309 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(ADD); 
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1759 "fransous.bison.cpp"
    break;

  case 55: /* expr: DECREMENTER VAR  */
#line 313 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(SUB);
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1768 "fransous.bison.cpp"
    break;

  case 56: /* expr: TABADD expr A VAR  */
#line 317 "fransous.y"
                         {add_instruction(TABADD, 0, (yyvsp[0].nom));}
#line 1774 "fransous.bison.cpp"
    break;

  case 57: /* expr: INDICE expr DE VAR  */
#line 318 "fransous.y"
                          {add_instruction(INDICE, 0, (yyvsp[0].nom));}
#line 1780 "fransous.bison.cpp"
    break;

  case 58: /* expr: TOLOWER VAR  */
#line 319 "fransous.y"
                   {add_instruction(TOLOWER);}
#line 1786 "fransous.bison.cpp"
    break;

  case 59: /* expr: FIRST DE VAR  */
#line 320 "fransous.y"
                    {add_instruction(FIRST);}
#line 1792 "fransous.bison.cpp"
    break;

  case 60: /* expr: LAST DE VAR  */
#line 321 "fransous.y"
                   {add_instruction(LAST);}
#line 1798 "fransous.bison.cpp"
    break;

  case 61: /* expr: SIZE VAR  */
#line 322 "fransous.y"
                {add_instruction(SIZE, 0, (yyvsp[0].nom));}
#line 1804 "fransous.bison.cpp"
    break;

  case 62: /* expr: ENDL  */
#line 323 "fransous.y"
            {add_instruction(ENDL);}
#line 1810 "fransous.bison.cpp"
    break;

  case 63: /* fonction: OPENFR expr  */
#line 326 "fransous.y"
                       {add_instruction(OPENFR);}
#line 1816 "fransous.bison.cpp"
    break;

  case 64: /* fonction: OPENFW expr  */
#line 327 "fransous.y"
                     {add_instruction(OPENFW);}
#line 1822 "fransous.bison.cpp"
    break;

  case 65: /* fonction: SUPPR expr DANS expr JUSQUE expr  */
#line 328 "fransous.y"
                                          {add_instruction(SUPPR);}
#line 1828 "fransous.bison.cpp"
    break;

  case 66: /* fonction: NEWNAME expr EN expr  */
#line 329 "fransous.y"
                             {add_instruction(NEWNAME);}
#line 1834 "fransous.bison.cpp"
    break;

  case 67: /* fonction: WAIT VAR  */
#line 330 "fransous.y"
                  {add_instruction(WAIT);}
#line 1840 "fransous.bison.cpp"
    break;

  case 68: /* fonction: PRINT expr concatenation  */
#line 331 "fransous.y"
                                  {add_instruction(PRINT);}
#line 1846 "fransous.bison.cpp"
    break;

  case 69: /* concatenation: %empty  */
#line 334 "fransous.y"
                {}
#line 1852 "fransous.bison.cpp"
    break;

  case 70: /* concatenation: concatenation AND expr  */
#line 335 "fransous.y"
                                       {add_instruction(CONCAT);}
#line 1858 "fransous.bison.cpp"
    break;

  case 72: /* condition: expr SUP expr  */
#line 339 "fransous.y"
                         {add_instruction(SUP);}
#line 1864 "fransous.bison.cpp"
    break;

  case 73: /* condition: expr INF expr  */
#line 340 "fransous.y"
                         {add_instruction(INF);}
#line 1870 "fransous.bison.cpp"
    break;

  case 74: /* condition: expr SUPEG expr  */
#line 341 "fransous.y"
                           {add_instruction(SUPEG);}
#line 1876 "fransous.bison.cpp"
    break;

  case 75: /* condition: expr INFEG expr  */
#line 342 "fransous.y"
                           {add_instruction(INFEG);}
#line 1882 "fransous.bison.cpp"
    break;

  case 76: /* condition: expr DIFF expr  */
#line 343 "fransous.y"
                          {add_instruction(DIFF);}
#line 1888 "fransous.bison.cpp"
    break;

  case 77: /* condition: expr EGAL expr  */
#line 344 "fransous.y"
                          {add_instruction(EGAL);}
#line 1894 "fransous.bison.cpp"
    break;

  case 78: /* condition: NON '(' condition ')'  */
#line 345 "fransous.y"
                               {add_instruction(NON);}
#line 1900 "fransous.bison.cpp"
    break;

  case 79: /* condition: '(' condition ORCOND condition ')'  */
#line 346 "fransous.y"
                                            {add_instruction(ORCOND);}
#line 1906 "fransous.bison.cpp"
    break;

  case 80: /* condition: '(' condition ANDCOND condition ')'  */
#line 347 "fransous.y"
                                             {add_instruction(ANDCOND);}
#line 1912 "fransous.bison.cpp"
    break;


#line 1916 "fransous.bison.cpp"

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

#line 348 "fransous.y"



int yyerror(char *s) {					
    printf("%s : \"%s\"\n", s, yytext);
}



// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
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


  printf("C'est quoi la réponse à la grande question sur la vie, l'univers et le reste ?\n");

  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
    auto ins = code_genere[ic];
    switch (ins.code){
      case OPENFR :                                 //////// REFAIRE
        /*if(pile.top().first == -1)r1=pile.top().second;
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        fopen(r4,"r");*/
        /*variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));*/
        ic++;
      break;
      case OPENFW :                                 //////// REFAIRE
        /*if(pile.top().first == -1)r1=pile.top().second;
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        fopen(r4,"w");*/
        /*variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));*/
        ic++;
      break;
      case SUPPR :
        /*r1=pile.top();
        pile.pop();
        r2=pile.top();
        pile.pop();
        r3=pile.top();
        pile.pop();
        remove(r3,r2,r1); /*Enleve "A" dans camion jusque M*/
        ic++;
      break;
      case NEWNAME :                                 //////// REFAIRE
        /*r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        r2=pile.top();
        pile.pop();
        strcpy(r5, variablesString[r2].c_str());
        rename(r5,r4);
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        variables.erase( variables.find(variablesString[r2]));
        variablesString.erase( variablesString.find(r2));*/
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
      break;*/
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
      /*case WAIT :
        r1=pile.top();
        pile.pop();
        wait(r1);
        ic++;
      break;*/
      case ADD:
        if(get<0>(pile.top()) == 1) r1=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        if(get<0>(pile.top()) == 1) r2=get<1>(pile.top());    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(make_tuple(1,r1+r2,""));
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

  execution(code_genere, variables, variablesTables);

  return 0;
}
