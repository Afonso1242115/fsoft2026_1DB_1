//
// Created by kikok on 15/03/2026.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "customer.h"
#include <iostream>
#include <string.h>

class Customer {
protected:
    string name;
    int age;
    string code
public:
    Customer(): age(0){};
    Customer(const string name, int age): name(name), age(age){}

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
    virtual void addCustomer()=0;

    string getCode(){
      return this->code;
    }

    string getCustomer(){
        string line ="";
        string line+= "Name:"+name+"\nAge:"+std::to_string(age)+;
        return line;
    }
    virtual void selectCustomer(){};
    //virtual float calculateDiscount()=0;

};
#endif //CUSTOMER_H
