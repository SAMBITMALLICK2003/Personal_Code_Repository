#include <iostream>
using namespace std;
class B;
class A;
class A {
private:
  int x;

public:
  A(int x) : x(x) {}
  void print_x(B& a) {
    std::cout << a.y << std::endl;
  }

  friend class B;
};

class B {
private:
    int y;
public:
    B(int x) : y(x) {}
  void print_x(A& a) {
    std::cout << a.x << std::endl;
  }
  friend class A;
};

int main() {
  A a(10);
  B b(20);

  b.print_x(a);

  return 0;
}