#include <fstream>          // #include = adds a library; <fstream> = file handling library
#include <iostream>         // #include = adds a library; <iostream> = input/output library
#include <string>           // #include = adds a library; <string> = string/text handling library
#include <vector>           // #include = adds a library; <vector> = dynamic array library

using namespace std;        // using = use; namespace = group of names; std = standard namespace


struct LogEntry {           // struct = creates a structure; LogEntry = structure name

    string line;            // string = text data type; line = stores one log line
};


int main() {                 // main() = starting point of C++ program

    ofstream sampleLog("server.log");
    // ofstream = output file stream
    // sampleLog = output file object
    // "server.log" = name of log file
    // opens/creates server.log for writing


    if (!sampleLog) {
    // if = checks a condition
    // !sampleLog = checks whether file opening failed

        cerr << "Unable to create log file." << endl;
        // cerr = error output stream
        // displays error message
        // endl = moves to next line

        return 1;
        // return = sends value back
        // 1 = indicates an error
    }


    sampleLog << "2026-09-09 08:00:00 INFO Server started\n";
    // sampleLog = writes data into the log file
    // << = insertion operator
    // text = log entry
    // \n = moves to the next line


    sampleLog << "2026-09-09 08:10:00 WARNING High memory usage\n";
    // writes a WARNING log entry
    // \n = moves to next line


    sampleLog << "2026-09-09 08:20:00 ERROR Database connection failed\n";
    // writes an ERROR log entry
    // \n = moves to next line


    sampleLog << "2026-09-09 08:30:00 INFO Backup completed\n";
    // writes an INFO log entry
    // \n = moves to next line


    sampleLog << "2026-09-09 08:40:00 CRITICAL Disk space low\n";
    // writes a CRITICAL log entry
    // \n = moves to next line


    sampleLog.close();
    // close() = closes the file
    // sampleLog = file being closed


    ifstream logFile("server.log");
    // ifstream = input file stream
    // logFile = input file object
    // "server.log" = file opened for reading


    if (!logFile) {
    // if = checks a condition
    // !logFile = checks whether file opening failed

        cerr << "Unable to open server.log." << endl;
        // cerr = error output stream
        // displays error message
        // endl = moves to next line

        return 1;
        // 1 = indicates an error
    }


    vector<LogEntry> errors;
    // vector = dynamic array/container
    // <LogEntry> = vector stores LogEntry objects
    // errors = vector name
    // stores critical/error log entries


    string line;
    // string = text data type
    // line = stores one line from the log file


    while (getline(logFile, line)) {
    // while = repeats while condition is true
    // getline = reads one complete line
    // logFile = input file
    // line = stores the line read from file


        if (line.find("ERROR") != string::npos ||
            line.find("CRITICAL") != string::npos) {
        // if = checks a condition
        // line.find("ERROR") = searches for the word ERROR
        // string::npos = special value meaning text was not found
        // != = not equal to
        // || = OR operator
        // line.find("CRITICAL") = searches for the word CRITICAL
        // condition is true if ERROR OR CRITICAL is found


            errors.push_back({line});
            // errors = vector
            // push_back() = adds an element to the end of vector
            // {line} = creates a LogEntry containing the current line
        }
    }


    cout << "=== Critical Log Events ===" << endl;
    // cout = displays output
    // heading = "Critical Log Events"
    // endl = moves to next line


    for (const auto& entry : errors) {
    // for = loop used to process elements
    // const = entry cannot be modified
    // auto = compiler automatically determines the data type
    // & = reference; avoids making a copy
    // entry = current LogEntry object
    // errors = vector being processed


        cout << entry.line << endl;
        // cout = displays output
        // entry.line = accesses line member of LogEntry
        // endl = moves to next line
    }


    cout << "Total critical events: " << errors.size() << endl;
    // cout = displays output
    // "Total critical events: " = text
    // errors.size() = returns number of elements in vector
    // endl = moves to next line
}