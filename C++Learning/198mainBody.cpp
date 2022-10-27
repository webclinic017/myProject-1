#include "198mainBody.h"

// 构造函数
MainBody::MainBody() {
    //初始化成员属性
    this->init();

    // 读取记录文件
    this->loadRecord();
    
    // 创建演讲选手
    this->createSpeaker();
};

// 析构函数
MainBody::~MainBody() {

};

// 显示菜单
void MainBody::showMenu() {
    cout << "******************************************" << endl;
    cout << "************* 欢迎参加演讲比赛 ***********" << endl;
    cout << "*************  1.开始演讲比赛  ***********" << endl;
    cout << "*************  2.查看往届纪录  ***********" << endl;
    cout << "*************  3.清空比赛记录  ***********" << endl;
    cout << "*************  0.退出比赛程序  ***********" << endl;
    cout << "******************************************" << endl;
    cout << endl;
};

// 退出功能
void MainBody::exitSystem() {
    // this->testVectorAndMap();
    cout << "欢迎下次使用" << endl;
    exit(0);
};

// 初始化成员属性的函数
void MainBody::init() {
    this->round_1.clear();
    this->round_2.clear();
    this->round_3.clear();
    this->speaker_map.clear();
    this->round_count = 1;
    this->isEmpty = true;
    this->record.clear();
};

// 创建选手函数
void MainBody::createSpeaker() {
    string nameseed = "ABCDEFGHIJKLMN";
    for (int i=0; i<12; i++) {
        string name = "选手";
        name += nameseed[i];
        Speaker spk;
        spk.name = name;
        spk.scoreArr[0] = 0.0;
        spk.scoreArr[1] = 0.0;
        this->round_1.push_back(10001+i);
        this->speaker_map.insert(make_pair(10001+i,spk));
    };
};

// 测试1:显示创建选手是否正确
// void MainBody::testVectorAndMap() {
//     cout << "round_1：" << endl;
//     for (vector<int>::iterator it = this->round_1.begin(); it!=this->round_1.end(); it++) {
//         cout << *it << "  ";
//     }; cout << endl;
//     cout << "speaker_map:" << endl;
//     for (map<int,Speaker>::iterator it = this->speaker_map.begin();it != this->speaker_map.end(); it++) {
//             cout << "编号：" << it->first << " 姓名：" << it->second.name << " 分数1：" << it->second.scoreArr[0] << " 分数2：" << it->second.scoreArr[1]<< endl;
//     };
// };

// 演讲比赛主流程
void MainBody::startGame() {
    // 0. 清屏
    system("clear");
    
    // 1.抽签
    this->draw_lots();

    // 2.第一轮比赛
	this->match();

    // 3.显示第一轮比赛结果
    this->showWinner();

    // 4.轮数加一
    this->round_count++;

    // 5.第二轮比赛
	this->match();

    // 6.显示第二轮比赛结果
    this->showWinner();

    // 7.保存记录到csv文件
    this->saveRecord();

    // 8.比赛结束 清除比赛痕迹
    this->round_2.clear(); this->round_3.clear(); this->round_count = 1;

    // 9.重载文件
    this->loadRecord();
};

// 抽签
void MainBody::draw_lots() {
    cout << "第 " << this->round_count << " 轮选手结束抽签：" << endl << "抽签结果:";
    // 创建随机数种子
	srand( (unsigned int)time(NULL) );
    if (this->round_count == 1) {
        random_shuffle(this->round_1.begin(),this->round_1.end());
        for (vector<int>::iterator it =this->round_1.begin(); it!=this->round_1.end(); it++) {
            cout << *it << " ";
        }; cout << endl << endl;
    }
    else {
        random_shuffle(this->round_2.begin(),this->round_2.end());
        for (vector<int>::iterator it =this->round_2.begin(); it!=this->round_2.end(); it++) {
            cout << *it << " ";
        }; cout << endl << endl;
    }
};

// 排序规则 (全局)
bool myRule(const Counter &c1, const Counter &c2) {
    return c1.score > c2.score;
};

