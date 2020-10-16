//SparseMatrix.h
#ifndef __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__
#define __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__

class SparseMatrix {
public:
    SparseMatrix(unsigned long long rows=1, unsigned long long cols=1) : 
        _rows(rows),
        _cols(cols) {}
        
    virtual ~SparseMatrix() {}

public:
    //! print the full matrix
    virtual void ToMatrix() = 0;

    //! get row number
    unsigned long long getRows() const {return _rows;}

    //! get col number
    unsigned long long getCols() const {return _cols;}

    //! set row number
    void setRows(unsigned long long x) {_rows=x;}

    //! set col number
    void setCols(unsigned long long x) {_cols=x;}

private:
    //! row number
    unsigned long long _rows;

    //! col number
    unsigned long long _cols;
};

#endif