/* Program to demonstrate Banking Management System */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Bank
{
    long account_balance;
    string customer_name;
    string account_number;
    
    public:
        void openAccount();
        void showAccount(string);
        void Deposit(string acctNum, long amount);
        void Withdraw(string acctNum, long amount);
};

vector<Bank*> list_of_accounts;

int main()
{
    Bank acctObj;
    string tempNum;
    long depositAmt, withdrawAmt;
    int choice = 0;
    do
    {
        cout << "*******************************" << endl;
        cout << "Banking Management System Menu" << endl;
        cout << "*******************************" << endl;
        cout << "1. Open an account\n2. Display an account\n3. Deposit\n4. Withdraw\n5. Quit Menu" << endl;
        cout << "________________________________" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1: acctObj.openAccount();
                    list_of_accounts.push_back(&acctObj);
                    break;
            case 2: cout << "Inquiry: Enter the account number: ";
                    cin >> tempNum;
                    acctObj.showAccount(tempNum);
                    break;
            case 3: cout << "Deposit: Enter account number: ";
                    cin >> tempNum;
                    cout << "Enter amount to deposit: ";
                    cin >> depositAmt;
                    acctObj.Deposit(tempNum, depositAmt);
                    break;
            case 4: cout << "Withdraw: Enter account number: ";
                    cin >> tempNum;
                    cout << "Enter amount to withdraw: ";
                    cin >> withdrawAmt;
                    acctObj.Withdraw(tempNum, withdrawAmt);
                    break;
            case 5: cout << "Exiting from menu" << endl;
                    return 0;
            default: cout << "Wrong choice entered" << endl;
        }
    }while(choice < 6);
    cout << "End of Bank Management System" << endl;
    return 0;
}


/*************************************************************
* Function Name : openAccount()
* Description   : To open an account
* User inputs   : Customer Name, Account Number, Account Opening
*                 Balance
* Returns       : None
**************************************************************/
void Bank::openAccount()
{
    cout << "Enter customer name: ";
    cin >> customer_name;
    cout << "Enter account number: ";
    cin >> account_number;
    cout << "Enter account opening balance: Rs ";
    cin >> account_balance;
}

/*************************************************************
* Function Name : showAccount()
* Description   : To display an account details.
* User inputs   : Account Number
* Returns       : None
**************************************************************/
void Bank::showAccount(string acctNum)
{
    for (auto iterator : list_of_accounts)
    {
        if((iterator->account_number).compare(acctNum) == 0)
        {
            cout << "Account Details are displayed below" << endl;
            cout << "Account Number: " << acctNum << endl;
            cout << "Customer name: " << iterator->customer_name << endl;
            cout << "Account Balance: Rs " << iterator->account_balance << endl;
            return;
        }
    }
    cout << "Account doesn't exist! " << endl;
}

/*************************************************************
* Function Name : Deposit()
* Description   : To deposit amount to an account.
* User inputs   : Account Number, Deposit amount
* Returns       : None
**************************************************************/
void Bank::Deposit(string tempAcctNum, long amount)
{
    for (auto iterator : list_of_accounts)
    {
        if((iterator->account_number).compare(tempAcctNum) == 0)
        {
            iterator->account_balance += amount;
            cout << "Account Balance: Rs " << iterator->account_balance << endl;
            return;
        }
    }
    cout << "Account doesn't exist! " << endl;
}

/*************************************************************
* Function Name : Withdraw()
* Description   : To Withdraw amount from an account.
* User inputs   : Account Number, Withdraw amount
* Returns       : None
**************************************************************/
void Bank::Withdraw(string tempAcctNum, long amount)
{
    for (auto iterator : list_of_accounts)
    {
        if((iterator->account_number).compare(tempAcctNum) == 0)
        {
            if(iterator->account_balance <= 0)
            {
                cout << "Withdraw aborted due to insufficient balance" << endl;
                return;
            }
            iterator->account_balance -= amount;
            cout << "Account Balance: Rs " << iterator->account_balance << endl;
            return;
        }
    }
    cout << "Account doesn't exist! " << endl;
}