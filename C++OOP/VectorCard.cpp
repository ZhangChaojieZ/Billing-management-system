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
////���ľ������
//
//int addnewCard(string cNum,string cPwd,float cMoney,vector<Card>& vec)
////�жϿ����Ƿ���ڣ�������������¿��������򷵻���Ӧ���
//{
//	int CardIndex = 0;
//	if (CardIsExit(cNum, CardIndex, vec) != NULL)
//		return FINDCARD;//�ҵ���
//	//����һ�ſ�
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
////���ݿ����жϿ��Ƿ���ڣ������ڣ��򷵻ظÿ���ַ����ͨ��CardIndex���ؿ�����Ŀ���������ڣ��򷵻ؿ�
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
////չʾ���п���Ϣ
//{
//	vector<Card>::iterator it;
//	cout << "����\t��״̬\t\t���\tʹ�ô���\t�ϴ�ʹ��ʱ��" << endl;
//	for (it = vec.begin(); it != vec.end(); it++)
//	{
//		char aLastTime[TIMELENGTH] = { 0 };
//		timeToString(it->cLast, aLastTime);
//		cout << it->cNumber << "\t";
//		if (it->cStatus == USING)
//			cout << "�����ϻ�\t";
//		else if (it->cStatus == UNUSE)
//			cout << "δ���ϻ�\t";
//		else if (it->cStatus == INVALID)
//			cout << "�Ѿ�ע��\t";
//		else
//			cout << "��Ϣ����";
//		cout << it->cBalance << "\t" << it->cUseCount << "\t\t" << aLastTime << endl;
//	}
//}
//
//bool saveCard(const Card* pCard, const string pPath) //����׷��ģʽ�ѿ�����Ϣд���ļ�
//{
//	ofstream ofile(pPath, ios::binary | ios::app);
//
//	ofile.write((char*)pCard, sizeof(Card)); 
//	ofile.close();
//
//	return true;
//}
//
//void CardVectorInit(const string filename, vector<Card>& vec)//���ļ��е���Ϣ����vector�У����г�ʼ��
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

