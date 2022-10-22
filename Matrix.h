#ifndef Matrix_h
#define Matrix_h

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

 int get_b()
 {
     return b;
 }
 void set_b(int b)
 {
     this->b = b;
 }

 Matrix()
 {
     a = 0;b = 0;
 }

 Matrix (int x)
 {
     a = x; b = x;
 }

 Matrix (int x, int y)
 {
     a = x; b = y;
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
if(b!=B.a) cout << "0";//throw string("Wrong size of matrices");
else {
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

#endif
