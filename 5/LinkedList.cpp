#include "LinkedList.h"

LinkedList::LinkedList(): header{nullptr}, size{0} {
}

int LinkedList::getSize(){
    return size;
}


void LinkedList::print(){
    Node *tmp = header;
    std::cout<<"[";
    while(tmp != nullptr){
        std::cout << tmp->value << ",";
        tmp = tmp->next;
    }
    std::cout<<"]";
    std::cout<<std::endl;
    delete[] tmp;
}

LinkedList::Node* LinkedList::move_to_index(int index){
    Node *tmp = header;
    int at_index = 0;
    
    if (index <= getSize()){

        
        while(at_index != index){
            tmp = tmp->next;
            at_index++;
        }
        
    } else {
        tmp = nullptr;
    }
    return tmp;
}

bool LinkedList::insert(int index, int element){
    if (index <= getSize()){
        Node *new_node = new Node;
        new_node->value = element;
        new_node->next = nullptr;

        // dodawanie elementu na poczatek przy pustej liscie
        if (index == 0 && getSize() == 0){
            header = new_node;
            

        // dodawanie elementu na poczatek przy nie pustej liscie
        } else if (index == 0 && getSize() != 0){
            Node *tmp = header;
            header = new_node;
            new_node->next = tmp;
        // dodawanie elementu w dowolnym indexie
        } else if (index != 0){
            Node* previous = move_to_index(index-1);
            Node* tmp = previous->next;
            previous->next = new_node;
            new_node->next = tmp;

        }
        size++;
        return true;
    } else {

        std::cout<<"Index: "<< index << " jest poza rozmiarem tablicy: " << getSize()<<std::endl;
        std::cout<<"Ostatnim mozliwym jest: "<< getSize() <<std::endl;
        return false;
    }
}

bool LinkedList::remove(int index){
    Node *previous = move_to_index(index-1);
    Node *tmp = previous->next;
    previous->next = tmp->next;
    if(move_to_index(index) != tmp){
        size--;
        delete[] tmp;
        return true;
    } else {
        delete[] tmp;
        return false;
    }

};
int LinkedList::retrieve(int index){
    Node* tmp = move_to_index(index);
    if(tmp != nullptr) return tmp->value;
    else return -1;
};
int LinkedList::locate(int element){
    Node* tmp = header;
    int i = 0;
    while(tmp->value != element){
        // std::cout<<tmp->value<<std::endl;
        tmp = move_to_index(i);
        if(tmp == nullptr) return -1;
        i++;
    }

    return i;
};
bool LinkedList::empty(){};
int LinkedList::first(){}; // jesli nie ma elementu to nullptr
int LinkedList::front(){};
int LinkedList::last(){};
int LinkedList::back(){};
bool LinkedList::push_front(int element){};
bool LinkedList::push_back(int element){};
bool LinkedList::pop_front(){};
bool LinkedList::pop_back(){};
void LinkedList::del_all(int element){};
void LinkedList::del_duplicates(int element){};
void LinkedList::reverse(){};