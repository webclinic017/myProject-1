#include <iostream>
using namespace std;
/*

*/

int main() {
	// 1.string& operator=(const char * c)		赋值c风格字符串
	string s1;
	s1 = "hello world"; cout << "s1 = " << s1 << endl;

	// 2.string& operator=(const string & s)	赋值c++风格字符串
	string s2;
	s2 = s1; cout << "s2 = " << s2 << endl;

	// 3.string& operator=(char c)				赋值一个字符
	string s3;
	s3 = "h"; cout << "s3 = " << s3 << endl;

	// 4，string& assign(const char * c)		赋值c风格字符串
	string s4;
	s4.assign("hello C++"); cout << "s4 = " << s4 << endl;

	// 5.string& assign(const char * c, int n)	赋值c风格字符串前n个字符
	string s5;
	s5.assign("hello C++", 8); cout << "s5 = " << s5 << endl;

	// 6.string& assign(const string & s)		赋值c++风格字符串
	string s6;
	s6.assign(s4); cout << "s6 = " << s6 << endl;

	// 7.string& assign(int n, char c)			赋值n个c字符
	string s7;
	s7.assign(10,'w'); cout << "s7 = " << s7 << endl;
	
	return 0;
}
