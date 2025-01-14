#include "Company.h"

Company::Company() {
    this->id = 0;
    this->name = "";
    this->nip = 0;
}
Company::Company(int id, string name, int nip) {
    this->id = id;
    this->name = name;
    this->nip = nip;
}

Company::~Company() {

}

void Company::Print(){
    cout << "Company info: ";
    cout << "Name: " << name << ", NIP number: " << nip << " ";
    Owner::Print();
}