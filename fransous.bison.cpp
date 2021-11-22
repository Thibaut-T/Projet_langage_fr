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
    int ic = 0;
    map<string,int> adresses;
    vector <instruction> code_genere;

    int add_instruction(const int &c, const double &v=0, const string &n="") {
        code_genere.push_back(instruction(c,v,n)); 
        ic++;
        return 0; 
    }; 

#line 111 "fransous.bison.cpp"

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
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_SI = 5,                         /* SI  */
  YYSYMBOL_GOTO = 6,                       /* GOTO  */
  YYSYMBOL_LABEL = 7,                      /* LABEL  */
  YYSYMBOL_JMP = 8,                        /* JMP  */
  YYSYMBOL_JMPCOND = 9,                    /* JMPCOND  */
  YYSYMBOL_ASSIGN = 10,                    /* ASSIGN  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_THEN = 12,                      /* THEN  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_ENDIF = 14,                     /* ENDIF  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_ENDFOR = 16,                    /* ENDFOR  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_BETWEEN = 18,                   /* BETWEEN  */
  YYSYMBOL_DECR = 19,                      /* DECR  */
  YYSYMBOL_INCR = 20,                      /* INCR  */
  YYSYMBOL_PRINT = 21,                     /* PRINT  */
  YYSYMBOL_SIN = 22,                       /* SIN  */
  YYSYMBOL_COS = 23,                       /* COS  */
  YYSYMBOL_TAN = 24,                       /* TAN  */
  YYSYMBOL_SEPARATOR = 25,                 /* SEPARATOR  */
  YYSYMBOL_WHILE = 26,                     /* WHILE  */
  YYSYMBOL_ENDWHILE = 27,                  /* ENDWHILE  */
  YYSYMBOL_DO = 28,                        /* DO  */
  YYSYMBOL_SWITCH = 29,                    /* SWITCH  */
  YYSYMBOL_ENDSWITCH = 30,                 /* ENDSWITCH  */
  YYSYMBOL_CASE = 31,                      /* CASE  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_EXP = 33,                       /* EXP  */
  YYSYMBOL_SQRT = 34,                      /* SQRT  */
  YYSYMBOL_POW = 35,                       /* POW  */
  YYSYMBOL_OPENFR = 36,                    /* OPENFR  */
  YYSYMBOL_OPENFW = 37,                    /* OPENFW  */
  YYSYMBOL_SUPPR = 38,                     /* SUPPR  */
  YYSYMBOL_NEWNAME = 39,                   /* NEWNAME  */
  YYSYMBOL_TOLOWER = 40,                   /* TOLOWER  */
  YYSYMBOL_FIRST = 41,                     /* FIRST  */
  YYSYMBOL_LAST = 42,                      /* LAST  */
  YYSYMBOL_SIZE = 43,                      /* SIZE  */
  YYSYMBOL_WAIT = 44,                      /* WAIT  */
  YYSYMBOL_VARAPO = 45,                    /* VARAPO  */
  YYSYMBOL_VRAI = 46,                      /* VRAI  */
  YYSYMBOL_FAUX = 47,                      /* FAUX  */
  YYSYMBOL_INF = 48,                       /* INF  */
  YYSYMBOL_SUP = 49,                       /* SUP  */
  YYSYMBOL_INFEG = 50,                     /* INFEG  */
  YYSYMBOL_SUPEG = 51,                     /* SUPEG  */
  YYSYMBOL_EGAL = 52,                      /* EGAL  */
  YYSYMBOL_DIFF = 53,                      /* DIFF  */
  YYSYMBOL_NON = 54,                       /* NON  */
  YYSYMBOL_commentaire = 55,               /* commentaire  */
  YYSYMBOL_DANS = 56,                      /* DANS  */
  YYSYMBOL_DE = 57,                        /* DE  */
  YYSYMBOL_JUSQUE = 58,                    /* JUSQUE  */
  YYSYMBOL_EN = 59,                        /* EN  */
  YYSYMBOL_ADD = 60,                       /* ADD  */
  YYSYMBOL_SUB = 61,                       /* SUB  */
  YYSYMBOL_MULT = 62,                      /* MULT  */
  YYSYMBOL_DIV = 63,                       /* DIV  */
  YYSYMBOL_64_n_ = 64,                     /* '\n'  */
  YYSYMBOL_65_ = 65,                       /* ':'  */
  YYSYMBOL_66_ = 66,                       /* '='  */
  YYSYMBOL_67_ = 67,                       /* '('  */
  YYSYMBOL_68_ = 68,                       /* ')'  */
  YYSYMBOL_69_ = 69,                       /* ','  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_lignes = 71,                    /* lignes  */
  YYSYMBOL_label = 72,                     /* label  */
  YYSYMBOL_separateur = 73,                /* separateur  */
  YYSYMBOL_case = 74,                      /* case  */
  YYSYMBOL_instruction = 75,               /* instruction  */
  YYSYMBOL_76_1 = 76,                      /* $@1  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_78_3 = 78,                      /* $@3  */
  YYSYMBOL_79_4 = 79,                      /* $@4  */
  YYSYMBOL_80_5 = 80,                      /* $@5  */
  YYSYMBOL_81_6 = 81,                      /* $@6  */
  YYSYMBOL_82_7 = 82,                      /* $@7  */
  YYSYMBOL_83_8 = 83,                      /* $@8  */
  YYSYMBOL_expr = 84,                      /* expr  */
  YYSYMBOL_fonction = 85,                  /* fonction  */
  YYSYMBOL_condition = 86,                 /* condition  */
  YYSYMBOL_var = 87                        /* var  */
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
#define YYLAST   238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  160

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
      64,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      67,    68,     2,     2,    69,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,     2,
       2,    66,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   126,   128,   129,   134,   137,   138,   140,
     141,   142,   143,   146,   150,   152,   150,   164,   164,   184,
     184,   205,   206,   209,   205,   213,   213,   217,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   251,   252,   253,   254,   255,   256,
     257,   258,   260
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
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "VAR", "SI",
  "GOTO", "LABEL", "JMP", "JMPCOND", "ASSIGN", "IF", "THEN", "ELSE",
  "ENDIF", "FOR", "ENDFOR", "AND", "BETWEEN", "DECR", "INCR", "PRINT",
  "SIN", "COS", "TAN", "SEPARATOR", "WHILE", "ENDWHILE", "DO", "SWITCH",
  "ENDSWITCH", "CASE", "BREAK", "EXP", "SQRT", "POW", "OPENFR", "OPENFW",
  "SUPPR", "NEWNAME", "TOLOWER", "FIRST", "LAST", "SIZE", "WAIT", "VARAPO",
  "VRAI", "FAUX", "INF", "SUP", "INFEG", "SUPEG", "EGAL", "DIFF", "NON",
  "commentaire", "DANS", "DE", "JUSQUE", "EN", "ADD", "SUB", "MULT", "DIV",
  "'\\n'", "':'", "'='", "'('", "')'", "','", "$accept", "lignes", "label",
  "separateur", "case", "instruction", "$@1", "$@2", "$@3", "$@4", "$@5",
  "$@6", "$@7", "$@8", "expr", "fonction", "condition", "var", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-24)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -77,    51,   -77,   -57,   105,   -77,   -77,   -55,     6,   151,
      17,   154,   -21,    -7,    11,   -77,     7,   -77,    13,    14,
      18,   154,   154,   154,   154,    57,     9,    10,    26,    80,
     -77,   -77,   -77,   154,    33,    -6,   -77,   154,   -77,   -77,
      31,   162,     7,    81,    -6,   154,   154,   154,   151,    37,
     -77,     7,   154,   154,   154,    -6,    -6,   146,   120,   -77,
      98,   101,   102,   -77,   -23,   -77,   154,   154,   154,   154,
      -6,   151,   154,   154,   154,   154,   154,   154,   -77,   107,
      28,    32,    99,     7,   -77,   -77,   -77,   103,   166,   -35,
     154,   154,   -77,   -77,   -77,   -77,    -6,    -6,   -77,   -77,
      44,    -6,    -6,    -6,    -6,    -6,    -6,   106,    97,   -77,
     -77,   -77,   -77,    -3,     0,   -77,   -77,   154,   132,    -6,
     -77,     7,   112,   -77,   151,   -77,   151,   170,   154,   -77,
      16,    -5,   -77,    92,   -77,    -6,     3,   116,   118,    95,
     105,   110,     7,     7,   -77,    93,     7,   -77,   -77,    66,
     -77,   -77,   -77,   -77,    45,    -2,    -1,   -77,   -77,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     4,     1,     0,     9,     5,    28,    30,     0,     0,
       0,     0,     0,     0,     0,    21,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    31,    32,     0,     0,    10,    11,     0,    13,    30,
       0,    54,     0,     0,    53,     0,     0,     0,     0,     0,
      25,     0,     0,     0,     0,    44,    45,     0,     0,    48,
       0,     0,     0,    52,     0,     3,     0,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     6,     2,     7,     0,     0,     0,
       0,     0,    49,    50,    51,    39,    40,    41,    42,    43,
       0,    56,    55,    58,    57,    60,    59,     0,     0,    33,
      34,    35,    22,     4,     0,    36,    37,     0,     0,    47,
      61,     0,     0,     2,     0,    27,     0,     0,     0,     2,
       0,     4,    26,     0,    38,    46,     4,     0,     0,     0,
       9,     0,     0,     0,    24,     0,     0,    19,    17,     0,
       2,     2,     2,     8,     4,     4,     4,    16,    20,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -76,   -77,   -39,   -77,    -8,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,    -4,   -77,   -47,   -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     4,    50,   114,    34,   107,   141,   152,   151,
      48,   123,   139,    85,    41,    36,    42,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      35,    83,     3,    78,     3,     3,     3,    44,     5,   113,
       3,    37,    86,    38,   158,   159,   -15,    55,    56,    57,
      58,    43,   -23,   124,   100,    66,    67,    68,    69,    64,
     125,   126,    49,    70,   117,   137,   138,    66,    67,    68,
      69,    80,    81,    82,   112,    95,    45,   131,    87,    88,
      89,     2,     3,   136,    66,    67,    68,    69,     3,   157,
      46,    59,    96,    97,    98,    99,    60,    61,   101,   102,
     103,   104,   105,   106,   154,   155,   156,   132,    47,   133,
      52,    53,   129,    62,    63,    54,   118,   119,    66,    67,
      68,    69,    66,    67,    68,    69,   109,    65,    71,    79,
     110,    84,    92,   147,   148,    93,    94,   150,     6,     7,
     108,     8,   120,   127,   122,   130,     9,   140,   121,   142,
      10,   143,   144,   146,   135,   149,    11,    12,    13,    14,
     153,    15,   145,    16,    17,     0,    35,     0,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,     0,     6,    39,     0,     6,    39,    66,
      67,    68,    69,    66,    67,    68,    69,   111,     0,     0,
       0,   115,    33,    12,    13,    14,    12,    13,    14,    91,
      66,    67,    68,    69,    18,    19,    20,    18,    19,    20,
     128,     0,    66,    67,    68,    69,    30,    31,    32,    30,
      31,    32,    90,     0,     0,    40,    66,    67,    68,    69,
      72,    73,    74,    75,    76,    77,     0,     0,    33,     0,
       0,    33,    66,    67,    68,    69,    66,    67,    68,    69,
      66,    67,    68,    69,   116,     0,     0,     0,   134
};

