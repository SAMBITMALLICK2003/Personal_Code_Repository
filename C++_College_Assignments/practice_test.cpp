#include<iostream>
using namespace std;
class exeption{
    string msg;
    public:
        exeption(const string& msg):msg(msg){}
        const string& what() const {return msg;}
};
long factorial(int n)
{
    if(n<0)
    {
        throw exeption("Negative number");
    }
    if(n>20)
    {
        throw exeption("Number more than 20");
    }
    if(n==0)
    {
        return 1;
    }
    return n*factorial(n-1);
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    try
    {
        int a=factorial(n);
        cout<<"Factorial of "<<n<<" is: "<<a<<endl;
    }
    catch(const exeption& e)
    {
        cout<<e.what()<<endl;
    }
    return 0;
}