/*Esta sección es para cabeceras de C*/
%{



#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"

int linea =0;



%}
%option noyywrap

DIGITO [0-9]
LETRA [A-Za-z]
COMI "\""
DIAGO "/"
GUIONB "_"
GUIONA "-"


NUMERO {GUIONA}?{DIGITO}+("."{DIGITO}+)?

RUTA1 ({DIAGO}({LETRA}|{NUMERO}|{GUIONB}|{GUIONA})+)+((".")({LETRA})+)?
RUTA2 {COMI}(({DIAGO}((" ")|{LETRA}|{NUMERO}|{GUIONB}|{GUIONA})+)+((".")({LETRA}+))?){COMI}

CAD ({LETRA}|{NUMERO}|{GUIONB}|{GUIONA})+
CADENA ({CAD})

CADENA2 {COMI}(({CAD})((" ")+{CAD})*){COMI}





/*****************************/
%%


"mkdisk" 	{return(MKDISK);}
"rmdisk" 	{return(RMDISK);}
"fdisk" 	{return(FDISK);}
"mount" 	{return(MOUNT);}
"unmount" 	{return(UNMOUNT);}
"rep" 		{return(REP);}
"exec" 		{return(EXEC);}

"-ruta" 	{return(RUTA);}
"-size" 	{return(SIZE);}
"-path" 	{return(PATH);}
"-f" 		{return(FIT);}
"-u" 		{return(UNIT);}
"-name" 	{return(NAME);}
"-type" 	{return(TYPE);}
"-delete" 	{return(DELETE);}
"-add" 		{return(ADD);}
"-id" 		{return(ID);}

"-fs" 		{return(FS);}
"-usr" 		{return(USR);}
"-pwd" 		{return(PWD);}
"-grp" 		{return(GRP);}
"-ugo" 		{return(UGO);}
"-R" 		{return(R);}
"-p" 		{return(P);}
"-cont" 	{return(CONT);}
"-file"		{return(FILES);}
"-dest" 	{return(DEST);}
"?" 		{return(INCOG);}
"*" 		{return(ASTER);}
"login" 	{return(LOGIN);}
"logout" 	{return(LOGOUT);}
"mkgrp" 	{return(MKGRP);}
"rmgrp" 	{return(RMGRP);}
"mkusr" 	{return(MKUSR);}
"rmusr" 	{return(RMUSR);}
"chmod" 	{return(CHMOD);}
"mkfile" 	{return(MKFILE);}
"rem" 		{return(REM);}
"edit" 		{return(EDIT);}
"ren" 		{return(REN);}
"mkdir" 	{return(MKDIR);}
"cp" 		{return(CP);}
"mv" 		{return(MV);}
"find" 		{return(FIND);}
"chown" 	{return(CHOWN);}
"chgrp" 	{return(CHGRP);}
"pause" 	{return(PAUSE);}
"recovery" 	{return(RECOVERY);}
"loss" 		{return(LOSS);}
"cat" 		{return(CAT);}
"mkfs" 		{return(MKFS);}



"=" 		{return(IGUAL);}
"#" 		{return(NUMERAL);}


{NUMERO} 	{yylval.real=atof(yytext); return(NUMERO);}
{RUTA1} 	{yylval.cadena=ArrtoCharP(yytext);return(RUTA1);}
{RUTA2} 	{yylval.cadena=ArrtoCharP(yytext);return(RUTA2);}
{CADENA} 	{yylval.cadena=ArrtoCharP(yytext);return(CADENA);}
{CADENA2} 	{yylval.cadena=ArrtoCharP(yytext);return(CADENA2);}

"\n" 		{linea++;}
[\t\r\f] 	{}
" " 		{}


. {printf("Error lexico en linea %d\n", linea);
printf("Texto: %s\n", yylval.cadena);

}
%%
/*CODIGO REQUERIDO DE FUNCIONES EN C*/
