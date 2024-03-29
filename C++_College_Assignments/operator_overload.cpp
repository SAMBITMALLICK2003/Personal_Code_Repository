#include <iostream>
using namespace std;

class Length
{
    int feet;
    int inches;

public:
    Length();
    Length(int, int);
    Length operator()(int,int);
    // bool operator<(Length&);
    // Length operator++();
    // Length operator++(int);
    void display();
};
Length Length::operator()(int a,int b)
{
    int f = feet;
    int i = inches;
    f+=a;
    i+=b;
    if(i>=12 && i%12>0)
    {
        f+=(i/12);
        i-=12*(i/12);
    }
    return Length(f,i);
} 
void Length::display()
{
    cout << feet << " feet " << inches << " inches" << endl;
}

// Length Length::operator++()
// {
//     ++inches;
//     if (inches >= 12)
//     {
//         inches -= 12;
//         ++feet;
//     }
//     return Length(feet, inches);
// }

// Length Length::operator++(int)
// {
//     Length temp(feet, inches);
//     inches++;
//     if (inches >= 12)
//     {
//         inches -= 12;
//         feet++;
//     }
//     return temp;
// }

Length::Length()
{
    feet = 0;
    inches = 0;
}

Length::Length(int ft, int in)
{
    feet = ft;
    inches = in;
}

// bool Length::operator<(Length& l)
// {
//     if (feet < l.feet)
//         return true;
//     else if (feet == l.feet && inches < l.inches)
//         return true;
//     return false;
// }

int main()
{
    Length l1(5, 6); // 5 feet 6 inches
    Length l2;
    l2=l1(10,25);
    l1.display();
    l2.display();
    return 0;
}
