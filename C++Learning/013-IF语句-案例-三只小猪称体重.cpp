#include <iostream>
using namespace std;
/*

*/

int main() {
	float peiqi = 0.0f;
	float lali = 0.0f;
	float huahua = 0.0f;
	cout << "请输入小猪佩奇的体重：";
	cin >> peiqi;
	cout << "请输入小猪拉里的体重：";
	cin >> lali;
	cout << "请输入小猪花花的体重：";
	cin >> huahua;
	cout << "佩奇、拉里、花花的体重分别为：" << peiqi << "kg， " << lali << "kg， " << huahua << "kg。" << endl;

	if (peiqi > lali) {
		if (peiqi > huahua) {
			cout << "佩奇最重" << endl;
		}
		else if (peiqi < huahua) {
			cout << "花花最重" << endl;
		}
		else {
			cout << "佩奇、花花最重" << endl;
		}
	}
	else if (peiqi < lali) {
		if (lali > huahua) {
			cout << "拉里最重" << endl;
		}
		else if (lali < huahua) {
			cout << "花花最重" << endl;
		}
		else {
			cout << "拉里、花花最重" << endl;
		}
	}
	else {
		if (peiqi > huahua) {
			cout << "佩奇、拉里最重" << endl;
		}
		else if (peiqi < huahua) {
			cout << "花花最重" << endl;
		}
		else {
			cout << "佩奇、拉里、花花一样重" << endl;
		}
	}
	
	return 0;
}
