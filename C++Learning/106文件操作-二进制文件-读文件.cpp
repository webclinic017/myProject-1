#include <iostream>
#include <fstream>

using namespace std;
/*
istream& read(char * buffer, int len)
参数解释:
	字符指针buffer指向内存中的一段存储空间 （读给谁？）
	len是读取的字符数
*/

class Person {
public:
	char name[64];
	string home;
	int age;
};



int main() {
	Person p;
	// 1. 包含头文件

	// 2. 创建输入流
	ifstream ifs;

	// 3. 打开文件
	ifs.open("./outputFiles/105.txt",ios::in | ios::binary);
	if (!ifs.is_open()) {
		cout << "打开文件失败！" << endl;
		return -1;
	}
	else {cout << "打开文件成功！" << endl;};

	// 4. 读取数据
	ifs.read((char * )&p, sizeof(Person));
	cout << p.name << endl;
	cout << p.age << endl;
	cout << p.home << endl; // string 类型读写时容易出错，我们尽量别用。

	// 5. 关闭文件
	ifs.close();
	
	return 0;
}
