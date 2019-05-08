//#pragma once//卡的具体操作
//#ifndef VECTORCARD_H
//#define VECTORCARD_H
//
//
//#include<vector>
//#include<string>
//#include"StructCard.h"
//using namespace std;
//
//int addnewCard(string cNum, string cPwd, float cMoney, vector<Card>& vec);
////判断卡号是否存在，不存在则加入新卡；存在则返回相应结果
//
//Card* CardIsExit(string cNum, int CardIndex, vector<Card>& vec);
////根据卡号判断卡是否存在；若存在，则返回该卡地址，并通过CardIndex返回卡的数目；若不存在，则返回空
//
//void displayCard(vector<Card>& vec);
////展示所有卡信息
//
//bool saveCard(const Card* pCard, const string pPath);
////采用追加模式把卡的信息写入文件
//
//void CardVectorInit(const string filename, vector<Card>& vec);
////把文件中的信息读到vector中，进行初始化
//#endif // !VECTORCARD_H