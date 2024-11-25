#include "../include/BibParser.h"
#include <fstream>
#include <sstream>
#include <regex>
#include <set>
#include <cassert>
#include <iostream>

using namespace std;

// Parse the BibTeX file and return a vector of Publication objects
vector<Publication> BibParser::parse(const string& filePath, const vector<string>& facultyList) {
    vector<Publication> publications;

    ifstream file(filePath);
    assert(file.is_open() && "Failed to open BibTeX file."); // Assert file opens successfully

    string line, entry;
    bool inEntry = false; // Track if we're inside an entry
    int braceCount = 0;   // Track brace balance
    regex entryStart(R"(@\w+\{)");   // Match entry start
    regex fieldStart(R"(^\s*\w+\s*=\s*\{)"); // Match start of a valid field
    regex entryEnd(R"(^\s*\}\s*$)"); // Match only the closing brace of an entry

    while (getline(file, line)) {
        if (line.empty()) continue; // Skip empty lines

        if (!inEntry) {
            // Check for entry start
            if (regex_search(line, entryStart)) {
                inEntry = true;
                entry = line + "\n";
                braceCount = count(line.begin(), line.end(), '{') - count(line.begin(), line.end(), '}');
                continue;
            } else if (!regex_match(line, regex(R"(\s*)"))) {
                // Trigger assertion only if the line isn't blank or valid padding
                assert(false && "Invalid Bib file: Unexpected content outside an entry.");
            }
        }

        if (inEntry) {
            entry += line + "\n";

            // Update brace count
            braceCount += count(line.begin(), line.end(), '{');
            braceCount -= count(line.begin(), line.end(), '}');

            // Check for entry end
            if (braceCount == 0) {
                try {
                    // Parse the entry only if it's complete
                    publications.push_back(parseEntry(entry, facultyList));
                } catch (const exception& e) {
                    cerr << "Skipping invalid entry: " << e.what() << endl;
                }
                entry.clear();
                inEntry = false;
            } else if (braceCount < 0) {
                assert(false && "Invalid Bib file: Mismatched closing braces.");
            }
        }
    }

    // Handle unfinished entries or unbalanced braces
    if (inEntry || braceCount != 0) {
        cerr << "Error: Unfinished or malformed BibTeX entry detected." << endl;
        assert(false && "Invalid Bib file: Unfinished entry or unbalanced braces.");
    }

    file.close();
    return publications;
}


// Parse a single BibTeX entry and return a Publication object
Publication BibParser::parseEntry(const string& entry, const vector<string>& facultyList) {
    string title = extractField(entry, "title");
    if (title.empty()) {
        throw invalid_argument("Missing 'title' field in entry.");
    }

    string venue = extractField(entry, "venue"); 
    string journal = extractField(entry, "journal"); 

    string yearStr = extractField(entry, "year");
    if (yearStr.empty()) {
        throw invalid_argument("Missing 'year' field in entry.");
    }

    string authorsStr = extractField(entry, "author");
    if (authorsStr.empty()) {
        throw invalid_argument("Missing 'author' field in entry.");
    }

    string doi = extractField(entry, "doi");
    string volume = extractField(entry, "volume");
    string number = extractField(entry, "number");
    string pages = extractField(entry, "pages");

    vector<Author> authors = parseAuthors(authorsStr, facultyList);
    int year = stoi(yearStr);

    return Publication(title, venue, journal, year, authors, doi, volume, number, pages);
}


// Helper function to trim whitespace
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    return (start == string::npos || end == string::npos) ? "" : str.substr(start, end - start + 1);
}

// Helper function to reformat names from "LastName, FirstName" to "FirstName LastName"
string reformatName(const string& name) {
    size_t commaPos = name.find(',');
    if (commaPos != string::npos) {
        string lastName = trim(name.substr(0, commaPos));
        string firstName = trim(name.substr(commaPos + 1));
        return firstName + " " + lastName; // Return "FirstName LastName"
    }
    return trim(name); // If no comma, return the name as is
}

// Parse the authors string and return a vector of Author objects
vector<Author> BibParser::parseAuthors(const string& authorsStr, const vector<string>& facultyList) {
    vector<Author> authors;
    set<string> authorNames; // Track duplicates
    bool hasInstituteAffiliation = false; // Track if any author is affiliated

    size_t start = 0, end = authorsStr.find(" and ");
    while (end != string::npos) {
        // Extract and reformat author name
        string authorName = reformatName(trim(authorsStr.substr(start, end - start)));

        // Assert no duplicate authors
        assert(authorNames.insert(authorName).second && "Invalid Bib file: Duplicate author in entry.");

        // Check if the author is affiliated with the institute
        bool isAffiliated = find(facultyList.begin(), facultyList.end(), authorName) != facultyList.end();
        if (isAffiliated) hasInstituteAffiliation = true;

        authors.emplace_back(authorName, isAffiliated ? "IIIT-Delhi" : "Unknown");
        start = end + 5; // Move past " and "
        end = authorsStr.find(" and ", start);
    }

    // Process the last author
    string lastAuthor = reformatName(trim(authorsStr.substr(start)));

    // Assert no duplicate authors
    assert(authorNames.insert(lastAuthor).second && "Invalid Bib file: Duplicate author in entry.");

    bool isAffiliated = find(facultyList.begin(), facultyList.end(), lastAuthor) != facultyList.end();
    if (isAffiliated) hasInstituteAffiliation = true;

    authors.emplace_back(lastAuthor, isAffiliated ? "IIIT-Delhi" : "Unknown");

    // Assert that at least one author is affiliated with the institute
    assert(hasInstituteAffiliation && "Invalid Bib file: No authors affiliated with IIIT-Delhi.");
    return authors;
}

// Extract a field's value from a BibTeX entry
string BibParser::extractField(const string& entry, const string& fieldName) {
    // Regex to match the field with its value enclosed in braces
    regex fieldRegex(R"(\b)" + fieldName + R"(\s*=\s*\{([^}]*)\})");
    smatch match;

    if (regex_search(entry, match, fieldRegex)) {
        return match[1].str(); // Return the extracted value
    }

    return ""; // Return empty string if field not found
}

// Validate a BibTeX entry for duplicate authors and affiliations
void BibParser::validateEntry(const vector<Author>& authors, const vector<string>& facultyList) {
    assert(!authors.empty() && "Invalid Bib file: Missing authors."); // Assert authors exist

    set<string> authorNames; // Track duplicates
    bool hasInstituteAffiliation = false;

    for (const auto& author : authors) {
        // Assert no duplicate authors
        assert(authorNames.insert(author.getName()).second && "Invalid Bib file: Duplicate author in entry.");

        // Check if any author is affiliated with the institute
        if (find(facultyList.begin(), facultyList.end(), author.getName()) != facultyList.end()) {
            hasInstituteAffiliation = true;
        }
    }

    // Assert that at least one author is affiliated
    assert(hasInstituteAffiliation && "Invalid Bib file: No authors affiliated with IIIT-Delhi.");
}
