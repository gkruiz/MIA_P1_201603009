

int recorridoBloque(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int recorridoBloqueIndirecto(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int recorridoInodo(ifstream &archivo ,int direccion, vector <char *> * valores ,int dezpla,int * bdir );
int BusquedaRuta(PARTITION particion , char * nombrearchivo ,char * ruta);



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



























