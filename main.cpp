#include <iostream>
#include <string>
#include <fstream>
using std::cout, std::string, std::cin;

class Employee{
    private:
        string name;
        int id;
        double salary;
    public:
        Employee(): name(""), id(0), salary(0) {}
        Employee(string name_, int id_, double salary_): name(name_), id(id_), salary(salary_) {}
        string getName() const {return name;}
        int getId() const {return id;}
        virtual double getSalary() const {return salary;}
        void setSalary(double newSalary) {salary = newSalary;}  
};

class Manager: public Employee {
    private:
        string department;
    public:
        Manager(string name_, int id_, double salary_, string department_): 
        Employee(name_, id_, salary_), department(department_) {}
        double getSalary() const {return Employee::getSalary() * 1.1;}
        string getDepartment() const {return department;}
};
bool isValidEmployeeData(const string& name, int id, double salary){
    return !name.empty() && id > 0 && salary >= 0;
}
void saveToFile(const Employee employees[], int size, const string& filename){
    std::fstream outfile (filename);
    if (outfile.is_open()){
        for (int i = 0; i < size; i++){
            int id = employees[i].getId();
            string name = employees[i].getName();
            double salary = employees[i].getSalary();
            if (isValidEmployeeData(name, id, salary)) {
                outfile << id << ' ' << name << ' ' << salary << '\n';
            }
        }
    }
    else cout << "Error! File isn't exist!\n";
    outfile.close();
}
int main(){
    // Basic level

    {
    Employee employees[5];
    for (int i = 0; i < 3; i++){
        cout << "Input " << i + 1 << " employee data.\n";
        string name;
        int id;
        double salary;
        cout << "Name: ";
        cin >> name;
        cout << "ID: ";
        cin >> id;
        cout << "Salary: ";
        cin >> salary;
        if (isValidEmployeeData(name, id, salary)){
            Employee newEmployee(name, id, salary);
            employees[i] = newEmployee;
        }
        else {
            cout << "Error! Invalid input!\n";
            i--;
        }
    }
    for (int i = 0; i < 5; i++){
        if (employees[i].getName() != ""){
            cout << "ID: [" << employees[i].getId() << "], "
            << "Name: [" << employees[i].getName() << "], "
            << "Salary: [" << employees[i].getSalary() << "]\n";
        }
    }
    saveToFile(employees, 5, "employees.txt");
    }

    // *

    {
        Employee* employees[4];
        Employee em1("John", 1, 1000);
        Employee em2("Bob", 2, 1000);
        Manager em3("Victor", 3, 5000, "PZ");
        Manager em4("Saul Goodman", 4, 10000, "Lawyer");
        employees[0] = &em1;
        employees[1] = &em2;
        employees[2] = &em3;
        employees[3] = &em4;
        for (int i = 0; i < 4; i++){
            string name = employees[i]->getName();
            double salary = employees[i]->getSalary();
            cout << "Salary " << name << ": " << salary << '\n';
        }
    }
    return 0;
}