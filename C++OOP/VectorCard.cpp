//
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include"StructCard.h"
//#include"global.h"
//#include"VectorCard.h"
//#include"tool.h"
//using namespace std;
////卡的具体操作
//
//int addnewCard(string cNum,string cPwd,float cMoney,vector<Card>& vec)
////判断卡号是否存在，不存在则加入新卡；存在则返回相应结果
//{
//	int CardIndex = 0;
//	if (CardIsExit(cNum, CardIndex, vec) != NULL)
//		return FINDCARD;//找到卡
//	//构造一张卡
//	Card card;
//	strcpy(card.cNumber , cNum.c_str());    
//	strcpy(card.cPassword, cPwd.c_str());
//	card.cTotalMoney = cMoney;
//	card.cBalance = cMoney;//card.cTotalMoney;
//	card.cStatus = UNUSE;
//	card.cUseCount = 0;
//	card.cStart = time(NULL);
//	card.cLast = time(NULL);
//
//	vec.push_back(card);
//	saveCard(&card, CARDPATH);
//	return SUCCESS;
//}
//
//Card* CardIsExit(string cNum, int CardIndex, vector<Card>& vec)
////根据卡号判断卡是否存在；若存在，则返回该卡地址，并通过CardIndex返回卡的数目；若不存在，则返回空
//{
//	vector<Card>::iterator it;
//	CardIndex = 0;
//	for (it = vec.begin(); it != vec.end(); it++)
//	{
//		if (it->cNumber == cNum)
//			return &(*it);
//		CardIndex++;
//	}
//	return NULL;
//}
//
//void displayCard(vector<Card>& vec)
////展示所有卡信息
//{
//	vector<Card>::iterator it;
//	cout << "卡号\t卡状态\t\t余额\t使用次数\t上次使用时间" << endl;
//	for (it = vec.begin(); it != vec.end(); it++)
//	{
//		char aLastTime[TIMELENGTH] = { 0 };
//		timeToString(it->cLast, aLastTime);
//		cout << it->cNumber << "\t";
//		if (it->cStatus == USING)
//			cout << "正在上机\t";
//		else if (it->cStatus == UNUSE)
//			cout << "未在上机\t";
//		else if (it->cStatus == INVALID)
//			cout << "已经注销\t";
//		else
//			cout << "信息出错！";
//		cout << it->cBalance << "\t" << it->cUseCount << "\t\t" << aLastTime << endl;
//	}
//}
//
//bool saveCard(const Card* pCard, const string pPath) //采用追加模式把卡的信息写入文件
//{
//	ofstream ofile(pPath, ios::binary | ios::app);
//
//	ofile.write((char*)pCard, sizeof(Card)); 
//	ofile.close();
//
//	return true;
//}
//
//void CardVectorInit(const string filename, vector<Card>& vec)//把文件中的信息读到vector中，进行初始化
//{
//	 ifstream ifile(filename);
//	 Card card;
//
//	 if (!ifile.is_open()) {
//		 ifile.close();
//		 return;
//	 }
//	while (true)
//	{
//		ifile.read((char*)&card, sizeof(Card));
//		if (ifile.eof()) 
//		{
//			ifile.close();
//			break;
//		}
//		vec.push_back(card);
//	} 
//	//displayCard(vec);
//	return;
//}

