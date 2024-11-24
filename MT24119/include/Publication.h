#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <vector>
#include <string>
#include <optional>
#include "Author.h"  // Include the Author 
using namespace std;

// Publication class definition
class Publication {
private:
    string title;                  // Title of the publication
    string publishedIn;            // Venue or Journal of publication
    int year;                           // Year of publication
    optional<string> doi;     // Optional DOI for the publication
    vector<Author> authors;        // List of authors
    optional<string> volume;  // Volume (optional, mostly for journals)
    optional<string> number;  // Number (optional, mostly for journals)
    optional<string> pages;   // Pages (optional, mostly for journals)

public:
    // Constructor for initializing a publication with necessary details
    Publication(const string& title, 
                const string& publishedIn, 
                int year, 
                const vector<Author>& authors, 
                const optional<string>& volume = nullopt,
                const optional<string>& number = nullopt, 
                const optional<string>& pages = nullopt,
                const optional<std::string>& doi = nullopt);

    // Setter for DOI (optional)
    void setDoi(const string& doi);

    // Checks if at least one author is affiliated with the specified institute
    bool hasInstituteAuthor(const string& instituteName) const;

    // Method to get the publication title
    string getPublicationTitle() const;

    // Displays publication details
    void display() const;
};

#endif // PUBLICATION_H
