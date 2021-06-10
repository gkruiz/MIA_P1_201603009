
char * RPfd(char * cadena);
bool MinFD(int tipo,FDI info);
vector<StartSize> sortArray(vector<StartSize> arra);
StartSize PosParti(vector<StartSize> espacios,char fitM,int sizeP);
void ParticionPRIMARIA(int sizen,PARTITION newp,FDI info);
int PosNueva(MBR copia,int sizeP);


bool validaNombres(vector <EBR> lista,char nombre[]);
vector<EBR> LinkpartitionEBR(EBR nuevo,vector<EBR> ebrs);
int PosNuevaLOGICA(vector<EBR> starts,int sizeP,PARTITION part);
vector<EBR> ReadEBRs(ifstream &archiv,PARTITION extendida);
PARTITION getExtPartition(MBR copia);
void ParticionLOGICA(int sizen,EBR newp,FDI info);
bool FormateaParticion(int inicio,int size,char*nombre,MBR nuevo,int formateo);
void EliminaParticion(FDI info);
vector<EBR> EliminaEBR(char* nombre,vector<EBR> ebrs);
void ActualizaLogicas(vector<EBR> pguardar,char * nomarchivo,MBR copia);
vector<StartSize> EspaModi(MBR copia,int sizeP,int start);
vector<EBR> ExtMovPLogAtras(vector<EBR> particiones,int startNuevo);
void ModificaParticion(FDI info);
vector<StartSize> EspaModiLogi(vector<EBR> starts,PARTITION part,int sizeP, int start);
void PrintSistemaParticiones(char *nombreDisco);

void FDISKCEM(FDI info){

	//3casos
	//crea particion
	//modifica particion
	//elimina particion


	if(info.add!=0){
	//es una modificacion de particion
	//minimos: path , name,add /opcionales: unit
		if(MinFD(1,info)){
            ModificaParticion(info);

		}else{
		cout<<"Hacen falta parametros para la modificacion de la particion"<<endl;
		}
	}else if(info.delet!=0){
	//es una eliminacion
	//minimos:path ,name,delet
		if(MinFD(2,info)){
            EliminaParticion(info);

		}else{
		cout<<"Hacen falta parametros para la eliminacion de la particion"<<endl;
		}
	}else{
	//es una creacion
	//minimos:path,name,size/opcionales: unit, type,fit
		if(MinFD(3,info)){

		//si particion primaria o extendida
		if((info.type==1)||(info.type==2)){
			PARTITION newp;
			newp.part_status='1';
			newp.part_type=DetTpar(info.type);
			newp.part_fit=DetFitPar(info.fit);
			//newp.part_start
			newp.part_size=info.size*(pow(1024,((double)(info.unit-1))));
			strcpy(newp.part_name, info.name);

		ParticionPRIMARIA(newp.part_size,newp,info);

		}else{
			//La particion es logica
			EBR nuevo;
			nuevo.part_fit=DetFitPar(info.fit);
			strcpy(nuevo.part_name, info.name);
			//nuevo.part_next
			nuevo.part_size=info.size*(pow(1024,((double)(info.unit-1))));
			//nuevo.part_start
			nuevo.part_status='1';
			nuevo.part_type='l';

			ParticionLOGICA(nuevo.part_size,nuevo,info);
		}




		}else{
		 cout<<"Hacen falta parametros para la creacion de la particion"<<endl;
		}
	}


}





