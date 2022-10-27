#include <iostream>
using namespace std;
/*
继承的优势：大量减少重复的代码。
语法：
	class 子类(派生类) : 继承方式 父类(基类) {};
*/
class BasePage {
public:
	void header() {
		cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
	};
	void footer() {
		cout << "帮助中心、交流合作、站内地图...（公共底部）" << endl; 
	};
	void left() {
		cout << "Java、Python、C++...（公共分类列表）" << endl; 
	};
};

class Java : public BasePage {
public:
	void content() {
		cout << "Java视频内容..." << endl; 
	};
};

class Python : public BasePage {
public:
	void content() {
		cout << "Python视频内容..." << endl; 
	};
};

class CPP : public BasePage {
public:
	void content() {
		cout << "C++视频内容..." << endl; 
	};
};

int main() {
	Java ja;
	ja.header(); ja.footer(); ja.left(); ja.content();
	cout << endl << endl;

	Python py;
	py.header(); py.footer(); py.left(); py.content();
	cout << endl << endl;

	CPP cpp;
	cpp.header(); cpp.footer(); cpp.left(); cpp.content();
	cout << endl << endl;
	return 0;
}
