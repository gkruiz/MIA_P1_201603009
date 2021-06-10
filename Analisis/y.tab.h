/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 125 "y.tab.h"

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