void ParticionPRIMARIA(int sizen,PARTITION newp,FDI info){
	//crea particion PRIMARIA
	//busca lugar libre de 4
	//calcula espacios libres
	//aplico fit y retorno posicion donde guardar
	//-1 si no hay lugar disponible
	//no importa si hay extendidas o logicas o primarias
	MBR tempoMBR;

	char *nomarchivo=RPfd(info.path);

	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	if(input_file){

        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
        //VALIDAR QUE ARCHIVO NO EXISTE
        PARTITION retorna=newp;

        int tamano=tempoMBR.mbr_tamano;
            cout<<"PARTICION PRIMARIA O EXTENDIDA:"<<endl;
            cout<<"FIT:"<<tempoMBR.disk_fit<<endl;
            cout<<"codigo:"<<tempoMBR.mbr_disk_signature<<endl;
            cout<<"tamano:"<<tempoMBR.mbr_tamano <<endl;
            cout<<"nombre:"<<tempoMBR.particion1.part_name <<"  start:"<<tempoMBR.particion1.part_start <<"  size:"<<tempoMBR.particion1.part_size <<endl;
            cout<<"nombre:"<<tempoMBR.particion2.part_name <<"  start:"<<tempoMBR.particion2.part_start <<"  size:"<<tempoMBR.particion2.part_size <<endl;
            cout<<"nombre:"<<tempoMBR.particion3.part_name <<"  start:"<<tempoMBR.particion3.part_start <<"  size:"<<tempoMBR.particion3.part_size <<endl;
            cout<<"nombre:"<<tempoMBR.particion4.part_name <<"  start:"<<tempoMBR.particion4.part_start <<"  size:"<<tempoMBR.particion4.part_size <<endl;

        ///calcula suma tamano todas las particiones
        int sumParticiones= tempoMBR.particion1.part_size+tempoMBR.particion2.part_size+tempoMBR.particion3.part_size+tempoMBR.particion4.part_size;
        ///calcula si existe una celda libre de las 4
        bool SpaLibre=(tempoMBR.particion1.part_size==0)||(tempoMBR.particion2.part_size==0)||(tempoMBR.particion3.part_size==0)||(tempoMBR.particion4.part_size==0);

        bool extendida = false;//no hay extendida
        //Sirve para hacer busqueda nombre de Logicas
        bool extLogi =(tempoMBR.particion1.part_type=='e')||(tempoMBR.particion2.part_type=='e')||(tempoMBR.particion3.part_type=='e')||(tempoMBR.particion4.part_type=='e');

        ///si hay que crear una extendida busca que exista alguna
        if(info.type==2){
            extendida=(tempoMBR.particion1.part_type=='e')||(tempoMBR.particion2.part_type=='e')||(tempoMBR.particion3.part_type=='e')||(tempoMBR.particion4.part_type=='e');
        }


        if(extendida){
            cout<<"Ya existe una particion extendida en el disco"<<endl;
         }else{
            ///Valida que Halla Espacio , Tambien que exista una de las 4 particiones posibles, y verifica que no exista una particion Extendida
            if((tamano-sumParticiones>=sizen)&&(SpaLibre)&&(!extendida)){


            ///compara los nombres de cada particion existente con el nuevo a asingar
             bool nom1=Compare(tempoMBR.particion1.part_name,info.name);
             bool nom2=Compare(tempoMBR.particion2.part_name,info.name);
             bool nom3=Compare(tempoMBR.particion3.part_name,info.name);
             bool nom4=Compare(tempoMBR.particion4.part_name,info.name);
             bool nom5=false;

            //valida que exista la particion extendida
            if(extLogi){
            //seleccion la particion extendida
                PARTITION extendida=getExtPartition(tempoMBR);
                //lista de ebr encontrados
                vector<EBR>leidos=ReadEBRs(input_file,extendida);
                //cout<<"tamebrs:"<<leidos.size()<<endl;
                nom5=validaNombres(leidos,info.name);
            }




            //los nombres no son iguales
                if(!(nom1||nom2||nom3||nom4||nom5)){
                        ///busca start particion para asignar a la nueva particion
                        int posicionD=PosNueva(tempoMBR,sizen);
                        //cout<<"posocion:"<<posicionD<<endl;
                        //si encuentra una posicion adecuada asigna la posicion de inicio
                        //y lo guarda en el mbr

                        if(posicionD!=-1){
                            //asigna el inicio de la particion
                            retorna.part_start=posicionD;


                                if(info.type==2){
                                    ///Suma un ebr para ajustar espacio en EXTENDIDA, sino quita una pequena porcion
                                    retorna.part_size=retorna.part_size+(sizeof(EBR));
                                }



                                //selecciona la celda para guardar la particion
                                if(tempoMBR.particion1.part_size==0){
                                    tempoMBR.particion1=retorna;
                                }else if(tempoMBR.particion2.part_size==0){
                                    tempoMBR.particion2=retorna;
                                }else if(tempoMBR.particion3.part_size==0){
                                    tempoMBR.particion3=retorna;
                                }else if(tempoMBR.particion4.part_size==0){
                                    tempoMBR.particion4=retorna;
                                }
                            //cierra el archivo de lectura del disco
                            input_file.close();



                            /*cout<<tempoMBR.particion1.part_name<<endl;
                            cout<<info.name<<endl;


                            cout<<"nom1:"<<nom1<<endl;
                            cout<<"nom2:"<<nom2<<endl;
                            cout<<"nom3:"<<nom3<<endl;
                            cout<<"nom4:"<<nom4<<endl;


                            cout<<"FIT:"<<retorna.part_fit<<endl;
                            cout<<"name:"<<retorna.part_name<<endl;
                            cout<<"size:"<<retorna.part_size<<endl;
                            cout<<"start:"<<retorna.part_start<<endl;
                            cout<<"status:"<<retorna.part_status<<endl;
                            cout<<"type:"<<retorna.part_type<<endl; */
                            //guarda el mbr en la primera posicion sin borrar lo demas
                            //abre el disco de nuevo para escribir el nuevo MBR
                            ofstream output_file(nomarchivo, ios::in);
                            long pos = output_file.tellp();
                            output_file.seekp(0);
                            output_file.write((char*)&tempoMBR, sizeof(tempoMBR));

                            if(info.type==2){
                                //cout<<"Entro en EBR LOGICA"<<endl;
                                ///Si la particion fuera extendida
                                ///pasa a escribir el ebr inicial en donde empieza la particion extendida
                                EBR nuev;
                                nuev.part_size=sizeof(nuev);

                                if(tempoMBR.particion1.part_type=='e'){
                                    nuev.part_start=tempoMBR.particion1.part_start;
                                    nuev.part_fit=tempoMBR.particion1.part_fit;
                                    output_file.seekp(tempoMBR.particion1.part_start+sizeof(MBR));
                                }else if(tempoMBR.particion2.part_type=='e'){
                                    nuev.part_start=tempoMBR.particion2.part_start;
                                    nuev.part_fit=tempoMBR.particion2.part_fit;
                                    output_file.seekp(tempoMBR.particion2.part_start+sizeof(MBR));
                                }else if(tempoMBR.particion3.part_type=='e'){
                                    nuev.part_start=tempoMBR.particion3.part_start;
                                    nuev.part_fit=tempoMBR.particion3.part_fit;
                                    output_file.seekp(tempoMBR.particion3.part_start+sizeof(MBR));
                                }else if(tempoMBR.particion4.part_type=='e'){
                                    nuev.part_start=tempoMBR.particion4.part_start;
                                    nuev.part_fit=tempoMBR.particion4.part_fit;
                                    output_file.seekp(tempoMBR.particion4.part_start+sizeof(MBR));
                                }else{
                                    cout<<"Error no existe la particion f"<<endl;
                                }
                                output_file.write((char*)&nuev, sizeof(nuev));
                            }

                            output_file.close();

                        }else{
                            cout<<"No hay un espacio libre lo suficiente grande como para alojar la particion"<<endl;
                            input_file.close();
                        }

                }else{
                    cout<<"El nombre de la particion esta repetido"<<endl;

                }



            }else{
                    cout<<"No hay suficiente espacio en el disco o maximo 4 particiones"<<endl;
                    input_file.close();
            }


         }




	}else{
        cout<<"El Disco no existe en la ruta solicitada o el nombre esta mal"<<endl;

	}


}




int PosNueva(MBR copia,int sizeP){
	//primero obtiene start particiones y las ordena
	int p1=copia.particion1.part_start;
	int p2=copia.particion2.part_start;
	int p3=copia.particion3.part_start;
	int p4=copia.particion4.part_start;

	int posicionx=-1;
/*
	cout<<"p1:"<<p1<<endl;
	cout<<"p2:"<<p2<<endl;
	cout<<"p3:"<<p3<<endl;
	cout<<"p4:"<<p4<<endl;*/
	if(!((p1==-1)&&(p2==-1)&&(p3==-1)&&(p4==-1))){
		//cout<<"hay mas de 1 particion"<<endl;
		char fitM=copia.disk_fit;//b f w
		vector<StartSize>starts;
		StartSize tt;

			if(p1!=-1){
				tt.start=p1;
				tt.size=copia.particion1.part_size;
				starts.push_back(tt);
			}
			if(p2!=-1){
				tt.start=p2;
				tt.size=copia.particion2.part_size;
				starts.push_back(tt);
			}
			if(p3!=-1){
				tt.start=p3;
				tt.size=copia.particion3.part_size;
				starts.push_back(tt);
			}if(p4!=-1){
				tt.start=p4;
				tt.size=copia.particion4.part_size;
				starts.push_back(tt);
			}
		//ordena los starts
		starts=sortArray(starts);

		//     |particionx|     |particiony|    |particionz|       |Final de disco
		vector<StartSize>libres;
		StartSize libreOpcion;
		int posicion=0;
		//cout<<"tamano starts*//////////////:"<<starts.size()<<endl;
		for(int i=0;i<starts.size();i++){
			StartSize tempo1=starts[i];
			/*cout<<"libre:"<<endl;
			cout<<"size:"<<tempo1.size<<endl;
			cout<<"start:"<<tempo1.start<<endl;*/

			int Slibre=tempo1.start-posicion;
				if(Slibre!=0){
					libreOpcion.size=Slibre;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
				}
			posicion=posicion+Slibre+tempo1.size;
		}

		int lib=copia.mbr_tamano-posicion;
		if(lib!=0){
			//cout<<"agrega parte final:"<<endl;
					libreOpcion.size=lib;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
            //cout<<libreOpcion.size<<endl;
            //cout<<libreOpcion.start<<endl;

		}

		//obtuvo los espacios libres ahora buscara el espacio dependiendo el fit
		StartSize lugarNuevo=PosParti(libres,copia.disk_fit,sizeP);
		posicionx=lugarNuevo.start;
		//cout<<"POSICION POSPORTI****************:"<<posicionx<<endl;
	}else{
		cout<<"no hay particiones posicion 0"<<endl;
		posicionx=0;
	}

	return posicionx;
}


vector<StartSize> sortArray(vector<StartSize> arra){

	vector<StartSize> array=arra;
	bool cambio=false;

	while(true){

		for(int i=0;i<array.size();i++){
			StartSize tempo=array[i];

			if(i!=(array.size()-1)){
			 	StartSize tempo2=array[i+1];
				 if(tempo.start>tempo2.start){
				 	array[i]=tempo2;
				 	array[i+1]=tempo;
				 	cambio=true;
				 }
			}
		}

		if(!cambio){
			break;
		}else{
			cambio=false;
		}

	}

	return array;
}



