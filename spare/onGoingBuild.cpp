#include <iostream>
#include <random>
using namespace std;

//Eric Staggs
//CS 255-02
//8/26/2026
//Array and Menu
//create a menu to fill and empty arrays


//create a non return function for a  user intereface
int menu(){
	
	int menuItem;
		cout << "-----------Menu------------" << endl;
		cout << "1) Fill Array" << endl;
		cout << "2) Sort" << endl;
		cout << "3) Empty place" << endl;
		cout << "4) Print Array" << endl;
		cout << "5) Quit" << endl;
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
	int temp = 0;

	
//do while statement to out put the menu before checking a condition
    do {
    	menuItem = menu();
    	
    	switch(menuItem){
			case 1:	
				fillArray(myArr, SIZE);
				break;
			case 2:
				for(int i = 0; i < 30 ; i++){	
								
					if(myArr[i]> myArr[i +1]){
						temp = myArr[i];
						myArr[i] = myArr[i+1];
						myArr[i+1];
					} else {
						break;
					}
				}
				cout << "Array Sorted!" << endl;
				break;
			case 3:
				break;
			case 4:
				printArray(myArr, SIZE);
				break;
			case 5:
				cout << "Thank you, Have a blessed day!" << endl;
				break;
			}
		} while (menuItem != 5);
	
   return 0;      
}