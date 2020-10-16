//SparseMatrix.h
#ifndef __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__
#define __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__

template <typename iT>
class SparseMatrix {
public:
    SparseMatrix(iT rows=1, iT cols=1) : 
        _rows(rows),
        _cols(cols) {}
        
    virtual ~SparseMatrix() {}

public:
    //! print the full matrix
    virtual void ToMatrix() = 0;

    //! get row number
    inline iT getRows() const {return _rows;}

    //! get col number
    inline iT getCols() const {return _cols;}

    //! set row number
    inline void setRows(iT x) {_rows=x;}

    //! set col number
    inline void setCols(iT x) {_cols=x;}

private:
    //! row number
    iT _rows;

    //! col number
    iT _cols;
};//end of class SparseMatrix

#endif