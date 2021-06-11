

void UNMOUNTP(UNM info);
void EXECS(EXE info);
bool DiskExiParti(char* nomarchivo,char*nomParticion);
void MOUNTP(MOU info);
void RMELIMINA(RMD info);
vector <string> RutatoReal(char* ruta);
void MKcrea(MKD info);
void CMkfs(Mkfs info);
void Wfolder(Mkdir info);







DiskMount RetMount(char * id);
void Formateo(char *nomarchivo,int N ,PARTITION particion,MBR tempoMBR,int tipoforma);
PARTITION getPartitionL(DiskMount infoP);
SB getSuperBloque(PARTITION particion , char * nombrearchivo);
char * obtUsuarios(int pos,char * nombrearchivo);
void LoginSA(Login info);


void ClaComando(int com){

    //cout<<"Comando:"<<com<<endl;

    switch(com){
        case 1:
        ///MKDISK
        MKcrea(info1);
        break;
        case 2:
        ///RMDISK
        RMELIMINA(info2);
        break;
        case 3:
        ///FDISK
        FDISKCEM(info3);
        break;
        case 4:
        ///MOUNT
        MOUNTP(info4);
        break;
        case 5:
        ///UNMOUNT
        UNMOUNTP(info5);
        break;
        case 6:
        ///REP
        repo(info6);
        repo2(info6);
        repo3(info6);
        repo4();
        break;
        case 7:
        ///EXEC
        EXECS(info7);
        break;
        case 8:
        ///MKFS
        CMkfs(info8);

        break;
        case 9:
        ///MKFS
        LoginSA(info9);

        break;
        case 10:
        ///MKFS
        Wfolder(info10);

        break;
        case 20:
        ///PAUSE
        printf("ENTRO EN PAUSE------------------------------->>>");
            char n=0;
            cin>>n;
        break;


    }






}
