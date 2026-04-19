//
// Created by kikok on 19/03/2026.
//

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "administrator.h"
#include <iostream>
#include <string.h>

class Administrator {
private:
    string name;
    int age;
    string code;

public:
    Administrator(): age(0){};
    Administrator(const string name, int age): name(name), age(age){}

    void setName(const string name){
        this->name = name;
    }

    void setAge(const int age){
        this->age = age;
    }

    void setCode(const string code){
        this->code = code;
    }

    string getName(){
        return this->name;
    }

    int getAge(){
        return this->age;
    }
    virtual void addAdministrator()=0;

    string getCode(){
        return this->code;
    }
};


#endif //ADMINISTRATOR_H
