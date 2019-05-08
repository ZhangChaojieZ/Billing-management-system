#include<iostream>
#include<string>
#include"menu.h"
#include"DataProcessing.h"
#include"model.h"
#include"service.h"
#include"global.h"
//#include<vector>
//#include"VectorCard.h"
#include"cardList.h"
#include"billList.h"
#include"moneyList.h"
using namespace std;



int main()
{
	string input;
	//vector<Card> vec;
	//CardVectorInit(CARDPATH, vec);//初始化文件中的卡信息

	CardNode* pCardNodeHead = NULL;
	pCardNodeHead = CardListInit(CARDPATH);

	BillingNode* pBillingNodeHead = NULL;
	pBillingNodeHead = BillingListInit(BILLINGPATH);

	MoneyInfoNode* pMoneyInfoNodeHead = NULL;
	pMoneyInfoNodeHead = moneyListInit(MONEYPATH);
	
	cout << "**欢迎进入计费管理系统**" << endl;	

	while (true) 
	{
		outputMenu();
		cin >> input;
		cin.clear();//清空数据流
		cin.sync();//更改cin标识符，clear（）和sync（）一起使用，清空缓冲区的数据，避免影响下一次输入
		if (input == "1")//如果两个字符串相等，compare（）返回值为0，判等不能用“==”，因为这个比较的是地址是否相等
		{
			cout << "******添加卡******\n";
			//addCard(vec);
			addCard(&pCardNodeHead,&pMoneyInfoNodeHead);
		}
		else if (input == "2")
		{
			cout << "******查询卡******\n";
			//queryCard(vec);
			queryCard(pCardNodeHead);
		}
		else if (input == "3")
		{
			cout << "******上机*******\n";
			ShangJi(pCardNodeHead,&pBillingNodeHead);
		}
		else if (input == "4")
		{
			cout << "******下机******\n";
			XiaJi(pCardNodeHead, pBillingNodeHead);
		}
		else if (input == "5")
		{
			cout << "******充值******\n";
			addMoney(pCardNodeHead, &pMoneyInfoNodeHead); 
		}
		else if (input == "6")
		{
			cout << "******退费******\n";
			backMoney(pCardNodeHead, &pMoneyInfoNodeHead);
		}
		else if (input == "7")
		{
			queryStats(pBillingNodeHead, pMoneyInfoNodeHead);
		}
		else if (input == "8")
		{
			cout << "******注销卡******\n";
			invalid(pCardNodeHead, &pMoneyInfoNodeHead);
		}
		else if (input == "0")
		{
			cleanData(pCardNodeHead);
			cout << "退出系统！谢谢使用！";
			break;
		}
		else cout << "输入错误，请重新输入！\n";
	}
	return 0;
}

