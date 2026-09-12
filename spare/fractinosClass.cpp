#include <iostream>
using namespace std;

//***************************************************
//Class declaration (header, prototype, interface)
//Fraction.h
//***************************************************
class Fraction{
	int num;  //private data member (private by default)
	int den;  //private data member
	
public:
	Fraction(); //constructor note: not return type and same as class
	Fraction(int n); //convert a wholde number toa fraction
	Fraction(int n, int d);
	void Print()const; // print method
	void Multiply();
	void Input(); //Input method
	void Create();
	
	
};

//***************************************************
//Class definitions(implementation)
//Fraction.cpp
//***************************************************
Fraction::Fraction(){ //className:: tells the comiler this is a method
								//belonging to the className
	num = 0;
	den = 1;
}
Fraction::Fraction(int n){
	num = n;
	den = 1;
}
Fraction::Fraction(int n, int d){
	num = n;
	if(d == 0){
		d = 1;
	} else {
		den = d;
	}
}

void Fraction::Print()const{
	cout << num << "/" << den;
}
void Fraction::Input(){
	char bobby;
	cin >> num >> bobby >> den;
	if(den == 0){
		den = 1;
	}
}

//***************************************************
//Driver
//Driver.cpp
//***************************************************

//in class building  class for fractions

int main(){
	Fraction f;
	f.Print();
	cout << endl;
	
	Fraction f1(55);
	f1.Print();
	cout << endl;
	
	Fraction f2;
	cout << "Enter a fraction in the form of n/d: ";
	f2.Input();
	f2.Print();
	
	return 0;
}