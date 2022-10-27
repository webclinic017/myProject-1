#include "199student.h"

// 默认构造
Student::Student() {};

// 有参构造
Student::Student(int s_id, string s_name, string s_password) {
    this->student_id = s_id;
    this->name = s_name;
    this->password = s_password;
    this->initComputer();
};

// 打开菜单
void Student::openMenu() {
    cout << "欢迎学生代表：" << this->name << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          1.申请预约          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|        2.查看我的预约        |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|        3.查看所有预约        |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          4.取消预约          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          0.注销登录          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "请输入您的选择：";
};

// 申请预约
void Student::applyOrder() {
    cout << "请输入日期：" << endl;
    cout << "1.礼拜一" << endl;
    cout << "2.礼拜二" << endl;
    cout << "3.礼拜三" << endl;
    cout << "4.礼拜四" << endl;
    cout << "5.礼拜五" << endl;
    int date;
    while (true) {
        cout << "请输入：";
        cin >> date;
        if (date>=1 and date<=5) { break; }
        else {cout << "输入错误！请重新输入！" << endl;};
    };
    cout << "请选择上午、下午：" << endl;
    cout << "1.上午" << endl;
    cout << "2.下午" << endl;
    int interval;
    while (true) {
        cout << "请输入：";
        cin >> interval;
        if (interval>=1 and interval<=2) { break; }
        else {cout << "输入错误！请重新输入！" << endl;};
    };
    cout << "请选择机房：" << endl;
    for (vector<Computer>::iterator it = this->v_computer.begin(); it != this->v_computer.end(); it++) {
        cout << "机房号：" << it->room_id << " 机房容量：" << it->room_capacity << endl;
    }
    int room;
    bool mark = true;
    while (mark) {
        cout << "请输入：";
        cin >> room;
        for (vector<Computer>::iterator it = this->v_computer.begin(); it != this->v_computer.end(); it++) {
            if (room == it->room_id) {mark=false;};
        };
        if (mark) {cout << "输入错误！请重新输入！" << endl;};
    };

    fstream fs(ORDER_FILE,ios::out|ios::app);
    fs << "date:" << date << " ";
    fs << "interval:" << interval << " ";
    fs << "stuID:" << this->student_id << " ";
    fs << "stuName:" << this->name << " ";
    fs << "roomID:" << room << " ";
    fs << "status:" << 1 << endl;
    fs.close();
    cout << "预约成功，审核中。" << endl;
    sleep(1.5);


};

// 查看自己的预约
void Student::showMyOrder() {
    OrderFile OF;
    if (OF.orderSize == 0) {cout << "无任何预约记录" << endl; return;}

    for (int i=0; i<OF.orderSize; i++) {
        if (OF.orders[i]["stuName"]  == this->name) {
            cout << "date:" 		<< OF.orders[i]["date"] 	<< " ";
			cout << "interval:" 	<< OF.orders[i]["interval"] << " ";
			cout << "stuID:" 		<< OF.orders[i]["stuId"] 	<< " ";
			cout << "stuName:" 	    << OF.orders[i]["stuName"] 	<< " ";
			cout << "roomID:" 	    << OF.orders[i]["roomId"] 	<< " ";
			cout << "status:" 	    << OF.orders[i]["status"] 	<< endl;
        };
    };
    int a = 0;
    while (a!=1) {
        cout << "请输入1回车返回上级菜单：";
        cin >> a;
        if (a != 1) {cout << "输入错误" << endl;};
    };    
};

// 查看所有预约
void Student::showAllOrder() {
    OrderFile OF;
    if (OF.orderSize == 0) {cout << "无任何预约记录" << endl; return;}
    
    for (int i=0; i<OF.orderSize; i++) {
        cout << "date:" 		<< OF.orders[i]["date"] 	<< " ";
        cout << "interval:" 	<< OF.orders[i]["interval"] << " ";
        cout << "stuID:" 		<< OF.orders[i]["stuId"] 	<< " ";
        cout << "stuName:" 	    << OF.orders[i]["stuName"] 	<< " ";
        cout << "roomID:" 	    << OF.orders[i]["roomId"] 	<< " ";
        cout << "status:" 	    << OF.orders[i]["status"] 	<< endl;
    };
    int a = 0;
    while (a!=1) {
        cout << "请输入1回车返回上级菜单：";
        cin >> a;
        if (a != 1) {cout << "输入错误" << endl;};
    };    
};

// 取消预约
void Student::cancelOrder() {
    OrderFile OF;
    if (OF.orderSize == 0) {cout << "无任何预约记录" << endl; return;}
	set<int> id_you_can_cancel;


    for (int i=0; i<OF.orderSize; i++) {
        if (OF.orders[i]["stuName"]  == this->name) {
            cout << "预约编号:"      << i << "  ";
            id_you_can_cancel.insert(i);
            cout << "date:" 		<< OF.orders[i]["date"] 	<< " ";
			cout << "interval:" 	<< OF.orders[i]["interval"] << " ";
			cout << "stuID:" 		<< OF.orders[i]["stuId"] 	<< " ";
			cout << "stuName:" 	    << OF.orders[i]["stuName"] 	<< " ";
			cout << "roomID:" 	    << OF.orders[i]["roomId"] 	<< " ";
			cout << "status:" 	    << OF.orders[i]["status"] 	<< endl;
        };
    };
    int a = 0;
    cout << "请输入你要取消的预约编号：";
    cin >> a;
    set<int>::iterator pos = id_you_can_cancel.find(a);
	if (pos != id_you_can_cancel.end()) {
        OF.orders[a]["status"] = "-1";
        OF.updataOrder();
		cout << "预约编号" << a << "取消成功" << endl;
	}
	else {
		cout << "您无权取消该条记录" << endl;
	};
    sleep(1.5);
};	

// 初始化机房容器
void Student::initComputer() {
    fstream fs(COMPUTER_FILE,ios::in);
    Computer c;
    while (fs >> c.room_id and fs >> c.room_capacity) {
        this->v_computer.push_back(c);
    };
    fs.close();
};