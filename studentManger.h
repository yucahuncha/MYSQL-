#pragma once
#include<iostream>
#include"mysql.h"
#include<string>
#include<vector>
using namespace std;

typedef struct Student
{
	int student_id;							//定义三个变量用存放数据
	string student_name;
	string  class_id;

}; Student;


class studentManger
{
	studentManger();					//构造函数
	~studentManger();				//析构函数


public:
	static studentManger* GetInstance()							//单例模式
	{
		static studentManger studentManger;
		return &studentManger;
	}

public:
	bool insert_student(Student& t);							//增加
	bool	 update_student(Student& t);						//更新
	bool delete_student(int	 studen_id);						//删除
	//vector<Student> get_students(string condition = "");		//显示所有学生
	char get_students(int student_id);						//查询单个学生
	void zhengjia();
	void shuanchu();
	void gengxin();
	void chanxun();
	
private:
	MYSQL* con = mysql_init(NULL);												//创建数据库连接指针
	//con = mysql_init(NULL);
	const char* host = "154.8.150.243";								//数据库地址
	const char* name = "student";									//数据库用户名
	const char* pw = "frCLdyrdhzj7G63F";										//数据库密码
	const char* database_name = "student";			//数据库名称
	const int port = 3306;											//端口
};

