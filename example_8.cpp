#include <iostream>
// #include = tells the compiler to include a library
// iostream = Input/Output Stream library
// It is used for cout and cin


using namespace std;
// using = use
// namespace = a group/container of names
// std = standard namespace
// This allows us to write cout instead of std::cout


class Complex
// class = creates a class
// Complex = name of the class
// {} = contains the members of the class
{

private:
    // private = these members can be accessed only inside the class

    double real;
    // double = data type for decimal numbers
    // real = variable name
    // Stores the real part of a complex number

    double imag;
    // double = decimal data type
    // imag = imaginary part
    // Stores the imaginary part


public:
    // public = these members can be accessed from outside the class


    Complex(double r = 0.0, double i = 0.0)
    // Complex = constructor name
    // Constructor name is same as class name
    // double r = real value received by constructor
    // = 0.0 means default value is 0.0
    // double i = imaginary value
    // = 0.0 means default value is 0.0

        : real(r), imag(i) {}
        // : = initializer list
        // real(r) = puts r into real
        // imag(i) = puts i into imag
        // {} = constructor body
        // This constructor initializes real and imaginary parts


    Complex operator+(const Complex& other) const
    // Complex = return type
    // operator+ = overloads the + operator
    // const Complex& other = receives another Complex object
    // const = object cannot be modified
    // & = reference
    // other = name of the second object
    // const at the end = function cannot modify current object

    {

        return Complex(real + other.real,
                       imag + other.imag);
        // return = sends a value back
        // Complex(...) = creates a new Complex object
        // real + other.real = adds real parts
        // imag + other.imag = adds imaginary parts
    }


    Complex operator-(const Complex& other) const
    // operator- = overloads the - operator
    // Used for subtraction

    {

        return Complex(real - other.real,
                       imag - other.imag);
        // Subtracts real parts
        // Subtracts imaginary parts
    }


    Complex operator*(const Complex& other) const
    // operator* = overloads the * operator
    // Used for multiplication

    {

        return Complex(
            real * other.real - imag * other.imag,
            // Real part formula:
            // (a+bi)(c+di)
            // Real part = ac - bd

            real * other.imag + imag * other.real
            // Imaginary part formula:
            // Imaginary part = ad + bc
        );
    }


    bool operator==(const Complex& other) const
    // bool = Boolean return type
    // bool gives either true or false
    // operator== = overloads == operator
    // Used to compare two Complex objects

    {

        return real == other.real &&
               imag == other.imag;
        // real == other.real = checks real parts
        // imag == other.imag = checks imaginary parts
        // && = AND operator
        // Both conditions must be true
        // If both are equal → true
        // Otherwise → false
    }


    void display() const
    // void = function does not return anything
    // display = function name
    // const = function does not modify object

    {

        cout << real << " + " << imag << "i" << endl;
        // cout = displays output on screen
        // real = prints real part
        // " + " = prints plus sign
        // imag = prints imaginary part
        // "i" = represents imaginary unit
        // endl = moves cursor to next line
    }
};


int main()
// main() = starting point of C++ program
// Program execution starts from main()

{

    Complex c1(3.0, 4.0);
    // Complex = class name
    // c1 = object name
    // 3.0 = real part
    // 4.0 = imaginary part
    // Creates first complex number: 3 + 4i


    Complex c2(1.0, 2.0);
    // Creates second complex number: 1 + 2i


    cout << "C1: ";
    // Prints C1:

    c1.display();
    // Calls display() function of c1
    // Displays: 3 + 4i


    cout << "C2: ";
    // Prints C2:

    c2.display();
    // Calls display() function of c2
    // Displays: 1 + 2i


    cout << "Sum: ";
    // Prints Sum:

    (c1 + c2).display();
    // c1 + c2 = calls overloaded + operator
    // Adds:
    // 3 + 1 = 4
    // 4 + 2 = 6
    // Result = 4 + 6i
    // display() prints the result


    cout << "Difference: ";
    // Prints Difference:

    (c1 - c2).display();
    // c1 - c2 = calls overloaded - operator
    // 3 - 1 = 2
    // 4 - 2 = 2
    // Result = 2 + 2i


    cout << "Product: ";
    // Prints Product:

    (c1 * c2).display();
    // c1 * c2 = calls overloaded * operator
    // Real part:
    // (3 × 1) - (4 × 2)
    // = 3 - 8
    // = -5
    //
    // Imaginary part:
    // (3 × 2) + (4 × 1)
    // = 6 + 4
    // = 10
    //
    // Result = -5 + 10i
}