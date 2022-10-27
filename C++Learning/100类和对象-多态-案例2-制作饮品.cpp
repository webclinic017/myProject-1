#include <iostream>
using namespace std;
/*
纯虚函数语法： virtual 返回类型 函数名(参数表) = 0;
包含纯虚函数的类叫做抽象类，它无法实例化对象。
子类必须重写父类的纯虚函数，否则子类也成了抽象类，也同样无法实例化对象。
*/
class MakeDrink {
public:
	// 1.饮料名称
	virtual void name() = 0;

	// 2.煮水
	virtual void boil() = 0;

	// 3.冲泡
	virtual void brewUp() = 0;

	// 4.倒入杯中
	virtual void pour() = 0;
	
	// 5.加糖
	virtual void addSugar() = 0;

	// 0.整合流程，对外精简接口
	void done() {
		name(); boil(); brewUp(); pour(); addSugar();
		cout << "制作完成!" << endl;
	};
};

class Coffee : public MakeDrink {
public:
	void name()		{cout << "制作咖啡" << endl;};
	void boil()		{cout << "煮农夫山泉" << endl;};
	void brewUp()	{cout << "85度冲泡" << endl;};
	void pour()		{cout << "倒入精美咖啡杯中" << endl;};
	void addSugar()	{cout << "加牛奶加糖" << endl;};
};

class Tea : public MakeDrink {
public:
	void name()		{cout << "制作龙井" << endl;};
	void boil()		{cout << "煮虎跑泉水" << endl;};
	void brewUp()	{cout << "98-100度冲泡" << endl;};
	void pour()		{cout << "倒入紫砂茶壶中" << endl;};
	void addSugar()	{cout << "不用加任何东西" << endl;};
};

void do_make(MakeDrink * m) {
	m->done();
};





int main() {
	do_make(new Coffee);
	cout << "---------------------------------------" << endl;
	do_make(new Tea);
	return 0;
}
