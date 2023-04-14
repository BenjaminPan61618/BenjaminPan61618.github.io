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

/* 执行过程：
 * 程序定义了一个名为Student的对象
 * 内部有 change 和 display 两个 public 数据成员函数
 * 和 num 和 score 两个 private 数据成员变量
 * 主函数中首先定义了一个名为 stud 的 Student 类型
 * 初始化其数据为 101, 78.5
 * 然后通过Student中的display成员函数使其显示，显示为101 78.5
 * 之后运行Student中的change成员函数将数据改为101, 80.5
 * Student 对象中的成员函数可以对 Student 内定义的 private 数据进行修改
 * 故再次执行stud.display();函数应输出101 80.5
 */

/*
 * 运行结果：
 * 101 78.5
 * 101 80.5
 */

