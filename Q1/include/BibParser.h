#ifndef BIBPARSER_H
#define BIBPARSER_H

#include <string>
#include <vector>
#include "Publication.h"
#include "Author.h"

// BibParser class for handling .bib file parsing
class BibParser {
public:
    // Parse a .bib file and return a vector of Publications
    static std::vector<Publication> parse(const std::string& filePath, const std::vector<std::string>& facultyList);

private:
    // Parses a single entry from a .bib file into a Publication object
    static Publication parseEntry(const std::string& entry, const std::vector<std::string>& facultyList);

    // Parses a string of authors into a vector of Author objects
    static std::vector<Author> parseAuthors(const std::string& authorsStr, const std::vector<std::string>& facultyList);

    // Extracts a field from a .bib entry using the specified field name
    static std::string extractField(const std::string& entry, const std::string& fieldName);

    // Validates the entry for formatting, duplicates, and institute affiliation
    static void validateEntry(const std::vector<Author>& authors, const std::vector<std::string>& facultyList);
};

#endif // BIBPARSER_H
