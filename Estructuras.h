
struct PARTITION{

	char part_status=0;
	char part_type=0;
	char part_fit=0;
	int part_start=-1;
	int part_size=0;
	char part_name[16]={0};

};



struct MBR{
	int mbr_tamano=0;
	time_t mbr_fecha_creacion;
	int mbr_disk_signature=0;
	char disk_fit=0;

	PARTITION particion1;
	PARTITION particion2;
	PARTITION particion3;
	PARTITION particion4;
};








struct EBR{

	char part_status=0;
	char part_type=0;
	char part_fit=0;
	int part_start=-1;
	int part_size=0;
	int part_next=-1;
	char part_name[16]={0};

};




struct StartSize{
int start=-1;
int size=0;
int posi=-1;
char type=0;
};


///Estructuras Sistema de archivos

struct DiskMount{

    char *path=0;
	char *name=0;
	int num=0;
	char let=0;

};



struct SB{

    int s_filesystem_type=-1;

    int s_inodes_count=-1;
    int s_blocks_count=-1;
    int s_free_blocks_count=-1;
    int s_free_inodes_count=-1;

    time_t s_mtime;
    time_t s_umtime;
    int s_mnt_count=-1;
    int s_magic=-1;
    ///dimensiones de los bloques
    int s_inode_size=-1;
    int s_block_size=-1;

    int s_first_ino=-1;
    int s_first_blo=-1;
    ///posiciones bloques
    int s_bm_inode_start=-1;
    int s_bm_block_start=-1;
    int s_inode_start=-1;
    int s_block_start=-1;

};






struct inodo{
int i_uid=-1;
int i_gid=-1;
int i_size=-1;
time_t i_atime=-1;
time_t i_ctime=-1;
time_t i_mtime=-1;
int i_block[15]={0};
char i_type=-1;     ///1 es carpeta 2 es archivo , pedia 0 y 1 , pero para distinguir si vacio o nulo
int i_perm=-1;


};

struct Content{

    char b_name[12]={0};
    int b_inodo=-1;

};


struct BloqueCarpeta{

    Content b_content[4];

};


struct BloqueArchivo{

    char b_content[64]={0};

};


struct BloqueApuntador{

    int b_pointers[16]={0};

};




struct nodo{
    nodo * sig=0;
    DiskMount info;
};




















