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

class Clock{
    public:
        //Constructores, estos 5 constructores inicializan la hora como lo dice el usuario dependiendo de la cantidad y el tipo de parametros que pase. Si pasa un numero incorrecto la clase llama a las funciones de correccion y le pedira al usuario que ingrese nuevamente el valor hastq que lo ponga bien. 
        Clock(){
            hours=0;
            minutes=0;
            seconds=0; 
            blocks="am";
        }       
        Clock(int hour){
            blocks="am";
            hours = correctHam(hour);
            minutes=0;
            seconds=0;
        }
        Clock(int hour, int minute){
            hours=correctHam(hour);
            minutes = correcttM(minute);
            seconds=0;
            blocks="am";
        }
        Clock(int hour, int minute, int second){
            hours=correctHam(hour);
            minutes = correcttM(minute);
            seconds = correcttS(second);
            blocks="am";
        }
        Clock(int hour, int minute, int second, string zone){
            minutes = correcttM(minute);
            seconds = correcttS(second);
            blocks=correctZone(zone);
            if (blocks == "am"){
                hours = correctHam(hour);
            }else{
                hours = correctHpm(hour);
            }
        }
        // armo los setters, para poder cambiar la hora, minutos y segundos. 
        void setHour(int hour){
            if (blocks == "pm")
            {hours = correctHpm(hour);
                return;
            }
            //por default se la zona horaria se pone como am. 
            hours = correctHam(hour);
            return;
        }
        void setMinutes(int minute){
            minutes = correcttM(minute);
        }
        void setSeconds(int second){
            seconds = correcttS(second);
        }
        // armo los getters, para que el usuario pueda obtener la hora, minuto, segundo, zona horaria y por si quiere el horario completo. 
        int getHour(){return hours;}
        int getMinute(){return minutes;}
        int getSeconds(){return seconds;}
        string getZone(){return blocks;}
        string getTime(){
            //convierto los ints a string para concatenarlos. 
            string time = to_string(hours) + "h " + to_string(minutes)+ "m " + to_string(seconds) + "s " + blocks + "\n";
            return time;
        }
        string getTime24hs(){
            if (blocks == "am" || hours == 12){
                return to_string(hours) + "h " + to_string(minutes)+ "m " + to_string(seconds) + "s\n";
            }
            else{
                int newHour = 12 + hours;
                return to_string(newHour) + "h " + to_string(minutes)+ "m " + to_string(seconds) + "s\n";
            }
        }
       
        private:
        int hours;
        int minutes;
        int seconds;
        string blocks;
};

int main(){
    //Testeo la clase Clock con valores validos. 
    Clock empty; 
    cout << "TEST: Default constructor: " << empty.getTime()<<endl;

    Clock hour(11); 
    cout << "TEST: Constructor with only the hours: " << hour.getTime()<<endl;

    Clock minutes(11,11); 

    cout << "TEST: Constructor with the hours and minutes: " << minutes.getTime()<<endl;

    Clock seconds(11,11,11); 
    cout << "TEST: Constructor with the hours, minutes and seconds: " << seconds.getTime()<<endl;

    Clock zone(11,11,11,"pm"); 
    cout << "TEST: Constructor with the hours, minutes, seconds and zone (pm): " << zone.getTime()<<endl;
    
    //Testeo la clase Clock con valores invalidos. 

    Clock hourI(34); 
    cout << "TEST: Constructor with only the hours (invalid): " << hourI.getTime()<<endl;

    Clock minutesI(11,100); 

    cout << "TEST: Constructor with the hours and minutes (invalid): " << minutesI.getTime()<<endl;

    Clock secondsI(11,11,100); 
    cout << "TEST: Constructor with the hours, minutes and seconds (invalid): " << secondsI.getTime()<<endl;

    Clock zoneI(11,11,11,"he"); 
    cout << "TEST: Constructor with the hours, minutes, seconds and zone (pm) (invalid): " << zoneI.getTime()<<endl;
    
    
    return 1;
}
