//CSRMatrix
#ifndef __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__
#define __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__

#include "SparseMatrix.h"
#include <iostream>
#include <vector>

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
        std::cout<<"this is a test.\n";
    }

private:
    int _rowNums;//行数量
    int _colNums;//列数量
    std::vector<T> _row;//行信息
    std::vector<T> _col;//列信息
    std::vector<T> _data;//数据信息
};

#endif