#include <iostream>
#include <string>

using namespace std;

class Cricketer {
private:
    string name;
    int age;

public:
    Cricketer(string n, int a) : name(n), age(a){}
    Cricketer(){}
    virtual void print() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Bowler : virtual public Cricketer {
protected:
    int wickets;

public:
    Bowler(string n, int a, int w) : Cricketer(n, a), wickets(w) {}

    void print(){
        Cricketer::print();
        cout << "Wickets: " << wickets << endl;
    }
};

class Batsman : virtual public Cricketer {
protected:
    int runs;

public:
    Batsman(string n, int a, int r) : Cricketer(n, a), runs(r) {}

    void print(){
        Cricketer::print();
        cout << "Runs: " << runs << endl;
    }
};

class Allrounder : public Bowler, public Batsman {
private:
    string role;

public:
    Allrounder(string n, int a, int w, int r, string ro) : Cricketer(n, a), Bowler(n, a, w), Batsman(n, a, r), role(ro){}
    void print(){
        cout << "Allrounder Details:" << endl;
        Cricketer::print();
        cout << "Runs: " << runs << endl;
        cout << "Wickets: " << wickets << endl;
        cout << "Role: " << role << endl;
    }
};

int main() {
    Cricketer *C;
    Cricketer *C1;
    Cricketer *C2;
    Bowler b("Johnson", 28, 150);
    Batsman ba("Smith", 30, 5000);
    Allrounder ar("Stokes", 26, 200, 3000, "Captain");
    C = &b;
    C1 = &ba;
    C2 = &ar;

    C->print();
    cout << endl;
    C1->print();
    cout << endl;
    C2->print();
    cout << endl;
    return 0;
}
