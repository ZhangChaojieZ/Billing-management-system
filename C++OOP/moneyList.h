#pragma once
#ifndef MONEYLIST_H
#define MONEYLIST_H
#include"model.h"
using namespace std;

int addNewMoney(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead, RechargeInfo* pRechargeInfo, string cNumber, string cPwd, float cMoney);//��ֵ

int returns(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead, ReturnsInfo* pReturnInfo, string cNumber, string cPwd);//�˷�

#endif // !MONEYLIST_H