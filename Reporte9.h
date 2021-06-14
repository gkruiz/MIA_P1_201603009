

vector<char*> escriPext(vector<char*>li1,bool ind1,bool ind2,bool ind3,bool ind4,MBR tempoMBR,vector<EBR>leidos,PARTITION extendida);

void reporteP(RE info);



void repo(RE info){


    MBR tempoMBR;


	char *nomarchivo=RPfd(info.path);
	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	if(input_file){


        ///validar que exista el archivo
        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
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

        }
        //cierra el documento
        input_file.close();


        ///inicia la generacin de los reportes

    tm *ltm = localtime(&tempoMBR.mbr_fecha_creacion);
    int ano=1900 + ltm->tm_year;
    int mes=1 + ltm->tm_mon;
    int dia= ltm->tm_mday;
    int hora=1 + ltm->tm_hour;
    int minu=1 + ltm->tm_min;
    int segu= 1 + ltm->tm_sec;



    vector<char*>lista;

    char*gene="digraph G {\n";
    lista.push_back(gene);
    lista.push_back("subgraph cluster_frontend {\n\"node1\" [\nlabel = \"{MBR|{{Nombre:| mbr_tamano | mbr_fecha_creacion |mbr_disk_signature| disk_fit}|{Valor:|");

    lista.push_back(intToCharP(tempoMBR.mbr_tamano));
    lista.push_back("|");
    lista.push_back(intToCharP(ano));
    lista.push_back("/");
    lista.push_back(intToCharP(mes));
    lista.push_back("/");
    lista.push_back(intToCharP(dia));
    lista.push_back("-");
    lista.push_back(intToCharP(hora));
    lista.push_back(":");
    lista.push_back(intToCharP(minu));
    lista.push_back(":");
    lista.push_back(intToCharP(segu));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.mbr_disk_signature));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.disk_fit));
    lista.push_back("\n}}}\"shape = \"record\"];");



    char part_status=0;
	char part_type=0;
	char part_fit=0;
	int part_start=-1;
	int part_size=0;
	char part_name[16]={0};


    lista.push_back("\n\"node2\" [label = \"{PARTITION|{{Nombre:| part_name | part_status | part_type |part_fit| part_start|part_size}|{Valor:|");
    lista.push_back(ArrtoCharP(tempoMBR.particion1.part_name));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion1.part_status));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion1.part_type));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion1.part_fit));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion1.part_start));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion1.part_size));
    lista.push_back("\n}}}\"shape = \"record\"];");


    lista.push_back("\n\"node3\" [label = \"{PARTITION|{{Nombre:| part_name | part_status | part_type |part_fit| part_start|part_size}|{Valor:|");
    lista.push_back(ArrtoCharP(tempoMBR.particion2.part_name));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion2.part_status));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion2.part_type));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion2.part_fit));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion2.part_start));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion2.part_size));
    lista.push_back("\n}}}\"shape = \"record\"];");


    lista.push_back("\n\"node4\" [label = \"{PARTITION|{{Nombre:| part_name | part_status | part_type |part_fit| part_start|part_size}|{Valor:|");
    lista.push_back(ArrtoCharP(tempoMBR.particion3.part_name));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion3.part_status));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion3.part_type));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion3.part_fit));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion3.part_start));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion3.part_size));
    lista.push_back("\n}}}\"shape = \"record\"];");


    lista.push_back("\n\"node5\" [label = \"{PARTITION|{{Nombre:| part_name | part_status | part_type |part_fit| part_start|part_size}|{Valor:|");
    lista.push_back(ArrtoCharP(tempoMBR.particion4.part_name));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion4.part_status));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion4.part_type));
    lista.push_back("|");
    lista.push_back(chaToCharP(tempoMBR.particion4.part_fit));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion4.part_start));
    lista.push_back("|");
    lista.push_back(intToCharP(tempoMBR.particion4.part_size));
    lista.push_back("\n}}}\"shape = \"record\"];");



    lista.push_back("}}");
    ofstream output_file("./REPORTES9/MBRS.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }




    output_file.close();

    char*ufinal="dot -Tpdf ./REPORTES9/MBRS.txt -o ./REPORTES9/MBRS.pdf ";
    system(ufinal);



    }else{
        cout<<"NO existe el disco en la ruta especificada"<<endl;
    }


}







