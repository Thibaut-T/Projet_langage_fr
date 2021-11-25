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
    map<double, string> variablesString;
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

#line 113 "fransous.bison.cpp"

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
  YYSYMBOL_TAB = 68,                       /* TAB  */
  YYSYMBOL_ADD = 69,                       /* ADD  */
  YYSYMBOL_SUB = 70,                       /* SUB  */
  YYSYMBOL_MULT = 71,                      /* MULT  */
  YYSYMBOL_DIV = 72,                       /* DIV  */
  YYSYMBOL_73_n_ = 73,                     /* '\n'  */
  YYSYMBOL_74_ = 74,                       /* ':'  */
  YYSYMBOL_75_ = 75,                       /* '='  */
  YYSYMBOL_76_ = 76,                       /* '('  */
  YYSYMBOL_77_ = 77,                       /* ')'  */
  YYSYMBOL_78_ = 78,                       /* ','  */
  YYSYMBOL_YYACCEPT = 79,                  /* $accept  */
  YYSYMBOL_lignes = 80,                    /* lignes  */
  YYSYMBOL_label = 81,                     /* label  */
  YYSYMBOL_separateur = 82,                /* separateur  */
  YYSYMBOL_case = 83,                      /* case  */
  YYSYMBOL_84_1 = 84,                      /* $@1  */
  YYSYMBOL_85_2 = 85,                      /* $@2  */
  YYSYMBOL_instruction = 86,               /* instruction  */
  YYSYMBOL_87_3 = 87,                      /* $@3  */
  YYSYMBOL_88_4 = 88,                      /* $@4  */
  YYSYMBOL_89_5 = 89,                      /* $@5  */
  YYSYMBOL_90_6 = 90,                      /* $@6  */
  YYSYMBOL_91_7 = 91,                      /* $@7  */
  YYSYMBOL_92_8 = 92,                      /* $@8  */
  YYSYMBOL_93_9 = 93,                      /* $@9  */
  YYSYMBOL_94_10 = 94,                     /* $@10  */
  YYSYMBOL_95_11 = 95,                     /* $@11  */
  YYSYMBOL_expr = 96,                      /* expr  */
  YYSYMBOL_fonction = 97,                  /* fonction  */
  YYSYMBOL_condition = 98                  /* condition  */
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
#define YYLAST   275

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   327


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
      73,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      76,    77,     2,     2,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,     2,
       2,    75,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   139,   139,   140,   142,   143,   148,   151,   152,   154,
     155,   154,   164,   165,   166,   167,   168,   169,   173,   175,
     173,   187,   187,   207,   207,   228,   229,   232,   228,   236,
     236,   241,   244,   244,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   278,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   297,   298,   299,   300,   301,   302,   303,
     304
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
  "DECREMENTER", "TAB", "ADD", "SUB", "MULT", "DIV", "'\\n'", "':'", "'='",
  "'('", "')'", "','", "$accept", "lignes", "label", "separateur", "case",
  "$@1", "$@2", "instruction", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "expr", "fonction", "condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-28)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -153,     8,  -153,   -64,   138,  -153,  -153,   -51,    28,    82,
      47,   -21,    10,   170,    18,    25,    29,  -153,    55,   170,
      31,    39,    40,   170,   170,   170,   170,    87,    34,    54,
      57,   113,  -153,  -153,  -153,   119,   120,   170,   170,    53,
      -7,  -153,   170,  -153,  -153,    60,   161,    55,   118,  -153,
     135,    -7,   170,   170,   170,    82,    71,  -153,   -27,   170,
     170,   170,    -7,    -7,   -58,   203,  -153,   140,   142,   145,
    -153,  -153,  -153,     5,    19,  -153,   170,   170,   170,   170,
      -7,    82,   170,   170,   170,   170,   170,   170,  -153,   154,
       7,    84,    42,   123,   157,    55,  -153,  -153,  -153,   172,
     181,   -11,   170,   170,  -153,  -153,  -153,  -153,     5,     5,
    -153,  -153,    85,    -7,    -7,    -7,    -7,    -7,    -7,   153,
     139,  -153,    55,  -153,  -153,  -153,  -153,    -2,  -153,  -153,
    -153,   170,   190,    -7,  -153,    55,   166,  -153,  -153,   101,
      16,   194,   170,  -153,    80,    -6,   146,  -153,   173,   163,
    -153,    -7,    26,   198,   200,   175,    82,   138,   170,   192,
      55,    55,  -153,  -153,   174,    -1,    55,  -153,  -153,   151,
    -153,  -153,  -153,  -153,  -153,   138,    23,    21,    27,   187,
    -153,  -153,  -153,   162,  -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     1,     0,    12,     5,    34,    36,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    37,    38,     0,     0,     0,     0,     0,
      13,    14,     0,    17,    36,     0,    63,     0,     0,     2,
       0,    62,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,    53,    54,     0,     0,    57,     0,     0,     0,
      61,    51,    52,    48,     0,     3,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       4,     0,     0,     0,     0,     0,     6,     2,    32,     0,
       0,     0,     0,     0,    58,    59,    60,    45,    46,    47,
      49,    50,     0,    65,    64,    67,    66,    69,    68,     0,
       0,    31,     0,    39,    40,    41,    26,     4,     7,    42,
      43,     0,     0,    56,    70,     0,     0,    16,     2,     0,
       9,     0,     0,     2,     0,     4,     0,    33,     0,     0,
      44,    55,     4,     0,     0,     0,     0,    12,     0,     0,
       0,     0,    28,    30,     0,     0,     0,    23,    21,     0,
      10,     2,     2,     2,     8,    12,     4,     4,     4,     0,
      20,    24,    22,     0,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,   -43,  -153,   -29,  -153,  -153,  -153,  -152,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,    -4,  -153,   -54
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     4,    57,   140,   149,   175,    39,   119,   159,
     173,   172,    55,   138,   155,    97,   128,    46,    41,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    95,    56,     3,   102,   164,    90,     3,     2,    51,
       5,    76,    77,    78,    79,    58,     3,     3,    88,    62,
      63,    64,    65,   179,    42,   -27,   121,   112,   170,    98,
       3,   139,     3,    73,    74,     3,     3,    43,    80,   180,
     181,   -19,    76,    77,    78,    79,   182,    49,    92,    93,
      94,   147,    48,   148,   127,    99,   100,   101,    76,    77,
      78,    79,    76,    77,    78,    79,   126,   131,    76,    77,
      78,    79,   108,   109,   110,   111,    78,    79,   113,   114,
     115,   116,   117,   118,    56,     6,    50,    44,    76,    77,
      78,    79,    66,   137,    52,   145,   107,    67,   132,   133,
     152,    53,   163,   153,   154,    54,   143,    59,    14,    15,
      16,    76,    77,    78,    79,    60,    61,    68,    70,   123,
      69,    20,    21,    22,    71,    72,    75,   141,   176,   177,
     178,   167,   168,    32,    33,    34,    81,   171,   151,    89,
      91,     6,    45,     7,    96,   104,     8,   105,    35,    36,
     106,     9,    37,    40,   165,    10,    11,   120,    38,   136,
      12,   122,   134,    13,    14,    15,    16,   135,    17,   144,
      18,    40,    19,     6,   146,    44,   156,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    76,    77,    78,    79,    14,    15,    16,   158,
     124,   160,   157,   161,    35,    36,   162,   166,    37,    20,
      21,    22,   169,     0,    38,    82,    83,    84,    85,    86,
      87,    32,    33,    34,   174,   183,    76,    77,    78,    79,
      76,    77,    78,    79,   125,   184,    35,    36,     0,     0,
      37,    76,    77,    78,    79,     0,    38,     0,     0,   129,
      76,    77,    78,    79,   142,     0,     0,     0,   130,    76,
      77,    78,    79,    76,    77,    78,    79,     0,   103,     0,
       0,   150,    76,    77,    78,    79
};

