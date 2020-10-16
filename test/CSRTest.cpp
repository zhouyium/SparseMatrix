//测试函数
#include <iostream>
#include <vector>
#include "SparseMatrix.h"
#include "CSRMatrix.h"

using namespace std;

int main() {
    //矩阵a是一个零阵
    CSRMatrix<int, int> a(3, 5);
    a.ToMatrix();
    cout<<"===\n";

    CSRMatrix<int, int> b;
    b=a;
    b(0, 1, 2);
    b.ToMatrix();
    cout<<"===\n";

    int row[] ={0, 2, 4, 7, 9};
    int col[] ={0, 1, 1, 2, 0, 2, 3, 1, 3};
    int data[]={1, 7, 2, 8, 5, 3, 9, 6, 4};
    vector<int> vr(row, row+sizeof(row)/sizeof(int));
    vector<int> vc(col, col+sizeof(col)/sizeof(int));
    vector<int> vd(data, data+sizeof(data)/sizeof(int));
    CSRMatrix<int, int> c(4, 4, vr, vc, vd);
    cout<<"===\n";
    cout<<"0, 0:"<<c(0, 0)<<"\n";
    cout<<"0, 1:"<<c(0, 1)<<"\n";
    cout<<"0, 2:"<<c(0, 2)<<"\n";
    cout<<"0, 3:"<<c(0, 3)<<"\n";
    cout<<"\n";
    cout<<"1, 0:"<<c(1, 0)<<"\n";
    cout<<"1, 1:"<<c(1, 1)<<"\n";
    cout<<"1, 2:"<<c(1, 2)<<"\n";
    cout<<"1, 3:"<<c(1, 3)<<"\n";
    cout<<"\n";
    cout<<"2, 0:"<<c(2, 0)<<"\n";
    cout<<"2, 1:"<<c(2, 1)<<"\n";
    cout<<"2, 2:"<<c(2, 2)<<"\n";
    cout<<"2, 3:"<<c(2, 3)<<"\n";
    cout<<"2, 4:"<<c(2, 4)<<"\n";
    cout<<"\n";
    cout<<"3, 0:"<<c(3, 0)<<"\n";
    cout<<"3, 1:"<<c(3, 1)<<"\n";
    cout<<"3, 2:"<<c(3, 2)<<"\n";
    cout<<"3, 3:"<<c(3, 3)<<"\n";
    cout<<"===\n";

    c.ToMatrix();
    cout<<"===\n";

    //std::vector 
    //CSRMatrix<int> xxx()

    return 0;
}