#include <iostream>
#include <iomanip>
#include <string>
#include "bankAccount.hpp"
using namespace std;


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
