#pragma once
#ifndef BILLLIST_H
#define BILLLIST_H

#include"model.h"

//����ڼƷ��йصĺ���

int Login(string CardNumber, string CardPwd, LoginInfo* pInfo, CardNode* pCardNodeHead, BillingNode **ppBillingNodeHea);
//�ٸü�¼��Ϊһ���ڵ�� �뵽�ϻ���¼�������ĩβ
//��ͬʱҲҪ��������¼����ڼƷ���Ϣ��¼�ļ� billing.dat ��ĩβ
//�ۻ�Ҫ�޸Ŀ����ļ��������е�״̬������Ϊ�ϻ�

int settle(string CardNumber, string CardPwd, SettleInfo* pInfo, CardNode* const pCardNodeHead, BillingNode* const pBillingNodeHea);
//�����»��Ŀ��ź����룬�����ȷ������ÿ���״̬�Ƿ����ϻ���
//�Ƿ����ϻ������� ��¼���������Ƿ񹻸��ѣ����һ����ȷ��������»�
//���»������֣���Ҫ�޸Ŀ���״ ̬������������ļ�������Ҫ�޸��ϻ����ѵ���Ϣ���� billing ������ļ����������ȷ�� ���������Ĵ�����ʾ��Ϣ��

#endif // !BILLLIST_H

