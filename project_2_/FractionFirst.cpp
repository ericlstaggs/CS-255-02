//**********************************
//CS 255
// Tuesday, September 01,2026 (Basic Class)
// Thursday, September 03, 2026 (operations, 
//                           overloading <<)
//**********************************

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
    Fraction Mult(const Fraction& right)const;
//    overload as a / as a friend
	friend Fraction operator/(const Fraction& left, const Fraction& right);
//	overload + as a method
	Fraction operator+(const Fraction& right);
//	overload - as a friend function
	friend Fraction operator-(const Fraction& right);
	
    Fraction Div(const Fraction& right)const;
    Fraction Add(const Fraction& right)const;
    Fraction Sub(const Fraction& right)const;
    friend ostream& operator<<(ostream& os, const Fraction& right);
    friend istream& operator>>(istream& is, Fraction& right);
    Fraction operator*(const Fraction& right);
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
Fraction Fraction::operator*(const Fraction& right){
	Fraction temp;
    temp.num  = num * right.num;            
    temp.den = den * right.den;
    return temp;
}

Fraction Fraction::Mult(const Fraction& right)const{
    Fraction temp;
    temp.num  = num * right.num;            
    temp.den = den * right.den;
    return temp;
//////////////////////////////////////
  /*  int t_num = num * right.num;
    int t_den = den * right.den;
    Fraction temp(t_num, t_den);
    return temp;
//////////////////////////////////////
    Fraction temp(num*right.num, den*right.den);
    return temp;*/
}
Fraction operator/(const Fraction& left, const Fraction& right){
	Fraction temp;
	temp.num = left.den * right.num;
	temp.den = left.num * right.den;
	
    return temp;
}

Fraction Fraction::Div(const Fraction& right)const{
    Fraction temp;
    temp.num = num * right.den;
    temp.den = den * right.num;
    return temp;
}
Fraction operator+(const Fraction& right){
	Fraction temp;
    temp.num = num * right.den + den * right.num;
    temp.den = den * right.den;
    return temp;
}

Fraction Fraction::Add(const Fraction& right)const{
    Fraction temp;
    temp.num = num * right.den + den * right.num;
    temp.den = den * right.den;
    return temp;
}

friend Fraction operator-(const Fraction& right){
	Fraction temp;
    temp.num = num * right.den - den * right.num;
    temp.den = den * right.den;
    return temp;
}

Fraction Fraction::Sub(const Fraction& right)const{
    Fraction temp;
    temp.num = num * right.den - den * right.num;
    temp.den = den * right.den;
    return temp;
}

ostream& operator<<(ostream& os, const Fraction& right){
    os << right.num << "/" << right.den;
    return os;
}

istream& operator>>(istream& is, Fraction& right){
	char dummy;
	is >> right.num >> dummy >> right.den;
	if(right.den == 0){
		right.den = 1;
	}
	return is;
}




//********************************************
// Driver
// Driver.cpp
//********************************************



int main(){

	Fraction f1(3,4), f2(1,2);
	cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
	
	cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;
	
	cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;

	cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;

//	f1.Print(); 
//	cout << endl;
//
//
//	cout << "Input Fraction n/d" << endl;
//	cin >> f1;
//
//	cout << f1 << endl;





//first day
//    Fraction f1(3,4);
//    f1.Print(); cout << endl;
//
//    Fraction f2(1,2);
//    f2.Print(); cout << endl;
//
//    cout << "*******MULT*********" << endl;
//    Fraction f3;
//    f3 = f1.Mult(f2);
//    f3.Print(); cout << endl;
//    cout << "*******DIV*********" << endl;
//    
//    f3 = f1.Div(f2);
//    f3.Print(); cout << endl;
//    cout << "*******ADD*********" << endl;
//    
//    f3 = f1.Add(f2);
//    f3.Print(); cout << endl;
//    cout << "*******SUB*********" << endl;
//    f3 = f1.Sub(f2);
//    f3.Print(); cout << endl;
//    cout << "****************" << endl;
//
//    cout << "NEW PRINT" << endl;
//    cout << f3 << endl;

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