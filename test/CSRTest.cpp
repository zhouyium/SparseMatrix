//测试函数
#include <iostream>
#include "SparseMatrix.h"
#include "CSRMatrix.h"

using namespace std;

int main() {
    CSRMatrix<int, int> xxx(3, 5);
    xxx.ToMatrix();

    //std::vector 
    //CSRMatrix<int> xxx()

    return 0;
}