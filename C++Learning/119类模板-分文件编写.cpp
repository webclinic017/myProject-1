// #include "119Person.cpp"
#include "119Person.hpp"
/*
由于类模板的成员函数是在它调用的时候创建的，如果分文件编写时直接包含”.h“文件，
会导致链接不到它的类外函数实现（”.cpp“）。
解决方法：
	1.直接包含”。cpp“源文件
	2.将”.h“ 和 ”.cpp“ 合并为”.hpp“放到头文件夹内,调用”.hpp“文件。
*/


int main() {
	Person<string, int> p("张三", 20);
	p.show();
	return 0;
}
