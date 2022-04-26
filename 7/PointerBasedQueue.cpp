#include "PointerBasedQueue.h"



PointerBasedQueue::PointerBasedQueue(){
    header = new Node();
    size = 0;
    front = header;
    rear = header;

}

PointerBasedQueue::~PointerBasedQueue(){
    
}


void PointerBasedQueue::print(){
    Node* tmp = header;
    std::cout<<"[";
    
    while(tmp != nullptr){
        if(tmp->next == nullptr) std::cout<<tmp->value;
        else std::cout<<tmp->value<<",";
        tmp = tmp->next;
    }; 
    std::cout<<"]";
    std::cout<<std::endl;
}

void PointerBasedQueue::enqueue(int element){

    if(!isFull()){
        if(size == 0){
            rear->value = element;
            size++;
        } else {
            Node* newNode = new Node();
            newNode->value = element;
            newNode->next = nullptr;
            rear->next = newNode;
            rear = newNode;
            size++;
             
        }

    } else {
        std::cout<<"Kolejka jest pelna"<<std::endl;
    }
}

void PointerBasedQueue::dequeue(){

    if(!isEmpty()){
        if(getSize() == 1){
            Node* tmp = new Node;
            header = new Node();
            front = header;
            rear = header;
            size = 0;
        } else {
            Node* tmp = front;
            front = front->next;
            header = front;
            delete tmp;
            size--;

        }

    } else {
        std::cout<<"Kolejka jest pusta!"<<std::endl;
    }
}

int PointerBasedQueue::getSize(){
    return size;
}

bool PointerBasedQueue::isFull(){
    if(size == MAX_SIZE) return true;
    return false;
}

bool PointerBasedQueue::isEmpty(){
    if(size == 0) return true;
    return false;
}

PointerBasedQueue::Node* PointerBasedQueue::getRear(){
    return rear;
}

PointerBasedQueue::Node* PointerBasedQueue::getFront(){
    return front;
}

