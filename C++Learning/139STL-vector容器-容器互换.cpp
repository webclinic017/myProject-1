#include <iostream>
using namespace std;
#include <vector>
/*

*/
void printVector(const vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	};
	cout << endl;
};


int main() {
	vector<int> v1;
	for (int i = 1; i <= 10; i++) {
		v1.push_back(i);
	};
	vector<int> v2;
	for (int i = 5; i >= 1; i--) {
		v2.push_back(i);
	};
	cout << "互换前：" << endl;
	printVector(v1);
	printVector(v2);

	v1.swap(v2);
	cout << "互换后：" << endl;
	printVector(v1);
	printVector(v2);

	cout << "实际的用途：巧用swap来清理内存空间" << endl;
	vector<int> v3;
	for (int i = 1; i <= 1000000; i++) {
		v3.push_back(i);
	};
	cout << "一开始：" << endl;
	cout << "size of v3 = " << v3.size() << endl;
	cout << "capacity of v3 = " << v3.capacity() << endl << endl;

	v3.resize(3);
	cout << "resize后：" << endl;
	cout << "size of v3 = " << v3.size() << endl;
	cout << "capacity of v3 = " << v3.capacity() << endl << endl;

	vector<int> (v3).swap(v3); // 用新的v3（size=3）做模板拷贝构造一个临时vector对象;再与v3交换内存地址，被交换的vector会被临时vector对象自动释放。
	cout << "swap后：" << endl;
	cout << "size of v3 = " << v3.size() << endl;
	cout << "capacity of v3 = " << v3.capacity() << endl << endl;

	return 0;
}
