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
    CSRMatrix(iT rows=1, iT cols=1);

    //! copy constructor
    CSRMatrix(const CSRMatrix& m);

    CSRMatrix(iT rows,
        iT cols,
        const std::vector<iT>& row,
        const std::vector<iT>& col,
        const std::vector<fT>& data);

    //! default destructor
    ~CSRMatrix();

public:
    // accessors and mutators for class members
    std::vector<iT>&        rowVector(void);
    const std::vector<iT>&  rowVector(void) const;
    void                    rowVector(const std::vector<iT>& v);

    std::vector<iT>&        colVector(void);
    const std::vector<iT>&  colVector(void) const;
    void                    colVector(const std::vector<iT>& v);

    std::vector<fT>&        operator()(void);
    const std::vector<fT>&  operator()(void) const;
    void                    operator()(const std::vector<fT>& d);

    const fT&               operator()(iT row, iT col) const;
    void                    operator()(iT row, iT col, fT val);

    /* support operators */
public:
    //matrix operator methods
    CSRMatrix&              operator=(const CSRMatrix& m);
#if 0
    CSRMatrix               operator+(const CSRMatrix& m) const;
    CSRMatrix               operator+=(const CSRMatrix& m) const;
    CSRMatrix               operator-(const CSRMatrix& m) const;
    CSRMatrix               operator-=(const CSRMatrix& m) const;
    CSRMatrix               operator*(const CSRMatrix& m) const;
    CSRMatrix               operator*(fT alpha) const;
    std::vector<fT>         operator*(const std::vector<fT> v) const;
#endif

public:
    //! print the matrix
    virtual void ToMatrix();

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
CSRMatrix<iT, fT>::CSRMatrix(iT rows, iT cols) : SparseMatrix<iT>(rows, cols) {
    //
    _row.empty();
    _col.empty();
    _data.empty();
}

//! copy constructor
template <typename iT, typename fT>
CSRMatrix<iT, fT>::CSRMatrix(const CSRMatrix& m) : SparseMatrix<iT>(m.Rows(), m.Cols()),
    _row(m.rowVector()),
    _col(m.colVector()), 
    _data(m()) {
}

template <typename iT, typename fT>
CSRMatrix<iT, fT>::CSRMatrix(iT rows,
    iT cols,
    const std::vector<iT>& row,
    const std::vector<iT>& col,
    const std::vector<fT>& data) : SparseMatrix<iT>(rows, cols),
    _row(row),
    _col(col),
    _data(data) {
}

//! default destructor
template <typename iT, typename fT>
CSRMatrix<iT, fT>::~CSRMatrix() {
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

//! return vector of non-zero elements and diagonal elements of matrix
template <typename iT, typename fT>
inline std::vector<fT>& CSRMatrix<iT, fT>::operator()(void) { 
    return this->_data; 
}

//! return copy of vector of non-zero elements and diagonal elements of matrix
template <typename iT, typename fT>
inline const std::vector<fT>& CSRMatrix<iT, fT>::operator()(void) const { 
    return _data; 
}

//! set vector of non-zero elements and diagonal elements of matrix to specified vector
template <typename iT, typename fT>
inline void CSRMatrix<iT, fT>::operator()(const std::vector<fT>& d) { 
    _data = d; 
}

/**
 * return value at specified indices of matrix
 * @param row matrix row
 * @param col matrix column
 * @return value at specified matrix row and column
 */
template <typename iT, typename fT>
const fT& CSRMatrix<iT, fT>::operator()(iT row, iT col) const {
    //TBD
    return 0;
}

/**
 * set value at specified indices of matrix
 * @param row matrix row
 * @param col matrix column
 * @param val value at specified matrix row and column
 */
template <typename iT, typename fT>
void CSRMatrix<iT, fT>::operator()(iT row, iT col, fT val) {
    //TBD

}

// matrix operator methods
/**
 * matrix assignment
 * @param m assign this to m (ie. produce a "deep" copy)
 * @return copy
 */
template <typename iT, typename fT>
CSRMatrix<iT, fT>& CSRMatrix<iT, fT>::operator=(const CSRMatrix<iT,fT>& m) {
	if (this != &m) {
		// perform copy
        this->Rows(m.Rows());
        this->Cols(m.Cols());
		this->rowVector(m.rowVector());
        this->colVector(m.colVector());
		(*this)(m());
	}
	
	// return reference
	return (*this);	
}

template <typename iT, typename fT>
void CSRMatrix<iT, fT>::ToMatrix() {
    iT rows = SparseMatrix<iT>::Rows();
    iT cols = SparseMatrix<iT>::Cols();

    std::cout<<"row nums is "<<rows<<" col nums is "<<cols<<"\n";

    iT idx=0;
    iT sz = _row.size();
    for (iT i=0; i<rows; i++) {
        //确定本行有几个数据
        iT nums=0;
        if (sz>i) {
            nums=_row[i+1]-_row[i];//本行数据个数
        }
        for (iT j=0; j<cols; j++) {
            fT x = 0;
            if (0!=nums && j==_col[idx]) {
                x = _data[idx];
                idx++;
            }
            std::cout<<x<<' ';
        }
        std::cout<<'\n';
    }
}

//} //end of namespace

#endif