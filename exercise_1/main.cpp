#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "clock.hpp"


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
