#include "ArrayBasedQueue.h"
using namespace std;


int main(){
    ArrayBasedQueue queue;
    queue.print();
    for(int i=1; i<=10; i++){
        queue.enqueue(i);
        cout<<"Size:" << queue.getSize()<<endl;
        cout<<"rear:" << queue.getRear()<<endl;
        cout<<"front:" << queue.getFront()<<endl;
        queue.print();
    } 

    for(int i=1; i<=10; i++){

        cout<<"Size:" << queue.getSize()<<endl;
        cout<<"rear:" << queue.getRear()<<endl;
        cout<<"front:" << queue.getFront()<<endl;
        queue.dequeue(); 
        queue.print();
    }

    for(int i=1; i<=10; i++){
        queue.enqueue(i);
        cout<<"Size:" << queue.getSize()<<endl;
        cout<<"rear:" << queue.getRear()<<endl;
        cout<<"front:" << queue.getFront()<<endl;
        queue.print();
    } 
    
}