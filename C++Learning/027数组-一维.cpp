#include <iostream>
using namespace std;
/*
特点：
1.数组中都是相同的数据类型
2.占用的是连续的内存空间
*/

int main() {
	//数组 的定义方式
	int		array1[3];
	short	array2[3] = {1, 2}; // 会用0补齐不全的数组
	float	array3[]  = {1.01, 2.02, 3.03};

	cout << "未赋值的数组1：" << array1[0] << "\t" << array1[1] << "\t" << array1[2] << endl;
	array1[0] = 10; array1[1] =  20; array1[2] = 30;
	cout << "已赋值的数组1：" << array1[0] << "\t" << array1[1] << "\t" << array1[2] << endl << endl;
	cout << "数组2：" 		 << array2[0] << "\t" << array2[1] << "\t" << array2[2] << endl << endl;
	cout << "数组3：" << array3[0] << "\t" << array3[1] << "\t" << array3[2] << endl << endl;
	
	// 数组 在内存中的长度
	int array4[] = {1,2,3,4,5};
	cout << "数组 在内存中的长度  "			<< sizeof(array4) << endl;
	cout << "数组[元素0] 在内存中的长度  "	<< sizeof(array4[0]) << endl;
	cout << "数组的元素个数为： " 			<< sizeof(array4)/sizeof(array4[0]) << endl << endl;

	// 数组 在内存中的首地址
	cout << "数组 首地址：" 		<< (long long)array4 << endl;
	cout << "数组 第一个元素地址："  << (long long)&array4[0] << endl;
	cout << "数组 第二个元素地址："  << (long long)&array4[1] << endl;
	
	// 注意：数组名是一个常量，不可以进行赋值操作
	return 0;
}
