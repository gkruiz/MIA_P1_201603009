
/*
   // current date/time based on current system
   time_t now = time(0);

   cout << "Number of sec since January 1,1970:" << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year" << 1900 + ltm->tm_year << endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<<  ltm->tm_mday << endl;
   cout << "Time: "<< 1 + ltm->tm_hour << ":";
   cout << 1 + ltm->tm_min << ":";
   cout << 1 + ltm->tm_sec << endl;

*/


bool DiskExiParti(char* nomarchivo,char*nomParticion);


void MKcrea(MKD info){
		// -MBR|0 --------->  x|
		// |MBR|               |

		char* nombarc=RPfd(info.path);//obtenerlo de la ruta
        cout<<nombarc<<endl;
	 	ofstream output_file(nombarc, ios::binary);

	 	if(output_file){
            //tamano a crear mas el tamano del mbr
            //el cero empieza despues del mbr para las particiones logicas
            ///suma un ebr, para hacer ajuste en la particion extendida sino hace falta un pequeno espacio
            int celdas=(info.size*(pow(1024,(double)info.unit)))+(sizeof(MBR))+(sizeof(EBR));
            //cout<<celdas<<endl;
            //disco mayor a 1mb
            int tamanolimite=1048576;

                //struct con fecha de creacion
                time_t now = time(0);
                tm *ltm = localtime(&now);

                //Numero random verificar
                int randomN;
                srand (time(NULL));
                randomN = rand() % 100000;
                randomN=randomN-((randomN*(ltm->tm_sec+(ltm->tm_sec*0.2))/100)+rand() % 5000);
            if(randomN<0){
                randomN=randomN*(-1);
            }
            MBR nue;
            nue.mbr_tamano=celdas;
            nue.mbr_fecha_creacion=now;
            nue.mbr_disk_signature=randomN;
            nue.disk_fit=DetFitPar(info.fit);

            //cout<<"fit disk crea:"<<nue.disk_fit<<endl;
            //para reobtener la fecha
            //tm *ltm2 = localtime(&nue.mbr_fecha_creacion);
            //cout << "Year" << 1900+ltm2->tm_year<<endl;


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


              long pos = output_file.tellp();
              output_file.seekp (pos-pos);
              output_file.write((char*)&nue, sizeof(nue));


            output_file.close();
	 	}else{
            cout<<"La ruta especificada no existe"<<endl;
	 	}






}




vector <string> RutatoReal(char* ruta){

	int i=0;
	int j=0;//relativo
	vector <string> guarda;
	char carpetax[31]={0};
	char borra[31]={0};

	while(ruta[i]!=0){

		if(ruta[i]=='/'&&j!=0){
			guarda.push_back(carpetax);
			strncpy(carpetax,borra,31);//borra contenido
			j=0;
		}else if(ruta[i]=='"'){

		}else if(ruta[i]!='/'){
			carpetax[j]=ruta[i];
			j++;
		}


	i++;
	}

		if(j!=0){
			guarda.push_back(carpetax);
			strncpy(carpetax,borra,31);//borra contenido
			j=0;
		}


	return guarda;

}


void RMELIMINA(RMD info){

	char *nomarchivo=RPfd(info.path);

		//char* olds="\"/ARCH9/disco.disk\"";
		//char *nomarchivo=RPfd(olds);
            cout<<nomarchivo<<endl;
        	FILE *eliminara;
        	eliminara=fopen(nomarchivo,"r");
			 if (eliminara==NULL)
			 {
				 cout<<"No existe la ruta o el disco"<<endl;
			 }
			else
			{
				cout<<"El disco ha sido eliminado con exito"<<endl;
		        fclose(eliminara);
		    //char* ant="del ";
		    char* ant="rm -r ";

		    char*ufinal=UneChar(ant,nomarchivo);
		    cout<<ufinal<<endl;
				system(ufinal);

			}


}




