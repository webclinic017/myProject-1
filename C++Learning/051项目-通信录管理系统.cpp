#include <iostream>
using namespace std;
/*
功能：
添加联系人：姓名、性别、年龄、联系电话、家庭住址（最多1000条）
显示联系人：
删除联系人：按姓名的方式删除掉联系人
查找联系人：按姓名的方式查看联系人信息
修改联系人：按姓名的方式修改联系人信息
清空联系人：
退出通讯录：退出当前通讯录
*/
const int MAX = 3; // 最多1000条

// 定义联系人
struct person {
	string name;
	string gendar;
	int age;
	string phone;
	string address;
};

// 定义通讯录
struct addressBook {
	struct person personArray[MAX];
	int count;
};


void showMenu() {
	cout << endl;
	cout << "****************************" << endl;
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   5、修改联系人   *****" << endl;
	cout << "*****   6、清空联系人   *****" << endl;
	cout << "*****   0、退出通讯录   *****" << endl;
	cout << "****************************" << endl;
};


void addPerson(struct addressBook * b) {
	if (b->count == MAX) {
		cout << "通讯录已满" << endl;
	}
	else {
		cout << "请输入联系人姓名："; cin >> b->personArray[b->count].name;
		cout << "请输入联系人性别："; cin >> b->personArray[b->count].gendar;
		cout << "请输入联系人年龄："; cin >> b->personArray[b->count].age;
		cout << "请输入联系人电话："; cin >> b->personArray[b->count].phone;
		cout << "请输入联系人地址："; cin >> b->personArray[b->count].address;
		b->count++;	
	};
};


void showBook(const struct addressBook * b) {
	if (b->count == 0) {
		cout << "无联系人记录" << endl;
	}
	else {
		cout << endl << "*** 《通讯录》 ***" << endl;
		for (int i=0; i < b->count; i++) {
			cout << "姓名:" << b->personArray[i].name << "  性别：" << b->personArray[i].gendar << "  年龄：" << b->personArray[i].age << "  电话：" << b->personArray[i].phone << "  地址：" << b->personArray[i].address << endl;
		};
	};
};

int findPerson(struct addressBook * b, string name) {
	for (int i = 0; i < b->count; i++) {
		if (b->personArray[i].name == name) {
			cout << "找到联系人！" << endl;
			return i;
		};
	};
	cout << "未找到联系人！" << endl;
	return -1;
};

void deletePerson(struct addressBook * b) {
	cout << "请输入需要删除的联系人名："; string name; cin >> name;
	int index = findPerson(b, name);
	if (index != -1) {
		b->personArray[index].name		= b->personArray[b->count-1].name;
		b->personArray[index].gendar	= b->personArray[b->count-1].gendar;
		b->personArray[index].age		= b->personArray[b->count-1].age;
		b->personArray[index].phone		= b->personArray[b->count-1].phone;
		b->personArray[index].address	= b->personArray[b->count-1].address;
		b->count--;
		cout << "删除联系人 " << name << " 成功!" << endl;
	};
};

void findOnePerson(struct addressBook * b) {
	cout << "请输入查找的联系人名："; string name; cin >> name;
	int index = findPerson(b, name);
	if (index != -1 ) {
		cout << "姓名:" << b->personArray[index].name << "  性别：" << b->personArray[index].gendar << "  年龄：" << b->personArray[index].age << "  电话：" << b->personArray[index].phone << "  地址：" << b->personArray[index].address << endl;
	};
};

void modifyPerson(struct addressBook * b) {
	cout << "请输入查找的联系人名："; string name; cin >> name;
	int index = findPerson(b, name);
	if (index != -1 ) {
		cout << "请更改联系人姓名："; cin >> b->personArray[index].name;
		cout << "请更改联系人性别："; cin >> b->personArray[index].gendar;
		cout << "请更改联系人年龄："; cin >> b->personArray[index].age;
		cout << "请更改联系人电话："; cin >> b->personArray[index].phone;
		cout << "请更改联系人地址："; cin >> b->personArray[index].address;
	};
};

void clearBook(struct addressBook * p) {
	cout << "是否要情况通讯录？（y or n）:"; char choose; cin >> choose;
	switch (choose) {
		case 'y': p->count = 0; cout << "清空通讯录成功" << endl; return;
			break;
		case 'n': return;
			break;
		default: cout << "输入错误" << endl; return;
			break;
	};
};


int main() {
	// 创建通讯录
	struct addressBook book;
	// 初始化通讯录
	book.count = 0;

	while (true) {
		int selection;
		showMenu();
		cout << "请输入你的选择："; 
		cin >> selection;
		system("clear"); // 清屏
		switch (selection) {
			case 0:		cout << "欢迎下次使用，再见。" << endl;  return 0;  // 0、退出通讯录
				break; 
			case 1:		addPerson(&book);  // 1、添加联系人
				break; 
			case 2:		showBook(&book);   // 2、显示联系人
				break;
			case 3:  	deletePerson(&book); // 3、删除联系人
				break;
			case 4: 	findOnePerson(&book); // 4、查找联系人
				break; 
			case 5:		modifyPerson(&book);  // 5、修改联系人
				break; 
			case 6:		clearBook(&book);     // 6、清空联系人
				break; 
			default:	cout << "输入错误，请输入0-6之间的数字！" << endl;
				break;
		};
	};
};
