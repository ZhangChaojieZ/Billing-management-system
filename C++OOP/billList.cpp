#include<iostream>
#include<fstream>
#include"DataProcessing.h"
#include"global.h"
#include"menu.h"
#include"model.h"
#include"tool.h"
#include"cardList.h"
#include"billList.h"
using namespace std;

int Login(string CardNumber, string CardPwd, LoginInfo* pInfo, CardNode* pCardNodeHead, BillingNode **ppBillingNodeHead)
{
	Billing billing;
	int nCardIndex=0;
	Card* pCard = cardIsExist(CardNumber, nCardIndex, pCardNodeHead);

	if (pCard == NULL)
	{
		return NOTFINDCARD;//δ�ҵ���
	}
	if (strcmp(pCard->cPassword, CardPwd.c_str()) != 0)
	{
		return NOTMATCH;//���벻ƥ��
	}
	if (pCard->cStatus == USING)
	{
		return USING;//�������ϻ�
	}
	if (pCard->cStatus == INVALID)
	{
		return INVALID;//���Ѿ�ע��
	}
	if (pCard->cBalance <= 0)
	{
		return NOTENOUGHMONEY;//������
	}

	//��������ϻ������¿���Ϣ
	pCard->cStatus = USING;//������ʹ��
	pCard->cUseCount++;//ʹ�ô�����1
	pCard->cLast = time(NULL);//���¿����ʹ��ʱ��

	//�����ļ��е���Ϣ
	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "��Ϣ�޸ĳɹ���\n";
	}

	//������Ѽ�¼
	strcpy(billing.cNumber, CardNumber.c_str());//�ϻ�����
	billing.cStart = time(NULL);//�ϻ�ʱ��	
	billing.cEnd = 0;//�»�ʱ��
	billing.cStatus = NOSETTLEMENT;//����״̬��δ����
	billing.cAmount = 0;//���ѽ��

	//�Ƚ��Ʒ���Ϣ���浽�ļ���
	if (saveBilling(&billing, BILLINGPATH))
	{
		cout << "�Ʒ���Ϣ����ɹ���\n";
	}

	//�ڼƷ�����������һ���Ʒ���Ϣ
	BillingNode* pBillingNode = new BillingNode;
	pBillingNode->data = billing;

	BillingNode* pBillingNodeTail = *ppBillingNodeHead;

	if (*ppBillingNodeHead == NULL)
	{
		*ppBillingNodeHead = pBillingNode;
		pBillingNodeTail = pBillingNode;
	}
	else
	{
		while (pBillingNodeTail->next != NULL)
		{
			pBillingNodeTail = pBillingNodeTail->next;
		}
		pBillingNodeTail->next = pBillingNode;
		pBillingNodeTail = pBillingNode;
	}
	pBillingNodeTail->next = NULL;

	//��װ�ϻ���Ϣ
	strcpy(pInfo->cNumber, CardNumber.c_str());
	pInfo->cBalance = pCard->cBalance;
	pInfo->cStart = billing.cStart;

	return SUCCESS;

}

int settle(string CardNumber, string CardPwd, SettleInfo* pInfo, CardNode* const pCardNodeHead, BillingNode* const pBillingNodeHead)
{
	int nCardIndex=0;  
	Card* pCard = cardIsExist(CardNumber, nCardIndex, pCardNodeHead);

	     
	if(pCard == NULL) // δ�ҵ���       
		return NOTFINDCARD; 
	
	if( strcmp(pCard->cPassword, CardPwd.c_str())!=0) // ���벻ƥ��       
		return NOTMATCH; 

	if(pCard->cStatus != USING) // �жϸÿ��Ƿ������ϻ���ֻ�������ϻ������ܽ����»�����  
		return UNUSE; 

	// ���ݿ��ţ���ѯ�Ʒ���Ϣ

	int nBillingIndex=0;     
	Billing* pBilling = billingIsExit(CardNumber, nBillingIndex, pBillingNodeHead); 
	 
	if(pBilling == NULL)// �����ѯ�Ʒ���ϢΪ�գ���ʾ�»�ʧ��  
	{     
		cout << "�Ʒ���ϢΪ��" << endl;  
		return UNUSE;
	} 
		 
	double dbAmount = getAmount(pBilling->cStart); // �������ѽ��		 
	float fBalance = pCard->cBalance - (float)dbAmount;  

	if(fBalance < 0) // ������С�����ѽ����ܽ����»�
	{   
		return NOTENOUGHMONEY; 
	} 

	// ���¿���Ϣ 
	pCard->cBalance = fBalance;// ���
	pCard->cStatus = UNUSE;// ״̬       
	pCard->cLast = time(NULL);// �ϴ�ʹ��ʱ��   
	

	 // �����ļ��еĿ���Ϣ 
	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "���¿���Ϣ�ɹ�" << endl;
	}

	 // ���¼Ʒ���Ϣ  
	pBilling->cAmount = (float)dbAmount;// ���ѽ��  
	pBilling->cStatus = YESSETTLEMENT;// ״̬���ѽ���   
	pBilling->cEnd = time(NULL);// �»�ʱ��    
		 
	 // �����ļ��еļƷ���Ϣ
	if (updateBilling(pBilling, BILLINGPATH, nBillingIndex))
	{
		cout << "���¼Ʒ���Ϣ���" << endl;
	}

	 // ��װ�»���Ϣ  
	strcpy(pInfo->cNumber, CardNumber.c_str());// ����   
	pInfo->cAmount = (float)dbAmount;// ���ѽ��        
	pInfo->cBalance = fBalance;// ���              
	pInfo->tStart = pBilling->cStart;// �ϻ�ʱ��         
	pInfo->tEnd = pBilling->cEnd;//time(NULL);// �»�ʱ��    
	
	return SUCCESS;
}
