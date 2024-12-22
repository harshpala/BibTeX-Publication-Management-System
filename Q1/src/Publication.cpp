#include "../include/Publication.h"
#include <iostream>


using namespace std;

// Constructor to initialize publication data
Publication::Publication(const string& title, 
                         const string& venue, 
                         const string& journal, 
                         int year, 
                         const vector<Author>& authors, 
                         const optional<string>& doi,
                         const optional<string>& volume, 
                         const optional<string>& number, 
                         const optional<string>& pages)
    : title(title), 
      venue(venue),
      journal(journal), 
      year(year), 
      authors(authors), 
      doi(doi), 
      volume(volume), 
      number(number), 
      pages(pages) {}


// Getter for authors
const vector<Author>& Publication::getAuthors() const {
    return authors;
}

// Display the publication details
void Publication::display() const {
    cout << "--------------------------" << endl;
    cout << "Title: " << title;

    // Display venue if present; otherwise, show journal
    if (!venue.empty()) {
        cout << "\nVenue: " << venue;
    } else if (!journal.empty()) {
        cout << "\nJournal: " << journal;
    } else {
        cout << "\nVenue/Journal: N/A";
    }

    cout << "\nYear: " << year;

    // Properly handle DOI
    if (doi && !doi->empty()) {
        cout << "\nDOI: https://doi.org/" << *doi;
    } else {
        cout << "\nDOI: N/A";
    }

    // Handle volume, number, and pages fields properly
    cout << "\nVolume: " << (volume && !volume->empty() ? *volume : "N/A")
              << "\nNumber: " << (number && !number->empty() ? *number : "N/A")
              << "\nPages: " << (pages && !pages->empty() ? *pages : "N/A");

    // Print authors
    cout << "\nAuthors:";
    for (const auto& author : authors) {
        cout << "\n    " << author.getName() << " (" << author.getAffiliation() << ")";
    }

    cout << endl;
}


