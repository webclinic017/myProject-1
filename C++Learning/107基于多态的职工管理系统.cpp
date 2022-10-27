#include "107staffManager.cpp"
// #include "107employee.cpp"
// #include "107manager.cpp"
// #include "107boss.cpp"


int main() {
	StaffManager core;
	while (true) {
		core.showMenu();
		cout << "请输入：";
		int choose;
		cin >> choose;
		switch (choose) {
			case 0:
				core.exitSystem();
			case 1:
				core.addStaff();
				break;
			case 2:
				core.showAllInfo();
				break;
			case 3:
				core.deleteStaff();
				break;
			case 4:
				core.modifyStaff();
				break;
			case 5:
				core.findStaff();
				break;
			case 6:
				core.sortStaff();
				break;
			case 7:
				core.clearStaff();
				break;
			default:
				system("clear"); break;
		}
	};


	// Worker * wk = new Employee(1,"张三",1);
	// Worker * wk = new Manager(1,"张三",1);
	// Worker * wk = new Boss(1,"张三",1);
	// wk->showInfo();
	return 0;
}