/*
    Dowolna funkcja haszująca, trzeba samemu wybrać
    NIe trzeba się trzymać nie wiadomo jak bardzo implementacji
    Zastanowić się jak dodajemy kolejne elementy o tym samym hashu
    czy dodajemy na koniec czy na początek


*/

#include "Hash.h"
#include <iostream>
using namespace std;

int main(){


    Hash* table = new Hash(10);
    // table->insert(1);
    for(int i=0; i<100; i++){
        table->insert(i);
    }
    table->print();
    table->remove(99);
    table->remove(1);
    table->remove(5);
    table->remove(55);
    table->print();
    cout<<"CONTAINS(26): "<<table->contains(26)<<endl;
    cout<<"CONTAINS(33): "<<table->contains(33)<<endl;
    cout<<"CONTAINS(99): "<<table->contains(99)<<endl;
    cout<<"CONTAINS(55): "<<table->contains(55)<<endl;
    cout<<"CONTAINS(22): "<<table->contains(22)<<endl;
    table->makeEmpty();
    table->print();

}