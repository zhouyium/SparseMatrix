//CSRMatrix
#ifndef __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__
#define __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__

#include "SparseMatrix.h"
#include <iostream>
#include <vector>
#include <ctime>

//namespace csr {

class SparseMatrix;

template <typename elementType>
class CSRMatrix : SparseMatrix{
public:
    //! default constructor
    CSRMatrix(unsigned long long rows, unsigned long long cols);

    //! default constructor
    CSRMatrix(const CSRMatrix& m);

    ~CSRMatrix() {}

    CSRMatrix(const std::vector<elementType>& row,
              const std::vector<elementType>& col,
              const std::vector<elementType>& data) {
        //TBD
    }

public:
    // accessors and mutators for class members
    std::vector<elementType>&        rowVector(void);
    const std::vector<elementType>&  rowVector(void) const;
    void                             rowVector(const std::vector<elementType>& v);

    /* support operators */
public:
    //matrix operator methods
    //CSRMatrix&      operator=(const CSRMatrix& m);
    //SparseMatrix    operator+(const SparseMatrix& m) const;

public:
    //! print the matrix
    void ToMatrix();

private:
    //! row index pointer vector
    std::vector<elementType> _row;

    //! column index pointer vector
    std::vector<elementType> _col;

    //! vector of non-zero elements and diagonal elements of matrix
    std::vector<elementType> _data;
}; //end of class CSRMatrix

//! default constructor
template <typename elementType>
CSRMatrix<elementType>::CSRMatrix(unsigned long long rows, unsigned long long cols) : SparseMatrix(rows, cols) {
}

//! return row pointer vector
template <typename elementType>
inline std::vector<elementType>& CSRMatrix<elementType>::rowVector(void) { 
    return this->_row; 
}

//! return copy of row pointer vector
template <typename elementType>
inline const std::vector<elementType>& CSRMatrix<elementType>::rowVector(void) const { 
    return _row; 
}

//! set row pointer vector to specified vector 
template <typename elementType>
inline void CSRMatrix<elementType>::rowVector(const std::vector<elementType>& v) { 
    _row = v; 
}

template <typename elementType>
void CSRMatrix<elementType>::ToMatrix() {
    unsigned long long rows = getRows();
    unsigned long long cols = getCols();
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

//} //end of namespace

#endif