#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


//hay dos funciones para verificar la hora porque am va de 0-11 mientras que pm va de 12-11. Entonces lo horarios irian desde 00-12 de manera corrcta, sin que exista simultaneamente la opcion de 12am o 00pm. 
int correctHam(int h){ 
    if (h<0 || h > 11){
        int newH = 12;
        while (newH<0 || newH > 11){
            cout << "Invalid Hour, enter another integer"<<endl;
            cin>> newH;
        }
        return newH;
    }
    return h;
}
int correctHpm(int h){ 
    if (h<=0 || h > 12){
        int newH=-1;
        while (newH<=0 || newH > 12){
            cout << "Invalid Hour, enter another integer"<<endl;
            cin>> newH;
        }
        return newH;
    }
    return h;
}
int correcttM(int i){ 
    if (i<0 || i> 59){
        int newI=60;
        while (newI<0 || newI > 59){
            cout << "Invalid number of minutes, enter another integer in range 0-59"<<endl;
            cin>> newI;
        }
        return newI;
    }
    return i;
}
int correcttS(int i){ 
    if (i<0 || i> 59){
        int newI=60;
        while (newI<0 || newI > 59){
            cout << "Invalid number of seconds, enter another integer in range 0-59"<<endl;
            cin>> newI;
        }
        return newI;
    }
    return i;
}
string correctZone(string z){
    if (z!="am" && z!="pm"){
        string newZ;
        while (newZ!="am" && newZ!="pm"){
            cout << "Invalid zone, enter am/pm in lowercase"<<endl;
            cin>>ws;
            getline(cin,newZ);// uso get line para eliminar los white spaces del buffer. 
        }
        return newZ;
    }
    return z;
}
