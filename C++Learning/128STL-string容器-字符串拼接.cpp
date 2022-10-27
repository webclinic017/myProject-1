#include <iostream>
using namespace std;
/*

*/

int main() {
	string s0 = "虚空";
	// 1.string& operator+=(const char * c)		拼接c风格字符串
	s0+="行者";
	cout << "s0 = " << s0 << endl;

	// 2.string& operator+=(const string & s)	拼接c++风格字符串
	s0+=s0;
	cout << "s0 = " << s0 << endl;

	// 3.string& operator+=(const char c)		拼接一个字符
	s0+='-';
	cout << "s0 = " << s0 << endl;

	// 4，string& append(const char * c)		拼接c风格字符串
	s0.append("恐惧");
	cout << "s0 = " << s0 << endl;

	// 5.string& append(const char * c, int n)	拼接c风格字符串前n个字符
	s0.append("hello",4);
	cout << "s0 = " << s0 << endl;

	// 6.string& append(const string & s)		拼接c++风格字符串
	s0.append(s0);
	cout << "s0 = " << s0 << endl;

	// 7.string& append(onst string & str, int pos, char n)			
	// 从pos开始拼接n个str中的字符到末尾
	s0.append(s0,12,2);
	cout << "s0 = " << s0 << endl;
	
	return 0;
}
