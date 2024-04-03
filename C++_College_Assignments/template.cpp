#include <iostream>
using namespace std;
namespace Myspace {

    template <typename T>
    class Data {
        T* arr;
        int size;
    public:
        Data(int a) : size(a) 
        {
            arr = new T[size];
        }
        void inz()
        {
            for(int i=0;i<size;i++)
            {
                cout<<"Enter "<<i<<"th element: ";
                cin>>arr[i];
            }
        }
        void bubblesort() 
        {
            for (int i = 0; i < size-1; i++) {
                for (int j = 0; j < size-i-1; j++) {
                    if (arr[j] > arr[j+1]) {
                        swap(arr[j], arr[j+1]);
                    }
                }
            }
        }
        void display()
        {
            for(int i=0;i<size;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

    };
}
using namespace Myspace;
int main()
{
    Data<int> d(5);
    d.inz();
    d.display();
    d.bubblesort();
    d.display();
}