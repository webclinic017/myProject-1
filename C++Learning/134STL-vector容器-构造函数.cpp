#include <iostream>
using namespace std;
#include <vector>
/*
vector 是个单端数组，只能前端是封闭的。
vector 的扩展是动态的：就是每次都会找一个新的空间复制值进去，然后释放原有空间
*/

void printVector(vector<int> vec) {
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
};



int main() {
	// 1.默认构造
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	};
	printVector(v1);

	// 2.区间赋值
	vector<int> v2(v1.begin()+1,v1.end()-1);
	printVector(v2);

	// 3.n个element构造
	vector<int> v3(5,1);
	printVector(v3);

	// 4.拷贝构造
	vector<int> v4(v3);
	printVector(v4);
	
	return 0;
}