static const yytype_int16 yycheck[] =
{
       4,    48,     7,    42,     7,     7,     7,    11,    65,    85,
       7,    66,    51,     7,    16,    16,    13,    21,    22,    23,
      24,     4,    27,    26,    71,    60,    61,    62,    63,    33,
      30,    31,    25,    37,    69,    19,    20,    60,    61,    62,
      63,    45,    46,    47,    83,    68,    67,   123,    52,    53,
      54,     0,     7,   129,    60,    61,    62,    63,     7,    14,
      67,     4,    66,    67,    68,    69,    57,    57,    72,    73,
      74,    75,    76,    77,   150,   151,   152,   124,    67,   126,
      67,    67,   121,    57,     4,    67,    90,    91,    60,    61,
      62,    63,    60,    61,    62,    63,    68,    64,    67,    18,
      68,    64,     4,   142,   143,     4,     4,   146,     3,     4,
       3,     6,    68,   117,    17,     3,    11,    25,    12,     3,
      15,     3,    27,    13,   128,    32,    21,    22,    23,    24,
      64,    26,   140,    28,    29,    -1,   140,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    -1,     3,     4,    -1,     3,     4,    60,
      61,    62,    63,    60,    61,    62,    63,    68,    -1,    -1,
      -1,    68,    67,    22,    23,    24,    22,    23,    24,    59,
      60,    61,    62,    63,    33,    34,    35,    33,    34,    35,
      58,    -1,    60,    61,    62,    63,    45,    46,    47,    45,
      46,    47,    56,    -1,    -1,    54,    60,    61,    62,    63,
      48,    49,    50,    51,    52,    53,    -1,    -1,    67,    -1,
      -1,    67,    60,    61,    62,    63,    60,    61,    62,    63,
      60,    61,    62,    63,    68,    -1,    -1,    -1,    68
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    71,     0,     7,    72,    65,     3,     4,     6,    11,
      15,    21,    22,    23,    24,    26,    28,    29,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    67,    75,    84,    85,    66,     7,     4,
      54,    84,    86,     4,    84,    67,    67,    67,    80,    25,
      73,    87,    67,    67,    67,    84,    84,    84,    84,     4,
      57,    57,    57,     4,    84,    64,    60,    61,    62,    63,
      84,    67,    48,    49,    50,    51,    52,    53,    73,    18,
      84,    84,    84,    86,    64,    83,    73,    84,    84,    84,
      56,    59,     4,     4,     4,    68,    84,    84,    84,    84,
      86,    84,    84,    84,    84,    84,    84,    76,     3,    68,
      68,    68,    73,    71,    74,    68,    68,    69,    84,    84,
      68,    12,    17,    81,    26,    30,    31,    84,    58,    73,
       3,    71,    86,    86,    68,    84,    71,    19,    20,    82,
      25,    77,     3,     3,    27,    75,    13,    73,    73,    32,
      73,    79,    78,    64,    71,    71,    71,    14,    16,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    71,    72,    72,    73,    74,    74,    75,
      75,    75,    75,    75,    76,    77,    75,    78,    75,    79,
      75,    80,    81,    82,    75,    83,    75,    75,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    87
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     2,     0,     7,     0,
       1,     1,     3,     2,     0,     0,    12,     0,    12,     0,
      12,     0,     0,     0,     8,     0,     6,     5,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     6,     3,
       3,     3,     3,     3,     2,     2,     6,     4,     2,     3,
       3,     3,     2,     2,     1,     3,     3,     3,     3,     3,
       3,     4,     0
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
#line 125 "fransous.y"
       { }
#line 1297 "fransous.bison.cpp"
    break;

  case 5: /* label: LABEL ':'  */
#line 129 "fransous.y"
                   { // Lorsque je rencontre un label
                     // je stocke le numéro d'instruction actelle
                     // dans la table des adresses. C'est tout!   
                     adresses [(yyvsp[-1].nom)] = ic;}
#line 1306 "fransous.bison.cpp"
    break;

  case 7: /* case: %empty  */
#line 137 "fransous.y"
       {}
#line 1312 "fransous.bison.cpp"
    break;

  case 9: /* instruction: %empty  */
#line 140 "fransous.y"
             {}
#line 1318 "fransous.bison.cpp"
    break;

  case 10: /* instruction: expr  */
#line 141 "fransous.y"
                       { }
#line 1324 "fransous.bison.cpp"
    break;

  case 11: /* instruction: fonction  */
#line 142 "fransous.y"
                       { }
#line 1330 "fransous.bison.cpp"
    break;

  case 12: /* instruction: VAR '=' expr  */
#line 143 "fransous.y"
                       { add_instruction(ASSIGN, 0, (yyvsp[-2].nom)); }
#line 1336 "fransous.bison.cpp"
    break;

  case 13: /* instruction: GOTO LABEL  */
#line 146 "fransous.y"
                       {  // J'insère un JMP vers une adresse que je ne connais pas encore.
                            // J'utiliserai la table des adresses pour la récupérer lors de l'exécution
                            add_instruction(JMP, -999, (yyvsp[0].nom)); 
                        }
#line 1345 "fransous.bison.cpp"
    break;

  case 14: /* $@1: %empty  */
#line 150 "fransous.y"
                                 {(yyvsp[-2].adresse).jc = ic; add_instruction(JMPCOND); }
#line 1351 "fransous.bison.cpp"
    break;

  case 15: /* $@2: %empty  */
#line 152 "fransous.y"
                          { // Je sauvegarde l'endroit actuel pour revenir mofifier l'adresse 
                          // lorsqu'elle sera connue (celle du JMP)
                          (yyvsp[-6].adresse).jmp = ic;
                          add_instruction(JMP);
                          // Je mets à jour l'adresse du saut conditionnel
                          code_genere[(yyvsp[-6].adresse).jc].value = ic;
                        }
#line 1363 "fransous.bison.cpp"
    break;

  case 16: /* instruction: IF condition separateur $@1 THEN separateur lignes $@2 ELSE separateur lignes ENDIF  */
#line 161 "fransous.y"
                        { // Je mets à jour l'adresse du saut inconditionnel
                        code_genere[(yyvsp[-11].adresse).jmp].value = ic;}
#line 1370 "fransous.bison.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 164 "fransous.y"
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
#line 1391 "fransous.bison.cpp"
    break;

  case 18: /* instruction: FOR VAR BETWEEN NUM AND NUM INCR NUM separateur $@3 lignes ENDFOR  */
#line 181 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;}
#line 1399 "fransous.bison.cpp"
    break;

  case 19: /* $@4: %empty  */
#line 184 "fransous.y"
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
#line 1420 "fransous.bison.cpp"
    break;

  case 20: /* instruction: FOR VAR BETWEEN NUM AND NUM DECR NUM separateur $@4 lignes ENDFOR  */
#line 201 "fransous.y"
                                                        {add_instruction(JMP);
                                                              code_genere[ic-1].value = (yyvsp[-11].adresse).jmp;
                                                              code_genere[(yyvsp[-11].adresse).jc].value = ic;}
#line 1428 "fransous.bison.cpp"
    break;

  case 21: /* $@5: %empty  */
#line 205 "fransous.y"
                                                      { (yyvsp[0].adresse).jmp = ic;}
#line 1434 "fransous.bison.cpp"
    break;

  case 22: /* $@6: %empty  */
#line 206 "fransous.y"
                                                      {(yyvsp[-3].adresse).jc = ic;
                                                        add_instruction(JMPCOND);
                                                      }
#line 1442 "fransous.bison.cpp"
    break;

  case 23: /* $@7: %empty  */
#line 209 "fransous.y"
                                                      { add_instruction(JMP, (yyvsp[-5].adresse).jmp);
                                                        code_genere[(yyvsp[-5].adresse).jc].value = ic;
                                                      }
#line 1450 "fransous.bison.cpp"
    break;

  case 25: /* $@8: %empty  */
#line 213 "fransous.y"
                                                      {(yyvsp[-1].adresse).jc = ic;}
#line 1456 "fransous.bison.cpp"
    break;

  case 26: /* instruction: DO separateur $@8 lignes WHILE condition  */
#line 215 "fransous.y"
                                                       { add_instruction(NON);
                                                         add_instruction(JMPCOND, (yyvsp[-5].adresse).jc);}
#line 1463 "fransous.bison.cpp"
    break;

  case 28: /* expr: NUM  */
#line 220 "fransous.y"
          {add_instruction (NUM, (yyvsp[0].valeur)); }
#line 1469 "fransous.bison.cpp"
    break;

  case 29: /* expr: VARAPO  */
#line 221 "fransous.y"
             {add_instruction(VARAPO, 0, (yyvsp[0].nom));}
#line 1475 "fransous.bison.cpp"
    break;

  case 30: /* expr: VAR  */
#line 222 "fransous.y"
          {add_instruction (VAR, 0, (yyvsp[0].nom)); }
#line 1481 "fransous.bison.cpp"
    break;

  case 31: /* expr: VRAI  */
#line 223 "fransous.y"
           {(yyval.valeur) = true; }
#line 1487 "fransous.bison.cpp"
    break;

  case 32: /* expr: FAUX  */
#line 224 "fransous.y"
           {(yyval.valeur)  = false; }
#line 1493 "fransous.bison.cpp"
    break;

  case 33: /* expr: SIN '(' expr ')'  */
#line 225 "fransous.y"
                        {add_instruction(SIN);/*$$ = sin($3); printf ("sin(%g) = %g\n", $3, $$ );*/ }
#line 1499 "fransous.bison.cpp"
    break;

  case 34: /* expr: COS '(' expr ')'  */
#line 226 "fransous.y"
                        {add_instruction(COS);/*$$ = cos($3); printf ("cos(%g) = %g\n", $3, $$ );*/  }
#line 1505 "fransous.bison.cpp"
    break;

  case 35: /* expr: TAN '(' expr ')'  */
#line 227 "fransous.y"
                        {add_instruction(TAN);/*$$ = tan($3); printf ("tan(%g) = %g\n", $3, $$ );*/ }
#line 1511 "fransous.bison.cpp"
    break;

  case 36: /* expr: EXP '(' expr ')'  */
#line 228 "fransous.y"
                        {add_instruction(EXP);/*$$ = exp($3); printf ("exp(%g) = %g\n", $3, $$ );*/ }
#line 1517 "fransous.bison.cpp"
    break;

  case 37: /* expr: SQRT '(' expr ')'  */
#line 229 "fransous.y"
                        {add_instruction(SQRT);/*$$ = sqrt($3); printf ("sqrt(%g) = %g\n", $3, $$ );*/ }
#line 1523 "fransous.bison.cpp"
    break;

  case 38: /* expr: POW '(' expr ',' expr ')'  */
#line 230 "fransous.y"
                              {add_instruction(POW);}
#line 1529 "fransous.bison.cpp"
    break;

  case 39: /* expr: '(' expr ')'  */
#line 231 "fransous.y"
                         { (yyval.valeur) = (yyvsp[-1].valeur); }
#line 1535 "fransous.bison.cpp"
    break;

  case 40: /* expr: expr ADD expr  */
#line 232 "fransous.y"
                    {add_instruction(ADD); }
#line 1541 "fransous.bison.cpp"
    break;

  case 41: /* expr: expr SUB expr  */
#line 233 "fransous.y"
                    {add_instruction(SUB); }
#line 1547 "fransous.bison.cpp"
    break;

  case 42: /* expr: expr MULT expr  */
#line 234 "fransous.y"
                     {add_instruction(MULT); }
#line 1553 "fransous.bison.cpp"
    break;

  case 43: /* expr: expr DIV expr  */
#line 235 "fransous.y"
                    { add_instruction(DIV); }
#line 1559 "fransous.bison.cpp"
    break;

  case 44: /* fonction: OPENFR expr  */
#line 238 "fransous.y"
                       {add_instruction(OPENFR);}
#line 1565 "fransous.bison.cpp"
    break;

  case 45: /* fonction: OPENFW expr  */
#line 239 "fransous.y"
                     {add_instruction(OPENFW);}
#line 1571 "fransous.bison.cpp"
    break;

  case 46: /* fonction: SUPPR expr DANS expr JUSQUE expr  */
#line 240 "fransous.y"
                                          {add_instruction(SUPPR);}
#line 1577 "fransous.bison.cpp"
    break;

  case 47: /* fonction: NEWNAME expr EN expr  */
#line 241 "fransous.y"
                             {add_instruction(NEWNAME);}
#line 1583 "fransous.bison.cpp"
    break;

  case 48: /* fonction: TOLOWER VAR  */
#line 242 "fransous.y"
                     {add_instruction(TOLOWER);}
#line 1589 "fransous.bison.cpp"
    break;

  case 49: /* fonction: FIRST DE VAR  */
#line 243 "fransous.y"
                      {add_instruction(FIRST);}
#line 1595 "fransous.bison.cpp"
    break;

  case 50: /* fonction: LAST DE VAR  */
#line 244 "fransous.y"
                     {add_instruction(LAST);}
#line 1601 "fransous.bison.cpp"
    break;

  case 51: /* fonction: SIZE DE VAR  */
#line 245 "fransous.y"
                     {add_instruction(SIZE);}
#line 1607 "fransous.bison.cpp"
    break;

  case 52: /* fonction: WAIT VAR  */
#line 246 "fransous.y"
                  {add_instruction(WAIT);}
#line 1613 "fransous.bison.cpp"
    break;

  case 53: /* fonction: PRINT expr  */
#line 247 "fransous.y"
                      { add_instruction(PRINT); }
#line 1619 "fransous.bison.cpp"
    break;

  case 55: /* condition: expr SUP expr  */
#line 252 "fransous.y"
                         {add_instruction(SUP);}
#line 1625 "fransous.bison.cpp"
    break;

  case 56: /* condition: expr INF expr  */
#line 253 "fransous.y"
                         {add_instruction(INF);}
#line 1631 "fransous.bison.cpp"
    break;

  case 57: /* condition: expr SUPEG expr  */
#line 254 "fransous.y"
                           {add_instruction(SUPEG);}
#line 1637 "fransous.bison.cpp"
    break;

  case 58: /* condition: expr INFEG expr  */
#line 255 "fransous.y"
                           {add_instruction(INFEG);}
#line 1643 "fransous.bison.cpp"
    break;

  case 59: /* condition: expr DIFF expr  */
#line 256 "fransous.y"
                          {add_instruction(DIFF);}
#line 1649 "fransous.bison.cpp"
    break;

  case 60: /* condition: expr EGAL expr  */
#line 257 "fransous.y"
                          {add_instruction(EGAL);}
#line 1655 "fransous.bison.cpp"
    break;

  case 61: /* condition: NON '(' condition ')'  */
#line 258 "fransous.y"
                               {add_instruction(NON);}
#line 1661 "fransous.bison.cpp"
    break;

  case 62: /* var: %empty  */
#line 260 "fransous.y"
      {}
#line 1667 "fransous.bison.cpp"
    break;


#line 1671 "fransous.bison.cpp"

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

#line 261 "fransous.y"



int yyerror(char *s) {					
    printf("%s : %s\n", s, yytext);
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
        cout << "$ cos(" << r1 << ") = " << cos(r1) << " : " << pile.top() << "\n";
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
