#include "ListBasedStack.h"

ListBasedStack::ListBasedStack(){
    stack_size = 0;
    STACK_MAX_SIZE = 1;
}
ListBasedStack::ListBasedStack(int size){
    stack_size = 0;
    STACK_MAX_SIZE = size;
}

void ListBasedStack::print(){
    if(stack_size == 0){
        std::cout<<"[]";
    } else {
        std::cout<<"[";
        for(int i=0; i<stack_size; i++){
            if(i == stack.getSize()) std::cout<<stack.retrieve(i);
            else std::cout<<stack.retrieve(i)<<",";
        }
        std::cout<<"]";
        std::cout<<std::endl;
    }
    
}

void ListBasedStack::push(int element){
    if(stack_size == STACK_MAX_SIZE){
        std::cout<<"Stos jest pelny!"<<std::endl;
    } else {
        stack.insert(stack_size, element);
        stack_size++;
    }
}

int ListBasedStack::peek(){
    if(!isEmpty()){
        return stack.retrieve(stack_size-1);
    } else return -1;
}

int ListBasedStack::pop(){
    if(!isEmpty()){
        int last = peek();
        stack.remove(stack_size-1);
        stack_size--;
        return last;
    } else return -1;
}

bool ListBasedStack::isEmpty(){
    if(stack_size == 0) return true;
    return false;
}
bool ListBasedStack::isFull(){
    if(stack_size == STACK_MAX_SIZE) return true;
    return false;
} 
int ListBasedStack::actual_size(){
    return stack_size;
}
int ListBasedStack::size(){
    return STACK_MAX_SIZE;
}