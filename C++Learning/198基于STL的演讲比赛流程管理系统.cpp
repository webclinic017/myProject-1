#include "198mainBody.cpp"
/*
比赛规则：
	1.12人参加比赛。共两轮：第一轮为淘汰赛，第二轮为决赛。
	2.每个选手都随机分配编号10001~10012。
	3.第一轮比赛分两组，每组6人
	4.10个评委打分，去掉最高和最低分，求得平均分为本轮成绩
	5.每组的前三晋级
	6.决赛的前三为冠亚季军
	7.每轮比赛过后要显示晋级选手的信息
程序功能：
	1.开始演讲比赛：完成整届比赛流程，每个阶段给用户打印信息，按任意键继续
	2.查看往届记录：往届记录都会在csv文件中
	3.清空比赛记录：清空csv
	4.退出比赛：退出当前比赛
*/

int main() {
	MainBody core;
	// core.showMenu();
	while (true) {
		core.showMenu();
		cout << "请输入您的选择：";
		int select = 0;
		cin >> select;
		switch (select) {
			case 1: // 1.开始演讲比赛
				core.startGame(); break;
			case 2: // 2.查看往届纪录
				core.showRecord(); break;
			case 3: // 3.清空比赛记录
				core.clearFile(); break;
			case 0: // 0.退出比赛程序
				core.exitSystem(); break;
			default:
				system("clear"); break;
		};
	};
	return 0;
}


