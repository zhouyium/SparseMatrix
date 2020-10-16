//CSRMatrix
#ifndef __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__
#define __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__

#include "SparseMatrix.h"
#include <iostream>
#include <vector>
#include <ctime>

template <typename elementType>
class CSRMatrix : SparseMatrix{
public:
    CSRMatrix() {}

    ~CSRMatrix() {}

    CSRMatrix(const std::vector<elementType>& row,
              const std::vector<elementType>& col,
              const std::vector<elementType>& data) {

    }


public:
    void ToMatrix(unsigned long long rows, unsigned long long cols) {
        unsigned long long i, j;
        elementType **array;//指向指针的指针，表示一个二维数组
        array=new elementType *[rows];//申请行
        for (i=0; i<rows; i++) {
            array[i]=new elementType[cols];//申请列
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
    std::vector<elementType> _row;//行信息
    std::vector<elementType> _col;//列信息
    std::vector<elementType> _data;//数据信息
};

#endif