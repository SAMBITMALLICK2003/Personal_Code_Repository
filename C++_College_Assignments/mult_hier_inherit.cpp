#include <iostream>

using namespace std;

class Person {
    protected:
        string name;
        int age;

    public:
        Person(string name, int age) : name(name), age(age) {}
        virtual void PrintDetails() = 0;
};
class Employee : public Person {
    private:
        int eid;
        int sal;

    public:
        Employee(string name, int age, int eid, int sal): Person(name, age), eid(eid), sal(sal) {}

        void PrintDetails(){
            cout << "Employee Details:" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Employee ID: " << eid << endl;
            cout << "Salary: $" << sal << endl;
        }
};

class Manager : public Person {
    private:
        int manager_id;
        int sal;

    public:
        Manager(string name, int age, int manager_id, int sal)
            : Person(name, age), manager_id(manager_id), sal(sal) {}

        void PrintDetails() override {
            cout << "Manager Details:" << endl;
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Manager ID: " << manager_id << endl;
            cout << "Salary: $" << sal << endl;
        }
};

int main() {
    Employee emp("John Doe", 30, 101, 50000);
    Manager mgr("Jane Smith", 35, 201, 80000);

    emp.PrintDetails();
    cout << endl;
    mgr.PrintDetails();

    return 0;
}
