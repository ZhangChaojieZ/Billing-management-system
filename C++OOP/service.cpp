
#include<iostream>
#include<string>
//#include<vector>
#include"DataProcessing.h"
#include"menu.h"
//#include"VectorCard.h"
#include"cardList.h"
#include"global.h"
#include"model.h"
#include"billList.h"
#include"moneyList.h"
#include"tool.h"
#include"queryStats.h"
using namespace std;

//void addCard(vector<Card>& vec)//��ӿ�
//{
//	string CardNumber;
//	string CardPwd;
//	float CardMoney;
//	if (inputNumPwdMon(CardNumber,CardPwd,CardMoney))
//	{
//		cout << "���ţ�" << CardNumber << endl;
//		cout << "���룺" << CardPwd << endl;
//		cout << "��" << CardMoney << endl;
//
//		int Result;
//		Result = addnewCard(CardNumber, CardPwd, CardMoney, vec);
//		if (Result == FINDCARD)
//			cout << "�ÿ��Ѵ��ڣ���ӿ�ʧ�ܣ�" << endl;
//		else if (Result == SUCCESS)
//			cout << "��ӿ��ɹ���" << endl;
//		else
//			cout << "�������"<<endl;
//	}	
//	else
//		cout << "��Ϣ���������ӿ�ʧ�ܣ�" << endl;
//}
//
//void queryCard(vector<Card>& vec)//��ѯ��
//{
//	displayCard(vec);
//}

void addCard(CardNode** ppCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead)
{
	string CardNumber;//����
	string CardPwd;//����
	float CardMoney;//��ֵ���
	char addcardTime[TIMELENGTH] = { 0 };//����ʱ��
	time_t tempTime;
	RechargeInfo* pRechargeInfo=new RechargeInfo;

	//CardNode* pCardNode = *ppCardNodeHead;

	if (inputNumPwdMon(CardNumber, CardPwd, CardMoney)) 
	{
		int nResult = addNewCard(CardNumber, CardPwd, CardMoney, ppCardNodeHead);
		switch (nResult)
		{
			case FINDCARD:
			{    
				cout << endl << endl << "����" << CardNumber << "���Ѿ����ڣ������ ��ʧ�ܣ�" << endl << endl; 
				break;           
			}             
			case SUCCESS:
			{                
				tempTime=time(NULL);
				timeToString(tempTime, addcardTime);
				cout << endl << endl << "����¿��ɹ�!" << endl << endl; 
				cout << "�¿����ţ�" << CardNumber << endl;
				cout << "�¿���" << CardMoney << endl; 
				cout << "����ʱ�䣺" << addcardTime<<endl;

				addNewMoney(*ppCardNodeHead, ppMoneyInfoNodeHead, pRechargeInfo, CardNumber, CardPwd, CardMoney);	//���ӿ�������һ����ֵ��¼			

				break;         
			}          
			default: 
			{              
				cout << endl << endl << "ϵͳ����!" << endl << endl;
				break;         
			}
		}
	}
	else
	{
		cout << endl << endl << "����ġ����ţ����룬������Ϣ��ʽ������Ҫ�� ��ӿ�ʧ��!" << endl << endl;
	}
	delete pRechargeInfo;
}

void queryCard(CardNode* pCardNodeHead) 
{
	displayCard(pCardNodeHead);
}

