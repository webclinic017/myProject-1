#include <iostream>
using namespace std;
/*

*/

struct student {
	string name;
	int age;
};

struct teacher {
	string name;
	struct student stu[5];
};

int main() {
	student s1 = {"tom",28};
	student s2 = {"jerry",28};
	student s3 = {"mike",28};
	student s4 = {"tim",28};
	student s5 = {"scort",28};

	student s6 = {"jone",28};
	student s7 = {"jenny",28};
	student s8 = {"eda",28};
	student s9 = {"lilly",28};
	student s10 = {"linda",28};

	student s11 = {"michel",28};
	student s12 = {"jeffny",28};
	student s13 = {"jack",28};
	student s14 = {"shawn",28};
	student s15 = {"tonny",28};

	teacher teacher_array[3] ={ {"Mr.Wang",{s1,s2,s3,s4,s5}}, {"Mr.Tang",{s6,s7,s8,s9,s10}}, {"Mr.Huang",{s11,s12,s13,s14,s15}}};

	for (int i = 0; i < 3; i++) {
		cout << "老师：" << teacher_array[i].name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "	学生：" << teacher_array[i].stu[j].name;
			cout << "	年龄：" << teacher_array[i].stu[j].age << endl;
		};
		cout << "===============================================" << endl;
	};

	return 0;
}
