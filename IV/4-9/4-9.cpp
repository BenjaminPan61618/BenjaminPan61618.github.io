#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Salary{
	private:
	int num;
	string name;
	double base_salary;
	double post_salary;
	double fund;
	double tax;
	double fact_salary;
	public:
	void input_info(){
    cin >> num;
    cin.ignore();
    getline(cin, name, ' ');
    string temp;
    getline(cin, temp);
    stringstream ss(temp);
    ss >> base_salary >> post_salary >> fund;
}
	void calc(){
    tax = (base_salary + post_salary) * 0.1;
    fact_salary = base_salary + post_salary - fund - tax;
}
void sort_desc(Salary Salary1[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(Salary1[i].fact_salary < Salary1[j].fact_salary){
                Salary temp = Salary1[i];
                Salary1[i] = Salary1[j];
                Salary1[j] = temp;
            }
        }
    }
}

    void print_info(Salary Salary1[], int size){
		cout<<"员工的实发工资是：(降序排列）"<< endl;
        for(int i = 0; i < size; i++){
            cout <<  Salary1[i].num   << "\t"<< Salary1[i].name <<"\t"<<  Salary1[i].base_salary << "\t"<< Salary1[i].post_salary <<"\t"<< Salary1[i].fund <<"\t"<< Salary1[i].tax <<"\t"<< Salary1[i].fact_salary << endl;
        }
    }
};

int main(){

    int num_salaries;
    cin >> num_salaries;
    
    Salary Salary1[num_salaries];
   
    for(int i = 0; i < num_salaries; i++){
        Salary1[i].input_info();
    }
    
  
    for(int i = 0; i < num_salaries; i++){
        Salary1[i].calc();
    }
    

    Salary1[0].sort_desc(Salary1, num_salaries);
    

    Salary1[0].print_info(Salary1, num_salaries);
    
    return 0;
}
