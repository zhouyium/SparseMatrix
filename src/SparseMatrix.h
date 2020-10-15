//SparseMatrix.h
#ifndef __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__
#define __SPARSE_MATRIX_H_DE38UR83CNKUR8CJIJ8C382XH197R3__

class SparseMatrix {
public:
    SparseMatrix() {};
    virtual ~SparseMatrix() {};

public:
    virtual void ToMatrix() = 0;   ///< 实现打印全矩阵功能

private:
};

#endif