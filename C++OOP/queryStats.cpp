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
	cout << "请输入要查询的年份（2000~3000）：";
	cin >> cYear;
	//cout << endl;
	cout << "请输入要查询的月份（1~12）：";
	cin >> cMonth;
	cout << endl;

	if (cYear >= 2000 && cYear <= 3000&&cMonth<=12&&cMonth>=1)
		return true;
	else
	{
		cout << "年份或月份输入错误！" << endl;
		return false;
	}
		
}

void UserBIlling(BillingNode* pBillingNodeHead)
{
	int startYear=0, startMonth=0;//起始时间
	int endYear=0, endMonth=0;//截止时间
	string cNumber;//要查询的卡号
	struct tm* timeInfo;
	char strTime[TIMELENGTH] = { 0 };//上机时间
	char endTime[TIMELENGTH] = { 0 };//下机时间
	int BillingAmount = 0;//记录条数
	float cMoneyAmount = 0;//累计消费金额


	if (pBillingNodeHead == NULL)
	{
		cout << "消费记录信息为空，查询不到！" << endl;
		return;
	}

	cout << "请输入要查询的卡号" << endl;
	if (!inputCardNumber(cNumber))
	{
		cout << "卡号输入错误" << endl;
		return;
	}

	cout << "请输入开始时间" << endl;
	if (!inputTime(startYear, startMonth))
	{
		cout << "起始时间输入错误！" << endl;
		return;
	}

	cout << "请输入截止时间" << endl;
	if (!inputTime(endYear, endMonth))
	{	
		cout << "截止时间输入错误！" << endl;
		return;
	}

	if (startYear < endYear )//年份不同
	{

		cout << "卡号\t" << "上机时间\t\t" << "下机时间\t\t" << "消费金额\t" << "消费状态" << endl;

		while (pBillingNodeHead != NULL)
		{
			if (strcmp(pBillingNodeHead->data.cNumber, cNumber.c_str())==0)
			{
				timeInfo = localtime(&pBillingNodeHead->data.cStart);//转化为tm结构体类型

				timeToString(pBillingNodeHead->data.cStart, strTime);
				timeToString(pBillingNodeHead->data.cEnd, endTime);

				if ((timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth) || (timeInfo->tm_year + 1900 == endYear && timeInfo->tm_mon + 1 <= endMonth) || (timeInfo->tm_year > startYear&&timeInfo->tm_year < endYear))
				{
					cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
					if (pBillingNodeHead->data.cStatus == 0)
						cout << "上机未结算" << endl;
					if (pBillingNodeHead->data.cStatus == 1)
						cout << "上机已结算" << endl;
					cMoneyAmount += pBillingNodeHead->data.cAmount;//累计消费金额
					BillingAmount++;
				}
			}
	
			pBillingNodeHead = pBillingNodeHead->next;
		}

		if (BillingAmount == 0)
		{
			cout << "该卡没有在该时间段内消费记录！" << endl;
			return;
		}
		else
		{
			cout << "累计消费金额为：" << cMoneyAmount << endl;
		}

	}
	else if (startYear == endYear && startMonth <= endMonth)//年份相同比较月份
	{
		cout << "卡号\t" << "上机时间\t\t" << "下机时间\t\t" << "消费金额\t" << "消费状态" << endl;

		while (pBillingNodeHead != NULL)
		{
			
			if (strcmp(pBillingNodeHead->data.cNumber, cNumber.c_str()) == 0)
			{
				timeInfo = localtime(&pBillingNodeHead->data.cStart);//转化为tm结构体类型

				timeToString(pBillingNodeHead->data.cStart, strTime);
				timeToString(pBillingNodeHead->data.cEnd, endTime);

				if (timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth && timeInfo->tm_mon + 1 <= endMonth)
				{
					cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
					
					if (pBillingNodeHead->data.cStatus == 0)
						cout << "上机未结算" << endl;
					if (pBillingNodeHead->data.cStatus == 1)
						cout << "上机已结算" << endl;
					cMoneyAmount += pBillingNodeHead->data.cAmount;//累计消费金额
					BillingAmount++;
				}
			}

			pBillingNodeHead = pBillingNodeHead->next;
		}
		if (BillingAmount == 0)
		{
			cout << "该卡没有在该时间段内消费记录！" << endl;
			return;
		}
		else
		{
			cout << "累计消费金额为：" << cMoneyAmount << endl;
		}
	}
	else
	{
		cout << "时间输入不正确" << endl;
		return;
	}


}

