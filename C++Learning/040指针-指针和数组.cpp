#include <iostream>
using namespace std;
/*
利用指针来访问数组中的元素
*/

int main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int * p = arr;
	cout << "指针地址：" << p << endl;
	cout << "利用指针找第一个元素：" << *p << endl;
	cout << "利用指针找后续的元素：" << endl;
	for (int i = 0; i < 9; i++) {
		// 由于p本来就是int类型的指针，它每次++都会往后移动4个字节。
		cout << *++p << endl; 
		// 对应到后面那个元素所在的内存地址。
	}

	return 0;
}