StartSize PosParti(vector<StartSize> espacios,char fitM,int sizeP){
	StartSize retorna;
    //cout<<"Fits:::"<<fitM<<endl;

    int can=espacios.size();
	for(int i=0;i<can;i++){
		StartSize tempo=espacios[i];
		/*cout<<"sizeLibre:"<<tempo.size<<endl;
		cout<<"startlibre:"<<tempo.start<<endl;
		cout<<"sizeCreara:"<<sizeP<<endl;*/

		if(fitM=='b'){
			if((retorna.size!=0)&&(tempo.size>=sizeP)){
				if(retorna.size>tempo.size){
					retorna=tempo;
				}
			}else if((retorna.size==0)&&(tempo.size>=sizeP)){
				retorna=tempo;
			}

		}else if(fitM=='f'){

			if(tempo.size>=sizeP){
					retorna=tempo;
					break;
            }

		}else if(fitM=='w'){
			if((retorna.size!=0)&&(tempo.size>=sizeP)){
				if(retorna.size<tempo.size){
					retorna=tempo;
				}
			}else if((retorna.size==0)&&(tempo.size>=sizeP)){
				retorna=tempo;
			}
		}

	}

	return retorna;
}










void ParticionLOGICA(int sizen,EBR newp,FDI info){
	//crea particion PRIMARIA
	//busca lugar libre de 4
	//calcula espacios libres
	//aplico fit y retorno posicion donde guardar
	//-1 si no hay lugar disponible
	//no importa si hay extendidas o logicas o primarias
	MBR tempoMBR;


	char *nomarchivo=RPfd(info.path);
	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	///validar que exita el archivo
	input_file.read((char*)&tempoMBR, sizeof(tempoMBR));

	EBR retorna=newp;

	int tamano=tempoMBR.mbr_tamano;
	cout<<"PARTICION LOGICA:"<<endl;
	cout<<"FIT:"<<tempoMBR.disk_fit<<endl;
	cout<<"codigo:"<<tempoMBR.mbr_disk_signature<<endl;
	cout<<"tamano:"<<tempoMBR.mbr_tamano <<endl;
	cout<<"nombre:"<<tempoMBR.particion1.part_name <<"  start:"<<tempoMBR.particion1.part_start <<"  size:"<<tempoMBR.particion1.part_size <<endl;
	cout<<"nombre:"<<tempoMBR.particion2.part_name <<"  start:"<<tempoMBR.particion2.part_start  <<"  size:"<<tempoMBR.particion2.part_size<<endl;
	cout<<"nombre:"<<tempoMBR.particion3.part_name <<"  start:"<<tempoMBR.particion3.part_start <<"  size:"<<tempoMBR.particion3.part_size<<endl;
	cout<<"nombre:"<<tempoMBR.particion4.part_name <<"  start:"<<tempoMBR.particion4.part_start <<"  size:"<<tempoMBR.particion4.part_size<<endl<<endl;


	//cout<<"busca extendida:"<<endl;
	bool extendida=(tempoMBR.particion1.part_type=='e')||(tempoMBR.particion2.part_type=='e')||(tempoMBR.particion3.part_type=='e')||(tempoMBR.particion4.part_type=='e');
	//cout<<"valida extendida:"<<endl;
	if(!extendida){//no hay particiones extendidas
	 	//cout<<"No hay ninguna particion extendida en el disco"<<endl;
	 	input_file.close();
	 }else{

	 	//obtiene particion extendida
	 	//cout<<"get particion:"<<endl;
	 	PARTITION extendida=getExtPartition(tempoMBR);
	 	//cout<<"comprueba tamano :"<<endl;
	 	//si el tamano no supera la extendida
	 	if(extendida.part_size>=sizen){
	 		//busca todos los ebr que halla
	 		//lista de ebr encontrados
	 		//cout<<"busca los ebrs:"<<endl;
	 		vector<EBR>leidos=ReadEBRs(input_file,extendida);
	 		//cout<<"tamebrs:"<<leidos.size()<<endl;
	 	//cout<<"valida nombres:"<<endl;
	 	//compara nombres repetidos///compara los nombres de cada particion existente con el nuevo a asingar
        bool nom1=Compare(tempoMBR.particion1.part_name,newp.part_name);
        bool nom2=Compare(tempoMBR.particion2.part_name,newp.part_name);
        bool nom3=Compare(tempoMBR.particion3.part_name,newp.part_name);
        bool nom4=Compare(tempoMBR.particion4.part_name,newp.part_name);
        bool nom5=validaNombres(leidos,newp.part_name);


		//los nombres no son iguales
			if(!(nom1|nom2|nom3|nom4|nom5)){
				//Retona la posicion dentro de la extendida a guardar
				//cout<<"Calcula posicion:"<<endl;
					int posicionD=PosNuevaLOGICA(leidos,sizen,extendida);
					//cout<<"posocion:"<<posicionD<<endl;
					//si encuentra una posicion adecuada asigna la posicion de inicio
					//y lo guarda

					if(posicionD!=-1){
						//retorna = EBR
						retorna.part_start=posicionD;

				 	input_file.close();

					//genera un ebr nuevo
					//tiene que enlazar con otro ebr  ||->|.|->||

					vector<EBR> pguardar=LinkpartitionEBR(retorna,leidos);
				 	/*cout<<"Particion logica FINAL"<<endl;
				 	cout<<"fit:"<<retorna.part_fit <<endl;
				 	cout<<"name:"<<retorna.part_name <<endl;
				 	cout<<"next:"<<retorna.part_next <<endl;
				 	cout<<"size:"<<retorna.part_size <<endl;
				 	cout<<"start:"<<retorna.part_start <<endl;
				 	cout<<"status:"<<retorna.part_status <<endl;
				 	cout<<"type:"<<retorna.part_type <<endl;*/
				 	int sumacero=sizeof(MBR);
					 			  //guarda el ebr en su posicion
								  ofstream output_file(nomarchivo, ios::in);
								  long pos = output_file.tellp();


								  for(int i=0;i<pguardar.size();i++){
								  	EBR ccopia=pguardar[i];
								  	/*cout<<"Particion logica Reescribe"<<endl;
								 	cout<<"fit:"<<ccopia.part_fit <<endl;
								 	cout<<"name:"<<ccopia.part_name <<endl;
								 	cout<<"next:"<<ccopia.part_next <<endl;
								 	cout<<"size:"<<ccopia.part_size <<endl;
								 	cout<<"start:"<<ccopia.part_start <<endl;
								 	cout<<"status:"<<ccopia.part_status <<endl;
								 	cout<<"type:"<<ccopia.part_type <<endl;
								  	cout<<endl<<endl;*/
								  	output_file.seekp(ccopia.part_start+sumacero);
								  	output_file.write((char*)&ccopia, sizeof(ccopia));
								  }

								  output_file.close();

					}else{
						cout<<"No hay un espacio libre lo suficiente grande como para alojar la particion"<<endl;
						input_file.close();
					}

			}else{
				cout<<"El nombre de la particion esta repetido"<<endl;
				input_file.close();

			}



		}else{
				cout<<"No hay suficiente espacio en la particion"<<endl;
				input_file.close();
		}


	 }





}






