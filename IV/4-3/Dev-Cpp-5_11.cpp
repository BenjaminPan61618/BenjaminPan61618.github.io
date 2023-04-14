(1)
#include <iostream>
using namespace std;
class Student
{public:
Student(int n,float s):num(n),score(s){ }
void change(int n,float s){num=n;score=s;}
void display(){cout<<num<<""<<score<<endl;}
private:
int num;
float score;
};
int main( )
{const Student stud(101,78.5);
stud.display( );
stud.change(101,80.5);
stud.display( );
return 0;
}
/* ������޷�ͨ�����룬��ʾ����
 * ԭ��
 * ��main�����еĵڶ����޸�Ϊconst Student stud(101,78.5)����main�����ж������һ��Student���͵ĳ������� stud
 * ��ʱstud�ĳ�Ա����ֻ�ܵ��ó�����Ա�����������ܵ��÷ǳ�����Ա������
 * ��main�����У�stud.change(101,80.5)�����޸ĳ�������stud��ֵ������change�������ǳ�����Ա��������˱������ᱨ��
 */



/*
(2)
#include <iostream>
using namespace std;
class Student
{public:
Student(const int n,const float s):num(n),score(s){ }
void change (const int n,const float s) const{num=n; score=s;}
void display() const{cout<<num<<" "<<score<<endl;}
private:
mutable int num;
mutable float score;
};
int main( )
{const Student stud(101,78.5);
stud.display( );
stud.change(101,80.5);
stud.display( );
return 0;
}
*/

/* ������
 * �˳���ԭ���ļ�����Ա�����ĳ��˳�����Ա����
 * ����num, score�ĳ���mutable��
 */

/*
 * ���н����
 * 101 78.5
 * 101 80.5
 */

/*
(3)
#include <iostream>
using namespace std;
class Student
{public:
Student(const int n,const float s):num(n),score(s){ }
void change (const int n,const float s) const{num=n; score=s;}
void display() const{cout<<num<<" "<<score<<endl;}
private:
mutable int num;
mutable float score;
};
int main( )
{Student stud(101,78.5);
Student *p=&stud;
p->display( );
p->change(101,80.5);
p->display( );
return 0;}
*/

/* 
 * ������
 * �����ԭ���򣬴˳��򴴽���һ��ָ��stud�����ָ��p
 * ���ŵ�����p��display���������num��score��ֵ
 * Ȼ�󣬵�����p��change��������num��Ϊ101����score��Ϊ80.5��
 * ����ٴε�����p��display������������޸ĺ��num��score��ֵ
 */

/*
 * ���н����
 * 101 78.5
 * 101 80.5
 */

/*
��4��
#include <iostream>
using namespace std;
class Student
{public:
Student(const int n,const float s):num(n),score(s){ }
void change (const int n,const float s) const{num=n; score=s;}
void display() const{cout<<num<<" "<<score<<endl;}
private:
mutable int num;
mutable float score;
};
int main( )
{Student stud(101,78.5);
const Student *p=&stud;
p->display( );
p->change(101,80.5);
p->display( );
return 0;}
*/

/*
 * ������
 * ����ڣ�3�����˳���ָ��stud�����ָ��p����Ϊָ�򳣶����ָ��
 * ָ�򳣶����ָ��Ҳ����ָ����ͨ���󣬵��ö��󽫱���Ϊ������
 * main�еĵ�������� p->change(101,80.5); �����ͼ�޸Ķ��� stud ��ֵ
 * ����ζ�ţ����change�����д��������������Ӧ����Ϊ����������������ֱ���
 * ��pָ��ĳ�����stud�У�num��score������Ϊmutable���ͣ���������н�����루3��һ��
 */

/*
��5��
#include <iostream>
using namespace std;
class Student
{public:
Student(const int n,const float s):num(n),score(s){ }
void change (const int n,const float s) const{num=n; score=s;}
void display() const{cout<<num<<" "<<score<<endl;}
private:
mutable int num;
mutable float score;
};
int main( )
{Student stud(101,78.5);
Student *const p=&stud;
p->display( );
p->change(101,80.5);
p->display( );
return 0;}
*/

/* 
 * ������
 * ����ڣ�3�����˳���ָ��stud�����ָ��p����һ������ָ��
 * ��˲���ͨ��p���޸�stud�����ֵ��
 * ���ǣ�����Student���е�num��score��Ա����������Ϊmutable
 * ���change���������޸����ǵ�ֵ����ʹ��const������Ҳ����
 */

