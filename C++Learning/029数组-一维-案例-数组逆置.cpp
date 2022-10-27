#include <iostream>
using namespace std;

/*
数组逆置：int arr = {1,3,2,5,4}; -> int arr = {4,5,2,3,1};
*/


int main() {
	int arr[] = {1,3,2,5,4};
	int start = 0;
	int end = sizeof(arr)/sizeof(arr[0]) - 1;
	int tmp;

	for (;start < end;) {
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}

	cout << "数组逆置后：";
	for (int i = 0; i <= sizeof(arr)/sizeof(arr[0]) - 1; i++) {
		cout << arr[i];
	}
	cout << endl;
	
	return 0;

}
