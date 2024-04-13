#include <iostream>
using namespace std;

class Number{
    protected:
        int num;
    public:
        Number(){};
        Number(int n):num(n){};
};
class Octal: public Number
{
    public:
        Octal(){};
        Octal(int a):Number(a){};
        void display(){
            int oct[100];
            int i=0;
            while(num!=0)
            {
                oct[i]=num%8;
                num=num/8;
                i++;
            }
            for(int j=i-1;j>=0;j--)
            {
                cout<<oct[j];
            }
        }
};
class Hex: public Number
{
    public:
        Hex(){};
        Hex(int a):Number(a){};
        void display(){
            char hex[100];
            char map[17]="0123456789ABCDEF";
            int i=0;
            while(num!=0)
            {
                hex[i]=map[num%16];
                num=num/16;
                i++;
            }
            for(int j=i-1;j>=0;j--)
            {
                cout<<hex[j];
            }
        }
};
int main()
{
    Octal o1(452);
    Hex h1(999);
    o1.display();
    cout<<endl;
    cout<<"-----------------------------------"<<endl;
    h1.display();
    cout<<endl;
    return 0;
}