//Eric Staggs
//CS 255-02
//9/9/2026
//Investment Accounts
//create a menu to create investment accounts and print them

//***************************************************************************************
// CS 1 Boot Camp Rudimentary Solution
// Note: this is a basic implementation. It does not include formatting output
// guidelines, but provides the basic functionality.
// You may use this to revamp your version for Project 2.
// If you do, note this in the comment header
//***************************************************************************************

#include <iostream>
using namespace std;

const int MAX = 5;
const string DASH = "----------------------";


struct InvestmentAccount{
	int acctNo;
	string lastName;
	string firstName;
	double initBal;
	unsigned short month;
	unsigned short day;
	unsigned short year;
	double curBal;
	double intRate;
	int compFreq;
	
};

//declare fucntion menu
void menu();

int main(){
	
	InvestmentAccount list[MAX];
	int size = 0;
//	calling the menu
	menu();
	
	return 0;
}

void menu(){
	
	InvestmentAccount list[MAX];
	int size = 0;
	
	list[0].acctNo = 1;
	list[0].lastName = "Smith";
	list[0].firstName = "Jane";
	list[0].initBal = 100;
	list[0].month = 11;
	list[0].day = 1;
	list[0].year = 2007;
	list [0].curBal = 5043.21;
	list[0].intRate = 0.05;
	int compFreq = 1;
	
	
	list[1].acctNo = 2;
	list[1].lastName = "Smith";
	list[1].firstName = "John";
	list[1].initBal = 200;
	list[1].month = 12;
	list[1].day = 1;
	list[1].year = 2007;
	list [1].curBal = 10155.21;
	list[1].intRate = 0.07;
	list[1].compFreq = 4;	
	
	size = 2;  //change if you hardcode more
	

	int input = 0;
	
	cout << DASH << endl;
	cout << "1. Print All Investment Accounts" << endl;
	cout << "2. Add an Investment Account. " << endl; 
	cout << "3. Delete an Investment Account." << endl;
	cout << "0. Quit" << endl;
	cin >> input;
	cout << DASH << endl;
	
	while (input != 0){
		
		
		
		if (input == 1){
			cout << "PRINTING" << endl;
			for (int i = 0; i < size; i++){
				cout << "Acct. No:\t "<< list[i].acctNo << endl;
				cout << "Name:\t" << list[i].firstName << " " << list[i].lastName << endl;
				cout << "Initial Date:\t" << list[i].month <<"\\" << list[i].day << "\\" << list[i].year << endl;
				cout << "Initial Balance:\t $ " << list[i].initBal << endl;
				cout << "Current Balance:\t $ " << list[i].curBal << endl;
				cout << "Annual Interest Rate:\t " << list[i].intRate << endl;
				cout << "Compounding Frequency: \t " << list[i].compFreq;
				switch (list[i].compFreq){
					
					case 1:  cout << "Yearly" << endl; break;
					case 2:  cout << "Semi-Annually" << endl; break;
					case 3:  cout << "Quarterly" << endl; break;
					case 4:  cout << "Monthly" << endl; break;
				}
			
			}
		}
		else if (input == 2){
			cout << "ADDING" << endl;
			if (size < MAX){
				
				cout << "Account No: ";
				cin >> list[size].acctNo;
				cout << "First: " ;
				cin >> list[size].firstName;
				cout << "Last: ";
				cin >> list[size].lastName;
				cout << "Initial Balance: ";
				cin >> list[size].initBal;
				cout << "Now Enter Start Date" << endl;
				cout << "Month [1..12]: ";
				cin >> list[size].month;
				cout << "Day [1..31]: ";
				cin >> list[size].day;
				cout << "Year: ";
				cin >> list[size].year;
				cout << "Current Balance: ";
				cin >> list[size].curBal;
				cout << "Annual Interest Rate: ";
				cin >> list[size].intRate;
				cout << endl << "Now Enter Number for Compounding Frequency" << endl;
				cout <<"1. Yearly" << endl;
				cout << "2. Semi-Annually" << endl;
				cout << "3. Quarterly " << endl;
				cout << "4. Monthly" << endl;
				cin >> list[size].compFreq;
				size++;
			}
			else{
				cout << "List is Full. No adding allowed." << endl;
			}
		}
		else if (input == 3){
			cout << "DELETING" << endl;
			if (size > 0){
				int temp_acc = 1;
				int temp_pos = -1;
				cout << "Which Account Number do you want to delete? ";
				cin >> temp_acc;
				for (int i = 0; i < size && temp_pos == -1; i++){
					if (list[i].acctNo == temp_acc)
						temp_pos = i;
				}
				if (temp_pos == -1)
					cout << "Account Number not found" << endl;
				else{
					for (int pos = temp_pos; pos < size-1; pos++){
						list[pos].acctNo = list[pos + 1].acctNo;
						list[pos].firstName = list[pos + 1].firstName;
						list[pos].lastName = list[pos + 1].lastName;
						list[pos].initBal = list[pos + 1].initBal;
						list[pos].month = list[pos + 1].month;
						list[pos].day = list[pos + 1].day;
						list[pos].year = list[pos + 1].year;
						list[pos].curBal = list[pos + 1].curBal;
						list[pos].intRate = list[pos + 1].intRate;
						list[pos].compFreq = list[pos + 1].compFreq;						
					}
					size--;
				}
				
			}
			else{
				cout << "List is Empty. No deleting allowed." << endl;
			}
		}
		else{
			cout << "INVALID INPUT" << endl;
		}
		cout << endl;
		cout << DASH << endl;
		cout << "1. Print All Investment Accounts" << endl;
		cout << "2. Add an Investment Account. " << endl; 
		cout << "3. Delete an Investment Account." << endl;
		cout << "0. Quit" << endl;
		cin >> input;
		cout << DASH << endl;
		cout << endl;
	
	}

}