#include <iostream>
#define MAX_SIZE 10

class ArrayBasedQueue {
    private:
        int array[MAX_SIZE] = {};
        int size;
        int front;
        int rear;

    public:
        ArrayBasedQueue();
        ~ArrayBasedQueue();
        bool isEmpty();
        bool isFull();
        // zostawiamy jedno miejsce puste, dlatego isFull == true dla size-1
        // miejsce puste między rear a front
        int getSize();
        void enqueue(const int element);
        // wstawianie to po prostu % MAX_SIZE
        void dequeue();
        int getFront();
        int getRear();

        void print();


};