#include <iostream>
#include <array> 
#include <string>
using namespace std;

//Eric Staggs
//CS 255-02
//9/10/2026
//Money Class
//create a class that is money and holds dollars and cents

class Money{
	//Money varialbes
	int dollars; //represents the whole dollar ammount
	int cents; //represents the cents ammount
	
	public:	
	
	friend ostream& operator<<(ostream os, const Money& pay);
	friend istream& operator>>(istream is, const Money& pay);
	void makeValid();
	int getCents();
	int getDollars();
	int setCents(int coins);
	int setDollars(int coins);

//	constuctor that takes no arguments	
	Money(){
		dollars = 0;
		cents = 0;
	}
//	constructor that takes cents
	Money(int coins){
		cents = coins;
		dollars = 0;
	}
//	constructor that takes both doallars and cents
	Money(int bucks, int coins){
		dollars = bucks;
		cents = coins;
	}
};


	ostream& operator<<(ostream os, const Money& pay){
		
		return os;
	}
	istream& operator>>(istream is, const Money& pay){
		
		return is;
	}

//********************************************
//class definition (implementation)
//********************************************
	
	void makeValid(){
		cout << "temp code" << endl;		
	}
//	fucntion that will return an integer of cents
	int getCents(){
		return cents;
	}
//	function that will return an integer of dollars
	int getDollars(){
		return dollars;
	}
//	function to set the cents ammount 
	int setCents(int coins){
		const int DOLLAR = 100;
		int c;
		if(coins > DOLLAR){
			c = coins % DOLLAR;
		} else if(coins < 0){
			coins = 0;
		} else {
			c = coins;
		}
		return coins;
	}
//	funcion to set the dollar ammount
	int setDollars(int bucks){
		dollars = bucks;
	}


//main program
int main(){
	
	return 0;
}