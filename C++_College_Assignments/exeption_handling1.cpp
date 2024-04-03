#include <iostream>
#include <string>
using namespace std;

// Define the custom exception class
class MyException {
public:
    MyException(const string& message) : message(message) {}
    const string& what() const { return message; }

private:
    string message;
};

// Define the function for averaging two positive integers
double average(int a, int b) {
    if (a < 0 || b < 0) {
        throw MyException("Both numbers must be positive.");
    }
    return (a + b) / 2.0;
}

int main() {
    try {
        cout << average(10, 20) << endl;
        cout << average(-10, 20) << endl;
    } catch (const MyException& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }
    return 0;
}