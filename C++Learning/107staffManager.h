#pragma once // 只允许包含一次
#include <iostream> // 标准输入输出流
#include "107worker.h"


using namespace std;

class StaffManager {
public:
	StaffManager();
	~StaffManager();
public:
	int staffNum; 			// 记录职工人数
	Worker ** staffArr;		// 保存职工信息的数组的指针
	bool FileHasInfo;

	void showMenu();
	void exitSystem();
	void addStaff();
	void saveFile(string path);
	void readFile(string path);
	bool showAllInfo();		  // 返回bool值使得修改函数中可以先显示一下。再做判断。
	int findStaffIdx(int ID); // 参数你要找的职工的ID,返回职工在数组的下标。
	void deleteStaff();
	void modifyStaff();
	void findStaff();
	void sortStaff();
	void clearStaff();
};
