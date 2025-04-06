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
