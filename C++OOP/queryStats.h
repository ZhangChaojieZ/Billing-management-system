#pragma once
#ifndef QUERYSTATS_H
#define QUERYSTATS_H

#include<iostream>
#include"model.h"
#include"menu.h"
#include"cardList.h"

using namespace std;

bool inputTime(int &cYear, int &cMonth);

void UserBIlling(BillingNode* pBillingNodeHead);//查询某卡在某一时间段内的消费信息信息

void TimeBIlling(BillingNode* pBillingNodeHead);//查询某一时间段内的消费记录

void Revenue(MoneyInfoNode* pMoneyInfoNodeHead);//查询每月营业额

#endif // !QUERYSTATS_H
