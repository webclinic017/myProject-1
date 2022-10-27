#include "199person.h"
#include <vector>
#include "199computer.h"
// #include "199teacher.h"
// #include "199student.h"
/*

*/
class Manager : public Person {
public:
	// 老师的容器，用来读取文件中的老师信息，用于对比编号是否重复
	vector<Teacher> v_teacher;

	// 学生的容器，用来读取文件中的学生信息，用于对比编号是否重复
	vector<Student> v_student;

	// 机房的容器，用来读取文件中的机房信息
	vector<Computer> v_computer;

public:
	// 默认构造
	Manager();

	// 有参构造
	Manager(string m_name, string m_password);

	// 显示菜单界面
	virtual void openMenu();

	// 添加账号
	void addPerson();

	// 查看账号
	void showPerson();

	// 查看挤信息
	void showComputer();

	// 清空预约
	void clearFile();

	// 初始化老师 & 学生容器
	void initVectors();

	// 初始化机房容器
	void initComputer();
};