void repo2(RE info){


    MBR tempoMBR;


	char *nomarchivo=RPfd(info.path);
	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	if(input_file){


        ///validar que exista el archivo
        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
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

        }
        //cierra el documento
        input_file.close();


        ///inicia la generacin de los reportes

    vector<char*>lista;

    char*gene="digraph G {\n";
    lista.push_back(gene);
    lista.push_back("subgraph cluster_frontend {\n");


    ///INICIA CON EBRS
    for(int i=0;i<leidos.size();i++){
        EBR temps=leidos[i];
            lista.push_back("\n\"node");
            lista.push_back(intToCharP(50+i));
            lista.push_back("\" [label = \"{PARTITION|{{Nombre:| part_name | part_status | part_type |part_fit| part_start|part_size|part_next}|{Valor:|");

            lista.push_back(ArrtoCharP(temps.part_name));
            lista.push_back("|");
            lista.push_back(chaToCharP(temps.part_status));
            lista.push_back("|");
            lista.push_back(chaToCharP(temps.part_type));
            lista.push_back("|");
            lista.push_back(chaToCharP(temps.part_fit));
            lista.push_back("|");
            lista.push_back(intToCharP(temps.part_start));
            lista.push_back("|");
            lista.push_back(intToCharP(temps.part_size));
            lista.push_back("|");
            lista.push_back(intToCharP(temps.part_next));
            lista.push_back("\n}}}\"shape = \"record\"];");

    }



    lista.push_back("}}");
    ofstream output_file("./REPORTES9/EBRS.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }


    output_file.close();

    char*ufinal="dot -Tpdf ./REPORTES9/EBRS.txt -o ./REPORTES9/EBRS.pdf ";
    system(ufinal);

    }else{
        cout<<"NO existe el disco en la ruta especificada"<<endl;
    }


}






