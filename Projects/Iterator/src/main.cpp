#include "List.h"
#include "Iterator.h"

#include "Employee.h"

void PrintEmployees(Iterator<Employee*>& i) {
    for (i.First(); !i.IsDone(); i.Next()) {
        i.CurrentItem()->Print();
    }
}

int main()
{
    //employees refered to a employee list created by Client.
    List<Employee*> *employees = nullptr;

    //...

    ListIterator<Employee*> forward(employees);
    ReverseListIterator<Employee*> backward(employees);

    PrintEmployees(forward);
    PrintEmployees(backward);


}