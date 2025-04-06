#include <iostream>
#include <iomanip>
#include <string>
#include "subClases.hpp"

using namespace std;


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
