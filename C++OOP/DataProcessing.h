#pragma once
//����й����ݴ���ĺ���
#include<iostream>
#include"model.h"
using namespace std;

CardNode* CardListInit(const string CardFilename);//��ʼ������Ϣ����

BillingNode* BillingListInit(const string billingFilename);//��ʼ���Ʒ���Ϣ����

MoneyInfoNode* moneyListInit(const string moneyFilename);//��ʼ����Ϣ����ֵ�˷�������

Card* cardIsExist(string strNo, int &nCardIndex, CardNode* const pCardNodeHead);//�жϿ�Ƭ�Ƿ����

Billing* billingIsExit(string CardNumber, int& nBillingIndex, BillingNode *pBillingNodeHead);//�жϸüƷѼ�¼�Ƿ����

bool saveCard(const Card* pCard, const string CardPath);//����׷��ģʽ�ѿ�����Ϣд���ļ�

bool saveBilling(const Billing* pbilling, const string pPath);//����Ʒ���Ϣ���ļ���

bool saveMoney(const MoneyInfo* pMoneyInfo, const string pPath);//�����ֵ�˷Ѽ�¼���ļ���

bool updateCard(const Card* pCard, const string nPath, int nCardIndex);//���¿���Ϣд�뵽�ļ���

bool updateBilling(const Billing* pBilling, const string nPath, int nBillingIndex);//���¼Ʒ���Ϣ�ļ���

double getAmount(time_t cStart);//�����ϻ�ʱ�䣬�������ѽ�� 