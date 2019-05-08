
#include<iostream>
#include<string>
using namespace std;

void outputMenu()
{
	cout << "******计费管理菜单******" << endl;
	cout << "\t1.添加卡\n\t2.查询卡\n\t3.上机\n\t4.下机\n\t5.充值\n\t6.退费\n\t7.查询统计\n\t8.注销卡\n\t0.退出\n请输入菜单选项编号：\n";

}

bool inputCardNumber(string &CardNumber)//输入卡号
{
	//string CardNumber;
	char flag = NULL;
	while (true)
	{
		cout << "请输入卡号（长度为1~17）：";
		cin >> CardNumber;
		cin.clear();
		cin.sync();
		if (CardNumber.length() > 17)
		{
			cout << "卡号长度超过最大程度！" << endl;
			while (flag != 'Y'&&flag != 'N')
			{
				cout << "是否重新输入，Y/N?";
				flag = toupper(flag);
				cin.clear();
				cin.sync();
			}
			if (flag == 'N')
			{
				cout << "卡号输入错误！" << endl;
				return false;
			}
		}
		else
			return true;
	}
}

bool inputCardPwd(string& CardPwd)//输入密码
{
	char flag = NULL;
	while (true)
	{
		cout << "请输入密码（长度为1~15）：";
		cin >> CardPwd;
		cin.clear();
		cin.sync();
		if (CardPwd.length() >15)
		{
			cout << "密码长度超过最大长度！" << endl;
			while (flag != 'Y'&&flag != 'N')
			{
				cout << "是否重新输入，Y/N?";
				cin >> flag;
				cin.clear();
				cin.sync();
			}
			if (flag == 'N')
			{
				cout << "密码格式错误！" << endl;
				return false;
			}
		}
		else
			return true;
	}
}

bool inputCardMoney(float& CardMoney)//输入金额
{
	char flag = NULL;
	while (true)
	{
		cout << "请输入充值金额（充值金额不得小于等于0）";
		cin >> CardMoney;
		cin.clear();
		cin.sync();
		if (CardMoney<=0)
		{
			cout << "充值金额小于等于零！" << endl;
			while (flag != 'Y'&&flag != 'N')
			{
				cout << "是否重新输入，Y/N?";
				cin >> flag;
				cin.clear();
				cin.sync();
			}
			if (flag == 'N')
			{
				cout << "金额输入错误！" << endl;
				return false;
			}
		}
		else
			return true;
	}
}

bool inputNumPwdMon(string& CardNumber, string& CardPwd, float& CardMoney)
{
	if (inputCardNumber(CardNumber) && inputCardPwd(CardPwd) && inputCardMoney(CardMoney))
		return true;
	else
		return false;
}

bool inputNumPwd(string& CardNumber, string& CardPwd)
{
	if (inputCardNumber(CardNumber) && inputCardPwd(CardPwd))
	{
		return true;
	}
	else
	{
		return false;
	}
}