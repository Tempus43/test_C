#include <iostream>
#include <string>
#include <vector>

using std::cout, std::string, std::vector;

class Employee{
    private:
        string name;
        int id;
        double salary;
    public:
        Employee(string name_, int id_, double salary_): name(name_), id(id_), salary(salary_) {}
        string getName() {return name;}
        int getId() {return id;}
        double getSalary() {return salary;}
        void setSalary(double newSalary) {salary = newSalary;}  
};
int main(){
    
    return 0;
}