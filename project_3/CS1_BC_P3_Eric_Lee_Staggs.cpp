//Eric Staggs
//CS 255-02
//9/11/2026
//Investment Accounts
//create a menu to create investment accounts and print them
//proj 3

#include <iostream>
#include <array>
#include <string>
#include <cmath>

using namespace std;

class Account {
// private fields
private:
    string fName, lName;
    int acctNum;
    double balance;
    string date;

public:
    // Default mo arg constructor 
    Account() {
        fName = "";
        lName = "";
        acctNum = 0;
        balance = 0.0f;
    }

    // Constructor with parameters
    Account(string firstName, string lastName, int aNum, double bal) {
        fName = firstName;
        lName = lastName;
        acctNum = aNum;
        balance = bal;
    }

    // create getters
    string getfName() { 
		return fName; 
	}
    string getlName() {
		return lName;
	}
    int getacctNum() { 
		return acctNum; 
	}
    float getBalance() { 
		return balance; 
	}

    // create setters
    void setfName(string n) { 
		fName = n; 
	}
    void setlName(string n) { 
		lName = n; 
	}
    void setacctNum(int num) { 
		acctNum = num; 
	}
    void setbalance(double bal) { 
		balance = bal;
		
	}

    // Print function
    void print() const {
        cout << "-------------------------------------" << endl;
        cout << "First Name: " << fName << endl;
        cout << "Last Name: " << lName << endl;
        cout << "Account Number: " << acctNum << endl;
        cout << "Balance: $" << balance << endl;
        cout << "-------------------------------------" << endl;
    }
};

/******************************************************
Function declarations 
*****************************************************/
int menu();
void printAll(const Account p[], int currentCount);
Account inputAcct();
void addAccount(Account p[], int maxSize, int& currentCount);
void deleteAccount(Account p[], int& currentCount);
//project 3 addition to project 2 class declarations (this is to help me)
Account sortLastName(Account p[], int& currentCount);
Account sortByNum(Account p[], int& currentCount);
void updateField(Account p[], int& currentCount);
double calRate(double currBal, double apr, int periods, int years);
void printAccBal(Account a);

