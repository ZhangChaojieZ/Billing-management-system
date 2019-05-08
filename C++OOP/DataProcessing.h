#pragma once
//存放有关数据处理的函数
#include<iostream>
#include"model.h"
using namespace std;

CardNode* CardListInit(const string CardFilename);//初始化卡信息链表

BillingNode* BillingListInit(const string billingFilename);//初始化计费信息链表

MoneyInfoNode* moneyListInit(const string moneyFilename);//初始化信息到充值退费链表中

Card* cardIsExist(string strNo, int &nCardIndex, CardNode* const pCardNodeHead);//判断卡片是否存在

Billing* billingIsExit(string CardNumber, int& nBillingIndex, BillingNode *pBillingNodeHead);//判断该计费记录是否存在

bool saveCard(const Card* pCard, const string CardPath);//采用追加模式把卡的信息写入文件

bool saveBilling(const Billing* pbilling, const string pPath);//保存计费信息到文件中

bool saveMoney(const MoneyInfo* pMoneyInfo, const string pPath);//保存充值退费记录到文件中

bool updateCard(const Card* pCard, const string nPath, int nCardIndex);//更新卡信息写入到文件中

bool updateBilling(const Billing* pBilling, const string nPath, int nBillingIndex);//更新计费信息文件中

double getAmount(time_t cStart);//根据上机时间，计算消费金额 