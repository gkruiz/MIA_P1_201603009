/*archivos de cabecera de C*/
%{

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
%}
%union
{
char* cadena;
float real;
}
%locations
%start inicio_comando
/***** definir tokens***/
%token <real> NUMERO
%token <cadena> RUTA1
%token <cadena> RUTA2
%token <cadena> CADENA
%token <cadena> CADENA2
%token <cadena> COME


%token <cadena> MKDISK
%token <cadena> RMDISK
%token <cadena> FDISK
%token <cadena> MOUNT
%token <cadena> UNMOUNT
%token <cadena> REP
%token <cadena> EXEC

%token <cadena> SIZE
%token <cadena> PATH
%token <cadena> FIT
%token <cadena> UNIT
%token <cadena> NAME
%token <cadena> TYPE
%token <cadena> DELETE
%token <cadena> ADD
%token <cadena> ID
%token <cadena> FILES
%token <cadena> FS
%token <cadena> PWD
%token <cadena> USR
%token <cadena> GRP
%token <cadena> UGO
%token <cadena> R
%token <cadena> P
%token <cadena> CONT
%token <cadena> FILEN
%token <cadena> DEST
%token <cadena> INCOG
%token <cadena> ASTER
%token <cadena> LOGIN
%token <cadena> LOGOUT
%token <cadena> MKGRP
%token <cadena> RMGRP
%token <cadena> MKUSR
%token <cadena> RMUSR
%token <cadena> CHMOD
%token <cadena> MKFILE
%token <cadena> REM
%token <cadena> EDIT
%token <cadena> REN
%token <cadena> MKDIR
%token <cadena> CP
%token <cadena> MV
%token <cadena> FIND
%token <cadena> CHOWN
%token <cadena> CHGRP
%token <cadena> PAUSE
%token <cadena> RECOVERY
%token <cadena> LOSS
%token <cadena> CAT
%token <cadena> MKFS
%token <cadena> IGUAL
%token <cadena> NUMERAL
%token <cadena> RUTA

/****************************/
%type <cadena> inicio_comando
%type <cadena> parametros1
%type <cadena> parametros2
%type <cadena> parametros3
%type <cadena> parametros4
%type <cadena> parametros5
%type <cadena> parametros6
%type <cadena> parametros7
%type <cadena> parametros8
%type <cadena> parametros9

%type <cadena> parametros11
%type <cadena> parametros12
%type <cadena> parametros13
%type <cadena> parametros14
%type <cadena> parametros15
%type <cadena> parametros16
%type <cadena> parametros17
%type <cadena> parametros18
%type <cadena> parametros19
%type <cadena> parametros20
%type <cadena> parametros21
%type <cadena> parametros22
%type <cadena> parametros23
%type <cadena> parametros24
%type <cadena> parametros25
%type <cadena> parametros26
%type <cadena> parametros27
%type <cadena> parametros28

%type <cadena> parametro1
%type <cadena> parametro3
%type <cadena> parametro4
%type <cadena> parametro6
%type <cadena> parametro8
%type <cadena> parametro9

%type <cadena> parametro13
%type <cadena> parametro15
%type <cadena> parametro16
%type <cadena> parametro19
%type <cadena> parametro20
%type <cadena> parametro21
%type <cadena> parametro22
%type <cadena> parametro23
%type <cadena> parametro24
%type <cadena> parametro25
%type <cadena> parametro26
%type <cadena> COMAND
%type <cadena> COMD


%right RMDISK FDISK MOUNT REP UNMOUNT EXEC
%right MKFS LOGIN LOGOUT MKGRP RMGRP RMUSR CHMOD MKFILE CAT REM EDIT REN MKDIR CP MV FIND
%right CHOWN CHGRP PAUSE RECOVERY LOSS NUMERAL RUTA

%%



/*Reglas de la gramática*/

inicio_comando: COMAND;



COMAND: COMAND COMD
		|COMD;

		
		
COMD: MKDISK parametros1{
	ClaComando(1);
}
|RMDISK 	parametros2{
	ClaComando(2);
}
|FDISK 		parametros3{
	ClaComando(3);
}
|MOUNT 		parametros4{
	ClaComando(4);
}
|UNMOUNT 	parametros5{
	ClaComando(5);
}
|REP 		parametros6{
	ClaComando(6);
}
|EXEC 		parametros7{
	ClaComando(7);
}
|MKFS 		parametros8{
	ClaComando(8);
}
|LOGIN 		parametros9{
	ClaComando(9);
}
|LOGOUT 	{
	Login borra;
	logueada=borra;
}
|MKGRP 		parametros11{
	comando=7;
}
|RMGRP 		parametros12{
	comando=7;
}
|MKUSR 		parametros13{
	comando=7;
}
|RMUSR 		parametros14{
	comando=7;
}
|CHMOD 		parametros15{
	comando=7;
}
|MKFILE 	parametros16{
	comando=8;
}
|CAT 		parametros17{
	comando=7;
}
|REM 		parametros18{
	comando=7;
}
|EDIT 		parametros19{
	comando=7;
}
|REN 		parametros20{
	comando=7;
}
|MKDIR 		parametros21{
	comando=7;
}
|CP 		parametros22{
	comando=7;
}
|MV 		parametros23{
	comando=7;
}
|FIND 		parametros24{
	comando=7;
}
|CHOWN 		parametros25{
	comando=7;
}
|CHGRP 		parametros26{
	comando=7;
}
|PAUSE 	{
	ClaComando(20);
}
|RECOVERY 	parametros27{
	comando=7;
}
|LOSS 		parametros28{
	comando=7;
}


