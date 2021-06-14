

/*DiskMount RetMount(char * id);
void Formateo(char *nomarchivo,int N ,PARTITION particion,MBR tempoMBR,int tipoforma);
PARTITION getPartitionL(DiskMount infoP);
SB getSuperBloque(PARTITION particion , char * nombrearchivo);
char * obtUsuarios(int pos,char * nombrearchivo);*/



void CMkfs(Mkfs info){

    /**
    ESTRUCTURA DE LOS BLOQUES
    EXT2:
    |SUPERBLOQUE | BIT_INODOS | BIT_BLOQUES | INODOS | BLOQUES|

    EXT3:
    |SUPERBLOQUE | JOURNALING | BIT_INODOS | BIT_BLOQUES | INODOS | BLOQUES|
    **/

    DiskMount infoP=RetMount(info.id);

    if(infoP.let!=0){
        MBR tempoMBR;

        char *nomarchivo=RPfd(infoP.path);
        ifstream input_file(nomarchivo, ios::binary);
        //Obtiene el MBR
        if(input_file){
            ///validar que exista el archivo
            input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
            ///compara los nombres de cada particion existente con el nuevo a asingar
            bool nom1=Compare(tempoMBR.particion1.part_name,infoP.name);
            bool nom2=Compare(tempoMBR.particion2.part_name,infoP.name);
            bool nom3=Compare(tempoMBR.particion3.part_name,infoP.name);
            bool nom4=Compare(tempoMBR.particion4.part_name,infoP.name);
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
                nom5=validaNombres(leidos,infoP.name);
            }
            //cierra el documento
            input_file.close();

            ///Inicia el analisis de la particion

            PARTITION pmontar;

            if(nom1&&(!ind1)){
                pmontar=tempoMBR.particion1;
            }else if(nom2&&(!ind2)){
                pmontar=tempoMBR.particion2;
            }else if(nom3&&(!ind3)){
                pmontar=tempoMBR.particion3;
            }else if(nom4&&(!ind4)){
                pmontar=tempoMBR.particion4;
            }else if((nom1&&(ind1))||(nom2&&(ind2))||(nom3&&(ind3))||(nom4&&(ind4))){
                cout<<"No se puede montar un sistema de archivos en una particion Extendida"<<endl;
            }else if(nom5){
                cout<<"No se puede montar un sistema de archivos en una particion Logica"<<endl;
            }else{
                cout<<"La particion no existe en el disco duro"<<endl;
            }

            cout<<"INICIA CALCULOS"<<endl;
            ///inicia con los calculos de los bloques
            if(pmontar.part_start!=-1){
                int tipoSis=info.fs;
                int formateo=info.type;

                ///valores Formula
                const int inod=sizeof(inodo);
                const int bloc=sizeof(BloqueCarpeta);///verificar
                const int sblo=sizeof(SB);
                //const int sblo=sizeof();
                int T_Particion=pmontar.part_size;

                ///VALOR MINIMO DE UNA PARTICION PONER EN FDISCK
                ///TAMBIEN VERIFICAR SI YA ESTA FORMATEADO CON ALGUN SISTEMA ARCHIVOS
                const int deno= 4+inod+(3*bloc);
                const int deno2= 4+inod+(3*bloc);///mas tamano del journaling
                const int numera= T_Particion-sblo;




                if(tipoSis==1){
                    cout<<"Montara EXT2"<<endl;
                    ///Es EXT2
                    if(numera>=deno){
                        ///Si se puede guardar el sistema de archivos EXT2
                        int residuo=numera%deno;
                        ///Es el numero de bloques
                        int N=(numera-residuo)/deno;
                        ///Salta a la construccion de los inodos y el formateo del sistema de archivos
                        Formateo(nomarchivo ,N ,pmontar, tempoMBR,info.type);

                    }else{
                        cout<<"Hace falta espacio para poder formatear la particion a ext2"<<endl;
                    }

                }else{
                    ///Es EXT3
                    cout<<"Montara EXT3"<<endl;
                    if(numera>=deno2){
                        ///Si se puede guardar el sistema de archivos EXT3
                        int residuo=numera%deno;
                        ///Es el numero de bloques
                        int N=(numera-residuo)/deno;
                        ///Salta a la construccion de los bloques y el formateo del sistema de archivos


                    }else{
                        cout<<"Hace falta espacio para poder formatear la particion a ext3"<<endl;
                    }

                }

            }


        }else{
            cout<<"El disco no exite en la ruta almacenada del montaje"<<endl;
        }

    }else{

        cout<<"La particion no esta montada en el sistema"<<endl;
    }







}



