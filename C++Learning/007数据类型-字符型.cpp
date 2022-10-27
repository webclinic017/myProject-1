#include <iostream>
using namespace std;
/*
字符型变量只表示单个字符
用单引号表示
''内只能有一个字符
一个字符型只占用1个byte
*/

int main() {
	//创建
	char chr = 'b';
	cout << "chr=" << chr << endl;
	//内存大小
	cout << "sizeof(chr)=" << sizeof(chr) << endl;
	
	// 错误1 char chr2 = "b";
	// 错误2 char chr3 = 'abcde';

	// 打印ASCII码值 (字符型可以转变为int型)
	cout << "b的ASCII码：" << (int)chr << endl;
	return 0;
}
