#pragma once
#ifndef MENU_H
#define MENU_H


#include<iostream>
#include<string>
using namespace std;

//存放输入函数
void outputMenu();//输出主菜单
bool inputCardNumber(string& CardNummber);//输入卡号
bool inputCardPwd(string& CardPwd);//输入密码
bool inputCardMoney(float& CardMoney);//输入金额
bool inputNumPwd(string& CardNumber, string& CardPwd);//输入卡号密码
bool inputNumPwdMon(string& CardNumber, string& CardPwd, float& CardMoney);//输入卡号密码金额

#endif // MENU_H