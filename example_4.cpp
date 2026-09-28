#include <iostream>
// #include = includes a library
// <iostream> = input/output library
// Provides cout, cin, endl, etc.

#include <string>
// Includes the string data type.

using namespace std;
// Allows us to use cout and string
// without writing std:: before them.


class Employee {
// class = keyword used to create a class
// Employee = class name

protected:
// protected members can be accessed inside
// this class and its derived classes

    int empId;
    // int = integer data type
    // empId = employee ID

    string name;
    // string = text data type
    // name = employee name

    string department;
    // department = stores department name


public:
// public members can be accessed from outside


    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept) {}

    // Employee = constructor
    // int id = receives employee ID
    // string n = receives employee name
    // string dept = receives department
    //
    // : = member initializer list
    // empId(id) = initializes empId
    // name(n) = initializes name
    // department(dept) = initializes department


    void displayBasicInfo() const {

        // void = function does not return a value
        // displayBasicInfo = function name
        // const = function does not modify the object

        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;

        // cout = displays output
        // << = insertion operator
        // empId = displays employee ID
        // name = displays employee name
        // department = displays department
    }


    virtual double calculateSalary() const = 0;

    // virtual = enables runtime polymorphism
    // double = function returns decimal value
    // calculateSalary = function name
    // const = does not modify object
    // = 0 = pure virtual function
    //
    // Because this is pure virtual,
    // Employee becomes an abstract class.


    virtual ~Employee() = default;

    // ~Employee = destructor
    // virtual = allows proper destruction through base class
    // = default = compiler provides the destructor automatically

};


// Derived class: FullTimeEmployee

class FullTimeEmployee : public Employee {

    // FullTimeEmployee = derived class
    // : public Employee = inherits publicly from Employee


private:

    double monthlySalary;
    // Stores monthly salary


public:

    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {}

    // Constructor of FullTimeEmployee
    // Employee(id, n, dept) = calls base-class constructor
    // monthlySalary(salary) = initializes salary


    double calculateSalary() const override {

        // override = overrides the base-class virtual function

        return monthlySalary;
        // Returns monthly salary
    }


    void display() const {

        // Displays full-time employee information

        displayBasicInfo();

        // Calls function inherited from Employee

        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;

        // Displays employee type
        // calculateSalary() returns salary
        // endl moves to next line
    }

};


// Derived class: PartTimeEmployee

class PartTimeEmployee : public Employee {

    // Inherits Employee publicly


private:

    double hourlyRate;
    // Stores payment per hour

    int hoursWorked;
    // Stores number of hours worked


public:

    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calls Employee constructor
    // Initializes hourlyRate
    // Initializes hoursWorked


    double calculateSalary() const override {

        // Overrides calculateSalary()

        return hourlyRate * hoursWorked;

        // Salary = hourly rate × hours worked
    }


    void display() const {

        displayBasicInfo();

        // Displays common employee information

        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;

        // Displays part-time salary
    }

};


// Derived class: Intern

class Intern : public Employee {

    // Intern inherits from Employee


private:

    double stipend;
    // Stores intern's stipend


public:

    Intern(int id, string n, string dept, double stipendAmount)
        : Employee(id, n, dept),
          stipend(stipendAmount) {}

    // Calls Employee constructor
    // Initializes stipend


    double calculateSalary() const override {

        // Overrides calculateSalary()

        return stipend;
        // Returns intern stipend
    }


    void display() const {

        displayBasicInfo();

        // Displays common employee information

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;

        // Displays intern stipend
    }

};


// Main function

int main() {

    // Program execution starts here


    FullTimeEmployee f1(101, "Amit", "IT", 65000);

    // Creates FullTimeEmployee object f1
    // ID = 101
    // Name = Amit
    // Department = IT
    // Monthly salary = 65000


    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);

    // Creates PartTimeEmployee object p1
    // ID = 102
    // Name = Sneha
    // Department = HR
    // Hourly rate = 250
    // Hours worked = 120


    Intern i1(103, "Rohan", "Marketing", 15000);

    // Creates Intern object i1
    // ID = 103
    // Name = Rohan
    // Department = Marketing
    // Stipend = 15000


    cout << "=== Employee Payroll ===" << endl;

    // Prints the heading


    f1.display();

    // Displays full-time employee details


    p1.display();

    // Displays part-time employee details


    i1.display();

    // Displays intern details

}