#include <iostream>
#define MAX_SIZE 10

class PointerBasedQueue {
    private:
        struct Node {
            int value;
            Node *next;
        };

        int size;
        Node* header;
        Node* front;
        Node* rear;

    public:
        PointerBasedQueue();
        ~PointerBasedQueue();
        bool isEmpty();
        bool isFull();
        // zostawiamy jedno miejsce puste, dlatego isFull == true dla size-1
        // miejsce puste między rear a front
        int getSize();
        void enqueue(const int element);
        // wstawianie to po prostu % MAX_SIZE
        void dequeue();

        Node* getFront();
        Node* getRear();

        void print();


};