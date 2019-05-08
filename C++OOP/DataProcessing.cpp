#include<iostream>
#include<fstream>
#include<time.h>
#include"model.h"
#include"global.h"
using namespace std;

CardNode* CardListInit(const string CardFilename)
{
	ifstream cardfile(CardFilename);
	CardNode *pCardNode, *pCardNodeHead, *pCardNodeTail;
	Card card;

	if (!cardfile.is_open())
	{
		return NULL;
	}

	pCardNodeHead = NULL;
	pCardNodeTail = NULL;

	while (true)
	{
		cardfile.read((char*)&card, sizeof(Card));

		if (cardfile.eof())
		{
			break;
		}

		pCardNode = new CardNode;
		pCardNode->data = card;

		if (pCardNodeHead == NULL)
		{
			pCardNodeHead = pCardNode;
			pCardNodeTail = pCardNode;
		}
		else
		{
			pCardNodeTail->next = pCardNode;
			pCardNodeTail = pCardNode;
		}
	}

	pCardNodeTail->next = NULL;//�˴��ļ�Ϊ��ʱ���ᱨ����δ���,�ѽ�����˴�����ȱʡ����Ȼ��ʼ����β��Ϊ��


	cardfile.close();

	return pCardNodeHead;

}

BillingNode* BillingListInit(const string billingFilename)
{
	ifstream billingfile(billingFilename);

	BillingNode *pBillingNode, *pBillingNodeHead, *pBillingNodeTail;
	Billing billing;

	if (!billingfile.is_open())
	{
		return NULL;
	}

	pBillingNodeHead = NULL;
	pBillingNodeTail = NULL;

	while (true)
	{
		billingfile.read((char*)&billing, sizeof(Billing));
		if (billingfile.eof())
		{
			break;
		}

		pBillingNode = new BillingNode;
		pBillingNode->data = billing;

		if (pBillingNodeHead == NULL)
		{
			pBillingNodeHead = pBillingNode;
			pBillingNodeTail = pBillingNode;
		}
		else
		{
			pBillingNodeTail->next = pBillingNode;
			pBillingNodeTail = pBillingNode;
		}
	}

	pBillingNodeTail->next = NULL;//�˴��ļ�Ϊ��ʱ���ᱨ����δ���,�ѽ��

	billingfile.close();
	return pBillingNodeHead;

}

MoneyInfoNode* moneyListInit(const string moneyFilename)
{
	ifstream moneyfile(moneyFilename);

	MoneyInfoNode *pMoneyInfoNode, *pMoneyInfoNodeHead, *pMoneyInfoNodeTail;
	MoneyInfo moneyInfo;

	if (!moneyfile.is_open())
	{
		return NULL;
	}

	pMoneyInfoNodeHead = NULL;
	pMoneyInfoNodeTail = NULL;

	while (true)
	{
		moneyfile.read((char*)&moneyInfo, sizeof(MoneyInfo));
		if (moneyfile.eof())
		{
			break;
		}

		pMoneyInfoNode = new MoneyInfoNode;
		pMoneyInfoNode->data = moneyInfo;

		if (pMoneyInfoNodeHead == NULL)
		{
			pMoneyInfoNodeHead = pMoneyInfoNode;
			pMoneyInfoNodeTail = pMoneyInfoNode;
		}
		else
		{
			pMoneyInfoNodeTail->next = pMoneyInfoNode;
			pMoneyInfoNodeTail = pMoneyInfoNode;
		}
	}

	pMoneyInfoNodeTail->next = NULL;//�˴��ļ�Ϊ��ʱ���ᱨ���ѽ��

	moneyfile.close();
	return pMoneyInfoNodeHead;

}

Card* cardIsExist(string cNum, int &nCardIndex, CardNode* const pCardNodeHead)
{
	CardNode *pCardNode = pCardNodeHead;

	nCardIndex = 0;
	while (pCardNode != NULL)
	{
		if (strcmp(pCardNode->data.cNumber, cNum.c_str()) == 0)//c_str() �� char* ��ʽ���� string �ں��ַ���
		{
			return &(pCardNode->data);
		}
		pCardNode = pCardNode->next;
		nCardIndex++;
	}

	return NULL;
}

Billing* billingIsExit(string CardNumber, int& nBillingIndex, BillingNode *pBillingNodeHead)
{
	BillingNode *pBillingNode = pBillingNodeHead;

	nBillingIndex = 0;
	while (pBillingNode != NULL)
	{
		if (strcmp(pBillingNode->data.cNumber, CardNumber.c_str()) == 0 && pBillingNode->data.cStatus == NOSETTLEMENT) //�ÿ����Ѽ�¼���ڣ���δ����
		{
			return &(pBillingNode->data);
		}
		pBillingNode = pBillingNode->next;
		nBillingIndex++;
	}

	return NULL;
}

bool saveCard(const Card* pCard, const string CardPath)
{
	ofstream ofile(CardPath, ios::binary | ios::app);

	ofile.write((char*)pCard, sizeof(Card));
	ofile.close();

	return true;
}

bool saveBilling(const Billing* pbilling, const string pPath)
{
	ofstream ofile(pPath, ios::binary | ios::app);

	ofile.write((char*)pbilling, sizeof(Billing));
	ofile.close();

	return true;
}

bool saveMoney(const MoneyInfo* pMoneyInfo, const string pPath)
{
	ofstream ofile(pPath, ios::binary | ios::app);

	ofile.write((char*)pMoneyInfo, sizeof(MoneyInfo));
	ofile.close();

	return true;
}

bool updateCard(const Card* pCard, const string nPath, int nCardIndex)
{
	fstream ofile;
	ofile.open(nPath, ios_base::in | ios_base::out);//���ָ����·��û�а������ļ���Ҳ���ᴴ��
	ofile.seekp(sizeof(Card)*nCardIndex, ios_base::beg);
	ofile.write((char*)pCard, sizeof(Card));
	ofile.close();

	return true;
}

bool updateBilling(const Billing* pBilling, const string nPath, int nBillingIndex)
{
	fstream ofile;
	ofile.open(nPath, ios_base::in | ios_base::out);//���ָ����·��û�а������ļ���Ҳ���ᴴ��
	ofile.seekp(sizeof(Billing)*nBillingIndex, ios_base::beg);//ofile.seekp(sizeof(Card)*nBillingIndex, ios_base::beg);
	ofile.write((char*)pBilling, sizeof(Billing));
	ofile.close();

	return true;
}

double getAmount(time_t cStart)
{
	double dbAmount = 0;// ���ѽ��   	 
	int nCount = 0;// �ϻ���ʱ�䵥Ԫ����ÿ����Ԫ15����     
	int nSec = 0;// ����ʱ��(��λ����)            	  
	int nMinutes = 0;// ����ʱ��(��λ������)            	 
	time_t tEnd = time(NULL);  // ����ʱ��Ϊ��ǰʱ�� 

	nSec = (int)(tEnd - cStart);// ��������ʱ�� 
	nMinutes = nSec / 60;

	if (nMinutes % UNIT == 0)// �������ѵ�ʱ�䵥Ԫ��
	{
		nCount = nMinutes / UNIT;
	}
	else
	{
		nCount = nMinutes / UNIT + 1;
	}

	if (nCount == 0)
		nCount = 1;

	dbAmount = nCount * CHARGE;// �������ѽ�� 

	return dbAmount;
}