/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "ana.y"


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
extern int yylex(void);
extern char *yytext;
extern YYSTYPE yylval ;
extern char * yysymbol_kind_t;
extern int linea;
extern FILE *yyin;
void yyerror (  char const *s);

#line 84 "y.tab.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUMERO = 258,
    RUTA1 = 259,
    RUTA2 = 260,
    CADENA = 261,
    CADENA2 = 262,
    COME = 263,
    MKDISK = 264,
    RMDISK = 265,
    FDISK = 266,
    MOUNT = 267,
    UNMOUNT = 268,
    REP = 269,
    EXEC = 270,
    SIZE = 271,
    PATH = 272,
    FIT = 273,
    UNIT = 274,
    NAME = 275,
    TYPE = 276,
    DELETE = 277,
    ADD = 278,
    ID = 279,
    FILES = 280,
    FS = 281,
    PWD = 282,
    USR = 283,
    GRP = 284,
    UGO = 285,
    R = 286,
    P = 287,
    CONT = 288,
    FILEN = 289,
    DEST = 290,
    INCOG = 291,
    ASTER = 292,
    LOGIN = 293,
    LOGOUT = 294,
    MKGRP = 295,
    RMGRP = 296,
    MKUSR = 297,
    RMUSR = 298,
    CHMOD = 299,
    MKFILE = 300,
    REM = 301,
    EDIT = 302,
    REN = 303,
    MKDIR = 304,
    CP = 305,
    MV = 306,
    FIND = 307,
    CHOWN = 308,
    CHGRP = 309,
    PAUSE = 310,
    RECOVERY = 311,
    LOSS = 312,
    CAT = 313,
    MKFS = 314,
    IGUAL = 315,
    NUMERAL = 316,
    RUTA = 317
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "ana.y"

char* cadena;
float real;

#line 204 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  138
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   264

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  165
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