int main() {
    int menuItem;
    const int SIZE = 10;
    Account portfolio[SIZE];//this just initializes so we can run the program
    int currentCount = 0; //  the actual number of active accounts

    // test accounts can be uncommented to speed up the testing
    portfolio[currentCount] = Account("Eric", "Staggs", 8675309, 55.35);
    currentCount++;
    portfolio[currentCount] = Account("Jane", "Doe", 654987, 8555.31);
    currentCount++;    
	portfolio[currentCount] = Account("Will", "Roberson", 123456, 546135.39);
    currentCount++;
    portfolio[currentCount] = Account("Jennifer", "Staggs", 123, 100000.00);
    currentCount++;

    // do while statement to output the menu before checking a condition
    do {
        menuItem = menu();
        switch(menuItem){
            case 1:
                printAll(portfolio, currentCount);
                break;
            case 2:
                addAccount(portfolio, SIZE, currentCount);
                break;
            case 3:
                deleteAccount(portfolio, currentCount);
                break;
            case 4:
            	sortLastName(portfolio, currentCount);
            	break;
            case 5:
            	sortByNum(portfolio, currentCount);
            	break;
            case 6:
            	updateField(portfolio, currentCount);
            	break;
            case 0:
                cout << "Thank you, Have a blessed day!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while(menuItem != 0);

    return 0;
}




void printAccBal(Account a){
		cout << "Account number: " << a.getacctNum() << endl;
		cout << "Account Balance: " << a.getBalance() << endl;
	
}
/******************************************************
Function that takes 4 paramaters and calculates interest
and returns the new balance after rate calculation
pricipal for the starting balance
apr is the rate at which the calcutlation is to be done
periods for the number of times in the apr
and years for the amout of years to calculate
returns the balance plus the interest

I would like to add that I had to google the formulas
and I had to go to https://www.w3schools.com/cpp/ref_math_pow.asp
to look up the paramater list for the pow() function
*****************************************************/
double calRate(double principal, double apr, int periods, int years){
// 	Formula: A = P * (1 + r/n)^(n*t)
//	A = final balance
//	P = principal
//	r = apr
//	n = the number of periods
//	t = years
	double r = apr / 100; //convert to a percentage
	double nt = years * periods;
	double n = periods;
	double finalBal = principal * pow(1 + r/n, nt);
	
	return finalBal;
}
/******************************************************
Function that takes 2 paramaters and searches for an
account, prints the total accounts with tha last name
then asks for the first name to id the correct account
takes two paramaters
an array of type Account
a number representing the array size
*****************************************************/
Account sortLastName(Account p[], int& currentCount){
	string name, temp;
	const int SIZE = 10;
	Account list[SIZE];
	int acctNum = -1;
	Account n;
	
	cout << "Please enter the last name of the account." << endl;
	cin >> name;

	for(int i = 0; i < currentCount; i++){
		temp = p[i].getlName();
		if(temp == name){
			++acctNum;
			Account n;
			n = p[i];
			p[i].print();
			list[acctNum] = n;
			++acctNum;
		} 	
	}
	if(acctNum < 0){
		cout << "Sorry no match." << endl;
	}
	if(acctNum > 0){
		string f;
		
		cout << "\n---------------------------" << endl;
		cout << "There is more than one account with that last name." << endl;
		cout << "Here are the account names" << endl;
		cout << "\n---------------------------" << endl;

		for(int i =0;i < acctNum; i++){
			cout << list[i].getfName() << endl;
		}
		cout << "Chose the first name of the account" << endl;
		cin >> f;
		for(int i = 0; i < acctNum; i++){
			if(f == list[i].getfName()){
				n = list[i];
			}
		}
	}
	return n;
}
/******************************************************
Function that takes two paramaters and searches and array
for an account with the matching account
takes two paramaters
an array of type Account
a number representing the array size
*****************************************************/
Account sortByNum(Account p[], int& currentCount){
	int number, temp;
	const int SIZE = 10;
	int acctNum = -1;
	Account n;
	
	cout << "Please enter the number of the account." << endl;
	cin >> number;
	
	for(int i = 0; i < currentCount; i++){
		temp = p[i].getacctNum();
		if(temp == number){
			++acctNum;
			n = p[i];
			p[i].print();
		}
	}
	if(acctNum < 0){
		cout << "No match" << endl;
	}
	return n;
}
/******************************************************
Function that takes two paramaters will update an exsiting 
account within an array and addes it to the array
takes two paramaters
an array of type Account
a number representing the array size
returns a float
*****************************************************/
void updateField(Account p[], int& currentCount){
	int rate, menuItem, yearly, semiAnnually, quarterly, monthly, rateChoice, years;
	double newBal;
	const int SIZE = 10;

	Account acc;
	Account list[SIZE];

	cout << "How would you like to search for the account?" << endl;
	cout << "\n-----------Menu------------" << endl;
	cout << "1) Sort by last name" << endl;
    cout << "2) Sort by Account number" << endl;
    cout << "0) Quit" << endl;
    cout << "Enter option: ";
    cin >> menuItem;
    
    switch(menuItem){
    	case 1:
    		acc = sortLastName(p, currentCount);
    		acc.print();
    		break;
    	case 2:
    	    acc = sortByNum(p, currentCount);
    	    acc.print();
    		break;
    	case 0:
    		cout << "Thank you, bye!" << endl;
    		break;
    	default:
    		cout << "Thank you, bye!" << endl;
    		break;
	}
	
	cout << "Enter the interst rate ammount" << endl;
	cin >> rate;
	cout << "What type of rate is this?" << endl;
	cout << "\n-----------Menu------------" << endl;
	cout << "1. Yearly" << endl;
	cout << "2. Semi-Annually" << endl;
	cout << "3. Quarterly" << endl;
	cout << "4. Monthly" << endl;
	
	cin >> rateChoice;
	
	cout << "For how many years?" << endl;
	cin >> years;
	
	newBal = calRate(acc.getBalance(), rate, rateChoice, years);
	
	for(int i = 0; i < currentCount; i++){
		if(p[i].getacctNum() == acc.getacctNum()){
			acc.setbalance(newBal);
			p[i] = acc;
		}
	}
	printAccBal(acc);
}
/******************************************************
Function to add an account that takes an array 
holding Accounts and adds the desired account
takes two paramaters
an array of type Account
a number representing the array size
*****************************************************/
void addAccount(Account p[], int maxSize, int& currentCount) {
    if (currentCount >= maxSize) {
        cout << "Portfolio is full! Cannot add more accounts." << endl;
        return;
    }
    
    // Get the new account data from input function
    p[currentCount] = inputAcct();
    currentCount++; //increase count
}

/******************************************************
Function to delete an account that takes an array 
holding Accounts and removes the desired account
takes two paramaters
an array of type Account
a number representing the array size
*****************************************************/
void deleteAccount(Account p[], int& currentCount) {
    if (currentCount == 0) {
        cout << "No accounts available to remove." << endl;
        return;
    }

    cout << "What account do you want to remove? (Enter line number)" << endl;
    for (int i = 0; i < currentCount; i++) {
        cout << (i + 1) << ") Acct #" << p[i].getacctNum() << " - " << p[i].getfName() << " " << p[i].getlName() << endl;
    }

    int remove;
    cin >> remove;

    // Validate the user's choice range
    if (remove < 1 || remove > currentCount) {
        cout << "Invalid selection." << endl;
        return;
    }

    // Convert to 0-based index
    int targetIndex = remove - 1;

    // Shift elements to the left to overwrite the target object
    for (int i = targetIndex; i < currentCount - 1; i++) {
        p[i] = p[i + 1]; 
    }

    // Decrement the active count
    currentCount--;
    cout << "Account successfully removed." << endl;
}

/******************************************************
Function to create a new account 
that returns an Account object 
takes no paramaters
*****************************************************/
Account inputAcct() {
    string first, last;
    int num;
    float bal;

    cout << "Enter the first name: " << endl;
    cin >> first;
    cout << "Enter the last name: " << endl;
    cin >> last;
    cout << "Enter the account number: " << endl;
    cin >> num;
    cout << "Enter the starting balance: " << endl;
    cin >> bal;

    Account newAcct(first, last, num, bal);
    cout << "Account successfully created" << endl;
    return newAcct;
}

/******************************************************
Function to print all elements in an array containing accounts
takes two paramaters
an array of type Account
a number representing the array size
*****************************************************/
void printAll(const Account p[], int currentCount) {
    if (currentCount == 0) {
        cout << "No active investment accounts found." << endl;
        return;
    }

    cout << "--- Printing Active Accounts ---" << endl;
    for(int i = 0; i < currentCount; i++) {
        p[i].print();
    }
}

/******************************************************
Function to display interface takes no paramaters
*****************************************************/
int menu() {
    int menuItem;
    cout << "\n-----------Menu------------" << endl;
    cout << "1) Print All Investment Accounts" << endl;
    cout << "2) Add an Investment Account" << endl;
    cout << "3) Delete an Investment Account" << endl;
    cout << "4) Sort by last name" << endl;
    cout << "5) Sort by Account number" << endl;
    cout << "6) Update and Print Current Value" << endl;

    cout << "0) Quit" << endl;
    cout << "Enter option: ";
    cin >> menuItem;
    return menuItem;
}
