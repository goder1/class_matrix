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

    Matrix(int x)
    {
        a = x; b = x;
    }

    Matrix(int x, int y)
    {
        a = x; b = y;
    }

    Matrix E_matrix(int a, int b)
    {
        Matrix A;
        A.matrix = new T* [a];
        for(int i = 0; i < a; i++)
        {
            A.matrix[i] = new T [b];
        }
        for(int i = 0 ; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                if(i == j)A.matrix[i][j] = 1;
                else A.matrix[i][j] = 0;
            }
        }
        A.a = a;
        A.b = b;
        return A;
    }



    Matrix operator*(Matrix B)
    {
        Matrix C;
        C.a = a;
        C.b = B.b;
        C.matrix = new T* [a];
        for(int i = 0; i < a; i++)
        {
            C.matrix[i] = new T [B.b];
        }
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < B.b; j++)
            {
                C.matrix[i][j]=0;
            }
        }
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < B.b; j++)
            {
                for(int t = 0; t < b; t++)
                C.matrix[i][j] += matrix[i][t] * B.matrix[t][j];
            }
        }
        return C;
    }

    Matrix fastPOW(int n)
    {
        if(n == 0)return E_matrix(a,b);
        else if(n%2 == 0)
        {
            Matrix C;
            C.a = a;
            C.b = b;
            C.matrix = new T* [a];
            for(int i = 0; i < a; i++)
            {
                C.matrix[i] = new T [b];
            }
            for(int i = 0; i < a; i++)
            {
                for(int j = 0; j < b; j++)
                {
                    C.matrix[i][j] = matrix[i][j];
                }
            }
            //c.matrix = matrix;
            return C.fastPOW(n/2) * C.fastPOW(n/2);
        }
        else
        {
            Matrix C;
            C.a = a;
            C.b = b;
            C.matrix = new T* [a];
            for(int i = 0; i < a; i++)
            {
                C.matrix[i] = new T [b];
            }
            for(int i = 0; i < a; i++)
            {
                for(int j = 0; j < b; j++)
                {
                    C.matrix[i][j] = matrix[i][j];
                }
            }
            //c.matrix = matrix;
            return C * (C.fastPOW(n/2) * C.fastPOW(n/2));
        }
    }


    Matrix transposition()
    {
        Matrix C;
        C.a = b;
        C.b = a;
        C.matrix = new T* [C.a];
        for(int i = 0; i < C.a ; i++)
        {
            C.matrix[i] = new T [C.b];
        }
        for (int i = 0; i < b; i++)
        {
            for(int j = 0; j < a; j++)
            {
                C.matrix[i][j] = matrix[j][i];
            }
        }
        return C;
    }

    Matrix operator+(Matrix B)
    {
        Matrix C;
        C.a = a;
        C.b = b;
        C.matrix = new T* [C.a];
        for(int i = 0; i < C.a ; i++)
        {
            C.matrix[i] = new T [C.b];
        }
        for (int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                C.matrix[i][j] = matrix[i][j] + B.matrix[i][j];
            }
        }
        return C;
    }

    Matrix operator*(T k)
    {
        Matrix C;
        C.a = a;
        C.b = b;
        //C.matrix = matrix;
        C.matrix = new T* [a];
        for(int i = 0; i < a; i++)
        {
            C.matrix[i] = new T [b];
        }
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                C.matrix[i][j] = matrix[i][j];
            }
        }
        for (int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                C.matrix[i][j] *= k;
            }
        }
        return C;
    }

    int determinant(int a)
    {
        if(a==1)return matrix[0][0];
        else if(a==2)return matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
        else
        {
            int k = 1,s = 0;
            for(int i = 0; i < a; i++)
            {
                Matrix<int> B(a-1);
                B.matrix = new int* [a-1];
                for (int j = 0; j < a-1; j++)
                {
                    B.matrix[j] = new int [a-1];
                }
                for (int j = 0; j < a-1; j++)
                {
                for(int q = 0; q < i; q++)
                {
                    B.matrix[j][q] = matrix[j+1][q];
                }
                for(int q = i; q < a-1; q++)
                {
                    B.matrix[j][q] = matrix[j+1][q+1];
                }
                }
                s += matrix[0][i] * B.determinant(a-1) * k;
                k =- k;
            }
        return s;
        }
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
        {
            out << A.matrix[i][j] << " ";
        }
        out << endl;
    }
    return out;
}

template<typename T>
istream& operator>>(istream& in, Matrix<T>& A) {
    A.matrix = new T* [A.a];
    for(int i = 0; i < A.a ; i++)
    {
        A.matrix[i] = new T [A.b];
    }
    for (int i = 0; i < A.a; i++)
    {
        for(int j = 0; j < A.b; j++)
        {
        in >> A.matrix[i][j];
        }
    }
    return in;
}

#endif
