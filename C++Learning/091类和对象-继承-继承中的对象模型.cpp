#include <iostream>
using namespace std;
/*
如何利用 “开发人员命令提示工具” 查看对象的模型：
1. 打开 visual studio 的 开发人员命令提示工具。
2. cd到 *.cpp 文件的路径。
3. 命令：cl /d1 reportSingleClassLayout类名 cpp文件名
*/

class Father {
private:
	int a;
	int b;
	int c;
};

class Son : public Father {
public:
	int d;
};

int main() {
	Father f;
	cout << "sizeof(father) = " << sizeof(f) << endl;

	Son s;
	cout << "sizeof(son) = " << sizeof(s) << endl;
	// 结果说明：就算是父类的私有属性，其实也被子类继承下来了。只不过被编译器隐藏了，处于不能访问的状态。
	return 0;
}
