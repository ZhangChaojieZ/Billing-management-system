#pragma once
#include<iostream>
//存放所有用到的结构体

struct Card
{
	//string cNumber;//卡号
	//string cPwd;//密码
	char cNumber[17];//卡号
	char cPassword[17];////密码
	//结构体中不能用string类型，string类型的变量实际是指针，切记，结构体中不能用string类型变量
	int cStatus;//卡状态
	time_t cStart;//开卡时间,long型
	float cTotalMoney;//累计金额
	time_t cLast;//最后使用时间，long型
	int cUseCount;//使用次数
	float cBalance;//余额
};

struct CardNode//卡信息链表结点
{
	Card data;//节点数据
	struct CardNode *next;//指向下一个节点
};

struct Billing//计费信息记录结构体，保留每次上下机信息
{
	char cNumber[17];//卡号
	time_t cEnd;//上机时间
	time_t cStart;//下机时间
	float cAmount;//消费金额
	int cStatus;//消费状态
};

struct BillingNode//计费信息结点
{
	Billing data;
	BillingNode *next;
};

struct LoginInfo//上机信息结构体
{
	char cNumber[17];//上机卡号
	time_t cStart;//上机时间
	float cBalance;//上机时卡余额
};

struct SettleInfo//下机信息结构体
{
	char cNumber[17];//卡号
	time_t tStart;//上机时间
	time_t tEnd;//下机时间
	float cAmount;//消费金额
	float cBalance;//余额
};

struct MoneyInfo//充值退费信息记录结构体
{
	char cNumber[17];//卡号
	float cMoney;//充值退费金额
	time_t tStart;//充值退费时间
	int cStatus;//状态：0-充值，1-退费
};

struct MoneyInfoNode//充值退费信息记录结点
{
	MoneyInfo data;
	MoneyInfoNode *next;
};

struct RechargeInfo//充值信息结构体
{
	char cNumber[17];//卡号
	time_t tRechargeTime;//充值时间
	float cMoney;//充值金额
	float cBalance;//余额
};

struct ReturnsInfo//退费信息结构体
{
	char cNumber[17];//卡号
	time_t tReturnsTime;//退费时间
	float cMoney;//退费金额
	float cBalance;//余额
};