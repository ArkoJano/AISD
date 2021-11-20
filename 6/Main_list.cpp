#include "ListBasedStack.h"
using namespace std;

int main(){

    ListBasedStack main_stack(10);
    for(int i=0; i<= 7; i++)
    {
        cout<<"push("<<i<<")"<< endl;
        main_stack.push(i);
    }
    cout<<"stos: "<<endl;
    main_stack.print();
    cout<<"actual_size(): "<<main_stack.actual_size()<<endl;
    cout<<"size(): "<<main_stack.size()<<endl;

    cout<<"isEmpty: "<<main_stack.isEmpty()<<endl;
    cout<<"peek: "<<main_stack.peek()<<endl;
    for(int i = 0; i<=8 ; i++)
    cout<<"pop: "<<main_stack.pop()<<endl;
    cout<<"stos: "<<endl;
    main_stack.print();
    cout<<"actual_size(): "<<main_stack.actual_size()<<endl;
    cout<<"isEmpty: "<<main_stack.isEmpty()<<endl;

}