

void AnalisisH(char * lineaCD);
void LimpiaStructs();
void MultiLinea(char * lineaCD);

void Consol(){

    char * mensaje="Manejo e Implementacion de Archivos /// Universidad de San Carlos de Guatemala ///2021\n\r";
    char * mensaje2="Kevin Golwer Enrique Ruiz Barbales 201603009\n\r";
    char * mensaje3="Ingrese el comando:\n\r\n\r";

    char opcion=0;
    while(true){
        void LimpiaStructs();
        opcion=0;

        cout<<mensaje;
        cout<<mensaje2;
        cout<<mensaje3;

            string entCom;
            //cin.ignore();
            getline(cin, entCom, '\n');

            char *temp=stringtocharp(entCom);
            int tam=longitud(temp);
            char *nues=(char*)malloc((tam+1)*sizeof(char));
            nues[tam]=0;

            for(int i=0;i<tam;i++){
                nues[i]=tolower(temp[i]);
            }


            AnalisisH(nues);

    }


}

void LimpiaStructs(){
    ClStru(1,&info1);
    ClStru(2,&info2);
    ClStru(3,&info3);
    ClStru(4,&info4);
    ClStru(5,&info5);
    ClStru(6,&info6);
    ClStru(7,&info7);
}


void AnalisisH(char * lineaCD){
    ofstream output_file("Code", ios::binary);
    output_file.write((char*)lineaCD, longitud(lineaCD));
    output_file.close();

    cout<<"comando:"<<lineaCD<<endl;

    FILE* in;
    in=fopen("Code","r");
    yyrestart(in);
    yyparse();
    fclose(in);


}




