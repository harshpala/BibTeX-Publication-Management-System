#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <vector>
#include <string>
#include <optional>
#include "Author.h"

using namespace std;

// Publication class definition
class Publication {
private:
    string title;                  // Title of the publication
    string venue;                   // For conferences
    string journal;                 // For journals
    int year;                      // Year of publication
    optional<string> doi;          // Optional DOI for the publication
    vector<Author> authors;        // List of authors
    optional<string> volume;       // Volume (optional, mostly for journals)
    optional<string> number;       // Number (optional, mostly for journals)
    optional<string> pages;        // Pages (optional, mostly for journals)

public:
    // Constructor for initializing a publication with necessary details
    Publication(const string& title, 
                const string& venue, 
                const string& journal,  
                int year, 
                const vector<Author>& authors, 
                const optional<string>& doi = nullopt,
                const optional<string>& volume = nullopt,
                const optional<string>& number = nullopt, 
                const optional<string>& pages = nullopt);

    // Getter for the list of authors
    const vector<Author>& getAuthors() const;

    void display() const;
};

#endif // PUBLICATION_H
