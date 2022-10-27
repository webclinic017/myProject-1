#include "199orderFile.h"




// 构造函数 在这里读文件
OrderFile::OrderFile() {
	fstream fs;
	fs.open("./outputFiles/order.txt",ios::in);
	string date;		// 日期
	string interval;	// 上下午
	string stuId;		// 学号
	string stuName;		// 姓名
	string roomId;		// 机房id
	string status;		// 预约状态
	this->orderSize = 0; // 预约条数初始化为0
	while (fs>>date && fs>>interval && fs>>stuId && fs>>stuName && fs>>roomId && fs>>status) {
		string key; string value;
		map<string,string> m;

		int pos;
		// 截取日期 date:1
		pos = date.find(":");
		key = date.substr(0,pos);
		value = date.substr(pos+1,date.size()-(pos+1));
		m.insert(make_pair(key,value));
		// cout << "key = " << key << endl; cout << "value = " << value << endl;
		
		// 截取时间段 interval:1
		pos = interval.find(":");
		key = interval.substr(0,pos);
		value = interval.substr(pos+1,interval.size()-(pos+1));
		m.insert(make_pair(key,value));

		// 截取学号 stuID:1
		pos = stuId.find(":");
		key = stuId.substr(0,pos);
		value = stuId.substr(pos+1,stuId.size()-(pos+1));
		m.insert(make_pair(key,value));

		// 截取姓名 stuName:fsw
		pos = stuName.find(":");
		key = stuName.substr(0,pos);
		value = stuName.substr(pos+1,stuName.size()-(pos+1));
		m.insert(make_pair(key,value));

		// 截取房间号 roomID:1
		pos = roomId.find(":");
		key = roomId.substr(0,pos);
		value = roomId.substr(pos+1,roomId.size()-(pos+1));
		m.insert(make_pair(key,value));

		// 截取预约状态 status:1
		pos = status.find(":");
		key = status.substr(0,pos);
		value = status.substr(pos+1,status.size()-(pos+1));
		m.insert(make_pair(key,value));

		// 插入预约容器中
		this->orders.insert(make_pair(this->orderSize,m));

		// 更新计数
		this->orderSize++;
	};

	// 关闭文件
	fs.close();
};

// 更新预约记录（将map<str,str>重新写入文件）
void OrderFile::updataOrder() {
	if (this->orderSize == 0) {
		return;
	}
	else {
		fstream fs;
		fs.open("./outputFiles/order.txt",ios::out|ios::trunc);
		for (int i=0; i<this->orderSize;i++) {
			fs << "date:" 		<< this->orders[i]["date"] 		<< " ";
			fs << "interval:" 	<< this->orders[i]["interval"] 	<< " ";
			fs << "stuID:" 		<< this->orders[i]["stuId"] 	<< " ";
			fs << "stuName:" 	<< this->orders[i]["stuName"] 	<< " ";
			fs << "roomID:" 	<< this->orders[i]["roomId"] 	<< " ";
			fs << "status:" 	<< this->orders[i]["status"] 	<< endl;
		};

		// 关闭文件
		fs.close();
	};
};