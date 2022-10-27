#include <iostream>
using namespace std;
#include <vector>
/*
vector 赋值
*/

void printVector(vector<int> &vec) {
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++ ) {
		cout << *it << " ";
	};
	cout << endl;
};
int main() {
	// 1.赋值n个element
	vector<int> v1;
	v1.assign(5,1);
	printVector(v1);
	
	// 2.将第二个vector中的[a,b)赋值给自己
	vector<int> v2;
	v2.assign(v1.begin()+1, v1.end()-1);
	printVector(v2);

	// 3.等号赋值法
	vector<int> v3;
	v3 = v2;
	printVector(v3);
	return 0;
}
