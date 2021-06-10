

int recorridoBloque(ifstream archivo ,int direccion, vector <char *> valores );
int recorridoBloqueIndirecto(ifstream archivo ,int direccion, vector <char *> valores );
int recorridoInodo(ifstream archivo ,int direccion, vector <char *> valores );
void BusquedaRuta(PARTITION particion , SB superb, char * nombrearchivo);



void Wfolder(Login info){

    char * usuario=info.usuario;
    char * password=info.password;
    char * id=info.id;

    ///Verifica que SI exista una sesion abierta
    if(longitud(logueada.id)!=0){
        DiskMount infoP=RetMount(id);
        ///verifica que exista la particio montada
        if(infoP.let!=0){

            PARTITION pmontar=getPartitionL(infoP);
            ///inicia con obtener usuarios
            if(pmontar.part_start!=-1){
                SB superbloque = getSuperBloque(pmontar , infoP.path);

                if(superbloque.s_block_start!=-1){
                    ///Inicio obtiene datos de usuarios y grupos
                    int posiciont=sizeof(MBR)+pmontar.part_start+superbloque.s_block_start+sizeof(BloqueArchivo);
                    char * infoUsuarios=obtUsuarios(posiciont , infoP.path);
                    cout<<"SALE::::"<<infoUsuarios<<endl;
                    vector<char *> valores = splitC(infoUsuarios,'$');
                    vector<char *> usus=splitC(valores[1],',');
                    ///fin obtien datos de usuarios y grupos

                    if(Compare(usus[3],usuario)&&Compare(usus[4],password)){
                        cout<<"Usuario valido"<<endl;
                        logueada=info9;
                    }else{
                        cout<<"Informacion NO_valida"<<endl;
                    }

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





void BusquedaRuta(PARTITION particion , SB superb, char * nombrearchivo){

    char *nomarchivo=RPfd(nombrearchivo);
    SB superbloque;

    ifstream input_file(nomarchivo, ios::binary);
        if(input_file){
            input_file.seekg(particion.part_start+sizeof(MBR));

            input_file.read((char*)&superbloque, sizeof(superbloque));

        }else{
            cout<<"El disco no exite en la ruta almacenada del montaje"<<endl;
        }


    input_file.close();


}


///cuando eliminar validar que no queden bloques
///con todas las direcciones vacias


///busca de moento solo carpeta ruta
///finaliza con un inodo
int recorridoInodo(ifstream archivo ,int direccion, vector <char *> valores ){
    ///-2 significa error, -x si encontro , +x ahi nomas se quedo
    int retorna=-2;

    if(valores.size()>0){
        inodo temp;

        input_file.seekg(direccion);
        input_file.read((char*)&temp, sizeof(inodo));

        ///sirve para ver si el inodo se leyo bien
        if((temp.i_type==1||temp.i_type==2)){
            ///valida que sea una carpeta
            if(temp.i_type==1){

                ///inicia a ver si existen apuntadores creados en el inodo
                for(int i=0;i<12;i++){
                    if(temp.i_block[i]!=0){
                    ///existe un apuntador bloque a carpeta o archivo
                        retorna=recorridoBloque(archivo,temp.i_block[i],valores);

                        if(retorna!=-2){

                            break;
                        }

                    }
                }

                ///si retorna aun no encuentra pasa a nodos simple , doble , y triple




                ///apundador simple
                if((retorna==-2)&&(temp.i_block[12]!=0)){
                    retorna=recorridoBloqueIndirecto(archivo,temp.i_block[i],valores);
                }





                ///apuntador doble
                if((retorna==-2)&&(temp.i_block[13]!=0)){
                    BloqueApuntador tempx;

                    input_file.seekg(temp.i_block[13]);
                    input_file.read((char*)&tempx, sizeof(BloqueApuntador));

                    for(int i=0;i<16;i++){
                        if(tempx.i_block[i]!=0){
                            retorna=recorridoBloqueIndirecto(archivo,tempx.i_block[i],valores);
                            if(retorna!=-2){
                                break;
                            }
                        }
                    }

                }




                ///apuntador triple
                if((retorna==-2)&&(temp.i_block[14]!=0)){

                    BloqueApuntador tempx;

                    input_file.seekg(temp.i_block[14]);
                    input_file.read((char*)&tempx, sizeof(BloqueApuntador));

                    for(int i=0;i<16;i++){
                        if(tempx.i_block[i]!=0){
                            BloqueApuntador tempx2;

                            input_file.seekg(tempx.i_block[i]);
                            input_file.read((char*)&tempx2, sizeof(BloqueApuntador));


                            for(int j=0;j<16;j++){
                                if(tempx2.i_block[j]!=0){
                                    retorna=recorridoBloqueIndirecto(archivo,tempx2.i_block[j],valores);
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
int recorridoBloqueIndirecto(ifstream archivo ,int direccion, vector <char *> valores ){


    int retorna=-2;

    if(valores.size()>0){
        BloqueApuntador temp;

        input_file.seekg(direccion);
        input_file.read((char*)&temp, sizeof(BloqueApuntador));


                ///inicia a ver si conincide el nombre y la ruta
                for(int i=0;i<16;i++){

                    if(temp.b_pointers[i]!=0){
                        retorna=recorridoBloque(archivo,temp.b_pointers[i],valores);

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











int recorridoBloque(ifstream archivo ,int direccion, vector <char *> valores ){


    int retorna=-2;

    if(valores.size()>0){
        BloqueCarpeta temp;

        input_file.seekg(direccion);
        input_file.read((char*)&temp, sizeof(BloqueCarpeta));

        ///sirve para ver si el bloque se leyo bien
        if((temp.b_content[0]!=0)||(temp.b_content[1]!=0)||(temp.b_content[2]!=0)||(temp.b_content[3]!=0)){

                ///inicia a ver si conincide el nombre y la ruta
                for(int i=0;i<4;i++){
                    if(temp.b_content[i]!=0){
                        ///obtiene el nombre guardado en el bloque
                        char * nombenB=ArrtoCharP(temp.b_content[i].b_name);
                        if(Compare(nombenB,valores[0])){
                            ///parte de la ruta coincidio
                            vector<char *> cambVal=valores;
                            cambVal.pop_front();
                            retorna=recorridoInodo(archivo ,temp.b_content[i].b_inodo,cambVal)
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



























