
int longitud(char*cad){

	int i=0;

	if(cad!=0){
        while(cad[i]!=0){
			i++;
		}
	}


	return i;
}



char* componeC(char*cad){


    char * nue=(char*)malloc(sizeof(char)*12);

    int j=0;
    int i=0;

	if(cad!=0){
        while(i!=12){
            if(cad[i]>47&&cad[i]<122){
                nue[j]=cad[i];
                j++;
            }
			i++;
		}
	}


	return nue;
}


bool Compare(char*cad1 ,char*cad2){
	bool comparo=false;

	if(cad1!=0&&cad2!=0){
        int l1=longitud(cad1);
        int l2=longitud(cad2);


        if(l1==l2){
            int i=0;
            while(cad1[i]==cad2[i]){
                if(i==l1){
                    comparo=true;
                    break;
                }
                i++;
            }
        }

	}

	return comparo;
}


char * ArrtoCharP(char array[]){
	//pasa de array a puntero


	int l1=longitud(array);
	char * tempo=(char*)malloc(sizeof(char)*(l1+1));
	//cout<<array<<endl;
		int i=0;
		while(i<l1){
			tempo[i]=array[i];
			i++;
		}
	tempo[i]=0;

 return tempo;
}


char*UneChar(char*cad1,char*cad2){

	int longi1=longitud(cad1);
	int longi2=longitud(cad2);

	char *final=(char*)malloc(sizeof(char)*(longi1+longi2+1));

	for(int i=0;i<longi1;i++){
		final[i]=cad1[i];
	}
	for(int i=0;i<longi2;i++){
		final[longi1+i]=cad2[i];
	}
	final[longi1+longi2]=0;

	return final;
}



void Impri(char *cade){

	cout<<cade<<endl;

}

void ClStru(short com,void * estT){

    if(com=1){
        MKD estru;
        MKD *real=(MKD*)estT;
        (*real)=estru;

    }else if(com=2){
        RMD estru;
        RMD *real=(RMD*)estT;
        (*real)=estru;

    }else if(com=3){
        FDI estru;
        FDI *real=(FDI*)estT;
        (*real)=estru;

    }else if(com=4){
        MOU estru;
        MOU *real=(MOU*)estT;
        (*real)=estru;

    }else if(com=5){
        UNM estru;
        UNM *real=(UNM*)estT;
        (*real)=estru;

    }else if(com=6){
        RE estru;
        RE *real=(RE*)estT;
        (*real)=estru;

    }else if(com=7){
        EXE estru;
        EXE *real=(EXE*)estT;
        (*real)=estru;

    }else{
        ///El comando es 0 , no hay alguno
    }


}



char * stringtocharp(string cadena){
    char * reto=(char*)malloc((cadena.length()+2)*(sizeof(char*)));
    for(int i=0;i<cadena.length();i++){
        ((reto[i]))=cadena.at(i);
    }
    reto[cadena.length()]=0;
    return reto;

}





char * RPfd(char * cadena){
	//elimina comillas y primera diagonal
	int longi=longitud(cadena);
	bool diago=true;
	int j=0;
	char* nueva=(char*)malloc(sizeof(char)*(longi+1));
	for(int i=0;i<longi;i++){
		if((cadena[i]!='"')){
			nueva[j]=cadena[i];
			j++;
		}
		/*else if((cadena[i]=='/')&&(!diago)){
			nueva[j]='\\';
			j++;
		}else if((cadena[i]=='/')&&(diago)){
			diago=false;
		}*/

	}
		nueva[j]=0;

	return nueva;
}


char DetFitPar(int num){
	char retorna=0;
	if(num==1){
		retorna='b';
	}else if(num==2){
		retorna='f';
	}else if(num==3){
		retorna='w';
	}
	return retorna;
}


//Determina el tipo de Particion segun un numero
char DetTpar(int num){
	char retorna=0;
	if(num==1){
		retorna='p';
	}else if(num==2){
		retorna='e';
	}else if(num==3){
		retorna='l';
	}
	return retorna;
}


char * intToCharP(int numero){

        string Result;          // string which will contain the result
        ostringstream convert;   // stream used for the conversion
        convert << numero;      // insert the textual representation of 'Number' in the characters in the stream
        Result = convert.str();
        char * p2= stringtocharp(Result);

    return p2;
}


char * chaToCharP(char cha){

        char temps[2]={cha,0};
        char * p2= ArrtoCharP(temps);

    return p2;
}



