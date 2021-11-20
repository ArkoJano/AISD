#include "List.h"
#include "LinkedList.h"
using namespace std;

int main(){
    LinkedList array;
    
    array.insert(0, 1);
    cout<<"array.insert(0,1)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(1, 2);
    cout<<"array.insert(1,2)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(2, 3);
    cout<<"array.insert(2,3)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(3, 4);
    cout<<"array.insert(3,4)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(0, 10);
    cout<<"array.insert(0,10)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    //cout<<array.move_to_index(2)->value<<endl;
    cout<<"Tablica: "<<endl;
    array.print();
    array.remove(1);
    cout<<"array.remove(1)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.remove(1);
    cout<<"array.remove(1)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    cout<<"Tablica: "<<endl;
    array.print();
    cout<<"array.retrieve(1): "<< array.retrieve(1)<<endl;
    cout<<"array.retrieve(3): "<< array.retrieve(3)<<endl;
    cout<<"array.retrieve(5): "<< array.retrieve(5)<<endl;
    cout<<"array.retrieve(10): "<< array.retrieve(10)<<endl;

    cout << "locate(3):"<< array.locate(3) <<endl;
    cout << "locate(12):"<< array.locate(12) <<endl;
    cout << "locate(12):"<< array.locate(4) <<endl;
    cout << "locate(12):"<< array.locate(40) <<endl;

    cout<<"array.empty(): " << array.empty() << endl;

    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    cout<<"Tablica: "<<endl;
    array.print();

    cout<<"array.empty(): " << array.empty() << endl;

    array.insert(0, 1);
    cout<<"array.insert(0,1)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(1, 2);
    cout<<"array.insert(1,2)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(2, 3);
    cout<<"array.insert(2,3)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.insert(3, 4);
    cout<<"array.insert(3,4)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    cout<<"Tablica: "<<endl;
    array.print();

    cout<<"array.first(): "<<array.first()<<endl;
    cout<<"array.last(): "<<array.first()<<endl;

    cout<<"array.front(): "<<array.front()<<endl;
    cout<<"array.back(): "<<array.back()<<endl;

    cout<<"array.len(): "<<array.len()<<endl;

    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    array.remove(0);
    cout<<"array.remove(0)"<<endl;
    cout<<"Rozmiar tablicy: "<<array.getSize()<<endl;
    cout<<"Tablica: "<<endl;
    array.print();

    cout<<"array.first(): "<<array.first()<<endl;
    cout<<"array.last(): "<<array.first()<<endl;

    cout<<"array.front(): "<<array.front()<<endl;
    cout<<"array.back(): "<<array.back()<<endl;

    cout<<"array.len(): "<<array.len()<<endl;

    for(int i=0; i<5;i++){
        cout << "--------------- Push_front -----------------"<<endl;
        cout << "push_front(5):" << array.push_front(i) <<endl;
        array.print();
        cout<< "Array size: "<< array.len()<<endl;
    }

    for(int i=0; i<5;i++){
        cout << "--------------- Push_back -----------------"<<endl;
        cout << "push_back(3):" << array.push_back(-i) <<endl;
        array.print();
        cout<< "Array size: "<< array.len()<<endl;
    }

    cout << "--------------- Pop_front -----------------"<<endl;
    cout << "pop_front():" << array.pop_front() <<endl;
    array.print();
    cout<< "Array size: "<< array.len()<<endl;

    cout << "--------------- Pop_back -----------------"<<endl;
    cout << "pop_back():" << array.pop_back() <<endl;
    array.print();
    cout<< "Array size: "<< array.len()<<endl;

    cout << "del_array():" << endl; 
    array.del_array();
    array.print();
    cout<< "Array size: "<< array.len()<<endl;

    
    for(int i=0; i<5;i++){
        cout << "--------------- Push_front -----------------"<<endl;
        cout << "push_front(i):" << array.push_front(i) <<endl;
        array.print();
        cout<< "Array size: "<< array.len()<<endl;
    }

    for(int i=0; i<10;i++){
        cout << "--------------- Push_back -----------------"<<endl;
        cout << "push_back(i):" << array.push_back(i) <<endl;
        array.print();
        cout<< "Array size: "<< array.len()<<endl;
    }

    cout << "--------------- dell_all -----------------"<<endl;
    cout << "del_all(3):" <<endl; 
    array.del_all(3);
    array.print();
    cout<< "Array size: "<< array.len()<<endl;

    cout << "--------------- dell_all -----------------"<<endl;
    cout << "del_all(4):" <<endl; 
    array.del_all(4);
    array.print();
    cout<< "Array size: "<< array.len()<<endl;

    cout << "--------------- dell_duplicates -----------------"<<endl;
    cout << "dell_duplicates(2):" <<endl; 
    array.del_duplicates(2);
    array.print();
    cout<< "Array size: "<< array.len()<<endl;

    cout << "----------------- reverse ------------------"<<endl;
    array.reverse();
    array.print();
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "--------------------------------------------"<<endl;
    
    cout << "----------------- del_odd_indexes ------------------"<<endl;
    array.del_odd_indexes();
    array.print();
    cout<< "Array size: "<< array.getSize()<<endl;

}