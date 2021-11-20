#include "ArrayBasedStack.h"

ArrayBasedStack::ArrayBasedStack(){
    stack = 2;
    stack_size = 0;
    STACK_MAX_SIZE = 1;
}
ArrayBasedStack::ArrayBasedStack(int max){
    stack = max+1;
    stack_size = 0;
    STACK_MAX_SIZE = max;    
};

void ArrayBasedStack::print(){
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

void ArrayBasedStack::push(int element){
    if(stack_size == STACK_MAX_SIZE){
        std::cout<<"Stos jest pelny!"<<std::endl;
    } else {
        stack.insert(stack_size, element);
        stack_size++;
    }
}

int ArrayBasedStack::peek(){
    if(!isEmpty()){
        return stack.retrieve(stack_size-1);
    } else return -1;
}

int ArrayBasedStack::pop(){
    if(!isEmpty()){
        int last = peek();
        stack.remove(stack_size-1);
        stack_size--;
        return last;
    } else return -1;
}

bool ArrayBasedStack::isEmpty(){
    if(stack_size == 0) return true;
    return false;
}
bool ArrayBasedStack::isFull(){
    if(stack_size == STACK_MAX_SIZE) return true;
    return false;
} 
int ArrayBasedStack::actual_size(){
    return stack_size;
}
int ArrayBasedStack::size(){
    return STACK_MAX_SIZE;
}