vector<EBR> LinkpartitionEBR(EBR nuevo,vector<EBR> ebrs){

	vector<EBR> finalebr=ebrs;
	//EN ELIMINACION
	//CONSERVAR PRIMER EBR (START Y NEXT)
	//		-------------       -------------
	//		|		    |       |           |
	//		|		    V	    |		    V
	//|ext|start|     |start|next|     |start|next|


	if(ebrs.size()!=0){
		//linkear posible ebrs
		//crea primer ebr (no se puede eliminar)
		for(int i=0;i<ebrs.size();i++){

			EBR tempo=ebrs[i];
			//el sacado es menor y el siguiente es mayor
			if((tempo.part_start<nuevo.part_start)&&(nuevo.part_start<tempo.part_next)){
				//caso en el que esta 1  2. 3
				//rehace los vinculos

				nuevo.part_next=tempo.part_next;
				tempo.part_next=nuevo.part_start;

				finalebr[i]=tempo;//actualiza el viejo con info nueva

				//guarda al medio
				//int itPos = finalebr.begin() + i+1;
				finalebr.insert((finalebr.begin() + i+1),nuevo);

			}else if((tempo.part_start<nuevo.part_start)&&(tempo.part_next==-1)){
				//caso en el que esta 1  2  3.
				//rehace los vinculos

				nuevo.part_next=-1;
				tempo.part_next=nuevo.part_start;

				finalebr[i]=tempo;//actualiza el viejo con info nueva
				//guarda al final
				finalebr.push_back(nuevo);

			}else if((tempo.part_start>nuevo.part_start)&&(i==0)){
				//caso en el que esta 1.  2  3
				//rehace los vinculos

				//nuevo.part_next=tempo.part_next;
				//guarda al inicio , no actualiza nada
				//auto itPos = finalebr.begin();
				 //finalebr.insert(finalebr.begin(),nuevo);
			}else if((tempo.part_start==nuevo.part_start)&&(i==0)){
				//caso en el que esta 1.  2  3
				//rehace los vinculos

				//nuevo.part_next=tempo.part_next;
				//tempo.part_next=nuevo.part_start;
				//guarda al inicio , no actualiza nada
				//auto itPos = finalebr.begin();
				 //finalebr.insert(finalebr.begin(),nuevo);
			}

		}



	}else{
		//solo escribir ebr
		nuevo.part_next=-1;
		finalebr.push_back(nuevo);
	}


	return finalebr;
}



//Busca la nueva posicion para una particion logica
int PosNuevaLOGICA(vector<EBR> starts,int sizeP,PARTITION part){
	//obtiene los espacios y sus starts
	//luego calcula la posicion segun el fit
		//     |particionx|     |particiony|    |particionz|       |Final de disco
		int posicionx=-1;
		vector<StartSize>libres;
		StartSize libreOpcion;
		int posicion=part.part_start;//empieza donde empiece la extendida
		//cout<<"tamano starts*//////////////:"<<starts.size()<<endl;
		for(int i=0;i<starts.size();i++){
			EBR tempo1=starts[i];
			/*cout<<"libre:"<<endl;
			cout<<"size:"<<tempo1.part_size<<endl;
			cout<<"start:"<<tempo1.part_start<<endl;*/

			int Slibre=tempo1.part_start-posicion;
				if(Slibre!=0){
					libreOpcion.size=Slibre;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
				}
			posicion=posicion+Slibre+tempo1.part_size;
		}
		//tamano extendida-posicion
		int lib=(part.part_size+part.part_start)-posicion;
		if(lib!=0){
			//cout<<"agrega parte final:"<<lib<<endl;
			//cout<<"agrega parte poscion:"<<posicion<<endl;
					libreOpcion.size=lib;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
		}

		//obtuvo los espacios libres ahora buscara el espacio dependiendo el fit
		StartSize lugarNuevo=PosParti(libres,part.part_fit,sizeP);
		posicionx=lugarNuevo.start;
		//cout<<"POSICION POSPORTI****************:"<<posicionx<<endl;


	return posicionx;
}














//Valida que vengan los comandos minimos para FDISK
bool MinFD(int tipo,FDI info){


	bool regresa=false;

	if(tipo==1){//add
		if((info.path!=0)&&(info.name!=0)&&(info.add!=0)){
			regresa=true;
		}
	}else if(tipo==2){//elimina
		if((info.path!=0)&&(info.name!=0)&&(info.delet!=0)){
			regresa=true;
		}
	}else if(tipo==3){//crea
		if((info.path!=0)&&(info.name!=0)&&(info.size!=0)){
			regresa=true;
		}

	}
	return regresa;

}




void EliminaParticion(FDI info){

    //Nombre Particion
    //Ruta disco
    //tipo de formateo
    //fast=1 , full=2
    char *nombre=RPfd(info.name);
    int forma=info.delet;

    MBR tempoMBR;


	char *nomarchivo=RPfd(info.path);
	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	if(input_file){


        ///validar que exista el archivo
        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
        ///compara los nombres de cada particion existente con el nuevo a asingar
        bool nom1=Compare(tempoMBR.particion1.part_name,info.name);
        bool nom2=Compare(tempoMBR.particion2.part_name,info.name);
        bool nom3=Compare(tempoMBR.particion3.part_name,info.name);
        bool nom4=Compare(tempoMBR.particion4.part_name,info.name);
        bool nom5=false;

        ///Sirve para hacer busqueda nombre de Logicas
        bool ind1=(tempoMBR.particion1.part_type=='e');
        bool ind2=(tempoMBR.particion2.part_type=='e');
        bool ind3=(tempoMBR.particion3.part_type=='e');
        bool ind4=(tempoMBR.particion4.part_type=='e');

        ///Puestos fuera para ser accedidos globalmente
        PARTITION extendida;
        vector<EBR>leidos;
        //valida que exista la particion extendida
        if(ind1||ind2||ind3||ind4){

        //seleccion la particion extendida
            extendida=getExtPartition(tempoMBR);
            //lista de ebr encontrados
            leidos=ReadEBRs(input_file,extendida);
            //cout<<"tamebrs:"<<leidos.size()<<endl;
            nom5=validaNombres(leidos,info.name);
        }
        //cierra el documento
        input_file.close();


        if((nom1|nom2|nom3|nom4)){
            cout<<"Existe la particion PRINCIPALES inicia para eliminar"<<endl;
            PARTITION temp;
            PARTITION limpia;
            if(nom1){
                //cout<<"Primera"<<endl;
                temp=tempoMBR.particion1;
                tempoMBR.particion1=limpia;
            }else if(nom2){
                //cout<<"Segunda"<<endl;
                temp=tempoMBR.particion2;
                tempoMBR.particion2=limpia;
            }else if(nom3){
                //cout<<"Tercera"<<endl;
                temp=tempoMBR.particion3;
                tempoMBR.particion3=limpia;
            }else if(nom4){
                //cout<<"Cuarta"<<endl;
                temp=tempoMBR.particion4;
                tempoMBR.particion4=limpia;
            }else{
                //ERROR EN LOS BOOLEANOS DE NOMBRE,NO TOMAR EN CUENTA
            }


            //cout<<"tipo:"<<temp.part_type<<endl;
            //cout<<"forma:"<< forma<<endl;

            ///ver si no elimino el primer ebr
            if((temp.part_type=='e')&&(forma==1)){
                //FORMATEO PARTICION EXTENDIDA , TIPO FAST
                FormateaParticion(temp.part_start,temp.part_size,nomarchivo,tempoMBR,1);
            }else if((temp.part_type=='p')&&(forma==1)){
                //FORMATEO PARTICION PRIMARIA , TIPO FAST
                FormateaParticion(temp.part_start,temp.part_size,nomarchivo,tempoMBR,1);
            }else if((temp.part_type=='e')&&(forma==2)){
                //FORMATEO PARTICION EXTENDIDA , TIPO FULL
                FormateaParticion(temp.part_start,temp.part_size,nomarchivo,tempoMBR,2);
            }else if((temp.part_type=='p')&&(forma==2)){
                //FORMATEO PARTICION EXTENDIDA , TIPO FULL
                FormateaParticion(temp.part_start,temp.part_size,nomarchivo,tempoMBR,2);
            }else{
                //el tipo de particion esta malo
                cout<<"El tipo de particion es incorrecto"<<endl;
            }


        }else if(nom5){
            cout<<"Existe la particion LOGICAS inicia para eliminar"<<endl;
            //selecciona el tipo de formateo de las particiones logicas
            ///selecciona el ebr a eliminar y lo elimina de la lista
            vector<EBR> nuevaLista=EliminaEBR(info.name,leidos);

            if((forma==1)){
                //FORMATEO PARTICION LOGICA , TIPO FAST
                ActualizaLogicas(nuevaLista,nomarchivo,tempoMBR);


            }else if((forma==2)){
                //FORMATEO PARTICION LOGICA , TIPO FULL
                FormateaParticion(extendida.part_start,extendida.part_size,nomarchivo,tempoMBR,2);
                ActualizaLogicas(nuevaLista,nomarchivo,tempoMBR);

            }

        }else{
            cout<<"La particion No existe en el disco duro"<<endl;
        }






        }


}




