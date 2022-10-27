#include "199teacher.h"

// 默认构造
Teacher::Teacher() {

};

// 有参构造
Teacher::Teacher(int t_id, string t_name, string t_password) {
    this->teacher_id = t_id;
    this->name = t_name;
    this->password = t_password;
};

// 显示菜单
void Teacher::openMenu() {
    cout << "欢迎老师：" << this->name << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          1.查看预约          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          2.审核预约          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          0.注销登录          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "请输入您的选择：";
};

// 查看所有预约
void Teacher::showAllOrder() {
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
    sleep(2);
};

// 审核预约
void Teacher::validOrder() {
	OrderFile OF;
    if (OF.orderSize == 0) {cout << "无任何预约记录" << endl; return;}

    for (int i=0; i<OF.orderSize; i++) {
        cout << "预约编号:"      << i << "  ";
        cout << "date:" 		<< OF.orders[i]["date"] 	<< " ";
        cout << "interval:" 	<< OF.orders[i]["interval"] << " ";
        cout << "stuID:" 		<< OF.orders[i]["stuId"] 	<< " ";
        cout << "stuName:" 	    << OF.orders[i]["stuName"] 	<< " ";
        cout << "roomID:" 	    << OF.orders[i]["roomId"] 	<< " ";
        cout << "status:" 	    << OF.orders[i]["status"] 	<< endl;
    };
    int num = 0;
    cout << "请输入你要审核的预约编号：";
    cin >> num;
    if (num>=0 && num<OF.orderSize) {
        while (true) {
            int valid;
            cout << "审核该预约：" << endl << "1.同意" << endl << "2.不同意" << endl << "0.不操作" << endl << "请输入：";
            cin >> valid;
            switch (valid) {
                case 1:
                    OF.orders[num]["status"] = "2";
                    OF.updataOrder();
                    cout << "预约编号" << num << "已同意" << endl;
                    return;
                case 2:
                    OF.orders[num]["status"] = "-2";
                    OF.updataOrder();
                    cout << "预约编号" << num << "已拒绝" << endl;
                    return;
                case 0:
                    return;
                default:
                    cout << "" << endl;
            };
        };
    }
    else {
        cout << "输入错误，没有该预约记录！" << endl;
    };
    
    sleep(2);
};