///Busca el disco montado en el sistema
DiskMount RetMount(char * id){

    vector <DiskMount> Montadas=getMontadas();
    DiskMount retorna;

    for(int i=0;i<Montadas.size();i++){
        DiskMount temp=Montadas[i];
        char *p1="09";
        char *p2=intToCharP(temp.num);
        char *p3=chaToCharP(temp.let);

        char *u1=UneChar(p1,p2);
        char *u2=UneChar(u1,p3);

        if(Compare(u2,id)){
            ///Encontro el id
            retorna=temp;
            break;
        }
    }
    ///retorna uno limpio si no lo encontro
    return retorna;

}




void Formateo(char *nomarchivo,int N ,PARTITION particion,MBR tempoMBR,int tipoforma){

    time_t now = time(0);
    ///todas son direcciones relativas a la particion
    SB superBloque;
    superBloque.s_filesystem_type=1;
    superBloque.s_inodes_count=N;           ///todos los inodos
    superBloque.s_blocks_count=3*N;         ///todos los bloques
    superBloque.s_free_inodes_count=N-2;    ///-2 porque usa dos al formatear
    superBloque.s_free_blocks_count=(3*N)-2;/// lo mismo 2 bloques usados
    superBloque.s_mtime=0;
    superBloque.s_umtime=0;
    superBloque.s_mnt_count=1;
    superBloque.s_magic=0xEF53;
    superBloque.s_inode_size=N*sizeof(inodo);///tamano del bloque inodo
    superBloque.s_block_size=3*N*sizeof(BloqueApuntador);///tamano del bloque bloques
    superBloque.s_first_ino=(sizeof(SB)+N+(3*N))+(2*sizeof(inodo));             ///apunta ultimo inodo libre
    superBloque.s_first_blo=(sizeof(SB)+N+(3*N)+(N*sizeof(inodo)))+(2*sizeof(BloqueCarpeta));///apunta ultimo bloque libre
    ///calculo inicio bitmap inodos ,empieza al final del superbloque
    superBloque.s_bm_inode_start=sizeof(SB);
    superBloque.s_bm_block_start=sizeof(SB)+N;
    superBloque.s_inode_start=sizeof(SB)+N+(3*N);
    superBloque.s_block_start=sizeof(SB)+N+(3*N)+(N*sizeof(inodo));




    ///Primer inodo, inodo carpeta
    inodo primero;
    primero.i_uid=0;    ///usuario propietario
    primero.i_gid=0;    ///grupo al que pernece propietario
    primero.i_size=0;   ///tamano del archivo
    primero.i_atime=0;  ///fecha de ultima lectura
    primero.i_ctime=now;///fecha creacion
    primero.i_block[0]=superBloque.s_block_start;///Primer apuntador va al primer bloque
    primero.i_type=1;///es una carpeta
    primero.i_perm=777;///Permisos




    Content info;
    BloqueCarpeta carpeta;

    ///Apuntador inodo padre:
    char*text="-1";
    strcpy(info.b_name, text);
    info.b_inodo=-1;
    carpeta.b_content[0]=info;

    ///Apuntador inodo Origen:
    text="/";
    strcpy(info.b_name, text);
    info.b_inodo=superBloque.s_inode_start;
    carpeta.b_content[1]=info;

    ///Apuntador inodo hijo:
    text="users.txt";
    strcpy(info.b_name, text);
    info.b_inodo=superBloque.s_inode_start+sizeof(inodo);
    carpeta.b_content[2]=info;

    ///informacion a guardar
    char * informacion="1,G,root$1,U,root,root,123$                                    ";
    int tamano=longitud(informacion);

    ///Inodo archivo usuarios.txt
    inodo archi;
    archi.i_uid=0;      ///usuario propietario
    archi.i_gid=0;      ///grupo al que pernece propietario
    archi.i_size=tamano;///tamano del archivo
    archi.i_atime=0;    ///fecha de ultima lectura
    archi.i_ctime=now;  ///fecha creacion
    archi.i_block[0]=superBloque.s_block_start+sizeof(BloqueArchivo);     ///van los apuntadores
    archi.i_type=2;     ///es un archivo
    archi.i_perm=777;     ///Permisos


    BloqueArchivo arch;
    strcpy(arch.b_content, informacion);///guarda la info en array 64
    arch.b_content[tamano]=0;///para definir el final de texto


    ///los tamanos de los array son pequenos porque
    ///si N muy grande error

    ///bitmap inodos
    bool ar[3]={0};
    ar[0]=1;
    ar[1]=1;
    ar[2]=0;
    ///bitmap bloques
    bool ar2[3]={0};
    ar2[0]=1;
    ar2[1]=1;
    ar2[2]=0;
    ///formatea la particion
    FormateaParticion(particion.part_start , particion.part_size,nomarchivo,tempoMBR,tipoforma);

    ///inicia a guardar la informacion

    ///direcciones reales
    int isbl=particion.part_start+sizeof(MBR);
    int ibin=isbl+sizeof(SB);
    int ibbl=ibin+N;
    int iino=ibbl+(3*N);
    int iblo=iino+(N*sizeof(inodo));

    cout<<"superbloque:"<< isbl<<endl;
    cout<<"bitinodo:"<< ibin<<endl;
    cout<<"bitbloque:"<< ibbl<<endl;
    cout<<"inidos:"<< iino<<endl;
    cout<<"bloques:"<< iblo<<endl;



	 	ofstream output_file(nomarchivo, ios::in);
        ///escribe el superbloque
	 	output_file.seekp(isbl);
        output_file.write((char*)&superBloque, sizeof(superBloque));
        ///escribe el bitmap inodos
        output_file.seekp(ibin);
        output_file.write((char*)&ar, sizeof(ar));
        ///escribe el bitmap bloques
        output_file.seekp(ibbl);
        output_file.write((char*)&ar2, sizeof(ar2));
        ///escrible los inodos
        output_file.seekp(iino);
        output_file.write((char*)&primero, sizeof(primero));

        output_file.seekp(iino+sizeof(inodo));
        output_file.write((char*)&archi, sizeof(archi));

        ///escribe los bloques
        output_file.seekp(iblo);
        output_file.write((char*)&carpeta, sizeof(carpeta));

        output_file.seekp(iblo+sizeof(BloqueArchivo));
        output_file.write((char*)&arch, sizeof(arch));



	 	output_file.close();



}




