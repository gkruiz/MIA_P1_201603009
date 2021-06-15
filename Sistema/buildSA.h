

int recorridoBloque(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int recorridoBloqueIndirecto(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int recorridoInodo(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int BusquedaRuta(PARTITION particion ,char * nombrearchivo,vector <char *> *carpe ,int * bdireccion);
int busApuLibreInodo(ifstream &input_file , inodo ino , int desp,char * tipo);

void buildMulPath(ifstream &archivo ,SB superb, int dirBlo ,int dirAbsIno,vector <char *> * valores , int desp, char *nomAr);
void MarkBMbloque(SB * superb , int desp ,int ip, char* nombrearchivo);
void MarkBMinodo(SB * superb , int desp ,int ip, char* nombrearchivo);
int calcDinodo(ifstream &archivo ,SB superb , int desp);
int calcDbloque(ifstream &archivo ,SB superb , int desp);
int creaInBlEnla(char tipo,ifstream &archivo , int dirPadre , int dirOrigen , char * nombres ,vector<char *> * ruta , SB * superb , int desp ,char * nomAr );
int buildMulIndirecto(char *nomAr,int cantidad,int direccion   , ifstream &archivo, SB * superb, int desp);
void reduEnlazIndCompl(int res ,ifstream &archivo,vector <char*> *valores,SB *superb,int desp,char* nomAr,int punteros);

void repSB(SB superb);
void repBMinoyblo(SB superb,ifstream &archivo,int desp);
void conIndvIno(inodo inos,int i,vector <char *> * lista, int posm);
void repInos(SB superb,ifstream &archivo, int desp);
void conIndvBlo(BloqueCarpeta inos,int i,vector <char *> * lista, int posm);
void repBloc(SB superb,ifstream &archivo, int desp);
void conIndvBloIndirec(BloqueApuntador inos,int i,vector <char *> * lista, int posm);
void recorridoBloqueRep(ifstream &archivo ,int direccion,int dezpla , vector <char *> * lista ,int old);
void recorridoInodoRep(ifstream &archivo ,int direccion, int dezpla , vector <char *> * lista);
void recorridoBloqueIndirectoRep(ifstream &archivo ,int direccion, int dezpla , vector <char *> * lista );
void RepoArbol(SB superb,ifstream &archivo, int desp);


void Wfolder(Mkdir info){




    ///Verifica que SI exista una sesion abierta
    if(longitud(logueada.id)!=0){

    char * usuario=logueada.usuario;
    char * password=logueada.password;
    char * id=logueada.id;

        DiskMount infoP=RetMount(id);

        ///verifica que exista la particio montada
        if(infoP.let!=0){

            PARTITION pmontar=getPartitionL(infoP);
            ///inicia con obtener usuarios
            if(pmontar.part_start!=-1){
                SB superbloque = getSuperBloque(pmontar , infoP.path);

                if((superbloque.s_block_start!=-1)&&(superbloque.s_block_start!=0)){
                    ///tendra la ruta restante que hay que construir
                    vector <char *> carpe=splitC(info.path,'/');
                    ///guarda el ultimo bloque que leyo para reenlazar
                    int * bdireccion=(int *)malloc(sizeof(int));
                    (*bdireccion)=0;
                    ///guarda direccion del ultimo inodo donde debe empezar a guardar las nuevas carpetas
                    int regre= BusquedaRuta(pmontar,infoP.path,&carpe,bdireccion);

                    int desp=sizeof(MBR)+pmontar.part_start;

                    //cout<<"Tamano de lista:"<<carpe.size()<<endl;

                    ifstream input_file(infoP.path, ios::binary);

                        buildMulPath(input_file ,superbloque, *bdireccion ,regre, &carpe , desp , infoP.path);

                    input_file.close();

                }else{
                    cout<<"La particion no esta formateada con ningun sistema de archivos"<<endl;

                }

            }

        }else{
            cout<<"La particion no esta montada en el sistema"<<endl;
        }

    }else{
        cout<<"No existe una sesion activa"<<endl;
    }





}




///particion la particion donde esta guardado el sistma de archivos
///nombrearchivo nomre del disco
///*ruta ruta donde hace la busqueda
///carpe vector donde esta alojada el split de la ruta
///bdireccio puntero que retorna la direccion del ultimo bloque que leyo para reenlazar

int BusquedaRuta(PARTITION particion ,char * nombrearchivo,vector <char *> * carpe ,int * bdireccion){

    char *nomarchivo=RPfd(nombrearchivo);
    SB superbloque;
    //vector <char *> carpe=splitC(ruta,'/');
    //int * bdireccion=(int *)malloc(sizeof(int));
    //(*bdireccion)=0;


    int retorna=-2;


    ifstream input_file(nomarchivo, ios::binary);

        if(input_file){
            input_file.seekg(particion.part_start+sizeof(MBR));
            ///carga el superbloque
            input_file.read((char*)&superbloque, sizeof(superbloque));

                ///valida que exista sistema de archivos
                if(superbloque.s_block_start!=-1){
                    int posiciont=sizeof(MBR)+particion.part_start+superbloque.s_inode_start;
                    int dezplaza=sizeof(MBR)+particion.part_start;
                    retorna=recorridoInodo(input_file , posiciont , carpe , dezplaza , bdireccion);
                    /*cout<<retorna<<endl;
                    for(int i=0;i<(carpe.size());i++){
                        cout<<carpe[i]<<endl;
                    }
                    cout<<(*bdireccion)<<endl;*/
                }else{
                    cout<<"La particion no esta formateada con ningun sistema de archivos"<<endl;
                }


        }else{
            cout<<"El disco no exite en la ruta almacenada del montaje"<<endl;
        }


    input_file.close();

    return retorna;
}


///aplicar ajuste
///ver llenar bitmap inodos  bloques


///construye los nuevos inodos y bloques para la ruta vector que se le pasa
///archivo es el archivo
///dirBlo es la direccion del ultimo bloque para reenlazar con el siguiente
///dirAbsIno es la direccion del ultimo inodo que se leyo , ahi se guaerdar la  nueva info
///valores es la lista donde se guarda la ruta separada
///desp es el deslazamiento relativo a la particion
void buildMulPath(ifstream &archivo ,SB stemp, int dirBlo ,int dirAbsIno,vector <char *> * valores , int desp , char *nomAr){

    SB superb = stemp;
    ///al terminar actualizar el superbloque

    ///toda la ruta no esta construida
    if(dirBlo==0){
        inodo temp;
        archivo.seekg(dirAbsIno);
        archivo.read((char*)&temp, sizeof(inodo));

        if((temp.i_type==1)||(temp.i_type==2)){
            char * tp=(char*)malloc(sizeof(char));
            int res= busApuLibreInodo(archivo, temp , desp,tp);
            ///INcia calculando las nuevas direcciones para inodo  bloque
            cout<<"res:"<<res<<endl;
            cout<<"*tp:"<<((*tp)*1)<<endl;


            if(((*tp)==1)&&(res!=-1)){
            ///en apuntador carpeta
                BloqueCarpeta tblo;
                archivo.seekg(desp+res);
                archivo.read((char*)&tblo, sizeof(BloqueCarpeta));
                ///valida que bloque no sea corrupto
                if(longitud(tblo.b_content[0].b_name)>0){
                    ///empieza analizar en 2 y 3 real
                    ///genera el nombre padre y origen
                    char * diago="*";
                    char * NPadr= ArrtoCharP(tblo.b_content[0].b_name);
                    char * NHij= ArrtoCharP(tblo.b_content[1].b_name);
                    char * fusiNom=UneChar(NPadr,diago);
                    fusiNom=UneChar(fusiNom,NHij);
                    //cout<<"salunido:"<<fusiNom<<endl;
                    int dirNueva=-1;

                    if(tblo.b_content[2].b_inodo==-1){
                        ///copia antes de que el nombre se elimine
                        strcpy(tblo.b_content[2].b_name, (*valores)[0]);
                        dirNueva= creaInBlEnla('2',archivo ,tblo.b_content[0].b_inodo , tblo.b_content[1].b_inodo , fusiNom ,valores , &superb , desp ,nomAr );
                        tblo.b_content[2].b_inodo=dirNueva;
                    }else if(tblo.b_content[3].b_inodo==-1){
                        ///lo mismo
                        strcpy(tblo.b_content[3].b_name, (*valores)[0]);
                        dirNueva= creaInBlEnla('2',archivo ,tblo.b_content[0].b_inodo , tblo.b_content[1].b_inodo , fusiNom ,valores , &superb , desp ,nomAr );
                        tblo.b_content[3].b_inodo=dirNueva;
                    }else{
                        cout<<"Error no libre"<<endl;
                    }
                    ///guarda el bloque leido ya actualizado
                    ofstream output_file(nomAr, ios::in);
                    output_file.seekp(desp+res);
                    output_file.write((char*)&tblo, sizeof(BloqueCarpeta));
                    output_file.close();
                }else{
                    cout<<"Bloque carpeta corrupto"<<endl;
                }



            }else if(((*tp)==2)&&(res!=-1)){
            ///en el inodo apuntador


                char * ss="-1*/";
                int dirNueva=-1;
                dirNueva= creaInBlEnla('2',archivo ,1, 1 , ss ,valores , &superb , desp ,nomAr );
                int dirIndirecto=-1;

                if(dirNueva!=-1){
                    if(res<=11){
                      //  cout<<"VALOR DE RES:"<<res<<endl;
                        temp.i_block[res]=dirNueva;
                    }else if(res==12){
                        dirIndirecto=buildMulIndirecto(nomAr,1,dirNueva,archivo,&superb,desp);
                        temp.i_block[res]=dirIndirecto;
                    }else if(res==13){
                        dirIndirecto=buildMulIndirecto(nomAr,2,dirNueva,archivo,&superb,desp);
                        temp.i_block[res]=dirIndirecto;
                    }else if(res==14){
                        dirIndirecto=buildMulIndirecto(nomAr,3,dirNueva,archivo,&superb,desp);
                        temp.i_block[res]=dirIndirecto;
                    }else{
                        cout<<"Error posicion"<<endl;
                    }
                  //   cout<<"sale res:"<<endl;
                    ///guarda el bloque leido ya actualizado en el INODO
                    ofstream output_file(nomAr, ios::in);
                    output_file.seekp(dirAbsIno);
                    output_file.write((char*)&temp, sizeof(inodo));
                    output_file.close();
                }else{
                    cout<<"Hubo un error al obtener la direccion"<<endl;
                }




            }else if(((*tp)==3)&&(res!=-1)){
            ///en primer apuntador indirecto , primer nivel
                reduEnlazIndCompl(res , archivo,valores,&superb, desp,nomAr,0);

            }else if(((*tp)==4)&&(res!=-1)){
            ///en segundo apuntador indirecto , primer nivel

                reduEnlazIndCompl(res ,archivo, valores , &superb, desp,nomAr,1);

            }else if(((*tp)==5)&&(res!=-1)){
            ///en segundo apuntador indirecto , segundo nivel
                cout<<"GUARDARA EN INDIRECTO 2----------------------"<<endl;
                cout<<"Direccion res:"<<res<<endl;
                reduEnlazIndCompl(res , archivo,valores,&superb, desp,nomAr,0);
            }else if(((*tp)==6)&&(res!=-1)){
            ///en tercer apuntador indirecto , primer nivel
                reduEnlazIndCompl(res ,archivo, valores , &superb, desp,nomAr,2);
            }else if(((*tp)==7)&&(res!=-1)){
            ///en tercer apuntador indirecto , segundo nivel
                reduEnlazIndCompl(res ,archivo, valores , &superb, desp,nomAr,1);
            }else if(((*tp)==8)&&(res!=-1)){
            ///en tercer apuntador indirecto , tercer nivel
                reduEnlazIndCompl(res , archivo,valores,&superb, desp,nomAr,0);
            }else{
                cout<<"la direccion es nula o el tipo esta mal"<<endl;
            }


        }else{
            cout<<"El inodo leido esta corrupto"<<endl;

        }



    }else{
    ///parte de la ruta esta creada
    ///existe un bloque antes creado
    ///inicia reenlazar


    }

    ///actualiza superbloque

        int UdirInodo=calcDinodo(archivo,superb,desp);
        int UdirBloque=calcDbloque(archivo,superb,desp);

        if(UdirInodo!=-1){
            UdirInodo=superb.s_inode_start+(UdirInodo*sizeof(inodo));
        }
        if(UdirBloque!=-1){
            UdirBloque=superb.s_block_start+(UdirBloque*sizeof(BloqueCarpeta));
        }

        superb.s_first_ino=UdirInodo;
        superb.s_first_blo=UdirBloque;

        ofstream output_file(nomAr, ios::in);
        output_file.seekp(desp);
        output_file.write((char*)&superb, sizeof(SB));
        output_file.close();


}




///punteros : Indica la cantidad de punteros Indirectos intermedios a crear
void reduEnlazIndCompl(int res ,ifstream &archivo,vector <char*> *valores,SB *superb,int desp,char* nomAr,int punteros){

                BloqueApuntador tblo;
                archivo.seekg(desp+res);
                archivo.read((char*)&tblo, sizeof(BloqueApuntador));
                cout<<"Dir real:"<<(desp+res)<<endl;
                ///lee el bloque apuntador indirecto
                bool val=false;

                int free=-1;
                ///hace OR con todos los valores
                for(int i=0;i<16;i++){
                    bool vllen=tblo.b_pointers[i]!=0;
                    if((tblo.b_pointers[i]==0)&&(free==-1)){
                        free=i;
                    }
                    val=val||vllen;
                }

                ///verifica que no sea corrupto
                if(val){
                ///inicia generado de path actualiza path
                    char * ss="-1*/";
                    int dirNueva=-1;
                    dirNueva= creaInBlEnla('2',archivo ,1, 1 , ss ,valores , superb , desp ,nomAr );

                    if(dirNueva!=-1){
                        if(punteros==0){
                            cout<<"Puntero0:"<<endl;
                            cout<<"dirCarpetasNuevo:"<<dirNueva<<endl;
                            cout<<"posicion en indirecto:"<<free<<endl;
                            cout<<"dir Indir Abs:"<<(desp+res)<<endl;

                            tblo.b_pointers[free]=dirNueva;
                        }else{
                            int dirIndirec=buildMulIndirecto(nomAr,punteros,dirNueva,archivo,superb,desp);
                            tblo.b_pointers[free]=dirIndirec;
                        }




                        ///guarda el bloque leido ya actualizado
                        ofstream output_file(nomAr, ios::in);
                        output_file.seekp(desp+res);
                        output_file.write((char*)&tblo, sizeof(BloqueApuntador));
                        output_file.close();
                    }else{
                        cout<<"Hubo un error al obtener la direccion"<<endl;
                    }

                }else{
                    cout<<"El apuntador indirecto es corrupto"<<endl;
                }


}




int buildMulIndirecto(char *nomAr,int cantidad,int direccion   , ifstream &archivo, SB * superb, int desp){
    ///son puros apuntadores indirectos nuevos

    int retorna=-1;
    cout<<"Direccion Indirecto:"<<direccion<<endl;

    if((direccion!=-1 || direccion!=0)&&(cantidad>0)){
        BloqueApuntador nuevo;
        nuevo.b_pointers[0]=direccion;

        int nuevadir=calcDbloque(archivo,(*superb),desp);
        if(nuevadir!=-1){
            ///para reenlzar en el bloque que le correspoda
            retorna=((*superb).s_block_start)+(nuevadir*sizeof(BloqueApuntador));
            ///marca si existe la ruta el bloque usado
            MarkBMbloque(superb,desp,nuevadir,nomAr);
            int tpos=desp+((*superb).s_block_start)+(nuevadir*sizeof(BloqueApuntador));
            ofstream output_file(nomAr, ios::in);
            output_file.seekp(tpos);
            output_file.write((char*)&nuevo, sizeof(BloqueApuntador));
            output_file.close();

            retorna=buildMulIndirecto(nomAr,(cantidad-1),(tpos-desp), archivo, superb,desp);
        }else{
            cout<<"Error direccion "<<endl;
        }

    }else if(cantidad<=0){
        retorna=direccion;
    }else{
        cout<<"Direccion Nula o vacia"<<endl;
    }





    return retorna;

}




///dir padre es la direccion relativa inodo a la particion
///dir origen lo mismo relativo
///nombres "nombre Padre / nombre Origen"
///ruta es la ruta separada
///superb super bloque
///desp es mbr+posicion de la particion
///nom archi , nombre del archivo para escribir sobre el
///tipo si crea bloque carpeta pos0 o crea en otro , solo llenaria primer bloque del bloque carpeta
///'1' es carpeta padre , origen ,hijo ,    '2' carpeta hijo nada mas
int creaInBlEnla(char tipo,ifstream &archivo , int dirPadre , int dirOrigen , char * nombres ,vector<char *> * ruta , SB * superb , int desp ,char * nomAr ){

    ///verifica que exista dir pardre
    ///verifica que exista dir Origen
    ///verifica que existe por lo menos 1 registro
    int retUltDirBlo=-1;
   // cout<<"creaEntra"<<endl;
    if(((*ruta).size())>0){
    //cout<<"pasa1creaEntra"<<endl;
        //(dirPadre!=-1)&&
        if((dirOrigen!=-1)){
            time_t now = time(0);
            vector <char *> nombrePyO= splitC(nombres,'*');
            int dirBlo = calcDbloque(archivo,(*superb),desp);///es numero no direccion
            int dirIno = calcDinodo(archivo,(*superb),desp);

          //  cout<<"dirblo"<<dirBlo<<endl;
          //  cout<<"dirino"<<dirIno<<endl;


            ///valida que exista direccion inodo y bloque
            if(dirBlo!=-1&&dirIno!=-1){

                if(dirPadre==-1){
                    retUltDirBlo=((*superb).s_inode_start)+(dirIno*sizeof(inodo));
                }else{
                    ///calcula la direccion relativa a la particion del ultimo bloque
                    retUltDirBlo=((*superb).s_block_start)+(dirBlo*sizeof(BloqueCarpeta));
                }

                ///Inicia llenado de Inodo y bloque carpeta
                inodo primero;
                primero.i_uid=0;    ///usuario propietario
                primero.i_gid=0;    ///grupo al que pernece propietario
                primero.i_size=0;   ///tamano del archivo
                primero.i_atime=now;  ///fecha de ultima lectura
                primero.i_ctime=now;///fecha creacion
                ///primero.i_block[0]=superBloque.s_block_start;///Se llenara mas abajo
                primero.i_type=1;///es una carpeta
                primero.i_perm=777;///Permisos




                Content info;
                BloqueCarpeta carpeta;

                if(tipo=='1'){
                    ///Apuntador inodo padre:
                    char*text=nombrePyO[0];
                    strcpy(info.b_name, text);
                    info.b_inodo=dirPadre;
                    carpeta.b_content[0]=info;

                    ///Apuntador inodo Origen:
                     Content info1;
                    text=nombrePyO[1];
                    strcpy(info1.b_name, text);
                    info1.b_inodo=dirOrigen;
                    carpeta.b_content[1]=info1;

                    ///Apuntador inodo hijo:
                     Content info2;
                    text=(*ruta)[0];
                    strcpy(info2.b_name, text);
                    info2.b_inodo=((*superb).s_inode_start)+(dirIno*sizeof(inodo));
                    carpeta.b_content[2]=info2;

                }else{

                    ///Apuntador inodo hijo PRIMERAO:
                    char*text=(*ruta)[0];
                    strcpy(info.b_name, text);
                    info.b_inodo=((*superb).s_inode_start)+(dirIno*sizeof(inodo));
                    carpeta.b_content[0]=info;

                }


                ///INICIA escribir datos de inodo y bloque
                ///escribe bloque
                ///Relativo disco / Relativo particion / Relativo Bloque Bloques
                int tpos=desp+((*superb).s_block_start)+(dirBlo*sizeof(BloqueCarpeta));
                ofstream output_file(nomAr, ios::in);
                output_file.seekp(tpos);
                output_file.write((char*)&carpeta, sizeof(BloqueCarpeta));
                ///escribe inodo
                ///Relativo disco / Relativo particion / Relativo Bloque Inodos
                //tpos=desp+((*superb).s_inode_start)+(dirIno*sizeof(inodo));
                //cout<<"Escribe inodo en p relativa:"<<((*superb).s_inode_start)+(dirIno*sizeof(inodo))<<endl;
                //output_file.seekp(tpos);
                //output_file.write((char*)&primero, sizeof(inodo));
                output_file.close();

                ///Marca los bitmap de inodo y de bloque
                MarkBMbloque(superb,desp,dirBlo,nomAr);
                MarkBMinodo(superb,desp,dirIno,nomAr);

                ///genera el nombre padre y origen
                char * diago="*";
                char * fusiNom=UneChar(nombrePyO[1],diago);
                fusiNom=UneChar(fusiNom,(*ruta)[0]);
                //cout<<"salunido:"<<fusiNom<<endl;

                ///saca de la lista
                vector <char *> temV=(*ruta);
                //cout<<"pasa1creaEntrax"<<endl;
                pop_front(temV);
                //cout<<"pasa1creaEntray"<<endl;
                (*ruta)=temV;
               // cout<<"pasa1creaEntraz"<<endl;
                ///ser vuelve a rellamar
                ///Dir Padre es la de origen , y la de Origen es la del ultimo inodo
                ///

                int reci=creaInBlEnla('1',archivo , dirOrigen , ((*superb).s_inode_start)+(dirIno*sizeof(inodo)) , fusiNom ,ruta ,superb ,desp ,nomAr );
                if(reci!=-1&&reci>0){
                    primero.i_block[0]=reci;
                }

                ofstream output_file2(nomAr, ios::in);
                tpos=desp+((*superb).s_inode_start)+(dirIno*sizeof(inodo));
                output_file2.seekp(tpos);
                output_file2.write((char*)&primero, sizeof(inodo));
                output_file2.close();


            }else{
                cout<<"No hay suficientes Inodos o bloques para crear el archivo"<<endl;

            }









        }else{
            cout<<"La direccion Padre u Origen o Size ruta esta mal"<<endl;
        }
    }
    //cout<<"salta a retornar"<<endl;

    return retUltDirBlo;


}







///marca el bitmap de bloques
///ip indice posicion del bitmap bloque
///direcciond del super bloque para hacer resta de bloque
void MarkBMbloque(SB * superb , int desp ,int ip, char* nombrearchivo){

    int inibitMapBloques=(*superb).s_bm_block_start;
    int sizChar=sizeof(bool);
    int canBloques=(*superb).s_blocks_count;


    if(ip<canBloques){
        int tpos=desp+inibitMapBloques+(ip*sizChar);
        ofstream output_file(nombrearchivo, ios::in);
        bool tx=1;
        output_file.seekp(tpos);
        output_file.write((char*)&tx, sizeof(bool));
        output_file.close();

        ((*superb).s_free_blocks_count)=((*superb).s_free_blocks_count)-1;
        ///no calcula aqui nueva direccion vacia de inodo , mejor hacer hasta el final

    }else{
        cout<<"La posicion del inodo es mayor a la cantidad permitida"<<endl;
    }


}



///marca el bitmap de inodos
///ip indice posicion del bitmap inodo
///direccion resta del inodo en sb
void MarkBMinodo(SB * superb , int desp ,int ip, char* nombrearchivo){

    int inibitMapInodos=(*superb).s_bm_inode_start;
    int sizChar=sizeof(bool);
    int canInodos=(*superb).s_inodes_count;

    if(ip<canInodos){
        int tpos=desp+inibitMapInodos+(ip*sizChar);
        ofstream output_file(nombrearchivo, ios::in);
        bool tx=1;
        output_file.seekp(tpos);
        output_file.write((char*)&tx, sizeof(bool));
        output_file.close();

        (*superb).s_free_inodes_count=((*superb).s_free_inodes_count)-1;
        ///no calcula aqui nueva direccion vacia de inodo , mejor hacer hasta el final

    }else{
        cout<<"La posicion del inodo es mayor a la cantidad permitida"<<endl;
    }

}





///retorna entero posicio del inodo ,NO direccion
int calcDinodo(ifstream &archivo ,SB superb , int desp){

    int retorna=-1;

    int inibitMapInodos=superb.s_bm_inode_start;
    int sizChar=sizeof(bool);
    int canInodos=superb.s_inodes_count;
    //cout<<"TOTAL BLOQUES:"<<superb.s_blocks_count<<endl;
    //cout<<"TOTAL INODOS:"<<superb.s_inodes_count<<endl;

    for(int i=0;i<canInodos;i++){
        int tpos=desp+inibitMapInodos+(i*sizChar);
        bool temp;
        archivo.seekg(tpos);
        archivo.read((char*)&temp, sizChar);

        if(temp==0){
            retorna=i;
            break;
        }else if(i==(canInodos-1)){
            cout<<"No hay espacios libres Inodos"<<endl;
        }
    }

    return retorna;

}





///retorna entero posicio del inodo ,NO direccion
int calcDbloque(ifstream &archivo ,SB superb , int desp){

    int retorna=-1;

    int inibitMapBloques=superb.s_bm_block_start;
    int sizChar=sizeof(bool);
    int canBloques=superb.s_blocks_count;


    for(int i=0;i<canBloques;i++){
        int tpos=desp+inibitMapBloques+(i*sizChar);
        bool temp;
        archivo.seekg(tpos);
        archivo.read((char*)&temp, sizChar);

        if(temp==0){
            retorna=i;
            break;
        }else if(i==(canBloques-1)){
            cout<<"No hay espacios libres bloques"<<endl;
        }
    }

    return retorna;

}




///al eliminar , no eliminar el primer bloque si existen mas carptas creadas en la misma linea


int busApuLibreInodo(ifstream &input_file , inodo ino , int desp,char * tipo){
    ///1 es apuntador carpeta   /retorna la direccion relativa
    ///2 es dentro del inodo    /retorna la posicion /cuidado 12 13 14 y el 0
    ///3 es apuntador indirecto 1 /retorna la direccion

    ///4 es apuntador indirecto 2 primer nivel /retorna la direccion
    ///5 es apuntador indirecto 2 segundo nivel /retorna la direccion

    ///6 es apuntador indirecto 3 primer nivel /retorna la direccion
    ///7 es apuntador indirecto 3 segundo nivel /retorna la direccion
    ///8 es apuntador indirecto 3 tercer nivel /retorna la direccion

    ///ApuntadorInd , Nivel
    ///1 1
    ///2 1 2
    ///3 1 2 3


    int retorna=-1;


    ///primero busca dentro del primer bloque si existiera
    if(ino.i_block[0]!=0){
        ///lee el bloque para verificar que exista espacio en el cuarto y tercer bloque
        BloqueCarpeta temp;
        input_file.seekg(desp+ino.i_block[0]);
        input_file.read((char*)&temp, sizeof(BloqueCarpeta));
        ///cout<<"iblock:"<<ino.i_block[0]<<endl;
        //cout<<"pri:"<<temp.b_content[0].b_name<<endl;
        //cout<<"segu:"<<temp.b_content[1].b_name<<endl;


        if(longitud(temp.b_content[0].b_name)>0&&longitud(temp.b_content[1].b_name)>0){
            ///verifica espcio libre
            if((temp.b_content[2].b_inodo==-1)||(temp.b_content[3].b_inodo==-1)){

                retorna=ino.i_block[0];

                (*tipo)=1;
            }

        }else{
            cout<<"El bloque esta corrupto"<<endl;
        }
    }

    ///seguiria analizando las otras posiciones a 15*
    if(retorna==-1){
        for(int i=0;i<15;i++){
            if(ino.i_block[i]==0){
                retorna=i;
                (*tipo)=2;
                break;
            }
        }
    }


    ///seguiria analizando la posicion indirecta 12*
    if((retorna==-1)&&(ino.i_block[12]!=0)){
        BloqueApuntador temp;
        input_file.seekg(desp+ino.i_block[12]);
        input_file.read((char*)&temp, sizeof(BloqueApuntador));

        for(int i=0;i<16;i++){
            if(temp.b_pointers[i]==0){
                retorna=ino.i_block[12];
                (*tipo)=3;
                break;
            }
        }
    }





    ///seguiria analizando la posicion indirecta 13*
    if((retorna==-1)&&(ino.i_block[13]!=0)){
        BloqueApuntador temp;
        input_file.seekg(desp+ino.i_block[13]);
        input_file.read((char*)&temp, sizeof(BloqueApuntador));

        for(int i=0;i<16;i++){
            ///primero busca espacio libre Pindirecto primer nivel , numero 13
            if(temp.b_pointers[i]!=0){
                ///si esta ocupado , entra y busca en el segundo nivel , numero 13
                BloqueApuntador temp2;
                input_file.seekg(desp+temp.b_pointers[i]);
                input_file.read((char*)&temp2 , sizeof(BloqueApuntador));

                for(int j=0;j<16;j++){
                    if(temp2.b_pointers[j]==0){
                        retorna=temp.b_pointers[i];
                        (*tipo)=5;
                        break;
                    }
                }

            }else{
                retorna=ino.i_block[13];
                (*tipo)=4;
                break;

            }
        }
    }



    ///seguiria analizando la posicion indirecta 14*
    if((retorna==-1)&&(ino.i_block[14]!=0)){
        BloqueApuntador temp;
        input_file.seekg(desp+ino.i_block[14]);
        input_file.read((char*)&temp, sizeof(BloqueApuntador));

        for(int i=0;i<16;i++){
            ///primero busca espacio libre Pindirecto primer nivel , numero 14
            if(temp.b_pointers[i]==0){
                retorna=ino.i_block[14];
                (*tipo)=6;
                break;
            }else{
            ///si esta ocupado , entra y busca en el segundo nivel , numero 14
                BloqueApuntador temp2;
                input_file.seekg(desp+temp.b_pointers[i]);
                input_file.read((char*)&temp2 , sizeof(BloqueApuntador));

                for(int j=0;j<16;j++){
                    if(temp2.b_pointers[j]==0){
                        retorna=temp.b_pointers[i];
                        (*tipo)=7;
                        break;
                    }else{
                    ///si esta ocupado , entra y busca en el tercer nivel , numero 14
                        BloqueApuntador temp3;
                        input_file.seekg(desp+temp2.b_pointers[j]);
                        input_file.read((char*)&temp3 , sizeof(BloqueApuntador));

                        for(int k=0;k<16;k++){
                            if(temp2.b_pointers[k]==0){
                                retorna=temp2.b_pointers[j];
                                (*tipo)=8;
                                break;
                            }
                        }

                    }
                }

            }
        }
    }


 return retorna;


}






///cuando eliminar validar que no queden bloques
///con todas las direcciones vacias


///busca de moento solo carpeta ruta
///finaliza con un inodo
///archivo para usar
///direccion es donde leera el  nuevo inodo
///valores lista de nombres de la ruta
///dezpla desplazamiento relativo a la particion
///bdir direccion del ultimo bloque leido
int recorridoInodo(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla ,int * bdir ){
    ///-2 significa error, -x si encontro , +x ahi nomas se quedo
    int retorna=-2;

    if((*valores).size()>0){
        inodo temp;

        archivo.seekg(direccion);
        archivo.read((char*)&temp, sizeof(inodo));

        ///sirve para ver si el inodo se leyo bien
        if((temp.i_type==1||temp.i_type==2)){
            ///valida que sea una carpeta
            if(temp.i_type==1){
                //cout<<"Es una carpeta"<<endl;
                ///inicia a ver si existen apuntadores creados en el inodo
                for(int i=0;i<12;i++){
                    if(temp.i_block[i]!=0){
                    cout<<"Esta en i:"<<i<<endl;
                    cout<<"Salta a bloque"<<endl;
                    ///existe un apuntador bloque a carpeta o archivo
                    int posiciont=dezpla+temp.i_block[i];
                        retorna=recorridoBloque(archivo,posiciont,valores,dezpla,bdir);
                        cout<<"Retorna?"<<retorna<<endl;
                        if(retorna!=-2){

                            break;
                        }

                    }
                }

                ///si retorna aun no encuentra pasa a nodos simple , doble , y triple




                ///apundador simple
                if((retorna==-2)&&(temp.i_block[12]!=0)){
                    int posiciont=dezpla+temp.i_block[12] ;
                    retorna=recorridoBloqueIndirecto(archivo, posiciont ,valores,dezpla,bdir);
                }





                ///apuntador doble
                if((retorna==-2)&&(temp.i_block[13]!=0)){
                    BloqueApuntador tempx;

                    archivo.seekg(temp.i_block[13]);
                    archivo.read((char*)&tempx, sizeof(BloqueApuntador));

                    for(int i=0;i<16;i++){
                        if(tempx.b_pointers[i]!=0){
                            int posiciont=dezpla+tempx.b_pointers[i] ;
                            retorna=recorridoBloqueIndirecto(archivo, posiciont ,valores,dezpla,bdir);
                            if(retorna!=-2){
                                break;
                            }
                        }
                    }

                }




                ///apuntador triple
                if((retorna==-2)&&(temp.i_block[14]!=0)){

                    BloqueApuntador tempx;

                    archivo.seekg(temp.i_block[14]);
                    archivo.read((char*)&tempx, sizeof(BloqueApuntador));

                    for(int i=0;i<16;i++){
                        if(tempx.b_pointers[i]!=0){
                            BloqueApuntador tempx2;

                            archivo.seekg(tempx.b_pointers[i]);
                            archivo.read((char*)&tempx2, sizeof(BloqueApuntador));


                            for(int j=0;j<16;j++){
                                if(tempx2.b_pointers[j]!=0){
                                    int posiciont=dezpla+tempx2.b_pointers[j] ;
                                    retorna=recorridoBloqueIndirecto(archivo, posiciont ,valores,dezpla,bdir);
                                    if(retorna!=-2){
                                        break;
                                    }
                                }
                            }

                            if(retorna!=-2){
                                break;
                            }

                        }
                    }

                }





                if(retorna==-2){
                    retorna=direccion;
                }

                ///si tampoco con los super , entonces retorna su direccion



            }else{

                cout<<"Es un archivo"<<endl;
            }

        }else{
            cout<<"El inodo leido esta corrupto"<<endl;

        }


    }else{
        retorna=-1*direccion;
        //cout<<"Fin lectura"<<endl;
    }


    return retorna;

}



///verificar si todos vacios eliminar direccion
///en apuntadores varios 1 2 3
int recorridoBloqueIndirecto(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla ,int * bdir ){


    int retorna=-2;

    if((*valores).size()>0){
        BloqueApuntador temp;

        archivo.seekg(direccion);
        archivo.read((char*)&temp, sizeof(BloqueApuntador));


                ///inicia a ver si conincide el nombre y la ruta
                for(int i=0;i<16;i++){

                    if(temp.b_pointers[i]!=0){
                        int posiciont=dezpla+temp.b_pointers[i] ;
                        retorna=recorridoBloque(archivo,posiciont,valores,dezpla,bdir);

                        if(retorna!=-2){

                            break;
                        }
                    }

                }


    }else{
        //retorna=-1*direccion;
        //cout<<"Fin lectura bloqueIndirecto?"<<endl;
    }

    return retorna;

}




int recorridoBloque(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla ,int * bdir ){


    int retorna=-2;

    if((*valores).size()>0){
        BloqueCarpeta temp;

        archivo.seekg(direccion);
        archivo.read((char*)&temp, sizeof(BloqueCarpeta));

        ///sirve para ver si el bloque se leyo bien
        if((temp.b_content[0].b_inodo!=-1)||(temp.b_content[1].b_inodo!=-1)||(temp.b_content[2].b_inodo!=-1)||(temp.b_content[3].b_inodo!=-1)){


                ///inicia a ver si conincide el nombre y la ruta
                for(int i=0;i<4;i++){
                    if(temp.b_content[i].b_inodo!=-1){
                        ///obtiene el nombre guardado en el bloque
                        char * nombenB=ArrtoCharP(temp.b_content[i].b_name);
                        cout<<"nombreenBloque:"<<nombenB<<endl;
                        cout<<"nombrecompara:"<<(*valores)[0]<<endl;

                        if(Compare(nombenB,(*valores)[0])){
                            ///guarda la ultima direccion del bloque leido
                            (*bdir)=direccion;
                            ///parte de la ruta coincidio
                            vector<char *> cambVal=(*valores);
                            pop_front(cambVal);
                            (*valores)=cambVal;
                            //cout<<"t bloque quita:"<<cambVal.size()<<endl;
                            //cout<<"i:"<<i<<endl;
                            //cout<<"t content name?:"<<temp.b_content[i].b_name<<endl;
                            //cout<<"t content inodo?:"<<temp.b_content[i].b_inodo<<endl;


                            int posiciont=dezpla+temp.b_content[i].b_inodo ;
                            retorna=recorridoInodo(archivo ,posiciont, valores ,dezpla,bdir);
                            break;
                        }

                    }


                }


        }else{
            cout<<"El bloque leido esta corrupto"<<endl;

        }


    }else{
        retorna=-1*direccion;
        //cout<<"Fin lectura bloque?"<<endl;
    }

    return retorna;

}







void reporteP(RE info){




    char * id=info.id;
    if(longitud(id)>0){

        DiskMount infoP=RetMount(id);

        ///verifica que exista la particio montada
        if(infoP.let!=0){

            PARTITION pmontar=getPartitionL(infoP);
            ///inicia con obtener usuarios
            if(pmontar.part_start!=-1){
                SB superbloque = getSuperBloque(pmontar , infoP.path);

                if((superbloque.s_block_start!=-1)&&(superbloque.s_block_start!=0)){
                    int desp=sizeof(MBR)+pmontar.part_start;
                    ifstream archivo(infoP.path, ios::in);
                     repSB(superbloque);
                     repBMinoyblo(superbloque,archivo,desp);
                     repInos(superbloque,archivo,desp);
                     repBloc(superbloque,archivo,desp);
                     RepoArbol(superbloque,archivo,desp);

                    //cout<<"Tamano de lista:"<<carpe.size()<<endl;



                        //buildMulPath(input_file ,superbloque, *bdireccion ,regre, &carpe , desp , infoP.path);

                    archivo.close();

                }else{
                    cout<<"La particion no esta formateada con ningun sistema de archivos"<<endl;

                }

            }

        }else{
            cout<<"La particion no esta montada en el sistema"<<endl;
        }


    }else{
        cout<<"ID vacio no puede generar reporte sistema archivos"<<endl;
    }




}





void repSB(SB superb){

    vector<char*>lista;

    char*gene="digraph G {subgraph cluster_frontend {\"node1\" [label = \"{SuperBloque|{{Nombre:| s_inodes_count | s_blocks_count |s_free_blocks_count|s_free_inodes_count|s_mtime|s_umtime|s_mnt_count|s_magic|s_inode_size|s_block_size|s_first_ino|s_first_blo|s_bm_inode_start|s_bm_block_start|s_inode_start|s_block_start}|";
    lista.push_back(gene);
    lista.push_back("{Valor:");
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_inodes_count));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_blocks_count));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_free_blocks_count));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_free_inodes_count));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_mtime));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_umtime));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_mnt_count));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_magic));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_inode_size));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_block_size));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_first_ino));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_first_blo));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_bm_inode_start));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_bm_block_start));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_inode_start));
    lista.push_back("|");
    lista.push_back(intToCharP(superb.s_block_start));
    lista.push_back("}}}\"shape = \"record\"];}}");





    ofstream output_file("./REPORTES9/SuperBloque.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }
    output_file.close();

    char*ufinal="dot -Tpdf ./REPORTES9/SuperBloque.txt -o ./REPORTES9/SuperBloque.pdf ";
    system(ufinal);



}



