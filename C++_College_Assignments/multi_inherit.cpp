#include <iostream>
#include <string>

using namespace std;

class WingedAnimals {
protected:
    int wingspan;

public:
    WingedAnimals(int a) : wingspan(a) {}

    void DisplayWingspan() {
        cout << "Wingspan: " << wingspan << " inches" << endl;
    }
};

class Mammals {
protected:
    int numLegs;

public:
    Mammals(int a) : numLegs(a) {}

    void DisplayNumLegs() {
        cout << "Number of Legs: " << numLegs << endl;
    }
};

class Bat : public WingedAnimals, public Mammals {
private:
    string species;

public:
    Bat(int a, int b, string c)
        : WingedAnimals(a), Mammals(b), species(c) {}

    void DisplaySpecies() {
        cout << "Species: " << species << endl;
    }

    void DisplayInfo() {
        cout << "Bat Information:" << endl;
        DisplaySpecies();
        DisplayWingspan();
        DisplayNumLegs();
    }
};

int main() {
    Bat myBat(10, 2, "Vampire");
    myBat.DisplayInfo();
    return 0;
}
