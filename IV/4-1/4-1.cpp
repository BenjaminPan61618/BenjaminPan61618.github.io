#include <iostream>
using namespace std;
struct Student{
	public:
	long student_id;
	double score;
};

int main()
{
    Student *ptr = new Student[5];
    for (int i = 0; i < 5; i++) {
    cout << "Insert the ID and the score of Student #" << i+1 <<":"<< endl;
    cin >> ptr[i].student_id >> ptr[i].score;
    }
    cout << "Data of 1st student: " << ptr->student_id << " " << ptr->score << endl;
    ptr += 2; 
    cout << "Data of 3rd student: " << ptr->student_id<< " " << ptr->score << endl;
    ptr += 2; 
    cout << "Data of 5th student: " << ptr->student_id << " " << ptr->score << endl;
    delete [] ptr;
    return 0;
}