#define YYUNDEFTOK  2
#define YYMAXUTOK   317


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   150,   150,   154,   155,   159,   162,   165,   168,   171,
     174,   177,   180,   183,   186,   190,   193,   196,   199,   202,
     205,   208,   211,   214,   217,   220,   223,   226,   229,   232,
     235,   238,   241,   244,   263,   264,   266,   270,   284,   305,
     306,   309,   312,   315,   318,   321,   325,   340,   343,   351,
     354,   362,   363,   365,   368,   371,   374,   377,   386,   389,
     397,   398,   400,   403,   406,   409,   421,   422,   424,   427,
     430,   433,   436,   439,   452,   455,   464,   467,   477,   478,
     480,   483,   486,   489,   498,   499,   501,   504,   507,   510,
     520,   521,   523,   526,   529,   539,   540,   542,   545,   548,
     551,   561,   562,   564,   567,   570,   573,   584,   585,   587,
     590,   593,   596,   599,   602,   613,   614,   616,   619,   622,
     625,   628,   639,   640,   642,   645,   648,   651,   663,   672,
     692,   693,   695,   705,   722,   737,   741,   756,   761,   778,
     779,   781,   791,   809,   826,   831,   836,   853,   867,   872,
     889,   890,   892,   897,   902,   920,   937,   938,   940,   943,
     948,   953,   958,   963,   981,   986
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "RUTA1", "RUTA2", "CADENA",
  "CADENA2", "COME", "MKDISK", "RMDISK", "FDISK", "MOUNT", "UNMOUNT",
  "REP", "EXEC", "SIZE", "PATH", "FIT", "UNIT", "NAME", "TYPE", "DELETE",
  "ADD", "ID", "FILES", "FS", "PWD", "USR", "GRP", "UGO", "R", "P", "CONT",
  "FILEN", "DEST", "INCOG", "ASTER", "LOGIN", "LOGOUT", "MKGRP", "RMGRP",
  "MKUSR", "RMUSR", "CHMOD", "MKFILE", "REM", "EDIT", "REN", "MKDIR", "CP",
  "MV", "FIND", "CHOWN", "CHGRP", "PAUSE", "RECOVERY", "LOSS", "CAT",
  "MKFS", "IGUAL", "NUMERAL", "RUTA", "$accept", "inicio_comando",
  "COMAND", "COMD", "parametros8", "parametro8", "parametros9",
  "parametro9", "parametros11", "parametros12", "parametros13",
  "parametro13", "parametros14", "parametros15", "parametro15",
  "parametros16", "parametro16", "parametros17", "parametros18",
  "parametros19", "parametro19", "parametros20", "parametro20",
  "parametros21", "parametro21", "parametros22", "parametro22",
  "parametros23", "parametro23", "parametros24", "parametro24",
  "parametros25", "parametro25", "parametros26", "parametro26",
  "parametros27", "parametros28", "parametros1", "parametro1",
  "parametros2", "parametros3", "parametro3", "parametros4", "parametro4",
  "parametros5", "parametros6", "parametro6", "parametros7", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    64,    -4,    -1,    67,   -16,   -10,     8,    51,   -17,
      44,    87,    63,    31,    43,    -5,   117,    38,    68,    40,
      -8,    34,    69,    39,    48,   -17,   127,   136,   138,    37,
     161,    -9,   -17,   105,   107,   109,   111,    64,   -17,   113,
     -17,   114,   115,   119,   121,   123,   125,   130,   131,    -1,
     -17,   132,   134,    67,   -17,   140,   -17,   142,   144,   147,
     149,   -10,   -17,   151,   -17,   152,   153,   155,    51,   -17,
     156,   -17,   157,   -17,   158,   159,   160,    63,   -17,   162,
     -17,   163,   164,   -17,    43,   -17,   165,   166,   -17,   167,
      -5,   -17,   168,   -17,   169,   170,    38,   -17,   171,   172,
      68,   -17,   173,   -17,    40,   -17,   174,   175,    -8,   -17,
     176,   177,    34,   -17,   178,   179,    69,   -17,   180,   181,
     -17,    39,   -17,   182,   183,    48,   -17,   184,   -17,   185,
     -17,   186,   -17,   187,   188,   189,    37,   -17,   -17,   -17,
      65,    89,   190,   191,   -17,    91,   192,    93,   193,   195,
     197,   199,   200,   205,   -17,    95,   204,   -17,   208,    97,
     215,   244,    99,   -17,   101,   245,    59,   102,   -17,   104,
     106,   246,   108,   110,   -17,   112,   116,   247,   -17,   251,
     118,   120,   -17,   122,   124,   126,   -17,   128,   129,   -17,
     133,   -17,   135,   137,   -17,   139,   141,   -17,   143,    17,
     -17,   145,   146,   -17,   148,   150,   -17,   249,   250,   154,
     252,   253,   254,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,   -17
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     2,     4,     0,     0,     0,     0,     5,   131,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     7,
     140,     0,     0,     8,   151,     0,     9,     0,     0,     0,
       0,    10,   157,     0,    11,     0,     0,     0,    13,    40,
       0,    15,     0,    16,     0,     0,     0,    17,    52,     0,
      18,     0,     0,    65,    19,    61,     0,     0,    70,     0,
      20,    67,     0,    22,     0,     0,    23,    79,     0,     0,
      24,    85,     0,    94,    25,    91,     0,     0,    26,    96,
       0,     0,    27,   102,     0,     0,    28,   108,     0,     0,
     119,    29,   116,     0,     0,    30,   123,     0,    32,     0,
      33,     0,    21,     0,     0,     0,    12,    35,     1,     3,
       0,     0,     0,     0,   130,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   139,     0,     0,   150,     0,     0,
       0,     0,     0,   156,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    60,     0,
       0,     0,    66,     0,     0,     0,    78,     0,     0,    84,
       0,    90,     0,     0,    95,     0,     0,   101,     0,     0,
     107,     0,     0,   115,     0,     0,   122,     0,     0,     0,
       0,     0,     0,    34,   132,   135,   136,   133,   134,   137,
     138,   141,   144,   145,   143,   142,   148,   146,   147,   149,
     153,   154,   152,   155,   159,   160,   158,   161,   162,   163,
     164,   165,    46,    45,    43,    44,    41,    42,    47,    48,
      49,    50,    55,    53,    54,    56,    57,    58,    59,    62,
      63,    64,    71,    68,    69,    72,    73,    76,    77,    80,
      81,    82,    83,    86,    87,    88,    89,    92,    93,    97,
      98,    99,   100,   103,   104,   105,   106,   109,   110,   113,
     114,   111,   112,   117,   118,   120,   121,   124,   125,   126,
     127,   128,   129,    74,    75,    37,    36,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -17,   -17,   -17,   226,   -17,    26,   -17,    96,   -17,   -17,
     -17,   100,   -17,   -17,    82,   -17,    78,   -17,   -17,   -17,
      74,   -17,    72,   -17,    76,   -17,    70,   -17,    75,   -17,
      60,   -17,    61,   -17,    73,   -17,   -17,   -17,   224,   -17,
     -17,   213,   -17,   210,   -17,   -17,   203,   -17
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    31,    32,   136,   137,    68,    69,    71,    73,
      77,    78,    80,    84,    85,    90,    91,   132,    93,    96,
      97,   100,   101,   104,   105,   108,   109,   112,   113,   116,
     117,   121,   122,   125,   126,   128,   130,    37,    38,    40,
      49,    50,    53,    54,    56,    61,    62,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       1,     2,     3,     4,     5,     6,     7,    57,    55,   106,
      58,    86,    87,    39,    59,    41,    42,    43,    44,    45,
      46,    47,    48,   289,   290,    63,    88,   107,    89,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,   110,    60,   291,   292,    94,   118,   102,   133,    79,
      81,   134,   243,   135,    70,   244,   245,   119,   214,   111,
     120,    95,   103,    82,    83,    65,   123,   124,    66,    67,
      33,    34,    35,    36,    51,    98,   114,    52,    99,   115,
      74,    75,    76,   215,   216,   219,   220,   222,   223,   230,
     231,   234,   235,   238,   239,   240,   241,    72,   246,   247,
     248,   249,   250,   251,   253,   254,   255,   256,   257,   258,
     259,   260,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,    92,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   293,
     294,   127,   295,   296,   297,   298,   299,   300,   303,   304,
     129,   138,   213,   131,   168,   140,   178,   141,   182,   142,
     186,   143,   189,   145,   146,   147,   200,   174,   194,   148,
     191,   149,   203,   150,     0,   151,     0,   197,     0,     0,
     152,   153,   155,     0,   156,   221,   217,   218,   206,   224,
     158,   225,   159,   226,   160,   227,   228,   161,   229,   162,
     232,   164,   165,   166,   233,   167,   169,   170,   171,   172,
     173,   236,   175,   176,   177,   179,   180,   181,   183,   184,
     185,   187,   188,   190,   192,   193,   195,   196,   198,   199,
     201,   202,   204,   205,   207,   208,   209,   210,   211,   212,
     237,   242,   252,   261,   262,   301,   302,   139,   305,   306,
     307,   144,   154,   157,   163
};

