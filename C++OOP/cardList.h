#pragma once
#include<iostream>
#include<string>
#include"model.h"
using namespace std;

//����뿨�йصĺ���
int addNewCard(string strNo, string strPwd, float fBalance, CardNode** ppCardNodeHead);//����¿�

void displayCard(CardNode* pCardNodeHead);//չʾ������Ϣ��ģ����ѯ��������Ӿ�ȷ��ѯ���ܣ