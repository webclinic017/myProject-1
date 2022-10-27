#include <iostream>
using namespace std;
/*
switch、for、while、do...while都可以用break跳转
*/

int main() {
	// 1.swith跳转
	cout << "1、普通难度  2、中等难度  3、高难度" << endl;
	cout << "请选择游戏难度：";
	unsigned short select;
	cin >> select;
	switch (select) {
		case 1:
			cout << "您选择的是普通难度！" << endl;	break;
		case 2:
			cout << "您选择的是中等难度！" << endl;	break;
		case 3:
			cout << "您选择的是高难度！" << endl;	break;
		default:
			cout << "输入错误！" << endl;	break;
	}

	// 2.循环语句跳转
	for (unsigned int i = 0; i < 10; i++) {
		if (i == 5) {
			break;
		}
		cout << i << endl;
	}
	
	//3.嵌套循环语句
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) {break;} // break 只会跳出一层循环
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}
