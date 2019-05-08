#include<iostream>
#include<fstream>
#include<string>
#include"DataProcessing.h"
#include"model.h"
#include"global.h"
#include"tool.h"
#include"menu.h"
#include"moneyList.h"
using namespace std;

int addNewCard(string cNum, string cPwd, float cMoney, CardNode** ppCardNodeHead)//ָ������ã����ú��������ppCardNodeHeadn��ָ���ݸı�
{
	int nCardIndex = 0;     
	if (cardIsExist(cNum, nCardIndex, *ppCardNodeHead) != NULL)
	{ 
		return FINDCARD;
	}

	Card card;

	strcpy(card.cNumber, cNum.c_str());//��cNum��ֵ����cNumber
	strcpy(card.cPassword, cPwd.c_str());//ͬ��
	card.cBalance = 0;

	// ����¿�ʱ���ۼƽ����ڿ������    
	card.cTotalMoney = card.cBalance;   
	card.cStatus = UNUSE;              // ��״̬  
	card.cUseCount = 0;                // ʹ�ô��� 

	// ����ʱ�䣬���ʹ��ʱ�䶼Ĭ��Ϊ��ǰʱ�� 
	card.cStart = card.cLast = time(NULL);   

	CardNode* pCardNode = new CardNode; 
	pCardNode->data = card;

	CardNode *pCardNodeHead = *ppCardNodeHead; 
	CardNode *pCardNodeTail = *ppCardNodeHead;

	if (pCardNodeHead == NULL)
	{       
		pCardNodeHead = pCardNode;     
		pCardNodeTail = pCardNode; 
		*ppCardNodeHead = pCardNode;  
	}  
	else   
	{      
		pCardNodeTail = pCardNodeHead;     
		while(pCardNodeTail->next != NULL) 
			pCardNodeTail = pCardNodeTail->next;         
		pCardNodeTail->next = pCardNode;  
		pCardNodeTail = pCardNode;   
	} 
		pCardNodeTail->next = NULL;

		saveCard(&card, CARDPATH);

		return SUCCESS;
	
}

void displayCard(CardNode* pCardNodeHead)
{
	string tempNumber;//Ҫ��ѯ�Ŀ���

	if (pCardNodeHead == NULL) //�ж������Ƿ�Ϊ��
	{
		cout << endl << endl << "һ���ϻ�����û�У�" << endl << endl;
		return; 
	}

	//cout << "����\t״̬\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��" << endl;
	if (inputCardNumber(tempNumber))
	{
		cout << "����\t״̬\t\t���\t�ۼ�ʹ��\tʹ�ô���\t�ϴ�ʹ��ʱ��" << endl;
		CardNode* pCur = pCardNodeHead;
		int flag = 0;
		while (pCur != NULL)
		{
			if (strstr(pCur->data.cNumber, tempNumber.c_str()) != NULL)//�쳣
			{
				flag = 1;	
				char aLastTime[TIMELENGTH] = { 0 };
				timeToString((pCur->data).cLast, aLastTime);
				cout << pCur->data.cNumber << "\t";
				if (pCur->data.cStatus == USING)
					cout << "�����ϻ�\t";
				else if (pCur->data.cStatus == UNUSE)
					cout << "δ���ϻ�\t";
				else if (pCur->data.cStatus == INVALID)
					cout << "ע��    \t";
				else
					cout << "����\t";
				cout << pCur->data.cBalance << "\t";
				cout << pCur->data.cTotalMoney << "\t\t" << pCur->data.cUseCount << "\t\t" << aLastTime << endl;
			}

			pCur = pCur->next;		
		}

		if (flag == 0)
		{
			cout << "����ѯ���Ų����ڣ�" << endl;
			return;
		}
	}
	else
	{
		cout << endl << endl << "����ġ����š���ʽ������Ҫ�� ��ѯ��ʧ��!" << endl << endl;
	}

}