#ifndef FACULTYPARSER_H
#define FACULTYPARSER_H

#include <vector>
#include <string>

class FacultyParser {
public:
    // Parse the faculty list from a CSV file and return a list of names
    static std::vector<std::string> parse(const std::string& filePath);
};

#endif // FACULTYPARSER_H
