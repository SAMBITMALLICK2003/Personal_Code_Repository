#include <iostream>
using namespace std;
class matrix
{
    int row,column,**arr;
    public:
        //Parameterized constructor
        matrix(int a, int b)
        {
            row = a;
            column = b;
            arr = new int*[row];
            for(int i=0;i<row;i++)
            {
                arr[i] = new int[column];
            }
        }
        //copy constructor
        matrix(const matrix &other)
        {
            row = other.row;
            column = other.column;
            arr = new int*[row];
            for(int i = 0; i < row; i++)
            {
                arr[i] = new int[column];
                for(int j = 0; j < column; j++)
                {
                    arr[i][j] = other.arr[i][j];
                }
            }
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
        //initialisation
        void inz()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    cout<<"Enter element "<<i<<" "<<j<<endl;
                    cin>>arr[i][j];
                }
            }
        }
        //display
        void disp()
        {
            for(int i=0;i<row;i++)
            {
                for(int j=0;j<column;j++)
                {
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        //matrix multiplication
        matrix matrix_mult(matrix &ob)
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
                matrix result(r,c);
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
    a.inz();
    b.inz();
    a.disp();
    b.disp();
    matrix c(a.matrix_mult(b));
    c.disp();
    return 0;
}