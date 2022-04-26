#include "ArrayBasedQueue.h"



ArrayBasedQueue::ArrayBasedQueue(){
    size = 0;
    front = 0;
    rear = 0;
    for(int i=0; i<=MAX_SIZE; i++){
        array[i] = 0;
    }
}

ArrayBasedQueue::~ArrayBasedQueue(){
    
}

void ArrayBasedQueue::print(){
    std::cout<<"[";
    for(int i=0; i<MAX_SIZE; i++){
        if(i == MAX_SIZE-1) std::cout<<array[i];
        else std::cout<<array[i]<<",";
    }
    std::cout<<"]";
    std::cout<<std::endl;
}

void ArrayBasedQueue::enqueue(int element){

    if(!isFull()){
        
        if(rear != front-1){
            array[rear] = element;
            rear = (rear+1) % (MAX_SIZE);
            size++;
        }

    } else {
        std::cout<<"Kolejka jest pelna"<<std::endl;
    }
}

void ArrayBasedQueue::dequeue(){

    if(!isEmpty()){
        array[front] = 0;
        front = (front + 1) % (MAX_SIZE);
        size--;

    } else {
        std::cout<<"Kolejka jest pusta!"<<std::endl;
    }
}

int ArrayBasedQueue::getSize(){
    return size;
}

bool ArrayBasedQueue::isFull(){
    if(size == MAX_SIZE - 1) return true;
    return false;
}

bool ArrayBasedQueue::isEmpty(){
    if(size == 0) return true;
    return false;
}

int ArrayBasedQueue::getRear(){
    return rear;
}

int ArrayBasedQueue::getFront(){
    return front;
}

