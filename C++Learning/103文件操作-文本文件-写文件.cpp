#include <iostream>
#include <fstream> // 读写文件
// #include <ofstream> // 写文件
// #include <ifstream> // 读文件

using namespace std;
/*

*/

int main() {
	// 1.包含头文件

	// 2.创建文件流对象
	fstream fs;

	// 3.打开文件
	fs.open("./outputFiles/103.txt",ios::out);

	// 4.写入数据
	fs << "姓名：张三。" << endl;
	fs << "年龄：18。" << endl;
	
	// 5.关闭文件
	fs.close();
	
	return 0;
}