void repBMinoyblo(SB superb,ifstream &archivo,int desp){


    int inibitMapInodos=superb.s_bm_inode_start;
    int sizChar=sizeof(bool);
    int canInodos=superb.s_inodes_count;

    ofstream output_file("./REPORTES9/BitMapInodos.txt", ios::binary);
    int sub=0;
    for(int i=0;i<canInodos;i++){
        int tpos=desp+inibitMapInodos+(i*sizChar);
        bool temp;
        archivo.seekg(tpos);
        archivo.read((char*)&temp, sizChar);

        char ts=0;

        if(temp==0){
            ts='0';
            output_file.write((char*)&ts, sizeof(char));
        }else{
            ts='1';
            output_file.write((char*)&ts, sizeof(char));
        }

        sub++;

        if(sub==20){
            ts='\n';
            output_file.write((char*)&ts, sizeof(char));
            sub=0;
        }

    }

    output_file.close();


    ///hace reporte bitma bloques


    ofstream output_file2("./REPORTES9/BitMapBloques.txt", ios::binary);
    sub=0;
    int inibitMapBloques=superb.s_bm_block_start;
    int canBloques=superb.s_blocks_count;


    for(int i=0;i<canBloques;i++){
        int tpos=desp+inibitMapBloques+(i*sizChar);
        bool temp;
        archivo.seekg(tpos);
        archivo.read((char*)&temp, sizChar);

        char ts=0;

        if(temp==0){
            ts='0';
            output_file2.write((char*)&ts, sizeof(char));
        }else{
            ts='1';
            output_file2.write((char*)&ts, sizeof(char));
        }

        sub++;

        if(sub==20){
            ts='\n';
            output_file2.write((char*)&ts, sizeof(char));
            sub=0;
        }




    }

    output_file2.close();

}





