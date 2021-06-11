
struct  MKD{

	int size=0;//positivo *
	int fit=2;//bf ff wf
	int unit=2;//k m *
	char *path=0;//*

};


struct  RMD{

	char *path=0;//*

};


struct  FDI{

	int size=0;//positivo>0 *al crear
	int unit=2;// b k m
	char *path=0;//*
	int type=1;// P E L
	int fit=3;// bf ff wf
	int delet=0;//fast full , name y path juntos
	char *name=0;//*
	int add=0;//positivo o negativo

};



struct  MOU{

	char *path=0;//*
	char *name=0;//*
};


struct  UNM{

	char *id=0;//*

};

struct  RE{

	int name=0;//-mbr -disk *
	char *path=0;//*
	char *id=0;//*

};



struct  EXE{

	char *path=0;//*


};





///SEGUNDA FASE




struct Mkfs{

    char * id=0;/**asdf**/
    int type=2;///Fast=1 ,Full=2
    int fs=1;  ///1Ext2 ,2Ext3

};




struct Login{
    char * usuario=0;
    char * password=0;
    char * id=0;
};






struct Mkdir{
    char * path=0;
    char p=0;
};


