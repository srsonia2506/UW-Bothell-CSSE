#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Employee {
private:
  string name, department;
  int vacation;
  double salary;
public:
    Employee() {
        name=" ";
        department = " ";
        salary=0.0;
        vacation = 0;
    }
    Employee(string name, int vacation) : Employee(name, "no particular", 0.0, vacation) {};
    Employee(string name, string department, double salary, int vacation) {
        this->name = name;
        this->department = department;
        this->salary = salary;
        this->vacation = vacation;
    }
    
    void show() {
        cout << name << " is part of " << department << " department and earns $" << salary << ". The person has " << vacation << " days off." << endl;
    }
};

int main() {
    Employee* p = new Employee();
    p->show();

    Employee q("Sally", 4);
    q.show();

    Employee* r = new Employee("Ram", "Software",1200.5,10);
    r->show();

    return 0;
}
