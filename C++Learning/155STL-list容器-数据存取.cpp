#include <iostream>
using namespace std;
#include <list>
#include <vector>
/*
list不支持 [] 和 at() 的访问方式。
	因为list是链表的形式，它的迭代器不支持随机访问。
	只有front(),end()两种数据访问方式
*/

int main() {
	list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_back(50);

	cout << "front = " << l.front() << endl;
	cout << "back = " << l.back() << endl;


	// 如何验证迭代器支不支持随机访问
	list<int>::iterator it = l.begin();
	it++;
	// it = it + 1; // error: no match for ‘operator+’ 不支持随机访问
	// it = it + 3; // error: no match for ‘operator+’ 不支持随机访问
	vector<int> v(3,10);
	vector<int>::iterator vit = v.begin();
	vit++;
	vit = vit + 1; // 支持随机访问
	vit = vit + 3; // 支持随机访问



	

	
	return 0;
}