void repInos(SB superb,ifstream &archivo, int desp){

    int inousados=(superb.s_inodes_count)-(superb.s_free_inodes_count);


    vector<char*>lista;

    int dir=desp+superb.s_inode_start;
    int tami=sizeof(inodo);

    lista.push_back("digraph G { rankdir=LR;");

    for(int i=0;i<inousados;i++){
        int dirT=dir+(i*tami);
        inodo temp;
        archivo.seekg(dirT);
        archivo.read((char*)&temp, tami);
        conIndvIno(temp,i,&lista,dirT);
        lista.push_back(" \n");
    }

        for(int i=0;i<inousados;i++){
        lista.push_back("node");
        lista.push_back(intToCharP(i));
        lista.push_back("->node");
        lista.push_back(intToCharP((i+1)));
        lista.push_back(" \n");
        }
    lista.push_back("}");



    ofstream output_file("./REPORTES9/RepInodos.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }
    output_file.close();

    char*ufinal="dot -Tpdf ./REPORTES9/RepInodos.txt -o ./REPORTES9/RepInodos.pdf ";
    system(ufinal);




}



void conIndvIno(inodo inos,int i,vector <char *> * lista, int posm){

    char*gene="\"node";
    (*lista).push_back(gene);
    (*lista).push_back(intToCharP(i));
    gene="\" [label = \"{{Inodo_";
    (*lista).push_back(gene);
    (*lista).push_back(intToCharP(posm));
    gene=" |{{Nombre:| i_uid | i_gid |i_size|i_atime|i_ctime|i_mtime|p0|p1|p2|p3|p4|p5|p6|p7|p8|p9|p10|p11|p12|p13|p14|i_type|i_perm}|{Valor:|";
    (*lista).push_back(gene);



    (*lista).push_back(intToCharP(inos.i_uid));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_gid));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_size));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_atime));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_ctime));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_mtime));
    for(int j=0;j<15;j++){
        (*lista).push_back("|");
        (*lista).push_back(intToCharP(inos.i_block[j]));
    }
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_type));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.i_perm));

    (*lista).push_back("}}}}\"shape = \"record\"];\n");

}





