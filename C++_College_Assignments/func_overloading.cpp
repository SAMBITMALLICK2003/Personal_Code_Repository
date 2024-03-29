#include <iostream>
using namespace std;

class compute
{
    public:
        int abs(int);
        float abs(float);
        float avg(int,int);
        float avg(int,float);
        float avg(float,int);
        float avg(float,float);
};

int compute::abs(int a)
{
    if(a<0) return -a; else return a;
}
float compute::abs(float a)
{
    if(a<0) return -a; else return a;
}
float compute::avg(int a,int b)
{
    return ((a+b)/2.0);
}
float compute::avg(int a,float b)
{
    return ((a+b)/2);
}
float compute::avg(float a,int b)
{
    return ((a+b)/2);
}
float compute::avg(float a,float b)
{
    return ((a+b)/2);
}

int main()
{
    compute c;
    cout<<"Abs(int) of "<<-5<<" is "<<c.abs(-5)<<endl;
    cout<<"Abs(int) of "<<5.56<<" is "<<c.abs(5.56f)<<endl;
    cout<<"Avg(int,int) of "<<5<<" and "<<6<<" is "<<c.avg(5,6)<<endl;
    cout<<"Avg(int,float) of "<<5<<" and "<<6.65<<" is "<<c.avg(5,6.65f)<<endl;
    cout<<"Avg(float,int) of "<<5.56<<" and "<<6<<" is "<<c.avg(5.56f,6)<<endl;
    cout<<"Avg(float,float) of "<<5.56<<" and "<<6.65<<" is "<<c.avg(5.56f,6.65f)<<endl;
    return 0;
}