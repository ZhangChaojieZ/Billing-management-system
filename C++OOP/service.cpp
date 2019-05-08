
#include<iostream>
#include<string>
//#include<vector>
#include"DataProcessing.h"
#include"menu.h"
//#include"VectorCard.h"
#include"cardList.h"
#include"global.h"
#include"model.h"
#include"billList.h"
#include"moneyList.h"
#include"tool.h"
#include"queryStats.h"
using namespace std;

//void addCard(vector<Card>& vec)//添加卡
//{
//	string CardNumber;
//	string CardPwd;
//	float CardMoney;
//	if (inputNumPwdMon(CardNumber,CardPwd,CardMoney))
//	{
//		cout << "卡号：" << CardNumber << endl;
//		cout << "密码：" << CardPwd << endl;
//		cout << "金额：" << CardMoney << endl;
//
//		int Result;
//		Result = addnewCard(CardNumber, CardPwd, CardMoney, vec);
//		if (Result == FINDCARD)
//			cout << "该卡已存在，添加卡失败！" << endl;
//		else if (Result == SUCCESS)
//			cout << "添加卡成功！" << endl;
//		else
//			cout << "其他情况"<<endl;
//	}	
//	else
//		cout << "信息输入错误，添加卡失败！" << endl;
//}
//
//void queryCard(vector<Card>& vec)//查询卡
//{
//	displayCard(vec);
//}

void addCard(CardNode** ppCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead)
{
	string CardNumber;//密码
	string CardPwd;//卡号
	float CardMoney;//充值金额
	char addcardTime[TIMELENGTH] = { 0 };//开卡时间
	time_t tempTime;
	RechargeInfo* pRechargeInfo=new RechargeInfo;

	//CardNode* pCardNode = *ppCardNodeHead;

	if (inputNumPwdMon(CardNumber, CardPwd, CardMoney)) 
	{
		int nResult = addNewCard(CardNumber, CardPwd, CardMoney, ppCardNodeHead);
		switch (nResult)
		{
			case FINDCARD:
			{    
				cout << endl << endl << "卡【" << CardNumber << "】已经存在，添加新 卡失败！" << endl << endl; 
				break;           
			}             
			case SUCCESS:
			{                
				tempTime=time(NULL);
				timeToString(tempTime, addcardTime);
				cout << endl << endl << "添加新卡成功!" << endl << endl; 
				cout << "新卡卡号：" << CardNumber << endl;
				cout << "新卡金额：" << CardMoney << endl; 
				cout << "开卡时间：" << addcardTime<<endl;

				addNewMoney(*ppCardNodeHead, ppMoneyInfoNodeHead, pRechargeInfo, CardNumber, CardPwd, CardMoney);	//增加卡，增加一条充值记录			

				break;         
			}          
			default: 
			{              
				cout << endl << endl << "系统错误!" << endl << endl;
				break;         
			}
		}
	}
	else
	{
		cout << endl << endl << "输入的【卡号，密码，金额】等信息格式不符号要求， 添加卡失败!" << endl << endl;
	}
	delete pRechargeInfo;
}

void queryCard(CardNode* pCardNodeHead) 
{
	displayCard(pCardNodeHead);
}