void RepoArbol(SB superb,ifstream &archivo, int desp){


    vector <char *> lista;

    int inicio= desp + superb.s_inode_start;

    lista.push_back("digraph G { rankdir=LR;");
        recorridoInodoRep(archivo,inicio,desp,&lista);
    lista.push_back("}");


    ofstream output_file("./REPORTES9/RepArbol.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }
    output_file.close();

    char*ufinal="dot -Tpdf ./REPORTES9/RepArbol.txt -o ./REPORTES9/RepArbol.pdf ";
    system(ufinal);
}





///busca de moento solo carpeta ruta
///finaliza con un inodo
///archivo para usar
///direccion es donde leera el  nuevo inodo
///valores lista de nombres de la ruta
///dezpla desplazamiento relativo a la particion
///bdir direccion del ultimo bloque leido
void recorridoInodoRep(ifstream &archivo ,int direccion, int dezpla , vector <char *> * lista){

        cout<<"Entra Rep Inodo"<<endl;
        inodo temp;

        archivo.seekg(direccion);
        archivo.read((char*)&temp, sizeof(inodo));

        ///sirve para ver si el inodo se leyo bien
        if((temp.i_type==1||temp.i_type==2)){
            ///valida que sea una carpeta
            if(temp.i_type==1){
                ///Escribe el inodo para el reporte
                conIndvIno(temp,direccion,lista, direccion);
                //cout<<"Es una carpeta"<<endl;
                ///inicia a ver si existen apuntadores creados en el inodo
                cout<<"PASA APUNTADOR EN INODO"<<endl;
                for(int i=0;i<12;i++){
                    if(temp.i_block[i]!=0){
                    cout<<"Esta en i:"<<i<<endl;

                    ///existe un apuntador bloque a carpeta o archivo
                    int posiciont=dezpla+temp.i_block[i];
                    cout<<"Salta DIRINODO ABS:"<<direccion<<endl;
                    cout<<"Salta DIRBLOQUE ABS:"<<posiciont<<endl;
                    (*lista).push_back(" node");
                    (*lista).push_back(intToCharP(direccion));
                    (*lista).push_back("->node");
                    (*lista).push_back(intToCharP(posiciont));
                    (*lista).push_back(" ");

                    if(i==0){
                        recorridoBloqueRep(archivo,posiciont,dezpla,lista,1);
                    }else{
                        recorridoBloqueRep(archivo,posiciont,dezpla,lista,0);
                    }


                        ///construir multiple apuntadores
                    }
                }

                ///si retorna aun no encuentra pasa a nodos simple , doble , y triple




                ///apundador simple
                cout<<"PASA APUNTADOR SIMPLE"<<endl;
                if((temp.i_block[12]!=0)){
                    int posiciont=dezpla+temp.i_block[12] ;
                    cout<<"Salta DIRINODO ABS 12:"<<direccion<<endl;
                    cout<<"Salta DIRIndire ABS 12:"<<posiciont<<endl;
                    recorridoBloqueIndirectoRep(archivo, posiciont ,dezpla,lista);
                }





                ///apuntador doble
                cout<<"PASA APUNTADOR DOBLE"<<endl;
                if((temp.i_block[13]!=0)){
                    BloqueApuntador tempx;

                    archivo.seekg(temp.i_block[13]);
                    archivo.read((char*)&tempx, sizeof(BloqueApuntador));

                    for(int i=0;i<16;i++){
                        if(tempx.b_pointers[i]!=0){
                            int posiciont=dezpla+tempx.b_pointers[i] ;
                            cout<<"Salta DIRINODO ABS 13:"<<direccion<<endl;
                            cout<<"Salta DIRIndire ABS 13:"<<posiciont<<endl;
                            recorridoBloqueIndirectoRep(archivo, posiciont ,dezpla,lista);


                        }
                    }

                }




                ///apuntador triple
                cout<<"PASA APUNTADOR TRIPLE"<<endl;
                if((temp.i_block[14]!=0)){

                    BloqueApuntador tempx;

                    archivo.seekg(temp.i_block[14]);
                    archivo.read((char*)&tempx, sizeof(BloqueApuntador));

                    for(int i=0;i<16;i++){
                        if(tempx.b_pointers[i]!=0){
                            BloqueApuntador tempx2;

                            archivo.seekg(tempx.b_pointers[i]);
                            archivo.read((char*)&tempx2, sizeof(BloqueApuntador));


                            for(int j=0;j<16;j++){
                                if(tempx2.b_pointers[j]!=0){
                                    int posiciont=dezpla+tempx2.b_pointers[j] ;
                                    cout<<"Salta DIRINODO ABS 14:"<<direccion<<endl;
                                    cout<<"Salta DIRIndire ABS 14:"<<posiciont<<endl;
                                    recorridoBloqueIndirectoRep(archivo, posiciont ,dezpla,lista);

                                }
                            }



                        }
                    }

                }


            }else{

                cout<<"Es un archivo"<<endl;
            }

        }else{
            cout<<"El inodo leido esta corrupto"<<endl;

        }




}



///verificar si todos vacios eliminar direccion
///en apuntadores varios 1 2 3
void recorridoBloqueIndirectoRep(ifstream &archivo ,int direccion, int dezpla , vector <char *> * lista ){


    BloqueApuntador temp;

    archivo.seekg(direccion);
    archivo.read((char*)&temp, sizeof(BloqueApuntador));

    conIndvBloIndirec(temp , direccion ,lista,direccion);

        ///inicia a ver si conincide el nombre y la ruta
        for(int i=0;i<16;i++){

            if(temp.b_pointers[i]!=0){

                int posiciont=dezpla+temp.b_pointers[i] ;
                cout<<"DIR INDI ABS:"<<direccion<<endl;
                cout<<"DIR BLO ABS:"<<posiciont<<endl;

                 (*lista).push_back(" node");
                    (*lista).push_back(intToCharP(direccion));
                    (*lista).push_back("->node");
                    (*lista).push_back(intToCharP(posiciont));
                    (*lista).push_back(" ");
                recorridoBloqueRep(archivo,posiciont,dezpla,lista,0);
            }
        }


}




void recorridoBloqueRep(ifstream &archivo ,int direccion,int dezpla , vector <char *> * lista ,int old){

        cout<<"Entra Bloque Rep"<<endl;
        BloqueCarpeta temp;

        archivo.seekg(direccion);
        archivo.read((char*)&temp, sizeof(BloqueCarpeta));

        ///sirve para ver si el bloque se leyo bien
        if((temp.b_content[0].b_inodo!=-1)||(temp.b_content[1].b_inodo!=-1)||(temp.b_content[2].b_inodo!=-1)||(temp.b_content[3].b_inodo!=-1)){

                ///escribe el bloque para reporte de arbol
                conIndvBlo(temp ,direccion , lista, direccion );

                ///inicia a ver si conincide el nombre y la ruta
                int camb=0;
                if(old==1){
                    camb=2;
                }
                for(int i=camb;i<4;i++){
                    if(temp.b_content[i].b_inodo!=-1){
                            int posiciont=dezpla+temp.b_content[i].b_inodo ;
                            cout<<"Nombre Bloque:"<<ArrtoCharP(temp.b_content[i].b_name) <<endl;
                            cout<<"Direcc a Inod:"<<temp.b_content[i].b_inodo <<endl;
                                (*lista).push_back(" node");
                                (*lista).push_back(intToCharP(direccion));
                                (*lista).push_back("->node");
                                (*lista).push_back(intToCharP(posiciont));
                                (*lista).push_back(" ");
                                 recorridoInodoRep(archivo ,posiciont, dezpla,lista);
                                 ///CONSTRUYE APUNTADORES A INODOS


                    }

                }

        }else{
            cout<<"El bloque leido esta corrupto"<<endl;

        }

}




















///pendientes


void repBloc(SB superb,ifstream &archivo, int desp){

    int bloquesUsa=(superb.s_blocks_count)-(superb.s_free_blocks_count);


    vector<char*>lista;

    int dir=desp+superb.s_block_start;
    int tami=sizeof(BloqueCarpeta);

    lista.push_back("digraph G { rankdir=LR;");
    cout<<"inicio bloques:"<<superb.s_block_start<<endl;
    cout<<"tamano bloque carpeta:"<<tami<<endl;
    cout<<"blo usados:"<<bloquesUsa<<endl;


    for(int i=0;i<bloquesUsa;i++){
        int dirT=dir+(i*tami);
        BloqueCarpeta temp;
        archivo.seekg(dirT);
        archivo.read((char*)&temp, tami);
        conIndvBlo(temp,i,&lista,dirT);
        lista.push_back(" \n");
    }

    for(int i=0;i<bloquesUsa;i++){
        lista.push_back("node");
        lista.push_back(intToCharP(i));
        lista.push_back("->node");
        lista.push_back(intToCharP((i+1)));
        lista.push_back(" \n");
    }
    lista.push_back("}");



    ofstream output_file("./REPORTES9/RepBloques.txt", ios::binary);

    for(int i=0;i<lista.size();i++){
        char*tempos=lista[i];
        int tamas=longitud(tempos);
            for(int j=0;j<tamas;j++){
                char ts=tempos[j];
                output_file.write((char*)&ts, sizeof(ts));
            }
    }
    output_file.close();

    char*ufinal="dot -Tpdf ./REPORTES9/RepBloques.txt -o ./REPORTES9/RepBloques.pdf ";
    system(ufinal);




}



void conIndvBlo(BloqueCarpeta inos,int i,vector <char *> * lista, int posm){

    char*gene="\"node";
    (*lista).push_back(gene);
    (*lista).push_back(intToCharP(i));
    gene="\" [label = \"{{Bloque_";
    (*lista).push_back(gene);
    (*lista).push_back(intToCharP(posm));
    gene=" |{{Nombre:| b_name0 | b_inodo0 | b_name1 | b_inodo1| b_name2 | b_inodo2| b_name3 | b_inodo3}|{Valor:|";
    (*lista).push_back(gene);

    cout<<"nombre:"<<(inos.b_content[0].b_name)<<endl;

    (*lista).push_back((ArrtoCharP(inos.b_content[0].b_name)));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.b_content[0].b_inodo));

    (*lista).push_back("|");
    (*lista).push_back(ArrtoCharP(inos.b_content[1].b_name));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.b_content[1].b_inodo));

    (*lista).push_back("|");
    (*lista).push_back(ArrtoCharP(inos.b_content[2].b_name));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.b_content[2].b_inodo));

    (*lista).push_back("|");
    (*lista).push_back(ArrtoCharP(inos.b_content[3].b_name));
    (*lista).push_back("|");
    (*lista).push_back(intToCharP(inos.b_content[3].b_inodo));


    (*lista).push_back("}}}}\"shape = \"record\"];\n");


}





void conIndvBloIndirec(BloqueApuntador inos,int i,vector <char *> * lista, int posm){

    char*gene="\"node";
    (*lista).push_back(gene);
    (*lista).push_back(intToCharP(i));
    gene="\" [label = \"{{BIndirecto_";
    (*lista).push_back(gene);
    (*lista).push_back(intToCharP(posm));
    gene=" |{{Nombre:| p0 | p1 | p2 | p3| p4 | p5 | p6 | p7 | p8 | p9 | p10 | p11 | p12 | p13 | p14 | p15 }|{Valor:|";
    (*lista).push_back(gene);

    for(int j=0;j<16;j++){
        if(j!=0){
            (*lista).push_back("|");
        }
        (*lista).push_back(intToCharP(inos.b_pointers[j]));
    }

    (*lista).push_back("}}}}\"shape = \"record\"];\n");

}



