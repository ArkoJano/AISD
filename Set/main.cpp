#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

using namespace std;

template <typename T>
class Iterator {
    public:
        // virtual ~Iterator() {};
        virtual bool IsDone() = 0;
        virtual T& operator*() = 0;
        virtual void operator++() = 0;

};

template <typename T>
class Visitor
{
public:
 virtual void Visit (T& element) = 0;
 virtual bool IsDone() { return false; }
}; 

class AddingVisitor:public Visitor<int>
{
    public:
        int suma;
        AddingVisitor():suma(0){};
        void Visit(int& obj) {
            suma+=obj;
            // suma++;
        }
        void MakeNull(){
            suma = 0;
        }
        
};


class OddVisitor:public Visitor<int>
{
    public:
        int is_odd;
        OddVisitor():is_odd(false){};
        void Visit(int& obj) {
            if(obj % 2 == 1){
                is_odd = true;
            }
        }
        bool IsDone() { return is_odd; }
        
        
};


template <typename T>
class Container
{
    protected:
        Container (){};
    public:
        virtual int Count () const = 0;
        virtual bool IsEmpty () const {return Count()==0;};
        virtual bool IsFull () const = 0;
        virtual void MakeNull() = 0;
        virtual int  Accept (Visitor<T> & v)  = 0; 
};
template <typename T>
class Set : public Container<T>{
    protected:
        int count;
    public:
        int universeSize;
        Set (int n) : universeSize (n) {}
        int UniverseSize() const {return universeSize;}
        int Count() const {return count;};
        virtual void Insert (T element)=0;
        virtual bool IsMember (T element) const=0;
        virtual void Withdraw (T element)=0;
};

class SetAsArray : public Set<int>
{
    protected:
        std::vector<bool> array;

    public:
        SetAsArray(unsigned int n) : Set(n){
            n=n+1;
            array.resize(n);
            for (bool index : array){
                index = false;
            }
            count = 0;
            universeSize = n;
        }
        
        class Iter : public Iterator<int>{
            public:
            std::vector<bool> data;
            int iter_universeSize;
            int index;
                Iter(vector<bool> arr, int size){
                    data = arr;
                    iter_universeSize = size;
                    index = 1;
                    for (bool value : data){
                        if (value == true){
                            break;
                        }
                        index++;
                    }
                }
                
                ~Iter(){};
                int& operator*() {
                    return index;
                }
                void operator++(){
                    for(int i = index; i <= (int) iter_universeSize; ++i){
                        // cout<<i << " ";
                        index = i;
                        if (data[i] == true){
                            index++;
                            break;
                        }
                    }
                }
                bool IsDone() {
                    return (index == iter_universeSize);
                }
        };

        Iter & newIterator(){
            return *new Iter(array, universeSize);
        }

        int Accept(Visitor<int> & v){
            int i, j = 0;
            bool found = false;
           
            
            for (i = 0; (i <= (int) universeSize); i++){
                // cout<<"i: "<<i<<endl;
                if (array[i] == true){
                    j = i + 1;
                    v.Visit(j);
                    bool result = v.IsDone();
                    if (result){
                        found = true;
                        break;
                    }
                }

            }
            // if (found) return j;
            // else return -1;
            return j;
        }
        void MakeNull(){
            count = 0;
            for (bool index : array){
                index = false;
            }
        };
        bool IsFull() const {
            return (Count()==UniverseSize());
        }
        void Insert (int element){
            if (element > 0 && element < universeSize){
                if (array[element-1] == false){
                    array[element-1] = true;
                    count++;
                }
            }
        }
        bool IsMember (int element) const {
            if(element > 0 && element < universeSize) 
                return array[element-1] == true; 
            else return false;
        };

        void Withdraw (int element){
            if (array[element-1] == true){
                array[element-1] = false;
                count--;
            }
        }

        void print(){
            for(int i=0; i<universeSize; i++){
                if(this->IsMember(i)){
                    cout<< i <<" ";
                }
            }
            cout<<endl;
        }



