#include <iostream>
#include <iomanip>
#include <string>
#include "clock.cpp"
using namespace std;


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
