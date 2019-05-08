#pragma once
//存放处理时间的函数声明
#ifndef TIMETOOL_H
#define TIMETOOL_H


#include<time.h>
#include<stdio.h>
using namespace std;

void timeToString(time_t tm, char* tmStr);
//将time_t类型转化为固定格式字符串

time_t stringToTime(char* tmStr);
//将字符串转化为time_t类型
#endif // !TIMETOOL_H