        //friend- funkcja uzyska prawo dostepu do prywatnych elementów danej klasy.
        friend SetAsArray operator + (
        SetAsArray const& s, SetAsArray const& t){
            SetAsArray result (s.universeSize - 1);
            if(s.UniverseSize() == t.UniverseSize()){
                for (unsigned int i = 0; i < (unsigned int) s.universeSize; ++i)
                    if(s.array[i] || t.array[i]){
                        result.array[i] = true;
                        result.count++;
                    } 
            }
            return result;

        }
        friend SetAsArray operator - (
        SetAsArray const& s, SetAsArray const& t){
            SetAsArray result (s.universeSize - 1);
            // if(s.UniverseSize() == t.UniverseSize()){
                for (unsigned int i = 0; i < (unsigned int)s.universeSize; ++i){
                    // cout<<i<<": s: "<<s.array[i]<<"| t: "<<t.array[i]<<endl;
                    if((s.array[i]) && !t.array[i]){
                        result.array[i] = true;
                        result.count++;
                    }
                }
                    
            // }
            return result;
        }
        friend SetAsArray operator * (
        SetAsArray const& s, SetAsArray const& t){
            // if(s.UniverseSize() == t.UniverseSize()){
                SetAsArray result (s.universeSize - 1);
                for (unsigned int i = 0; i < (unsigned int)s.universeSize; ++i){
                    // cout<<"i:" << i <<" "<< s.array[i] << ":"<< t.array[i]<<endl;
                    if(s.array[i] && t.array[i]){ 
                        result.array[i] = true;
                        result.count++;
                    }
                }
                    
                return result;
            // }
        }
        friend bool operator == (
        SetAsArray const& s, SetAsArray const& t){
            if(s.UniverseSize() == t.UniverseSize()){
                for (unsigned int i = 0; i < (unsigned int)s.universeSize; ++i)
                    if(s.array[i] != t.array[i]) return false;
                return true;
            } 
            return false; 
            
        }
        friend bool operator <= (
        SetAsArray const& s, SetAsArray const& t){
            if(s.UniverseSize() <= t.UniverseSize()){
                int counter = 0;
                for (unsigned int i = 0; i < (unsigned int)s.universeSize; ++i){
                    // cout<<"s: "<< s.array[i] << "t: "<< t.array[i]<<endl;
                    if(s.array[i] && t.array[i]){
                        counter++;
                    }
                    // if(s.array[i] != t.array[i]) return false;
                    
                }
                if(counter == s.count) return true;
                return false;
            } 
            return false; 
            
        }
        //void Accept (Visitor&) const{};
        //o metodzie Accept powiemy na następnych zajęciach
}; 



int main(){

    SetAsArray A(10);
    SetAsArray B(10);
    SetAsArray C(10);
    SetAsArray D(10);

    for(int i=0; i<=10; i+=2){
        A.Insert(i);
    }

    for(int i=1; i<=10; i+=2){
        B.Insert(i);
    }

    C = A + B;
    D = C - B;

    cout <<"A: ";
    A.print();

    cout <<"B: ";
    B.print();

    cout <<"C: ";
    C.print();

    cout <<"D: ";
    D.print();

    cout <<"Czy D == A: "<<((D == A) ? "Tak" : "Nie")<<endl;
    cout <<"Czy D <= A: "<<((D <= A) ? "Tak" : "Nie")<<endl;
    cout <<"Czy C == B: "<<((C == B) ? "Tak" : "Nie")<<endl;
    cout <<"Czy B <= C: "<<((B <= C) ? "Tak" : "Nie")<<endl;

    A.Insert(1);
    A.print();
    cout <<"Czy D == A: "<<((D == A) ? "Tak" : "Nie")<<endl;
    cout <<"Czy D <= A: "<<((D <= A) ? "Tak" : "Nie")<<endl;

    A.Insert(5);
    cout <<"A: ";
    A.print();
    AddingVisitor v_A;
    A.Accept(v_A);
    cout<< "Suma A: "<< v_A.suma << endl;
    SetAsArray E(10);
    E = A * B;
    // cout <<"A: ";
    // A.print();
    // cout <<"B: ";
    // B.print();
    cout <<"E: ";
    E.print();
    AddingVisitor v_E;
    E.Accept(v_E);
    cout<< "Suma E: "<< v_E.suma << endl;
    v_E.MakeNull();
    E.Withdraw(1);
    cout <<"E: ";
    E.print();
    E.Accept(v_E);
    cout<< "Suma E: "<< v_E.suma << endl;
    cout<< "Ilosc elementów E:" <<E.Count() <<endl;
    cout<< "Ilosc elementów C:" <<C.Count() <<endl;
    cout<< "Ilosc elementów D:" <<D.Count() <<endl;
    
    cout <<"B: ";
    B.print();
    OddVisitor oddVisitor_B;
    cout<< "B: Miejsce pierwszego nieparzystego elementu: " << B.Accept(oddVisitor_B) << endl;
    cout <<"A: ";
    A.print();
    OddVisitor oddVisitor_A;
    cout<< "A: Miejsce pierwszego nieparzystego elementu: " << A.Accept(oddVisitor_A) << endl;
    A.Withdraw(1);
    A.Withdraw(5);
    cout <<"A: ";
    A.print();
    cout<< "A: Miejsce pierwszego nieparzystego elementu: " << A.Accept(oddVisitor_A) << endl;
    
    OddVisitor oddVisitor_D;
    cout<< "D: Miejsce pierwszego nieparzystego elementu: " << D.Accept(oddVisitor_D) << endl;
    // A.newIterator();
    SetAsArray::Iter iter =  A.newIterator(); 
    cout <<"A: ";
    while (!iter.IsDone()){
        cout<<*iter<<" ";
        ++iter;
    }
    cout<<endl;
    SetAsArray::Iter iter_b =  B.newIterator(); 
    cout <<"B: ";
    while (!iter_b.IsDone()){
        cout<<*iter_b<<" ";
        ++iter_b;
    }
    cout<<endl;
    return 0;
}