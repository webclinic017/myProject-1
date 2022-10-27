#include <iostream>
using namespace std;
#include <map>
/*

*/
void printMap(const map<int,string> &m) {
	cout << "map:" << endl;
	for (map<int,string>::const_iterator it = m.begin(); it != m.end(); it++) {
		cout << "序号：" << it->first << " 姓名：" << it->second << endl;
	};
	cout << endl;
};

int main() {
	map<int,string> m;
	// 插入方法1
	m.insert(pair<int,string>(1,"刘备"));
	// 插入方法2
	m.insert(make_pair(2,"关羽"));	
	// 插入方法3
	m.insert(map<int,string>::value_type(3,"张飞"));	
	// 插入方法4 不推荐
	m[4] = "赵云";
	cout << m[5] << endl; // 因为普通的调用一个不存在的key会被map创建出一个空值。
	printMap(m);

	// 删除1 传入迭代器
	m.erase(m.begin());
	printMap(m);

	// 删除2 传入迭代器区间
	map<int,string>::iterator it1 = m.begin();	it1++;
	map<int,string>::iterator it2 = m.end();	it2--;
	m.erase(it1,it2);
	printMap(m);
	
	// 删除3 传入key值
	m.erase(5);
	printMap(m);
	
	// 清空
	m.clear();
	printMap(m);
	return 0;
}
