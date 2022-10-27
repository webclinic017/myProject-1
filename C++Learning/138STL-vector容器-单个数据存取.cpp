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
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	v[1] = 200;
	v.at(2) = 300;
	v.front() = 100;
	v.back() = 500;
	printVector(v);
	
	return 0;
}