bool FormateaParticion(int inicio,int size,char*nombre,MBR nuevo,int formateo){

        cout<<"Inicio:"<<inicio<<endl;
        cout<<"Size:"<<size<<endl;
        cout<<"Ruta Disco Eliminar:"<<nombre<<endl;
        cout<<"Parti1:"<<nuevo.particion1.part_name<<endl;
        cout<<"Parti2:"<<nuevo.particion2.part_name<<endl;
        cout<<"Parti3:"<<nuevo.particion3.part_name<<endl;
        cout<<"Parti4:"<<nuevo.particion4.part_name<<endl;

        // -MBR|0 --------->  x|
		// |MBR|               |


		char* nombarc=RPfd(nombre);

	 	ofstream output_file(nombarc, ios::in);


        if(formateo==1){
            //FAST

        }else if(formateo==2){
            //FULL
                //el cero empieza despues del mbr para las particiones logicas
                int celdas=size;
                //cout<<celdas<<endl;
                //disco mayor a 1mb
                int tamanolimite=1048576;

                output_file.seekp(inicio+sizeof(MBR));
                if(celdas>tamanolimite){
                    //cout<<"MAYOR 1MB"<<endl;
                    while(true){

                        if(celdas>tamanolimite){
                            char escribe[tamanolimite]={0};
                            output_file.write((char*)&escribe, sizeof(escribe));
                            celdas=celdas-tamanolimite;
                        }else{
                            char escribe[celdas]={0};
                            output_file.write((char*)&escribe, sizeof(escribe));
                            celdas=celdas-celdas;
                            break;
                        }

                    }

                 }else{
                    //cout<<"menor o igual 1MB"<<endl;
                    char escribe[celdas]={0};
                    output_file.write((char*)&escribe, sizeof(escribe));
                 }


        }else{
            cout<<"Tipo de formateo desconocido"<<endl;
        }





          //Escribe el MBR
		  output_file.seekp (0);
		  output_file.write((char*)&nuevo, sizeof(nuevo));


		output_file.close();



}











vector<EBR> EliminaEBR(char* nombre,vector<EBR> ebrs){

	vector<EBR> finalebr=ebrs;
	//EN ELIMINACION
	//CONSERVAR PRIMER EBR (START Y NEXT)
	//		-------------       -------------
	//		|		    |       |           |
	//		|		    V	    |		    V
	//|ext|start|     |start|next|     |start|next|


	if(ebrs.size()!=0){
		//linkear posible ebrs
		//crea primer ebr (no se puede eliminar)
		int size_eb=ebrs.size();
		for(int i=0;i<size_eb;i++){

			EBR tempo=ebrs[i];
            char * nom=ArrtoCharP(tempo.part_name);

            cout<<tempo.part_fit<<endl;
            cout<<tempo.part_name<<endl;
            cout<<tempo.part_next<<endl;
            cout<<tempo.part_size<<endl;
            cout<<tempo.part_start<<endl;
            cout<<tempo.part_status<<endl;
            cout<<tempo.part_type<<endl;
            cout<<endl<<endl;
            EBR eliminar;
			if(Compare(nom,nombre)){


                eliminar=tempo;
                EBR vacio;
                if(i==(size_eb-1)){
                    ///Elimina al final
                    ///cambia el apuntador anterior
                    (finalebr[i-1]).part_next=-1;
                    (finalebr[i])=vacio;
                }else{
                    ///La posicion esta en medio de dos nodos
                    ///apunta el anterior al primero
                    (finalebr[i-1]).part_next=(finalebr[i]).part_next;
                    ///vacia el contenido del ebr a eliminar

                    (finalebr[i])=vacio;
                }



                ///como lo encontro se sale del ciclo
                break;
			}

		}



	}


	return finalebr;
}





void ActualizaLogicas(vector<EBR> pguardar,char * nomarchivo,MBR copia){

        int sumacero=sizeof(MBR);
        //guarda el ebr en su posicion
        ofstream output_file(nomarchivo, ios::in);
        long pos = output_file.tellp();


        for(int i=0;i<pguardar.size();i++){
            EBR ccopia=pguardar[i];
            cout<<"Particion logica Reescribe"<<endl;
            cout<<"fit:"<<ccopia.part_fit <<endl;
            cout<<"name:"<<ccopia.part_name <<endl;
            cout<<"next:"<<ccopia.part_next <<endl;
            cout<<"size:"<<ccopia.part_size <<endl;
            cout<<"start:"<<ccopia.part_start <<endl;
            cout<<"status:"<<ccopia.part_status <<endl;
            cout<<"type:"<<ccopia.part_type <<endl;
            cout<<endl<<endl;/**/
            ///Porque cuando queda en medio borro contenido ebr pero lo deja ahi , entonces part_start=-1
            if(ccopia.part_start!=-1){
                output_file.seekp(ccopia.part_start+sumacero);
                output_file.write((char*)&ccopia, sizeof(ccopia));
            }

        }

        //Escribe el MBR
        MBR cop=copia;
        output_file.seekp (0);
        output_file.write((char*)&cop, sizeof(cop));

        output_file.close();



}




