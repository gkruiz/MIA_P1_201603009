


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