static const yytype_int16 yycheck[] =
{
       9,    10,    11,    12,    13,    14,    15,    17,    24,    17,
      20,    16,    17,    17,    24,    16,    17,    18,    19,    20,
      21,    22,    23,     6,     7,    17,    31,    35,    33,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    17,    62,    36,    37,    17,    17,    17,    21,    28,
      17,    24,     3,    26,    20,     6,     7,    28,     3,    35,
      31,    33,    32,    30,    31,    24,    28,    29,    27,    28,
      16,    17,    18,    19,    17,    17,    17,    20,    20,    20,
      27,    28,    29,     4,     5,     4,     5,     4,     5,     4,
       5,     4,     5,     4,     5,     4,     5,    20,     6,     7,
       6,     7,     6,     7,     6,     7,     6,     7,     6,     7,
       4,     5,     4,     5,     4,     5,     4,     5,     4,     5,
       4,     5,     4,     5,    17,     6,     7,     4,     5,     4,
       5,     4,     5,     4,     5,     4,     5,     4,     5,     4,
       5,    24,     6,     7,     6,     7,     6,     7,     4,     5,
      24,     0,   136,    25,    68,    60,    84,    60,    90,    60,
      96,    60,   100,    60,    60,    60,   116,    77,   108,    60,
     104,    60,   121,    60,    -1,    60,    -1,   112,    -1,    -1,
      60,    60,    60,    -1,    60,     3,     6,     6,   125,     6,
      60,     6,    60,     6,    60,     6,     6,    60,     3,    60,
       6,    60,    60,    60,     6,    60,    60,    60,    60,    60,
      60,     6,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
       6,     6,     6,     6,     3,     6,     6,    31,     6,     6,
       6,    37,    49,    53,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    11,    12,    13,    14,    15,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      64,    65,    66,    16,    17,    18,    19,   100,   101,    17,
     102,    16,    17,    18,    19,    20,    21,    22,    23,   103,
     104,    17,    20,   105,   106,    24,   107,    17,    20,    24,
      62,   108,   109,    17,   110,    24,    27,    28,    69,    70,
      20,    71,    20,    72,    27,    28,    29,    73,    74,    28,
      75,    17,    30,    31,    76,    77,    16,    17,    31,    33,
      78,    79,    17,    81,    17,    33,    82,    83,    17,    20,
      84,    85,    17,    32,    86,    87,    17,    35,    88,    89,
      17,    35,    90,    91,    17,    20,    92,    93,    17,    28,
      31,    94,    95,    28,    29,    96,    97,    24,    98,    24,
      99,    25,    80,    21,    24,    26,    67,    68,     0,    66,
      60,    60,    60,    60,   101,    60,    60,    60,    60,    60,
      60,    60,    60,    60,   104,    60,    60,   106,    60,    60,
      60,    60,    60,   109,    60,    60,    60,    60,    70,    60,
      60,    60,    60,    60,    74,    60,    60,    60,    77,    60,
      60,    60,    79,    60,    60,    60,    83,    60,    60,    85,
      60,    87,    60,    60,    89,    60,    60,    91,    60,    60,
      93,    60,    60,    95,    60,    60,    97,    60,    60,    60,
      60,    60,    60,    68,     3,     4,     5,     6,     6,     4,
       5,     3,     4,     5,     6,     6,     6,     6,     6,     3,
       4,     5,     6,     6,     4,     5,     6,     6,     4,     5,
       4,     5,     6,     3,     6,     7,     6,     7,     6,     7,
       6,     7,     6,     6,     7,     6,     7,     6,     7,     4,
       5,     6,     3,     4,     5,     4,     5,     4,     5,     4,
       5,     4,     5,     4,     5,     6,     7,     4,     5,     4,
       5,     4,     5,     4,     5,     4,     5,     4,     5,     6,
       7,    36,    37,     4,     5,     6,     7,     6,     7,     6,
       7,     6,     6,     4,     5,     6,     6,     6
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    70,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    75,    75,
      76,    76,    77,    77,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    83,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    87,    88,    88,    89,    89,    89,
      89,    90,    90,    91,    91,    91,    91,    92,    92,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    96,    96,    97,    97,    97,    97,    98,    99,
     100,   100,   101,   101,   101,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   106,   106,   107,   108,   108,   109,   109,
     109,   109,   109,   109,   110,   110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     2,     2,     2,     1,     3,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     1,     2,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     1,
       3,     3,     3,     3,     2,     1,     3,     3,     3,     3,
       2,     1,     3,     3,     1,     2,     1,     3,     3,     3,
       3,     2,     1,     3,     3,     3,     3,     2,     1,     3,
       3,     3,     3,     3,     3,     2,     1,     3,     3,     1,
       3,     3,     2,     1,     3,     3,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     1,     3,     3,     3,     3,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5:
#line 159 "ana.y"
                        {
	ClaComando(1);
}
#line 1707 "y.tab.cpp"
    break;

  case 6:
#line 162 "ana.y"
                           {
	ClaComando(2);
}
#line 1715 "y.tab.cpp"
    break;

  case 7:
#line 165 "ana.y"
                           {
	ClaComando(3);
}
#line 1723 "y.tab.cpp"
    break;

  case 8:
#line 168 "ana.y"
                           {
	ClaComando(4);
}
#line 1731 "y.tab.cpp"
    break;

  case 9:
#line 171 "ana.y"
                           {
	ClaComando(5);
}
#line 1739 "y.tab.cpp"
    break;

  case 10:
#line 174 "ana.y"
                           {
	ClaComando(6);
}
#line 1747 "y.tab.cpp"
    break;

  case 11:
#line 177 "ana.y"
                           {
	ClaComando(7);
}
#line 1755 "y.tab.cpp"
    break;

  case 12:
#line 180 "ana.y"
                           {
	ClaComando(8);
}
#line 1763 "y.tab.cpp"
    break;

  case 13:
#line 183 "ana.y"
                           {
	ClaComando(9);
}
#line 1771 "y.tab.cpp"
    break;

  case 14:
#line 186 "ana.y"
                {
	Login borra;
	logueada=borra;
}
#line 1780 "y.tab.cpp"
    break;

  case 15:
#line 190 "ana.y"
                            {
	comando=7;
}
#line 1788 "y.tab.cpp"
    break;

  case 16:
#line 193 "ana.y"
                            {
	comando=7;
}
#line 1796 "y.tab.cpp"
    break;

  case 17:
#line 196 "ana.y"
                            {
	comando=7;
}
#line 1804 "y.tab.cpp"
    break;

  case 18:
#line 199 "ana.y"
                            {
	comando=7;
}
#line 1812 "y.tab.cpp"
    break;

  case 19:
#line 202 "ana.y"
                            {
	comando=7;
}
#line 1820 "y.tab.cpp"
    break;

  case 20:
#line 205 "ana.y"
                            {
	comando=8;
}
#line 1828 "y.tab.cpp"
    break;

  case 21:
#line 208 "ana.y"
                            {
	comando=7;
}
#line 1836 "y.tab.cpp"
    break;

  case 22:
#line 211 "ana.y"
                            {
	comando=7;
}
#line 1844 "y.tab.cpp"
    break;

  case 23:
#line 214 "ana.y"
                            {
	comando=7;
}
#line 1852 "y.tab.cpp"
    break;

  case 24:
#line 217 "ana.y"
                            {
	comando=7;
}
#line 1860 "y.tab.cpp"
    break;

  case 25:
#line 220 "ana.y"
                            {
	comando=7;
}
#line 1868 "y.tab.cpp"
    break;

  case 26:
#line 223 "ana.y"
                            {
	comando=7;
}
#line 1876 "y.tab.cpp"
    break;

  case 27:
#line 226 "ana.y"
                            {
	comando=7;
}
#line 1884 "y.tab.cpp"
    break;

  case 28:
#line 229 "ana.y"
                            {
	comando=7;
}
#line 1892 "y.tab.cpp"
    break;

  case 29:
#line 232 "ana.y"
                            {
	comando=7;
}
#line 1900 "y.tab.cpp"
    break;

  case 30:
#line 235 "ana.y"
                            {
	comando=7;
}
#line 1908 "y.tab.cpp"
    break;

  case 31:
#line 238 "ana.y"
        {
	ClaComando(20);
}
#line 1916 "y.tab.cpp"
    break;

  case 32:
#line 241 "ana.y"
                            {
	comando=7;
}
#line 1924 "y.tab.cpp"
    break;

  case 33:
#line 244 "ana.y"
                            {
	comando=7;
}
#line 1932 "y.tab.cpp"
    break;

  case 36:
#line 266 "ana.y"
                          {
	info8.id=(yyvsp[0].cadena);
	
}
#line 1941 "y.tab.cpp"
    break;

  case 37:
#line 270 "ana.y"
                  {
	
	char*ps1="fast";
	char*ps2="full";
	if(Compare((yyvsp[0].cadena),ps1)){
		info8.type=1;
	}else if(Compare((yyvsp[0].cadena),ps2)){
		info8.type=2;
	}else{
		info8.type=0;
		printf("El tipo de formateo es erroneo");
	}
	
}
#line 1960 "y.tab.cpp"
    break;

  case 38:
#line 284 "ana.y"
                {
	char*ps1="2fs";
	char*ps2="3fs";
	if(Compare((yyvsp[0].cadena),ps1)){
		info8.fs=1;
	}else if(Compare((yyvsp[0].cadena),ps2)){
		info8.fs=2;
	}else{
		info8.fs=0;
		printf("El tipo de sistema de archivos es erroneo");
	}
	
}
#line 1978 "y.tab.cpp"
    break;

  case 41:
#line 309 "ana.y"
                           {
	info9.usuario=(yyvsp[0].cadena);
}
#line 1986 "y.tab.cpp"
    break;

  case 42:
#line 312 "ana.y"
                  {
	info9.usuario=(yyvsp[0].cadena);
}
#line 1994 "y.tab.cpp"
    break;

  case 43:
#line 315 "ana.y"
                 {
	info9.password=(yyvsp[0].cadena);
}
#line 2002 "y.tab.cpp"
    break;

  case 44:
#line 318 "ana.y"
                  {
	info9.password=(yyvsp[0].cadena);
}
#line 2010 "y.tab.cpp"
    break;

  case 45:
#line 321 "ana.y"
                 {
	int tex=(yyvsp[0].real);
	info9.password=intToCharP(tex);
}
#line 2019 "y.tab.cpp"
    break;

  case 46:
#line 325 "ana.y"
                {
	info9.id=(yyvsp[0].cadena);
}
#line 2027 "y.tab.cpp"
    break;

  case 47:
#line 340 "ana.y"
                              {

}
#line 2035 "y.tab.cpp"
    break;

  case 48:
#line 343 "ana.y"
                   {

}
#line 2043 "y.tab.cpp"
    break;

  case 49:
#line 351 "ana.y"
                              {

}
#line 2051 "y.tab.cpp"
    break;

  case 50:
#line 354 "ana.y"
                   {

}
#line 2059 "y.tab.cpp"
    break;

  case 53:
#line 365 "ana.y"
                            {

}
#line 2067 "y.tab.cpp"
    break;

  case 54:
#line 368 "ana.y"
                  {

}
#line 2075 "y.tab.cpp"
    break;

  case 55:
#line 371 "ana.y"
                 {

}
#line 2083 "y.tab.cpp"
    break;

  case 56:
#line 374 "ana.y"
                 {

}
#line 2091 "y.tab.cpp"
    break;

  case 57:
#line 377 "ana.y"
                  {

}
#line 2099 "y.tab.cpp"
    break;

  case 58:
#line 386 "ana.y"
                             {

}
#line 2107 "y.tab.cpp"
    break;

  case 59:
#line 389 "ana.y"
                  {

}
#line 2115 "y.tab.cpp"
    break;

  case 62:
#line 400 "ana.y"
                            {

}
#line 2123 "y.tab.cpp"
    break;

  case 63:
#line 403 "ana.y"
                 {

}
#line 2131 "y.tab.cpp"
    break;

  case 64:
#line 406 "ana.y"
                 {

}
#line 2139 "y.tab.cpp"
    break;

  case 65:
#line 409 "ana.y"
   {

}
#line 2147 "y.tab.cpp"
    break;

  case 68:
#line 424 "ana.y"
                            {

}
#line 2155 "y.tab.cpp"
    break;

  case 69:
#line 427 "ana.y"
                 {

}
#line 2163 "y.tab.cpp"
    break;

  case 70:
#line 430 "ana.y"
   {

}
#line 2171 "y.tab.cpp"
    break;

  case 71:
#line 433 "ana.y"
                  {

}
#line 2179 "y.tab.cpp"
    break;

  case 72:
#line 436 "ana.y"
                 {

}
#line 2187 "y.tab.cpp"
    break;

  case 73:
#line 439 "ana.y"
                 {

}
#line 2195 "y.tab.cpp"
    break;

  case 74:
#line 452 "ana.y"
                              {

}
#line 2203 "y.tab.cpp"
    break;

  case 75:
#line 455 "ana.y"
                  {

}
#line 2211 "y.tab.cpp"
    break;

  case 76:
#line 464 "ana.y"
                             {

}
#line 2219 "y.tab.cpp"
    break;

  case 77:
#line 467 "ana.y"
                 {


}
#line 2228 "y.tab.cpp"
    break;

  case 80:
#line 480 "ana.y"
                            {

}
#line 2236 "y.tab.cpp"
    break;

  case 81:
#line 483 "ana.y"
                 {

}
#line 2244 "y.tab.cpp"
    break;

  case 82:
#line 486 "ana.y"
                 {

}
#line 2252 "y.tab.cpp"
    break;

  case 83:
#line 489 "ana.y"
                 {

}
#line 2260 "y.tab.cpp"
    break;

  case 86:
#line 501 "ana.y"
                            {

}
#line 2268 "y.tab.cpp"
    break;

  case 87:
#line 504 "ana.y"
                 {

}
#line 2276 "y.tab.cpp"
    break;

  case 88:
#line 507 "ana.y"
                  {

}
#line 2284 "y.tab.cpp"
    break;

  case 89:
#line 510 "ana.y"
                   {

}
#line 2292 "y.tab.cpp"
    break;

  case 92:
#line 523 "ana.y"
                            {

}
#line 2300 "y.tab.cpp"
    break;

  case 93:
#line 526 "ana.y"
                 {

}
#line 2308 "y.tab.cpp"
    break;

  case 94:
#line 529 "ana.y"
  {

}
#line 2316 "y.tab.cpp"
    break;

  case 97:
#line 542 "ana.y"
                            {

}
#line 2324 "y.tab.cpp"
    break;

  case 98:
#line 545 "ana.y"
                 {

}
#line 2332 "y.tab.cpp"
    break;

  case 99:
#line 548 "ana.y"
                 {

}
#line 2340 "y.tab.cpp"
    break;

  case 100:
#line 551 "ana.y"
                 {

}
#line 2348 "y.tab.cpp"
    break;

  case 103:
#line 564 "ana.y"
                            {

}
#line 2356 "y.tab.cpp"
    break;

  case 104:
#line 567 "ana.y"
                 {

}
#line 2364 "y.tab.cpp"
    break;

  case 105:
#line 570 "ana.y"
                 {

}
#line 2372 "y.tab.cpp"
    break;

  case 106:
#line 573 "ana.y"
                 {

}
#line 2380 "y.tab.cpp"
    break;

  case 109:
#line 587 "ana.y"
                            {

}
#line 2388 "y.tab.cpp"
    break;

  case 110:
#line 590 "ana.y"
                 {

}
#line 2396 "y.tab.cpp"
    break;

  case 111:
#line 593 "ana.y"
                 {

}
#line 2404 "y.tab.cpp"
    break;

  case 112:
#line 596 "ana.y"
                 {

}
#line 2412 "y.tab.cpp"
    break;

  case 113:
#line 599 "ana.y"
                  {

}
#line 2420 "y.tab.cpp"
    break;

  case 114:
#line 602 "ana.y"
                   {

}
#line 2428 "y.tab.cpp"
    break;

  case 117:
#line 616 "ana.y"
                            {

}
#line 2436 "y.tab.cpp"
    break;

  case 118:
#line 619 "ana.y"
                 {

}
#line 2444 "y.tab.cpp"
    break;

  case 119:
#line 622 "ana.y"
  {

}
#line 2452 "y.tab.cpp"
    break;

  case 120:
#line 625 "ana.y"
                 {

}
#line 2460 "y.tab.cpp"
    break;

  case 121:
#line 628 "ana.y"
                  {

}
#line 2468 "y.tab.cpp"
    break;

  case 124:
#line 642 "ana.y"
                            {

}
#line 2476 "y.tab.cpp"
    break;

  case 125:
#line 645 "ana.y"
                  {

}
#line 2484 "y.tab.cpp"
    break;

  case 126:
#line 648 "ana.y"
                 {

}
#line 2492 "y.tab.cpp"
    break;

  case 127:
#line 651 "ana.y"
                  {

}
#line 2500 "y.tab.cpp"
    break;

  case 128:
#line 663 "ana.y"
                            {

}
#line 2508 "y.tab.cpp"
    break;

  case 129:
#line 672 "ana.y"
                            {

}
#line 2516 "y.tab.cpp"
    break;

  case 132:
#line 695 "ana.y"
                            {

	if((yyvsp[0].real)>0){
		info1.size=(int)(yyvsp[0].real);
	}else{
	char* salex="El tamano es incorrecto";
	Impri(salex);
		//el tamano no es correcto
	}
}
#line 2531 "y.tab.cpp"
    break;

  case 133:
#line 705 "ana.y"
                 {
	char* compa="bf";
	char* compa1="ff";
	char* compa2="wf";
	
	if(Compare(compa,(yyvsp[0].cadena))){
		info1.fit=1;
	}else if(Compare(compa1,(yyvsp[0].cadena))){
		info1.fit=2;
	}else if(Compare(compa2,(yyvsp[0].cadena))){
		info1.fit=3;
	}else{
	char* salex="El ajuste es incorrecto";
	Impri(salex);
	//el ajuste no es correcto
	}
}
#line 2553 "y.tab.cpp"
    break;

  case 134:
#line 722 "ana.y"
                  {

	char* compa1="k";
	char* compa2="m";
	
	if(Compare(compa1,(yyvsp[0].cadena))){
		info1.unit=1;
	}else if(Compare(compa2,(yyvsp[0].cadena))){
		info1.unit=2;
	}else{
	char* salex="Las unidades no son correctas";
	Impri(salex);
	//las unidades no son correctas
	}
}
#line 2573 "y.tab.cpp"
    break;

  case 135:
#line 737 "ana.y"
                 {

	info1.path=(yyvsp[0].cadena);
}
#line 2582 "y.tab.cpp"
    break;

  case 136:
#line 741 "ana.y"
                 {

	info1.path=(yyvsp[0].cadena);
}
#line 2591 "y.tab.cpp"
    break;

  case 137:
#line 756 "ana.y"
                             {

	info2.path=(yyvsp[0].cadena);

}
#line 2601 "y.tab.cpp"
    break;

  case 138:
#line 761 "ana.y"
                 {

	info2.path=(yyvsp[0].cadena);

}
#line 2611 "y.tab.cpp"
    break;

  case 141:
#line 781 "ana.y"
                            {

	if((yyvsp[0].real)>0){
		info3.size=(int)(yyvsp[0].real);
	}else{
	char* salex="El tamano es incorrecto";
	Impri(salex);
		//el tamano no es correcto
	}
}
#line 2626 "y.tab.cpp"
    break;

  case 142:
#line 791 "ana.y"
                  {

	char* compa="b";
	char* compa1="k";
	char* compa2="m";
	
	if(Compare(compa,(yyvsp[0].cadena))){
		info3.unit=1;
	}else if(Compare(compa1,(yyvsp[0].cadena))){
		info3.unit=2;
	}else if(Compare(compa2,(yyvsp[0].cadena))){
		info3.unit=3;
	}else{
	char* salex="las unidades son incorrectas";
	Impri(salex);
	//las unidades no son correctas
	}
}
#line 2649 "y.tab.cpp"
    break;

  case 143:
#line 809 "ana.y"
                 {
	char* compa="bf";
	char* compa1="ff";
	char* compa2="wf";
	
	if(Compare(compa,(yyvsp[0].cadena))){
		info3.fit=1;
	}else if(Compare(compa1,(yyvsp[0].cadena))){
		info3.fit=2;
	}else if(Compare(compa2,(yyvsp[0].cadena))){
		info3.fit=3;
	}else{
	char* salex="El ajuste es incorrecto";
	Impri(salex);
	//el ajuste no es correcto
	}
}
#line 2671 "y.tab.cpp"
    break;

  case 144:
#line 826 "ana.y"
                 {

	info3.path=(yyvsp[0].cadena);

}
#line 2681 "y.tab.cpp"
    break;

  case 145:
#line 831 "ana.y"
                 {

	info3.path=(yyvsp[0].cadena);

}
#line 2691 "y.tab.cpp"
    break;

  case 146:
#line 836 "ana.y"
                  {
	char* compa="p";
	char* compa1="e";
	char* compa2="l";
	
	if(Compare(compa,(yyvsp[0].cadena))){
		info3.type=1;
	}else if(Compare(compa1,(yyvsp[0].cadena))){
		info3.type=2;
	}else if(Compare(compa2,(yyvsp[0].cadena))){
		info3.type=3;
	}else{
	char* salex="El tipo de particion es incorrecto";
	Impri(salex);
	//el tipo de partcion no es correcto
	}
}
#line 2713 "y.tab.cpp"
    break;

  case 147:
#line 853 "ana.y"
                    {
	char* compa="fast";
	char* compa1="full";
	
	if(Compare(compa,(yyvsp[0].cadena))){
		info3.delet=1;
	}else if(Compare(compa1,(yyvsp[0].cadena))){
		info3.delet=2;
	}else{
	char* salex="El valor de eliminar es incorrecto";
	Impri(salex);
	//el tipo de partcion no es correcto
	}
}
#line 2732 "y.tab.cpp"
    break;

  case 148:
#line 867 "ana.y"
                  {

	info3.name=(yyvsp[0].cadena);

}
#line 2742 "y.tab.cpp"
    break;

  case 149:
#line 872 "ana.y"
                 {

	info3.add=(int)(yyvsp[0].real);

}
#line 2752 "y.tab.cpp"
    break;

  case 152:
#line 892 "ana.y"
                            {

	info4.name=(yyvsp[0].cadena);

}
#line 2762 "y.tab.cpp"
    break;

  case 153:
#line 897 "ana.y"
                 {

	info4.path=(yyvsp[0].cadena);

}
#line 2772 "y.tab.cpp"
    break;

  case 154:
#line 902 "ana.y"
                 {

	info4.path=(yyvsp[0].cadena);

}
#line 2782 "y.tab.cpp"
    break;

  case 155:
#line 920 "ana.y"
                            {

	info5.id=(yyvsp[0].cadena);

}
#line 2792 "y.tab.cpp"
    break;

  case 158:
#line 940 "ana.y"
                            {
	
}
#line 2800 "y.tab.cpp"
    break;

  case 159:
#line 943 "ana.y"
                 {

	info6.path=(yyvsp[0].cadena);

}
#line 2810 "y.tab.cpp"
    break;

  case 160:
#line 948 "ana.y"
                 {

	info6.path=(yyvsp[0].cadena);

}
#line 2820 "y.tab.cpp"
    break;

  case 161:
#line 953 "ana.y"
                {

	info6.id=(yyvsp[0].cadena);

}
#line 2830 "y.tab.cpp"
    break;

  case 162:
#line 958 "ana.y"
                 {

	info6.id=(yyvsp[0].cadena);

}
#line 2840 "y.tab.cpp"
    break;

  case 163:
#line 963 "ana.y"
                 {

	info6.id=(yyvsp[0].cadena);

}
#line 2850 "y.tab.cpp"
    break;

  case 164:
#line 981 "ana.y"
                             {

	info7.path=(yyvsp[0].cadena);

}
#line 2860 "y.tab.cpp"
    break;

  case 165:
#line 986 "ana.y"
                 {

	info7.path=(yyvsp[0].cadena);

}
#line 2870 "y.tab.cpp"
    break;


#line 2874 "y.tab.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 995 "ana.y"

/*Codigo en C requerido por el usuario*/


/*extern char *yytext;
extern int linea;*/

void yyerror (  char const *s){
	printf("Info: %s\n", s);
	printf("Texto: %s\n", yytext);
	printf("Linea: %d\n", linea);
	
	comando=0;
	
}








/*
int main (int argc, char **argv){
if(argc>1)
yyin=fopen(argv[1],"rt");
else
yyin=stdin;
yyparse();
return 0;
}
*/