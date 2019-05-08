#include<iostream>
#include<string>
#include<time.h>
#include"model.h"
#include"global.h"
#include"menu.h"
//#include"cardList.h"
#include"tool.h"
using namespace std;

bool inputTime(int &cYear, int &cMonth)
{
	char flag = NULL;
	cout << "������Ҫ��ѯ����ݣ�2000~3000����";
	cin >> cYear;
	//cout << endl;
	cout << "������Ҫ��ѯ���·ݣ�1~12����";
	cin >> cMonth;
	cout << endl;

	if (cYear >= 2000 && cYear <= 3000&&cMonth<=12&&cMonth>=1)
		return true;
	else
	{
		cout << "��ݻ��·��������" << endl;
		return false;
	}
		
}

void UserBIlling(BillingNode* pBillingNodeHead)
{
	int startYear=0, startMonth=0;//��ʼʱ��
	int endYear=0, endMonth=0;//��ֹʱ��
	string cNumber;//Ҫ��ѯ�Ŀ���
	struct tm* timeInfo;
	char strTime[TIMELENGTH] = { 0 };//�ϻ�ʱ��
	char endTime[TIMELENGTH] = { 0 };//�»�ʱ��
	int BillingAmount = 0;//��¼����
	float cMoneyAmount = 0;//�ۼ����ѽ��


	if (pBillingNodeHead == NULL)
	{
		cout << "���Ѽ�¼��ϢΪ�գ���ѯ������" << endl;
		return;
	}

	cout << "������Ҫ��ѯ�Ŀ���" << endl;
	if (!inputCardNumber(cNumber))
	{
		cout << "�����������" << endl;
		return;
	}

	cout << "�����뿪ʼʱ��" << endl;
	if (!inputTime(startYear, startMonth))
	{
		cout << "��ʼʱ���������" << endl;
		return;
	}

	cout << "�������ֹʱ��" << endl;
	if (!inputTime(endYear, endMonth))
	{	
		cout << "��ֹʱ���������" << endl;
		return;
	}

	if (startYear < endYear )//��ݲ�ͬ
	{

		cout << "����\t" << "�ϻ�ʱ��\t\t" << "�»�ʱ��\t\t" << "���ѽ��\t" << "����״̬" << endl;

		while (pBillingNodeHead != NULL)
		{
			if (strcmp(pBillingNodeHead->data.cNumber, cNumber.c_str())==0)
			{
				timeInfo = localtime(&pBillingNodeHead->data.cStart);//ת��Ϊtm�ṹ������

				timeToString(pBillingNodeHead->data.cStart, strTime);
				timeToString(pBillingNodeHead->data.cEnd, endTime);

				if ((timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth) || (timeInfo->tm_year + 1900 == endYear && timeInfo->tm_mon + 1 <= endMonth) || (timeInfo->tm_year > startYear&&timeInfo->tm_year < endYear))
				{
					cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
					if (pBillingNodeHead->data.cStatus == 0)
						cout << "�ϻ�δ����" << endl;
					if (pBillingNodeHead->data.cStatus == 1)
						cout << "�ϻ��ѽ���" << endl;
					cMoneyAmount += pBillingNodeHead->data.cAmount;//�ۼ����ѽ��
					BillingAmount++;
				}
			}
	
			pBillingNodeHead = pBillingNodeHead->next;
		}

		if (BillingAmount == 0)
		{
			cout << "�ÿ�û���ڸ�ʱ��������Ѽ�¼��" << endl;
			return;
		}
		else
		{
			cout << "�ۼ����ѽ��Ϊ��" << cMoneyAmount << endl;
		}

	}
	else if (startYear == endYear && startMonth <= endMonth)//�����ͬ�Ƚ��·�
	{
		cout << "����\t" << "�ϻ�ʱ��\t\t" << "�»�ʱ��\t\t" << "���ѽ��\t" << "����״̬" << endl;

		while (pBillingNodeHead != NULL)
		{
			
			if (strcmp(pBillingNodeHead->data.cNumber, cNumber.c_str()) == 0)
			{
				timeInfo = localtime(&pBillingNodeHead->data.cStart);//ת��Ϊtm�ṹ������

				timeToString(pBillingNodeHead->data.cStart, strTime);
				timeToString(pBillingNodeHead->data.cEnd, endTime);

				if (timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth && timeInfo->tm_mon + 1 <= endMonth)
				{
					cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
					
					if (pBillingNodeHead->data.cStatus == 0)
						cout << "�ϻ�δ����" << endl;
					if (pBillingNodeHead->data.cStatus == 1)
						cout << "�ϻ��ѽ���" << endl;
					cMoneyAmount += pBillingNodeHead->data.cAmount;//�ۼ����ѽ��
					BillingAmount++;
				}
			}

			pBillingNodeHead = pBillingNodeHead->next;
		}
		if (BillingAmount == 0)
		{
			cout << "�ÿ�û���ڸ�ʱ��������Ѽ�¼��" << endl;
			return;
		}
		else
		{
			cout << "�ۼ����ѽ��Ϊ��" << cMoneyAmount << endl;
		}
	}
	else
	{
		cout << "ʱ�����벻��ȷ" << endl;
		return;
	}


}

