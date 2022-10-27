#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <ctime>
/*
random_shuffle：洗牌算法
*/
void myPrint(int num) {
	cout << num << " ";
};

int main() {
	vector<int> v;
	for (int i = 1; i <= 10; i++) {
		v.push_back(i);
	};
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	// 创建随机数种子
	srand( (unsigned int)time(NULL) );

	// 洗牌后
	random_shuffle(v.begin(),v.end());
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;
	return 0;
}
