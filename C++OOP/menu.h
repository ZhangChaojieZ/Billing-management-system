#pragma once
#ifndef MENU_H
#define MENU_H


#include<iostream>
#include<string>
using namespace std;

//������뺯��
void outputMenu();//������˵�
bool inputCardNumber(string& CardNummber);//���뿨��
bool inputCardPwd(string& CardPwd);//��������
bool inputCardMoney(float& CardMoney);//������
bool inputNumPwd(string& CardNumber, string& CardPwd);//���뿨������
bool inputNumPwdMon(string& CardNumber, string& CardPwd, float& CardMoney);//���뿨��������

#endif // MENU_H