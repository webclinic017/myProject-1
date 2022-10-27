#include <iostream>
using namespace std;
/*
对不同数据类型的数组进行选择排序。
*/

template<typename T>
void arrSort1(T &p, int len) {
	for (int i=0; i<len-1; i++) {
		for (int j=i+1; j<len; j++) {
			if (p[i] < p[j]) {
				T tmp; // 假设p是一个char数组的引用，T接收到的是一个char类型的指针，这里的temp也被T定义为一个char类型的指针。
				*tmp= p[i];
				p[i] = p[j];
				p[j] = *tmp;
			};
		};
	};
	for (int k=0; k<len; k++) {
		cout << p[k] << endl;
	}
}

// 写法二：
template<typename T>
void arrSort2(T p[], int len) {
	for (int i=0; i<len-1; i++) {
		for (int j=i+1; j<len; j++) {
			if (p[i] > p[j]) {
				T tmp[1]; // p直接传入数组，T接收到的是一个数组，这里的temp[1]也被T定义为一个数组。
				tmp[0]= p[i];
				p[i] = p[j];
				p[j] = tmp[0];
			};
		};
	};
	for (int k=0; k<len; k++) {
		cout << p[k] << endl;
	}
}

int main() {
	int arr1[] = {2,1,3};
	int len1 = sizeof(arr1)/sizeof(arr1[0]);
	arrSort1(arr1,len1);

	char arr2[] = "jfaeon";
	int len2 = sizeof(arr2)/sizeof(arr2[0]);
	arrSort2(arr2,len2);
	
	return 0;
}
