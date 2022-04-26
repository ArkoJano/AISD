#include "PointerBasedQueue.h"
using namespace std;


int main(){
    PointerBasedQueue queue;
    queue.print();
    for(int i=1; i<=10; i++){
        queue.enqueue(i);
        cout<<"Size:" << queue.getSize()<<endl;
        cout<<"rear:" << queue.getRear()->value<<endl;
        cout<<"front:" << queue.getFront()->value<<endl;
        queue.print();
    } 

    for(int i=1; i<=10; i++){

        cout<<"Size:" << queue.getSize()<<endl;
        cout<<"rear:" << queue.getRear()->value<<endl;
        cout<<"front:" << queue.getFront()->value<<endl;
        queue.dequeue(); 
        queue.print();
    }

    for(int i=1; i<=10; i++){
        queue.enqueue(i);
        cout<<"Size:" << queue.getSize()<<endl;
        cout<<"rear:" << queue.getRear()->value<<endl;
        cout<<"front:" << queue.getFront()->value<<endl;
        queue.print();
    } 
    
}