#include "List.h"
#include "Iterator.h"

#include "SkipList.h"

#include "Employee.h"

void PrintEmployees(Iterator<Employee*>& i) {
    for (i.First(); !i.IsDone(); i.Next()) {
        i.CurrentItem()->Print();
    }
}

int main()
{
    //employees refered to a employee list created by Client.
    List<Employee*>* employees = new List<Employee*>(0);

    auto e1 = new Employee(1, "jay");
    auto e2 = new Employee(2, "zhen");
    auto e3 = new Employee(3, "xu");
    auto e4 = new Employee(4, "feng");

    employees->add(e1);
    employees->add(e2);
    employees->add(e3);
    employees->add(e4);

    //...

    ListIterator<Employee*> forward(employees);
    ReverseListIterator<Employee*> backward(employees);

    PrintEmployees(forward);
    PrintEmployees(backward);

    SkipList<Employee*> *skipEmployees = new SkipList<Employee*>(0);
    skipEmployees->add(e1);
    skipEmployees->add(e2);
    skipEmployees->add(e3);
    skipEmployees->add(e4);

    std::cout << "---------------------------------------" << std::endl;

    //Create corresponding Iterator according to concrete list type
    SkipListIterator<Employee*> skipforword(skipEmployees);
    PrintEmployees(skipforword);


    delete e1;
    delete e2;
    delete e3;
    delete e4;

    delete employees;
    delete skipEmployees;


}