;











/*MKFS*/

parametros8:parametros8 parametro8
|parametro8;

parametro8:ID IGUAL CADENA{
	info8.id=$3;
	
}
|TYPE IGUAL CADENA{
	
	char*ps1="fast";
	char*ps2="full";
	if(Compare($3,ps1)){
		info8.type=1;
	}else if(Compare($3,ps2)){
		info8.type=2;
	}else{
		info8.type=0;
		printf("El tipo de formateo es erroneo");
	}
	
}
|FS IGUAL CADENA{
	char*ps1="2fs";
	char*ps2="3fs";
	if(Compare($3,ps1)){
		info8.fs=1;
	}else if(Compare($3,ps2)){
		info8.fs=2;
	}else{
		info8.fs=0;
		printf("El tipo de sistema de archivos es erroneo");
	}
	
};






/*LOGIN*/

parametros9:parametros9 parametro9
|parametro9
;

parametro9:USR IGUAL CADENA{
	info9.usuario=$3;
}
|USR IGUAL CADENA2{
	info9.usuario=$3;
}
|PWD IGUAL CADENA{
	info9.password=$3;
}
|PWD IGUAL CADENA2{
	info9.password=$3;
}
|PWD IGUAL NUMERO{
	int tex=$3;
	info9.password=intToCharP(tex);
}
|ID IGUAL CADENA{
	info9.id=$3;
};










/*MKGRP*/

parametros11:NAME IGUAL CADENA{

}
|NAME IGUAL CADENA2{

}
;


/*RMGRP*/

parametros12:NAME IGUAL CADENA{

}
|NAME IGUAL CADENA2{

};



/*MKUSR*/

parametros13:parametros13 parametro13
|parametro13;

parametro13:USR IGUAL CADENA{

}
|USR IGUAL CADENA2{

}
|PWD IGUAL CADENA{

}
|GRP IGUAL CADENA{

}
|GRP IGUAL CADENA2{

};




/*RMUSR*/

parametros14:USR IGUAL CADENA{

}
|USR IGUAL CADENA2{

};



/*CHMOD*/

parametros15:parametros15 parametro15
|parametro15;

parametro15:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|UGO IGUAL CADENA{

}
|R {

};







/*MKFILE*/

parametros16:parametros16 parametro16
|parametro16;

parametro16:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|R {

}
|SIZE IGUAL NUMERO{

}
|CONT IGUAL RUTA1{

}
|CONT IGUAL RUTA2{

}
;







/*CAT*/

parametros17:FILES IGUAL RUTA1{

}
|FILES IGUAL RUTA2{

};




/*REM*/

parametros18:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{


};




/*EDIT*/

parametros19:parametros19 parametro19
|parametro19;

parametro19:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|CONT IGUAL RUTA1{

}
|CONT IGUAL RUTA2{

};




/*REN*/

parametros20:parametros20 parametro20
|parametro20;

parametro20:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|NAME IGUAL CADENA{

}
|NAME IGUAL CADENA2{

}
;




/*MKDIR*/

parametros21:parametros21 parametro21
|parametro21;

parametro21:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|P{

}
;




/*CP*/

parametros22:parametros22 parametro22
|parametro22;

parametro22:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|DEST IGUAL RUTA1{

}
|DEST IGUAL RUTA2{

}
;




/*MV*/

parametros23:parametros23 parametro23
|parametro23;

parametro23:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|DEST IGUAL RUTA1{

}
|DEST IGUAL RUTA2{

}
;





/*FIND*/

parametros24:parametros24 parametro24
|parametro24;

parametro24:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|NAME IGUAL INCOG{

}
|NAME IGUAL ASTER{

}
|NAME IGUAL CADENA{

}
|NAME IGUAL CADENA2{

}
;





/*CHOWN*/

parametros25:parametros25 parametro25
|parametro25;

parametro25:PATH IGUAL RUTA1{

}
|PATH IGUAL RUTA2{

}
|R{

}
|USR IGUAL CADENA{

}
|USR IGUAL CADENA2{

}
;





/*CHGRP*/

parametros26:parametros26 parametro26
|parametro26;

parametro26:USR IGUAL CADENA{

}
|USR IGUAL CADENA2{

}
|GRP IGUAL CADENA{

}
|GRP IGUAL CADENA2{

}
;






/*RECOVERY*/

