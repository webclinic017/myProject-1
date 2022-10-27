#include <iostream>
using namespace std;
/*
二维数组的定义方式
数据类型 数组名[行数][列数]
数据类型 数组名[行数][列数] = {{数据1，数据2},{数据3，数据4}}
数据类型 数组名[行数][列数] = {数据1，数据2 , 数据3，数据4}
数据类型 数组名[   ][列数] = {数据1，数据2 , 数据3，数据4}
*/

int main() {
	int arr1[][3] = {{1,2,3},{4,5,6}};

	double arr2[][6] = {1,2,3,4,5,6,7};

	cout << "arr1[0][0]: " << arr1[0][0] << endl << endl;

	cout << "arr2[][]: " << endl;
	for (int i=0; i < 2; i++) {
		for (int j=0; j < 6; j++){
			cout << arr2[i][j] << " ";
		}
		cout << endl;
	}

	//二维数组的内存占用大小
	cout << "sizeof arr1: " << sizeof(arr1) << endl;
	cout << "sizeof arr1[0][0]: " << sizeof(arr1[0][0]) << endl;
	cout << "len of arr1: " << sizeof(arr1)/sizeof(arr1[0][0]) << endl << endl;

	cout << "sizeof arr2: " << sizeof(arr2) << endl;
	cout << "sizeof arr2[0][0]: " << sizeof(arr2[0][0]) << endl;
	cout << "len of arr2: " << sizeof(arr2)/sizeof(arr2[0][0]) << endl;

	//二维数组 的 内存中的首地址
	cout << "arr1地址：" 			<< (int)arr1 		<<endl;
	cout << "arr1[0]地址：" 		<< (int)arr1[0] 	<<endl;
	cout << "arr1[1]地址：" 		<< (int)arr1[1] 	<<endl;
	cout << "arr1[0][0]地址：" 		<< (int)&arr1[0][0] <<endl;
	cout << "arr1[0][1]地址：" 		<< (int)&arr1[0][1] <<endl;
	
	return 0;
}
