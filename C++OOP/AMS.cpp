#include<iostream>
#include<string>
#include"menu.h"
#include"DataProcessing.h"
#include"model.h"
#include"service.h"
#include"global.h"
//#include<vector>
//#include"VectorCard.h"
#include"cardList.h"
#include"billList.h"
#include"moneyList.h"
using namespace std;



int main()
{
	string input;
	//vector<Card> vec;
	//CardVectorInit(CARDPATH, vec);//��ʼ���ļ��еĿ���Ϣ

	CardNode* pCardNodeHead = NULL;
	pCardNodeHead = CardListInit(CARDPATH);

	BillingNode* pBillingNodeHead = NULL;
	pBillingNodeHead = BillingListInit(BILLINGPATH);

	MoneyInfoNode* pMoneyInfoNodeHead = NULL;
	pMoneyInfoNodeHead = moneyListInit(MONEYPATH);
	
	cout << "**��ӭ����Ʒѹ���ϵͳ**" << endl;	

	while (true) 
	{
		outputMenu();
		cin >> input;
		cin.clear();//���������
		cin.sync();//����cin��ʶ����clear������sync����һ��ʹ�ã���ջ����������ݣ�����Ӱ����һ������
		if (input == "1")//��������ַ�����ȣ�compare��������ֵΪ0���еȲ����á�==������Ϊ����Ƚϵ��ǵ�ַ�Ƿ����
		{
			cout << "******��ӿ�******\n";
			//addCard(vec);
			addCard(&pCardNodeHead,&pMoneyInfoNodeHead);
		}
		else if (input == "2")
		{
			cout << "******��ѯ��******\n";
			//queryCard(vec);
			queryCard(pCardNodeHead);
		}
		else if (input == "3")
		{
			cout << "******�ϻ�*******\n";
			ShangJi(pCardNodeHead,&pBillingNodeHead);
		}
		else if (input == "4")
		{
			cout << "******�»�******\n";
			XiaJi(pCardNodeHead, pBillingNodeHead);
		}
		else if (input == "5")
		{
			cout << "******��ֵ******\n";
			addMoney(pCardNodeHead, &pMoneyInfoNodeHead); 
		}
		else if (input == "6")
		{
			cout << "******�˷�******\n";
			backMoney(pCardNodeHead, &pMoneyInfoNodeHead);
		}
		else if (input == "7")
		{
			queryStats(pBillingNodeHead, pMoneyInfoNodeHead);
		}
		else if (input == "8")
		{
			cout << "******ע����******\n";
			invalid(pCardNodeHead, &pMoneyInfoNodeHead);
		}
		else if (input == "0")
		{
			cleanData(pCardNodeHead);
			cout << "�˳�ϵͳ��ллʹ�ã�";
			break;
		}
		else cout << "����������������룡\n";
	}
	return 0;
}

