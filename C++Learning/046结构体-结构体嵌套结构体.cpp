#include <iostream>
using namespace std;
/*
结构体嵌套结构体：
结构体中的某个成员是另一个结构体。
老师1对1辅导学生，一个老师的结构体中记录一个学生的结构体。
*/

int main() {
	struct student {
		string name;
		int age;
	};

	struct teacher {
		string name;
		int age;
		struct student stu;
	};


	student s1 = {"xiao ming", 16};
	teacher t1 = {"Miss.Wang",		29,		s1				};
	teacher t2 = {"Miss.Huang",		31, 	{"xiao xu", 17}	};
	teacher t3;
	t3.name = "Mr.Yang";
	t3.age = 35;
	t3.stu.name = "xiao chen";
	t3.stu.age = 18;

	cout << "老师2---姓名：" << t2.name << "  年龄：" << t2.age 
		<< " 带学生的姓名：" << t2.stu.name
		<< " 带学生的年龄：" << t2.stu.age << endl;
	return 0;
}