void TimeBIlling(BillingNode* pBillingNodeHead)
{
	int startYear = 0, startMonth = 0;//��ʼʱ��
	int endYear = 0, endMonth = 0;//��ֹʱ��
	struct tm* timeInfo;
	char strTime[TIMELENGTH] = { 0 };//�ϻ�ʱ��
	char endTime[TIMELENGTH] = { 0 };//�»�ʱ��
	int BillingAmount = 0;//��¼����
	float cMoneyAmount = 0;//�ۼ����ѽ��

	if (pBillingNodeHead == NULL)
	{
		cout << "���Ѽ�¼��ϢΪ�գ���ѯ������" << endl;
		return;
	}

	cout << "�����뿪ʼʱ��" << endl;
	if (!inputTime(startYear, startMonth))
	{
		cout << "��ʼʱ���������" << endl;
		return;
	}

	cout << "�������ֹʱ��" << endl;
	if (!inputTime(endYear, endMonth))
	{
		cout << "��ֹʱ���������" << endl;
		return;
	}

	if (startYear < endYear)//��ݲ�ͬ
	{

		cout << "����\t" << "�ϻ�ʱ��\t\t" << "�»�ʱ��\t\t" << "���ѽ��\t" << "����״̬" << endl;

		while (pBillingNodeHead != NULL)
		{

			timeInfo = localtime(&pBillingNodeHead->data.cStart);//ת��Ϊtm�ṹ������

			timeToString(pBillingNodeHead->data.cStart, strTime);
			timeToString(pBillingNodeHead->data.cEnd, endTime);


			if ((timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth) || (timeInfo->tm_year + 1900 == endYear && timeInfo->tm_mon + 1 <= endMonth) || (timeInfo->tm_year > startYear&&timeInfo->tm_year < endYear))
			{
				cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
				if (pBillingNodeHead->data.cStatus == 0)
					cout << "�ϻ�δ����" << endl;
				if (pBillingNodeHead->data.cStatus == 1)
					cout << "�ϻ��ѽ���" << endl;
				cMoneyAmount += pBillingNodeHead->data.cAmount;//�ۼ����ѽ��
				BillingAmount++;
			}

			pBillingNodeHead = pBillingNodeHead->next;
		}

		if (BillingAmount == 0)
		{
			cout << "�ÿ�û���ڸ�ʱ��������Ѽ�¼��" << endl;
			return;
		}
		else
		{
			cout << "�ۼ����ѽ��Ϊ��" << cMoneyAmount << endl;
		}

	}
	else if (startYear == endYear && startMonth <= endMonth)//�����ͬ�Ƚ��·�
	{
		cout << "����\t" << "�ϻ�ʱ��\t\t" << "�»�ʱ��\t\t" << "���ѽ��\t" << "����״̬" << endl;

		while (pBillingNodeHead != NULL)
		{
			timeInfo = localtime(&pBillingNodeHead->data.cStart);//ת��Ϊtm�ṹ������

			timeToString(pBillingNodeHead->data.cStart, strTime);
			timeToString(pBillingNodeHead->data.cEnd, endTime);

			if (timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth && timeInfo->tm_mon + 1 <= endMonth)
			{
				cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
				
			
			if (pBillingNodeHead->data.cStatus == 0)
				cout << "�ϻ�δ����" << endl;
			if (pBillingNodeHead->data.cStatus == 1)
				cout << "�ϻ��ѽ���" << endl;

			BillingAmount++;
			cMoneyAmount += pBillingNodeHead->data.cAmount;//�ۼ����ѽ��
			}

			pBillingNodeHead = pBillingNodeHead->next;
		}

		if (BillingAmount == 0)
		{
			cout << "�ÿ�û���ڸ�ʱ��������Ѽ�¼��" << endl;
			return;
		}
		else
		{
			cout << "�ۼ����ѽ��Ϊ��" << cMoneyAmount << endl;
		}

	}
	else
	{
		cout << "ʱ�����벻��ȷ" << endl;
		return;
	}

}

void Revenue(MoneyInfoNode* pMoneyInfoNodeHead)
{
	int startYear = 0, startMonth = 0;//Ҫ��ѯ��ʱ��
	struct tm* timeInfo;
	char strTime[TIMELENGTH] = { 0 };//��ֵ�˷�ʱ��
	int MoneyNumber = 0;//��¼����
	float revenueAmount=0;//Ӫҵ��

	if (pMoneyInfoNodeHead == NULL)
	{
		cout << "��ֵ�˷���ϢΪ�գ���ѯ������" << endl;
		return;
	}

	cout << "������Ҫ��ѯ��ʱ��" << endl;
	if (!inputTime(startYear, startMonth))
	{
		cout << "��ѯʱ���������" << endl;
		return;
	}

	cout << "����\t" << "��ֵ�˷ѽ��\t" << "��ֵ�˷�״̬\t" << "��ֵ�˷�ʱ��"  << endl;

	while (pMoneyInfoNodeHead != NULL)
	{
		timeInfo = localtime(&pMoneyInfoNodeHead->data.tStart);//ת��Ϊtm�ṹ������

		timeToString(pMoneyInfoNodeHead->data.tStart, strTime);

		if (timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 == startMonth)
		{
			if (pMoneyInfoNodeHead->data.cStatus == 0)
				revenueAmount += pMoneyInfoNodeHead->data.cMoney;
			else
				revenueAmount -= pMoneyInfoNodeHead->data.cMoney;

			cout << pMoneyInfoNodeHead->data.cNumber << "\t"  <<  pMoneyInfoNodeHead->data.cMoney << "\t\t";
			MoneyNumber++;
		
			if (pMoneyInfoNodeHead->data.cStatus == 0)
				cout << "��ֵ" << "\t\t";
			if (pMoneyInfoNodeHead->data.cStatus == 1)
				cout << "�˷�" << "\t\t";

			cout << strTime << endl;
		}

		pMoneyInfoNodeHead = pMoneyInfoNodeHead->next;
	}

	if (MoneyNumber == 0)
	{
		cout << "��ʱ�����û�г�ֵ�˷Ѽ�¼��" << endl;
		return;
	}
	else
	{
		cout << startYear << "��" << startMonth << "�·�Ӫҵ��Ϊ��" << revenueAmount << endl;
		return;
	}

}
