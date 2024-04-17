#include <iostream>
using namespace std;
class employee;
class hod
{
    string name,dept;
    int emp_id,salary;
    public:
        hod(string,string,int,int);
        void show_details();
        void enhance_sal(employee&,int);
        friend class employee;
        void show(employee& ob)
        {
            cout<<ob.name<<endl;
        
        }
};
class employee
{
    string name,dept,designation;
    int emp_id,salary;
    public:
        employee(string,string,string,int,int);
        void show_details();
        friend void hod::enhance_sal(employee&,int);
        friend class hod;
        void show(hod& ob)
        {
            cout<<ob.name<<endl;
        }
};
employee::employee(string a,string b,string c,int d,int e)
{
    name = a;
    dept = b;
    designation = c;
    emp_id = d;
    salary = e;
}
hod::hod(string a,string b,int c,int d)
{
    name = a;
    dept = b;
    emp_id = c;
    salary = d;
}
void employee::show_details()
{
    cout<<"Name: "<<name<<", Department: "<<dept<<", Designation: "<<designation<<", Emp_id: "<<emp_id<<", Salary: "<<salary<<endl;
}
void hod::show_details()
{
    cout<<"Name: "<<name<<", Department: "<<emp_id<<", Emp_id: "<<salary<<", Salary: "<<salary<<endl;
}
void hod::enhance_sal(employee& e,int x)
{
    e.salary+=x;
}

int main()
{
    employee e1("Sambit Mallick","ECE","Professor",1,10000);
    employee e2("Suraj Roy","ECE","Professor",2,12000);
    e1.show_details();
    e2.show_details();
    hod h1("Dr. Prabir Banerjee","ECE",10,20000);
    h1.enhance_sal(e1,5000);
    e1.show_details();
    e1.show(h1);
    h1.show(e1);
    return 0;
}