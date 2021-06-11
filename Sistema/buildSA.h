

int recorridoBloque(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int recorridoBloqueIndirecto(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int recorridoInodo(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int BusquedaRuta(PARTITION particion , char * nombrearchivo ,char * ruta);
int busApuLibreInodo(ifstream &input_file , inodo ino , int desp,char * tipo);


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

                if(superbloque.s_block_start!=-1){
                    ///Inicio obtiene datos de usuarios y grupos

                    int regre= BusquedaRuta(pmontar,infoP.path,info.path);
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





int BusquedaRuta(PARTITION particion ,char * nombrearchivo,char * ruta){

    char *nomarchivo=RPfd(nombrearchivo);
    SB superbloque;
    vector <char *> carpe=splitC(ruta,'/');
    int * bdireccion=(int *)malloc(sizeof(int));
    (*bdireccion)=0;


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
                    retorna=recorridoInodo(input_file , posiciont , &carpe , dezplaza , bdireccion);
                    cout<<retorna<<endl;
                    for(int i=0;i<(carpe.size());i++){
                        cout<<carpe[i]<<endl;
                    }
                    cout<<(*bdireccion)<<endl;


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
void buildMulPath(ifstream &archivo , int dirBlo ,int dirAbsIno,vector <char *> * valores , int desp){

    ///toda la ruta no esta construida
    if(dirBlo==0){
        inodo temp;
        archivo.seekg(dirAbsIno);
        archivo.read((char*)&temp, sizeof(inodo));

        if((temp.i_type==1)||(temp.i_type==2)){
            char * tp=(char*)malloc(sizeof(char));
            int res= busApuLibreInodo(archivo, temp , desp,tp);

            if(((*tp)==1)&&(res!=-1)){
            ///en apuntador carpeta

            }else if(((*tp)==2)&&(res!=-1)){
            ///en el inodo apuntador

            }else if(((*tp)==3)&&(res!=-1)){
            ///en primer apuntador indirecto , primer nivel

            }else if(((*tp)==4)&&(res!=-1)){
            ///en segundo apuntador indirecto , primer nivel

            }else if(((*tp)==5)&&(res!=-1)){
            ///en segundo apuntador indirecto , segundo nivel

            }else if(((*tp)==6)&&(res!=-1)){
            ///en tercer apuntador indirecto , primer nivel

            }else if(((*tp)==7)&&(res!=-1)){
            ///en tercer apuntador indirecto , segundo nivel

            }else if(((*tp)==8)&&(res!=-1)){
            ///en tercer apuntador indirecto , tercer nivel

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

        if((temp.b_content[0].b_inodo!=0)&&(temp.b_content[1].b_inodo!=0)){
            ///verifica espcio libre
            if((temp.b_content[2].b_inodo==0)||(temp.b_content[3].b_inodo==0)){
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
            if(temp.b_pointers[i]==0){
                retorna=ino.i_block[13];
                (*tipo)=4;
                break;
            }else{
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

                ///inicia a ver si existen apuntadores creados en el inodo
                for(int i=0;i<12;i++){
                    if(temp.i_block[i]!=0){
                    ///existe un apuntador bloque a carpeta o archivo
                    int posiciont=dezpla+temp.i_block[i];
                        retorna=recorridoBloque(archivo,posiciont,valores,dezpla,bdir);

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



            }

        }else{
            cout<<"El inodo leido esta corrupto"<<endl;

        }


    }else{
        retorna=-1*direccion;
        cout<<"Fin lectura"<<endl;
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
        cout<<"Fin lectura bloqueIndirecto?"<<endl;
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
                        if(Compare(nombenB,(*valores)[0])){
                            ///guarda la ultima direccion del bloque leido
                            (*bdir)=direccion;
                            ///parte de la ruta coincidio
                            vector<char *> cambVal=(*valores);
                            pop_front(cambVal);
                            (*valores)=cambVal;
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
        cout<<"Fin lectura bloque?"<<endl;
    }

    return retorna;

}



























