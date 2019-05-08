#pragma once
#include<iostream>
#include<string>
#include"model.h"
using namespace std;

//存放与卡有关的函数
int addNewCard(string strNo, string strPwd, float fBalance, CardNode** ppCardNodeHead);//添加新卡

void displayCard(CardNode* pCardNodeHead);//展示卡的信息，模糊查询（可以添加精确查询功能）