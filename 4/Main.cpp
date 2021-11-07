#include "List.h"
#include "ArrayList.h"
using namespace std;

int main(){
    ArrayList array{5};
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(0, 1);
    cout<<"insert(0, 1)"<<endl;
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(1, 1);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(2, 2);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(3, 3);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(4, 4);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.print();
    array.remove(3);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.remove(3);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize() <<endl;
    array.insert(5, 1);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(6, 2);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    array.insert(7, 3);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;    
    array.insert(8, 4);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "retrieve(5):"<< array.retrieve(5)<<endl;
    cout << "locate(3):"<< array.locate(3) <<endl;
    cout << "locate(12):"<< array.locate(12) <<endl;
    cout << "end:"<< array.end() <<endl;
    cout << "first:"<< array.first() <<endl;
    cout << "remove(0)"<<endl;
    array.remove(0);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout << "first:"<< array.first() <<endl;
    cout << "next(5):"<< array.next(5) <<endl;
    cout << "previous(5):"<< array.previous(5) <<endl;
    cout << "last:" << array.last() <<endl;

    
    for(int i=0; i<5;i++){
    cout << "--------------- Push_front -----------------"<<endl;
    cout << "push_front(5):" << array.push_front(5) <<endl;
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;
    }

    cout << "---------------- Push_back -----------------"<<endl;
    cout << "push_front(5):" << array.push_back(5) <<endl;
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "---------------- pop_front -----------------"<<endl;
    cout << "pop_front(5):" << array.pop_front() <<endl;
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "----------------- pop_back -----------------"<<endl;
    cout << "pop_back(5):" << array.pop_back() <<endl;
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "--------------- del_all(1s) ----------------"<<endl;
    array.del_all(1);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "------------- del_dupicates(5) -------------"<<endl;
    array.del_duplicates(5);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "----------------------------------- --------"<<endl;

    cout << "----------------- reverse ------------------"<<endl;
    array.reverse();
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "------------ del_dupicates(2) --------------"<<endl;
    array.del_duplicates(2);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "--------------- del_all(4) -----------------"<<endl;
    array.del_all(4);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;

    cout << "------------- del_dupicates(3) -------------"<<endl;
    array.del_duplicates(3);
    array.print();
    cout << "Empty places: "<< array.emptyPlaces() <<endl;
    cout<< "Array size: "<< array.getSize()<<endl;
    cout << "last_position:" << array.last() <<endl;
    cout << "--------------------------------------------"<<endl;
}
