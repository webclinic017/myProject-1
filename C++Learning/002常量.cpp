#include <iostream>
using namespace std;

//常量的定义方式
// 1. #define 宏常量
#define day 7

// 2. const 修饰的变量
const int month = 12; // 非全局变量

int main() {
	
	//day = 14; //报错 lvalue required as left operand of assignment
	cout << "一周总共有"<<day<< "天" <<endl;
	// const int month = 12;
	// month = 24; //报错assignment of read-only variable
	cout << "一年总共有"<<month<< "月" <<endl;	
	
	
	
	return 0;
}
