#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
using namespace std;

template<typename T>
class Matrix{
T** matrix;
int a;
int b;

public:
 void set_a(int a)
 {
     this->a = a;
 }

 int get_a()
 {
     return a;
 }

 void set_b(int b)
 {
     this->b = b;
 }
 Matrix E_matrix(int a, int b)
{
    Matrix A;
    A.matrix = new T* [a];
    for(int i = 0; i<a; i++)
    {
        A.matrix[i] = new T [b];
    }
    for(int i = 0 ;i<a;i++)
        for(int j = 0;j<b;j++)
        {
            if(i == j)A.matrix[i][j]=1;
            else A.matrix[i][j]=0;
        }
    A.a = a;
    A.b = b;
    return A;
}



Matrix umnozim(Matrix B)
{
Matrix C;
C.a = a;
C.b = B.b;
C.matrix = new T* [a];
for(int i = 0;i<a;i++)
    C.matrix[i] = new T [B.b];

    for(int i = 0; i < a; i++)
    for(int j = 0;j<B.b;j++)
    C.matrix[i][j]=0;
for(int i = 0;i<a;i++)
    for(int q = 0;q<B.b;q++)
    {
        for(int t = 0;t<b;t++)
        C.matrix[i][q]+=matrix[i][t]*B.matrix[t][q];
    }
return C;
}

Matrix fastPOW(int n){
    if(n==0)return E_matrix(a,b);
    else if(n%2==0)
    {
        Matrix c;
        c.a = a;
        c.b = b;
        c.matrix = matrix;
        return c.fastPOW(n/2).umnozim(c.fastPOW(n/2));
    }
    else
    {
        Matrix c;
        c.a = a;
        c.b = b;
        c.matrix = matrix;
        return c.umnozim(c.fastPOW(n/2).umnozim(c.fastPOW(n/2)));
    }
}


Matrix transponiruy()
{
    Matrix C;
    C.a = b;
    C.b = a;
    C.matrix = new T* [C.a];
    for(int i = 0; i < C.a ; i++)C.matrix[i] = new T [C.b];
    for (int i = 0; i < b; i++)
        {
            for(int q = 0; q < a; q++)
            {
                C.matrix[i][q]=matrix[q][i];
            }
        }
        return C;
}

Matrix slozhi(Matrix B){
    Matrix C;
    C.a = a;
    C.b = b;
    C.matrix = new T* [C.a];
    for(int i = 0; i < C.a ; i++)C.matrix[i] = new T [C.b];
    for (int i = 0; i < a; i++)
    {
        for(int q = 0; q < b; q++)
        {
            C.matrix[i][q]=matrix[i][q]+B.matrix[i][q];
        }
    }
    return C;
}

Matrix umnozh(T k){
    Matrix C;
    C.a = a;
    C.b = b;
    C.matrix = matrix;
    for (int i = 0; i < a; i++)
    {
        for(int q = 0; q < b; q++)
        {
            C.matrix[i][q]*=k;
        }
    }
    return C;
}

template<typename Type> friend istream& operator>>(istream&, Matrix<Type>&);
template<typename Type> friend ostream& operator<<(ostream&, const Matrix<Type>&);

T* operator[](int a)
{
    return matrix[a];
}


};

template<typename T>
ostream& operator<<(ostream& out, const Matrix<T>& A)
{
    for (int i = 0; i < A.a; i++)
    {
        for(int j = 0; j < A.b; j++)
        out << A.matrix[i][j] << " ";
        out << endl;
    }
    return out;
}

template<typename T>
istream& operator>>(istream& in, Matrix<T>& A) {
    A.matrix = new T* [A.a];
    for(int i = 0; i < A.a ; i++)A.matrix[i] = new T [A.b];
    for (int i = 0; i < A.a; i++)
    {
        for(int j = 0; j < A.b; j++)
        in >> A.matrix[i][j];
    }
    return in;
}


int main()
{
srand(time(NULL));
int a,b,c,d,g=0,p;
int w;
cout<<"1.Multiplying matrix by number \n2.Sum of matrix\n3.Transposition of matrix\n4.Multiplying matrices\n5.Matrix's degree\n\n Choose the command:\n";
cin>>w;
if(w==1){
cout<<"Enter the size of matrix\n";
cin >> a >> b;
Matrix<int> A;
A.set_a(a);
A.set_b(b);
cout<<"Enter the numbers for matrix\n";
cin >> A;
/*for (int i = 0; i < a; i++) A[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 100;
}
}*/
cout<<"Enter the number for multiplying\n";
int k;cin>>k;
cout<<"Original matrix:\n";
cout<<A;
Matrix<int> C = A.umnozh(k);
cout<<"\nNew matrix:\n";
cout<<C;
cout<<endl;
}





if(w==2)
{

cout<<"Enter the size of matrices\n";
cin >> a >> b;
Matrix<int> A,B;
A.set_a(a);
A.set_b(b);
B.set_a(a);
B.set_b(b);
cout<<"Enter the numbers for the first matrix\n";
cin >> A;
cout<<"Enter the numbers for the second matrix\n";
cin >> B;
cout<<"Original matrices:\n";
cout<< A << B;
cout<<endl;

Matrix<int> C;
C = A.slozhi(B);
cout<<"\nNew matrix:\n"<<C;
}

if(w==3){
cout<<"Enter the size of matrix\n";
cin >> a >> b;
Matrix<int> A;
A.set_a(a);
A.set_b(b);
//cout<<A.get_a()<<endl;
cout<<"Enter the numbers for the matrix\n";
cin >> A;
cout<<"Original matrix:\n";
cout << A;
Matrix<int> C = A.transponiruy();
cout<<"\nNew matrix:\n"<<C;
return 0;
}



if(w==4){
cout<<"Enter the size of the first matrix\n";
cin >> a >> b;
Matrix<int> A;
A.set_a(a);
A.set_b(b);
cout<<"Enter the numbers for the first matrix\n";
cin >> A;
cout<<"Enter the size of the second matrix\n";
cin >> c >> d;
Matrix<int> B;
B.set_a(c);
B.set_b(d);
cout<<"Enter the numbers for the second matrix\n";
cin >> B;
cout<<"Original matrices:\n\n";
cout<<A<<endl<<B;
Matrix<int> C;
C = A.umnozim(B);
cout<<"\nNew matrix:\n";
cout<<C;


}

if(w==5)
{
cout<<"Enter the size of matrix\n";
cin >> a >> b;
Matrix<int> A;
A.set_a(a);
A.set_b(b);
cout<<"Enter the numbers for the matrix\n";
cin >> A;
if(a==b)
{
cout<<"Enter the degree of matrix\n";
int n;
cin >> n;
cout<<"Original matrix:\n"<<A;

cout<<"Matrix in "<<n<<" degree:\n";
Matrix<int> B;

B = A.fastPOW(n);
cout<<B;
}
else cout<<"This matrix could not be multiplied by itself :/";
}
return 0;
}
