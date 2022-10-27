#include "199manager.h"
#include <algorithm>
// #include <vector>

// 默认构造
Manager::Manager() {
    this->initVectors();
    this->initComputer();
};

// 有参构造
Manager::Manager(string m_name, string m_password) {
    this->name = m_name; this->password = m_password;
    this->initVectors();
    this->initComputer();
};

// 显示菜单界面
void Manager::openMenu() {
    cout << "欢迎管理员：" << this->name << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          1.添加账号          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          2.查看账号          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          3.查看机房          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          4.清空预约          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          0.注销登录          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "请输入您的选择：";
};

// 添加账号
void Manager::addPerson() {
    system("clear");
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          1.学    生          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          2.老    师          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          3.管 理 员          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "请输入您要添加的账号类型：";
    int select; int id; string name; string password; fstream fs;
    cin >> select;
    bool mark = true;
    switch (select) {
        case 1:
            while (mark) {
                mark = false;
                cout << "请输入学生编号："; cin >> id;
                for (vector<Student>::iterator it = this->v_student.begin(); it != this->v_student.end(); it++) {
                    if (it->student_id == id) {
                        cout << "有重复的学生编号了" << endl;
                        mark = true; break;
                    };
                };

            };
            
            cout << "请输入姓名："; cin >> name;
            cout << "请输入密码："; cin >> password;
            fs.open(STUDENT_FILE,ios::out|ios::app);
            fs << id << " " << name << " " << password << endl;
            fs.close();
            cout << "学生账号添加成功！" << endl; sleep(1.25);
            break;
        case 2:
            while (mark) {
                mark = false;
                cout << "请输入教师工号："; cin >> id;
                for (vector<Teacher>::iterator it = this->v_teacher.begin(); it != this->v_teacher.end(); it++) {
                    if (it->teacher_id == id) {
                        cout << "有重复的教师工号了" << endl;
                        mark = true; break;
                    };
                };

            };
            cout << "请输入姓名："; cin >> name;
            cout << "请输入密码："; cin >> password;
            fs.open(TEACHER_FILE,ios::out|ios::app);
            fs << id << " " << name << " " << password << endl;
            fs.close();
            cout << "教师账号添加成功！" << endl; sleep(1.25);
            break;
        case 3:
            cout << "请输入管理员姓名："; cin >> name;
            cout << "请输入管理员密码："; cin >> password;
            fs.open(ADMIN_FILE,ios::out|ios::app);
            fs << name << " " << password << endl;
            fs.close();
            cout << "管理员账号添加成功！" << endl; sleep(1.25);
            break;
        default:
            cout << "您输入有误！" << endl; sleep(1.25); return;
    };

    // 做完一次添加操作，及时更新学生容器和老师容器
    this->initVectors();
};

// 查看账号
void Manager::showPerson() {
    system("clear");
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          1.学    生          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t|          2.老    师          |" << endl;
    // cout << "\t\t|                              |" << endl;
    // cout << "\t\t|          3.管 理 员          |" << endl;
    cout << "\t\t|                              |" << endl;
    cout << "\t\t| ---------------------------- |" << endl;
    cout << "请输入您要查的账号类型：";
    int select; int id; string name; string password; fstream fs;
    cin >> select;
    switch (select) {
        case 1:
            fs.open(STUDENT_FILE,ios::in);
            while (fs >> id and fs >> name and fs >> password) {
                cout << "学生编号：" << id << " 姓名：" << name << " 密码：" << password << endl;
            } 
            fs.close();
            sleep(2.5);
            break;
        case 2:
            fs.open(TEACHER_FILE,ios::in);
            while (fs >> id and fs >> name and fs >> password) {
                cout << "教师编号：" << id << " 姓名：" << name << " 密码：" << password << endl;
            } 
            fs.close();
            sleep(2.5);
            break;
        // case 3:
        //     fs.open(ADMIN_FILE,ios::in);
        //     while (fs >> name and fs >> password) {
        //         cout << "管理员姓名：" << name << " 管理员密码：" << password << endl;
        //     } 
        //     fs.close();
        //     sleep(2.5);
        //     break;
        default:
            cout << "您输入有误！" << endl; sleep(1.25); return;
    }

};

// 查看机房信息
void printComputer(Computer &c) {
    cout << "机房编号" << c.room_id << " 机房容量：" << c.room_capacity << endl;
};
void Manager::showComputer() {
    system("clear");
    for_each(this->v_computer.begin(),this->v_computer.end(),printComputer);
    sleep(2.25);
};

// 清空预约
void Manager::clearFile() {
    system("clear");
    fstream fs;
    fs.open(ORDER_FILE, ios::out | ios::trunc);
    fs.close();
    cout << "所有预约已经清空" << endl;
    sleep(1.25);
};

// 初始化老师 & 学生容器
void Manager::initVectors() {
    // 清空容器
    this->v_student.clear();
    this->v_teacher.clear();
    fstream fs;
    Student s;
    Teacher t;
    // 存入学生信息
    fs.open(STUDENT_FILE,ios::in);
    if (!fs.is_open()) {cout << STUDENT_FILE << "文件不存在！" << endl; return;}
    while (fs >> s.student_id and fs >> s.name and fs >> s.password) {
        this->v_student.push_back(s);
    };
    fs.close();
    // 存入老师信息
    fs.open(TEACHER_FILE,ios::in);
    if (!fs.is_open()) {cout << TEACHER_FILE << "文件不存在！" << endl; return;}
    while (fs >> t.teacher_id and fs >> t.name and fs >> t.password) {
        this->v_teacher.push_back(t);
    };
    fs.close();
};

// 初始化机房容器
void Manager::initComputer() {
    fstream fs; int room_id; int room_capacity;
    fs.open(COMPUTER_FILE,ios::in);
    if (!fs.is_open()) {cout << "无机房信息" << endl; return;}
    Computer c;
    while (fs >> c.room_id and fs >> c.room_capacity) {
        this->v_computer.push_back(c);
    };
    fs.close();
};