#include <iostream>
using namespace std;
#include <vector>
#include <map>
/*
公司招聘了10个员工ABCDEFGHIJ,员工信息有：姓名，工资
公司有三个部门：策划 美术 研发
随机给10名员工分配部门和工资
分部门显示员工信息

实现：
	1.创建10名员工 放在vector容器中
	2.遍历vector取出10名员工,随机分配部门和薪水
	3.将部门编号作为key,员工信息作为value放在multimap容器中
	4.遍历multimap分部门显示员工信息
*/
class Employee {
public:
	string name;
	float salary;
	Employee(string name) {
		this->name = name;
		this->salary = rand()%10000 + 10000; // 10000~19999
	};
};

// class myRule {
// public:
// 	bool operator()(const Employee &e1, const Employee &e2) {
// 		return e1.salary > e2.salary;
// 	};
// };


int main() {
	// 1.创建员工
	vector<Employee> ev;
	ev.push_back(Employee("A"));
	ev.push_back(Employee("B"));
	ev.push_back(Employee("C"));
	ev.push_back(Employee("D"));
	ev.push_back(Employee("E"));
	ev.push_back(Employee("F"));
	ev.push_back(Employee("G"));
	ev.push_back(Employee("H"));
	ev.push_back(Employee("I"));
	ev.push_back(Employee("J"));
	// 1.01 测试
	// for (vector<Employee>::iterator it = ev.begin(); it != ev.end(); it++) {
	// 	cout << "测试：姓名：" << it->name << " 薪水：" << it->salary << endl;
	// };

	// 2.创建部门
	map<int,string> dpt; // department
	dpt.insert(make_pair(1,"策划"));
	dpt.insert(make_pair(2,"美术"));
	dpt.insert(make_pair(3,"研发"));

	// 3.员工分组
	multimap<int,Employee> emp_list;
	while (!ev.empty()) {
		int depId = rand() % 3 + 1; // 1,2,3
		emp_list.insert(make_pair(depId,ev.back()));
		ev.pop_back();
	};

	// 4.显示员工信息
	for (multimap<int,Employee>::iterator it = emp_list.begin(); it != emp_list.end(); it++) {
		cout << "部门：" << dpt[it->first] << " 员工姓名：" << it->second.name << " 员工薪水：" << it->second.salary << endl; 
	};
	
	// 5.统计具体人数
	cout << "策划部门人数：" << emp_list.count(1) << endl;
	cout << "美术部门人数：" << emp_list.count(2) << endl;
	cout << "研发部门人数：" << emp_list.count(3) << endl;

	return 0;
}
