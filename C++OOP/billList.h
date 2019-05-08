#pragma once
#ifndef BILLLIST_H
#define BILLLIST_H

#include"model.h"

//存放于计费有关的函数

int Login(string CardNumber, string CardPwd, LoginInfo* pInfo, CardNode* pCardNodeHead, BillingNode **ppBillingNodeHea);
//①该记录作为一个节点插 入到上机记录的链表的末尾
//②同时也要将这条记录添加在计费信息记录文件 billing.dat 的末尾
//③还要修改卡在文件和链表中的状态，即变为上机

int settle(string CardNumber, string CardPwd, SettleInfo* pInfo, CardNode* const pCardNodeHead, BillingNode* const pBillingNodeHea);
//输入下机的卡号和密码，如果正确，则检测该卡的状态是否在上机？
//是否有上机的消费 记录，检测余额是否够付费，如果一切正确，则可以下机
//在下机过程种，需要修改卡的状 态（包括链表和文件），还要修改上机消费的信息，即 billing 链表和文件。如果不正确， 则给出具体的错误提示信息。

#endif // !BILLLIST_H

