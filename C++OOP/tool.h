#pragma once
//��Ŵ���ʱ��ĺ�������
#ifndef TIMETOOL_H
#define TIMETOOL_H


#include<time.h>
#include<stdio.h>
using namespace std;

void timeToString(time_t tm, char* tmStr);
//��time_t����ת��Ϊ�̶���ʽ�ַ���

time_t stringToTime(char* tmStr);
//���ַ���ת��Ϊtime_t����
#endif // !TIMETOOL_H