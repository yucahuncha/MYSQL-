#include<iostream>
#include"mysql.h"
#include<string>
using namespace std;
#include"studentManger.h"



int main()
{
	
	cout << "--------��ӭ����ѧ����Ϣ����ϵͳ--------" << endl;
	cout << "-------------�������������-------------" << endl;
	getchar();
	while (100)
	{
		int a = NULL;
		cout << "---------------1.����ѧ����Ϣ---------------" << endl;
		cout << "---------------2.ɾ��ѧ����Ϣ---------------" << endl;
		cout << "---------------3.�޸�ѧ����Ϣ---------------" << endl;
		cout << "---------------4.��ѯѧ����Ϣ---------------" << endl;
		cin >> a;
		if (a==1)
		{
			studentManger::GetInstance()->zhengjia();
		}
		if (a==2)
		{
			studentManger::GetInstance()->shuanchu();
		}
		if (a==3)
		{
			studentManger::GetInstance()->gengxin();
		}
		if (a==4)
		{
			studentManger::GetInstance()->chanxun();
		}
		if (a>4)
		{
			cout << "���������Ŷ��" << endl;
		}

	}
	return 0;
}