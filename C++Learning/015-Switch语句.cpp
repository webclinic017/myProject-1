#include <iostream>
using namespace std;
/*
switch 缺点：分支判断时只能是整型和字符型，不能是整型区间（如5<x<9）。
switch 优点：执行效率比if...else...高
switch 分支需要添加break。
*/

int main() {
	unsigned short score;
	cout << "请给你刚看的这部电影打分:";
	cin >> score;
	cout << "您给的分数为：" << score << endl << endl;
	
	switch (score) {
		case 10:	cout << "你认为是经典" << endl;		break;
		case 9:		cout << "你认为是经典" << endl;		break;
		case 8:		cout << "你认为是非常好" << endl;	break;
		case 7:		cout << "你认为是非常好" << endl;	break;
		case 6:		cout << "你认为是一般" << endl;		break;
		case 5:		cout << "你认为是一般" << endl;		break;
		default:	cout << "你认为是烂片" << endl;		break;
	}
	return 0;
}
