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
/* 结果：无法通过编译，提示报错。
 * 原因：
 * 将main函数中的第二行修改为const Student stud(101,78.5)后，在main函数中定义的是一个Student类型的常量对象 stud
 * 此时stud的成员函数只能调用常量成员函数，而不能调用非常量成员函数。
 * 在main函数中，stud.change(101,80.5)尝试修改常量对象stud的值，但是change函数不是常量成员函数，因此编译器会报错。
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

/* 分析：
 * 此程序将原来的几个成员函数改成了常量成员函数
 * 并将num, score改成了mutable量
 */

/*
 * 运行结果：
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
 * 分析：
 * 相较于原程序，此程序创建了一个指向stud对象的指针p
 * 接着调用了p的display函数输出了num和score的值
 * 然后，调用了p的change函数，将num改为101，将score改为80.5。
 * 最后，再次调用了p的display函数，输出了修改后的num和score的值
 */

/*
 * 运行结果：
 * 101 78.5
 * 101 80.5
 */

/*
（4）
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
 * 分析：
 * 相较于（3），此程序将指向stud对象的指针p定义为指向常对象的指针
 * 指向常对象的指针也可以指向普通对象，但该对象将被视为常对象
 * main中的第五行语句 p->change(101,80.5); 语句试图修改对象 stud 的值
 * 这意味着，如果change函数中传入的两个参数对应的量为常量，编译器会出现报错
 * 但p指向的常对象stud中，num和score被定义为mutable类型，故因此运行结果会与（3）一致
 */

/*
（5）
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
 * 分析：
 * 相较于（3），此程序将指向stud对象的指针p定义一个常量指针
 * 因此不能通过p来修改stud对象的值。
 * 但是，由于Student类中的num和score成员变量被声明为mutable
 * 因此change函数可以修改它们的值，即使在const函数中也可以
 */
