#include <iostream>
using namespace std;
#include <unistd.h> // sleep函数
#include "199globalFile.h"
#include <fstream>
#include "199person.h"
#include "199student.cpp"
#include "199teacher.cpp"
#include "199manager.cpp"
// #include "199orderFile.cpp"
/*

*/
// 学生子菜单
void studentMenu(Person * person) {
	while (true) {
		// 清屏
		system("clear");

		// 打开学生菜单
		person->openMenu(); // 父类指针指向子类对象实现多态

		// 强转父类指针为子类指针，以调用子类的成员函数
		Student * stu = (Student *)person;



		// 选择器变量
		int select = 0;
		cin >> select;
		switch (select) {
			case 1: // 申请预约
				stu->applyOrder();
				break;
			case 2: // 查看我的预约
				stu->showMyOrder();
				break;
			case 3: // 查看所有预约
				stu->showAllOrder();
				break;
			case 4: // 取消预约
				stu->cancelOrder();
				break;
			case 0: // 注销登录
				delete stu;
				cout << "注销成功" << endl;
				sleep(1.25);
				return;
			default:
				cout << "您输入的数字有误，请重新输入！" << endl;
				sleep(1.25);
		};
	};
};



// 教师子菜单
void teacherMenu(Person * person) {
	while (true) {
		// 清屏
		system("clear");

		// 打开老师菜单
		person->openMenu(); // 父类指针指向子类对象实现多态

		// 强转父类指针为子类指针，以调用子类的成员函数
		Teacher * tea = (Teacher *)person;



		// 选择器变量
		int select = 0;
		cin >> select;
		switch (select) {
			case 1: // 查看所有预约
				tea->showAllOrder();
				break;
			case 2: // 审核预约
				tea->validOrder();
				break;
			case 0: // 注销登录
				delete tea;
				cout << "注销成功" << endl;
				sleep(1.25);
				return;
			default:
				cout << "您输入的数字有误，请重新输入！" << endl;
				sleep(1.25);
		};
	};
};


// 管理员子菜单
void managerMenu(Person * person) {
	while (true) {
		// 清屏
		system("clear");

		// 打开管理员菜单
		person->openMenu(); // 父类指针指向子类对象实现多态

		// 强转父类指针为子类指针，以调用子类的成员函数
		Manager * man = (Manager *)person;

		// 选择器变量
		int select = 0;
		cin >> select;
		switch (select) {
			case 1: // 添加账号
				man->addPerson();
				break;
			case 2: // 查看账号
				man->showPerson();
				break;
			case 3: // 查看机房信息
				man->showComputer();
				break;
			case 4: // 清空预约
				man->clearFile();
				break;
			case 0: // 退出
				delete man;
				cout << "注销成功" << endl;
				sleep(1.25);
				return;
			default:
				cout << "您输入的数字有误，请重新输入！" << endl;
				sleep(1.25);
		};
	};
};


// 登录功能
void logIn(string filename) {
	//形参检查
	if (filename != STUDENT_FILE and filename != TEACHER_FILE and filename != ADMIN_FILE) {
		cout << "logIn()参数错误！可接受的参数为：“STUDENT_FILE”，“TEACHER_FILE”，“ADMIN_FILE”" << endl; 
		sleep(2);
		return;
	};

	// 打开文件
	fstream fs; fs.open(filename,ios::in);

	// 函数内参数初始化
	int id = 0;
	string name = "";
	string password = "";

	// 输入编号
	if (filename == STUDENT_FILE) {
		cout << "请输入学生学号：";
		cin >> id;
	}
	else if (filename == TEACHER_FILE) {
		cout << "请输入教师编号：";
		cin >> id;
	};
	// 输入姓名和密码
	cout << "请输入姓名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> password;

	// 创建Person类的指针，用作下面使用多态
	Person * ps;
	

	// 验证信息
	int f_id; string f_name; string f_password; // 变量：储存从文件中读取的账号密码信息
	if (filename == STUDENT_FILE) {
		// 学生登录验证
		while (fs >> f_id and fs >> f_name and fs >> f_password) {
			if (id == f_id and name == f_name and password == f_password) {
				cout << name << "同学你好，你的登录信息验证成功！" << endl;
				sleep(1);
				ps = new Student(id,name,password); // 多态: person的指针指向student的对象
				// 进入学生子菜单
				studentMenu(ps);
				return;
			};
		};
	}
	else if (filename == TEACHER_FILE) {
		// 老师登录验证
		while (fs >> f_id and fs >> f_name and fs >> f_password) {
			if (id == f_id and name == f_name and password == f_password) {
				cout << name << "老师您好，您的登录信息验证成功！" << endl;
				ps = new Teacher(id,name,password); // 多态: person的指针指向teacher的对象
				sleep(2);
				teacherMenu(ps);
				return;
			};
		};
	}
	else if (filename == ADMIN_FILE) {
		// 管理员登录验证
		while (fs >> f_name and fs >> f_password) {
			if (name == f_name and password == f_password) {
				cout << "敬爱的管理员" << name << "您好，您的登录信息验证成功！" << endl;
				sleep(1);
				ps = new Manager(name,password); // 多态: person的指针指向manager的对象
				// 进入管理员子菜单
				managerMenu(ps);
				return;
			};
		};
	};

	// 验证失败
 	cout << "验证登录失败!请检查用户名密码是否正确。" << endl;
	sleep(3);


};




int main() {
	while (true) {
		system("clear");
		cout << "================  欢迎来到传智播客机房预约系统  ================" << endl;
		cout << "\t\t| ---------------------------- |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          1.学生代表          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          2.老    师          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          3.管 理 员          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t|          0.退    出          |" << endl;
		cout << "\t\t|                              |" << endl;
		cout << "\t\t| ---------------------------- |" << endl;
		cout << "请输入您的选择：";
		int select;
		cin >> select;
		switch (select) {
			case 1:
				logIn(STUDENT_FILE);
				break;
			case 2:
				logIn(TEACHER_FILE);
				break;
			case 3:
				logIn(ADMIN_FILE);
				break;
			case 0:
				cout << "感谢使用，再见。" << endl;
				return 0;
			default:
				cout << "您输入的数字有误，请重新输入！" << endl;
				sleep(1.25);
		};
	};
	return 0;
}
