#pragma once

#include <iostream>

class Employee
{
public:
    Employee(uint64_t number, const std::string& name)
        :_number(number), _name(name)
    {}
    
    void Print() {
        std::cout << "Name is:" << _name << ", Number is " << _number << std::endl;
    }

private:
    uint64_t _number;
    std::string _name;

};