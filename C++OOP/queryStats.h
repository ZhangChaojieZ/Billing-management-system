#pragma once
#ifndef QUERYSTATS_H
#define QUERYSTATS_H

#include<iostream>
#include"model.h"
#include"menu.h"
#include"cardList.h"

using namespace std;

bool inputTime(int &cYear, int &cMonth);

void UserBIlling(BillingNode* pBillingNodeHead);//��ѯĳ����ĳһʱ����ڵ�������Ϣ��Ϣ

void TimeBIlling(BillingNode* pBillingNodeHead);//��ѯĳһʱ����ڵ����Ѽ�¼

void Revenue(MoneyInfoNode* pMoneyInfoNodeHead);//��ѯÿ��Ӫҵ��

#endif // !QUERYSTATS_H
