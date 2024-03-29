#include <iostream>
using namespace std;
int main()
{
    int *a = new int(5);
    char *b = new char('f');
    cout<<*a<<endl;
    cout<<a<<endl;
    cout<<*b<<endl;
    cout<<b<<endl;
    return 0;
}