void TimeBIlling(BillingNode* pBillingNodeHead)
{
	int startYear = 0, startMonth = 0;//起始时间
	int endYear = 0, endMonth = 0;//截止时间
	struct tm* timeInfo;
	char strTime[TIMELENGTH] = { 0 };//上机时间
	char endTime[TIMELENGTH] = { 0 };//下机时间
	int BillingAmount = 0;//记录条数
	float cMoneyAmount = 0;//累计消费金额

	if (pBillingNodeHead == NULL)
	{
		cout << "消费记录信息为空，查询不到！" << endl;
		return;
	}

	cout << "请输入开始时间" << endl;
	if (!inputTime(startYear, startMonth))
	{
		cout << "起始时间输入错误！" << endl;
		return;
	}

	cout << "请输入截止时间" << endl;
	if (!inputTime(endYear, endMonth))
	{
		cout << "截止时间输入错误！" << endl;
		return;
	}

	if (startYear < endYear)//年份不同
	{

		cout << "卡号\t" << "上机时间\t\t" << "下机时间\t\t" << "消费金额\t" << "消费状态" << endl;

		while (pBillingNodeHead != NULL)
		{

			timeInfo = localtime(&pBillingNodeHead->data.cStart);//转化为tm结构体类型

			timeToString(pBillingNodeHead->data.cStart, strTime);
			timeToString(pBillingNodeHead->data.cEnd, endTime);


			if ((timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth) || (timeInfo->tm_year + 1900 == endYear && timeInfo->tm_mon + 1 <= endMonth) || (timeInfo->tm_year > startYear&&timeInfo->tm_year < endYear))
			{
				cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
				if (pBillingNodeHead->data.cStatus == 0)
					cout << "上机未结算" << endl;
				if (pBillingNodeHead->data.cStatus == 1)
					cout << "上机已结算" << endl;
				cMoneyAmount += pBillingNodeHead->data.cAmount;//累计消费金额
				BillingAmount++;
			}

			pBillingNodeHead = pBillingNodeHead->next;
		}

		if (BillingAmount == 0)
		{
			cout << "该卡没有在该时间段内消费记录！" << endl;
			return;
		}
		else
		{
			cout << "累计消费金额为：" << cMoneyAmount << endl;
		}

	}
	else if (startYear == endYear && startMonth <= endMonth)//年份相同比较月份
	{
		cout << "卡号\t" << "上机时间\t\t" << "下机时间\t\t" << "消费金额\t" << "消费状态" << endl;

		while (pBillingNodeHead != NULL)
		{
			timeInfo = localtime(&pBillingNodeHead->data.cStart);//转化为tm结构体类型

			timeToString(pBillingNodeHead->data.cStart, strTime);
			timeToString(pBillingNodeHead->data.cEnd, endTime);

			if (timeInfo->tm_year + 1900 == startYear && timeInfo->tm_mon + 1 >= startMonth && timeInfo->tm_mon + 1 <= endMonth)
			{
				cout << pBillingNodeHead->data.cNumber << "\t" << strTime << "\t" << endTime << "\t" << pBillingNodeHead->data.cAmount << "\t\t";
				
			
			if (pBillingNodeHead->data.cStatus == 0)
				cout << "上机未结算" << endl;
			if (pBillingNodeHead->data.cStatus == 1)
				cout << "上机已结算" << endl;

			BillingAmount++;
			cMoneyAmount += pBillingNodeHead->data.cAmount;//累计消费金额
			}

			pBillingNodeHead = pBillingNodeHead->next;
		}

		if (BillingAmount == 0)
		{
			cout << "该卡没有在该时间段内消费记录！" << endl;
			return;
		}
		else
		{
			cout << "累计消费金额为：" << cMoneyAmount << endl;
		}

	}
	else
	{
		cout << "时间输入不正确" << endl;
		return;
	}

}

void Revenue(MoneyInfoNode* pMoneyInfoNodeHead)
{
	int startYear = 0, startMonth = 0;//要查询的时间
	struct tm* timeInfo;
	char strTime[TIMELENGTH] = { 0 };//充值退费时间
	int MoneyNumber = 0;//记录条数
	float revenueAmount=0;//营业额

	if (pMoneyInfoNodeHead == NULL)
	{
		cout << "充值退费信息为空，查询不到！" << endl;
		return;
	}

	cout << "请输入要查询的时间" << endl;
	if (!inputTime(startYear, startMonth))
	{
		cout << "查询时间输入错误！" << endl;
		return;
	}

	cout << "卡号\t" << "充值退费金额\t" << "充值退费状态\t" << "充值退费时间"  << endl;

	while (pMoneyInfoNodeHead != NULL)
	{
		timeInfo = localtime(&pMoneyInfoNodeHead->data.tStart);//转化为tm结构体类型

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
				cout << "充值" << "\t\t";
			if (pMoneyInfoNodeHead->data.cStatus == 1)
				cout << "退费" << "\t\t";

			cout << strTime << endl;
		}

		pMoneyInfoNodeHead = pMoneyInfoNodeHead->next;
	}

	if (MoneyNumber == 0)
	{
		cout << "该时间段内没有充值退费记录！" << endl;
		return;
	}
	else
	{
		cout << startYear << "年" << startMonth << "月份营业额为：" << revenueAmount << endl;
		return;
	}

}
