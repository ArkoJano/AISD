#include "LinkedList.h"

class ListBasedStack {
    private:
        LinkedList stack;
        int stack_size;
        int STACK_MAX_SIZE;
    
    public:
        ListBasedStack();
        ListBasedStack(int max);
        ~ListBasedStack() = default;
        void print();
        void push(int element);
        int pop();
        int peek();
        bool isEmpty();
        int actual_size();
        int size();
        bool isFull();
};