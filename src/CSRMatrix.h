//CSRMatrix
#ifndef __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__
#define __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__

#include "SparseMatrix.h"
#include <iostream>
#include <vector>
#include <ctime>

//namespace csr {

template <typename iT, typename fT>
class CSRMatrix : SparseMatrix<iT>{
public:
    //! default constructor
    CSRMatrix(iT rows, iT cols);

    //! copy constructor
    CSRMatrix(const CSRMatrix& m);

    ~CSRMatrix() {}

    CSRMatrix(const std::vector<iT>& row,
              const std::vector<iT>& col,
              const std::vector<fT>& data) {
        //TBD
    }

public:
    // accessors and mutators for class members
    std::vector<iT>&        rowVector(void);
    const std::vector<iT>&  rowVector(void) const;
    void                                    rowVector(const std::vector<iT>& v);

    std::vector<iT>&        colVector(void);
    const std::vector<iT>&  colVector(void) const;
    void                                    colVector(const std::vector<iT>& v);

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
    std::vector<iT> _row;

    //! column index pointer vector
    std::vector<iT> _col;

    //! vector of non-zero elements and diagonal elements of matrix
    std::vector<fT> _data;
}; //end of class CSRMatrix

//! default constructor
template <typename iT, typename fT>
CSRMatrix<iT, fT>::CSRMatrix(iT rows, iT cols) : 
    SparseMatrix<iT>(rows, cols) {
}

//! copy constructor
template <typename iT, typename fT>
CSRMatrix<iT, fT>::CSRMatrix(const CSRMatrix& m) : 
    SparseMatrix<iT>(m.getRows(), m.getCols) {
}


//! return row pointer vector
template <typename iT, typename fT>
inline std::vector<iT>& CSRMatrix<iT, fT>::rowVector(void) { 
    return this->_row; 
}

//! return copy of row pointer vector
template <typename iT, typename fT>
inline const std::vector<iT>& CSRMatrix<iT, fT>::rowVector(void) const { 
    return _row; 
}

//! set row pointer vector to specified vector 
template <typename iT, typename fT>
inline void CSRMatrix<iT, fT>::rowVector(const std::vector<iT>& v) { 
    _row = v; 
}

//! return column pointer vector
template <typename iT, typename fT>
inline std::vector<iT>& CSRMatrix<iT, fT>::colVector(void) { 
    return this->_col; 
}

//! return copy of column pointer vector
template <typename iT, typename fT>
inline const std::vector<iT>& CSRMatrix<iT, fT>::colVector(void) const { 
    return _col; 
}

//! set column pointer vector to specified vector
template <typename iT, typename fT>
inline void CSRMatrix<iT, fT>::colVector(const std::vector<iT>& v) { 
    _col = v; 
}

template <typename iT, typename fT>
void CSRMatrix<iT, fT>::ToMatrix() {
    iT rows = SparseMatrix<iT>::getRows();
    iT cols = SparseMatrix<iT>::getCols();
    iT i, j;
    fT **array;//指向指针的指针，表示一个二维数组
    array=new fT *[rows];//申请行
    for (i=0; i<rows; i++) {
        array[i]=new fT[cols];//申请列
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