void ModificaParticion(FDI info){


    /** Nota:

    Verificar que si al agregar espacio afecta al sistema de archivos
    Verificar que si al quitar esapcio afecta tambien sistema de archivos

       **/




    //Nombre Particion
    //Ruta disco
    //tipo de formateo
    //fast=1 , full=2
    char *nombre=RPfd(info.name);
    ///Tamano a agregar o quitar
    int modificacion=(info.add*(pow(1024,(double)(info.unit-1))));

    MBR tempoMBR;


	char *nomarchivo=RPfd(info.path);
	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	if(input_file){


        ///validar que exista el archivo
        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
        ///compara los nombres de cada particion existente con el nuevo a asingar
        bool nom1=Compare(tempoMBR.particion1.part_name,info.name);
        bool nom2=Compare(tempoMBR.particion2.part_name,info.name);
        bool nom3=Compare(tempoMBR.particion3.part_name,info.name);
        bool nom4=Compare(tempoMBR.particion4.part_name,info.name);
        bool nom5=false;
        ///Sirve para hacer busqueda nombre de Logicas
        bool ind1=(tempoMBR.particion1.part_type=='e');
        bool ind2=(tempoMBR.particion2.part_type=='e');
        bool ind3=(tempoMBR.particion3.part_type=='e');
        bool ind4=(tempoMBR.particion4.part_type=='e');
        ///Puestos fuera para ser accedidos globalmente
        PARTITION extendida;
        vector<EBR>leidos;

        //valida que exista la particion extendida
        if(ind1||ind2||ind3||ind4){

        //seleccion la particion extendida
            extendida=getExtPartition(tempoMBR);
            //lista de ebr encontrados
            leidos=ReadEBRs(input_file,extendida);
            //cout<<"tamebrs:"<<leidos.size()<<endl;
            nom5=validaNombres(leidos,info.name);
        }
        //cierra el documento
        input_file.close();





        ///Primeras dos validaciones , solo con relacion al disco NO a particiones
        ///tamano de la Adicion es mayor al disco Positivo
        int VTam_DP= !((modificacion)>tempoMBR.mbr_tamano);
        ///tamno de la Adicion no negativo
        int VTam_DN= !((modificacion+tempoMBR.mbr_tamano)<0);


        ///VERIFICAR QUE LA PARTICION NO TENGA SISTEMA DE ARCHIVOS


        ///Verifica que exista la particion
        if((nom1|nom2|nom3|nom4)){
            cout<<"Existe la particion PRINCIPALES ,modificara..."<<endl;
        ///valida    | Disco |
        /// VTamDN X  <---->  VTamDP X
            if(VTam_DN&&VTam_DP){
                ///Determina cual es la particion a modificar y la guarda en modis
                PARTITION modis;
                if(nom1){
                    modis=tempoMBR.particion1;
                }else if(nom2){
                    modis=tempoMBR.particion2;
                }else if(nom3){
                    modis=tempoMBR.particion3;
                }else if(nom4){
                    modis=tempoMBR.particion4;
                }else{

                }



                ///tamano positivo o negativo

                if(modificacion>0){
                ///Se agregara espacio + "CRECE"
                ///calcula espacios
                vector<StartSize> dosEspa = EspaModi(tempoMBR,modis.part_size,modis.part_start);
                ///retorna dos espacios uno frente y otro trasero, vacio ambos si no hay
                bool exi1= (dosEspa[0].size)!=0; ///crece hacia atras
                bool exi2= (dosEspa[1].size)!=0;///crece hacia adelante
                    ///valida no exista primer espacio , segundo si , y tamano mayor o igual al que quiere agregar
                    if(((!exi1)&&(exi2))&&(dosEspa[1].size>=modificacion)){
                        ///Agrega hacia adelante |     |-->|
                        ///EN ESTA PARTE SE MODIFICA EL ESPACIO DE LA PARTICION , Y TAMBIEN SI SE TIENE QUE
                        ///MOVER EL SISTEMA DE ARCHIVOS , PARTICION EXTENDIDA PARTICIONES Y NORMAL SISTEMA DE ARCHIVOS
                        modis.part_size=(modis.part_size+modificacion);

                        if(modis.part_type=='e'){
                        ///si es una particion extendida, corre las particiones logicas hacia atras

                        }else{
                        ///si es una particion primaria, corre el sistema de archivos

                        }


                    }else if(((exi1)&&(!exi2))&&(dosEspa[0].size>=modificacion)){
                        ///Agrega hacia atras   | <--|     |
                        ///EN ESTA PARTE SE MODIFICA EL ESPACIO DE LA PARTICION , Y TAMBIEN SI SE TIENE QUE
                        ///MOVER EL SISTEMA DE ARCHIVOS , PARTICION EXTENDIDA PARTICIONES Y NORMAL SISTEMA DE ARCHIVOS
                        modis.part_size=(modis.part_size+modificacion);
                        modis.part_start=modis.part_start-modificacion;

                        if(modis.part_type=='e'){
                        ///si es una particion extendida, corre las particiones logicas hacia atras
                            leidos=ExtMovPLogAtras(leidos,modis.part_start);
                        }else{
                        ///si es una particion primaria, corre el sistema de archivos

                        }


                    }else if(((exi1)&&(exi2))&&((dosEspa[0].size+dosEspa[1].size)>=modificacion)){
                        ///Agrega hacia adelante y hacia atras   | <--|     | -->|
                        ///EN ESTA PARTE SE MODIFICA EL ESPACIO DE LA PARTICION , Y TAMBIEN SI SE TIENE QUE
                        ///MOVER EL SISTEMA DE ARCHIVOS , PARTICION EXTENDIDA PARTICIONES Y NORMAL SISTEMA DE ARCHIVOS
                        modis.part_size=(modis.part_size+modificacion);
                        //se mueve para adelante y luego retrocede
                        if(dosEspa[1].size>=modificacion){
                            ///Crece hacia adelante nada mas no mueve el inicio
                        }else{
                            modis.part_start=modis.part_start-(modificacion-dosEspa[1].size);
                        }


                        if(modis.part_type=='e'){
                        ///si es una particion extendida, corre las particiones logicas hacia atras
                            leidos=ExtMovPLogAtras(leidos,modis.part_start);
                        }else{
                        ///si es una particion primaria, corre el sistema de archivos

                        }

                    }else{
                        cout<<"No existe suficiente espacio contiguo para poder aumentar la particion "<<endl;
                    }



                    ///Luego de hacer los cambios pasa a guardar la particion en el MBR
                    if(nom1){
                        tempoMBR.particion1=modis;
                    }else if(nom2){
                        tempoMBR.particion2=modis;
                    }else if(nom3){
                        tempoMBR.particion3=modis;
                    }else if(nom4){
                        tempoMBR.particion4=modis;
                    }else{

                    }

                    ///si fuera extendida las particiones logicas estan actualizadas en "leidos"

                    ///pasa a escribir MBR Y (SISTEMA ARCHIVOS , O LOGICAS)

                }else{
                    ///Se quitara espacio -  "ACHIQUITA"
                    ///valor en Bytes
                    int valor_minimo=100;
                    int op=(modis.part_size+modificacion);
                    cout<<op<<endl<<endl;
                    ///valor minimo temporal =100bytes
                    if((op)>=valor_minimo){
                        if(modis.part_type=='e'){
                            ///si es particion Extendida determinar ultima particion logica y ver que no quede dentro
                            int tam=leidos.size()-1;
                            ///Final Particion Logica
                            int FPLog=((leidos[tam].part_start)+(leidos[tam].part_size));
                            ///Final Particion Extendida
                            int FPExt=(modis.part_start)+(modis.part_size);

                            if((FPExt+modificacion)>=FPLog){
                                modis.part_size=modis.part_size+modificacion;

                            }else{
                                ///El espacio lo esta usando una particion logica
                                cout<<"El espacio a eliminar esta en uso en la particion Extendida"<<endl;
                            }

                        }else{
                            ///si es una particion primaria, verificar que quede un pequeno espacio
                            modis.part_size=modis.part_size+modificacion;

                        }

                        ///Luego de hacer los cambios pasa a guardar la particion en el MBR
                        if(nom1){
                            tempoMBR.particion1=modis;
                        }else if(nom2){
                            tempoMBR.particion2=modis;
                        }else if(nom3){
                            tempoMBR.particion3=modis;
                        }else if(nom4){
                            tempoMBR.particion4=modis;
                        }else{

                        }

                    }else{
                        ///el valor de la particion no puede ser menor a

                        cout<<"El valor minimo de la particion no puede ser menor a: (Bytes)"<<valor_minimo<<endl;


                    }



                }


            ActualizaLogicas(leidos,nomarchivo,tempoMBR);


            }else{
                cout<<"Las dimensiones de la modificacion estan Fuera del Tamano del disco"<<endl;
            }//fin valida VTAM DN Y DP

        }else if(nom5){
                ///INICIA modficacion particion Logica
                cout<<"Existe la particion LOGICAS inicia ,modificar"<<endl;

            if(VTam_DN&&VTam_DP){


                EBR mod;
                int posi=-1;

                ///Localiza la particion logica y su posicin para modificar
                for(int i=0;i<leidos.size();i++){
                    EBR temp=leidos[i];
                    char * nomT=ArrtoCharP(temp.part_name);
                    char * nomB=ArrtoCharP(info.name);

                    if(Compare(nomT,nomB)){
                        mod=temp;
                        posi=i;
                        break;
                    }
                }


                ///Identifica posicion de la particion
                if(modificacion>0){
                    ///La particion Logica CRECE +
                    vector<StartSize> espacios=EspaModiLogi(leidos,extendida,mod.part_size, mod.part_start);
                    bool exi1= (espacios[0].size)!=0; ///crece hacia atras
                    bool exi2= (espacios[1].size)!=0;///crece hacia adelante

                    if(((!exi1)&&(exi2))&&(espacios[1].size>=modificacion)){
                        ///Crece hacia adelante
                        mod.part_size=mod.part_size+modificacion;
                    }else if(((exi1)&&(!exi2))&&(espacios[0].size>=modificacion)){
                        ///Crece hacia atras
                        mod.part_size=mod.part_size+modificacion;
                        mod.part_start=mod.part_start-modificacion;

                        ///modifica el link particion anterior
                        (leidos[posi-1]).part_next=mod.part_start;

                    }else if(((exi1)&&(exi2))&&((espacios[0].size+espacios[1].size)>=modificacion)){

                        if(espacios[1].size>=modificacion){
                            ///Crece hacia adelante nada mas no mueve el inicio
                            mod.part_size=mod.part_size+modificacion;
                        }else{
                            ///Crece hacia adelante y luego hacia atras
                            mod.part_size=mod.part_size+modificacion;
                            mod.part_start=mod.part_start-(modificacion-espacios[1].size);

                            ///modifica el link particion anterior
                            (leidos[posi-1]).part_next=mod.part_start;
                        }

                    }else{
                        cout<<"No existe suficiente espacio contiguo para poder aumentar la particion "<<endl;
                    }


                }else{
                    ///La particion Logica ACHIQUITA -
                    ///valor en Bytes
                    int valor_minimo=100;
                    int op=(mod.part_size+modificacion);
                    cout<<op<<endl<<endl;
                    ///valor minimo temporal =100bytes
                    if((op)>=valor_minimo){
                        mod.part_size=mod.part_size+modificacion;
                    }else{
                        ///el valor de la particion no puede ser menor a
                        cout<<"El valor minimo de la particion no puede ser menor a: (Bytes)"<<valor_minimo<<endl;
                    }

                }

            ///Actualiza la particion
            (leidos[posi])=mod;
            ActualizaLogicas(leidos,nomarchivo,tempoMBR);


            }else{
                cout<<"Las dimensiones de la modificacion estan Fuera del Tamano del disco"<<endl;
            }





        }else{
            cout<<"La particion No existe en el disco duro"<<endl;
        }


    }


}