void ShangJi(CardNode* pCardNodeHead, BillingNode** BillingNodeHead)
{
	string cNum;
	string cPwd;
	LoginInfo* pInfo = new LoginInfo;//�ϻ���Ϣ��������ʾ
	char cTime[TIMELENGTH] = { 0 };
	if (inputNumPwd(cNum, cPwd))
	{
		cout << endl << "*******�ϻ���Ϣ����******" << endl;

		//�����ϻ��������ʾ��ͬ��Ϣ
		int cResult = Login(cNum, cPwd, pInfo, pCardNodeHead, BillingNodeHead);
		switch (cResult)
		{
		case NOTFINDCARD:
		case NOTMATCH:
		{
			cout << endl << endl << "�������ڣ�����Ϣ���ԣ������ϻ�" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			timeToString(pInfo->cStart, cTime);//�ϻ�ʱ��ת��
			cout << endl;
			cout << "��    �ţ�\t" << cNum << endl;
			cout << "��    �\t" << pInfo->cBalance << endl;
			cout << "�ϻ�ʱ�䣺\t" << cTime << endl;
			break;
		}
		case USING:
		{
			cout << endl << "�ÿ�����ʹ�ã������ظ��ϻ���" << endl;
			break;
		}
		case NOTENOUGHMONEY:
		{
			cout << endl << "�����㣬�����ϻ���" << endl;
			break;
		}
		case INVALID:
		{
			cout << "�ÿ��Ѿ�ע���������ϻ���" << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else
	{
		cout << endl << endl << "���Ż��������ʽ����ȷ���ϻ�ʧ�ܣ�" << endl << endl;
	}
	delete pInfo;
}

void XiaJi(CardNode* pCardNodeHead, BillingNode* pBillingNodeHead)
{
	string CardNumber;
	string CardPwd;

	SettleInfo* pInfo = new SettleInfo; // �»���Ϣ
	char aStartTime[TIMELENGTH] = { 0 };  // �ϻ�ʱ�� 
	char aEndTime[TIMELENGTH] = { 0 };    // �»�ʱ�� 

	if (inputNumPwd(CardNumber, CardPwd)) {
		cout << "----------�»���Ϣ����----------\n\n";

		int nResult = settle(CardNumber, CardPwd, pInfo, pCardNodeHead, pBillingNodeHead);
		switch (nResult)
		{
		case NOTFINDCARD:
		case NOTMATCH:
		{
			cout << endl << endl << "�������ڣ�����Ϣ���ԣ��»�ʧ�ܣ�" << endl << endl;
			break;
		}
		case SUCCESS:
		{
			timeToString(pInfo->tStart, aStartTime);
			timeToString(pInfo->tEnd, aEndTime);

			cout << endl;
			cout << "��    ��: \t" << CardNumber << endl;
			cout << "��    ��: \t" << pInfo->cAmount << endl;
			cout << "��    ��: \t" << pInfo->cBalance << endl;
			cout << "�ϻ�ʱ�䣺\t" << aStartTime << endl;
			cout << "�»�ʱ�䣺\t" << aEndTime << endl;

			break;
		}
		case UNUSE:
		{
			cout << endl << endl << "�ÿ�û���ϻ���" << endl << endl;
			break;
		}
		case NOTENOUGHMONEY:
		{
			cout << endl << endl << "�����㣬���ȳ�ֵ���»���" << endl << endl;
			break;
		}
		default:
		{
			break;
		}
		}
	}
	else
	{
		cout << endl << endl << "���Ż��������ʽ����ȷ���»�ʧ��!" << endl << endl;
	}

	delete pInfo;

}

void addMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead)
{
	string cNum;
	string cPwd;
	float cMoney;//��ֵ���
	RechargeInfo* pRechargeInfo = new RechargeInfo;//��ֵ��Ϣ�ṹ�壬������ʾ
	char cRechargeTime[TIMELENGTH] = { 0 };//��ֵʱ��

	if (inputNumPwdMon(cNum,cPwd,cMoney))
	{
		cout << "******��ֵ��Ϣ����******" << endl<<endl;
		int nResult = addNewMoney(pCardNodeHead, pMoneyInfoNodeHead, pRechargeInfo,cNum, cPwd,cMoney);
		switch(nResult)
		{
			case NOTFINDCARD:
			case NOTMATCH:
			{
				cout << "�ÿ������ڻ���Ϣ�����ڣ��޷���ֵ��" << endl;
				break;
			}
			case INVALID:
			{
				cout << "�ÿ���ע�����޷���ֵ��" << endl;
				break; 
			}
			case SUCCESS:
			{
				timeToString(pRechargeInfo->tRechargeTime, cRechargeTime);

				cout << endl;
				cout << "��    ��: \t" << cNum << endl;
				cout << "��ֵ���: \t" << pRechargeInfo->cMoney << endl;
				cout << "��    ��: \t" << pRechargeInfo->cBalance << endl;
				cout << "��ֵʱ�䣺\t" << cRechargeTime << endl<<endl;
			}
		}
	}
	else
	{
		cout << "����,���������������޷���ֵ��" << endl;
	}

	delete pRechargeInfo;

}

void backMoney(CardNode* pCardNodeHead, MoneyInfoNode** pMoneyInfoNodeHead)
{
	string cNum;
	string cPwd;
	ReturnsInfo* pReturnsInfo = new ReturnsInfo;//��ֵ��Ϣ�ṹ�壬������ʾ
	char cReturnsTime[TIMELENGTH] = { 0 };//��ֵʱ��

	if (inputNumPwd(cNum, cPwd))
	{
		cout << "******�˷���Ϣ����******" << endl <<endl;
		int nResult = returns(pCardNodeHead, pMoneyInfoNodeHead, pReturnsInfo, cNum, cPwd);
		switch (nResult)
		{
			case NOTFINDCARD:
			case NOTMATCH:
			{
				cout << "�ÿ������ڻ���Ϣ�����ڣ��޷��˷ѣ�" << endl;
				break;
			}
			case INVALID:
			{
				cout << "�ÿ���ע�����޷��˷ѣ�" << endl;
				break;
			}
			case NOTENOUGHMONEY:
			{
				cout << "�����㣬�޷��˷ѣ�" << endl;
				return;
			}
			case SUCCESS:
			{
				timeToString(pReturnsInfo->tReturnsTime, cReturnsTime);
				cout << "��    ��: \t" << cNum << endl;
				cout << "�˷ѽ��: \t" << pReturnsInfo->cMoney << endl;
				cout << "��    ��: \t" << pReturnsInfo->cBalance << endl;
				cout << "�˷�ʱ�䣺\t" << cReturnsTime << endl<<endl;
			}
		}
	}
	else
	{
		cout << "����,���������������޷���ֵ��" << endl;
	}

	delete pReturnsInfo;

}

void invalid(CardNode* pCardNodeHead, MoneyInfoNode** ppMoneyInfoNodeHead)
{
	int nCardIndex = 0;
	float tempMoney;
	string cNumber;
	string cPwd;

	if (inputNumPwd(cNumber, cPwd))
	{
		char cInvalidTime[TIMELENGTH] = { 0 };
		ReturnsInfo* pReturnsInfo = new ReturnsInfo;
		Card* pCard = cardIsExist(cNumber, nCardIndex, pCardNodeHead);

		if (strcmp(pCard->cPassword, cPwd.c_str()) != 0)
		{
			cout<<"�������벻ƥ�䣬ע��ʧ�ܣ�"<<endl;//���벻ƥ��
			return;
		}
		if (pCard->cStatus == INVALID)
		{
			cout<<"�ÿ���ע���������ظ�ע����"<<endl;//���Ѿ�ע��
			return;
		}
		if (pCard->cStatus == USING)
		{
			cout << "�ÿ������ϻ����޷�ע����" << endl;
			return;
		}
		if (pCard != NULL)
		{
			if (pCard->cBalance >= 0)
			{
				tempMoney = pCard->cBalance;
				returns(pCardNodeHead, ppMoneyInfoNodeHead, pReturnsInfo, cNumber, cPwd);
			}
			else
			{
				tempMoney = 0;
			}

			pCard->cBalance = 0;
			pCard->cStatus = INVALID;
			pCard->cLast = time(NULL);

			if (updateCard(pCard, CARDPATH, nCardIndex))
			{
				cout << "ע�����ɹ���" << endl;
			}

			timeToString(pCard->cLast, cInvalidTime);

			//ע������Ϣ��ʾ
			cout << "ע������Ϣ���£�" << endl;
			cout << "����\t" << "�˿���\t" << "ע����ʱ��" << endl;
			cout << pCard->cNumber<<"\t" << tempMoney <<"\t\t"<< cInvalidTime << endl<<endl;

		}
		else
		{
			cout<<"�ÿ������ڻ���Ϣ�����ڣ�ע��ʧ�ܣ�"<<endl;
			return;
		}
		delete pReturnsInfo;
	}
	else
	{
		cout << "���Ż��������ע��ʧ�ܣ�" << endl;
		return;
	}


}

void queryStats(BillingNode* pBillingNodeHead, MoneyInfoNode* pMoneyInfoNodeHead)
{
	string cNumber;
	string input;
	while (true)
	{
		cout << "******��ѯͳ��******\n";
		cout << "\t1.�������Ѽ�¼\n" << "\t2.ĳʱ����������ϻ��»����Ѽ�¼\n" << "\t3.�³�ֵ�˷Ѽ�¼\n" << "\t4.�˳�" << endl;
		cout << "������˵�ѡ���ţ�";
		cin >> input;
		cin.clear();
		cin.sync();

		if (input == "1")
		{
			UserBIlling(pBillingNodeHead);
		}
		else if (input == "2")
		{
			TimeBIlling(pBillingNodeHead);
		}
		else if (input == "3")
		{
			Revenue(pMoneyInfoNodeHead);
		}
		else if (input == "4")
		{
			break;
		}
	}
}

void cleanData(CardNode* pCardNodeHead)
{
	CardNode *pCardNode;

	while (pCardNodeHead != NULL)
	{
		pCardNode = pCardNodeHead; 
		pCardNodeHead = pCardNodeHead->next;    
		delete pCardNode;
	}
}