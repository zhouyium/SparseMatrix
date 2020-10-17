//测试函数
#include <iostream>
#include <vector>
#include "SparseMatrix.h"
#include "CSRMatrix.h"

using namespace std;

int main() {
    //矩阵a是一个零阵
    cout<<"赋值测试\n";
    CSRMatrix<int, int> a(5, 10);
    a.ToMatrix();
    cout<<"a(2, 8, 1)===\n";
    a(2, 8, 1);
    a.ToMatrix();
    cout<<"a(2, 4, 2)===\n";
    a(2, 4, 2);
    a.ToMatrix();
    cout<<"a(2, 6, 3)===\n";
    a(2, 6, 3);
    a.ToMatrix();
    cout<<"a(2, 2, 4)===\n";
    a(2, 2, 4);
    a.ToMatrix();
    cout<<"a(2, 3, 5)===\n";
    a(2, 3, 5);
    a.ToMatrix();
    cout<<"a(1, 1, 6)===\n";
    a(1, 1, 6);
    a.ToMatrix();
    cout<<"a(1, 3, 7)===\n";
    a(1, 3, 7);
    a.ToMatrix();
    cout<<"a(4, 5, 8)===\n";
    a(4, 5, 8);
    a.ToMatrix();
    cout<<"a(6, 1, 6)===\n";
    a(6, 1, 6);
    a.ToMatrix();
    cout<<"a(4, 5, 9)===\n";
    a(4, 5, 9);
    a.ToMatrix();
    cout<<"a(2, 3, 12)===\n";
    a(2, 3, 12);
    a.ToMatrix();
    cout<<"a(2, 2, 13)===\n";
    a(2, 2, 13);
    a.ToMatrix();
    cout<<"a(2, 3, 0)===\n";
    a(2, 3, 0);
    a.ToMatrix();
    cout<<"a(2, 3, 4)===\n";
    a(2, 3, 4);
    a.ToMatrix();
    cout<<"a(2, 3, 5)===\n";
    a(2, 3, 5);
    a.ToMatrix();
    cout<<"a(2, 3, 0)===\n";
    a(2, 3, 0);
    a.ToMatrix();
    cout<<"a(2, 3, 7)===\n";
    a(2, 3, 7);
    a.ToMatrix();
    cout<<"a(2, 4, 7)===\n";
    a(2, 4, 7);
    a.ToMatrix();
    cout<<"===\n";

    cout<<"\n*拷贝方法1测试===\n";
    CSRMatrix<int, int> b;
    b=a;
    b.ToMatrix();
    cout<<"===\n";

    cout<<"\n*拷贝方法2测试===\n";
    int row[] ={0, 2, 4, 7, 9};
    int col[] ={0, 1, 1, 2, 0, 2, 3, 1, 3};
    int data[]={1, 7, 2, 8, 5, 3, 9, 6, 4};
    vector<int> vr(row, row+sizeof(row)/sizeof(int));
    vector<int> vc(col, col+sizeof(col)/sizeof(int));
    vector<int> vd(data, data+sizeof(data)/sizeof(int));
    CSRMatrix<int, int> c(4, 4, vr, vc, vd);
    cout<<"===\n";
    cout<<"1, 1:"<<c(1, 1)<<"\n";
    cout<<"1, 2:"<<c(1, 2)<<"\n";
    cout<<"1, 3:"<<c(1, 3)<<"\n";
    cout<<"1, 4:"<<c(1, 4)<<"\n";
    cout<<"\n";
    cout<<"2, 1:"<<c(2, 1)<<"\n";
    cout<<"2, 2:"<<c(2, 2)<<"\n";
    cout<<"2, 3:"<<c(2, 3)<<"\n";
    cout<<"2, 4:"<<c(2, 4)<<"\n";
    cout<<"\n";
    cout<<"3, 1:"<<c(3, 1)<<"\n";
    cout<<"3, 2:"<<c(3, 2)<<"\n";
    cout<<"3, 3:"<<c(3, 3)<<"\n";
    cout<<"3, 4:"<<c(3, 4)<<"\n";
    cout<<"3, 5:"<<c(3, 5)<<"\n";
    cout<<"\n";
    cout<<"4, 1:"<<c(4, 1)<<"\n";
    cout<<"4, 2:"<<c(4, 2)<<"\n";
    cout<<"4, 3:"<<c(4, 3)<<"\n";
    cout<<"4, 4:"<<c(4, 4)<<"\n";
    cout<<"===\n";
    c.ToMatrix();
    cout<<"===\n";

    //std::vector 
    //CSRMatrix<int> xxx()

    return 0;
}