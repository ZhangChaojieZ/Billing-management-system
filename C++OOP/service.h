#pragma once
#ifndef SERVICE_H
#define SERVICE_H

#include<iostream>
//#include<vector>
#include"model.h"
using namespace std;

//���Ҫʵ�ֹ��ܵ�������

//void addCard(vector<Card>& vec);//��ӿ�
//void queryCard(vector<Card>& vec);//��ѯ��

void addCard(CardNode** ppCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead);//��ӿ�
void queryCard(CardNode* pCardNodeHead);//��ѯ��
void ShangJi(CardNode* pCardNodeHead, BillingNode** BillingNodeHead);//�ϻ�
void XiaJi(CardNode* pCardNodeHead, BillingNode* pBillingNodeHead);//�»�
void addMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead);//��ֵ
void backMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead);//�˷�
void invalid(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead);//ע����
void queryStats(BillingNode* pBillingNodeHead, MoneyInfoNode* pMoneyInfoNodeHead);
void cleanData(CardNode* pCardNodeHead);//�ڵ��ɾ��

#endif // !SERVICE_H