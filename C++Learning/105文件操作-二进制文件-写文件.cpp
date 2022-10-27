#include <iostream>
#include <fstream>

using namespace std;
/*
ostream& write(const char * buffer, int len)
参数解释:
	字符指针buffer指向内存中的一段存储空间
	len是读取的字符数
*/
class Person {
public:
	char name[64];
	string home;
	int age;
};



int main() {
	Person p = { "张三", "北京东城区交道口", 18};
	// 1. 包含头文件

	// 2. 创建输出流
	ofstream ofs;

	// 3. 打开文件
	ofs.open("./outputFiles/105.txt",ios::out|ios::binary);

	// 4. 写入数据
	ofs.write((const char * )&p, sizeof(p));
	
	// 5. 关闭文件
	ofs.close();
	
	return 0;
}
