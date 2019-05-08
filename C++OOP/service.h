#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include<iostream>
//#include<vector>
#include"model.h"
using namespace std;

//存放要实现功能的主函数

//void addCard(vector<Card>& vec);//添加卡
//void queryCard(vector<Card>& vec);//查询卡

void addCard(CardNode** ppCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead);//添加卡
void queryCard(CardNode* pCardNodeHead);//查询卡
void ShangJi(CardNode* pCardNodeHead, BillingNode** BillingNodeHead);//上机
void XiaJi(CardNode* pCardNodeHead, BillingNode* pBillingNodeHead);//下机
void addMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead);//充值
void backMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead);//退费
void invalid(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead);//注销卡
void queryStats(BillingNode* pBillingNodeHead, MoneyInfoNode* pMoneyInfoNodeHead);
void cleanData(CardNode* pCardNodeHead);//节点的删除

#endif // !SERVICE_H