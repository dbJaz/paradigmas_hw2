#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class BankAccount{//clase abstracta, asi que ALGUNOS de sus metodos van a ser virtuales puros. Si todos lo fueran sería una interfaz y no es lo que se pide.
    protected: // todo lo que este en protected lo va a poder acceder la clase que hereda esta clase. Se hace protected para que savings y checking lo puedan cacceder sin necesidad de hacerlo publico. 
        double balance;
        string holder;
    public: 
        BankAccount(){//tiene sentido? yo creo que no
            balance = 0;
            holder = " ";
        }
        BankAccount (string name,double money=0){//pongo el valor del dinero por defecto a 0 por si unicamente se quiere incializar la cuenta sin plata.
            balance = money;
            holder = name;
        }
        virtual ~BankAccount(){
            cout << "Bank account destructor" << endl;
        }//destructor

        void deposit(double money){
            balance = balance + money;
        }
        //metodos virtuales puros
        virtual void withdraw(double money)=0;
        virtual void showInfo()=0;
};

class SavingsBank: public BankAccount{// hereda bank account publicamente para que los objetos de savings bank puedan acceder a los metodos publicos de bank account como publicos. En otras palabras, que los metodos publicos de bank account los puedan acceder objetos de la clase savings bank en el main, como por ejemplo en la linea 110.
    private: 
        int counter;//es pñrivado porque ninguna clase que no sea saavings bank deberia tener la necesidad de utilizarlo.
    public: 
        SavingsBank() : BankAccount(){// se inicializa con los valores que se pusieron en bank account. Y se agrega counter porqye es privado de savings. 
            counter = 0;
        }
        SavingsBank(string name, double money=0): BankAccount(name,money){
            counter = 0;
        }
        ~SavingsBank(){ 
            cout << "Savings bank destructor" << endl;
        }

        void withdraw(double money) override {
            if (money > balance){
                cout << "There´s not enough money in the account to withdraw" << endl;
            }else{
                balance = balance - money;
            }
        }
        void showInfo() override {
            if (counter == 2){
                cout << "The account has been charged with a $20 fee because the information has been showed already two times." << endl;
                if (balance < 20){
                    balance = 0;
                }else {
                balance = balance -20;
                counter =0;
            
            }
            }
            cout <<"Holder: " << holder << "\n" << "Balance: $" << balance << endl;
            counter = counter + 1;
            if (counter == 2){
                cout <<"If the information is requested one more time, the account will be charded a $20 fee."  << endl;
            }
        }
        friend class CheckingAccount; //le doy acceso a la clase cheking account, para que pueda ver el balance. 
    };

class CheckingAccount: public BankAccount{// se hace public por la misma razon anterior. 
    private: 
        SavingsBank* savings; //puntero a savings bank, para poder acceder al balance de esta cuenta. Es private por la misma razon anterior. Esta relacionm no necesita accerdela ninguna clase que no sea esta. 
    public: 
        CheckingAccount() : BankAccount(){
            savings = nullptr; //inicializo el puntero a null, porque todavia no hay una cuenta de ahorros asociada.
        }
        CheckingAccount(string name, double money=0): BankAccount(name,money){}
        ~CheckingAccount(){
            cout << "Cheking account destructor" << endl;
        }

        void setSavings(SavingsBank* saving){
            savings = saving;
        }

        void withdraw(double money) override {
            if (savings == nullptr && (money > balance)){
                cout << "There is not enough money in the account to withdraw and no savings account asociated." << endl;
            }
            else if (money > balance && money > savings->balance){
                cout << "There is no enough money in both, cheking and savings accounts. The money won´t be withdrawed" << endl;
            }else{
            balance = balance - money;}
        }
        void showInfo() override {
            cout << "Holder: " << holder << "\n"<< "Balance: $" << balance << endl;
        }

};

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