//Retorna la partincion extendida del mbr
PARTITION getExtPartition(MBR copia){

	if(copia.particion1.part_type=='e'){
		return copia.particion1;
	}else if(copia.particion2.part_type=='e'){
		return copia.particion2;
	}else if(copia.particion3.part_type=='e'){
		return copia.particion3;
	}else if(copia.particion4.part_type=='e'){
		return copia.particion4;
	}else{
	    PARTITION vacio;
		return vacio;
	}
}




//Lee los ebrs del archivo
vector<EBR> ReadEBRs(ifstream &archivo,PARTITION extendida){

	//este metodo lee los ebr enlazados
	//y los guarda en una lista
	vector<EBR> temporal;//donde se guardan los ebr's
	bool primero=true;
	int sumacero=sizeof(MBR);
	int posicionLeer=extendida.part_start+sumacero;
	//ifstream archivo=archiv;

	while(true){
		EBR ebrtempo;
		//cout<<"traslada:"<<posicionLeer<<endl;
		archivo.seekg(posicionLeer);//se traslada en donde empieza la particion extendida
		//cout<<"lee:"<<endl;
		archivo.read((char*)&ebrtempo, sizeof(ebrtempo));//lee un ebr
		if((ebrtempo.part_fit=='b')||(ebrtempo.part_fit=='f')||(ebrtempo.part_fit=='w')||((ebrtempo.part_next!=-1)&&(ebrtempo.part_next!=0))){
			/*cout<<ebrtempo.part_fit<<endl;
			cout<<ebrtempo.part_name<<endl;
			cout<<ebrtempo.part_next<<endl;
			cout<<ebrtempo.part_size<<endl;
			cout<<ebrtempo.part_start<<endl;
			cout<<ebrtempo.part_status<<endl;
			cout<<ebrtempo.part_type<<endl;
            cout<<endl<<endl;*/

			//encontro un ebr en la posicion
		temporal.push_back(ebrtempo);//guarda el ebr hallado

			if(ebrtempo.part_next!=-1){//si hay otro ebr siguiente
				posicionLeer=ebrtempo.part_next+sumacero;
			}else{
				break;
			}

		}else{
			//cout<<"no hay ebr"<<endl;
			//si en el primer ebr no hay nada
			break;
		}
	}

	return temporal;
}




//Busca nombres repetidos en los ebrs
bool validaNombres(vector <EBR> lista,char nombre[]){
	bool retorna=false;

		for(int i=0;i<lista.size();i++){

			EBR tempo=lista[i];
                    /*cout<<"A Buscar:"<<nombre<<endl;
					cout<<"Particiones logicas"<<endl;
				 	cout<<"fit:"<<tempo.part_fit <<endl;
				 	cout<<"name:"<<tempo.part_name <<endl;
				 	cout<<"next:"<<tempo.part_next <<endl;
				 	cout<<"size:"<<tempo.part_size <<endl;
				 	cout<<"start:"<<tempo.part_start <<endl;
				 	cout<<"status:"<<tempo.part_status <<endl;
				 	cout<<"type:"<<tempo.part_type <<endl;*/


            char * nombs= ArrtoCharP(nombre);
			if(Compare(nombs,tempo.part_name)){
				retorna=true;
				break;
			}


		}
	return retorna;
}




vector<char *> splitC(char * cadena,char sepa){

    int longitudc= longitud(cadena);
    int i=0;

    vector<char *> lista;

    vector<char> cade;


    if((longitudc)!=0){
        while(i!=longitudc){
            char t=cadena[i];
                if(t!=sepa){
                    cade.push_back(t);
                }else if(cade.size()>0){
                    ///traslada lo guardado en cade a u char puntuero
                    vector<char> vaci;
                    char * tempo= (char*) malloc(sizeof(char)*(cade.size()+1));
                    for(int j=0;j<cade.size();j++){
                        tempo[j]=cade[j];
                    }
                    tempo[cade.size()]=0;
                    lista.push_back(tempo);
                    cade=vaci;
                }
            i++;
        }


        if(cade.size()>0){
            ///traslada lo guardado en cade a u char puntuero final
            vector<char> vaci;
            char * tempo= (char*) malloc(sizeof(char)*(cade.size()+1));
            for(int j=0;j<cade.size();j++){
                tempo[j]=cade[j];
            }
            tempo[cade.size()]=0;
            lista.push_back(tempo);
            cade=vaci;
        }

    }


    return lista;

}

template<typename T>
void pop_front(std::vector<T> &v)
{
    if (v.size() > 0) {
        v.erase(v.begin());
    }
}
