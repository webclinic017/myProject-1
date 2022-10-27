#include <iostream>
using namespace std;
/*
string类的构造函数
	1. string(); 默认
	2. string(const char * s) 用c风格的字符串拷贝构造
	3. string(const string & s) 用string自己的实例对象拷贝构造
	4. string(int n, char c) 用n个char字符构造自己
*/
int main() {
	string s1;

	const char * str = "nihao";
	string s2(str);
	cout << "s2 = " << s2 << endl;

	string s3(s2);
	cout << "s3 = " << s3 << endl;

	string s4(5, 'a');
	cout << "s4 = " << s4 << endl;
	return 0;
}
