#include <iostream>
#include <fstream>
using namespace std;
/*

*/

int main() {
	//1.包含头文件

	//2.创建流对象
	fstream fs;

	//3.打开文件
	fs.open("./outputFiles/103.txt",ios::in);

	//4.判断文件是否打开
	if ( !fs.is_open()) {
		cout << "打开文件失败！" << endl;
	}
	else {
		cout << "打开文件成功！" << endl;
	};

	//5.读文件
		//5.1 方法一
		// char buf[2155] = {0}; //创建一个x字节的字符数组，把它置零。
		// while (fs >> buf) {
		// 	cout << buf << endl;
		// };

		//5.2 方法二
		// char buf[1908] = {0};
		// while (fs.getline(buf,sizeof(buf))) {
		// 	cout << buf << endl;
		// };

		//5.3 方法三
		string str;
		while ( getline(fs,str) ) {
			cout << str << endl;
		};

		//5.4 方法四
		// char c;
		// while ( (c = fs.get()) != EOF ) {
		// 	cout << c;
		// };

	//6.关闭
	fs.close();
	
	return 0;
}
