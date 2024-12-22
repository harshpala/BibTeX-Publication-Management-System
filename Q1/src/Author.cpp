#include "../include/Author.h"

// Constructor implementation
Author::Author(const std::string& name, const std::string& affiliation)
: name(name), affiliation(affiliation) {}

// Return the author's name
std::string Author::getName() const {
    return name;
}

// Return the author's affiliation
std::string Author::getAffiliation() const {
    return affiliation;
}

// Check if the author's affiliation matches the specified institute name
bool Author::isFromInstitute(const std::string& instituteName) const {
    return affiliation == instituteName;
}
