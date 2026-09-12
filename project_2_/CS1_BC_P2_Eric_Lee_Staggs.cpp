#include <iostream>
#include <array>
#include <string>

using namespace std;

//Eric Staggs
//CS 255-02
//9/10/2026
//Investment Accounts
//create a menu to create investment accounts and print them

class Account {
// private fields
private:
    string fName, lName;
    int acctNum;
    float balance;
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
    Account(string firstName, string lastName, int aNum, float bal) {
        fName = firstName;
        lName = lastName;
        acctNum = aNum;
        balance = bal;
    }

    // create getters
    string getfName() const { 
		return fName; 
	}
    string getlName() const {
		return lName;
	}
    int getacctNum() const { 
		return acctNum; 
	}
    float getBalance() const { 
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
    void setbalance(float bal) { 
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

// Declaring functions
int menu();
void printAll(const Account p[], int currentCount);
Account inputAcct();
void addAccount(Account p[], int maxSize, int& currentCount);
void deleteAccount(Account p[], int& currentCount);

int main() {
    int menuItem;
    const int SIZE = 10;
    Account portfolio[SIZE];
    int currentCount = 0; //  the actual number of active accounts

    // test account
    portfolio[currentCount] = Account("Eric", "Staggs", 8675309, 55.35);
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

/******************************************************
Function to add an account that takes an array 
holding Accounts and adds the desired account
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
Function to display interface
*****************************************************/
int menu() {
    int menuItem;
    cout << "\n-----------Menu------------" << endl;
    cout << "1) Print All Investment Accounts" << endl;
    cout << "2) Add an Investment Account" << endl;
    cout << "3) Delete an Investment Account" << endl;
    cout << "0) Quit" << endl;
    cout << "Enter option: ";
    cin >> menuItem;
    return menuItem;
}
