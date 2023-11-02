#pragma once
#include<iostream>
#include"mysql.h"
#include<string>
#include<vector>
using namespace std;

typedef struct Student
{
	int student_id;							//�������������ô������
	string student_name;
	string  class_id;

}; Student;


class studentManger
{
	studentManger();					//���캯��
	~studentManger();				//��������


public:
	static studentManger* GetInstance()							//����ģʽ
	{
		static studentManger studentManger;
		return &studentManger;
	}

public:
	bool insert_student(Student& t);							//����
	bool	 update_student(Student& t);						//����
	bool delete_student(int	 studen_id);						//ɾ��
	//vector<Student> get_students(string condition = "");		//��ʾ����ѧ��
	char get_students(int student_id);						//��ѯ����ѧ��
	void zhengjia();
	void shuanchu();
	void gengxin();
	void chanxun();
	
private:
	MYSQL* con = mysql_init(NULL);												//�������ݿ�����ָ��
	//con = mysql_init(NULL);
	const char* host = "154.8.150.243";								//���ݿ��ַ
	const char* name = "student";									//���ݿ��û���
	const char* pw = "frCLdyrdhzj7G63F";										//���ݿ�����
	const char* database_name = "student";			//���ݿ�����
	const int port = 3306;											//�˿�
};

