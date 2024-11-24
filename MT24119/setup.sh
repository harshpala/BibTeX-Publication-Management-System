#!/bin/bash

# Create directories if they do not exist
mkdir -p src include build data

# Create empty source files if they do not exist
[ ! -f src/main.cpp ] && touch src/main.cpp
[ ! -f src/Author.cpp ] && touch src/Author.cpp
[ ! -f src/Publication.cpp ] && touch src/Publication.cpp
[ ! -f src/BibParser.cpp ] && touch src/BibParser.cpp

# Create empty header files if they do not exist
[ ! -f include/Author.h ] && touch include/Author.h
[ ! -f include/Publication.h ] && touch include/Publication.h
[ ! -f include/BibParser.h ] && touch include/BibParser.h

# Create an empty Makefile in the build directory if it does not exist
[ ! -f build/Makefile ] && touch build/Makefile

# Create a sample empty .bib file in the data directory if it does not exist
[ ! -f data/sample.bib ] && touch data/publist.bib

# print the project structure
echo "Project structure created. Directory and file setup:"
echo "
/MT24119
│
├── build/
│   └── Makefile        # Empty, ready for build configuration
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
    └── sample.bib      # Empty .bib file for sample data
"
