#include <iostream>
#include <string>
using namespace std;

// Define the custom exception class
class MyException {
public:
    MyException(const int a,const int b,const string& message) : a(a),b(b),message(message) {
        full_message = to_string(a) + " and " + to_string(b) + ", " + message;
    }
    const string& what() const { return full_message; }

private:
    string message,full_message;
    int a,b;
};

// Define the function for averaging two positive integers
double average(int a, int b) {
    if (a < 0 || b < 0) {
        throw MyException(a,b,"Both numbers must be positive.");
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