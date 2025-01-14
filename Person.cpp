#include "Person.h"

Person::Person(){
    this->id = 0;
    this->name = "";
    this->surname = "";
    this->pesel = 0;
}

Person::Person(int id, string name, string surname, long int pesel){
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->pesel = pesel;
}

Person::~Person(){

}
void Person::Print(){
    cout << "Person info: ";
    cout << "Name: " << name << ", Surname: " << surname << ", PESEL number: " << pesel << " ";
    Owner::Print();
}