void MOUNTP(MOU info){
    cout<<"COMANDO MOUNT"<<endl;

    vector <DiskMount> Montadas=getMontadas();
    char Discos[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

    DiskMount nueva;

    char let='a';
    int num=0;
    vector <char> letr;


    bool NDNP=true;

    ///Busca Letras de discos ya usadas
    for(int j=0;j<Montadas.size();j++){
        DiskMount tempo=Montadas[j];
        short mov=((short)tempo.let)-((short)'a');
        Discos[mov]=0;
    }


    for(int i=0;i<Montadas.size();i++){
        DiskMount tempo=Montadas[i];
        if(Compare(RPfd(tempo.name),RPfd(info.name))&&Compare(RPfd(tempo.path),RPfd(info.path))){
            ///La particion ya esta montada
            cout<<"La particion ya esta montada"<<endl;
            NDNP=false;
            break;
        }else if(Compare(RPfd(tempo.path),RPfd(info.path))){
            ///Ya se ha montado una particion De ese disco
            ///Guarda la misma letra
            nueva.let=tempo.let;
            ///Recorre las montadas del disco para encontrar el ultimo numero usado
            for(int j=0;j<Montadas.size();j++){
                DiskMount tempo2=Montadas[j];
                if(Compare(RPfd(tempo2.path),RPfd(info.path))&&(tempo2.num>num)){
                    ///Busca el mayor numero particion
                    num=tempo2.num;
                }
            }
            ///aumenta en 1 el numero
            nueva.num=(num)+1;
            ///Guarda la direccion al disco
            nueva.name=info.name;
            nueva.path=RPfd(info.path);
            ///Guarda el MOUNT
            bool existe=DiskExiParti(nueva.path,nueva.name);
            if(existe){
                ///si existe el disco duro y la particion
                Montadas.push_back(nueva);
            }else{
                //cout<<"La"<<endl;
            }

            NDNP=false;
            break;
        }else{

        }
    }



    if(NDNP){
        ///Si es Disco nuevo con particion nueva selecciona la nueva letra
        for(int i=0;i<26;i++){
            if(Discos[i]!=0){
                let=Discos[i];
                break;
            }
        }

        cout<<"Guarda Particion disco Nueva"<<endl;
        ///Guardara un nuevo Disco con nueva particion
        nueva.let=let;
        ///aumenta en 1 el numero
        nueva.num=(num)+1;
        ///Guarda la direccion al disco
        nueva.name=info.name;
        nueva.path=RPfd(info.path);
        ///Guarda el MOUNT
        bool existe=DiskExiParti(RPfd(nueva.path),nueva.name);
        if(existe){
            ///si existe el disco duro y la particion
            Montadas.push_back(nueva);
        }else{
            //cout<<"La"<<endl;
        }

    }

    upMontadas(Montadas);

}





bool DiskExiParti(char* nomarchivo,char*nomParticion){

    bool retorna=false;

    MBR tempoMBR;

        //char *nomarchivo=RPfd(infoP.path);
        ifstream input_file(nomarchivo, ios::binary);
        //Obtiene el MBR
        if(input_file){
            ///validar que exista el archivo
            input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
            ///compara los nombres de cada particion existente con el nuevo a asingar
            bool nom1=Compare(tempoMBR.particion1.part_name,nomParticion);
            bool nom2=Compare(tempoMBR.particion2.part_name,nomParticion);
            bool nom3=Compare(tempoMBR.particion3.part_name,nomParticion);
            bool nom4=Compare(tempoMBR.particion4.part_name,nomParticion);
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
                nom5=validaNombres(leidos,nomParticion);
            }
            //cierra el documento
            input_file.close();

            ///Inicia el analisis de la particion

            PARTITION pmontar;

            if(nom1&&(!ind1)){
                retorna=true;
            }else if(nom2&&(!ind2)){
                retorna=true;
            }else if(nom3&&(!ind3)){
                retorna=true;
            }else if(nom4&&(!ind4)){
                retorna=true;
            }else if((nom1&&(ind1))||(nom2&&(ind2))||(nom3&&(ind3))||(nom4&&(ind4))){
                cout<<"No se puede montar un sistema de archivos en una particion Extendida"<<endl;
            }else if(nom5){
                cout<<"No se puede montar un sistema de archivos en una particion Logica"<<endl;
            }else{
                cout<<"La particion no existe en el disco duro"<<endl;
            }


        }else{
            cout<<"El disco no existe en la ruta especificada"<<endl;
        }

    return retorna;
}


void UNMOUNTP(UNM info){

vector<DiskMount>nuevo;
vector <DiskMount> Montadas=getMontadas();

int posi=-1;

    for(int i=0;i<Montadas.size();i++){
        DiskMount temp=Montadas[i];
        char * p1="09";
        char * p2= intToCharP(temp.num);

        char arr[]={temp.let,0};
        char * p3= ArrtoCharP(arr);

        char *u1=UneChar(p1,p2);
        char *u2=UneChar(u1,p3);
        /*
        cout<<"a:"<<p1<<endl;
        cout<<"b:"<<p2<<endl;
        cout<<"c:"<<p3<<endl;
        cout<<"UNION DE UNMOUNT:"<<u2<<endl;*/

        if(Compare(u2,info.id)){
            ///encontro  la particion montada
            posi=i;
            break;
        }
    }

    for(int i=0;i<Montadas.size();i++){
        if(i!=posi){
             DiskMount temp=Montadas[i];
             nuevo.push_back(temp);
        }
    }

    //Montadas=nuevo;
    upMontadas(nuevo);

}



void EXECS(EXE info){

    char*nomarchivo=RPfd(info.path);

    ifstream input_files;
    input_files.open(nomarchivo);

    ofstream output_file("archi.txt", ios::binary);
    char temps=1;

    while (input_files.tellg()!=-1)
    {
        input_files.read((char*)&temps, sizeof(temps));
        temps = tolower(temps);
        output_file.write((char*)&temps, sizeof(temps));
      cout<<temps;

    }

    input_files.close();
    output_file.close();


    FILE* in;
    //ClStru();
    in=fopen("archi.txt","r");

    cout<<"Cadena correcta0"<<endl;
    yyrestart(in);
    cout<<"Cadena correcta1"<<endl;
    yyparse();
    cout<<"Cadena correcta2"<<endl;

}




