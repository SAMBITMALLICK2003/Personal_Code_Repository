#include <iostream>
using namespace std;

class Number{
    protected:
        int num;
    public:
        Number(){};
        Number(int n):num(n){};
        virtual void display(){
            cout<<num<<endl;
        }
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
    Octal oct(32);
    Hex hex(32);
    Number *n;
    n = &oct;
    n->display();
    n = &hex;
    n->display();
    return 0;
}