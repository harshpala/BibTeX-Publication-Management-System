#include "../include/Publication.h"
#include <iostream>
using namespace std;

// Constructor to initialize publication data
Publication::Publication(const string& title, 
                         const string& publishedIn, 
                         int year, 
                         const vector<Author>& authors, 
                         const optional<string>& volume,
                         const optional<string>& number, 
                         const optional<string>& pages,
                         const optional<string>& doi)
: title(title), publishedIn(publishedIn), year(year), authors(authors), volume(volume), number(number), pages(pages), doi(doi) {}

// Setter for the optional DOI
void Publication::setDoi(const string& doi) {
    this->doi = doi;
}

// Check if any author is affiliated with the specified institute
bool Publication::hasInstituteAuthor(const string& instituteName) const {
    for (const auto& author : authors) {
        if (author.isFromInstitute(instituteName)) return true;
    }
    return false;
}

string Publication::getPublicationTitle() const {
    return title;
}

// Display the publication details to standard output
void Publication::display() const {
    cout<<"--------------------------"<<endl;
    cout << "Title: " << title
              << "\nVenue of publication: " << publishedIn;
            //   << "\nNumber of authors: " << authors.size();
    cout << "\nAuthors and affiliations:";
    for (const auto& author : authors) {
        cout << "\n  " << author.getName() << " (" << author.getAffiliation() << ")";
    }
    if (doi) cout << "\nDOI: " << "https://doi.org/" << doi.value();
    cout << "\nYear of publication: " << year << endl;
    cout<<endl;
}

