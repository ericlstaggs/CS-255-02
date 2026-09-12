#include <iostream>
using namespace std;

//Eric Staggs
//CS 255-02
//8/26/2026
//Investment Accounts
//create a menu to create investment accounts and print them


//create a return function for a  user intereface
int menu(){
	
	int menuItem;
		cout << "-----------Menu------------" << endl;
		cout << "1) Prinnt All Investment Accounts" << endl;
		cout << "2) Add an Investment Account" << endl;
		cout << "3) Delete and Investment Account" << endl;
		cout << "0) Quit" << endl;
		cin >> menuItem;
		
	return menuItem;
}


void printArray(int passedArr[], int num){
	
//	int thisArray[10] = {1,2,3,4,5,6,7,8,9,10};
	for	(int i = 0; i < num; i++){
		cout << passedArr[i] << ", " ;
	}
	cout << endl;
}

void fillArray(int arr[], int num){
	
   // 1. Initialize the random number engine with a random seed
    random_device rd;  
    mt19937 gen(rd()); 

    // 2. Define the range of random numbers (inclusive, e.g., 1 to 100)
    uniform_int_distribution<> distr(1, 100); 

    // 3. Fill the array using a loop
    for (int i = 0; i < num; ++i) {
        arr[i] = distr(gen);
    }
	
}

int main() {
//	create a holder for the input
	int menuItem;
	const int SIZE = 10;
	int myArr[SIZE];
	int testArr[SIZE] = {10,9,8,7,6,5,4,3,2,1};
	
//do while statement to out put the menu before checking a condition
    do {
    	menuItem = menu();
    	
    	switch(menuItem){
			case 1:	
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 0:
				cout << "Thank you, Have a blessed day!" << endl;
				break;
			}
		} while (menuItem != 0);
	
   return 0;      
}