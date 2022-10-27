#include "107staffManager.h"
#include "107employee.cpp"
#include "107boss.cpp"
#include "107manager.cpp"
#include <fstream>
#define FILENAME "./outputFiles/staffInfo.txt"

StaffManager::StaffManager() {
	// this->staffNum = 0;
	// this->staffArr = NULL;
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		ifs.close();
		this->staffNum = 0;
		this->staffArr = NULL;
		this->FileHasInfo = false;
		// return;
	}
	else if (ifs.get() == EOF) {
		cout << "文件为空" << endl;
		ifs.close();
		this->staffNum = 0;
		this->staffArr = NULL;
		this->FileHasInfo = false;
		// return;
	}
	else {
		cout << "文件存在且有数据" << endl;
		this->readFile(FILENAME);
	};
	cout << "StaffManager的构造函数" << endl;
};

StaffManager::~StaffManager() {
	if (this->staffArr != NULL) {
		for (int i=0; i<this->staffNum; i++) {
			delete this->staffArr[i];
		}
		delete [] this->staffArr;
		this->staffArr = NULL;
	};
	cout << "StaffManager的析构函数" << endl;
};

void StaffManager::showMenu() {
	cout << "******************************************" << endl;
	cout << "***********  欢迎使用职工管理系统！ **********" << endl;
	cout << "************** 0.退出管理程序 **************" << endl;
	cout << "************** 1.添加职工信息 **************" << endl;
	cout << "************** 2.显示职工信息 **************" << endl;
	cout << "************** 3.删除离职职工 **************" << endl;
	cout << "************** 4.修改职工信息 **************" << endl;
	cout << "************** 5.查找职工信息 **************" << endl;
	cout << "************** 6.职工编号排序 **************" << endl;
	cout << "************** 7.清空所有文档 **************" << endl;
};

void StaffManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	exit(0);
};

void StaffManager::saveFile(string path) {
	ofstream ofs;
	ofs.open(path,ios::out);
	if (!ofs.is_open()) {cout << "文件打开失败" << endl;}
	else {
		for (int i = 0; i < this->staffNum; i++) {
			ofs << this->staffArr[i]->id << " " 
			<< this->staffArr[i]->name << " "
			<< this->staffArr[i]->department_id << endl;
		};
		cout << "文件写入成功！" << endl;
	};
	ofs.close();
};

void StaffManager::readFile(string path) {
	// 统计文件数据行数
	int count = 0;
	ifstream ifs;
	ifs.open(path,ios::in);
	int r_id; string r_name; int r_departmentID;
	while (ifs >> r_id and ifs >> r_name and ifs >> r_departmentID) {count++;};
	ifs.close();

	// 开辟新空间 指向Worker ** 指针
	Worker ** tmpArr = new Worker*[count];
	ifs.open(path,ios::in);
	r_id = 0; r_name = ""; r_departmentID = 0;
	Worker * wk = NULL;
	for (int i=0; i<count; i++) {
		ifs >> r_id && ifs >> r_name && ifs >> r_departmentID;
		switch (r_departmentID) {
			case 1:
				wk = new Employee(r_id, r_name, r_departmentID);
				break;
			case 2:
				wk = new Manager(r_id, r_name, r_departmentID);
				break;
			case 3:
				wk = new Boss(r_id, r_name, r_departmentID);
				break;
		};
		tmpArr[i] = wk;
	};
	ifs.close();
	this->staffNum = count;
	this->staffArr = tmpArr;
	this->FileHasInfo = true;
	// delete tmpArr; // 巨坑，不能释放
	// tmpArr = NULL;
};

