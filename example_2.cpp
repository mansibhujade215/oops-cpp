#include <iostream>          // #include = adds a library; <iostream> = input/output library
#include <string>            // <string> = library for using string data type

using namespace std;         // using = use; namespace = group of names; std = standard namespace

class Student {              // class = creates a class; Student = class name

private:                     // private = accessible only inside the class
    int rollNo;              // int = integer; rollNo = student's roll number
    string name;              // string = text; name = student's name
    int totalDays;           // totalDays = total number of classes
    int presentDays;         // presentDays = number of classes attended

public:                      // public = accessible from outside the class

    Student(int r, string n) // Student = constructor; r and n = parameters
        : rollNo(r), name(n), totalDays(0), presentDays(0) {}
        // : = constructor initializer list
        // rollNo(r) = assigns r to rollNo
        // name(n) = assigns n to name
        // totalDays(0) = starts totalDays at 0
        // presentDays(0) = starts presentDays at 0

    void markAttendance(bool isPresent) {  // void = returns nothing
                                           // markAttendance = function name
                                           // bool = true/false value
                                           // isPresent = attendance status

        totalDays++;                       // ++ = increases value by 1

        if (isPresent) {                   // if = checks a condition
                                           // isPresent = checks true/false

            presentDays++;                 // increases presentDays by 1
        }                                  // } = ends if block
    }                                      // } = ends function

    double getAttendancePercentage() const {
        // double = decimal number
        // getAttendancePercentage = function name
        // const = function does not modify object data

        if (totalDays == 0) {              // == = comparison operator
                                           // checks whether totalDays is zero

            return 0.0;                    // return = sends value back
        }

        return (presentDays * 100.0) / totalDays;
        // presentDays = number of days student attended
        // * = multiplication
        // 100.0 = used to calculate percentage
        // / = division
        // totalDays = total classes
    }

    void display() const {                 // display = function to show details

        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: "
             << getAttendancePercentage()
             << "%" << endl;
        // cout = displays output
        // << = insertion operator
        // endl = moves to next line
    }
};

int main() {                               // main() = starting point of program

    Student s1(101, "Rahul");              // creates Student object s1
                                           // 101 = roll number
                                           // "Rahul" = name

    Student s2(102, "Priya");              // creates Student object s2

    s1.markAttendance(true);               // Rahul = present
    s1.markAttendance(true);               // Rahul = present
    s1.markAttendance(false);              // Rahul = absent

    s2.markAttendance(true);               // Priya = present
    s2.markAttendance(true);               // Priya = present
    s2.markAttendance(true);               // Priya = present

    cout << "=== Attendance Report ===" << endl;
    // cout = output
    // "Attendance Report" = text
    // endl = new line

    s1.display();                          // displays Rahul's attendance
    s2.display();                          // displays Priya's attendance

    return 0;                              // 0 = successful execution
}