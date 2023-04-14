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
		void insert_quantity(){cout<<"������ѧ������:";cin>>quantity;}
		void insert_info(){cin.ignore();cout<<"������ѧ������:";getline(cin,name);cout<<"������ѧ��ѧ��:";cin>>student_id;cout<<"������ѧ���ߵ���ѧ�ɼ�:";cin>>score_math;cout<<"������ѧ��C++�ɼ�:";cin>>score_cpp;cout<<"������ѧ����ѧӢ��ɼ�:";cin>>score_eng;}
		void display_info(){cout<<"����:"<<name<<endl<<"ѧ��:"<<student_id<<endl<<"�ߵ���ѧ�ɼ�:"<<score_math<<endl<<"C++�ɼ�:"<<score_cpp<<endl<<"Ӣ��ɼ�:"<<score_eng<<endl;}
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
		cout<<"������Ҫ��ѯ��ѧ��ѧ��:";
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
			cout<<"δ�ҵ���ѧ����Ϣ"<<endl;
		}
		cout<<"�Ƿ���Ҫ������ѯ(y/n):";
		cin>>ch;
	}while(ch == 'y' || ch == 'Y');
	cout<<"--------------------"<<endl;
	for(i=1;i<=n;i++)
	{
		s[i].display_info();
	}
	return 0;
}

