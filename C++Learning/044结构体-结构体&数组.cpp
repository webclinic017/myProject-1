#include <iostream>
using namespace std;
/*
结构体数组：
struct student arr[] = {
	{...},
	{...},
	{...}
}
*/

int main() {
	// 步骤一：定义结构体
	struct student {
		string name;
		int age;
		int score;
	};

	// 步骤二：创建结构体数组
	student studArr[] {
		{"tom",10,65},
		{"jerry",13,77},
		{"mike",16,96}
	};

	// 修改结构体数组的值 (只能修改、不能添加)
	studArr[2].name = "jane";
	studArr[2].age = 18;
	studArr[2].score = 82;

	// 遍历打印结构体数组
	int len = sizeof(studArr)/sizeof(studArr[0]);
	for (int i = 0; i < len; i++) {
		cout << "姓名：" << studArr[i].name
			<< ", 年龄：" << studArr[i].age
			<< ", 分数：" << studArr[i].score << "。" << endl;
	};

	return 0;
}
