#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>

// Author class definition
class Author {
private:
    std::string name;           // Name of the author
    std::string affiliation;    // Author's affiliation

public:
    // Constructor to initialize an author with name and affiliation
    Author(const std::string& name, const std::string& affiliation);

    // Getter for author's name
    std::string getName() const;

    // Getter for author's affiliation
    std::string getAffiliation() const;

    // Checks if author is from a given institute
    bool isFromInstitute(const std::string& instituteName) const;
};

#endif // AUTHOR_H
