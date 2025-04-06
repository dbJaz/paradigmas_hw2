#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Number{//clase abstracta pura o intefaz porque todos sus metodos son virtuales puros.
    public: 
       //operaciones pedidas
        virtual ~Number()=0;//destructor, no se declara nada para que number sea una interfaz y obkiga a las clases derivadas a poner su destructor.
        virtual string toString()=0;//la igualo a 0 para hcerla una clase virtual pura, o abstracta. Si no la igualo a 0 y hago que retorne un string, todas las clases derivadas de esta debrian sobreescribirla.
       //el virtual hace que las clases que deriven de esta obligatoriamente implementen este método sobreescribiendolo. 
        virtual void sum( const Number& num)=0;
        virtual void substract(const Number& num)=0;
        virtual void multiply(const Number& num)=0;
        virtual void divide(const Number& num)=0;
};
Number::~Number() {
    cout << "Number destructor" << endl;
}//ASe debe definir el destructor de la clase abstracta pura. Como la clase es abstracta pura, no se puede definir dentro de la clase. 

class Whole: public Number {
    private: 
        int number;
    public: 
        Whole(){
            number = 0;
        }
        Whole(int num){
            number = num;
        }
        ~Whole(){
            cout << "Whole destructor" << endl;
        }
        void setNumber(int num){
            number = num;
        }

        //metodos pedidos
        string toString() override{
            string num = to_string(number);
            return num;
        }
        void sum( const Number& num) override{ // se le pasa un numero constante ya que num no va a sufrir modificiaciones dentro de estas funciones. Num se pasa por referencia para evitar hacer una copia del objeto. Override sobreescribe el metodo de la clase base.
            const Whole& whole = dynamic_cast<const Whole&>(num);//En esta linea uso dynamic cast para convertir una referencia de tipo number a una de tipo whole. 
            number = number + whole.number;
        }
        void substract( const Number& num) override{
            const Whole& whole = dynamic_cast<const Whole&>(num);
            number = number - whole.number;
        }
        void multiply( const Number& num) override{
            const Whole& whole = dynamic_cast<const Whole&>(num);
            number = number * whole.number;
        }
        void divide( const Number& num) override{
            const Whole& whole = dynamic_cast<const Whole&>(num);
            if(whole.number == 0){
                cout << "A number can´t be divided by 0. " << endl;
            }else{
                number = number / whole.number;
            }
        }
    };
class Real: public Number{
    private:
        double number;
    public: 
        Real(){
            number = 0;
        }
        Real(double num){
            number = num;
        }
        ~Real(){
            cout << "Real destructor" << endl;
        }
        void setNumber(double num){
            number = num;
        }
        //metodos pedidos
        string toString()override{
            string num = to_string(number);
            return num;
        }
        void sum(const Number& num)override{
            const Real& real = dynamic_cast<const Real&>(num);
            number = number + real.number;
        }
        void substract(const Number& num) override{
            const Real& real = dynamic_cast<const Real&>(num);
            number = number - real.number;
        }
        void multiply(const Number& num)override{
            const Real& real = dynamic_cast<const Real&>(num);
            number = number * real.number;
            
        }
        void divide(const Number& num)override{
            const Real& real = dynamic_cast<const Real&>(num);
            if(real.number == 0){
                cout << "A number can´t be divided by 0. " << endl;
            }else{
                number = number / real.number;
            }}        
};
class Complex: public Number{
    private: 
        pair <double,double> number;
    public: 
        Complex(){
            number.first = 0;
            number.second = 0;
        }
        ~Complex(){
            cout << "Complex destructor" << endl;
        }
        Complex(double real, double imagNum){
            number.first = real;
            number.second = imagNum;
        }
        void setNumber(double real, double imagNum){
            number.first = real;
            number.second = imagNum;
        }
        //metodos pedidos
        string toString()override{
            string num = to_string(number.first) + " + " + to_string(number.second) + " i";
            return num;
        }
        void sum(const Number& num)override{
            const Complex& complex = dynamic_cast<const Complex&>(num);
            number.first = number.first + complex.number.first;
            number.second = number.second + complex.number.second;
        }
        void substract(const Number& num)override{
            const Complex& complex = dynamic_cast<const Complex&>(num);
            number.first = number.first - complex.number.first;
            number.second = number.second - complex.number.second;
        }
        void multiply (const Number& num)override{
            const Complex& complex = dynamic_cast<const Complex&>(num);
            // Calculo por separado la parte real y compleja. Luego las asigno al prmer y segundo luagr del pair que tenfo que me representa mi numero complejo y mi numero imagunario.
            double realPart = (number.first * complex.number.first) - (number.second * complex.number.second);
            double imagPart = (number.first * complex.number.second) + (number.second * complex.number.first);

            number.first = realPart;
            number.second = imagPart;
        }
        void divide(const Number& num)override{
            const Complex& complex = dynamic_cast<const Complex&>(num);
            if (complex.number.first == 0 && complex.number.second == 0){
                cout << "A number can´t be divided by 0. " << endl;}
            else{
                int a = number.first;
                int b = number.second; 
                int c = complex.number.first; 
                int d = complex.number.second;

                int numeratorR = ((a*c) + (b*d));
                int numeratorI = ((b*c) - (a*d));
                int denominator = (c*c) + (d*d);

                number.first = numeratorR/denominator;
                number.second = numeratorI/denominator;
            }
        }
    };

int main(){
    Whole whole; 
    Whole wholeSuMult(2);
    Whole wholeSubs(3);
    Whole wholeDiv(4);
    whole.setNumber(11);
    whole.sum(wholeSuMult);
    whole.substract(wholeSubs);
    whole.multiply(wholeSuMult);
    whole.divide(wholeDiv);
    cout << "TEST: Whole number operations, it should print 5: " << whole.toString() << endl;

    Real real;
    real.setNumber(11.5);
    Real realSuMult(2);
    Real realSubs(3);
    Real realDiv(4);
    real.sum(realSuMult);
    real.substract(realSubs);  
    real.multiply(realSuMult);
    real.divide(realDiv);
    cout << "TEST: Real number operations, it should print 5.25: " << real.toString() << endl;

    Complex complex(11.5,2);
    Complex multiplication(2,2);
    Complex division(4,4);
    Complex sum(2,1);
    Complex subs(3,1);


    complex.sum(sum);
    complex.substract(subs);
    complex.multiply(multiplication);
    complex.divide(division);
    //hice cuenta en el aire hacer bien
    cout << "TEST: Complex number operations, it should print 5.25 + 1 i: " << complex.toString() << endl;

};
