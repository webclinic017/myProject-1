#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "198speaker.h"
#include <deque>
#include <algorithm>
#include <numeric>
#include <fstream>
/*
MainBody:
	1.提供菜单界面交互
	2.对比赛流程进行控制
	3.与csv文件进行读写交互
*/

class MainBody {
public: // 成员属性
	// 存放一开始12名选手的编号
	vector<int> round_1;

	// 存放晋级的6名选手的编号
	vector<int> round_2;
	
	// 存放冠亚军3名选手的编号
	vector<int> round_3;
	
	// 存放 选手的编号vs选手 的键值对
	map<int,Speaker> speaker_map;
	
	// 存放比赛轮数
	int round_count;

	// 文件是否为空标志
	bool isEmpty;

	// 存放比赛历史的容器
	map<int,vector<string>> record;

public: // 成员函数	
	// 构造函数
	MainBody();
	
	// 析构函数
	~MainBody();
	
	// 显示菜单
	void showMenu();
	
	// 退出功能
	void exitSystem();
	
	// 初始化成员属性的函数
	void init();

	// 创建选手函数
	void createSpeaker();

	// 测试1:显示创建选手是否正确
	// void testVectorAndMap();

	// 演讲比赛主流程
	void startGame();

	// 抽签
	void draw_lots();

	// 排序规则
	// bool myRule(const Counter &c1, const Counter &c2);

	// 比赛
	void match();

	// 显示比赛结果
	void showWinner();

	// 保存记录到csv文件
    void saveRecord();

	// 读取文件到容器
	void loadRecord();

	// 显示记录容器record中的往届信息
	void showRecord();

	// 清空文件
	void clearFile();
};
