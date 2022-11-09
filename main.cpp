#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include "Matrix.h"
#include <cstdlib>
#include <unistd.h>

using namespace std;

void strange_number()
{
cout << "Strange number, don't you think?\n";
sleep(1);
system("clear");
}

bool check_number(string a)
{
    int er = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if(int(a[i]) - 48 < 0 || int(a[i]) - 48 > 9){er = 1;i = a.length();}
    }
    if(er)return false;
    else return true;
}

int main()
{
    srand(time(NULL));
    int a,b,c,d;
    string w;
    string command = "";
    while(command != "STOP")
    {
        cout << "1.Multiplying matrix by number \n2.Sum of matrix\n3.Transposition of matrix\n4.Multiplying matrices\n5.Matrix degree\n6.Matrix determinant\n7.Matrix reverse(test)\n8.Solving equations (n equations and n unknowns)\n9.STOP\n\n Choose the command:\n";
        cin >> w;
        if(int(w[0]) - 48 == 1 && w.size() == 1)
        {
            cout << "Enter the size of matrix\n";
            try
            {
                cin >> a;
                if(a <= 0)throw "gg";
                cin >> b;
                if(b <= 0)throw "gg";
                Matrix<int> A(a,b);
                cout << "Enter the numbers for matrix\n";
                cin >> A;
                cout << "Enter the number for multiplying\n";
                int k;
                cin >> k;
                if(k==0)throw "gg";
                cout << "Original matrix:\n";
                cout << A;
                Matrix<int> C = A * k;
                cout << "\nNew matrix:\n";
                cout << C;
                cout << endl;
            }
            catch(const char *err)
            {
                if(err == "gg")cout << "Strange number :(\n";
            }
        }


        else if(int(w[0])-48==2&&w.size()==1)
        {

            cout << "Enter the size of matrices\n";
            cin >> a >> b;
            Matrix<int> A(a,b),B(a,b);
            cout << "Enter the numbers for the first matrix\n";
            cin >> A;
            cout << "Enter the numbers for the second matrix\n";
            cin >> B;
            cout << "Original matrices:\n\n";
            cout << A << endl << B;
            cout << endl;

            Matrix<int> C;
            C = A + B;
            cout << "New matrix:\n"<<C;
        }


        else if(int(w[0]) - 48 == 3 && w.size() == 1)
        {
            cout << "Enter the size of matrix\n";
            cin >> a >> b;
            Matrix<int> A;
            A.set_a(a);
            A.set_b(b);
            cout << "Enter the numbers for the matrix\n";
            cin >> A;
            cout << "Original matrix:\n";
            cout << A;
            Matrix<int> C = A.transposition();
            cout << "\nNew matrix:\n" << C;
        }


        else if(int(w[0]) - 48 == 4 && w.size() == 1)
        {
            cout << "Enter the size of the first matrix\n";
            cin >> a >> b;
            Matrix<int> A;
            A.set_a(a);
            A.set_b(b);
            cout << "Enter the numbers for the first matrix\n";
            cin >> A;
            cout << "Enter the size of the second matrix\n";
            cin >> c >> d;

            Matrix<int> B;
            B.set_a(c);
            B.set_b(d);
            cout << "Enter the numbers for the second matrix\n";
            cin >> B;
            cout << "Original matrices:\n\n";
            cout << A << endl << B;
            Matrix<int> C;
            try
            {
                C = A * B;
                cout << "\nNew matrix:\n";
                cout << C;
            }
            catch(string error)
            {
                cout << "Error: " << error << endl;
            }


        }


        else if(int(w[0]) - 48 == 5 && w.size() == 1)
        {
            cout << "Enter the size of matrix\n";
            cin >> a >> b;
            Matrix<int> A;
            A.set_a(a);
            A.set_b(b);
            cout << "Enter the numbers for the matrix\n";
            cin >> A;
            if(a == b)
            {
                cout << "Enter the degree of matrix\n";
                int n;
                cin >> n;
                Matrix<int> B;
                B = A.fastPOW(n);
                cout << "Original matrix:\n" << A;
                cout << "Matrix in " << n << " degree:\n";
                cout << B;
            }
            else cout << "This matrix could not be multiplied by itself :/";
        }

        else if(int(w[0]) - 48 == 6 && w.size() == 1)
        {
            cout << "Enter the size of matrix (only one number)\n";
            cin >> a;
            Matrix<int> A;
            A.set_a(a);
            A.set_b(a);
            cout << "Enter the numbers for the matrix\n";
            cin >> A;
            cout << "Matrix:\n" << A;
            cout << "determinant:\n";
            int det = 0;
            det = A.determinant(a);
            cout << det << endl;
        }

        else if(int(w[0]) - 48 == 7 && w.size() == 1)
        {
            cout << "Enter the size of matrix (only one number)\n";
            cin >> a;
            Matrix<float> A;
            A.set_a(a);
            A.set_b(a);
            cout << "Enter the numbers for the matrix\n";
            cin >> A;
            cout << "Matrix:\n" << A;
            cout << "Reversed Matrix:\n";
            Matrix<float> B;
            B = A.reverse_matrix();
            cout << B;
        }

        else if(int(w[0]) - 48 == 8 && w.size() == 1)
        {
            cout << "Enter the amount of equations\n";
            cin >> a;
            Matrix<float> A(a);
            cout << "Enter the coefficients of the equations\n";
            cin >> A;
            cout << "Enter the free terms\n";
            Matrix<float> B(a,1);
            cin >> B;
            A = A.reverse_matrix();
            A = A * B;
            cout << "Values of unknowns:\n";
            cout << A;
        }

        else if(int(w[0]) - 48 == 9 && w.size() == 1)
        {
            command = "STOP";
            return 0;
        }


        else
        {
            cout << "strange command :/\n\n";
        }
        cout << "Do you want to continue?\nEnter 'continue'\n";
        string cont = "";
        cin >> cont;
        if(cont == "continue")system("clear");
        else
        {
            cout << "indeed )))\n";
            sleep(1);
            system("clear");
        }
    }
    return 0;
}
