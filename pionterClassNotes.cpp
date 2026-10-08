#include <iostream>

using namespace std;

int main(){
    int *ptr = nullptr;

    cout << ptr << endl;
//    cout << *ptr << endl;
    ptr = new int; 

/*
ptr = new int; 
dynamically allocates an intyeger variable 
on the heap and returns  the address to be stored into ptr
*/

cout << ptr << endl;
*ptr = 1000;
cout << *ptr << endl;

delete ptr;//dynamically deallocates the integer variable 
ptr = nullptr;//resets the pointer to null


//    what new returns is an address
    

    return 0;
}