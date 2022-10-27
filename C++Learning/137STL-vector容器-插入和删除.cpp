#include <iostream>
using namespace std;
#include <vector>
/*

*/
void printVector(const vector<int> &vec) {
	for (vector<int>::const_iterator it = vec.begin(); it < vec.end(); it++) {
		cout << *it << " ";
	};
	cout << endl;
};

int main() {
	vector<int> v;
	
	// 1.尾插
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	// 2.尾删
	v.pop_back();
	printVector(v);

	// 3.插入
	v.insert(v.begin()+1,11);
	printVector(v);

	v.insert(v.begin(),2,5);
	printVector(v);

	// 4.删除
	v.erase(v.begin()+2);
	printVector(v);

	v.erase(v.begin()+1,v.end()-1);
	printVector(v);

	// 5.清空
	v.clear();
	printVector(v);
	
	return 0;
}
