#include <iostream>
#include <stdlib.h>
#include <map>
using namespace std;

#define SIZE_OF_ARRAY 10


void print_array(int array[], int size){
    for(int i=0; i<size; i++){
        cout << array[i]<< " ";
    }
}

int insertion_sort(int array[], int size){
    int dominant_operation = 0;

    for(int j=1; j<size; j++){
        dominant_operation++;

        int v = array[j];
        int i = j - 1;

        while (i>=0 && array[i]>v){
            dominant_operation++;
            array[i+1] = array[i];
            i -= 1;
        }
    array[i+1] = v;
    
    }

    return dominant_operation;
}

void copy_array(int from_array[], int to_array[], int size){
    for(int i=0; i<size; i++){
        to_array[i] = from_array[i];
    }
}


int factorial(int n){
    int result = 1;
    for(int i=0; i<n; i++){
        result *= n-i;
    }
    return result;
}

int pow(int number, int base){
    int result = 1;
    for(int i=0;i<base;i++){
        result *= number;
    }
    return result;
}



string complexity(int size, int dominant_operations){
    string time_complexity = "O(0)";

    if(dominant_operations < size-1) time_complexity = "O(1)";
    else if(dominant_operations <= size-1) time_complexity = "O(n)";
    else if(dominant_operations <= pow(size,2)) time_complexity = "O(n^2)";
    else if(dominant_operations <= pow(2, size)) time_complexity = "O(2^n)";
    else if (dominant_operations <= factorial(size)) time_complexity  = "O(n!)";

    
    return time_complexity;
}


// string average_complexity(int size){
//     int random_size = rand() % 20;
//     int dominant_operations = size*(size-1)/4;
//     return complexity(size, dominant_operations);
// }

string average_complexity(int size){
    
    int rand_array[size];
    int number_of_iterations = 30;
    int complexity_results = 0;;
    

    for(int j=0; j<number_of_iterations; j++){

        

        for(int i=0; i<size; i++){
            int x = rand() % 20;
            rand_array[i] = x; 
        }

        int dominant_operations;
        dominant_operations = insertion_sort(rand_array, size);
        complexity_results += dominant_operations;

    }
    complexity_results /= number_of_iterations;
    return complexity(size, complexity_results);
}



string pesimistic_complexity(int size){

    int pesimistic_array[SIZE_OF_ARRAY];
    for(int i=1; i<=SIZE_OF_ARRAY; i++){
        pesimistic_array[i-1];
    }
    int dominant_operations = insertion_sort(pesimistic_array, size);
    
    return complexity(size, dominant_operations);

}



string pessimistic_sensitivity(string pesimistic, string average){
    string complexity_O[] = {"O(0)", "O(1)", "O(n)", "O(n^2)","O(2^n)", "O(n!)"};
    int pesimistic_wage, average_wage;


    for(int i=0; i<6;i++){
        if(complexity_O[i] == pesimistic) pesimistic_wage = i;
        if(complexity_O[i] == average) average_wage = i;
    }


    int pesimistic_sensitivity = pesimistic_wage - average_wage;

    return complexity_O[pesimistic_sensitivity];
}


int main(){



    int rand_array[SIZE_OF_ARRAY];

    for(int i=0; i<SIZE_OF_ARRAY; i++){
        int x = rand() % 20;
        rand_array[i] = x; 
    }
   

    int size = sizeof(rand_array)/sizeof(rand_array[0]);

    cout<<"-------------------Przypadek tablicy z losowymi danymi------------------"<<endl;

    cout<<"Tablica przed posortowaniem: ";
        print_array(rand_array, size);
    cout<<endl;

    int dominant_operation = insertion_sort(rand_array, size);


    cout<<"Posortowana tablica: ";
        print_array(rand_array, size);
    cout<< endl;

    cout<< "Operacje dominujace: "<< dominant_operation << endl;

    string time_complexity = complexity(size, dominant_operation);

    cout<< "Czy liczba operacji dominujacych zgadza sie z oszacowaniem:"<<endl;
   
    if(dominant_operation < pow(SIZE_OF_ARRAY,2)){
        cout<< "Tak, bo "<< dominant_operation << " < " << pow(SIZE_OF_ARRAY,2)<<endl;
    } else {
        cout<< "Nie, bo "<< dominant_operation << " > " << pow(SIZE_OF_ARRAY,2)<<endl;
    }
    cout<< "Dla tego zestawu danych algorytm ma zlozonosc czasowa rowna: "<< time_complexity << endl;
    cout<<"------------------------------------------------------------------------"<<endl<<endl;
    
    
    cout<<"-----------------Przypadek tablicy z posortowanymi danymi---------------"<<endl;

    int sorted_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout<<"Tablica przed posortowaniem: ";
        print_array(sorted_array, size);
    cout<<endl;

    dominant_operation = insertion_sort(sorted_array, size);


    cout<<"Posortowana tablica: ";
        print_array(sorted_array, size);
    cout<< endl;

    cout<< "Operacje dominujace: "<< dominant_operation << endl;

    time_complexity = complexity(size, dominant_operation);

    cout<< "Czy liczba operacji dominujacych zgadza sie z oszacowaniem:"<<endl;
   
    if(dominant_operation < pow(SIZE_OF_ARRAY,2)){
        cout<< "Tak, bo "<< dominant_operation << " < " << pow(SIZE_OF_ARRAY,2)<<endl;
    } else {
        cout<< "Nie, bo "<< dominant_operation << " > " << pow(SIZE_OF_ARRAY,2)<<endl;
    }
    cout<< "Dla tego zestawu danych algorytm ma zlozonosc czasowa rowna: "<< time_complexity << endl;
    cout<<"------------------------------------------------------------------------"<<endl<<endl;
    
    
    
    cout<<"-------------------------Pesymistyczna zlozonosc-------------------------"<<endl;
    string O_pesimistic = pesimistic_complexity(SIZE_OF_ARRAY); 
    cout<<"Pesymistyczna zlozonosc czasowa algorytmu: "<< O_pesimistic << endl;;

    cout<<"-----------------------------------------------------------------------"<<endl<<endl;


    cout<<"----------------------------Srednia zlozonosc---------------------------"<<endl;
    string O_average = average_complexity(SIZE_OF_ARRAY);
    cout<<"Srednia zlozonosc czasowa algorytmu: " << O_average <<endl;
    cout<<"------------------------------------------------------------------------"<<endl<<endl;
    // int average_args[2];
    // copy_array(args, average_args, 2);

    cout<<"----------------------------Miara wrazliwosci---------------------------"<<endl;
    cout<<"Miara wrazliwosci pesymistycznej: "<< pessimistic_sensitivity(O_pesimistic, O_average)<<endl;;
    cout<<"------------------------------------------------------------------------"<<endl<<endl;

}



