#include <iostream>
using namespace std;
class matrix
{
    int row,column,**arr;
    public:
        //Parameterized constructor
        matrix()
        {}
        matrix(int a, int b)
        {
            row = a;
            column = b;
            arr = new int*[row];
            for(int i=0;i<row;i++)
            {
                arr[i] = new int[column];
                for(int j = 0; j < column; j++)
                {
                    arr[i][j] = 0;
                }
            }
        }
        //copy constructor
        // matrix(const matrix &other)
        // {
        //     row = other.row;
        //     column = other.column;
        //     arr = new int*[row];
        //     for(int i = 0; i < row; i++)
        //     {
        //         arr[i] = new int[column];
        //         for(int j = 0; j < column; j++)
        //         {
        //             arr[i][j] = other.arr[i][j];
        //         }
        //     }
        //     cout<<"My Copy constructor is called"<<endl;
        // }
        //initialisation
        friend istream & operator>>(istream & in, matrix& c)
        {
            for(int i=0;i<c.row;i++)
            {
                for(int j=0;j<c.column;j++)
                {
                    cout<<"Enter element "<<i<<" "<<j<<endl;
                    in>>c.arr[i][j];
                }
            }
            return in;
        }
        //destructor
        ~matrix()
        {
            for (int i = 0; i < row; i++)
            {
                delete[] arr[i];
            }
            delete[] arr;
        }
        //display
        friend ostream & operator<<(ostream& out, matrix& c)
        {
            for(int i=0;i<c.row;i++)
            {
                for(int j=0;j<c.column;j++)
                {
                    cout<<c.arr[i][j]<<" ";
                }
                cout<<endl;
            }
            return out;
        }
        void operator=(matrix other)
        {
            row = other.row;
            column = other.column;
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < column; j++)
                {
                    arr[i][j] = other.arr[i][j];
                }
            }
        
        }
        //matrix multiplication
        matrix operator*(matrix &ob)
        {
            if(column!=ob.row)
            {
                cout<<"Multiplication not possible"<<endl;
                return matrix(0,0);
            }
            else
            {
                int r = row;
                int c = ob.column;
                static matrix result(r,c);
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        result.arr[i][j]=0;
                        for(int k=0;k<ob.row;k++)
                        {
                            result.arr[i][j] += arr[i][k]*ob.arr[k][j];
                        }
                    }
                }
                return result;
            }
        }
};
int main()
{
    int r1,c1,r2,c2;
    cout<<"Enter row 1: "<<endl;
    cin>>r1;
    cout<<"Enter column 1: "<<endl;
    cin>>c1;
    cout<<"Enter row 2: "<<endl;
    cin>>r2;
    cout<<"Enter column 2: "<<endl;
    cin>>c2;
    matrix a(r1,c1);
    matrix b(r2,c2);
    cin>>a;
    cin>>b;
    cout<<a;
    cout<<b;
    matrix c(r1,c2);
    c=a*b;
    cout<<c;
    return 0;
}