#!/bin/bash

# Get the directory where the script is located
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Create directories if they do not exist
mkdir -p "$PROJECT_ROOT/src" "$PROJECT_ROOT/include" "$PROJECT_ROOT/build" "$PROJECT_ROOT/data"

# Create empty source files if they do not exist
[ ! -f "$PROJECT_ROOT/src/main.cpp" ] && touch "$PROJECT_ROOT/src/main.cpp"
[ ! -f "$PROJECT_ROOT/src/Author.cpp" ] && touch "$PROJECT_ROOT/src/Author.cpp"
[ ! -f "$PROJECT_ROOT/src/Publication.cpp" ] && touch "$PROJECT_ROOT/src/Publication.cpp"
[ ! -f "$PROJECT_ROOT/src/BibParser.cpp" ] && touch "$PROJECT_ROOT/src/BibParser.cpp"

# Create empty header files if they do not exist
[ ! -f "$PROJECT_ROOT/include/Author.h" ] && touch "$PROJECT_ROOT/include/Author.h"
[ ! -f "$PROJECT_ROOT/include/Publication.h" ] && touch "$PROJECT_ROOT/include/Publication.h"
[ ! -f "$PROJECT_ROOT/include/BibParser.h" ] && touch "$PROJECT_ROOT/include/BibParser.h"

# Create a sample empty .bib file and a CSV file in the data directory if they do not exist
[ ! -f "$PROJECT_ROOT/data/publist.bib" ] && touch "$PROJECT_ROOT/data/publist.bib"
[ ! -f "$PROJECT_ROOT/data/faculty.csv" ] && touch "$PROJECT_ROOT/data/faculty.csv"

# print the project structure
echo "Project structure created. Directory and file setup:"
echo "
$PROJECT_ROOT/
│
├── src/
│   ├── main.cpp        # Empty source file, main application entry
│   ├── Author.cpp      # Empty source file for Author class
│   ├── Publication.cpp # Empty source file for Publication class
│   └── BibParser.cpp   # Empty source file for BibParser class
│
├── include/
│   ├── Author.h        # Empty header file for the Author class
│   ├── Publication.h   # Empty header file for the Publication class
│   └── BibParser.h     # Empty header file for BibParser class
│
└── data/
    ├── publist.bib     # Empty .bib file for sample data
    └── faculty.csv     # Empty CSV file for faculty data
"
