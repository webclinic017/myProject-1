#include <iostream>
using namespace std;
/*
结构体 == “用户自定义的数据类型”
允许用户存储不同的数据类型

语法：
struct 结构体名 {结构体成员列表};
*/

/*

2.
*/

int main() {
	// 1.创建“学生”数据类型：包括（姓名、年龄、分数、身高）
	struct student {
		string 	name;
		int 	age;
		int		score;
		float	height;
	} s3;
	// 2.创建具体的“学生”
		// 2.1 方法1
		struct student s1; // 这里的struct 关键字可以不写
		s1.name = "张坤";
		s1.age = 28;
		s1.height = 176.3;
		s1.score = 506;
		cout << "姓名：" << s1.name << "，年龄：" << s1.age << "，分数：" << s1.score << "，身高：" << s1.height << endl;
		
		// 2.2 方法2
		student s2 = {"葛亮",25,632,177.1}; // 这里的struct 关键字可以不写
		cout << "姓名：" << s2.name << "，年龄：" << s2.age << "，分数：" << s2.score << "，身高：" << s2.height << endl;
		
		// 2.3 方法3
		// struct student {......} s3;
		s3.name = "时光";
		s3.age = 19;
		s3.height = 171.2;
		s3.score = 698;
		cout << "姓名：" << s3.name << "，年龄：" << s3.age << "，分数：" << s3.score << "，身高：" << s3.height << endl;
		
	return 0;
}
