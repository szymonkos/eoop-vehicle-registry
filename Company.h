#ifndef CPP_PROJECT2019_COMPANY_H
#define CPP_PROJECT2019_COMPANY_H

#include "Owner.h"
class Company : public Owner{
public:
    string name;
    int nip;
    Company();
    Company(int id, string name, int nip);
    ~Company();
    void Print()override;
};

#endif //CPP_PROJECT2019_COMPANY_H
