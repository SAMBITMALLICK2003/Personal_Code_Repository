#include <iostream>
#include <cmath>
using namespace std;

class complex
{
    double r,i;
    public:
        complex(double,double);
        void disp();
        friend complex operator+(const complex&,const complex&);
        friend complex operator-(const complex&,const complex&);
        friend complex operator*(const complex&,const complex&);
        friend complex operator/(const complex&,const complex&);
        friend string operator>(const complex&,const complex&);
        friend string operator<(const complex&,const complex&);
        friend string operator>=(const complex&,const complex&);
        friend string operator<=(const complex&,const complex&);
};
complex::complex(double a = 0.0, double b = 0.0)
{
    r=a;
    i=b;
}
void complex::disp()
{
    if(i>=0)
        cout<<r<<" + i"<<i<<endl;
    else
        cout<<r<<" - i"<<i<<endl;
}
complex operator+(const complex& c1 ,const complex& c2 )
{
    return complex(c1.r+c2.r,c1.i+c2.i);
}
complex operator-(const complex& c1 ,const complex& c2 )
{
    return complex(c1.r-c2.r,c1.i-c2.i);
}
complex operator*(const complex& c1 ,const complex& c2 )
{
    return complex(c1.r*c2.r-c1.i*c2.i,c1.i*c2.r+c1.r*c2.i);
}
complex operator/(const complex& c1 ,const complex& c2 )
{
    double a = (c1.r*c2.r+c1.i*c2.i)/(c2.r*c2.r + c2.i*c2.i);
    double b = (c1.i*c2.r-c1.r*c2.i)/(c2.r*c2.r + c2.i*c2.i);
    return complex(a,b);
}
string operator>(const complex& c1 ,const complex& c2 )
{
    if(sqrt(pow(c1.r,2)+pow(c1.i,2))>sqrt(pow(c2.r,2)+pow(c2.i,2)))
        return "True";
    return "False";
}
string operator<(const complex& c1 ,const complex& c2 )
{
    if(sqrt(pow(c1.r,2)+pow(c1.i,2))<sqrt(pow(c2.r,2)+pow(c2.i,2)))
        return "True";
    return "False";
}
string operator>=(const complex& c1 ,const complex& c2 )
{
    if(sqrt(pow(c1.r,2)+pow(c1.i,2))>=sqrt(pow(c2.r,2)+pow(c2.i,2)))
        return "True";
    return "False";
}
string operator<=(const complex& c1 ,const complex& c2 )
{
    if(sqrt(pow(c1.r,2)+pow(c1.i,2))<=sqrt(pow(c2.r,2)+pow(c2.i,2)))
        return "True";
    return "False";
}
int main()
{
    complex c1(2,5);
    complex c2(2,4);
    complex c3 = c1+20;
    complex c4 = c1-c2;
    complex c5 = c1*c2;
    complex c6 = c1/2;
    c3.disp();
    c4.disp();
    c5.disp();
    c6.disp();
    cout<<(c3>=c1)<<endl;
    return 0;
}