// 比赛
void MainBody::match() {
    if (this->round_count == 1) {
        cout << "第一轮比赛正式开始！" << endl;
        // 这里老师的做法太复杂，我这里用"198speaker.h"中的计分器做两个队伍，再对这两个队伍排序
        vector<Counter> team1;
        vector<Counter> team2;

        // 创建随机数种子
        srand( (unsigned int)time(NULL) );
        
        // 打分
        for (int i = 0; i < 12; i++) {
            // 参赛编号
            int id = this->round_1[i];

            // 打分（求平均分）
            deque<double> scores;
            for (int j = 0; j < 10; j++) {
                double score = (rand() % 4001 + 6000) / 100.00; // 600~1000分
                scores.push_back(score);
            };
            sort(scores.begin(),scores.end());
            scores.pop_front(); scores.pop_back();
            double avg = accumulate(scores.begin(),scores.end(),0.0f) / scores.size();
            
            // 在map中记录分数
            this->speaker_map[id].scoreArr[0] = avg;

            // 将编号和分数记录在两个队伍中
            if ( i<6 ) {
                team1.push_back(Counter(id,avg));
            }
            else {
                team2.push_back(Counter(id,avg));
            };
        };

        // 打分完成将队伍安照分数进行排序
        sort(team1.begin(),team1.end(),myRule);
        sort(team2.begin(),team2.end(),myRule);

        // 添加编号到第二轮round_2
        for (int i = 0; i < 3; i++) {
            round_2.push_back(team1[i].id);
            round_2.push_back(team2[i].id);
        };

        // 测试 
        /*
        cout << "team1:" << endl;
        for (vector<Counter>::iterator it = team1.begin(); it != team1.end(); it++) {
            cout << "编号：" <<  it->id << " 分数：" << it->score << endl;
        };
        cout << "team2:" << endl;
        for (vector<Counter>::iterator it = team2.begin(); it != team2.end(); it++) {
            cout << "编号：" <<  it->id << " 分数：" << it->score << endl;
        };
        cout << "speaker_map:" << endl;
        for (map<int,Speaker>::iterator it = speaker_map.begin();it != speaker_map.end(); it++) {
                cout << "编号：" << it->first << " 姓名：" << it->second.name << " 分数1：" << it->second.scoreArr[0] << " 分数2：" << it->second.scoreArr[1]<< endl;
        };
        cout << "晋级round_2选手：" << endl;
        for (vector<int>::iterator it = this->round_2.begin(); it!=this->round_2.end(); it++) {
            cout << *it << "  ";
        }; cout << endl << endl;
        */
    }
    else {
        cout << "第二轮比赛正式开始！" << endl;
        // 这里老师的做法太复杂，我这里用"198speaker.h"中的计分器做两个队伍，再对这两个队伍排序
        vector<Counter> team3;

        // 创建随机数种子
        srand( (unsigned int)time(NULL) );
        
        // 打分
        for (int i = 0; i < 6; i++) {
            // 参赛编号
            int id = this->round_2[i];

            // 打分（求平均分）
            deque<double> scores;
            for (int j = 0; j < 10; j++) {
                double score = (rand() % 4001 + 6000) / 100.00; // 600~1000分
                scores.push_back(score);
            };
            sort(scores.begin(),scores.end());
            scores.pop_front(); scores.pop_back();
            double avg = accumulate(scores.begin(),scores.end(),0.0f) / scores.size();
            
            // 在map中记录分数
            this->speaker_map[id].scoreArr[1] = avg;

            // 将编号和分数记录在两个队伍中
            team3.push_back(Counter(id,avg));
        };

        // 打分完成将队伍安照分数进行排序
        sort(team3.begin(),team3.end(),myRule);


        // 添加编号到第二轮round_3
        for (int i = 0; i < 3; i++) {
            round_3.push_back(team3[i].id);
        }

        // 测试
        /*
        cout << "team3:" << endl;
        for (vector<Counter>::iterator it = team3.begin(); it != team3.end(); it++) {
            cout << "编号：" <<  it->id << " 分数：" << it->score << endl;
        };

        cout << "speaker_map:" << endl;
        for (map<int,Speaker>::iterator it = speaker_map.begin();it != speaker_map.end(); it++) {
                cout << "编号：" << it->first << " 姓名：" << it->second.name << " 分数1：" << it->second.scoreArr[0] << " 分数2：" << it->second.scoreArr[1]<< endl;
        };
        cout << "冠亚季军：" << endl;
        for (vector<int>::iterator it = this->round_3.begin(); it!=this->round_3.end(); it++) {
            cout << *it << "  ";
        }; cout << endl << endl;
        */
    };
};