static const yytype_int16 yycheck[] =
{
       4,    55,    29,     9,    62,   157,    49,     9,     0,    13,
      74,    69,    70,    71,    72,    19,     9,     9,    47,    23,
      24,    25,    26,   175,    75,    31,    19,    81,    29,    58,
       9,    33,     9,    37,    38,     9,     9,     9,    42,    16,
      19,    15,    69,    70,    71,    72,    19,    68,    52,    53,
      54,    35,     5,    37,    97,    59,    60,    61,    69,    70,
      71,    72,    69,    70,    71,    72,    95,    78,    69,    70,
      71,    72,    76,    77,    78,    79,    71,    72,    82,    83,
      84,    85,    86,    87,    29,     3,    76,     5,    69,    70,
      71,    72,     5,   122,    76,   138,    77,    63,   102,   103,
     143,    76,   156,    23,    24,    76,   135,    76,    26,    27,
      28,    69,    70,    71,    72,    76,    76,    63,     5,    77,
      63,    39,    40,    41,     5,     5,    73,   131,   171,   172,
     173,   160,   161,    51,    52,    53,    76,   166,   142,    21,
       5,     3,    60,     5,    73,     5,     8,     5,    66,    67,
       5,    13,    70,   157,   158,    17,    18,     3,    76,    20,
      22,    77,    77,    25,    26,    27,    28,    14,    30,     3,
      32,   175,    34,     3,    73,     5,    30,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    69,    70,    71,    72,    26,    27,    28,    36,
      77,     3,    29,     3,    66,    67,    31,    15,    70,    39,
      40,    41,    38,    -1,    76,    54,    55,    56,    57,    58,
      59,    51,    52,    53,    73,    38,    69,    70,    71,    72,
      69,    70,    71,    72,    77,    73,    66,    67,    -1,    -1,
      70,    69,    70,    71,    72,    -1,    76,    -1,    -1,    77,
      69,    70,    71,    72,    64,    -1,    -1,    -1,    77,    69,
      70,    71,    72,    69,    70,    71,    72,    -1,    65,    -1,
      -1,    77,    69,    70,    71,    72
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    80,     0,     9,    81,    74,     3,     5,     8,    13,
      17,    18,    22,    25,    26,    27,    28,    30,    32,    34,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    66,    67,    70,    76,    86,
      96,    97,    75,     9,     5,    60,    96,    98,     5,    68,
      76,    96,    76,    76,    76,    91,    29,    82,    96,    76,
      76,    76,    96,    96,    96,    96,     5,    63,    63,    63,
       5,     5,     5,    96,    96,    73,    69,    70,    71,    72,
      96,    76,    54,    55,    56,    57,    58,    59,    82,    21,
      80,     5,    96,    96,    96,    98,    73,    94,    82,    96,
      96,    96,    62,    65,     5,     5,     5,    77,    96,    96,
      96,    96,    98,    96,    96,    96,    96,    96,    96,    87,
       3,    19,    77,    77,    77,    77,    82,    80,    95,    77,
      77,    78,    96,    96,    77,    14,    20,    82,    92,    33,
      83,    96,    64,    82,     3,    80,    73,    35,    37,    84,
      77,    96,    80,    23,    24,    93,    30,    29,    36,    88,
       3,     3,    31,    98,    86,    96,    15,    82,    82,    38,
      29,    82,    90,    89,    73,    85,    80,    80,    80,    86,
      16,    19,    19,    38,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    82,    83,    83,    84,
      85,    83,    86,    86,    86,    86,    86,    86,    87,    88,
      86,    89,    86,    90,    86,    91,    92,    93,    86,    94,
      86,    86,    95,    86,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     2,     0,     6,     0,
       0,     9,     0,     1,     1,     3,     5,     2,     0,     0,
      12,     0,    12,     0,    12,     0,     0,     0,     8,     0,
       8,     4,     0,     6,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     6,     3,     3,     3,     2,     3,
       3,     2,     2,     2,     2,     6,     4,     2,     3,     3,
       3,     2,     2,     1,     3,     3,     3,     3,     3,     3,
       4
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
#line 139 "fransous.y"
       { }
#line 1333 "fransous.bison.cpp"
    break;

  case 5: /* label: LABEL ':'  */
#line 143 "fransous.y"
                   { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1342 "fransous.bison.cpp"
    break;

  case 7: /* case: %empty  */
#line 151 "fransous.y"
       {}
#line 1348 "fransous.bison.cpp"
    break;

  case 8: /* case: case DEFAULT SEPARATOR instruction BREAK '\n'  */
#line 152 "fransous.y"
                                                        { breakN.push_back(ic);
                                                          add_instruction(JMP);}
#line 1355 "fransous.bison.cpp"
    break;

  case 9: /* $@1: %empty  */
#line 154 "fransous.y"
               {(yyvsp[0].adresse).save = ic-1;}
#line 1361 "fransous.bison.cpp"
    break;

  case 10: /* $@2: %empty  */
#line 155 "fransous.y"
                            {add_instruction(EGAL);
                            (yyvsp[-2].adresse).jc = ic; 
                            add_instruction(JMPCOND);}
#line 1369 "fransous.bison.cpp"
    break;

  case 11: /* case: case $@1 CASE expr SEPARATOR $@2 instruction BREAK '\n'  */
#line 159 "fransous.y"
                   {breakN.push_back(ic) ;
                    add_instruction(JMP);
                    code_genere[(yyvsp[-6].adresse).jc].value = ic;
                    add_instruction(VARID, 0, code_genere[(yyvsp[-8].adresse).save].name);}
#line 1378 "fransous.bison.cpp"
    break;

  case 12: /* instruction: %empty  */
#line 164 "fransous.y"
             {}
#line 1384 "fransous.bison.cpp"
    break;

  case 13: /* instruction: expr  */
#line 165 "fransous.y"
                       { }
#line 1390 "fransous.bison.cpp"
    break;

  case 14: /* instruction: fonction  */
#line 166 "fransous.y"
                       { }
#line 1396 "fransous.bison.cpp"
    break;

  case 15: /* instruction: VAR '=' expr  */
#line 167 "fransous.y"
                       { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1402 "fransous.bison.cpp"
    break;

  case 16: /* instruction: FONCTION '(' VAR ')' separateur  */
#line 168 "fransous.y"
                                          { add_instruction(FONCTION); }
#line 1408 "fransous.bison.cpp"
    break;

  case 17: /* instruction: GOTO LABEL  */
#line 169 "fransous.y"
                       {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, (yyvsp[0].nom)); 
                        }
#line 1417 "fransous.bison.cpp"
    break;

  case 18: /* $@3: %empty  */
#line 173 "fransous.y"
                                 {(yyvsp[-2].adresse).jc = ic; add_instruction(JMPCOND); }
#line 1423 "fransous.bison.cpp"
    break;

  case 19: /* $@4: %empty  */
#line 175 "fransous.y"
                          { // Je sauvegarde l'endroit actuel pour revenir modifier l'adresse 
                          // lorsqu'elle sera connue (celle du JMP)
                          (yyvsp[-6].adresse).jmp = ic;
                          add_instruction(JMP);
                          // Je mets à jour l'adresse du saut conditionnel
                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                        }
#line 1435 "fransous.bison.cpp"
    break;

  case 20: /* instruction: IF condition separateur $@3 THEN separateur lignes $@4 ELSE separateur lignes ENDIF  */
#line 184 "fransous.y"
                        { // Je mets à jour l'adresse du saut inconditionnel
                        code_genere[(yyvsp[-11].adresse).jmp].value = ic;}
#line 1442 "fransous.bison.cpp"
    break;

  case 21: /* $@5: %empty  */
#line 187 "fransous.y"
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
#line 1463 "fransous.bison.cpp"
    break;

  case 22: /* instruction: FOR VAR BETWEEN NUM AND NUM INCR NUM separateur $@5 lignes ENDFOR  */
#line 204 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;}
#line 1471 "fransous.bison.cpp"
    break;

  case 23: /* $@6: %empty  */
#line 207 "fransous.y"
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
                                                                add_instruction(INF);
                                                                (yyvsp[-8].adresse).jc = ic;
                                                                add_instruction(JMPCOND);}
#line 1492 "fransous.bison.cpp"
    break;

  case 24: /* instruction: FOR VAR BETWEEN NUM AND NUM DECR NUM separateur $@6 lignes ENDFOR  */
#line 224 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;}
#line 1500 "fransous.bison.cpp"
    break;

  case 25: /* $@7: %empty  */
#line 228 "fransous.y"
                                                      { (yyvsp[0].adresse).jmp = ic;}
#line 1506 "fransous.bison.cpp"
    break;

  case 26: /* $@8: %empty  */
#line 229 "fransous.y"
                                                      {(yyvsp[-3].adresse).jc = ic;
                                                        add_instruction(JMPCOND);
                                                      }
#line 1514 "fransous.bison.cpp"
    break;

  case 27: /* $@9: %empty  */
#line 232 "fransous.y"
                                                      { add_instruction(JMP, (yyvsp[-5].adresse).jmp);
                                                        code_genere[(yyvsp[-5].adresse).jc].value = ic;
                                                      }
#line 1522 "fransous.bison.cpp"
    break;

  case 29: /* $@10: %empty  */
#line 236 "fransous.y"
                                                      {(yyvsp[-1].adresse).jc = ic;}
#line 1528 "fransous.bison.cpp"
    break;

  case 30: /* instruction: DO separateur $@10 lignes ENDDO '\n' WHILE condition  */
#line 239 "fransous.y"
                                                    { add_instruction(NON);
                                                        add_instruction(JMPCOND, (yyvsp[-7].adresse).jc);}
#line 1535 "fransous.bison.cpp"
    break;

  case 32: /* $@11: %empty  */
#line 244 "fransous.y"
                                                      { if(!breakN.empty()){
                                                          adresseBreak.push_back(breakN);
                                                          breakN.clear();
                                                        }}
#line 1544 "fransous.bison.cpp"
    break;

  case 33: /* instruction: SWITCH expr separateur $@11 case ENDSWITCH  */
#line 249 "fransous.y"
                                                      {for(auto itr : breakN){
                                                          code_genere[itr].value = ic;
                                                          }
                                                        breakN.clear();
                                                        if(!adresseBreak.empty()){
                                                          breakN = adresseBreak.back();
                                                          adresseBreak.pop_back();
                                                        } }
#line 1557 "fransous.bison.cpp"
    break;

  case 34: /* expr: NUM  */
#line 257 "fransous.y"
          {add_instruction (NUM, (yyvsp[0].valeur));}
#line 1563 "fransous.bison.cpp"
    break;

  case 35: /* expr: VARAPO  */
#line 258 "fransous.y"
             {add_instruction(VARAPO, 0, (yyvsp[0].nom));}
#line 1569 "fransous.bison.cpp"
    break;

  case 36: /* expr: VAR  */
#line 259 "fransous.y"
          {add_instruction (VAR, 0, (yyvsp[0].nom)); }
#line 1575 "fransous.bison.cpp"
    break;

  case 37: /* expr: VRAI  */
#line 260 "fransous.y"
           {add_instruction (NUM, true);}
#line 1581 "fransous.bison.cpp"
    break;

  case 38: /* expr: FAUX  */
#line 261 "fransous.y"
           {add_instruction (NUM, false);}
#line 1587 "fransous.bison.cpp"
    break;

  case 39: /* expr: SIN '(' expr ')'  */
#line 262 "fransous.y"
                        {add_instruction(SIN);}
#line 1593 "fransous.bison.cpp"
    break;

  case 40: /* expr: COS '(' expr ')'  */
#line 263 "fransous.y"
                        {add_instruction(COS);}
#line 1599 "fransous.bison.cpp"
    break;

  case 41: /* expr: TAN '(' expr ')'  */
#line 264 "fransous.y"
                        {add_instruction(TAN);}
#line 1605 "fransous.bison.cpp"
    break;

  case 42: /* expr: EXP '(' expr ')'  */
#line 265 "fransous.y"
                        {add_instruction(EXP);}
#line 1611 "fransous.bison.cpp"
    break;

  case 43: /* expr: SQRT '(' expr ')'  */
#line 266 "fransous.y"
                        {add_instruction(SQRT);}
#line 1617 "fransous.bison.cpp"
    break;

  case 44: /* expr: POW '(' expr ',' expr ')'  */
#line 267 "fransous.y"
                              {add_instruction(POW);}
#line 1623 "fransous.bison.cpp"
    break;

  case 45: /* expr: '(' expr ')'  */
#line 268 "fransous.y"
                         { (yyval.valeur) = (yyvsp[-1].valeur);}
#line 1629 "fransous.bison.cpp"
    break;

  case 46: /* expr: expr ADD expr  */
#line 269 "fransous.y"
                    {add_instruction(ADD);}
#line 1635 "fransous.bison.cpp"
    break;

  case 47: /* expr: expr SUB expr  */
#line 270 "fransous.y"
                    {add_instruction(SUB);}
#line 1641 "fransous.bison.cpp"
    break;

  case 48: /* expr: SUB expr  */
#line 271 "fransous.y"
                {add_instruction(NUM, -1); add_instruction(MULT);}
#line 1647 "fransous.bison.cpp"
    break;

  case 49: /* expr: expr MULT expr  */
#line 272 "fransous.y"
                     {add_instruction(MULT);}
#line 1653 "fransous.bison.cpp"
    break;

  case 50: /* expr: expr DIV expr  */
#line 273 "fransous.y"
                    {add_instruction(DIV);}
#line 1659 "fransous.bison.cpp"
    break;

  case 51: /* expr: INCREMENTER VAR  */
#line 274 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(ADD); 
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1668 "fransous.bison.cpp"
    break;

  case 52: /* expr: DECREMENTER VAR  */
#line 278 "fransous.y"
                      {add_instruction(VAR, 0, (yyvsp[0].nom)); 
                       add_instruction(NUM, 1); 
                       add_instruction(SUB);
                       add_instruction(ASSIGN, 0, (yyvsp[0].nom));}
#line 1677 "fransous.bison.cpp"
    break;

  case 53: /* fonction: OPENFR expr  */
#line 284 "fransous.y"
                       {add_instruction(OPENFR);}
#line 1683 "fransous.bison.cpp"
    break;

  case 54: /* fonction: OPENFW expr  */
#line 285 "fransous.y"
                     {add_instruction(OPENFW);}
#line 1689 "fransous.bison.cpp"
    break;

  case 55: /* fonction: SUPPR expr DANS expr JUSQUE expr  */
#line 286 "fransous.y"
                                          {add_instruction(SUPPR);}
#line 1695 "fransous.bison.cpp"
    break;

  case 56: /* fonction: NEWNAME expr EN expr  */
#line 287 "fransous.y"
                             {add_instruction(NEWNAME);}
#line 1701 "fransous.bison.cpp"
    break;

  case 57: /* fonction: TOLOWER VAR  */
#line 288 "fransous.y"
                     {add_instruction(TOLOWER);}
#line 1707 "fransous.bison.cpp"
    break;

  case 58: /* fonction: FIRST DE VAR  */
#line 289 "fransous.y"
                      {add_instruction(FIRST);}
#line 1713 "fransous.bison.cpp"
    break;

  case 59: /* fonction: LAST DE VAR  */
#line 290 "fransous.y"
                     {add_instruction(LAST);}
#line 1719 "fransous.bison.cpp"
    break;

  case 60: /* fonction: SIZE DE VAR  */
#line 291 "fransous.y"
                     {add_instruction(SIZE);}
#line 1725 "fransous.bison.cpp"
    break;

  case 61: /* fonction: WAIT VAR  */
#line 292 "fransous.y"
                  {add_instruction(WAIT);}
#line 1731 "fransous.bison.cpp"
    break;

  case 62: /* fonction: PRINT expr  */
#line 293 "fransous.y"
                    {add_instruction(PRINT);}
#line 1737 "fransous.bison.cpp"
    break;

  case 64: /* condition: expr SUP expr  */
#line 298 "fransous.y"
                         {add_instruction(SUP);}
#line 1743 "fransous.bison.cpp"
    break;

  case 65: /* condition: expr INF expr  */
#line 299 "fransous.y"
                         {add_instruction(INF);}
#line 1749 "fransous.bison.cpp"
    break;

  case 66: /* condition: expr SUPEG expr  */
#line 300 "fransous.y"
                           {add_instruction(SUPEG);}
#line 1755 "fransous.bison.cpp"
    break;

  case 67: /* condition: expr INFEG expr  */
#line 301 "fransous.y"
                           {add_instruction(INFEG);}
#line 1761 "fransous.bison.cpp"
    break;

  case 68: /* condition: expr DIFF expr  */
#line 302 "fransous.y"
                          {add_instruction(DIFF);}
#line 1767 "fransous.bison.cpp"
    break;

  case 69: /* condition: expr EGAL expr  */
#line 303 "fransous.y"
                          {add_instruction(EGAL);}
#line 1773 "fransous.bison.cpp"
    break;

  case 70: /* condition: NON '(' condition ')'  */
#line 304 "fransous.y"
                               {add_instruction(NON);}
#line 1779 "fransous.bison.cpp"
    break;


#line 1783 "fransous.bison.cpp"

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

#line 305 "fransous.y"



int yyerror(char *s) {					
    printf("%s : \"%s\"\n", s, yytext);
}



// Petite fonction pour mieux voir le code généré 
// (au lieu des nombres associés au tokens)
string print_code(int ins) {
  switch (ins) {
    case ADD      : return "ADD"; break;
    case SUB      : return "SUB"; break;
    case MULT     : return "MUL"; break;
    case DIV      : return "DIV"; break;
    case NUM      : return "NUM"; break;
    case VAR      : return "VAR"; break;
    case VARID    : return "VARID"; break;
    case VARAPO   : return "VARAPO"; break;
    case PRINT    : return "PRINT"; break;
    case ASSIGN   : return "MOV"; break;
    case JMP      : return "JMP"; break;
    case JMPCOND  : return "JC "; break;
    case INF      : return "INF"; break;
    case SUP      : return "SUP"; break;
    case SUPEG    : return "SUPEG"; break;
    case INFEG    : return "INFEG"; break;
    case EGAL     : return "EGAL"; break;
    case DIFF     : return "DIFF"; break;
    case NON      : return "NON"; break;
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
    default : return ""; break;
  }
}

// Fonction qui exécute le code généré sur un petit émulateur
void execution ( const vector <instruction> &code_genere, 
                 map<string,double> &variables )
{
  printf("\n------- Exécution du programme ---------\n");
  stack<double> pile;

  int ic = 0;  // compteur instruction
  double r1, r2, r3;  // des registres
  char r4[50], r5[50];


  printf("C'est quoi la réponse à la grande question sur la vie, l'univers et le reste ?\n");

  while (ic < code_genere.size()){   // tant que nous ne sommes pas à la fin du programme
    auto ins = code_genere[ic];
    switch (ins.code){
      case OPENFR :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        fopen(r4,"r");
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        ic++;
      break;
      case OPENFW :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        fopen(r4,"w");
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        ic++;
      break;
      /*case SUPPR :
        r1=pile.top();
        pile.pop();
        r2=pile.top();
        pile.pop();
        r3=pile.top();
        pile.pop();
        remove(r3,r2,r1); /*Enleve "A" dans camion jusque M*/
        /*ic++;
      break;*/
      case NEWNAME :
        r1=pile.top();
        pile.pop();
        strcpy(r4, variablesString[r1].c_str());
        r2=pile.top();
        pile.pop();
        strcpy(r5, variablesString[r2].c_str());
        rename(r5,r4);
        variables.erase( variables.find(variablesString[r1]));
        variablesString.erase( variablesString.find(r1));
        variables.erase( variables.find(variablesString[r2]));
        variablesString.erase( variablesString.find(r2));
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
      break;
      case SIZE : 
        r1=pile.top();
        pile.pop();
        size(r1);
        ic++;
      break;
      case WAIT :
        r1=pile.top();
        pile.pop();
        wait(r1);
        ic++;
      break;*/
      case ADD:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1+r2);
        ic++;
      break;
      case SUB:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2-r1);
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
      case DIV:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2/r1);
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
      case VARID:
            pile.push(variables[ins.name]);
            ic++;
      break;
      case VARAPO:
        r1 = variablesString.size();
        variables[ins.name] = r1;
        variablesString[r1] = ins.name;
        pile.push(variables.at(ins.name));
        ic++;
      break;
      case SUP:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2>r1);
        ic++;
      break;
      case SUPEG:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2>=r1);
        ic++;
      break;
      case INF:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2<r1);
        ic++;
      break;
      case INFEG:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r2<=r1);
        ic++;
      break;
      case EGAL:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1==r2);
        ic++;
      break;
      case DIFF:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        pile.push(r1!=r2);
        ic++;
      break;
      case NON:
        r1 = pile.top();
        pile.pop();

        pile.push(!r1);
        ic++;
      break;
      case SIN:
        r1 = pile.top();
        pile.pop();
        pile.push(sin(r1));
        ic++;
      break;
      case COS:
        r1 = pile.top();
        pile.pop();
        pile.push(cos(r1));
        ic++;
      break;
      case TAN: 
        r1 = pile.top();
        pile.pop();
        pile.push(tan(r1));
        ic++;
      break;
      case EXP:
        r1 = pile.top();
        pile.pop();
        pile.push(exp(r1));
        ic++;
      break;
      case POW:
        r1 = pile.top();
        pile.pop();
        r2 = pile.top();
        pile.pop();
        pile.push(pow(r2, r1));
        ic++;
      break;
      case SQRT:
        r1 = pile.top();
        pile.pop();
        pile.push(sqrt(r1));
        ic++;
      break;
      case FONCTION:
        r1 = pile.top();    // Rrécupérer la tête de pile;
        pile.pop();

        r2 = pile.top();
        pile.top();
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
