#C语言编译器
CC = gcc

#C++编译器
CXX = g++

#简化rm -f
RM = rm -f

#头文件搜索路径
INCLUDE_PATH = ./src

#C语言配置参数
CFLAGS = -g -Wall -std=c11 -I$(INCLUDE_PATH) -o

#C++配置参数
CXXFLAGS = -g -Wall -std=c++11 -I$(INCLUDE_PATH) -o

LDFLAGS = 

#test 需要的东西
TEST_CSR_SOURCES = ./test/CSRTest.cpp
TEST_TARGET = ./build/main
TEST_INCLUDE_PATH = ./src

#编译测试文件
.PHONY : all
all :
	@echo bulding executable file ....
	@$(CXX) $(TEST_CSR_SOURCES) $(CXXFLAGS) $(TEST_TARGET)
	@echo created file: $(TEST_TARGET)		

#删除所有编译带来的文件
.PHONY : clean
clean :
	@echo 'removeing all build file ...'
	$(RM) -r *.so *.o
	@$(RM) -r $(TEST_TARGET)
	@echo 'done'

#重新编译
.PHONY : rebuild
rebuild: clean all

#显示帮助
.PHONY : help
help:
	@echo "本makefile 一共实现了以下几种命令模式"