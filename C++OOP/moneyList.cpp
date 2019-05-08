#include<iostream>
#include<fstream>
#include<time.h>
#include"DataProcessing.h"
#include"cardList.h"
#include"model.h"
#include"global.h"
#include"moneyList.h"
using namespace std;

int addNewMoney(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead, RechargeInfo* pRechargeInfo,string cNumber, string cPwd, float cMoney)
{
	MoneyInfo pMoneyInfo;
	int nCardIndex = 0;
	Card* pCard = cardIsExist(cNumber, nCardIndex, pCardNodeHead);

	if (pCard == NULL)
	{
		return NOTFINDCARD;//未找到卡
	}
	if (strcmp(pCard->cPassword, cPwd.c_str()) != 0)
	{
		return NOTMATCH;//密码不匹配
	}
	if (pCard->cStatus == INVALID)
	{
		return INVALID;//卡已经注销
	}

	//如果可以充值，更新卡信息
	pCard->cTotalMoney += cMoney;//累计金额增加
	pCard->cBalance += cMoney;//余额增加

	//更新卡文件中的信息
	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "信息修改成功！"<<endl;
	}

	//添加充值退费记录
	strcpy(pMoneyInfo.cNumber, cNumber.c_str());//充值退费卡号
	pMoneyInfo.cMoney = cMoney;//充值退费金额
	pMoneyInfo.cStatus = 0;//充值退费状态,0-充值，1-退费
	pMoneyInfo.tStart = time(NULL);//充值退费时间

	if (saveMoney(&pMoneyInfo, MONEYPATH))
	{
		cout << "充值信息保存成功" << endl;
	}

	//在充值退费链表中添加信息
	MoneyInfoNode* pMoneyInfoNode = new MoneyInfoNode;
	pMoneyInfoNode->data = pMoneyInfo;

	MoneyInfoNode* pMoneyInfogNodeTail = *ppMoneyInfoNodeHead;

	if (*ppMoneyInfoNodeHead == NULL)
	{
		*ppMoneyInfoNodeHead = pMoneyInfoNode;
		pMoneyInfogNodeTail = pMoneyInfoNode;
	}
	else
	{
		while (pMoneyInfogNodeTail->next != NULL)
		{
			pMoneyInfogNodeTail = pMoneyInfogNodeTail->next;
		}
		pMoneyInfogNodeTail->next = pMoneyInfoNode;
		pMoneyInfogNodeTail = pMoneyInfoNode;
	}

	pMoneyInfogNodeTail->next = NULL;

	//组装充值信息
	strcpy(pRechargeInfo->cNumber, cNumber.c_str());
	pRechargeInfo->cMoney = cMoney;
	pRechargeInfo->cBalance = pCard->cBalance;
	pRechargeInfo->tRechargeTime = time(NULL);

	return SUCCESS;

}

int returns(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead, ReturnsInfo* pReturnsInfo, string cNumber, string cPwd)
{
	MoneyInfo pMoneyInfo;
	int nCardIndex = 0;
	Card* pCard = cardIsExist(cNumber, nCardIndex, pCardNodeHead);

	if (pCard == NULL)
	{
		return NOTFINDCARD;//未找到卡
	}
	if (strcmp(pCard->cPassword, cPwd.c_str()) != 0)
	{
		return NOTMATCH;//密码不匹配
	}
	if (pCard->cStatus == INVALID)
	{
		return INVALID;//卡已经注销
	}
	if (pCard->cBalance == 0)
	{
		return NOTENOUGHMONEY;//余额不足
	}

	float tempMoney = pCard->cBalance;//暂存卡内余额
	//如果可以退费，更新卡信息
	pCard->cBalance = 0;

	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "更新卡信息成功！" << endl;
	}

	//添加充值退费记录
	strcpy(pMoneyInfo.cNumber, cNumber.c_str());//充值退费卡号
	pMoneyInfo.cMoney = tempMoney;//充值退费金额
	pMoneyInfo.cStatus = 1;//充值退费状态,0-充值，1-退费
	pMoneyInfo.tStart = time(NULL);//充值退费时间

	if (saveMoney(&pMoneyInfo, MONEYPATH))
	{
		cout << "退费信息保存成功" << endl;
	}

	//在充值退费链表中添加信息
	MoneyInfoNode* pMoneyInfoNode = new MoneyInfoNode;
	pMoneyInfoNode->data = pMoneyInfo;

	MoneyInfoNode* pMoneyInfogNodeTail = *ppMoneyInfoNodeHead;

	if (*ppMoneyInfoNodeHead == NULL)
	{
		*ppMoneyInfoNodeHead = pMoneyInfoNode;
		pMoneyInfogNodeTail = pMoneyInfoNode;
	}
	else
	{
		while (pMoneyInfogNodeTail->next != NULL)
		{
			pMoneyInfogNodeTail = pMoneyInfogNodeTail->next;
		}
		pMoneyInfogNodeTail->next = pMoneyInfoNode;
		pMoneyInfogNodeTail = pMoneyInfoNode;
	}
	pMoneyInfogNodeTail->next = NULL;

	//组装退费信息
	strcpy(pReturnsInfo->cNumber, cNumber.c_str());
	pReturnsInfo->cMoney = tempMoney;
	pReturnsInfo->cBalance = pCard->cBalance;
	pReturnsInfo->tReturnsTime = time(NULL);

	return SUCCESS;

}