parametros27:ID IGUAL CADENA{

}
;



/*LOSS*/

parametros28:ID IGUAL CADENA{

}
;














/*MKDISK*/

parametros1:parametros1 parametro1
|parametro1;

parametro1:SIZE IGUAL NUMERO{

	if($3>0){
		info1.size=(int)$3;
	}else{
	char* salex="El tamano es incorrecto";
	Impri(salex);
		//el tamano no es correcto
	}
}
|FIT IGUAL CADENA{
	char* compa="bf";
	char* compa1="ff";
	char* compa2="wf";
	
	if(Compare(compa,$3)){
		info1.fit=1;
	}else if(Compare(compa1,$3)){
		info1.fit=2;
	}else if(Compare(compa2,$3)){
		info1.fit=3;
	}else{
	char* salex="El ajuste es incorrecto";
	Impri(salex);
	//el ajuste no es correcto
	}
}
|UNIT IGUAL CADENA{

	char* compa1="k";
	char* compa2="m";
	
	if(Compare(compa1,$3)){
		info1.unit=1;
	}else if(Compare(compa2,$3)){
		info1.unit=2;
	}else{
	char* salex="Las unidades no son correctas";
	Impri(salex);
	//las unidades no son correctas
	}
}
|PATH IGUAL RUTA1{

	info1.path=$3;
}
|PATH IGUAL RUTA2{

	info1.path=$3;
};









/*RMDISK*/

parametros2: PATH IGUAL RUTA1{

	info2.path=$3;

}
|PATH IGUAL RUTA2{

	info2.path=$3;

};










/*FDISK*/

parametros3:parametros3 parametro3
|parametro3;

parametro3:SIZE IGUAL NUMERO{

	if($3>0){
		info3.size=(int)$3;
	}else{
	char* salex="El tamano es incorrecto";
	Impri(salex);
		//el tamano no es correcto
	}
}
|UNIT IGUAL CADENA{

	char* compa="b";
	char* compa1="k";
	char* compa2="m";
	
	if(Compare(compa,$3)){
		info3.unit=1;
	}else if(Compare(compa1,$3)){
		info3.unit=2;
	}else if(Compare(compa2,$3)){
		info3.unit=3;
	}else{
	char* salex="las unidades son incorrectas";
	Impri(salex);
	//las unidades no son correctas
	}
}
|FIT IGUAL CADENA{
	char* compa="bf";
	char* compa1="ff";
	char* compa2="wf";
	
	if(Compare(compa,$3)){
		info3.fit=1;
	}else if(Compare(compa1,$3)){
		info3.fit=2;
	}else if(Compare(compa2,$3)){
		info3.fit=3;
	}else{
	char* salex="El ajuste es incorrecto";
	Impri(salex);
	//el ajuste no es correcto
	}
}
|PATH IGUAL RUTA1{

	info3.path=$3;

}
|PATH IGUAL RUTA2{

	info3.path=$3;

}
|TYPE IGUAL CADENA{
	char* compa="p";
	char* compa1="e";
	char* compa2="l";
	
	if(Compare(compa,$3)){
		info3.type=1;
	}else if(Compare(compa1,$3)){
		info3.type=2;
	}else if(Compare(compa2,$3)){
		info3.type=3;
	}else{
	char* salex="El tipo de particion es incorrecto";
	Impri(salex);
	//el tipo de partcion no es correcto
	}
}
|DELETE IGUAL CADENA{
	char* compa="fast";
	char* compa1="full";
	
	if(Compare(compa,$3)){
		info3.delet=1;
	}else if(Compare(compa1,$3)){
		info3.delet=2;
	}else{
	char* salex="El valor de eliminar es incorrecto";
	Impri(salex);
	//el tipo de partcion no es correcto
	}
}
|NAME IGUAL CADENA{

	info3.name=$3;

}
|ADD IGUAL NUMERO{

	info3.add=(int)$3;

};










/*MOUNT*/

parametros4:parametros4 parametro4
|parametro4;

parametro4:NAME IGUAL CADENA{

	info4.name=$3;

}
|PATH IGUAL RUTA1{

	info4.path=$3;

}
|PATH IGUAL RUTA2{

	info4.path=$3;

};











/*UNMOUNT*/

parametros5: ID IGUAL CADENA{

	info5.id=$3;

};










/*REP*/

parametros6:parametros6 parametro6
|parametro6;

parametro6:NAME IGUAL CADENA{
	
}
|PATH IGUAL RUTA1{

	info6.path=$3;

}
|PATH IGUAL RUTA2{

	info6.path=$3;

}
|ID IGUAL CADENA{

	info6.id=$3;

}
|RUTA IGUAL RUTA1{

	info6.id=$3;

}
|RUTA IGUAL RUTA2{

	info6.id=$3;

};











/*EXEC*/

parametros7: PATH IGUAL RUTA1{

	info7.path=$3;

}
|PATH IGUAL RUTA2{

	info7.path=$3;

};



/****************************/
%%
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