void StaffManager::addStaff() {
	// 添加数
	int addNum = 0;
	cout << "请输入须要添加几名员工：";
	cin >> addNum;
	if (addNum < 1) {cout<<"输入数字错误！"<<endl;return;};

	// 新的总人数
	int newNum = this->staffNum + addNum;

	// 开辟新空间 (每个数据都是Worker*, 一共newNum个数据)
	Worker ** newStaffArr = new Worker*[newNum];

	// 转移旧数组中的数据
	if (this->staffArr != NULL) {
		for (int i=0; i < this->staffNum; i++) {
			newStaffArr[i] = this->staffArr[i];
		};
	};

	// 添加手工输入的新数据
	int input_id = 0; string input_name = ""; int input_departmentId = 0;
	
	for (int j=0; j < addNum; j++) {
		input_id = 0; input_name = ""; input_departmentId = 0;
		cout << "请输入第 " << j << " 个员工的信息" << endl;
		

		// 部门编号
		cout << "-选择员工的类别-" << endl;
		cout << "1.普通员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		do{
			cout << "请选择：";
			cin >> input_departmentId;
		}
		while (!(input_departmentId==1|input_departmentId==2|input_departmentId==3));
		
		// 职工编号
		do {
			cout << "请输入职工编号：";
			cin >> input_id;
			if (this->findStaffIdx(input_id) == -1) {
				break;
			}
			else {
				cout << "存在该编号的员工" << endl;
			};

		} while (true);
		

		// 职工姓名
		cout << "请输入职工姓名：";
		cin >> input_name;

		// 根据选择创建worker指针指向相应子类对象
		Worker * wk = NULL;
		switch (input_departmentId) {
			case 1:
				wk = new Employee(input_id, input_name, input_departmentId);
				break;
			case 2:
				wk = new Manager(input_id, input_name, input_departmentId);
				break;
			case 3:
				wk = new Boss(input_id, input_name, input_departmentId);
				break;
			default:
				break;
		};
		
		// 新的指针添加到指针数组中
		newStaffArr[staffNum + j] = wk;
	};

	// 释放原有空间
	delete[] this->staffArr;

	// 指针指向新空间
	this->staffArr = newStaffArr;

	// 更改人数
	this->staffNum = newNum;
	cout << "添加数据成功！" << endl;

	// 保存文件
	this->saveFile(FILENAME);

	// 更新文件状态
	this->FileHasInfo = true;
};


bool StaffManager::showAllInfo() {
	if (FileHasInfo) {
		system("clear");
		for (int i=0;i<this->staffNum;i++) {
			this->staffArr[i]->showInfo();
			//worker类指针 -> worker类成员函数
		};
		return true;
	}
	else {
		cout << "当前无职工信息" << endl;
		return false;
	}
};

int StaffManager::findStaffIdx(int ID) {
	for (int i=0;i<this->staffNum;i++) {
		if (this->staffArr[i]->id == ID) {
			return i;
		};
	};
	return -1;
};

void StaffManager::deleteStaff() {
	if (!this->showAllInfo()) {cout<<"请先输入职工信息！"<<endl;return;};
	int ID;
	cout << "请输入离职员工的职工编号：";
	cin >> ID;
	int idx = this->findStaffIdx(ID);
	if (idx == -1) {
		cout << "没有编号为" << ID << "的员工，请检查您的输入。" << endl;
	}
	else {
		for (int i=idx; i<this->staffNum-1; i++) {
			this->staffArr[i] = this->staffArr[i+1];	
		}
		this->staffNum--;
		cout << "成功删除编号为" << ID << "的员工。" << endl;
		this->saveFile(FILENAME);
		if (this->staffNum == 0) {this->FileHasInfo = false;}
	}
};

