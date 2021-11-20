#include "List.h"

class LinkedList : public List {
    private:

        struct Node {
            int value;
            Node *next;
        };
        Node *header;
        int size;

    public:
        LinkedList();
        ~LinkedList() = default;
        void print();
        int getSize();
        Node* move_to_index(int index);
        bool insert(int index, int element); 
        // chcemy wstawić żeby dodać na koniec, jeśli nie będzie miejsca
        // to zwraca błąd
        bool remove(int index);
        // pamiętać o zwalnianiu pamięci 
        int retrieve(int index);
        int locate(int element);
        bool empty();
        Node* first(); // jesli nie ma elementu to nullptr
        int front();
        Node* last();
        int back();
        int len();
        bool push_front(int element);
        bool push_back(int element);
        bool pop_front();
        bool pop_back();
        void del_array();
        void del_all(int element);
        void del_duplicates(int element);
        void reverse();
        void del_odd_indexes();

};