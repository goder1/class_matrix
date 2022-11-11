#ifndef Matrix_h
#define Matrix_h

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>
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

    T get_elem(int i, int j)
    {
        return matrix[i][j];
    }

    void set_elem(T elem, int i, int j)
    {
        matrix[i][j] = elem;
    }

    Matrix()
    {
        a = 0;b = 0;
        matrix = new T* [a];
        for (int j = 0; j < a; j++)
        {
        matrix[j] = new T [a];
        }
    }

    Matrix(int x)
    {
        a = x; b = x;
        matrix = new T* [a];
        for (int j = 0; j < a; j++)
        {
        matrix[j] = new T [a];
        }
    }

    Matrix(int x, int y)
    {
        a = x; b = y;
        matrix = new T* [a];
        for (int j = 0; j < a; j++)
        {
        matrix[j] = new T [b];
        }
    }

    Matrix E_matrix(int a)
    {
        Matrix<T> A;
        A.matrix = new T* [a];
        for(int i = 0; i < a; i++)
        {
            A.matrix[i] = new T [a];
        }
        for(int i = 0 ; i < a; i++)
        {
            for(int j = 0; j < a; j++)
            {
                if(i == j)A.matrix[i][j] = 1;
                else A.matrix[i][j] = 0;
            }
        }
        A.a = a;
        A.b = a;
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
        if(n == 0)return E_matrix(a);
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
        Matrix C(a,b);
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
        Matrix C(a,b);
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

    void operator=(Matrix<T> A)
    {
        a = A.a;
        b = A.b;
        matrix = new T* [a];
        for (int j = 0; j < a; j++)
        {
        matrix[j] = new T [b];
        }
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                matrix[i][j] = A.matrix[i][j];
            }
        }
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
                Matrix<T> B(a-1);
                for (int j = 0; j < a-1; j++)
                {
                for(int q = 0; q < i; q++)
                {
                    //B.matrix[j][q] = matrix[j+1][q];
                    B.set_elem(matrix[j+1][q],j,q);
                }
                for(int q = i; q < a-1; q++)
                {
                    //B.matrix[j][q] = matrix[j+1][q+1];
                    B.set_elem(matrix[j+1][q+1],j,q);
                }
                }
                s += matrix[0][i] * B.determinant(a-1) * k;
                k =- k;
            }
        return s;
        }
    }

    void swap_lines(int x, int y)
    {
        for (int i = 0; i < a; i++)
        {
            swap(matrix[x][i], matrix[y][i]);
        }
    }
    void swap_colummns(int x, int y)
    {
        for (int i = 0; i < a; i++)
        {
            swap(matrix[i][x], matrix[i][y]);
        }
    }

    Matrix reverse_matrix()
    {
        Matrix<T> B = E_matrix(a);
        Matrix<T> C(a,b);
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            C.matrix[i][j] = matrix[i][j];
        }

        if(C.determinant(a) != 0)
        {
            for(int i = 0; i < a; i++)
            {
                for(int j = 0; j < a; j++)
                {
                    //making not 0 numbers on the main diagonal
                    if(i == j && C.matrix[i][j] == 0)
                    {
                        int no_way = 0;
                        for(int q = 0; q < a; q++)
                        {
                            if(C.matrix[q][j] != 0 && C.matrix[i][q] != 0)
                            {
                                for (int p = 0; p < a; p++)
                                {
                                    swap(C.matrix[q][p], C.matrix[i][p]);
                                }
                                for (int p = 0; p < a; p++)
                                {
                                    swap(B.matrix[q][p], B.matrix[i][p]);
                                }
                                no_way = 1;
                            }
                        }
                        if(no_way == 0)
                        {
                            return E_matrix(0);
                        }
                    }
                }
            }
            for(int j = 0; j < a; j++)
            {
                for(int i = j; i < a; i++)
                {
                    if(i != j && C.matrix[i][j] != 0)
                    {
                        for(int q = 0; q < a; q++)
                        {
                            if(C.matrix[q][j] != 0 && q != i && q >= j)
                            {
                                for(int k = 0; k < a; k++)
                                {
                                    if (k!= j)
                                    {
                                        C.matrix[i][k] = C.matrix[i][k] * C.matrix[q][j] - C.matrix[q][k] * C.matrix[i][j];
                                    }
                                    B.matrix[i][k] = B.matrix[i][k] * C.matrix[q][j] - B.matrix[q][k] * C.matrix[i][j];
                                }
                                C.matrix[i][j] = 0;
                            }
                        }
                    }
                }
                for(int k = 0; k < a; k++)
                {
                    for(int d = 0; d < a; d++)
                    {
                        //making not 0 numbers on the main diagonal
                        if(k == d && C.matrix[k][d] == 0)
                        {
                            int no_way = 0;
                            for(int q = 0; q < a; q++)
                            {
                                if(C.matrix[q][d] != 0 && C.matrix[k][q] != 0)
                                {
                                    for (int p = 0; p < a; p++)
                                    {
                                        swap(C.matrix[q][p], C.matrix[k][p]);
                                    }
                                    for (int p = 0; p < a; p++)
                                    {
                                        swap(B.matrix[q][p], B.matrix[k][p]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < a; i++)
            {
                for(int j = i; j < a; j++)
                {
                    if(i != j && C.matrix[i][j] != 0)
                    {
                        for(int q = 0; q < a; q++)
                        {
                            if(C.matrix[q][j] != 0 && q != i && q >= j)
                            {
                                for(int k = 0; k < a; k++)
                                {
                                    if (k!= j)
                                    {
                                        C.matrix[i][k] = C.matrix[i][k] * C.matrix[q][j] - C.matrix[q][k] * C.matrix[i][j];
                                    }
                                    B.matrix[i][k] = B.matrix[i][k] * C.matrix[q][j] - B.matrix[q][k] * C.matrix[i][j];
                                }
                                C.matrix[i][j] = 0;
                                for(int d = 0; d < a ; d++)
                                {
                                    for(int g = 0; g < a; g++)
                                    {
                                        if(abs(C.matrix[d][g])>=10000000000000000000)
                                        {
                                            for(int e = 0; e < a; e++)
                                            {
                                                C.matrix[d][e]/=10000000000000000000;
                                                B.matrix[d][e]/=10000000000000000000;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                for(int k = 0; k < a; k++)
                {
                    for(int d = 0; d < a; d++)
                    {
                        //making not 0 numbers on the main diagonal
                        if(k == d && C.matrix[k][d] == 0)
                        {
                            int no_way = 0;
                            for(int q = 0; q < a; q++)
                            {
                                if(C.matrix[q][d] != 0 && C.matrix[k][q] != 0)
                                {
                                    for (int p = 0; p < a; p++)
                                    {
                                        swap(C.matrix[q][p], C.matrix[k][p]);
                                    }
                                    for (int p = 0; p < a; p++)
                                    {
                                        swap(B.matrix[q][p], B.matrix[k][p]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 0; i < a; i++)
            {
                for(int j = 0; j < a; j++)
                {
                    B.matrix[i][j]/=C.matrix[i][i];
                }
            }
        }
        return B;
    }

    /*void solve_equations()
    {

    }*/

    template<typename Type> friend istream& operator>>(istream&, Matrix<Type>&);
    template<typename Type> friend ostream& operator<<(ostream&, const Matrix<Type>&);

    T* operator[](int a)
    {
        return matrix[a];
    }


    ~Matrix()
    {
        for(int i = 0; i < a; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    Matrix(const Matrix & A)
    {
        a = A.a;
        b = A.b;
        matrix = new T* [a];
        for(int i = 0; i < a; i++)
        {
            matrix[i] = new T [b];
        }
        for(int i = 0; i < a; i++)
        {
            for(int j = 0; j < b; j++)
            {
                matrix[i][j] = A.matrix[i][j];
            }
        }
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
