//CSRMatrix
#ifndef __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__
#define __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__

#include "SparseMatrix.h"
#include <iostream>
#include <vector>
#include <ctime>

template <typename T>
class CSRMatrix : SparseMatrix{
public:
    CSRMatrix() {}

    ~CSRMatrix() {}

    CSRMatrix(const std::vector<T>& row,
              const std::vector<T>& col,
              const std::vector<T>& data) {

    }


public:
    void ToMatrix(unsigned long long rows, unsigned long long cols) {
        unsigned long long i, j;
        T **array;//指向指针的指针，表示一个二维数组
        array=new T *[rows];//申请行
        for (i=0; i<rows; i++) {
            array[i]=new T[cols];//申请列
        }
        std::cout<<"row nums is "<<rows<<" col nums is "<<cols<<"\n";

        //这里使用随机数
        int maxx=200;
        int minx=1;

        srand((unsigned int)time(NULL));
        for (i=0; i<rows; i++) {
            for (j=0; j<cols; j++) {
                int x=rand()%(maxx-minx+1)+minx;
                std::cout<<x<<' ';
            }
            std::cout<<'\n';
        }

        for (i=0; i<rows; i++) {
            delete[] array[i];//释放列
        }
        delete[] array;//释放行        
    }

private:
    int _rowNums;//行数量
    int _colNums;//列数量
    std::vector<T> _row;//行信息
    std::vector<T> _col;//列信息
    std::vector<T> _data;//数据信息
};

#endif