#include <iostream>
using namespace std;
#include <stack>
/*
stack 栈 先进后出 栈底是封住的。栈顶可以出。
不允许遍历，因为只有栈顶元素能被访问。
*/

int main() {
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout << "栈的大小：" << s.size() << endl;
	while (!s.empty()) {
		cout << "栈顶元素为：" << s.top() << endl;
		s.pop();
	};
	cout << "栈的大小：" << s.size() << endl;


	
	return 0;
}