vector<StartSize> EspaModi(MBR copia,int sizeP,int start){
	//primero obtiene start particiones y las ordena
	int p1=copia.particion1.part_start;
	int p2=copia.particion2.part_start;
	int p3=copia.particion3.part_start;
	int p4=copia.particion4.part_start;


/*
	cout<<"p1:"<<p1<<endl;
	cout<<"p2:"<<p2<<endl;
	cout<<"p3:"<<p3<<endl;
	cout<<"p4:"<<p4<<endl;*/
    StartSize vacio;
	vector<StartSize>retorna;
	retorna.push_back(vacio);
	retorna.push_back(vacio);


	if(!((p1==-1)&&(p2==-1)&&(p3==-1)&&(p4==-1))){
		vector<StartSize>starts;
		StartSize tt;

			if(p1!=-1){
				tt.start=p1;
				tt.size=copia.particion1.part_size;
				starts.push_back(tt);
			}
			if(p2!=-1){
				tt.start=p2;
				tt.size=copia.particion2.part_size;
				starts.push_back(tt);
			}
			if(p3!=-1){
				tt.start=p3;
				tt.size=copia.particion3.part_size;
				starts.push_back(tt);
			}if(p4!=-1){
				tt.start=p4;
				tt.size=copia.particion4.part_size;
				starts.push_back(tt);
			}
		//ordena los starts
		starts=sortArray(starts);



		//     |particionx|     |particiony|    |particionz|       |Final de disco
		vector<StartSize>libres;
		StartSize libreOpcion;
		int posicion=0;
		//cout<<"tamano starts*//////////////:"<<starts.size()<<endl;
		for(int i=0;i<starts.size();i++){
			StartSize tempo1=starts[i];
			/*cout<<"libre:"<<endl;
			cout<<"size:"<<tempo1.size<<endl;
			cout<<"start:"<<tempo1.start<<endl;*/

			int Slibre=tempo1.start-posicion;
				if(Slibre!=0){
					libreOpcion.size=Slibre;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
				}
			posicion=posicion+Slibre+tempo1.size;
		}

		int lib=copia.mbr_tamano-posicion;
		if(lib!=0){
			//cout<<"agrega parte final:"<<endl;
					libreOpcion.size=lib;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
            //cout<<libreOpcion.size<<endl;
            //cout<<libreOpcion.start<<endl;

		}





        ///Busca los dos posibles espacios DELANTE O TRASERO

        for(int i=0;i<libres.size();i++){
            StartSize tempo=libres[i];

            if(((tempo.start+tempo.size)==start)){
            ///si esta antes de la particion
                retorna[0]=tempo;
            }else if(((tempo.start)==(start+sizeP))){
            ///esta despues de la partcion
                retorna[1]=tempo;
            }
        }






	}else{
		cout<<"no hay particiones posicion 0"<<endl;

	}

	return retorna;
}



vector<EBR> ExtMovPLogAtras(vector<EBR> particiones,int startNuevo){

    vector<EBR> regresa=particiones;

    ///calcula diferencia a retroceder
    int dif=(particiones[0].part_start)-startNuevo;

    for(int i=0;i<particiones.size();i++){
        EBR tempo=particiones[i];
        tempo.part_start=tempo.part_start-dif;
        regresa[i]=tempo;
    }


    return regresa;
}





