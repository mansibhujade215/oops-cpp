#include <iostream>
// Includes input/output library.
// Provides cout and endl.

#include <memory>
// Provides unique_ptr and make_unique().

#include <vector>
// Provides vector container.

using namespace std;
// Allows us to use cout, vector, etc.
// without writing std::


class Shape {
// Base class for all shapes.

public:

    virtual double area() const = 0;

    // virtual = enables runtime polymorphism.
    // double = returns decimal value.
    // area() = function name.
    // const = does not modify object.
    // = 0 = pure virtual function.
    //
    // This makes Shape an abstract class.


    virtual void draw() const = 0;

    // virtual = virtual function.
    // void = does not return any value.
    // draw() = function name.
    // const = does not modify object.
    // = 0 = pure virtual function.


    virtual ~Shape() = default;

    // Virtual destructor.
    // = default means compiler creates it automatically.
};


// Circle class

class Circle : public Shape {

private:

    double radius;
    // Stores radius of circle.


public:

    explicit Circle(double r) : radius(r) {}

    // explicit = prevents unwanted automatic conversion.
    // Circle = constructor.
    // r = radius received from user/program.
    // radius(r) = initializes radius.


    double area() const override {

        // Overrides Shape's area() function.

        return 3.14159265359 * radius * radius;

        // Formula:
        // Area = π × radius × radius
    }


    void draw() const override {

        // Overrides Shape's draw() function.

        cout << "Drawing circle with radius "
             << radius << endl;

        // Displays circle information.
    }
};


// Rectangle class

class Rectangle : public Shape {

private:

    double length;
    // Stores length.

    double width;
    // Stores width.


public:

    Rectangle(double l, double w)
        : length(l), width(w) {}

    // Constructor.
    // l = length.
    // w = width.
    // Initializes length and width.


    double area() const override {

        // Calculates rectangle area.

        return length * width;

        // Formula:
        // Area = length × width
    }


    void draw() const override {

        cout << "Drawing rectangle "
             << length
             << " x "
             << width
             << endl;

        // Displays rectangle dimensions.
    }
};


// Triangle class

class Triangle : public Shape {

private:

    double base;
    // Stores base of triangle.

    double height;
    // Stores height of triangle.


public:

    Triangle(double b, double h)
        : base(b), height(h) {}

    // Constructor.
    // b = base.
    // h = height.


    double area() const override {

        // Calculates triangle area.

        return 0.5 * base * height;

        // Formula:
        // Area = 1/2 × base × height
    }


    void draw() const override {

        cout << "Drawing triangle with base "
             << base
             << " and height "
             << height
             << endl;

        // Displays triangle dimensions.
    }
};


int main() {

    // Program execution starts here.


    vector<unique_ptr<Shape>> shapes;

    // vector = container.
    // unique_ptr = smart pointer.
    // Shape = base class.
    // shapes = vector name.
    //
    // It can store Circle, Rectangle
    // and Triangle objects.


    shapes.push_back(make_unique<Circle>(5.0));

    // Creates Circle object.
    // Radius = 5.0
    // Adds it to vector.


    shapes.push_back(make_unique<Rectangle>(4.0, 6.0));

    // Creates Rectangle.
    // Length = 4.0
    // Width = 6.0


    shapes.push_back(make_unique<Triangle>(3.0, 8.0));

    // Creates Triangle.
    // Base = 3.0
    // Height = 8.0


    cout << "=== CAD Shape System ===" << endl;

    // Prints heading.


    for (const auto& shape : shapes) {

        // for = loop.
        // const = cannot modify.
        // auto = compiler determines type.
        // & = reference.
        // shape = current shape.


        shape->draw();

        // -> accesses function through pointer.
        // Calls the correct draw() function.


        cout << "Area: "
             << shape->area()
             << " square units"
             << endl;

        // Calls the correct area()
        // according to the actual shape.
        //
        // This is runtime polymorphism.
    }

}