// 显示比赛结果
void MainBody::showWinner() {
    if (this->round_count == 1) {
        cout << "晋级决赛选手：" << endl;
        for (vector<int>::iterator it = this->round_2.begin(); it!=this->round_2.end(); it++) {
            cout << "姓名：" << speaker_map[*it].name << " 分数：" << speaker_map[*it].scoreArr[0] << endl;
        }; 
    }
    else {
        cout << "冠亚季军：" << endl;
        for (vector<int>::iterator it = this->round_3.begin(); it!=this->round_3.end(); it++) {
            cout << "姓名：" << speaker_map[*it].name << " 分数：" << speaker_map[*it].scoreArr[1] << endl;
        }; 
    };
};

// 保存记录到csv文件
void MainBody::saveRecord() {
    fstream fs;
    fs.open("./outputFiles/matchRecord.csv",ios::out|ios::app);
    for (vector<int>::iterator it = this->round_3.begin(); it != this->round_3.end(); it++) {
        fs << *it << "," << speaker_map[*it].scoreArr[1] << ",";
    }; fs << endl;
    fs.close();
};

// 读取文件到容器
void MainBody::loadRecord() {
    ifstream ifs;
    ifs.open("./outputFiles/matchRecord.csv",ios::in);
    if (!ifs.is_open()) {
        cout << "比赛记录csv文件不存在" << endl;
        ifs.close();
        this->isEmpty = true;
        return;
    }
    else if (ifs.get() == EOF) {
		cout << "比赛记录csv为空" << endl;
        ifs.close();
        this->isEmpty = true;
		return;
	}
    else {
        ifs.close(); // 因为已经读走了一个字符 所以必须重启一次
        ifs.open("./outputFiles/matchRecord.csv",ios::in);
        string data;
        int times = 1; // 第几届
        while (ifs >> data) {
            // cout << data << endl;
            // 10002,86.687,10009,81.356,10007,78.556,
            
            int pos  = -1; // 变量，逗号的位置
            int start = 0; // 变量，每次截取的开始位置
            vector<string> v_tmp;
            while (true) {
                pos = data.find(",", start);
                if (pos == -1) {
                    break;
                }
                else {
                    string temp = data.substr(start, pos-start); // 从start位置开始截取，截取pos-start个长度的字符。
                    // cout << temp << endl;
                    v_tmp.push_back(temp); // 存入vector中，等最后把pair(int,vector<string>)存入我们的历史记录容器中
                    start = pos + 1;
                };
            };
            this->record.insert(pair<int,vector<string>>(times,v_tmp));
            times++; // 届数+1
        };
        ifs.close();
        this->isEmpty = false;
    };
};

// 显示 容器record中的往届信息
void MainBody::showRecord() {
    system("clear");
    this->loadRecord();
    if (this->isEmpty) {
        cout << "暂时无往届记录，请开始比赛生成记录。" << endl;
    }
    else {
        for (map<int,vector<string>>::iterator it = this->record.begin(); it != this->record.end(); it++) {
            cout << "第 " << it->first << " 届演讲比赛：" << endl;
            // int firstID = (int)(it->second[0]); int secondID = (int)it->second[2]; int thirdID = (int)it->second[4];
            // double firstScore = it->second[1]; double secondScore = it->second[3]; double thirdScore = it->second[5];
            cout << "冠军：" << (it->second[0]) << " 分数：" << it->second[1] << endl;
            cout << "亚军：" << it->second[2] << " 分数：" << it->second[3] << endl;
            cout << "季军：" << it->second[4] << " 分数：" << it->second[5] << endl;
            // cout << speaker_map[10002].name << endl;
        };
    };
        
};

// 清空文件
void MainBody::clearFile() {
    system("clear");
    fstream fs;
    fs.open("./outputFiles/matchRecord.csv",ios::out|ios::trunc);
    fs << "";
    fs.close();
    this->record.clear();
    this->isEmpty = true;
    cout << "文件已经清空！" << endl;
};











