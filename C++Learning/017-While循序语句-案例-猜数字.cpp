#include <iostream>
using namespace std;
/*
1.系统生成一个1-100的随机数
2.用户输入
3.系统比对，告诉用户大了小了
4.继续猜
5.直到猜对了
*/

#include <stdlib.h>
#include <ctime>

int main() {
	// 1.生成随机数种子
	srand( (unsigned int)time(NULL) );			//from stdlib.h、ctime
	// 2.生成一个0-99的随机数 + 1。如果不用种子，这个数字windows下一直是42
	unsigned short randNum = rand() % 100 + 1;
	// 3.接收输入的数字
	unsigned short num;
	cout << "请输入一个0-100的数:";
	cin >> num;
	// 4.while 比对
	while (num != randNum) {
		num > randNum 
			? 
			cout << "你的数给大了。" << endl 
			: 
			cout << "你的数给小了。" << endl;
		cout << "请输入一个0-100的数:";
		cin >> num;
	}
	// 5.返回结果
	cout << "你猜对了！数字就是：" << randNum << endl; 
	return 0;
}
