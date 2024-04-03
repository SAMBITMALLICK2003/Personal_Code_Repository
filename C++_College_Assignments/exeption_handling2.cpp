#include <iostream>
#include <cmath>
using namespace std;

void calculateRoots(double a, double b, double c) {
    if (a == 0) {
        throw invalid_argument("a must not be zero.");
    }

    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        throw domain_error("The equation has no real roots.");
    }

    double root1 = (-b + sqrt(discriminant)) / (2 * a);
    double root2 = (-b - sqrt(discriminant)) / (2 * a);

    std::cout << "The roots are " << root1 << " and " << root2 << std::endl;
}

int main() {
    try {
        calculateRoots(1, -3, 2);
        calculateRoots(1, 0, 1);
    } catch (const exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}