void LoginSA(Login info){

    char * usuario=info.usuario;
    char * password=info.password;
    char * id=info.id;

    ///Verifica que no exista una sesion abierta
    if(longitud(logueada.id)==0){
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
        cout<<"Ya existe una sesion activa"<<endl;
    }




}




SB getSuperBloque(PARTITION particion , char * nombrearchivo){

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

    return superbloque;

}



char * obtUsuarios(int pos,char * nombrearchivo){

    char *nomarchivo=RPfd(nombrearchivo);
    BloqueArchivo barchivo;
    char * retorna=0;

    ifstream input_file(nomarchivo, ios::binary);
        if(input_file){
            input_file.seekg(pos);
            input_file.read((char*)&barchivo, sizeof(barchivo));
            retorna=ArrtoCharP(barchivo.b_content);
        }else{
            cout<<"El disco no exite en la ruta almacenada del montaje"<<endl;
        }

    input_file.close();

    return retorna;

}





PARTITION getPartitionL(DiskMount infoP){
///Rertorna particiones primarias
///se usa para login
MBR tempoMBR;
PARTITION pmontar;

        char *nomarchivo=RPfd(infoP.path);
        ifstream input_file(nomarchivo, ios::binary);
        //Obtiene el MBR
        if(input_file){
            ///validar que exista el archivo
            input_file.read((char*)&tempoMBR, sizeof(tempoMBR));
            ///compara los nombres de cada particion existente con el nuevo a asingar
            bool nom1=Compare(tempoMBR.particion1.part_name,infoP.name);
            bool nom2=Compare(tempoMBR.particion2.part_name,infoP.name);
            bool nom3=Compare(tempoMBR.particion3.part_name,infoP.name);
            bool nom4=Compare(tempoMBR.particion4.part_name,infoP.name);
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
                nom5=validaNombres(leidos,infoP.name);
            }
            //cierra el documento
            input_file.close();

            ///Inicia el analisis de la particion



            if(nom1&&(!ind1)){
                pmontar=tempoMBR.particion1;
            }else if(nom2&&(!ind2)){
                pmontar=tempoMBR.particion2;
            }else if(nom3&&(!ind3)){
                pmontar=tempoMBR.particion3;
            }else if(nom4&&(!ind4)){
                pmontar=tempoMBR.particion4;
            }else if((nom1&&(ind1))||(nom2&&(ind2))||(nom3&&(ind3))||(nom4&&(ind4))){
                cout<<"La particion seleccionada es una particion Extendida"<<endl;
            }else if(nom5){
                cout<<"La particion seleccionada es una particion Logica"<<endl;
            }else{
                cout<<"La particion no existe en el disco duro"<<endl;
            }








        }else{
            cout<<"El disco no exite en la ruta almacenada del montaje"<<endl;
        }




    return pmontar;

}










