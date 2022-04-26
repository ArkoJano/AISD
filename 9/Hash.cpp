#include "Hash.h"
using namespace std;

Hash::Hash(int _size){
    size = _size;
    head = new Node*[size];
    for(int i=0; i<size; i++){
        head[i] = NULL;
    }
}

Hash::~Hash(){
    delete[] head;
}

int Hash::hash(const int &element){
    return element % size;
}

bool Hash::insert(const int & element){
    int elementHash = hash(element);
    Node* newNode = new Node();
    newNode->element = element;
    newNode->key = elementHash;
    newNode->next = nullptr;

    if( head[elementHash] == nullptr ){
        // cout<<"Wstawiam jako pierwszy: "<< element<<endl;
        head[elementHash] = newNode;
        return true;
    // wstawiamy na nowy element na koniec
    } else {
        Node* current = head[elementHash];
        while (current->next != nullptr){
            current = current->next;
        }        
        current->next = newNode;
        return true;
        // cout<<"Wstawiam jako kolejny: "<< element<<endl;
    }

    return false;
}

bool Hash::remove(const int &element){
    int elementHash = hash(element);
    Node* current = head[elementHash];

    
    if(current != nullptr){
        if ( current->element == element){
            head[elementHash] = current->next;
            delete[] current;
            return true;
        }
        Node* previous = current;
        current = current->next;

        while (current != nullptr && current->element != element){
            previous = previous->next;
            current = current->next;
        }

        if(current == nullptr){
            return false;
        }

        previous->next = current->next;
        delete[] current;    
        return true;    


    }
    return false;
}

bool Hash::contains(const int &element){
    int elementHash = hash(element);
    Node* current = head[elementHash];
    while (current->next != nullptr){
        if(current->next->element == element) return true;
        current = current->next;
    }
    return false; 
};

void Hash::makeEmpty(){
    for(int i=0;i<size;i++){
        Node* current = head[i];
        Node* next = NULL;
    
        while (current != NULL)
        {
            next = current->next;
            free(current);
            current = next;
        }
    
        head[i] = nullptr;
    }

}

void Hash::print(){
    cout<<"KEY:"<<endl;
    int elementHash;
    Node* current;
    for (int i = 0; i < size; i++) {
        cout<< " | " << i << " | ";
        elementHash = hash(i);
        current = head[elementHash];
        if( current != nullptr){
            while(current->next != nullptr){
                cout<< " ---> " << current->element; 
                current = current->next;
            }
            cout<< " ---> " << current->element; 

            
        }
        cout<<endl<< "  ---  "<<endl;
  }
}