#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Student {
    private:
        string name;
        vector<pair <string,float> >  grades; 
        int IDnumber; 
    public: 
        //constructores
        Student(){
            name = " ";
            IDnumber = 0;
        }
        Student(string stname, int id){
            name = stname;
            IDnumber = id;
            // mismo q anterior 
        }
        Student(string stname, int id, vector<pair <string,float> >  stgrades){
            name = stname;
            IDnumber = id;
            grades = stgrades;
        }
        ~Student(){
            cout << "Student Destructor" << endl;
        }
        //setters
        void setName(string stname){
            name = stname;
        }
        void setId(int stId){
            IDnumber = stId;
        }
        void setGrades(string subject, float grade){
            grades.push_back(make_pair(subject,grade));
        }
        //getters
        int getSID() {return IDnumber;};
        string getName() {return name;}
        int getAverage() {
            int av=0;
            int den=0;
            for (int i =0; i < grades.size();i++){
                av = av + grades[i].second;
                den = den +1;
            }
            if (den == 0){
                cout << "There are no grades yet." << endl;
                return 0;
            }
            return av/den;
        }
    };
