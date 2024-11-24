#!/bin/bash

# Get the directory where the script is located
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

# Create directories if they do not exist
mkdir -p "$PROJECT_ROOT/src" "$PROJECT_ROOT/include"

# Create empty source files if they do not exist
[ ! -f "$PROJECT_ROOT/src/main.cpp" ] && touch "$PROJECT_ROOT/src/main.cpp"
[ ! -f "$PROJECT_ROOT/src/Author.cpp" ] && touch "$PROJECT_ROOT/src/Author.cpp"
[ ! -f "$PROJECT_ROOT/src/Publication.cpp" ] && touch "$PROJECT_ROOT/src/Publication.cpp"

# Create empty header files if they do not exist
[ ! -f "$PROJECT_ROOT/include/Author.h" ] && touch "$PROJECT_ROOT/include/Author.h"
[ ! -f "$PROJECT_ROOT/include/Publication.h" ] && touch "$PROJECT_ROOT/include/Publication.h"

# print the project structure
echo "Project structure created. Directory and file setup:"
echo "
$PROJECT_ROOT/
│
├── src/
│   ├── main.cpp        # Empty source file, main application entry
│   ├── Author.cpp      # Empty source file for Author class
│   └── Publication.cpp # Empty source file for Publication class
│
└── include/
    ├── Author.h        # Empty header file for the Author class
    └── Publication.h   # Empty header file for the Publication class
"
