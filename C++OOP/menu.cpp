
#include<iostream>
#include<string>
using namespace std;

void outputMenu()
{
	cout << "******�Ʒѹ���˵�******" << endl;
	cout << "\t1.��ӿ�\n\t2.��ѯ��\n\t3.�ϻ�\n\t4.�»�\n\t5.��ֵ\n\t6.�˷�\n\t7.��ѯͳ��\n\t8.ע����\n\t0.�˳�\n������˵�ѡ���ţ�\n";

}

bool inputCardNumber(string &CardNumber)//���뿨��
{
	//string CardNumber;
	char flag = NULL;
	while (true)
	{
		cout << "�����뿨�ţ�����Ϊ1~17����";
		cin >> CardNumber;
		cin.clear();
		cin.sync();
		if (CardNumber.length() > 17)
		{
			cout << "���ų��ȳ������̶ȣ�" << endl;
			while (flag != 'Y'&&flag != 'N')
			{
				cout << "�Ƿ��������룬Y/N?";
				flag = toupper(flag);
				cin.clear();
				cin.sync();
			}
			if (flag == 'N')
			{
				cout << "�����������" << endl;
				return false;
			}
		}
		else
			return true;
	}
}

bool inputCardPwd(string& CardPwd)//��������
{
	char flag = NULL;
	while (true)
	{
		cout << "���������루����Ϊ1~15����";
		cin >> CardPwd;
		cin.clear();
		cin.sync();
		if (CardPwd.length() >15)
		{
			cout << "���볤�ȳ�����󳤶ȣ�" << endl;
			while (flag != 'Y'&&flag != 'N')
			{
				cout << "�Ƿ��������룬Y/N?";
				cin >> flag;
				cin.clear();
				cin.sync();
			}
			if (flag == 'N')
			{
				cout << "�����ʽ����" << endl;
				return false;
			}
		}
		else
			return true;
	}
}

bool inputCardMoney(float& CardMoney)//������
{
	char flag = NULL;
	while (true)
	{
		cout << "�������ֵ����ֵ����С�ڵ���0��";
		cin >> CardMoney;
		cin.clear();
		cin.sync();
		if (CardMoney<=0)
		{
			cout << "��ֵ���С�ڵ����㣡" << endl;
			while (flag != 'Y'&&flag != 'N')
			{
				cout << "�Ƿ��������룬Y/N?";
				cin >> flag;
				cin.clear();
				cin.sync();
			}
			if (flag == 'N')
			{
				cout << "����������" << endl;
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