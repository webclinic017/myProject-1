#include <iostream>
using namespace std;
/*
冒泡排序：4,2,8,0,5,7,1,3,9
1、对比 4,2 把大的数字交换到后面
2、一轮结束后，最后面一定是最大的数字
3、执行9-1轮就排序完成了
*/

int main() {
	int arr[] = {4,2,8,0,5,7,1,9,3,6};
	
	int tmp;
	int num = sizeof(arr)/sizeof(arr[0]) - 1;
	for (int times = 0; times < num; times++) {
		for (int i = 0; i < num; i++) {
			if (arr[i] > arr[i+1]) {
				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
	}

	
	for (int j = 0; j <= num; j++) {
		cout << arr[j] << " ";
	}
	cout << endl;
	return 0;
}
