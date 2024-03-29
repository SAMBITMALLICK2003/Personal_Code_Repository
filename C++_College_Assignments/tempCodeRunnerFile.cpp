#include <iostream>
#include <string>

using namespace std;

// Base class Cricketer
class Cricketer {
protected:
    string name;
    int age;

public:
    Cricketer(string n, int a) : name(n), age(a){}
    Cricketer(){}
    void printDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class Bowler from Cricketer
class Bowler : virtual public Cricketer {
private:
    int wickets;

public:
    Bowler(string n, int a, int w) : Cricketer(n, a), wickets(w) {}

    void printBowler(){
        printDetails();
        cout << "Wickets: " << wickets << endl;
    }
};

// Derived class Batsman from Cricketer
class Batsman : virtual public Cricketer {
private:
    int runs;

public:
    Batsman(string n, int a, int r) : Cricketer(n, a), runs(r) {}

    void printBatsman(){
        printDetails();
        cout << "Runs: " << runs << endl;
    }
};

// Derived class Allrounder from Bowler and Batsman
class Allrounder : public Bowler, public Batsman {
public:
    Allrounder(string n, int a, int w, int r, string ro) : Cricketer(n, a), Bowler(n, a, w), Batsman(n, a, r){}
    void printDetails(){
        cout << "Allrounder Details:" << endl;
        printBatsman();
        printBowler();
    }
};

int main() {
    Bowler b("Johnson", 28, 150);
    Batsman ba("Smith", 30, 5000);
    Allrounder ar("Stokes", 26, 200, 3000, "Captain");


    b.printDetails();
    cout << endl;
    ba.printDetails();
    cout << endl;
    ar.printDetails();
    cout << endl;
    return 0;
}
