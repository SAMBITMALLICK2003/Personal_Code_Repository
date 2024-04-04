#include <iostream>
#include <cmath>
using namespace std;
class MyException {
public:
    MyException(const string& message) : message(message) {}
    const string& what() const { return message; }

private:
    string message;
};
void calculateRoots(double a, double b, double c) {
    if (a == 0) {
        throw MyException("a must not be zero.");
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        throw MyException("The equation has no real roots.");
    }

    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);

    cout << "The roots are " << root1 << " and " << root2 << endl;
}

int main() {
    try {
        calculateRoots(1, -3, 2);
        calculateRoots(1, 0, 1);
    } catch (const MyException& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}