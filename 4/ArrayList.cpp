#include "ArrayList.h"
using namespace std;

ArrayList::ArrayList(int size): size{size}, first_position{0}, 
last_position{0}, empty_places{size}  {
    array = new int[size];
}

ArrayList::~ArrayList(){
    delete[] array;
}

void ArrayList::print(){
    cout<<"[";
    for(int i=0; i<size; i++){
        if(i == size-1) cout<<array[i];
        else cout<<array[i]<<",";
    }
    cout<<"]";
    cout<<endl;
}

int ArrayList::getSize(){
    return size;
}

int ArrayList::emptyPlaces(){
    return empty_places;
}

void ArrayList::reSize(){
    int* tmp = new int[size];
        for(int i=0; i<size; i++){
            tmp[i] = array[i];
        } 

        empty_places += size;
        size *= 2;
        array = new int[size];

        for(int i=0; i<size/2; i++){
            array[i] = tmp[i];
        }

        

        delete[] tmp;
}

bool ArrayList::insert(int index, int element){
    
    if(index >= size){
        reSize();
    }

    int if_empty = array[index];
    int tmp = array[index];
    array[index] = element;
    array[index+1] = tmp;
    
    if(index < first_position){
        first_position = index;
    }

    if(index > last_position){
        last_position = index;
    }

    for(int i=index+1; i<size; i++){
        
        tmp = array[i];
        array[i] = tmp;
    }

    if(array[index] == element) {
        if( if_empty == 0){
            empty_places--;

        }
        return true;
    } else {
        return false;
    }
}

bool ArrayList::remove(int index){
    
    for(int i=index; i<size; i++){
        array[i] = array[i+1];
    }
    empty_places++;
    array[size-1] = 0;

    
    if(index < size){
        last_position--;
        return true;
    } else {
        return false;
    }

}

int ArrayList::retrieve(int index) {
    
    if(index <= size) return array[index];    
    return -1;
}
int ArrayList::locate(int element) {

    for(int i=0; i<size; i++){
        if( array[i] == element){
            return i;
        }
    }

    return size;
}
int ArrayList::end() {return size;}
int ArrayList::first() {return first_position;}
int ArrayList::next(int index) {
    
    if(index < size+1) return index+1;
    else return -1;
}
int ArrayList::previous(int index) {return index-1;}
int ArrayList::last() {    
    return last_position;
}
int ArrayList::back() {
    return array[last_position];
}
bool ArrayList::push_front(int element) {


    if(last_position == size-1){
        reSize();
    }


    for(int i=size-1; i>0; i--){
        array[i] = array[i-1];
    }

    array[0] = element;
    empty_places--;
    last_position++;

    if(array[0] == element) return true;
    return false;
}
bool ArrayList::push_back(int element) {

    if(last_position == size-1){
        reSize();
    }

    array[last_position+1] = element;

    if(array[last_position+1] == element){
        empty_places--;
        last_position++;
        
        return true;
    }    
    return false;
}
bool ArrayList::pop_front() {

    remove(0);

    return true;
    
}
bool ArrayList::pop_back() {
    
    remove(last_position);
    return true;
}

void ArrayList::del_all(int element){
    for(int i=0;i<size;i++){
        if( array[i] == element ){
            remove(i);
        }
    }
}

void ArrayList::del_duplicates(int element){
    int counter = 0;
    for(int i=0;i<size;i++){
        if( array[i] == element ){
            if(counter != 0) {
                remove(i);
                i--;
            }
        counter++;                       
        }

    }
}

void ArrayList::reverse(){
    int tmp;
    for(int i=0; i<size/2;i++){
        tmp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = tmp;
    }
}
