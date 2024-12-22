#include "../include/BibParser.h"
#include "../include/FacultyParser.h"
#include "../include/PublicationsDatabase.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>
#include <fstream>

using namespace std;

// Validate input: non-empty and contains only alphabetic characters and spaces
bool isValidInput(const string& input) {
    return !input.empty() && all_of(input.begin(), input.end(), [](char c) {
        return isalpha(c) || isspace(c);
    });
}

int main(int argc, char* argv[]) {
    // Check if there are no arguments passed
    if (argc < 2) {
        cerr << "No input given.\nUsage: " << argv[0] << " <author_name_1> [<author_name_2> ...]" << endl;
        return 1;
    }

    vector<string> authorNames;
    for (int i = 1; i < argc; ++i) {
        string author = argv[i];
        if (!isValidInput(author)) {
            cerr << "Invalid input: Author names should contain only alphabetic characters and spaces." << endl;
            return 1;
        }
        authorNames.push_back(author);
    }

    string bibFilePath = "data/publist.bib";  // Path to the BibTeX file
    string facultyFilePath = "data/faculty.csv";  // Path to the faculty CSV file

    // Check if the BibTeX file exists and can be opened
    ifstream bibFile(bibFilePath);
    if (!bibFile) {
        cerr << "Error: The BibTeX file does not exist or cannot be opened: " << bibFilePath << endl;
        return 1;
    }

    try {
        // Parse the faculty list
        vector<string> facultyList = FacultyParser::parse(facultyFilePath);

        // Parse the BibTeX file and construct the database
        vector<Publication> publications = BibParser::parse(bibFilePath, facultyList);
        PublicationsDatabase database;

        for (const auto& publication : publications) {
            database.addPublication(publication);
        }

        // Process each author input
        for (const auto& authorName : authorNames) {
            vector<Publication> authorPublications = database.getPublicationsByAuthor(authorName);

            if (authorPublications.empty()) {
                cout << "No publications found for author: " << authorName << endl;
            } else {
                cout << "Publications for " << authorName << ":\n";

                int totalCoAuthors = 0;
                int publicationCount = 0;

                for (const auto& publication : authorPublications) {
                    publication.display();
                    int coAuthors = publication.getAuthors().size() - 1; // Exclude the author themselves
                    totalCoAuthors += coAuthors;
                    publicationCount++;
                }

                double averageCoAuthors = publicationCount > 0
                                           ? static_cast<double>(totalCoAuthors) / publicationCount
                                           : 0.0;

                cout << "Average number of co-authors per paper: " << averageCoAuthors << endl;
            }

            cout << "-----------------------------------" << endl;
        }

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
