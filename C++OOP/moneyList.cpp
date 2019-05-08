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
		return NOTFINDCARD;//δ�ҵ���
	}
	if (strcmp(pCard->cPassword, cPwd.c_str()) != 0)
	{
		return NOTMATCH;//���벻ƥ��
	}
	if (pCard->cStatus == INVALID)
	{
		return INVALID;//���Ѿ�ע��
	}

	//������Գ�ֵ�����¿���Ϣ
	pCard->cTotalMoney += cMoney;//�ۼƽ������
	pCard->cBalance += cMoney;//�������

	//���¿��ļ��е���Ϣ
	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "��Ϣ�޸ĳɹ���"<<endl;
	}

	//��ӳ�ֵ�˷Ѽ�¼
	strcpy(pMoneyInfo.cNumber, cNumber.c_str());//��ֵ�˷ѿ���
	pMoneyInfo.cMoney = cMoney;//��ֵ�˷ѽ��
	pMoneyInfo.cStatus = 0;//��ֵ�˷�״̬,0-��ֵ��1-�˷�
	pMoneyInfo.tStart = time(NULL);//��ֵ�˷�ʱ��

	if (saveMoney(&pMoneyInfo, MONEYPATH))
	{
		cout << "��ֵ��Ϣ����ɹ�" << endl;
	}

	//�ڳ�ֵ�˷������������Ϣ
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

	//��װ��ֵ��Ϣ
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
		return NOTFINDCARD;//δ�ҵ���
	}
	if (strcmp(pCard->cPassword, cPwd.c_str()) != 0)
	{
		return NOTMATCH;//���벻ƥ��
	}
	if (pCard->cStatus == INVALID)
	{
		return INVALID;//���Ѿ�ע��
	}
	if (pCard->cBalance == 0)
	{
		return NOTENOUGHMONEY;//����
	}

	float tempMoney = pCard->cBalance;//�ݴ濨�����
	//��������˷ѣ����¿���Ϣ
	pCard->cBalance = 0;

	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "���¿���Ϣ�ɹ���" << endl;
	}

	//��ӳ�ֵ�˷Ѽ�¼
	strcpy(pMoneyInfo.cNumber, cNumber.c_str());//��ֵ�˷ѿ���
	pMoneyInfo.cMoney = tempMoney;//��ֵ�˷ѽ��
	pMoneyInfo.cStatus = 1;//��ֵ�˷�״̬,0-��ֵ��1-�˷�
	pMoneyInfo.tStart = time(NULL);//��ֵ�˷�ʱ��

	if (saveMoney(&pMoneyInfo, MONEYPATH))
	{
		cout << "�˷���Ϣ����ɹ�" << endl;
	}

	//�ڳ�ֵ�˷������������Ϣ
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

	//��װ�˷���Ϣ
	strcpy(pReturnsInfo->cNumber, cNumber.c_str());
	pReturnsInfo->cMoney = tempMoney;
	pReturnsInfo->cBalance = pCard->cBalance;
	pReturnsInfo->tReturnsTime = time(NULL);

	return SUCCESS;

}
