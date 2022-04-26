#include <iostream>
#include <vector>
using namespace std;

class Container
{
    protected:
        Container (){};
    public:
        virtual unsigned int Count () const = 0;
        virtual bool IsEmpty () const {
            return Count() == 0;};
        virtual bool IsFull () const = 0;
        virtual void MakeNull() = 0;
};

template <typename T>
class PriorityQueue : public Container{
    public:
        virtual void Enqueue (T element) = 0;
        virtual T FindMin () const = 0;
        virtual T DequeueMin () = 0;
};

template <typename T>
class BinaryHeap : public PriorityQueue<T>
{
    protected:
        int count;
        vector<T> data;
    public:
        BinaryHeap ();
        BinaryHeap (unsigned int n);
        ~BinaryHeap (){;};
        void MakeNull();
        void Enqueue (T element);
        T FindMin () const;
        T DequeueMin ();
        bool IsEmpty () const;
        bool IsFull () const ;
        unsigned int Count() const {return count;} 
        void print();
        
};
template <typename T>
void BinaryHeap<T>::MakeNull(){
    count = 0;
}

template <typename T>
void BinaryHeap<T>::Enqueue (T element){
    if(this->IsFull()){
        data.resize(data.size()*2);
    }
    ++count;
    int i = count - 1;
    while(i > 0 && data[(i-1)/2] > element){ // nie doszlismy do konca
                                             // i rodzic jest wiekszy od
                                             // wstawianego elementu
        data[i] = data[(i-1)/2];
        i = (i-1)/2;                                             
    }
    data[i] = element;
}

template <typename T>
T BinaryHeap<T>::DequeueMin (){
    if(!this->IsEmpty()){
        T wynik = data[0]; // usuniety najmniejszy element
        T ostatni   = data[count - 1]; // ostatni element 

        count--; // zmniejszamy licznik elementow

        int i = 0;

        while(2*i+1 < count){   // przegladamy wszystkie dzieci
            int dziecko = 2*i+1; // pierwsze dziecko 
            if(dziecko + 1 < count && // jesli istnieje drugie 
                data[dziecko+1]<data[dziecko]){ // i jest mniejsze od pierwszego

                dziecko = dziecko + 1;    
            }
            if(ostatni <= data[dziecko]) // jesli znalezlismy miejsce dla elementu
                break; 
            // jesli nie to podstawiamy na tej pozycji
            data[i] = data[dziecko]; 
            i = dziecko; // rozważamy teraz węzeł niżej
        }
        data[i] = ostatni; // znalezlismy miejsce dla tego elementu
        return wynik;
    }
}
template <typename T>
T BinaryHeap<T>::FindMin () const{
    if(count < 1){
        abort();
    }
    return data[0];
}
template <typename T>
BinaryHeap<T>::BinaryHeap(unsigned int n){
    count = 0; 
    data.resize(n);
}
template <typename T>
BinaryHeap<T>::BinaryHeap(){
    count = 0; 
    data.resize(10);
}
template <typename T>
bool BinaryHeap<T>::IsFull () const{
    return (count == data.size());
}

template <typename T>
bool BinaryHeap<T>::IsEmpty () const{
    return (count == 0);
}

template<typename T>
void BinaryHeap<T>::print(){
    cout<<"|";
    for(T obj : data){
        cout<<obj<<"|";
    }
    cout<<endl;
}

int main(){

    //Utwórz kolejkę (dugość wektora 10)
    BinaryHeap<int>* heap = new BinaryHeap<int>(2);
    // Sprawdź, czy jest pusta
    cout<<"Pusta?: "<<(heap->IsEmpty() ? "tak" : "nie")<<endl;
    heap->Enqueue(5);
    // Sprawdź, czy jest pusta
    cout<<"Pelna?: "<<(heap->IsFull() ? "tak" : "nie")<<endl;
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Enqueue(6);
    heap->Enqueue(6);
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Enqueue(8);
    heap->Enqueue(8);
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Enqueue(3);
    heap->Enqueue(3);
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Enqueue(9);
    heap->Enqueue(9);
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Enqueue(2);
    heap->Enqueue(2);
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Enqueue(1);
    heap->Enqueue(1);
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // DequeueMin()
    heap->DequeueMin();
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // DequeueMin()
    heap->DequeueMin();
    // Wypisz();
    heap->print();
    // WypiszMin()
    cout<<"MIN: "<<heap->FindMin()<<endl;
    // Makenull()
    heap->MakeNull();
    // Sprawdź, czy jest pusta
    cout<<"Pusta?: "<<(heap->IsEmpty() ? "tak" : "nie")<<endl;

    return 0;
}
