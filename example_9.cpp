#include <iostream>   // #include = includes a library; iostream = input/output library
#include <string>     // #include = includes a library; string = provides string data type
#include <cctype>     // #include = includes a library; cctype = provides character functions

using namespace std;  // using = use; namespace = group of names; std = standard namespace


class Validator {     // class = creates a class; Validator = class name

public:               // public = members can be accessed from outside the class


    bool validate(int marks) const
    // bool = return type; gives true or false
    // validate = function name
    // int = integer data type
    // marks = parameter name
    // const = function cannot modify the object

    {

        return marks >= 0 && marks <= 100;
        // return = sends result back
        // marks >= 0 = checks marks are greater than or equal to 0
        // && = AND operator
        // marks <= 100 = checks marks are less than or equal to 100
        // Both conditions must be true
    }


    bool validate(double amount) const
    // bool = return type
    // validate = function name
    // double = decimal data type
    // amount = parameter name
    // const = function cannot modify the object

    {

        return amount > 0.0 && amount <= 1000000.0;
        // return = sends result back
        // amount > 0.0 = checks amount is greater than 0
        // && = AND operator
        // amount <= 1000000.0 = checks amount is not more than 10,00,000
    }


    bool validate(const string& name) const
    // bool = return type
    // validate = function name
    // const string& = receives a string without copying it
    // name = parameter name
    // const = value cannot be changed
    // & = reference
    // const at the end = function cannot modify the object

    {

        if (name.empty())
        // if = checks a condition
        // name = string variable
        // . = accesses a function
        // empty() = checks whether string is empty

        {

            return false;
            // return = sends result back
            // false = name is not valid
        }


        for (char ch : name)
        // for = loop
        // char = character data type
        // ch = variable that stores one character
        // : = takes characters from
        // name = string being checked

        {

            if (!isalpha(static_cast<unsigned char>(ch)) && ch != ' ')
            // if = checks condition
            // isalpha() = checks whether character is an alphabet
            // static_cast = converts one data type into another
            // unsigned char = converted character type
            // ch = current character
            // && = AND operator
            // ch != ' ' = checks character is not a space
            // ! = NOT operator

            {

                return false;
                // return = sends result back
                // false = name is invalid
            }
        }


        return true;
        // return = sends result back
        // true = name is valid
    }
};


int main()
// int = integer return type
// main = starting function of the program
// () = no parameters

{

    Validator validator;
    // Validator = class name
    // validator = object name
    // Creates an object of Validator class


    cout << boolalpha;
    // cout = displays output
    // << = insertion operator
    // boolalpha = prints true/false instead of 1/0


    cout << "Marks 88 valid: "
         << validator.validate(88)
         << endl;
    // cout = displays output
    // "Marks 88 valid: " = text displayed
    // validator = object name
    // . = accesses member function
    // validate(88) = calls validate(int)
    // 88 = integer value
    // endl = moves to next line


    cout << "Marks 120 valid: "
         << validator.validate(120)
         << endl;
    // validate(120) = calls validate(int)
    // 120 is greater than 100
    // Therefore result is false


    cout << "Amount 4500.50 valid: "
         << validator.validate(4500.50)
         << endl;
    // validate(4500.50) = calls validate(double)
    // 4500.50 = decimal value
    // Amount is greater than 0 and less than 1000000
    // Therefore result is true


    cout << "Name Priya Sharma valid: "
         << validator.validate(string("Priya Sharma"))
         << endl;
    // string = string data type
    // "Priya Sharma" = name
    // validate() = calls validate(string)
    // Letters and space are allowed
    // Therefore result is true


    cout << "Name Priya123 valid: "
         << validator.validate(string("Priya123"))
         << endl;
    // string("Priya123") = creates a string
    // validate() = calls validate(string)
    // 123 contains numbers
    // Numbers are not allowed in the name
    // Therefore result is false
}