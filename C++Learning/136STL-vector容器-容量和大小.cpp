#include <iostream>
using namespace std;
#include <vector>
/*

*/
void printVector(const vector<double> vec) {
	for (vector<double>::const_iterator it = vec.begin(); it != vec.end(); it++ ) {
		cout << *it << " ";
	};
	cout << endl;
};

int main() {
	vector<double> v;
	cout << v.empty() << endl << endl;

	for (double i = 1.01; i < 11; i++) {
		v.push_back(i);
	};
	cout << v.empty() << endl;
	cout << "size(数字多少) = " << v.size() << endl;
	cout << "capacity(最多可容纳-超过的话自己会扩展) = " << v.capacity() << endl << endl;

	v.resize(15);
	printVector(v);

	v.resize(10);
	v.resize(15,9.99);
	printVector(v);
	
	return 0;
}
