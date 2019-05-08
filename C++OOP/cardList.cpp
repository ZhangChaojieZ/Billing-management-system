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

int addNewCard(string cNum, string cPwd, float cMoney, CardNode** ppCardNodeHead)//指针的引用，调用函数后参数ppCardNodeHeadn所指内容改变
{
	int nCardIndex = 0;     
	if (cardIsExist(cNum, nCardIndex, *ppCardNodeHead) != NULL)
	{ 
		return FINDCARD;
	}

	Card card;

	strcpy(card.cNumber, cNum.c_str());//把cNum的值赋给cNumber
	strcpy(card.cPassword, cPwd.c_str());//同上
	card.cBalance = 0;

	// 添加新卡时，累计金额等于开卡金额    
	card.cTotalMoney = card.cBalance;   
	card.cStatus = UNUSE;              // 卡状态  
	card.cUseCount = 0;                // 使用次数 

	// 开卡时间，最后使用时间都默认为当前时间 
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
	string tempNumber;//要查询的卡号

	if (pCardNodeHead == NULL) //判断链表是否为空
	{
		cout << endl << endl << "一张上机卡都没有！" << endl << endl;
		return; 
	}

	//cout << "卡号\t状态\t余额\t累计使用\t使用次数\t上次使用时间" << endl;
	if (inputCardNumber(tempNumber))
	{
		cout << "卡号\t状态\t\t余额\t累计使用\t使用次数\t上次使用时间" << endl;
		CardNode* pCur = pCardNodeHead;
		int flag = 0;
		while (pCur != NULL)
		{
			if (strstr(pCur->data.cNumber, tempNumber.c_str()) != NULL)//异常
			{
				flag = 1;	
				char aLastTime[TIMELENGTH] = { 0 };
				timeToString((pCur->data).cLast, aLastTime);
				cout << pCur->data.cNumber << "\t";
				if (pCur->data.cStatus == USING)
					cout << "正在上机\t";
				else if (pCur->data.cStatus == UNUSE)
					cout << "未在上机\t";
				else if (pCur->data.cStatus == INVALID)
					cout << "注销    \t";
				else
					cout << "错误\t";
				cout << pCur->data.cBalance << "\t";
				cout << pCur->data.cTotalMoney << "\t\t" << pCur->data.cUseCount << "\t\t" << aLastTime << endl;
			}

			pCur = pCur->next;		
		}

		if (flag == 0)
		{
			cout << "所查询卡号不存在！" << endl;
			return;
		}
	}
	else
	{
		cout << endl << endl << "输入的【卡号】格式不符号要求， 查询卡失败!" << endl << endl;
	}

}