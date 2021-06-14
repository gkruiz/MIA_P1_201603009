
#include <fstream>
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
//#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <math.h>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#include <sstream>

using namespace std;
void rec9();


#include "Estructuras.h"///Aqui va el MBR , EBR ,estructuras a guardar
#include "Comandos.h"///Aqui van todos los comandos que se pueden escribir
#include "Genericas.h"///Aqui van las funciones genericas para usar


///Informacion Global
//vector <DiskMount> Montadas;
nodo * PMontadas;
Login logueada;


int comando=0;
char* ass;

MKD info1;
RMD info2;
FDI info3;
MOU info4;
UNM info5;
RE info6;
EXE info7;
Mkfs info8;

Login info9;
Mkdir info10;




//#include "Analisis/ana.tab.c"
#include "List9.h"
#include "Fdisk.h"
#include "Reporte9.h"
#include "Clasifica9.h"
#include "Analisis/y.tab.h"
#include "Analisis/y.tab.c"
#include "Analisis/lex.yy.c"
#include "fuciones.h"///Aqui van de momento lo que ejecuta todos los comandos

#include "Sistema/SArchivos.h"
#include "Sistema/buildSA.h"

#include "Consola.h"


int main (){

    cout<<sizeof(bool)<<endl;
    //rec9();

    Consol();


return 0;
}


void rec9(){

    vector<DiskMount>mons;

    DiskMount temp;

    temp.let='a';
    temp.num=1;
    temp.name="asdf1";
    temp.path="nose1";
    mons.push_back(temp);


    temp.let='b';
    temp.num=2;
    temp.name="asdf2";
    temp.path="nose2";
    mons.push_back(temp);


    temp.let='c';
    temp.num=3;
    temp.name="asdf3";
    temp.path="nose3";
    mons.push_back(temp);


    temp.let='d';
    temp.num=4;
    temp.name="asdf4";
    temp.path="nose4";
    mons.push_back(temp);

    temp.let='e';
    temp.num=5;
    temp.name="asdf5";
    temp.path="nose5";
    mons.push_back(temp);



    upMontadas(mons);

    //cout<<"paso1"<<endl;
    vector <DiskMount> ss=getMontadas();

    /*for(int i=0;i<ss.size();i++){
        cout<<ss[i].let<<endl;
        cout<<ss[i].name<<endl;
        cout<<ss[i].num<<endl;
        cout<<ss[i].path<<endl;
    }*/


    nodo * tempf=PMontadas;

    while((tempf)!=0){
        cout<<(tempf->info).let<<endl;
        cout<<(tempf->info).name<<endl;
        cout<<(tempf->info).num<<endl;
        cout<<(tempf->info).path<<endl;
        tempf=tempf->sig;
    }


}



