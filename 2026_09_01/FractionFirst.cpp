#include <iostream>
using namespace std;
//********************************************
// class declaration (header, protype, interface)
// Fraction.h
//********************************************

class Fraction{
    int num;    //private data member (private by default)
    int den;    //private data member 
public:
    Fraction(); //constructor note: no return type and same name as class
    Fraction(int n); //convert a whole number to a fraction
    Fraction(int n, int d); //build a fraction with 2 ints
    void Print()const; //Print method
    void Input(); //Input Method
    Fraction Mult(const Fraction& right) const;
    Fraction Div(const Fraction& right) const;
    Fraction Add(const Fraction& right) const;
	Fraction Sub(const Fraction& right) const;
	friend ostream& operator<<(ostream&os, const Fraction& right);
//	Fraction Reduce(const Fraction& right) const;
    
};


//********************************************
//class definition (implementation)
// Fraction.cpp
//********************************************
Fraction::Fraction(){  //className:: tells the compiler this is a method
                       // belonging to className
    num = 0;
    den = 1;
} 

Fraction::Fraction(int n){
    num = n;
    den = 1;
}

Fraction::Fraction(int n, int d){
    num = n;
    if (d == 0)
        d = 1;
    den = d;
}

void Fraction::Print()const{
    cout << num << "/" << den;
}

void Fraction::Input(){
    char bobby;
    cin >> num >> bobby >> den;
    if (den == 0)
        den = 1;
}

Fraction Fraction::Mult(const Fraction& right) const{
	int top = num * right.num;
	int bottom =  den * right.den;
	
	Fraction a(top, bottom);
	return a;
	
	//num //access to calling object numerater
	//right.num //access to the parameter num
}

Fraction Fraction::Div(const Fraction& right) const{
	int top = num * right.den;
	int bottom = den * right.num;
	
	Fraction a(top, bottom);
	return a;
}

Fraction Fraction::Add(const Fraction& right) const{
	Fraction temp;
	temp.num = num * right.den + den * right.num;
	temp.den = den * right.den;
	return temp;
}

Fraction Fraction::Sub(const Fraction& right) const{
	Fraction temp;
	temp.num = num * right.den - den * right.num;
	temp.den = den * right.den;
	return temp;
}

ostream& operator<<(ostream& os, const Fraction& right){
	os << right.num << "/" << right.den;
	return os;
}


//********************************************
// Driver
// Driver.cpp
//********************************************
int main(){

    Fraction f1(3,4);
    f1.Print(); cout << endl;

    Fraction f2(1,2);
    cout << "Enter a fraction in the form n/d: ";
    f2.Print(); cout << endl;
    
    Fraction f3;
    f3 = f1.Mult(f2); cout << "mult" << endl;
    
    
    f3.Print(); cout << endl;
    
    Fraction f4;
    f4 = f1.Div(f2); cout << "div" << endl;
    
    f4.Print();	cout << endl;

    
    Fraction f5;
    f5 = f1.Add(f2); cout << "add" << endl;
    
	f5.Print();	cout << endl;
	
	Fraction f6;
	f5 = f1.Sub(f2); cout << "sub" << endl;
	
	f5.Print();
	
	cout << f5;
    return 0;
}

/*
parallel arrays to struct
struct properties and shortcomings (default public)
class differences  (default private)
Data Type 2 traits and how that drives everything we do from here on
Data Type Concept
Data Type Declaration
Data Type Definition
Data Type Instantiation (use)
Language around Objects 
-encapsulation
-data members, methods
-source->executable life cycle
-build class piece by piece


*/