#include <fstream>          // #include = adds a library; <fstream> = file handling library
#include <iostream>         // #include = adds a library; <iostream> = input/output library
#include <sstream>          // #include = adds a library; <sstream> = string stream library
#include <string>           // #include = adds a library; <string> = string/text handling library

using namespace std;        // using = use; namespace = group of names; std = standard namespace


class Student {             // class = creates a class; Student = class name

private:                    // private = accessible only inside the class

    int rollNo;             // int = integer number; rollNo = variable for roll number
    string name;            // string = text; name = variable for student's name
    double marks;            // double = decimal number; marks = variable for student's marks


public:                     // public = accessible from outside the class

    Student() : rollNo(0), marks(0.0) {}
    // Student() = default constructor
    // : = initialization list
    // rollNo(0) = initializes rollNo with 0
    // marks(0.0) = initializes marks with 0.0
    // {} = empty constructor body


    Student(int r, string n, double m)
        : rollNo(r), name(n), marks(m) {}
    // Student = parameterized constructor
    // int r = integer parameter; stores roll number
    // string n = string parameter; stores student name
    // double m = decimal parameter; stores marks
    // : = initialization list
    // rollNo(r) = initializes rollNo using r
    // name(n) = initializes name using n
    // marks(m) = initializes marks using m


    void saveToFile(ofstream& out) const {
    // void = function returns nothing
    // saveToFile = function name
    // ofstream& out = reference to output file stream
    // const = function does not modify the Student object

        out << rollNo << ',' << name << ',' << marks << '\n';
        // out = output file stream
        // << = insertion operator; sends data to file
        // rollNo = writes student's roll number
        // ',' = comma separator
        // name = writes student's name
        // marks = writes student's marks
        // '\n' = moves to the next line in the file
    }


    bool loadFromLine(const string& line) {
    // bool = function returns true or false
    // loadFromLine = function name
    // const string& line = receives one line of text without modifying it

        string rollText;
        // string = text data type
        // rollText = stores roll number as text

        string marksText;
        // string = text data type
        // marksText = stores marks as text

        stringstream stream(line);
        // stringstream = treats a string like a stream
        // stream = object name
        // line = input string used to create the stream


        if (!getline(stream, rollText, ',')) return false;
        // if = checks a condition
        // getline = reads data from the stream
        // stream = source of data
        // rollText = stores extracted roll number
        // ',' = tells getline to stop at comma
        // ! = NOT operator
        // return false = returns false if reading fails


        if (!getline(stream, name, ',')) return false;
        // getline = reads the student's name
        // name = stores extracted name
        // ',' = comma is used as delimiter
        // return false = stops if reading fails


        if (!getline(stream, marksText)) return false;
        // getline = reads the remaining data
        // marksText = stores marks as text
        // return false = stops if reading fails


        rollNo = stoi(rollText);
        // stoi = converts string to integer
        // rollText = text containing roll number
        // rollNo = stores converted integer value


        marks = stod(marksText);
        // stod = converts string to double
        // marksText = text containing marks
        // marks = stores converted decimal value


        return true;
        // return = sends a value back
        // true = indicates successful loading
    }


    void display() const {
    // void = function returns nothing
    // display = function name
    // const = function does not modify the object

        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Marks: " << marks << endl;
        // cout = displays output on screen
        // << = insertion operator
        // "Roll: " = text displayed before roll number
        // rollNo = displays student's roll number
        // " | Name: " = separator and name label
        // name = displays student's name
        // " | Marks: " = separator and marks label
        // marks = displays student's marks
        // endl = moves cursor to the next line
    }
};


int main() {                 // main() = starting point of C++ program

    ofstream outFile("students.csv");
    // ofstream = output file stream
    // outFile = file stream object
    // "students.csv" = file name
    // creates/opens the CSV file for writing


    if (!outFile) {
    // if = checks a condition
    // !outFile = checks whether the file failed to open

        cerr << "Unable to open students.csv for writing." << endl;
        // cerr = error output stream
        // << = insertion operator
        // error message = displayed when file cannot be opened
        // endl = moves to next line

        return 1;
        // return = sends value back
        // 1 = indicates an error
    }


    Student s1(101, "Rahul Patil", 85.5);
    // Student = class name
    // s1 = object name
    // 101 = roll number
    // "Rahul Patil" = student's name
    // 85.5 = student's marks


    Student s2(102, "Priya Sharma", 92.0);
    // s2 = second Student object
    // 102 = roll number
    // "Priya Sharma" = student's name
    // 92.0 = student's marks


    Student s3(103, "Amit Kulkarni", 78.5);
    // s3 = third Student object
    // 103 = roll number
    // "Amit Kulkarni" = student's name
    // 78.5 = student's marks


    s1.saveToFile(outFile);
    // s1 = first Student object
    // . = accesses class member
    // saveToFile() = calls function
    // outFile = sends data to students.csv


    s2.saveToFile(outFile);
    // s2 = second Student object
    // saveToFile() = saves second student's data
    // outFile = output file


    s3.saveToFile(outFile);
    // s3 = third Student object
    // saveToFile() = saves third student's data
    // outFile = output file


    outFile.close();
    // close() = closes the file
    // outFile = file being closed


    ifstream inFile("students.csv");
    // ifstream = input file stream
    // inFile = input file object
    // "students.csv" = file opened for reading


    if (!inFile) {
    // if = checks a condition
    // !inFile = checks whether file opening failed

        cerr << "Unable to open students.csv for reading." << endl;
        // cerr = error output stream
        // displays error message
        // endl = moves to next line

        return 1;
        // 1 = indicates an error
    }


    cout << "=== Student Report ===" << endl;
    // cout = displays output
    // "=== Student Report ===" = heading
    // endl = moves to next line


    string line;
    // string = text data type
    // line = stores one complete line from the file


    while (getline(inFile, line)) {
    // while = repeats while condition is true
    // getline = reads one line from file
    // inFile = input file
    // line = stores the line read from file


        Student student;
        // Student = class name
        // student = object created to store one student's data


        if (student.loadFromLine(line)) {
        // if = checks condition
        // loadFromLine() = loads data from the line
        // line = data passed to the function


            student.display();
            // student = Student object
            // . = accesses class member
            // display() = displays student information
        }
    }
}