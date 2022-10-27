#include <iostream>
using namespace std;
/*
结构体做函数参数
值传递
地址传递
*/
struct student {
	string name;
	int age;
	int score;
};

void printstudent(struct student c) {
	c.age = 100;   // 不改变实参
	cout << "printstudent():" << "姓名：" << c.name  << endl;
	cout << "printstudent():" << "年龄：" << c.age   << endl;
	cout << "printstudent():" << "分数：" << c.score << endl;
};

void print_student2 (struct student * p) {
	p -> age = 200; // 改变实参
	cout << "print_student2():" << "姓名：" << p -> name  << endl;
	cout << "print_student2():" << "年龄：" << p -> age   << endl;
	cout << "print_student2():" << "分数：" << p -> score << endl;
};


int main() {

	student s = {"tom", 20, 85};

	print_student2(&s);
	printstudent(s);	

	cout << "main():" << "姓名：" << s.name  << endl;
	cout << "main():" << "年龄：" << s.age   << endl;
	cout << "main():" << "分数：" << s.score << endl;
	
	return 0;
}
