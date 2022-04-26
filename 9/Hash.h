#include <iostream>

const int HASH_TABLE_SIZE = 10;

class Hash{
    private:
        struct Node{
            int key;
            int element;
            Node* next;
        };
        Node** head;
        int size;
    public:

        Hash(int size = HASH_TABLE_SIZE);
        ~Hash();
        bool insert(const int &x);
        bool remove(const int &x);
        bool contains(const int &x);
        int hash(const int &x);
        void makeEmpty();
        void print();

};