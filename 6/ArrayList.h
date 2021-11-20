#include "List.h"

class ArrayList : public List {
    private:
        int size;
        int *array;
        int first_position;
        int last_position;
        int empty_places;

    public:
        ArrayList();
        ArrayList(int size);
        ~ArrayList();
        void print();
        int getSize();
        void reSize();
        bool insert(int index, int element);
        bool remove(int index);
        int emptyPlaces();
        int retrieve(int index);
        int locate(int index);
        int end();
        int first();
        int next(int index);
        int previous(int index);
        int last();
        int back();
        bool push_front(int element);
        bool push_back(int element);
        bool pop_front();
        bool pop_back();
        void del_all(int element);
        void del_duplicates(int element);
        void reverse();
};