//CSRMatrix
#ifndef __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__
#define __CSR_MATRIX_H_DI2843DH8DN8123909RDYU34X__

#include "SparseMatrix.h"
#include <iostream>
#include <iomanip>
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

    const fT                operator()(iT row, iT col) const;
    void                    operator()(iT row, iT col, fT val);

    /* support operators */
public:
    //matrix operator methods
    CSRMatrix&              operator=(const CSRMatrix& m);
    CSRMatrix               operator+(const CSRMatrix& m);
    CSRMatrix               operator+=(const CSRMatrix& m);
#if 0
    CSRMatrix               operator-(const CSRMatrix& m) const;
    CSRMatrix               operator-=(const CSRMatrix& m) const;
    CSRMatrix               operator*(const CSRMatrix& m) const;
    CSRMatrix               operator*(fT alpha) const;
    std::vector<fT>         operator*(const std::vector<fT> v) const;
#endif

public:
    //! print the matrix
    virtual void ToMatrix();

protected:
    void Init(iT x);

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
    Init(rows);
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

template <typename iT, typename fT>
void CSRMatrix<iT, fT>::Init(iT x) {
    //初始化数据
    _row.reserve(x+1);
    for (iT i=0; i<=x; i++) {
        _row.push_back(0);
    }
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
const fT CSRMatrix<iT, fT>::operator()(iT row, iT col) const {
    row--;
    col--;
    if (row<0 || col<0) {
        return 0;
    }
    iT rows = SparseMatrix<iT>::Rows();
    iT cols = SparseMatrix<iT>::Cols();
    iT rsz = this->_row.size()-1;
    iT csz = this->_col.size();
    
    if (row>rsz || col>csz || row>rows || col>cols) {
        //数据不存在
        std::cout<<__FILE__<<" "<<__LINE__<<"\n";
        return 0;
    }

    //找到row索引
    iT idx_st = _row[row];
    iT idx_ed = _row[row+1];
    for (iT j=idx_st; j<idx_ed; j++) {
        //找 col 索引
        if (col==_col[j]) {
            return _data[j];
        }
    }
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
    row--;
    col--;
    if (row<0 || col<0) {
        return;
    }

    iT rows = SparseMatrix<iT>::Rows();
    iT cols = SparseMatrix<iT>::Cols();
    if (row>rows || col>cols) {
        std::cout<<__FILE__<<" "<<__LINE__<<"\n";
        return;
    }

    if (0==_row[rows] && 0==val) {
        return;
    }

    //列索引
    typename std::vector<iT>::iterator itc = _col.begin();
    iT idx=0;
    //找起点
    for (iT i=_row[row]; i>0; i--) {
        itc++;
        idx++;
    }
    while (itc!=_col.end() && idx<_row[row+1] && *itc<col) {
        itc++;
        idx++;
    }

    //数据索引
    typename std::vector<fT>::iterator itd = _data.begin();
    for (iT i=0; i<idx; i++) {
        itd++;
    }

    //看是插入还是修改. 1 插入,2修改,3删除
    int op=1;
    if (false==_col.empty() && *itc==col) {
        op=2;
        if (0==val) {
            op=3;
        }
    }
    if (1==op) {
        _col.insert(itc, col);
        _data.insert(itd, val);
        //行索引全部加一
        for (iT i=row+1; i<=rows; i++) {
            _row[i]++;
        }
    } else if (2==op) {
        *itd=val;
    } else {
        _col.erase(itc);
        _data.erase(itd);
        //行索引全部减一
        for (iT i=row+1; i<=rows; i++) {
            _row[i]--;
        }
    }
#if 0
    std::cout<<__FILE__<<"\n";
    std::cout<<"_row is:";
    for (itc=_row.begin(); itc!=_row.end(); itc++) {
        std::cout<<*itc<<" ";
    }
    std::cout<<"\n_col is:";
    for (itc=_col.begin(); itc!=_col.end(); itc++) {
        std::cout<<*itc<<" ";
    }
    std::cout<<"\n_data is:";
    for (itd=_data.begin(); itd!=_data.end(); itd++) {
        std::cout<<*itd<<" ";
    }
    std::cout<<"\n";
#endif
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

    //std::cout<<"row nums is "<<rows<<" col nums is "<<cols<<"\n";

    iT idx=0;
    for (iT i=0; i<rows; i++) {
        //确定本行有几个数据
        iT nums=_row[i+1]-_row[i];//本行数据个数
        for (iT j=0; j<cols; j++) {
            fT x = 0;
            if (nums>0 && j==_col[idx]) {
                x = _data[idx];
                idx++;
                nums--;
            }
            std::cout<<x<<' ';
        }
        std::cout<<'\n';
    }
}

/**
 * matrix addition
 * @param m matrix to add to this
 * @return result of matrix addition
 */
template <typename iT, typename fT>
CSRMatrix<iT, fT> CSRMatrix<iT, fT>::operator+(const CSRMatrix<iT, fT>& m) {
    iT rows = SparseMatrix<iT>::Rows();
    iT cols = SparseMatrix<iT>::Cols();
    //创建一个新的矩阵
    CSRMatrix<iT, fT> ret(rows, cols);
    if (rows!=m.Rows() && cols!=m.Cols()) {
        //保证行列数量相等
        return ret;
    }

    //遍历 _row
    typename std::vector<iT>::iterator itA = _col.begin();
    typename std::vector<fT>::iterator ifA = _data.begin();
    std::vector<iT> _colB=m.colVector();
    std::vector<fT> _dataB=m();
    typename std::vector<iT>::iterator itB = _colB.begin();
    typename std::vector<fT>::iterator ifB = _dataB.begin();
    for (iT i=0; i<rows; i++) {
        iT numsA = _row[i+1]-_row[i];
        iT numsB = m.rowVector()[i+1]-m.rowVector()[i];

        if (0==numsA && 0==numsB) {
            continue;
        }
        while (numsA>0 && numsB>0 && _col.end()!=itA && _colB.end()!=itB) {
            if (*itA==*itB) {
                if (0!=(*ifA)+(*ifB)) {
                    ret(i+1, *itA+1, (*ifA)+(*ifB));
                }
                itA++;
                ifA++;
                numsA--;
                itB++;
                ifB++;
                numsB--;
            } else if (*itA>*itB) {
                ret(i+1, *itB+1, *ifB);
                itB++;
                ifB++;
                numsB--;
            } else {
                ret(i+1, *itA+1, *ifA);
                itA++;
                ifA++;
                numsA--;
            }
        }
        while (numsA>0 && _col.end()!=itA) {
            ret(i+1, *itA+1, *ifA);
            itA++;
            ifA++;
            numsA--;
        }
        while (numsB>0 && _colB.end()!=itB) {
            ret(i+1, *itB+1, *ifB);
            itB++;
            ifB++;
            numsB--;
        }
    }
    
    return ret;
}

template <typename iT, typename fT>
CSRMatrix<iT, fT> CSRMatrix<iT, fT>::operator+=(const CSRMatrix<iT, fT>& m) {
    //创建一个新的矩阵
    CSRMatrix<iT, fT> ret(this->Rows(), this->Cols());
    ret = ret+m;
    return ret;
}
//} //end of namespace

#endif