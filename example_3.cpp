#include <iostream>          // #include = adds a library; <iostream> = input/output library
#include <string>            // <string> = library for using string data type

using namespace std;         // using = use; namespace = group of names; std = standard namespace

class Product {              // class = creates a class; Product = class name

private:                     // private = accessible only inside the class
    int productId;            // int = integer; productId = product ID
    string productName;       // string = text; productName = product name
    double price;             // double = decimal number; price = product price
    int stockQuantity;        // int = integer; stockQuantity = available stock
    static int totalProducts; // static = shared by all objects
                               // totalProducts = counts active Product objects

public:                      // public = accessible from outside the class

    Product(int id, string name, double p, int stock)
        : productId(id), productName(name), price(p), stockQuantity(stock) {
        // Product = constructor
        // id, name, p, stock = parameters
        // : = constructor initializer list
        // productId(id) = assigns id to productId
        // productName(name) = assigns name to productName
        // price(p) = assigns p to price
        // stockQuantity(stock) = assigns stock to stockQuantity

        totalProducts++;     // ++ = increases totalProducts by 1
    }

    inline int getId() const {
        // inline = suggests putting function code directly where called
        // int = function returns integer
        // getId = function name
        // const = does not modify object

        return productId;    // return = sends productId back
    }

    inline string getName() const {
        // string = function returns text
        // getName = function name
        // const = does not modify object

        return productName;  // returns product name
    }

    inline double getPrice() const {
        // double = function returns decimal value
        // getPrice = function name

        return price;        // returns product price
    }

    void updateStock(int quantity) {
        // void = returns nothing
        // updateStock = function name
        // int quantity = new stock quantity

        stockQuantity = quantity; // = assigns quantity to stockQuantity
    }

    static int getTotalProducts() {
        // static = function belongs to class, not a particular object
        // int = returns integer
        // getTotalProducts = function name

        return totalProducts; // returns total number of products
    }

    void display() const {
        // void = returns nothing
        // display = function name
        // const = does not modify object

        cout << "ID: " << productId
             << " | Product: " << productName
             << " | Price: Rs. " << price
             << " | Stock: " << stockQuantity << endl;

        // cout = displays output
        // << = insertion operator
        // endl = moves to next line
    }

    ~Product() {
        // ~Product = destructor
        // destructor runs when an object is destroyed

        totalProducts--;   // -- = decreases totalProducts by 1
    }
};

int Product::totalProducts = 0;
// Product:: = accesses the static member of Product class
// totalProducts = static variable
// = 0 = initializes it with zero

int main() {                 // main() = starting point of program

    Product p1(1001, "Laptop", 55000, 15);
    // Product = class
    // p1 = object name
    // 1001 = product ID
    // "Laptop" = product name
    // 55000 = price
    // 15 = stock quantity

    Product p2(1002, "Mouse", 450, 50);
    // creates second Product object

    Product p3(1003, "Keyboard", 1200, 30);
    // creates third Product object

    cout << "=== Product Catalog ===" << endl;
    // displays heading

    p1.display();             // . = accesses member; display() = calls function
    p2.display();             // displays second product
    p3.display();             // displays third product

    cout << "\nTotal Products in Catalog: "
         << Product::getTotalProducts() << endl;
    // \n = moves to a new line
    // Product:: = accesses class-level function
    // getTotalProducts() = calls static function

    return 0;                 // 0 = successful execution
}