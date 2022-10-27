#pragma once
#include <map>
#include <fstream>

class OrderFile {
public:
	// 记录所有预约信息的容器
	map<int,map<string,string>> orders;

	// 记录的条数
	int orderSize;

public:
	// 构造函数 在这里读文件
	OrderFile();

	// 更新预约记录
	void updataOrder();
	
};