void repo3(RE info){


    MBR tempoMBR;


	char *nomarchivo=RPfd(info.path);
	ifstream input_file(nomarchivo, ios::binary);
	//Obtiene el MBR
	if(input_file){


        ///validar que exista el archivo
        input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
        ///Sirve para hacer busqueda nombre de Logicas
        bool ind1=(tempoMBR.particion1.part_type=='e');
        bool ind2=(tempoMBR.particion2.part_type=='e');
        bool ind3=(tempoMBR.particion3.part_type=='e');
        bool ind4=(tempoMBR.particion4.part_type=='e');

        ///Puestos fuera para ser accedidos globalmente
        PARTITION extendida;
        vector<EBR>leidos;

        vector<StartSize>libresP=ListEspLibrPrimaria(tempoMBR);
        vector<StartSize>libresL;
        //valida que exista la particion extendida
        if(ind1||ind2||ind3||ind4){

        //seleccion la particion extendida
            extendida=getExtPartition(tempoMBR);
            //lista de ebr encontrados
            leidos=ReadEBRs(input_file,extendida);
            //libresL=ListEspLibrLogica(leidos,extendida);
        }
        //cierra el documento
        input_file.close();


        ///inicia la generacin de los reportes

    vector<char*>lista;
    float tmax=(float)tempoMBR.mbr_tamano;
    float porce=0;

    char*gene="digraph G {\n";
    lista.push_back(gene);
    lista.push_back("subgraph cluster_frontend {\n");


            lista.push_back("\n\"node");
            lista.push_back(intToCharP(0));
            lista.push_back("\" [label = \"{MBR|");
            porce=(sizeof(MBR)/tmax)*100;
            cout<<porce<<endl;
            lista.push_back(intToCharP(porce));
            lista.push_back("%");
            lista.push_back("|");
            lista.push_back(intToCharP(sizeof(MBR)));
            lista.push_back("\n}\"shape = \"record\"];");












            int finP=0;
            for(int i=0;i<libresP.size();i++){

                StartSize tempos=libresP[i];
                if(finP==tempos.start){
                ///esta contigua
                    if(tempos.type=='e'){
                        lista= escriPext(lista,ind1,ind2,ind3,ind4,tempoMBR,leidos,extendida);

                    }else{
                        lista.push_back("\n\"nodes");
                        lista.push_back(intToCharP(i));
                        lista.push_back("\" [label = \"{Particion");
                        lista.push_back(intToCharP(tempos.posi));//numero particion
                        lista.push_back("|");
                        porce=(tempos.size/tmax)*100;
                        cout<<porce<<endl;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%");
                        lista.push_back("|");
                        lista.push_back(intToCharP(tempos.size));
                        lista.push_back("\n}\"shape = \"record\"];");
                    }
                    //cout<<"posiAntes-------------->>>"<<finP<<endl;
                    finP=finP+tempos.size;

                }else{
                ///hay un espacio
                    float espas=tempos.start-finP;
                        lista.push_back("\n\"nodex");
                        lista.push_back(intToCharP(i));
                        lista.push_back("\" [label = \"{Libre");
                        lista.push_back("|");
                        porce=(espas/tmax)*100;
                        //cout<<porce<<endl;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%");
                        lista.push_back("|");
                        lista.push_back(intToCharP(espas));
                        lista.push_back("\n}\"shape = \"record\"];");

                        /// contigua continua
                        if(tempos.type=='e'){
                            lista= escriPext(lista,ind1,ind2,ind3,ind4,tempoMBR,leidos,extendida);

                        }else{
                            lista.push_back("\n\"nodes");
                            lista.push_back(intToCharP(i));
                            lista.push_back("\" [label = \"{Particion");
                            lista.push_back(intToCharP(tempos.posi));//numero particion
                            lista.push_back("|");
                            porce=(tempos.size/tmax)*100;
                            cout<<porce<<endl;
                            lista.push_back(intToCharP(porce));
                            lista.push_back("%");
                            lista.push_back("|");
                            lista.push_back(intToCharP(tempos.size));
                            lista.push_back("\n}\"shape = \"record\"];");
                        }
                        //cout<<"posiAntes-------------->>>"<<finP<<endl;
                        finP=tempos.size+tempos.start;

                }




            }

            float fiesl=tmax-finP;
            if(fiesl!=0){
                    ///hay un espacio al final del disco
                        lista.push_back("\n\"nodef");
                        lista.push_back(intToCharP(0));
                        lista.push_back("\" [label = \"{Libre");
                        lista.push_back("|");
                        porce=(fiesl/tmax)*100;
                        //cout<<porce<<endl;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%");
                        lista.push_back("|");
                        lista.push_back(intToCharP(fiesl));
                        lista.push_back("\n}\"shape = \"record\"];");

            }


    lista.push_back("}}");
    ofstream output_file("./REPORTES9/DISCO.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }


    output_file.close();
    char*ufinal="dot -Tpdf ./REPORTES9/DISCO.txt -o ./REPORTES9/DISCO.pdf ";
    system(ufinal);

    }else{
        cout<<"NO existe el disco en la ruta especificada"<<endl;
    }


}



void repo4(){

    vector<char*>lista;
    vector <DiskMount> Montadas=getMontadas();
    char*gene="digraph G {subgraph cluster_frontend {";
    lista.push_back(gene);

    for(int i=0;i<Montadas.size();i++){
       DiskMount temp=Montadas[i];
        char * p1="09";
        char * p2= intToCharP(temp.num);

        char arr[]={temp.let,0};
        char * p3= ArrtoCharP(arr);

        char *u1=UneChar(p1,p2);
        char *u2=UneChar(u1,p3);
        lista.push_back("\"node");
        lista.push_back(intToCharP(i));
        lista.push_back("\" [label = \"{MOUNT|{{Info:|Id:| Path: | Nombre: }|{Valor:|");
        lista.push_back(u2);
        lista.push_back("|");
        lista.push_back(temp.path);
        lista.push_back("|");
        lista.push_back(temp.name);
        lista.push_back("}}}\"shape = \"record\"];");


    }


        lista.push_back("}}");
        ofstream output_file("./REPORTES9/MOUNTS.txt", ios::binary);

        for(int i=0;i<lista.size();i++){
            char*tempos=lista[i];
            int tamas=longitud(tempos);
                for(int j=0;j<tamas;j++){
                    char ts=tempos[j];
                    output_file.write((char*)&ts, sizeof(ts));
                }
        }


        output_file.close();

        char*ufinal="dot -Tpdf ./REPORTES9/MOUNTS.txt -o ./REPORTES9/MOUNTS.pdf ";
        system(ufinal);




}



vector<char*> escriPext(vector<char*>li1,bool ind1,bool ind2,bool ind3,bool ind4,MBR tempoMBR,vector<EBR>leidos,PARTITION extendida){

    float tmax=(float)tempoMBR.mbr_tamano;
    float porce=0;
    vector<char*>lista=li1;

            ///Existe alguna particion extendida
            if(ind1||ind2||ind3||ind4){

                int tam=-1;
                if(ind1){
                ///primera particion ext
                    tam=tempoMBR.particion1.part_size;
                }else if(ind2){
                ///segu particion ext
                    tam=tempoMBR.particion2.part_size;
                }else if(ind3){
                ///terce particion ext
                    tam=tempoMBR.particion3.part_size;
                }else if(ind4){
                ///cuart particion ext
                    tam=tempoMBR.particion4.part_size;
                }

                ///escribe la entrada particion extendida
                lista.push_back("\"node52\" [label = \"{EXTENDIDA| {\n");


                    /// EBRS
                    int sumaSS=extendida.part_start;
                    for(int i=0;i<leidos.size();i++){


                        EBR temps=leidos[i];
                        //suma start y size
                        if(i!=0){
                            lista.push_back("|");
                        }
                        if(temps.part_start==sumaSS){
                        ///contigua
                        lista.push_back("EBR| {Logica |");
                        porce=(temps.part_size/tmax)*100;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%|");
                        lista.push_back(intToCharP(temps.part_size));
                        lista.push_back("}");
                        sumaSS=sumaSS+temps.part_size;
                        }else{
                        ///separada espacio libre
                        int libre=temps.part_start-sumaSS;
                        lista.push_back("{Libre |");
                        porce=(libre/tmax)*100;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%|");
                        lista.push_back(intToCharP(libre));
                        lista.push_back("}");
                        ///contigua luego del espacio libre
                        lista.push_back("|EBR| {Logica |");
                        porce=(temps.part_size/tmax)*100;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%|");
                        lista.push_back(intToCharP(temps.part_size));
                        lista.push_back("}");
                        sumaSS=temps.part_start+temps.part_size;



                        }

                    }

                    float fins=(extendida.part_size+extendida.part_start)-sumaSS;
                    if(fins!=0){
                    ///hay espacio al final
                        lista.push_back("|{Libre |");
                        porce=(fins/tmax)*100;
                        lista.push_back(intToCharP(porce));
                        lista.push_back("%|");
                        lista.push_back(intToCharP(fins));
                        lista.push_back("}");
                    }

            }

            lista.push_back("\n}}\"shape = \"record\"];");


    return lista;
}









































