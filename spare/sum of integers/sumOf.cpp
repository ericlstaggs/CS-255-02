#include <iostream>
using namespace std;

int main() {
    int number;

    cout << "Enter an integer: ";
    cin >> number;


	// Set the variable equal to input
	int temp = number;
	int sum = 0;
	// control loop to get the remainder and remove the last digit
	while(temp > 0){
		// sum is equal to the remainder or the stripped number
		sum += temp % 10;
		// removing the last digit
		temp /= 10;
	}
	
	// output the results in sentence form
	cout << "The sum of the integer is : "<< sum << endl;
	
    return 0;
}
