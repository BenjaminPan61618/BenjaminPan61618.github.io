#include <iostream>
using namespace std;
class Student
{public:
Student(int n,float s):num(n),score(s){ }
void change(int n,float s){num=n;score=s;}
void display(){cout<<num<<" "<<score<<endl;}
private:
int num;
float score;
};
int main( )
{Student stud(101,78.5);
stud.display( );
stud.change(101,80.5);
stud.display( );
return 0;
}

/* ִ�й��̣�
 * ��������һ����ΪStudent�Ķ���
 * �ڲ��� change �� display ���� public ���ݳ�Ա����
 * �� num �� score ���� private ���ݳ�Ա����
 * �����������ȶ�����һ����Ϊ stud �� Student ����
 * ��ʼ��������Ϊ 101, 78.5
 * Ȼ��ͨ��Student�е�display��Ա����ʹ����ʾ����ʾΪ101 78.5
 * ֮������Student�е�change��Ա���������ݸ�Ϊ101, 80.5
 * Student �����еĳ�Ա�������Զ� Student �ڶ���� private ���ݽ����޸�
 * ���ٴ�ִ��stud.display();����Ӧ���101 80.5
 */

/*
 * ���н����
 * 101 78.5
 * 101 80.5
 */