void ShangJi(CardNode* pCardNodeHead, BillingNode** BillingNodeHead)
{
	string cNum;
	string cPwd;
	LoginInfo* pInfo = new LoginInfo;//上机信息。用于显示
	char cTime[TIMELENGTH] = { 0 };
	if (inputNumPwd(cNum, cPwd))
	{
		cout << endl << "*******上机信息如下******" << endl;

		//根据上机结果，提示不同信息
		int cResult = Login(cNum, cPwd, pInfo, pCardNodeHead, BillingNodeHead);
		switch (cResult)
		{
		case NOTFINDCARD:
		case NOTMATCH:
		{
			cout << endl << endl << "卡不存在，或卡信息不对，不能上机" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			timeToString(pInfo->cStart, cTime);//上机时间转化
			cout << endl;
			cout << "卡    号：\t" << cNum << endl;
			cout << "余    额：\t" << pInfo->cBalance << endl;
			cout << "上机时间：\t" << cTime << endl;
			break;
		}
		case USING:
		{
			cout << endl << "该卡正在使用，不能重复上机！" << endl;
			break;
		}
		case NOTENOUGHMONEY:
		{
			cout << endl << "卡余额不足，不能上机！" << endl;
			break;
		}
		case INVALID:
		{
			cout << "该卡已经注销，不能上机！" << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else
	{
		cout << endl << endl << "卡号或者密码格式不正确，上机失败！" << endl << endl;
	}
	delete pInfo;
}

void XiaJi(CardNode* pCardNodeHead, BillingNode* pBillingNodeHead)
{
	string CardNumber;
	string CardPwd;

	SettleInfo* pInfo = new SettleInfo; // 下机信息
	char aStartTime[TIMELENGTH] = { 0 };  // 上机时间 
	char aEndTime[TIMELENGTH] = { 0 };    // 下机时间 

	if (inputNumPwd(CardNumber, CardPwd)) {
		cout << "----------下机信息如下----------\n\n";

		int nResult = settle(CardNumber, CardPwd, pInfo, pCardNodeHead, pBillingNodeHead);
		switch (nResult)
		{
		case NOTFINDCARD:
		case NOTMATCH:
		{
			cout << endl << endl << "卡不存在，或卡信息不对，下机失败！" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			timeToString(pInfo->tStart, aStartTime);
			timeToString(pInfo->tEnd, aEndTime);

			cout << endl;
			cout << "卡    号: \t" << CardNumber << endl;
			cout << "消    费: \t" << pInfo->cAmount << endl;
			cout << "余    额: \t" << pInfo->cBalance << endl;
			cout << "上机时间：\t" << aStartTime << endl;
			cout << "下机时间：\t" << aEndTime << endl;

			break;
		}
		case UNUSE:
		{
			cout << endl << endl << "该卡没有上机！" << endl << endl;
			break;
		}
		case NOTENOUGHMONEY:
		{
			cout << endl << endl << "卡余额不足，请先充值再下机！" << endl << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else
	{
		cout << endl << endl << "卡号或者密码格式不正确，下机失败!" << endl << endl;
	}

	delete pInfo;

}

void addMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead)
{
	string cNum;
	string cPwd;
	float cMoney;//充值金额
	RechargeInfo* pRechargeInfo = new RechargeInfo;//充值信息结构体，用于显示
	char cRechargeTime[TIMELENGTH] = { 0 };//充值时间

	if (inputNumPwdMon(cNum,cPwd,cMoney))
	{
		cout << "******充值信息如下******" << endl<<endl;
		int nResult = addNewMoney(pCardNodeHead, pMoneyInfoNodeHead, pRechargeInfo,cNum, cPwd,cMoney);
		switch(nResult)
		{
			case NOTFINDCARD:
			case NOTMATCH:
			{
				cout << "该卡不存在或卡信息不存在，无法充值！" << endl;
				break;
			}
			case INVALID:
			{
				cout << "该卡已注销，无法充值！" << endl;
				break; 
			}
			case SUCCESS:
			{
				timeToString(pRechargeInfo->tRechargeTime, cRechargeTime);

				cout << endl;
				cout << "卡    号: \t" << cNum << endl;
				cout << "充值金额: \t" << pRechargeInfo->cMoney << endl;
				cout << "余    额: \t" << pRechargeInfo->cBalance << endl;
				cout << "充值时间：\t" << cRechargeTime << endl<<endl;
			}
		}
	}
	else
	{
		cout << "卡号,密码或金额输入错误，无法充值！" << endl;
	}

	delete pRechargeInfo;

}

void backMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead)
{
	string cNum;
	string cPwd;
	ReturnsInfo* pReturnsInfo = new ReturnsInfo;//充值信息结构体，用于显示
	char cReturnsTime[TIMELENGTH] = { 0 };//充值时间

	if (inputNumPwd(cNum, cPwd))
	{
		cout << "******退费信息如下******" << endl <<endl;
		int nResult = returns(pCardNodeHead, pMoneyInfoNodeHead, pReturnsInfo, cNum, cPwd);
		switch (nResult)
		{
			case NOTFINDCARD:
			case NOTMATCH:
			{
				cout << "该卡不存在或卡信息不存在，无法退费！" << endl;
				break;
			}
			case INVALID:
			{
				cout << "该卡已注销，无法退费！" << endl;
				break;
			}
			case NOTENOUGHMONEY:
			{
				cout << "卡余额不足，无法退费！" << endl;
				return;
			}
			case SUCCESS:
			{
				timeToString(pReturnsInfo->tReturnsTime, cReturnsTime);
				cout << "卡    号: \t" << cNum << endl;
				cout << "退费金额: \t" << pReturnsInfo->cMoney << endl;
				cout << "余    额: \t" << pReturnsInfo->cBalance << endl;
				cout << "退费时间：\t" << cReturnsTime << endl<<endl;
			}
		}
	}
	else
	{
		cout << "卡号,密码或金额输入错误，无法充值！" << endl;
	}

	delete pReturnsInfo;

}

void invalid(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead)
{
	int nCardIndex = 0;
	float tempMoney;
	string cNumber;
	string cPwd;

	if (inputNumPwd(cNumber, cPwd))
	{
		char cInvalidTime[TIMELENGTH] = { 0 };
		ReturnsInfo* pReturnsInfo = new ReturnsInfo;
		Card* pCard = cardIsExist(cNumber, nCardIndex, pCardNodeHead);

		if (strcmp(pCard->cPassword, cPwd.c_str()) != 0)
		{
			cout<<"卡号密码不匹配，注销失败！"<<endl;//密码不匹配
			return;
		}
		if (pCard->cStatus == INVALID)
		{
			cout<<"该卡已注销，不能重复注销！"<<endl;//卡已经注销
			return;
		}
		if (pCard->cStatus == USING)
		{
			cout << "该卡正在上机，无法注销！" << endl;
			return;
		}
		if (pCard != NULL)
		{
			if (pCard->cBalance >= 0)
			{
				tempMoney = pCard->cBalance;
				returns(pCardNodeHead, ppMoneyInfoNodeHead, pReturnsInfo, cNumber, cPwd);
			}
			else
			{
				tempMoney = 0;
			}

			pCard->cBalance = 0;
			pCard->cStatus = INVALID;
			pCard->cLast = time(NULL);

			if (updateCard(pCard, CARDPATH, nCardIndex))
			{
				cout << "注销卡成功！" << endl;
			}

			timeToString(pCard->cLast, cInvalidTime);

			//注销卡信息显示
			cout << "注销卡信息如下：" << endl;
			cout << "卡号\t" << "退款金额\t" << "注销卡时间" << endl;
			cout << pCard->cNumber<<"\t" << tempMoney <<"\t\t"<< cInvalidTime << endl<<endl;

		}
		else
		{
			cout<<"该卡不存在或卡信息不存在，注销失败！"<<endl;
			return;
		}
		delete pReturnsInfo;
	}
	else
	{
		cout << "卡号或密码错误，注销失败！" << endl;
		return;
	}


}

void queryStats(BillingNode* pBillingNodeHead, MoneyInfoNode* pMoneyInfoNodeHead)
{
	string cNumber;
	string input;
	while (true)
	{
		cout << "******查询统计******\n";
		cout << "\t1.个人消费记录\n" << "\t2.某时间段内所有上机下机消费记录\n" << "\t3.月充值退费记录\n" << "\t4.退出" << endl;
		cout << "请输入菜单选项编号：";
		cin >> input;
		cin.clear();
		cin.sync();

		if (input == "1")
		{
			UserBIlling(pBillingNodeHead);
		}
		else if (input == "2")
		{
			TimeBIlling(pBillingNodeHead);
		}
		else if (input == "3")
		{
			Revenue(pMoneyInfoNodeHead);
		}
		else if (input == "4")
		{
			break;
		}
	}
}

void cleanData(CardNode* pCardNodeHead)
{
	CardNode *pCardNode;

	while (pCardNodeHead != NULL)
	{
		pCardNode = pCardNodeHead; 
		pCardNodeHead = pCardNodeHead->next;    
		delete pCardNode;
	}
}