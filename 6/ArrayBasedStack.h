#include "ArrayList.h"

class ArrayBasedStack {
    private:
        ArrayList stack;
        int stack_size;
        int STACK_MAX_SIZE;
    
    public:
        ArrayBasedStack();
        ArrayBasedStack(int max);
        ~ArrayBasedStack() = default;
        void print();
        void push(int element);
        int pop();
        int peek();
        bool isEmpty();
        int actual_size();
        int size();
        bool isFull();
};