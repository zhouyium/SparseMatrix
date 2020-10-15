//测试函数
#include <iostream>
#include "SparseMatrix.h"
#include "CSRMatrix.h"

using namespace std;

int main() {
    CSRMatrix<int> xxx;
    xxx.ToMatrix(3, 5);

    //std::vector 
    //CSRMatrix<int> xxx()

    return 0;
}