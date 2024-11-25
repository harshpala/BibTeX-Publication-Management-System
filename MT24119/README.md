# BibTeX Publication Management System

This project parses a BibTeX file containing publication data, processes it, and allows querying publications based on authors' names. It calculates the average number of co-authors for each publication by the queried author.

## Features

- **Parse BibTeX File**: Extracts publication details including title, venue, authors, DOI, and year from a BibTeX file.
- **Query by Author**: Allows querying for a list of publications for one or more authors by name.
- **Co-author Statistics**: Computes the average number of co-authors per publication for a queried author.
- **Faculty Validation**: Checks if at least one author is affiliated with the institution (e.g., "IIIT-Delhi").
- **Input Validation**: Ensures that the input author names are valid (alphabetic characters and spaces).

## Requirements

- **C++17** or higher
- **g++ compiler** (or any C++17 compatible compiler)
- **CMake** (optional, for building the project easily)

### Files:
- **BibParser.h** & **BibParser.cpp**: Contains the logic to parse the BibTeX file and validate its structure.
- **FacultyParser.h** & **FacultyParser.cpp**: Parses the CSV file containing the list of faculty members.
- **Publication.h** & **Publication.cpp**: Represents the Publication data and provides a method to display the publication details.
- **PublicationsDatabase.h**: Stores publications and allows querying by author name.

## Project Structure
```
/MT24119
│
├── build/                          # Build directory for compiled objects
├── bin/                            # Executable files directory
│   └── project_debug               # Debug build of the project
│   └── project_release             # Release build of the project
│
├── src/
│   ├── main.cpp        # Empty source file, main application entry
│   ├── Author.cpp      # Empty source file for Author class
│   └── Publication.cpp # Empty source file for Publication class
│
├── include/
│   ├── Author.h        # Empty header file for the Author class
│   └── Publication.h   # Empty header file for the Publication class
│
├── Makefile                        # Makefile for building the project
└── README.md                       # Project documentation
```

## How to Build and Run

### **Step 1: Change directory to the Working directory**

Run the below command to move to Working directory:

```bash
cd MT24119
```

### **Step 2: bash script files to create the directory and file structures**

use the setup.sh to create the directory and file structures:

```bash
./setup.sh
```
### **Step 3: Compile the Project**

Use the `Makefile` to build the project:

```bash
make debug
```
This will build the debug version of the project. You can also build the optimized version with:
```bash
make release
```
### **Step 4: Run the Program**

Run the program with author names as command-line arguments. For example:

```bash
./bin/project_debug
```
This will display the list of publications for the given authors.

If there's a mistake, the program will display an appropriate message.

## **Features**
### **Publications Display**
For each queried author, the program will display the following details:

- Title of the publication.
- Venue or Journal where the paper was published.
- Year of publication.
- DOI (if available).
- Volume, Number, and Pages (if available).
- List of Authors and their affiliations (if known).


## **Note**
Each Publication object should contain a list of Author objects, representing the authors of the publication. Ensure at least one author has the institute's affiliation.
Data Structure Considerations:

Use STL containers like vector to manage collections of objects (e.g., storing multiple Publication or Author objects).
Consider using map or unordered_map for efficient searching of publications by author name.
Example Scenario Implementation:

Create several Author objects, some affiliated with the institute and others not.
Create a Publication object, adding the Author objects to it.
Implement checks in the Publication class to validate the conditions like having at least one affiliated author.
Handling Optional DOI:

