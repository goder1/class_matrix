#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

void umnozim(int** A,int** B,int** C,int a,int b,int c,int d)
{
for(int i = 0;i<a;i++)
    for(int q = 0;q<d;q++)
    {
        for(int t = 0;t<c;t++)
        C[i][q]+=A[i][t]*B[t][q];
    }





}
void menaystroka(int** A,int** B,int a,int b,int x,int y){
for (int i = 0; i < a; i++)
{
int c = A[x][i];
A[x][i]=A[y][i];
A[y][i]=c;
}

}
void menaystolb(int** A,int** B,int a,int b,int x,int y)
{
for (int i = 0; i < a; i++)
{
int c = A[i][x];
A[i][x]=A[i][y];
A[i][y]=c;
}
}

void transponiruy(int** A,int** B,int a,int b)
{
for (int i = 0; i < b; i++)
{
for(int q = 0; q < a; q++)
{
B[i][q]=A[q][i];
}
}
}
void slozhi(int** A,int** B,int** C,int a,int b){
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
C[i][q]=A[i][q]+B[i][q];
}
}
}
void umnozh(int** A,int a,int b,int k){
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q]*=k;
}
}
}
int main()
{
srand(time(NULL));
int a,b,c,d,g=0,p;
int w;
cout<<"1.Multiplying matrix by number \n2.Sum of matrix\n3.Transposition of matrix\n4.Swapping column\n5.Swapping lines\n6.Multiplying matrices\n";
cin>>w;
if(w==1){
cout<<"Enter the size of matrix\n";
cin >> a >> b;
int **A = new int* [a];
for (int i = 0; i < a; i++) A[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 100;
}
}
cout<<"Enter the number for multiplying\n";
int k;cin>>k;
cout<<"Original matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}
umnozh(A,a,b,k);
cout<<"\nNew matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}


}


if(w==2)
{

    cout<<"Enter the size of matrix\n";
cin >> a >> b;
int **A = new int* [a];
int **B = new int* [a];
for (int i = 0; i < a; i++) {A[i] = new int [b];B[i] = new int [b];}
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 100;
B[i][q] = rand() % 100;
}
}
cout<<"Original matrices:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}
cout<<endl;
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<B[i][q]<<" ";
}
cout<<endl;
}

int **C = new int* [a];
for (int i = 0; i < a; i++) C[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
C[i][q] = 0;
}
}
slozhi(A,B,C,a,b);
cout<<"\nNew matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<C[i][q]<<" ";
}
cout<<endl;
}



}
if(w==3){
cout<<"Enter the size of matrix\n";
cin >> a >> b;
int **A = new int* [a];
for (int i = 0; i < a; i++) A[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 100;
}
}

int **B = new int* [b];
for (int i = 0; i < b; i++) B[i] = new int [a];
for (int i = 0; i < b; i++)
{
for(int q = 0; q < a; q++)
{
B[i][q] = 0;
}
}

cout<<"Original matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}
transponiruy(A,B,a,b);
cout<<"\nNew matrix:\n";
for (int i = 0; i < b; i++)
{
for(int q = 0; q < a; q++)
{
cout<<B[i][q]<<" ";
}
cout<<endl;
}


}

if(w==4){
cout<<"Enter the size of matrix\n";
cin >> a >> b;
int **A = new int* [a];
for (int i = 0; i < a; i++) A[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 100;
}
}

int **B = new int* [a];
for (int i = 0; i < a; i++) B[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
B[i][q] = 0;
}
}
cout<<"Enter numbers of columns which you want to swap\n";
int x,y;cin>>x>>y;
x-=1;
y-=1;
cout<<"Original matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}
menaystolb(A,B,a,b,x,y);
cout<<"\nNew matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}


}


if(w==5){
cout<<"Enter the size of matrix\n";
cin >> a >> b;
int **A = new int* [a];
for (int i = 0; i < a; i++) A[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 100;
}
}

int **B = new int* [a];
for (int i = 0; i < a; i++) B[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
B[i][q] = 0;
}
}
cout<<"Enter numbers of lines which you want to swap\n";
int x,y;cin>>x>>y;
x-=1;
y-=1;
cout<<"Original matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}
menaystroka(A,B,a,b,x,y);
cout<<"\nNew matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}


}


if(w==6){
cout<<"Enter the size of first matrix\n";
cin >> a >> b;
int **A = new int* [a];
for (int i = 0; i < a; i++) A[i] = new int [b];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
A[i][q] = rand() % 10;
}
}
cout<<"Enter the size of second matrix\n";
cin >> c >> d;
int **B = new int* [c];
for (int i = 0; i < c; i++) B[i] = new int [d];
for (int i = 0; i < c; i++)
{
for(int q = 0; q < d; q++)
{
B[i][q] = rand() % 10;
}
}
int **C = new int* [a];
for (int i = 0; i < a; i++) C[i] = new int [d];
for (int i = 0; i < a; i++)
{
for(int q = 0; q < d; q++)
{
C[i][q] = 0;
}
}
cout<<"Original matrices:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < b; q++)
{
cout<<A[i][q]<<" ";
}
cout<<endl;
}
cout<<endl;
for (int i = 0; i < c; i++)
{
for(int q = 0; q < d; q++)
{
cout<<B[i][q]<<" ";
}
cout<<endl;
}
umnozim(A,B,C,a,b,c,d);
cout<<"\nNew matrix:\n";
for (int i = 0; i < a; i++)
{
for(int q = 0; q < d; q++)
{
cout<<C[i][q]<<" ";
}
cout<<endl;
}


}
}
