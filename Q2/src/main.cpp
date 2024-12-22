#include "../include/BibParser.h"
#include "../include/FacultyParser.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string bibFilePath = "data/publist.bib";
    string facultyFilePath = "data/faculty.csv";
    string institute = "IIIT-Delhi";  // Assuming

    try {
        // Parse the faculty list
        vector<string> facultyList = FacultyParser::parse(facultyFilePath);

        if (facultyList.empty()) {
            cerr << "Error: Faculty list is empty. Please check the CSV file." << endl;
            return 1;
        }

        // Parse the BibTeX file
        vector<Publication> publications = BibParser::parse(bibFilePath, facultyList);

        // Display all publications
        for (const auto& pub : publications) {
            pub.display();
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
