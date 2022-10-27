#include <iostream>
using namespace std;
/*
跳过所在循环语句中未执行的部分，继续下一次循环。
*/

int main() {
	for (int i = 0; i < 100; i++) {
		if (i % 2 == 0) {
			continue; // 执行到此就不在往下执行了，继续下一次循环。
		}
		cout << i << endl;
	}
	
	return 0;
}
