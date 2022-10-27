#include <iostream>
using namespace std;
/*

*/

int main() {
	string str = "hello";
	cout << "字符串长度：" << str.size() << endl;
	for (int i = 0; i < str.size(); i++) {
		cout << str[i] << " ";
	};
	cout << endl;

	for (int i = 0; i < str.size(); i++) {
		cout << str.at(i) << " ";
	};
	cout << endl;

	str[0] = 'F';
	str.at(4) = 'W'; 
	cout << "修改后的字符串" << str << endl;

	return 0;
}
