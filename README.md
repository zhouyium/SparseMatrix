# SparseMatrix
使用 C++ 实现对稀疏矩阵的相关操作。

# CSR
CSR 的数据存储图
![Image text](./images/csr.jpg)

# CSC
CSC 的数据村出土
![Image text](./images/csc.jpg)

# 目录结构
├── LICENSE  
├── Makefile  
├── README.md  
├── build                           可执行文件保存目录  
├── libs                            库文件保存目录  
├── src                             自己实现的CPP文件保存目录，目前H文件也暂时放这里  
│   ├── CSRMatrix.h  
│   └── SparseMatrix.h  
└── test                            测试用代码  
    └── CSRTest.cpp  

# 类说明
SparseMatrix 类  
    一个纯虚类。基类。  
  
CSRMatrix 类  
    继承自 SparseMatrix，实现 CSR 的稀疏矩阵  

# 当前进度
目前只是实现了一个纯虚类，实现了基础的代码。