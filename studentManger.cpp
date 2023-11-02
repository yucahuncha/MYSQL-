#include "studentManger.h"
#include<stdio.h>
#include<iostream>

studentManger::studentManger()														//��ʼ�����ݿ�����
{
	//�������ݿ�����
	//MYSQL *con = mysql_init(NULL);
	//�������ݿ�����ʽ
	mysql_options(con, MYSQL_SET_CHARSET_NAME, "GBK");															

	if (!mysql_real_connect(con, host, name, pw, database_name, port, NULL, 0 ))																//�������ݿ�
	{
		std::cout << "failed to connect" << std::endl;
		exit(1);																				//�������ֱ���˳�
	}

}

studentManger::~studentManger()													//��������ֱ���˳����ݿ��ok
{
	mysql_close(con);
}

bool studentManger::insert_student(Student& stu)																						//����
{
	char sql[1024];																																					//����һ������Ϊ1024�ֽڵı������ڴ��sql���
	sprintf_s(sql, "insert into students (student_id, student_name, class_id) values(%d,'%s', '%s');", stu.student_id, stu.student_name.c_str(), stu.class_id.c_str());
	if (mysql_query(con, sql))																						//�ж��Ƿ��������ӡ������Ϣ
	{
		printf("failed to insert data: Error:%s\n", mysql_error(con));
		return false;
	}
	else
	{
		cout << "���ӳɹ�" << endl;
	}
	return true;
}

bool studentManger::update_student(Student& stu)															//�޸�
{
	char sql[1024];
	sprintf_s(sql, "UPDATE students SET student_name = '%s', class_id = '%s' where student_id = %d", stu.student_name.c_str(), stu.class_id.c_str(), stu.student_id);

	if (mysql_query(con, sql))																									//ִ����䲢�ж��Ƿ����
	{
		printf("failed to update data: Error:%s\n", mysql_error(con));
		return false;
	}
	else
	{
		cout << "�޸ĳɹ�" << endl;
	}
	return true;
}

bool studentManger::delete_student(int student_id)																		//ɾ��
{

	string sql = "DELETE FROM students WHERE student_id = " + to_string(student_id);
	const char* str = sql.c_str();
	if (mysql_query(con, str))																							//�ж��Ƿ��������ӡ������Ϣ
	{
		fprintf(stderr, "failed to detele data: Error:%s\n", mysql_error(con));
		return false;
	}
	else
	{
		cout << "ɾ���ɹ�" << endl;
	}
	return true;
}

/*vector<Student> studentManger::get_students(string condition)																//��ʾ����ѧ��
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
	
	MYSQL_ROW row;																												//��ȡ���ص���Ϣ 
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


char studentManger::get_students(int student_id)																//��ѯ
{
	string sql = "select * from students where student_id = " + to_string(student_id);
	const char* str = sql.c_str();
	if (mysql_query(con, str))																							//�ж��Ƿ��������ӡ������Ϣ
	{
		fprintf(stderr, "failed to select data: Error:%s\n", mysql_error(con));
		return false;
	}
	MYSQL_RES* res = mysql_store_result(con);
	MYSQL_ROW row;															//���������Ϣ������
	while ((row = mysql_fetch_row(res)))
	{
		Student stu;
		stu.student_id = atoi(row[0]);
		stu.student_name = row[1];
		stu.class_id = row[2];
		cout << stu.student_id << ":" << stu.student_name << ":" << stu.class_id << endl;					//��ӡ��Ϣ
	}
}

void studentManger::zhengjia()
{
	int ID;
	char name[10];
	char banji[20];
	cout << "������ѧ����id���������༶" << endl;
	cin >> ID >> name >> banji;
	Student stu{ ID, name, banji };
	studentManger::GetInstance()->insert_student(stu);
}

void studentManger::shuanchu()
{
	int ID;
	cout << "������Ҫɾ����ID" << endl;
	cin >> ID;
	studentManger::GetInstance()->delete_student(ID);
}

void studentManger::gengxin()
{
	int ID;
	char name[10];
	char banji[20];
	cout << "������Ҫ���µ�ID��Ȼ���������֣��༶" << endl;
	cin >> ID;
	cin >> name >> banji;
	Student stu{ ID, name, banji };
	studentManger::GetInstance()->update_student(stu);
};

void studentManger::chanxun()
{
	int ID;
	cout << "������Ҫ��ѯ��ID" << endl;
	cin >> ID;
	studentManger::GetInstance()->get_students(ID);
};
