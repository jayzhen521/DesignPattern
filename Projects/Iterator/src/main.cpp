#include "Employee.h"
#include "List.h"
#include "SkipList.h"
#include "IteratorPtr.h"


void PrintEmployees(Iterator<Employee*>& i) {
    for (i.First(); !i.IsDone(); i.Next()) {
        i.CurrentItem()->Print();
    }
}

int main()
{
    //employees refered to a employee list created by Client.
    auto e1 = new Employee(1, "jay");
    auto e2 = new Employee(2, "zhen");
    auto e3 = new Employee(3, "xu");
    auto e4 = new Employee(4, "feng");

    //Client know which kind of List should be created, and which kind of Iterator should be created.
    //Thanks to the list the and iterator are coupled, using AbstratList, Client don't take care about 
    //choosing corresponding Iterator.
    List<Employee*>* employees = new List<Employee*>(0);
    SkipList<Employee*>* skipEmployees = new SkipList<Employee*>(0);

    employees->add(e1);
    employees->add(e2);
    employees->add(e3);
    employees->add(e4);

    skipEmployees->add(e1);
    skipEmployees->add(e2);
    skipEmployees->add(e3);
    skipEmployees->add(e4);

    List<Employee*>* aEmployeeList = nullptr;

    //simulate:not need to know the type of skipEmployees
    aEmployeeList = employees;

    //Interface-oriented programming
    {
        //Iterator<Employee*>* iter = aEmployeeList->CreateIterator();
        IteratorPtr iter(aEmployeeList->CreateIterator());
        PrintEmployees(*iter);
        //iter = aEmployeeList->CreateReverseIterator();
        //PrintEmployees(*iter);
    }

    std::cout << "---------------------------------------" << std::endl;

    //simulate:not need to know the type of skipEmployees
    aEmployeeList = skipEmployees;

    //Interface-oriented programming
    {
        //Iterator<Employee*>* iter = aEmployeeList->CreateIterator();
        IteratorPtr iter(aEmployeeList->CreateIterator());
        PrintEmployees(*iter);
    }

    delete e1;
    delete e2;
    delete e3;
    delete e4;

    delete employees;
    delete skipEmployees;


}