#pragma once
#include<iostream>
//��������õ��Ľṹ��

struct Card
{
	//string cNumber;//����
	//string cPwd;//����
	char cNumber[17];//����
	char cPassword[17];////����
	//�ṹ���в�����string���ͣ�string���͵ı���ʵ����ָ�룬�мǣ��ṹ���в�����string���ͱ���
	int cStatus;//��״̬
	time_t cStart;//����ʱ��,long��
	float cTotalMoney;//�ۼƽ��
	time_t cLast;//���ʹ��ʱ�䣬long��
	int cUseCount;//ʹ�ô���
	float cBalance;//���
};

struct CardNode//����Ϣ������
{
	Card data;//�ڵ�����
	struct CardNode *next;//ָ����һ���ڵ�
};

struct Billing//�Ʒ���Ϣ��¼�ṹ�壬����ÿ�����»���Ϣ
{
	char cNumber[17];//����
	time_t cEnd;//�ϻ�ʱ��
	time_t cStart;//�»�ʱ��
	float cAmount;//���ѽ��
	int cStatus;//����״̬
};

struct BillingNode//�Ʒ���Ϣ���
{
	Billing data;
	BillingNode *next;
};

struct LoginInfo//�ϻ���Ϣ�ṹ��
{
	char cNumber[17];//�ϻ�����
	time_t cStart;//�ϻ�ʱ��
	float cBalance;//�ϻ�ʱ�����
};

struct SettleInfo//�»���Ϣ�ṹ��
{
	char cNumber[17];//����
	time_t tStart;//�ϻ�ʱ��
	time_t tEnd;//�»�ʱ��
	float cAmount;//���ѽ��
	float cBalance;//���
};

struct MoneyInfo//��ֵ�˷���Ϣ��¼�ṹ��
{
	char cNumber[17];//����
	float cMoney;//��ֵ�˷ѽ��
	time_t tStart;//��ֵ�˷�ʱ��
	int cStatus;//״̬��0-��ֵ��1-�˷�
};

struct MoneyInfoNode//��ֵ�˷���Ϣ��¼���
{
	MoneyInfo data;
	MoneyInfoNode *next;
};

struct RechargeInfo//��ֵ��Ϣ�ṹ��
{
	char cNumber[17];//����
	time_t tRechargeTime;//��ֵʱ��
	float cMoney;//��ֵ���
	float cBalance;//���
};

struct ReturnsInfo//�˷���Ϣ�ṹ��
{
	char cNumber[17];//����
	time_t tReturnsTime;//�˷�ʱ��
	float cMoney;//�˷ѽ��
	float cBalance;//���
};