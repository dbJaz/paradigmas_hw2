#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include "student.hpp"
using namespace std;

//sobcarga de operadores
bool operator<(const shared_ptr<Student>& main,const shared_ptr<Student>& other){//sobrecargo el operador > para comparar al objeto estudiante por los nombres.  
    return main->getName() < other->getName();};

ostream& operator<<(ostream& os, const shared_ptr<Student>& student){//ostream me indica que voy a devolver un string. Ostream trata al os como si fuese un cout. Sobrecargo al operador << para que me impirma la info del alumno.  
    os<<"Name: "<<student->getName()<<"\n"<<"Student ID:  "<<student->getSID()<<"\n"<<"Weighted average: "<<student->getAverage()<<endl;
    return os;
}

class Course {
    private:  
        vector<shared_ptr<Student> > students;
        int capacity;
        string name;
    public: 
        //constructores
        Course(){
            name = " ";
            capacity = 0;//inicializo la capacidad en 0 porque aun no hay nadie inscripto.
        }
        Course(string courseName){
            name = courseName;
            capacity = 0;
        }
        Course(const Course& dcpy){//le doy un curso y hago una copia profunda del curso. 
            for(int i=0; i< dcpy.students.size();i++){
                shared_ptr<Student> aux = dcpy.students[i];
                students.push_back(make_shared<Student>(*aux)); //el shared_ptr crea una copia del puntero aux, y lo guarda en el vector.
            }
        }
        ~Course(){
            cout << "Course Destructor" << endl;
        }
        //setters 
        void setStudent(shared_ptr<Student>  student){  
            if (students.size() == 20){
                cout << "The course is complete, no more students can be added.";
                return;
            }
            for (int i=0; i<students.size();i++){
                if (students[i]->getSID() == student->getSID()){//el numero e legajo tiene que ser unico, si se repite el alumno no va aser adminitdo en el curso. 
                    if (students[i]->getName() == student->getName()){
                        cout << "This student is inscribed in the course."<< endl;
                        return;
                    }
                    else{
                        cout << "The student ID should be unique, "<<students[i]->getName()<< " and "<< student->getName()<<" have the same ID." << endl;
                        return;
                    }
                    return;
                }
            }
            students.push_back(student); //Hago un shared pointer del student y lo agrego al vector.
            capacity = capacity + 1;
            return;
        }
        void setUnsuscribe(int id){
        for (int i=0; i<students.size();i++){
            if (students[i]->getSID() == id){
                students.erase(students.begin() + i);//erase elimina el pintero a la posicion i, inicia un iterador en beguin y le suma i para llegar a la posicion del estudiante que se quiere eliminar.
                cout << "The student has been unsubscribed from the course"<< endl;
                return;
            }
        }
        cout<<"The student wasn´t inscribed in the course";
        return;
    }
        void setName(string courseName){
            name = courseName;
        }

        void isComplete(){
            if (students.size() == 20){
                cout << "The course is complete." << endl;
                return;
            }
            cout << "There are" << 20 - capacity << " spaces left"<< endl;
            return;
        }
        bool isEnrolled(int studentID){
            for (int i=0; i<students.size();i++){
                if (students[i]->getSID() == studentID){
                    cout << "The student is enrolled in this course." << endl;
                    return true;
                }
            }
            cout << "There is no student with that ID enrolled in the course. " << endl;
            return false;
        }
        void Alphabetical(){
            sort(students.begin(),students.end());
            for (int i = 0; i < students.size(); i++) {
                cout << students[i];
        }}
        void printInfo(){
            cout << "Students in the course: " << endl;
            for (int i=0; i< students.size(); i++){
                cout << students[i];
            }
        }
        string getName(){
            return name;
        }   
};
