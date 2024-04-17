#include <bits/stdc++.h>
using namespace std;

class length {
    int feet, inches;

  public:
    length(int, int);
    length operator++(int);
    length operator++();
    bool operator>(length &);
    void display();
    friend ostream& operator<<(ostream &, const length &);
    friend istream& operator>>(istream&,length&);
};
istream& operator>>(istream& in,length& l)
{
    cout<<"Enter feet: ";
    in>>l.feet;
    cout<<"Enter inches: ";
    in>>l.inches;
    return in;
}
ostream& operator<<(ostream& out, const length &l){
    out << "Metres:\t\t" << l.feet << endl;
    out << "Centimetres:\t" << l.inches << endl;
    return out;
}
length::length(int ft, int in) : feet(ft), inches(in) {}

void length ::display() {
    cout << endl;
    cout << "Metres:\t\t" << feet << endl;
    cout << "Centimetres:\t" << inches << endl;
    cout << endl;
}

bool length ::operator>(length &l) {
    if (feet > l.feet)
        return true;
    else if (inches > l.inches)
        return true;
    else
        return false;
}

// Pre-Increment
length length ::operator++() {
    inches++;
    if (inches == 12) {
        inches = 0;
        feet++;
    }
    return length(feet, inches);
}

// Post-Increment
length length ::operator++(int) {
    length temp(feet, inches);
    inches++;
    if (inches == 12) {
        inches = 0;
        feet++;
    }
    return temp;
}

int main() {
    length l1(2, 3);
    length l2(3, 4);
    cout<<++l1;
    cin>>l1;
    cout<<++l1;
    // cout << (l2 > l1) << endl;
    // cout << "Pre-Increment:" << endl;
    // l2 = ++l1;
    // l1.display();
    // l2.display();
    // cout << "Post-Increment:" << endl;
    // l2 = l1++;
    // l1.display();
    // l2.display();
    return 0;
}