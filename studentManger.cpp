#include "studentManger.h"
#include<stdio.h>
#include<iostream>

studentManger::studentManger()														//初始化数据库连接
{
	//创建数据库链接
	//MYSQL *con = mysql_init(NULL);
	//设置数据库编码格式
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");															

	if (!mysql_real_connect(con, host, name, pw, database_name, port, NULL, 0 ))																//连接数据库
	{
		std::cout << "failed to connect" << std::endl;
		exit(1);																				//如果出错直接退出
	}

}

studentManger::~studentManger()													//析构函数直接退出数据库就ok
{
	mysql_close(con);
}

bool studentManger::insert_student(Student& stu)																						//增加
{
	char sql[1024];																																					//创建一个长度为1024字节的变量用于存放sql语句
	sprintf_s(sql, "insert into students (student_id, student_name, class_id) values(%d,'%s', '%s');", stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());
	if (mysql_query(con, sql))																						//判断是否出错，并打印错误信息
	{
		printf("failed to insert data: Error:%s\n", mysql_error(con));
		return false;
	}
	else
	{
		cout << "增加成功" << endl;
	}
	return true;
}

bool studentManger::update_student(Student& stu)															//修改
{
	char sql[1024];
	sprintf_s(sql, "UPDATE students SET student_name = '%s', class_id = '%s' where student_id = %d", stu.student_name.c_str(), stu.class_id.c_str(), stu.student_id);

	if (mysql_query(con, sql))																									//执行语句并判断是否出错
	{
		printf("failed to update data: Error:%s\n", mysql_error(con));
		return false;
	}
	else
	{
		cout << "修改成功" << endl;
	}
	return true;
}

bool studentManger::delete_student(int student_id)																		//删除
{

	string sql = "DELETE FROM students WHERE student_id = " + to_string(student_id);
	const char* str = sql.c_str();
	if (mysql_query(con, str))																							//判断是否出错，并打印错误信息
	{
		fprintf(stderr, "failed to detele data: Error:%s\n", mysql_error(con));
		return false;
	}
	else
	{
		cout << "删除成功" << endl;
	}
	return true;
}

/*vector<Student> studentManger::get_students(string condition)																//显示所有学生
{
	vector<Student> stuList;
	char sql[1024];
	sprintf(sql, "select * from students where student_id=8888", condition.c_str());
	//sprintf(sql, "select * from students where student_id=%s");
	//string sql = "select * from students where student_id=" + to_string(conce);
	if (mysql_query(con, sql))
	{
		printf("failed to selete data: Error:%s\n", mysql_error(con));
		return {};
	}

	MYSQL_RES* res = mysql_store_result(con);
	
	MYSQL_ROW row;																												//获取返回的信息 
	while ((row = mysql_fetch_row(res)))
	{
		Student stu;
		stu.student_id = atoi(row[0]);
		stu.student_name = row[1];
		stu.class_id = row[2];

		printf("%d", stu.student_id);

		stuList.push_back(stu);
	}

	return stuList;
}
*/


char studentManger::get_students(int student_id)																//查询
{
	string sql = "select * from students where student_id = " + to_string(student_id);
	const char* str = sql.c_str();
	if (mysql_query(con, str))																							//判断是否出错，并打印错误信息
	{
		fprintf(stderr, "failed to select data: Error:%s\n", mysql_error(con));
		return false;
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;															//创建存放信息的数组
	while ((row = mysql_fetch_row(res)))
	{
		Student stu;
		stu.student_id = atoi(row[0]);
		stu.student_name = row[1];
		stu.class_id = row[2];
		cout << stu.student_id << ":" << stu.student_name << ":" << stu.class_id << endl;					//打印信息
	}
}

void studentManger::zhengjia()
{
	int ID;
	char name[10];
	char banji[20];
	cout << "请输入学生的id和姓名，班级" << endl;
	cin >> ID >> name >> banji;
	Student stu{ ID, name, banji };
	studentManger::GetInstance()->insert_student(stu);
}

void studentManger::shuanchu()
{
	int ID;
	cout << "请输入要删除的ID" << endl;
	cin >> ID;
	studentManger::GetInstance()->delete_student(ID);
}

void studentManger::gengxin()
{
	int ID;
	char name[10];
	char banji[20];
	cout << "请输入要更新的ID，然后输入名字，班级" << endl;
	cin >> ID;
	cin >> name >> banji;
	Student stu{ ID, name, banji };
	studentManger::GetInstance()->update_student(stu);
};

void studentManger::chanxun()
{
	int ID;
	cout << "请输入要查询的ID" << endl;
	cin >> ID;
	studentManger::GetInstance()->get_students(ID);
};
