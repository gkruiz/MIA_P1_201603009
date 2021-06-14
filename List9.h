





vector <DiskMount> getMontadas(){

 //cout<<"antes"<<endl;
    vector <DiskMount> mm;

    nodo * temp=PMontadas;

    while((temp)!=0&&temp>0){
        DiskMount temporal;
        temporal=temp->info;
        //cout<<"sale ruta:"<<((temp->info).path)<<endl;
        //cout<<"sale direc:"<<((temp))<<endl;
        if(longitud(temporal.path)>0){
            mm.push_back(temporal);
        }

        temp=temp->sig;

    }
 //cout<<"despues"<<endl;
    return mm;
}



void upMontadas(vector <DiskMount> lista){

    int tm=lista.size();

    PMontadas = 0;
    int i=0;
    nodo * susti=0;


    while((tm)!=i){

        nodo * tempo=(nodo*)malloc(sizeof(nodo));
        tempo->info=lista[i];
        //cout<<"asdf:"<<i<<endl;

        if(i>0){
            susti->sig=tempo;
        }else{
            tempo->sig=0;
            PMontadas=tempo;
        }

        susti=tempo;

        i++;
    }

}




