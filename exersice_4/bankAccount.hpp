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
