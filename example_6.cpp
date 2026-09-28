#include <iostream>
// Includes input/output library.
// Provides cout and endl.

#include <memory>
// Provides unique_ptr and make_unique().

#include <string>
// Provides string data type.

#include <vector>
// Provides vector container.

using namespace std;
// Allows us to use cout, string, vector, etc.
// without writing std::


class Vehicle {
// Base class for all vehicles.

protected:

    string vehicleId;
    // Stores vehicle ID.

    string registrationNumber;
    // Stores registration number.


public:

    Vehicle(string vid, string reg)
        : vehicleId(vid), registrationNumber(reg) {}

    // Constructor of Vehicle.
    // vid = vehicle ID.
    // reg = registration number.


    void startEngine() const {

        // Function to start the vehicle engine.

        cout << "Engine started for "
             << vehicleId << endl;

        // Displays vehicle ID.
    }


    virtual void displayInfo() const = 0;

    // virtual = enables runtime polymorphism.
    // displayInfo() = function name.
    // const = does not modify object.
    // = 0 = pure virtual function.
    //
    // Vehicle becomes an abstract class.


    virtual ~Vehicle() = default;

    // Virtual destructor.
};


// Truck class

class Truck : public Vehicle {

private:

    double fuelCapacity;
    // Stores fuel capacity of truck.


public:

    Truck(string vid, string reg, double fuel)
        : Vehicle(vid, reg), fuelCapacity(fuel) {}

    // Calls Vehicle constructor.
    // Initializes fuel capacity.


    void displayInfo() const override {

        // Overrides displayInfo().

        cout << "Truck | ";

        // Prints vehicle type.

        Vehicle::displayInfo();

        // Calls displayInfo() of Vehicle.
    }
};


// Delivery Van class

class DeliveryVan : public Vehicle {

private:

    int packageCount;
    // Stores number of packages.


public:

    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {}

    // Calls Vehicle constructor.
    // Initializes package count.


    void displayInfo() const override {

        cout << "Delivery Van | ";

        // Displays vehicle type.

        Vehicle::displayInfo();

        // Calls base-class displayInfo().

        cout << "Packages loaded: "
             << packageCount << endl;

        // Displays number of packages.
    }

};


// Bike class

class Bike : public Vehicle {

private:

    bool hasDeliveryBox;
    // Stores whether delivery box is available.


public:

    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

    // Calls Vehicle constructor.
    // Initializes delivery-box status.


    void displayInfo() const override {

        cout << "Delivery Bike | ";

        // Displays vehicle type.

        Vehicle::displayInfo();

        // Calls base-class function.

        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available"
                                : "Not available")
             << endl;

        // ?: = ternary operator.
        //
        // If hasDeliveryBox is true:
        //     prints "Available"
        //
        // Otherwise:
        //     prints "Not available"
    }

};


int main() {

    // Program execution starts here.


    vector<unique_ptr<Vehicle>> fleet;

    // Creates a vector of smart pointers.
    // Vehicle is the base class.
    // fleet stores different vehicle objects.


    fleet.push_back(
        make_unique<Truck>(
            "V001",
            "MH12-AB-1234",
            10.5
        )
    );

    // Creates a Truck object.
    // Vehicle ID = V001
    // Registration = MH12-AB-1234
    // Fuel capacity = 10.5


    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002",
            "MH12-CD-5678",
            50
        )
    );

    // Creates DeliveryVan object.
    // Vehicle ID = V002
    // Registration = MH12-CD-5678
    // Packages = 50


    fleet.push_back(
        make_unique<Bike>(
            "V003",
            "MH12-EF-9012",
            true
        )
    );

    // Creates Bike object.
    // Vehicle ID = V003
    // Registration = MH12-EF-9012
    // Delivery box = true.


    cout << "=== Fleet Status ===" << endl;

    // Prints heading.


    for (const auto& vehicle : fleet) {

        // for = loop.
        // const = cannot modify.
        // auto = compiler determines data type.
        // & = reference.
        // vehicle = current vehicle.


        vehicle->startEngine();

        // -> accesses function through pointer.
        // Starts engine.


        vehicle->displayInfo();

        // Calls the appropriate displayInfo()
        // of Truck, DeliveryVan or Bike.
        //
        // This demonstrates runtime polymorphism.


        cout << endl;

        // Prints an empty line.
    }

}