#include "../include/FacultyParser.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> FacultyParser::parse(const string& filePath) {
    vector<string> facultyList;
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Failed to open faculty CSV file: " << filePath << endl;
        return facultyList;
    }

    string line;
    bool isHeader = true;  // Skip the first header line

    while (getline(file, line)) {
        if (isHeader) {
            isHeader = false;
            continue;
        }

        stringstream ss(line);
        string name;
        getline(ss, name, ',');  // Extract the first column (Name)
        
        // Trim leading and trailing whitespace
        size_t start = name.find_first_not_of(" ");
        size_t end = name.find_last_not_of(" ");
        if (start != string::npos && end != string::npos) {
            name = name.substr(start, end - start + 1);
        }

        facultyList.push_back(name);
    }

    file.close();
    return facultyList;
}
