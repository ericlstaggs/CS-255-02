#include <iostream>
using namespace std;

##Eric Staggs
##CS 255-02 
##21Aug2026
##Take input from user as an int 
##and add all the numbers up for a sum

int main() {
	
	#create values for the sum and user input as integers
	int num = 0;
	int sum = 0;
	int temp = 0;
	
	#output to cmd line text
	cout << "Enter an Integer" ;
	#get user input and store
	cin >> num;
	
	#Set the variable equal to input
	temp = num;
	
	#control loop to get the remainder and remove the last digit
	while(temp > 0){
		#sum is equal to the remainder or the stripped number
		sum += temp % 10;
		#removing the last digit
		temp /= 10;
	}
	
	#output the results in sentence form
	cout << "The sum of the integer is : "<< sum << endl;
	
	return 0;
}