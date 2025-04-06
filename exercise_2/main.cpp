#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include "course.hpp"
using namespace std;

int main() {
    enum Options {COURSE = 1, SUBSCRIBE, UNSUSCRIBE, SEARCH, COMPLETE, PRINT, COPY, EXIT};//uso el enum para luego utilizar el switch.
    vector<shared_ptr <Course> > courses;//armo un vector que me almacene los cursos para luego poder preguntarke al usuario con cual quiere trabajar. Si no asocio los cursos a un puntero, a penas se sale del case del switch se destruye.
    vector<shared_ptr <Student > > students; //creo un vector de punteros para los students para que p se destruye al salir de los cases del switch. Lo mismo sucede con los students. Ya que las clases tienen una relacion de agregacion, necesito asociar a los estudiantes a un puntero para que no se destruyan. 
    while(true){
        int option;
        cout << "Choose an option: \n\t1. Create a course \n\t2. Subscribe a student to a course \n\t3. Unsubscribe a student from a course \n\t4. See if a student is inscribed in a course \n\t5. See if the course is complete \n\t6. Print course information \n\t7. Copy the course \n\t8. Exit" << endl;
        cin >> option;
        while (option>8 || option <1){
            cout << "The option selected is not part of the menu, please enter another integer between 1 and 8. "<<endl;
            cin >> option;
        }
        switch (option){
            case COURSE: {
                string name;

                cout <<"What is the name of the course to create? (Put the first capital letter and the rest of the name in lower case)"<<endl;
                cin >> ws;
                getline(cin,name);

                shared_ptr<Course> newCourse = make_shared<Course>();
                newCourse->setName(name);
                courses.push_back(newCourse);//guardo el curso en el vector de cursos, para que si quiere agregar un alumno a un curso especifico lo pueda hacer. 
                cout << "A course was created." << endl;
                break;}
            case SUBSCRIBE:{
                string courseName;
                int id;
                int opt;
                cout << "Wich course would you like to add the student to? (Put the first capital letter and the rest of the name in lower case)"<<endl;
                cin >> ws;
                getline(cin,courseName);

                cout << "Do you want to create a new student?\n\t1. Create a new student\n\t2.Add to the course an exitent student" << endl;
                cin >> opt;

                while ((opt!=1) && (opt!=2) ){
                    cout << "The option selected is not part of the menu, please enter another integer between 1 and 2. "<<endl;
                    cin >> opt;
                }
                
                if (opt == 2){
                    cout << "State the ID of the student you want to add? " << endl;
                    cin >> id;
                    bool foundStudent = false;
                    bool foundCourse = false;

                    for (int i=0; i<students.size();i++){
                        if (students[i]->getSID() == id){
                            foundStudent = true;
                            for (int j=0; j<courses.size();j++){//busco entre todos los cursos en mi vector de cursos el nombre del curso que me pasaron, de encontrar el curso, se elije el segundo elemento del pair para agregar al estudiante al curso.
                                if (courses[j]->getName() == courseName){
                                    foundCourse = true;
                                    courses[j]->setStudent(students[i]);
                                    cout << "The course "<< courseName << " was found.And the student was added" << endl;
                                    break;
                                }   
                                
                            }
                           break;
                        }
                        
                    }
                    if (foundStudent == false){
                        cout << "The student was not found." << endl;
                    }else if (foundCourse == false){
                        cout << "The course was not found." << endl;
                    }
                    break;
                }
                else{
                    int id;
                    int op2;
                    int opt3;
                    bool found = true;
                    string name;

                    cout << "A new student will be created." << endl;
                    cout << "State the name of the student."<<endl;
                    cin >> ws;
                    getline(cin,name);
                    cout << "State the ID of the student. (It must be unique)"<<endl;
                    cin >> id;
                    for (int i=0; i<students.size();i++){//veo si el ID pasado no le pertenece a un estudiante que ya existe.
                        if (students[i]->getSID() == id){
                            cout << "The ID of the student is not unique, please try again." << endl;
                            break;
                            }}
                    
                    cout << "Do you want to assign any grades to this student?\n\t1. Yes\n\t2. No" << endl;
                    cin >> opt3;

                    while (opt3<1 || opt3>2){
                        cout << "The option selected is not part of the menu, please enter another integer between 1 and 2. "<<endl;
                        cin >> opt3;
                    }
                    shared_ptr<Student> student = make_shared<Student>();
                    student->setName(name);
                    student->setId(id);
                    
                    while (opt3 == 1){//whule para agregar las materias y notas ddel alumno
                        string subject;
                        float grade;

                        cout << "Enter name of the subject: " << endl;
                        cin >> ws;
                        getline(cin,subject);

                        cout << "Enter the grade assingned to " << subject <<": "<< endl;
                        cin >> grade;
                        student->setGrades(subject,grade);
                        cout << "Do you want to assingn any other grades to this student? \n\t1. Yes \n\t2. No" << endl;
                        cin >> opt3;
                        while (opt3< 1 || opt3>2){
                            cout << "The option selected is not part of the menu, please enter another integer between 1 and 2. "<<endl;
                            cin >> opt3;
                        }
                    }
                    
                    cout << "A student was created." << endl;
                    

                    for (int i=0; i<courses.size();i++){//busco entre todos los cursos en mi vector de cursos el nombre del curso que me pasaron
                        if (courses[i]->getName() == courseName){
                            found = true;
                            courses[i]->setStudent(student);
                            students.push_back(student);//guardo el alumno nuevo en el vector de punteros a alumnos existentes.
                            cout << "The course "<< courseName << " was found. And the student added" << endl;
                            break;
                        }
                    
                    }
                    if (found == false){
                        cout << "The course was not found." << endl;
                    }
                    break;}
                } // termino para que no siga con los siguentes cases      
            case UNSUSCRIBE:{
                string courseName2;
                int id;
                bool foundCourse = false;
                
                cout << "Wich course would you like to unsubscribe the student from? (Put the first capital letter and the rest of the name in lower case)"<<endl;
                cin >> ws;
                getline(cin,courseName2);
                cout << "What is the ID of the student you want to unsubscribe? " << endl;
                cin >> id;

                for (int i=0; i<courses.size();i++){
                    if (courses[i]->getName() == courseName2){
                        foundCourse = true;
                        courses[i]->setUnsuscribe(id);
                    }}
                if (foundCourse == false){
                    cout << "The course "<< courseName2 << "wasn´t found. Try again." << endl;
                }
                break;}
            case SEARCH:{
                string courseName3;
                int id2;
                bool foundCourse = false;
                
                cout << "Wich course would you like to search the student in? (Put the first capital letter and the rest of the name in lower case)"<<endl;
                cin >> ws;
                getline(cin,courseName3);
                cout << "What is the ID of the student you want to search for? " << endl;
                cin >> id2;

                for (int i=0; i<courses.size();i++){
                    if (courses[i]->getName() == courseName3){
                        foundCourse = true;
                        courses[i]->isEnrolled(id2);
                        break;
                    }}
                if (foundCourse == false){
                    cout << "The course "<< courseName3 << "wasn´t found. Try again." << endl;}
                break;}
            case COMPLETE: {
                    string courseName4;
                    bool foundCourse = false;
                    cout << "Wich course would you like to see if it is complete? (Put the first capital letter and the rest of the name in lower case)"<<endl;
                    cin >> ws; 
                    getline(cin,courseName4);
                    for (int i=0; i<courses.size();i++){
                        if (courses[i]->getName() == courseName4){
                            foundCourse = true;
                            courses[i]->isComplete();
                            break;
                        }}
                    if (foundCourse == false){
                    cout << "The course "<< courseName4 << "wasn´t found. Try again." << endl;}
                    break;}   
            case PRINT: {
                    int option;
                    bool foundCourse = false;
                    cout <<"Would you like to print:\n\t1.All the courses\n\t2.A specific course\n\t3.None"<<endl;
                    cin >> option;
                    while (option<1 || option>3){
                        cout << "The option selected is not part of the menu, please enter another integer between 1 and 3. "<<endl;
                        cin >> option;
                    }

                    if (option == 1){
                        for (int i=0; i<courses.size();i++){
                            cout << "Course name: " << courses[i]->getName() <<"------------------"<< endl;
                            courses[i]->printInfo();
                        }
                    }
                    else if (option == 2){
                        string courseName5;
                        cout << "State the name of a course to pritn it's information" <<endl;
                        cin >> ws;
                        getline(cin,courseName5);

                        for (int i=0; i<courses.size();i++){
                            if (courses[i]->getName() == courseName5){
                                foundCourse = true;
                                cout << "Course name: " << courses[i]->getName() <<"------------------"<< endl;
                                courses[i]->Alphabetical();
                                break;
                            }
                        }
                        if (foundCourse == false){
                            cout << "The course "<< courseName5 << "wasn´t found. Try again." << endl;
                        }
                    }
                    else if (option == 3){
                        cout << "No course will be printed." << endl;
                    }
                    break;}
            case COPY: {
                    string courseName6;
                    string newCourseName;
                    bool foundCourse = false;

                    cout << "State the name of the course you would like to copy? (Put the first capital letter and the rest of the name in lower case)"<<endl;
                    cin >> ws; 
                    getline(cin,courseName6);

                    cout << "State the name of the new course. (Put the first capital letter and the rest of the name in lower case)"<<endl;
                    cin >> ws; 
                    getline(cin,newCourseName);

                    if(newCourseName == courseName6){
                        cout << "The name of the new course can´t be the same as the original." << endl;
                        break;
                    }
                    for (int i=0; i<courses.size();i++){
                        if (courses[i]->getName() == courseName6){
                            foundCourse = true;

                            shared_ptr <Course> copiedCourse = make_shared<Course>(*courses[i]);//hago una copia del curso original, para que no se modifique el original.
                            copiedCourse->setName(newCourseName);

                            courses.push_back(copiedCourse);

                            cout << "The course "<< courseName6 << "was copied." << endl;
                            cout << "Original: " << courseName6<<"------------------"<< endl;
                            courses[i]->Alphabetical();
                            cout << "Copy: " << copiedCourse->getName()<<"------------------"<< endl;
                            copiedCourse->Alphabetical();
                            break;
                        }}
                    if (foundCourse == false){
                        cout << "The course "<< courseName6 << "wasn´t found. Try again." << endl;}
                    break;}
                
            case EXIT:{
                cout << "End of progam" << endl;
                return 0;
            }
        }     
}}
