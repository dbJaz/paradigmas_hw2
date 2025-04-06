#include <iostream>
#include <iomanip>
#include <string>
#include "subClases.hpp"
using namespace std;


int main(){
    
    cout <<"\n------------SAVINGS BANK------------------" << endl;
    SavingsBank savings;
    SavingsBank savings2("Marianela", 150);

    cout << "\nTEST: Savings bank default constructor: " <<endl;
    savings.showInfo();

    cout << "\nTEST: Savings bank constructor with values: " << endl;
    savings2.showInfo();

    savings2.withdraw(75);
    cout << "\nTEST: Withdrew $75: " << endl;
    savings2.showInfo();

    cout << "\nTEST: Depositing $66 and $20 should be removed because I have used showedInfo three times: " << endl;
    savings2.deposit(66);
    savings2.showInfo();

    cout << "\nTEST: Will try to withdraw $198, but there is not enough money in the account: " << endl;
    savings2.withdraw(198);
    

    cout <<"\n------------CHECKING ACCOUNT------------------" << endl;

    CheckingAccount checking;
    CheckingAccount checking2("Bertram", 11);
    SavingsBank savings3("Bertram", 87);



    cout << "\nTEST: Checking account default constructor: " << endl;
    checking.showInfo();

    cout << "\nTEST: Checking account constructor with values: " << endl;
    checking2.showInfo();


    cout << "\nTEST: Withdrawing $5: " << endl;
    checking2.withdraw(5);
    checking2.showInfo();

    
    cout << "\nTEST: Depositing $18: " << endl;
    checking2.deposit(18);
    checking2.showInfo();


    cout << "\nTEST: Will try to withdraw $164, there is not enough money in the cheking account and no savings account asociated: " << endl;
    checking2.withdraw(164);
    checking2.showInfo();

    cout << "\nTEST: Will try to withdraw $164, there is not enough money in either accounts: " << endl;
    checking2.setSavings(&savings3); //asocio la cuenta de ahorros de bertram a su cuenta corriente. 
    checking2.withdraw(164);
    checking2.showInfo();


    cout << "\nTEST: Will try to withdraw $38, there is not enough money in the cheking account but there is in the savings: " << endl;
    checking2.withdraw(38);
    checking2.showInfo();

    cout << "\n";
    return 1;
}   