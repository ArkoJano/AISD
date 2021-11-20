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

    if(!empty()){
        if(index != 0){
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
        
        } else {
            Node* tmp = header->next;
            delete[] header;
            header = tmp;
            size--;
            return true;
        }
    } else {
        return false;
    }

};
int LinkedList::retrieve(int index){
    if(!empty()){
        Node* tmp = move_to_index(index);
        if(tmp != nullptr) return tmp->value;
        else return -1; 
    } 
    return -1;
};
int LinkedList::locate(int element){
    if(!empty()){
        Node* tmp = header;
        int i = 0;
        while(tmp->value != element){
            tmp = move_to_index(i);
            if(tmp == nullptr) return -1;
            i++;
        }
    if(i == 0) return 0;
    return i-1;
    }
    return -1;
};
bool LinkedList::empty(){
    if (header == nullptr) return true;
    return false;
};
// jesli nie ma elementu to nullptr
LinkedList::Node* LinkedList::first(){
    if(!empty()) return header;
    else return nullptr;

}; 
int LinkedList::front(){
    if(!empty()) return header->value;
    else return -1;
};
LinkedList::Node* LinkedList::last(){
    if(!empty()) {
        Node* tmp = move_to_index(getSize()-1);
        return tmp;
    }
    else return nullptr;
};
int LinkedList::back(){
    if(!empty()) {
        Node* tmp = move_to_index(getSize()-1);
        return tmp->value;
    }
    else return -1;
};
int LinkedList::len(){
    return getSize();
}
bool LinkedList::push_front(int element){
    return insert(0, element);
};
bool LinkedList::push_back(int element){
     return insert(getSize(), element);
};
bool LinkedList::pop_front(){
    return remove(0);
};
bool LinkedList::pop_back(){
    return remove(getSize()-1);
};
void LinkedList::del_array(){
     if(!empty()){
        int i = getSize();
        while(i != 0){
            Node* tmp = header;
            header = header->next;
            i--;
            delete[] tmp;
            size--;
        }

    }
};

void LinkedList::del_all(int element){
    if(!empty()){
        while(locate(element) != -1){
            int index = locate(element);
            remove(index);
        }

    }
};

void LinkedList::del_duplicates(int element){
   if(!empty()){
        Node* tmp = header;
        int i = 0, counter = 0;
        while(tmp != nullptr){
            if(tmp->value == element){
                if(counter == 0) { 
                    counter++;
                } else {
                    remove(i);
                }
            }
            tmp = tmp->next;
            i++;
        }
        delete[] tmp;
   }
};
void LinkedList::reverse(){
    Node* tmp = header;
    Node* next = nullptr;
    Node* prev = nullptr;
    while(tmp != nullptr){
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
    }
    header = prev;

    delete[] tmp, next, prev;

};

// void LinkedList::del_odd_indexes(){
//     if(!empty()){
//         Node* tmp = header;
//         Node* prev = nullptr;
//         Node* next = tmp->next;
//         int counter = 0;
//         while(tmp != nullptr){
//             if(counter % 2 == 0){

//             }
//     }
// }

void LinkedList::del_odd_indexes(){
    Node* tmp = header;
    Node* prev = nullptr;

    int i = 0, counter = 0;
    while(tmp != nullptr){
        
        if(counter % 2 == 0) { 
            if(counter != 0){
                prev->next = tmp->next;
                delete[] tmp;
                tmp = prev->next;

            } else {
                header = header->next;
                delete[] tmp;
                tmp = header;
            }
            size--;
        } else {

            prev = tmp;
            tmp = tmp->next;
        }
        counter++;
        // std::cout<< "prev: " << prev->value << " tmp: " << tmp->value <<std::endl;
    }
    // delete[] tmp;
}

// void LinkedList::del_odd_indexes(){
//     if(!empty()){
//         int i = 0;
//         while(i <= getSize()){
//             if(i % 2 == 0){
//                 remove(locate(move_to_index(i)->value));
//                 i--;
//             }
//             i++;
//         }
//     }
// }