vector<StartSize> EspaModiLogi(vector<EBR> starts,PARTITION part,int sizeP, int start){
	//obtiene los espacios y sus starts
	//luego calcula la posicion segun el fit
		//     |particionx|     |particiony|    |particionz|       |Final de disco

		vector<StartSize>libres;



		StartSize libreOpcion;
		int posicion=part.part_start;//empieza donde empiece la extendida
		//cout<<"tamano starts*//////////////:"<<starts.size()<<endl;
		for(int i=0;i<starts.size();i++){
			EBR tempo1=starts[i];
			/*cout<<"libre:"<<endl;
			cout<<"size:"<<tempo1.part_size<<endl;
			cout<<"start:"<<tempo1.part_start<<endl;*/

			int Slibre=tempo1.part_start-posicion;
				if(Slibre!=0){
					libreOpcion.size=Slibre;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
				}
			posicion=posicion+Slibre+tempo1.part_size;
		}
		//tamano extendida-posicion
		int lib=(part.part_size+part.part_start)-posicion;
		if(lib!=0){
			//cout<<"agrega parte final:"<<lib<<endl;
			//cout<<"agrega parte poscion:"<<posicion<<endl;
					libreOpcion.size=lib;
					libreOpcion.start=posicion;
					libres.push_back(libreOpcion);
		}


        StartSize vacio;
        vector<StartSize>retorna;
        retorna.push_back(vacio);
        retorna.push_back(vacio);


        for(int i=0;i<libres.size();i++){
            StartSize temp=libres[i];
            int prim= (temp.start+temp.size);

            if(prim==start){
                retorna[0]=temp;
            }else if((start+sizeP)==temp.start){
                retorna[1]=temp;
            }
        }





	return retorna;
}




void PrintSistemaParticiones(char *nombreDisco){


    MBR tempoMBR;

	ifstream input_file(nombreDisco, ios::binary);
	//Obtiene el MBR
	if(input_file){

        ///validar que exista el archivo
        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));

        PARTITION extendida;
        vector<EBR>leidos;
        ///Sirve para hacer busqueda nombre de Logicas
        bool ind1=(tempoMBR.particion1.part_type=='e');
        bool ind2=(tempoMBR.particion2.part_type=='e');
        bool ind3=(tempoMBR.particion3.part_type=='e');
        bool ind4=(tempoMBR.particion4.part_type=='e');
        //valida que exista la particion extendida
        if(ind1||ind2||ind3||ind4){

        //seleccion la particion extendida
            extendida=getExtPartition(tempoMBR);
            //lista de ebr encontrados
            leidos=ReadEBRs(input_file,extendida);

        }
        //cierra el documento
        input_file.close();

        cout<<"MBR:"<<endl;
        cout<<"FIT "<<tempoMBR.disk_fit<<endl;
        cout<<"SIGNATURE "<<tempoMBR.mbr_disk_signature<<endl;
        cout<<"CREACION "<<tempoMBR.mbr_fecha_creacion<<endl;
        cout<<"TAMANO "<<tempoMBR.mbr_tamano<<endl;

        cout<<"CASILLA 1:"<<endl;
        cout<<"FIT "<<tempoMBR.particion1.part_fit<<endl;
        cout<<"NAME "<<tempoMBR.particion1.part_name<<endl;
        cout<<"SIZE "<<tempoMBR.particion1.part_size<<endl;
        cout<<"START "<<tempoMBR.particion1.part_start<<endl;
        cout<<"STATUS "<<tempoMBR.particion1.part_status<<endl;
        cout<<"TYPE "<<tempoMBR.particion1.part_type<<endl<<endl;

        cout<<"CASILLA 2:"<<endl;
        cout<<"FIT "<<tempoMBR.particion2.part_fit<<endl;
        cout<<"NAME "<<tempoMBR.particion2.part_name<<endl;
        cout<<"SIZE "<<tempoMBR.particion2.part_size<<endl;
        cout<<"START "<<tempoMBR.particion2.part_start<<endl;
        cout<<"STATUS "<<tempoMBR.particion2.part_status<<endl;
        cout<<"TYPE "<<tempoMBR.particion2.part_type<<endl<<endl;


        cout<<"CASILLA 3:"<<endl;
        cout<<"FIT "<<tempoMBR.particion3.part_fit<<endl;
        cout<<"NAME "<<tempoMBR.particion3.part_name<<endl;
        cout<<"SIZE "<<tempoMBR.particion3.part_size<<endl;
        cout<<"START "<<tempoMBR.particion3.part_start<<endl;
        cout<<"STATUS "<<tempoMBR.particion3.part_status<<endl;
        cout<<"TYPE "<<tempoMBR.particion3.part_type<<endl<<endl;


        cout<<"CASILLA 4:"<<endl;
        cout<<"FIT "<<tempoMBR.particion4.part_fit<<endl;
        cout<<"NAME "<<tempoMBR.particion4.part_name<<endl;
        cout<<"SIZE "<<tempoMBR.particion4.part_size<<endl;
        cout<<"START "<<tempoMBR.particion4.part_start<<endl;
        cout<<"STATUS "<<tempoMBR.particion4.part_status<<endl;
        cout<<"TYPE "<<tempoMBR.particion4.part_type<<endl<<endl;

        for(int i =0;i<leidos.size();i++){
            EBR tempo=leidos[i];
            cout<<"LOGICA"<<i<<endl;
            cout<<"FIT "<<tempo.part_fit<<endl;
            cout<<"NAME "<<tempo.part_name<<endl;
            cout<<"NEXT "<<tempo.part_next<<endl;
            cout<<"SIZE "<<tempo.part_size<<endl;
            cout<<"START "<<tempo.part_start<<endl;
            cout<<"STATUS "<<tempo.part_status<<endl;
            cout<<"TYPE "<<tempo.part_type<<endl<<endl;

        }

    }
}








vector<StartSize> ListEspLibrPrimaria(MBR copia){
	//primero obtiene start particiones y las ordena
	int p1=copia.particion1.part_start;
	int p2=copia.particion2.part_start;
	int p3=copia.particion3.part_start;
	int p4=copia.particion4.part_start;

	vector<StartSize>retorna;

	if(!((p1==-1)&&(p2==-1)&&(p3==-1)&&(p4==-1))){
		vector<StartSize>starts;
		StartSize tt;

			if(p1!=-1){
				tt.start=p1;
				tt.size=copia.particion1.part_size;
				tt.posi=1;
				tt.type=copia.particion1.part_type;
				starts.push_back(tt);
			}
			if(p2!=-1){
				tt.start=p2;
				tt.size=copia.particion2.part_size;
				tt.posi=2;
				tt.type=copia.particion2.part_type;
				starts.push_back(tt);
			}
			if(p3!=-1){
				tt.start=p3;
				tt.size=copia.particion3.part_size;
				tt.posi=3;
				tt.type=copia.particion3.part_type;
				starts.push_back(tt);
			}if(p4!=-1){
				tt.start=p4;
				tt.size=copia.particion4.part_size;
				tt.posi=4;
				tt.type=copia.particion4.part_type;
				starts.push_back(tt);
			}
		//ordena los starts
		starts=sortArray(starts);



        retorna=starts;

	}else{
		cout<<"no hay particiones posicion 0"<<endl;

	}

	return retorna;
}






