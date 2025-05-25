# req-dep-graph-76887568
## Project 2: SRS Dependency Graph Generator
### Alan Shiah

## Usage
In order to build the project, run the command 'make' in the root directory. To run the file, use the command
'make run' in the root directory. Finally, to remove the file, use the command 'make clean'.

## Modules
graphParser.h
- Parses given SRS.md file and creates a dependency graph that is then output to SRS-Dependency-Graph.txt

reportParser.h
- Parses given SRS.md file and creates a summary of every dependency that is then output to SRS-Report.txt

txtReader.h
- Given file name, will output every line of file to terminal

## AI Usage
GitHub CoPilot and/or ChatGPT was used in the following ways:
- Clarification for certain parts of the assignment
- How a Makefile works, and how to go about creating one
- How to parse text files
- Examples of parsing text files
- How to strip line buffers from fget
- Autocomplete code feature for efficiency
- Autocomplete comments for efficiency
- Helped create data structure
- Explained memory allocation and free
