#include <iostream>
using namespace std;
/*
int arr[] = {4,3,6,9,1,2,10,8,5,7};
封装一个函数，利用指针形式的形参，对数组实现冒泡排序。
*/


void bubbleSort(int * p, int lengthOfArray) {
	/*
	参数1：数组的地址指针
	参数2：数组的长度
	*/
	for (int i = 0; i < lengthOfArray; i++) {
		//1.用一个零时指针q,每次循环重置指针到p的初始位置。
		int * q = p;
		//2.数组长度为10，比较次数为9次不是10次。
		//3.每一次排序，最后一位变为最大，所以排序次数减一。
		for (int j = 0; j < lengthOfArray - 1 - i; j++) {
			if (*q > *(q+1)) {
				int tmp = *q;
				*q = *(q+1);
				*(q+1) = tmp;
			}
			q++; //4.这个++必须写在if外面。
		}
	}

}

int main() {
	int arr[] = {4,3,6,9,1,2,10,8,5,7};
	int len = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,len); // arr本身就是一个指针，即一个内存地址。
	for (int k = 0; k < 10; k++) {
		cout << arr[k] << endl;
	}
	return 0;
}
