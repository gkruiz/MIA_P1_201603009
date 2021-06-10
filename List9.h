





vector <DiskMount> getMontadas(){

    vector <DiskMount> mm;

    nodo * temp=PMontadas;

    while((temp)!=0){
        mm.push_back(temp->info);
        temp=temp->sig;
    }

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
        //cout<<i<<endl;

        if(i>0){
            susti->sig=tempo;
        }else{
            PMontadas=tempo;
        }

        susti=tempo;

        i++;
    }

}




