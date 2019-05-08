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
		return NOTFINDCARD;//未找到卡
	}
	if (strcmp(pCard->cPassword, CardPwd.c_str()) != 0)
	{
		return NOTMATCH;//密码不匹配
	}
	if (pCard->cStatus == USING)
	{
		return USING;//卡正在上机
	}
	if (pCard->cStatus == INVALID)
	{
		return INVALID;//卡已经注销
	}
	if (pCard->cBalance <= 0)
	{
		return NOTENOUGHMONEY;//卡余额不足
	}

	//如果可以上机，更新卡信息
	pCard->cStatus = USING;//卡正在使用
	pCard->cUseCount++;//使用次数加1
	pCard->cLast = time(NULL);//更新卡最后使用时间

	//更新文件中的信息
	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "信息修改成功！\n";
	}

	//添加消费记录
	strcpy(billing.cNumber, CardNumber.c_str());//上机卡号
	billing.cStart = time(NULL);//上机时间	
	billing.cEnd = 0;//下机时间
	billing.cStatus = NOSETTLEMENT;//消费状态，未结算
	billing.cAmount = 0;//消费金额

	//先将计费信息保存到文件中
	if (saveBilling(&billing, BILLINGPATH))
	{
		cout << "计费信息保存成功！\n";
	}

	//在计费链表中增加一条计费信息
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

	//组装上机信息
	strcpy(pInfo->cNumber, CardNumber.c_str());
	pInfo->cBalance = pCard->cBalance;
	pInfo->cStart = billing.cStart;

	return SUCCESS;

}

int settle(string CardNumber, string CardPwd, SettleInfo* pInfo, CardNode* const pCardNodeHead, BillingNode* const pBillingNodeHead)
{
	int nCardIndex=0;  
	Card* pCard = cardIsExist(CardNumber, nCardIndex, pCardNodeHead);

	     
	if(pCard == NULL) // 未找到卡       
		return NOTFINDCARD; 
	
	if( strcmp(pCard->cPassword, CardPwd.c_str())!=0) // 密码不匹配       
		return NOTMATCH; 

	if(pCard->cStatus != USING) // 判断该卡是否正在上机，只有正在上机卡才能进行下机操作  
		return UNUSE; 

	// 根据卡号，查询计费信息

	int nBillingIndex=0;     
	Billing* pBilling = billingIsExit(CardNumber, nBillingIndex, pBillingNodeHead); 
	 
	if(pBilling == NULL)// 如果查询计费信息为空，表示下机失败  
	{     
		cout << "计费信息为空" << endl;  
		return UNUSE;
	} 
		 
	double dbAmount = getAmount(pBilling->cStart); // 计算消费金额		 
	float fBalance = pCard->cBalance - (float)dbAmount;  

	if(fBalance < 0) // 如果余额小于消费金额，则不能进行下机
	{   
		return NOTENOUGHMONEY; 
	} 

	// 更新卡信息 
	pCard->cBalance = fBalance;// 余额
	pCard->cStatus = UNUSE;// 状态       
	pCard->cLast = time(NULL);// 上次使用时间   
	

	 // 更新文件中的卡信息 
	if (updateCard(pCard, CARDPATH, nCardIndex))
	{
		cout << "更新卡信息成功" << endl;
	}

	 // 更新计费信息  
	pBilling->cAmount = (float)dbAmount;// 消费金额  
	pBilling->cStatus = YESSETTLEMENT;// 状态，已结算   
	pBilling->cEnd = time(NULL);// 下机时间    
		 
	 // 更新文件中的计费信息
	if (updateBilling(pBilling, BILLINGPATH, nBillingIndex))
	{
		cout << "更新计费信息完成" << endl;
	}

	 // 组装下机信息  
	strcpy(pInfo->cNumber, CardNumber.c_str());// 卡号   
	pInfo->cAmount = (float)dbAmount;// 消费金额        
	pInfo->cBalance = fBalance;// 余额              
	pInfo->tStart = pBilling->cStart;// 上机时间         
	pInfo->tEnd = pBilling->cEnd;//time(NULL);// 下机时间    
	
	return SUCCESS;
}
