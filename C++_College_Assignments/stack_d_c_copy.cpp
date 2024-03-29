#include<iostream>
using namespace std;

class stack
{
    int top,size,*arr;
    public:
        stack();
        stack(int);
        void push(int);
        int pop();
        void display();
        int & operator[](int);
};
int& stack::operator[](int a)
{
    if(a>=size)
    {
        cout<<"Index out of range"<<endl;
        return arr[0];
    }
    return arr[a];
}
stack::stack()
{
    top=-1;
    size=10;
    arr=new int[size];
}

stack::stack(int k)
{
    top=-1;
    size=k;
    arr=new int[size];
}

void stack::push(int k)
{
    if(top>=size-1)
    {
        cout<<"Stack is full"<<endl;
    }
    else
    {
        arr[++top]=k;
    }
}

int stack::pop()
{
    if(top==-1)
    {
        cout<<"Stack is empty"<<endl;
        return 0;
    }
    else
    {
        return arr[top--];
    }
}

void stack:: display()
{
    if(top==-1)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}

// stack:: stack(stack& ob)
// {
//     top=ob.top;
//     size=ob.size;
//     arr=new int[size];
//     for(int i=0;i<=top;i++)
//     {
//         arr[i]=ob.arr[i];
//     }
// }

int main()
{
    stack s1(5);
    s1.push(4);
    s1.push(7);
    s1.push(8);
    s1.display();
    cout<<s1[1]<<endl;
    return 0;
}