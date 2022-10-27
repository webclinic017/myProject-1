#include <iostream>
using namespace std;
#include <vector>
/*

*/

int main() {
	vector<vector<int>> v;
	vector<int> v1; vector<int> v2; vector<int> v3; vector<int> v4;
	for (int i = 1; i <= 4; i++) {
		v1.push_back(i);
		v2.push_back(10+i);
		v3.push_back(20+i);
		v4.push_back(30+i);
	};
	v.push_back(v1); v.push_back(v2); v.push_back(v3); v.push_back(v4);

	// 遍历
	for (vector<vector<int>>::iterator i = v.begin(); i < v.end(); i++) {
		for (vector<int>::iterator j = (*i).begin(); j < (*i).end(); j++) { // (*i)==> v1、v2、v3、v4
			cout << *j << " ";
		};
		cout << endl;
	};

	
	return 0;
}
