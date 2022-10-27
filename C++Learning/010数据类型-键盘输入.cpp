#include <iostream>
using namespace std;
/*

*/

int main() {
	//1整型
	int sht;
	cout << "请输入整型变量 "<< endl;
	cin >> sht;
	cout << "整型变量sht:"<<sht << endl<<endl;

	//2浮点型
	float flt;
	cout << "请输入浮点型变量 "<< endl;
	cin >> flt;
	cout << "浮点型变量flt:"<<flt << endl<<endl;

	//3字符型
	char chr;
	cout << "请输入字符型变量 "<< endl;
	cin >> chr;
	cout << "字符型变量chr:"<< chr << endl<<endl;

	//4字符串型
	string stg;
	cout << "请输入字符串变量 "<< endl;
	cin >> stg;
	cout << "字符串型变量stg:"<< stg << endl<<endl;

	//5布尔型
	bool bol = false;
	cout << "请输入布尔型变量 "<< endl;
	cin >> bol; //只要输入不是0，都转变为1
	cout << "布尔型变量bol:"<< bol << endl<<endl;

	
	
	return 0;
}