void StaffManager::modifyStaff() {
	if (this->showAllInfo()) {
		cout << "请输入你要修改的职工编号:";
		int ID;
		cin >> ID;
		int idx = this->findStaffIdx(ID);
		if (idx == -1) {
			cout << "没有编号为" << ID << "的员工，请检查您的输入。" << endl;
		}
		else {
			int input_departmentId; int input_id; string input_name;
			// 部门编号
			cout << "-选择新的员工的类别-" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			do{
				cout << "请选择：";
				cin >> input_departmentId;
			}
			while (!(input_departmentId==1|input_departmentId==2|input_departmentId==3));
			
			// 职工编号
			do {
				cout << "请输入职工编号：";
				cin >> input_id;
				if (this->findStaffIdx(input_id) == -1 |this->findStaffIdx(input_id) == this->findStaffIdx(ID)) {
					break;
				}
				else {
					cout << "存在该编号的员工" << endl;
				};
			} while (true);

			// 职工姓名
			cout << "请输入新的职工姓名：";
			cin >> input_name;

			// 根据选择创建worker指针指向相应子类对象
			Worker * wk = NULL;
			switch (input_departmentId) {
				case 1:
					wk = new Employee(input_id, input_name, input_departmentId);
					break;
				case 2:
					wk = new Manager(input_id, input_name, input_departmentId);
					break;
				case 3:
					wk = new Boss(input_id, input_name, input_departmentId);
					break;
				default:
					break;
			};
			delete this->staffArr[idx];
			this->staffArr[idx] = wk;
			this->saveFile(FILENAME);
			cout << "修改信息成功" << endl;
		};
	}
	else {
		cout << "请先输入职工信息！" << endl;
	};
};

void StaffManager::findStaff() {
	if (!this->showAllInfo()) {cout<<"请先输入职工信息！"<<endl;return;};
	int select; string input_name; int input_id; // 定义变量不要放在case里面。
	do {
		cout << "1.按姓名查找" << endl << "2.职工编号查找" << endl;
		cout << "请输入查找方式:";
		cin >> select;
	}
	while (select != 1 and select != 2);
	switch (select) {
		case 1:
			cout << "请输入需要查找的姓名：";
			cin >> input_name;
			cout << "查找结果如下：" << endl;
			for (int i=0; i < this->staffNum; i++) {
				if (this->staffArr[i]->name == input_name) {
					this->staffArr[i]->showInfo();
				};
			};break;
		case 2:
			cout << "请输入需要查找的员工编号：";
			cin >> input_id;
			cout << "查找结果如下：" << endl;
			for (int i=0; i < this->staffNum; i++) {
				if (this->staffArr[i]->id == input_id) {
					this->staffArr[i]->showInfo();
					break;
				};
			};break;
	};
}

void StaffManager::sortStaff() {
	if (!this->showAllInfo()) {cout<<"请先输入职工信息！"<<endl;return;};
	int select;
	Worker * tmp = NULL;
	do {
		cout << "1.按编号从小到大排序" << endl << "2.按编号从大到小排序" << endl;
		cout << "请输入排序方式:";
		cin >> select;
	}
	while (select != 1 and select != 2);
	switch (select) {
		case 1:
			for (int i=0; i < this->staffNum-1; i++) {
				for (int j=0; j < this->staffNum-1-i; j++) {
					if (this->staffArr[j]->id > this->staffArr[j+1]->id) {
						tmp = this->staffArr[j];
						this->staffArr[j] = this->staffArr[j+1];
						this->staffArr[j+1] = tmp;
					}
				};
			};
			this->saveFile(FILENAME);
			break;
		case 2:
			for (int i=0; i < this->staffNum-1; i++) {
				for (int j=0; j < this->staffNum-1-i; j++) {
					if (this->staffArr[j]->id < this->staffArr[j+1]->id) {
						tmp = this->staffArr[j];
						this->staffArr[j] = this->staffArr[j+1];
						this->staffArr[j+1] = tmp;
					}
				};
			};
			this->saveFile(FILENAME);
			break;

	};
	
};

void StaffManager::clearStaff() {
	string select;
	cout << "职工信息即将清空，届时所有职工信息将会丢失！" << endl 
			<< "如要继续，请输入 \"yes-i-agree\"" << endl;
	cout << "请输入:";
	cin >> select;
	if (select == "yes-i-agree") {
		for (int i=0; i<this->staffNum; i++) {
			delete this->staffArr[i];
		}
		delete[] this->staffArr;
		this->staffArr = NULL;
		this->staffNum = 0;
		this->FileHasInfo = 0;
		this->saveFile(FILENAME);
		cout << "职工信息已清空" << endl;
	}
	else {
		cout << "取消清空操作" << endl;
	};
};





