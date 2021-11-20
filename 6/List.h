#ifndef LIST_H
#define LIST_H


#include <iostream>


class List {

    public:


        virtual ~List() = default;
        virtual bool insert(int index, int element) = 0;
        virtual bool remove(int index) = 0;
        virtual int retrieve(int index) = 0;
        virtual int locate(int index) = 0;
        virtual int back() = 0;
        virtual bool push_front(int element) = 0;
        virtual bool push_back(int element) = 0;
        virtual bool pop_front() = 0;
        virtual bool pop_back() = 0;

    
};

#endif