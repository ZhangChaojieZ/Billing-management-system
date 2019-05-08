#pragma once
#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include<string>
using namespace std;
//��ų���

const string CARDPATH = "c:\\c++\\card.dat";//����Ϣ��¼�ļ�//
const string BILLINGPATH = "c:\\c++\\billing.dat";//�Ʒ���Ϣ��¼�ļ�
const string MONEYPATH = "c:\\c++\\money.dat";//��ֵ�˷Ѽ�¼�ļ�

//const string CARDPATH = "card.dat";//����Ϣ��¼�ļ�
//const string BILLINGPATH = "billling.dat";//�Ʒ���Ϣ��¼�ļ�
//const string MONEYPATH = "money.dat";//��ֵ�˷Ѽ�¼��

const int TIMELENGTH = 20;//ʱ���ַ����鳤��
const int SUCCESS = 0;//�����ɹ�
const int FINDCARD = 1;//�ҵ���
const int NOTFINDCARD = 2;//δ�ҵ���
const int NOTMATCH = 3;//�������벻ƥ��
const int NOTENOUGHMONEY = 4;//������
const int NOTFARE = 5;//δ�ҵ��Ʒ���Ϣ

const int USING = 6;//��״̬�������ϻ�
const int UNUSE = 7;//��״̬��δ���ϻ�
const int INVALID = 8;//��״̬���Ѿ�ע��

const int NOSETTLEMENT = 0;//�ϻ�δ����
const int YESSETTLEMENT = 1;//�ϻ��ѽ���

const int UNIT = 15;//��С�շѵ�Ԫ�����ӣ�
const float CHARGE = 0.5f;//ÿ���Ʒѵ�Ԫ�շѣ�Ԫ��

#endif // GLOBAL_H_INCLUDED