#include <iostream>
#include <string>
using namespace std;

class Student{
	private:
    	int quantity;
    	string name;
		long student_id;
		int score_math;
		int score_cpp;
		int score_eng;
	public:
		void insert_quantity(){cout<<"请输入学生总数:";cin>>quantity;}
		void insert_info(){cin.ignore();cout<<"请输入学生姓名:";getline(cin,name);cout<<"请输入学生学号:";cin>>student_id;cout<<"请输入学生高等数学成绩:";cin>>score_math;cout<<"请输入学生C++成绩:";cin>>score_cpp;cout<<"请输入学生大学英语成绩:";cin>>score_eng;}
		void display_info(){cout<<"姓名:"<<name<<endl<<"学号:"<<student_id<<endl<<"高等数学成绩:"<<score_math<<endl<<"C++成绩:"<<score_cpp<<endl<<"英语成绩:"<<score_eng<<endl;}
		int get_quantity() { return quantity; }
		void set_quantity(int q) { quantity = q; }
		long get_student_id() { return student_id; }
		void set_student_id(long id) { student_id = id; }
};

int main()
{
	Student s[100];
	int i, n, id, flag;
	char ch;
	s[0].insert_quantity();
	n = s[0].get_quantity();
	for(i=1;i<=n;i++)
	{
		s[i].insert_info();
	}
	do
	{
		flag = 0;
		cout<<"请输入要查询的学生学号:";
		cin>>id;
		for(i=1;i<=n;i++)
		{
			if(s[i].get_student_id() == id)
			{
				s[i].display_info();
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout<<"未找到该学生信息"<<endl;
		}
		cout<<"是否需要继续查询(y/n):";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
	cout<<"--------------------"<<endl;
	for(i=1;i<=n;i++)
	{
		s[i].display_info();
	}
	return 0;
}

