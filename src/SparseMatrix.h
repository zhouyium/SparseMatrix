//SparseMatrix.h
#ifndef __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__
#define __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__

template <typename iT>
class SparseMatrix {
public:
    //! default constructor
    SparseMatrix(iT rows=1, iT cols=1);

    //! default destructor    
    virtual ~SparseMatrix();

public:
    //! print the full matrix
    virtual void ToMatrix() = 0;

    //! get row number
    iT Rows() const;

    //! set row number
    void Rows(iT x);

    //! get col number
    iT Cols() const;

    //! set col number
    void Cols(iT x);

private:
    //! row number
    iT _rows;

    //! col number
    iT _cols;
};//end of class SparseMatrix

template <typename iT>
SparseMatrix<iT>::SparseMatrix(iT rows, iT cols) : _rows(rows),
    _cols(cols) {
}

template <typename iT>
SparseMatrix<iT>::~SparseMatrix() {
}

template <typename iT>
inline iT SparseMatrix<iT>::Rows() const {
    return this->_rows;
}

template <typename iT>
inline void SparseMatrix<iT>::Rows(iT x) {
    this->_rows = x;
}

template <typename iT>
inline iT SparseMatrix<iT>::Cols() const {
    return this->_cols;
}

template <typename iT>
inline void SparseMatrix<iT>::Cols(iT x) {
    this->_cols = x;
}

#endif