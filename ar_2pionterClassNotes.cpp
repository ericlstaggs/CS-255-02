#include <iostream>

using namespace std;

void Resize(int*& array, int&size){
    int increase;
    cout << "How much bigger";
    cin >> increase;
    int* temp = new int[size + increase];//creates a new larger array
    //copy array to temp
    int i = 0;
    for (int i = 0 ; i < size; i++){
        temp[i] = array[i];
    //generate values for the new section
    for ( ; i < size + increase; i++){
        temp[i] = rand()%100;
    //update size
    size = size + increase;
    //deallocate old array
    delete [] array;
    //reassign the new array 
    array = temp;
}

int main() {

    int size =0;
    cout << "What size array?"<<endl;
    cin>>size;
    int *ar = new int[size];
    for(int i =0; i <size,i++){
        ar[i] = rand()%100;

    
    }

    for(int i = 0 i < size, i++){
        cout << ar[i] << endl;
    }
    
    Resize(ar, size);


    delete [] ar; //dynamically deallocate the array
    ar = nullptr;
    return 0;
}