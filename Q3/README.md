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
/Q3
│
├── build/                          # Build directory for compiled objects
├── bin/                            # Executable files directory
│   └── project_debug               # Debug build of the project
│   └── project_release             # Release build of the project
├── data/                           # Directory containing sample data files
│   ├── sample.bib                  # Sample BibTeX file with publication data
│   └── faculty.csv                 # CSV file containing faculty names
├── include/                        # Header files for the project
│   ├── BibParser.h                 # Header for the BibParser class
│   ├── FacultyParser.h             # Header for the FacultyParser class
│   ├── Publication.h               # Header for the Publication class
│   └── PublicationsDatabase.h      # Header for managing publications
├── src/                            # Source code files
│   ├── main.cpp                    # Main entry point of the application
│   ├── BibParser.cpp               # Implementation of BibParser class
│   ├── FacultyParser.cpp           # Implementation of FacultyParser class
│   ├── Publication.cpp             # Implementation of Publication class
│   └── PublicationsDatabase.cpp    # Implementation of PublicationsDatabase class
├── setup.sh                        # build configuration
├── Makefile                        # Makefile for building the project
└── README.md                       # Project documentation
```

## How to Build and Run

### **Step 1: Change directory to the Working directory**

Run the below command to move to Working directory:

```bash
cd Q3
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
./bin/project_debug "Arani Bhattacharya" "James Gross"
```
This will display the list of publications for the given authors along with the average number of co-authors.

If no arguments are provided or if there's a mistake, the program will display an appropriate message.

### **Step 5: Input Validation**
- The program ensures that the input for author names is valid (only alphabetic characters and spaces).
  
- If an invalid input is detected, the program will notify you with the following message

```bash
Invalid input: Author names should contain only alphabetic characters and spaces.
```

## **Features**
### **Publications Display**
For each queried author, the program will display the following details:

- Title of the publication.
- Venue or Journal where the paper was published.
- Year of publication.
- DOI (if available).
- Volume, Number, and Pages (if available).
- List of Authors and their affiliations (if known).

### **Average Number of Co-authors**

For each publication associated with the queried author, the program calculates and displays the average number of co-authors.

