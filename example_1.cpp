#include <iostream>   // #include = adds a library to the program
                      // <iostream> = input/output library
                      // It provides cout, cin, endl, etc.

#include <string>     // Includes the string library
                      // It allows us to use the string data type.

#include <vector>     // Includes the vector library
                      // It allows us to store multiple objects dynamically.

using namespace std;  // Allows us to use cout, string, vector, etc.
                      // without writing std:: before them.


class SoilSensor {    // class = keyword used to create a class
                      // SoilSensor = name of the class
                      // { = starts the class body

private:              // private members can only be accessed inside the class

    string sensorId;       // Stores the unique ID of the sensor
                           // string = text data type
                           // sensorId = variable name

    double moistureLevel;  // Stores the soil moisture percentage
                           // double = decimal number data type

    string timestamp;      // Stores the time of the sensor reading


public:                   // public members can be accessed from outside the class


    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    // SoilSensor = constructor name
    // It has the same name as the class.
    //
    // string id = receives the sensor ID
    // double moisture = receives the moisture value
    // string time = receives the time
    //
    // : = starts the member initializer list
    //
    // sensorId(id) = assigns id to sensorId
    // moistureLevel(moisture) = assigns moisture to moistureLevel
    // timestamp(time) = assigns time to timestamp
    //
    // {} = constructor body


    void readSensor(double newMoisture, string newTime) {

        // void = function does not return any value
        // readSensor = function name
        // double newMoisture = new moisture value
        // string newTime = new time value

        moistureLevel = newMoisture;
        // Updates the old moisture value with the new value

        timestamp = newTime;
        // Updates the old timestamp with the new time
    }


    void displayData() const {

        // void = function does not return a value
        // displayData = function name
        // const = this function will not modify the object

        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;

        // cout = displays output on the screen
        // << = insertion operator
        // "Sensor: " = text displayed on screen
        // sensorId = displays sensor ID
        // " | Moisture: " = displays moisture label
        // moistureLevel = displays moisture value
        // "%" = displays percentage symbol
        // " | Time: " = displays time label
        // timestamp = displays timestamp
        // endl = moves cursor to the next line
    }

};   // }; = ends the SoilSensor class


int main() {

    // main() = starting point of the C++ program
    // int = main function returns an integer value


    vector<SoilSensor> farmSensors;

    // vector = container used to store multiple values/objects
    // <SoilSensor> = vector will store SoilSensor objects
    // farmSensors = name of the vector
    // ; = ends the statement


    farmSensors.emplace_back("S001", 45.2, "08:00");

    // emplace_back() = creates and adds an object at the end of vector
    // "S001" = sensor ID
    // 45.2 = initial moisture level
    // "08:00" = timestamp


    farmSensors.emplace_back("S002", 52.8, "08:00");

    // Creates second SoilSensor object
    // Sensor ID = S002
    // Moisture = 52.8%
    // Time = 08:00


    farmSensors.emplace_back("S003", 38.5, "08:00");

    // Creates third SoilSensor object
    // Sensor ID = S003
    // Moisture = 38.5%
    // Time = 08:00


    cout << "=== Morning Sensor Readings ===" << endl;

    // cout = displays text
    // "=== Morning Sensor Readings ===" = heading
    // endl = moves to next line


    for (const auto& sensor : farmSensors) {

        // for = loop
        // const = sensor object cannot be modified
        // auto = compiler automatically determines the data type
        // & = reference, so a copy is not created
        // sensor = current object
        // : = means "from"
        // farmSensors = loop through all sensor objects

        sensor.displayData();

        // Calls displayData() for every sensor.
    }


    farmSensors[0].readSensor(47.5, "09:00");

    // farmSensors[0] = first sensor in the vector
    // [0] = index of first element
    // . = accesses a function/member of the object
    // readSensor() = updates the sensor reading
    // 47.5 = new moisture level
    // "09:00" = new timestamp


    cout << "\n=== Updated Reading ===" << endl;

    // \n = creates a blank line before the heading
    // cout = displays output
    // endl = moves to next line


    farmSensors[0].displayData();

    // Displays the updated information of the first sensor.

}