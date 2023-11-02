#include<iostream>
#include"mysql.h"
#include<string>
using namespace std;
#include"studentManger.h"



int main()
{
	
	cout << "--------欢迎来到学生信息管理系统--------" << endl;
	cout << "-------------按下任意键继续-------------" << endl;
	getchar();
	while (100)
	{
		int a = NULL;
		cout << "---------------1.增加学生信息---------------" << endl;
		cout << "---------------2.删除学生信息---------------" << endl;
		cout << "---------------3.修改学生信息---------------" << endl;
		cout << "---------------4.查询学生信息---------------" << endl;
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
			cout << "您输入错了哦！" << endl;
		}

	}
	return 0;
}