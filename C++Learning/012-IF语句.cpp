#include <iostream>
using namespace std;
/*
if (条件) {执行语句}
*/

int main() {
	int score = 0;
	cout << "请输入你的高考分数：";
	cin >> score;

	cout << "一本的分数线为：600分。" << endl;
	cout << "二本的分数线为：500分。" << endl;
	cout << "三本的分数线为：400分。" << endl;
	cout << "你的分数为：" << score << "分。" << endl;

	// 注意事项： if (条件) 后面不用加“;”
	if (score >= 600) {
		cout << "恭喜您考上一本大学！" << endl;
		if (score >= 700) {
			cout << "你的分数够上清北！" << endl;
		}
		else if (score >= 670) {
			cout << "你的分数够上复交！" << endl;
		}
		else if (score >= 640) {
			cout << "你的分数够上985！" << endl;
		}
		else {
			cout << "你考取的是一所普通的一本大学" << endl;
		};
	}
	else if (score >= 500) {
		cout << "恭喜您考上二本大学！" << endl;
	}
	else if (score >= 400) {
		cout << "恭喜您考上三本大学！" << endl;
	}
	else {
		cout << "很遗憾，您未考上本科。。。" << endl;
	}

	return 0;
}
