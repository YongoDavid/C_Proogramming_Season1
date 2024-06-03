***

## Task
TODO - What is the problem? And where is the challenge?
To create a program called my_cat which does the same thing as the system's cat command used in the command-line.
The cat command concatenates and displays the content of one or more files in the terminal.

## Description
TODO - How have you solved the problem?
The problem was solved by replacing the prohibited functions fgetc and fgets with the following steps:
Using the open function to open each file for reading.
Using the read function to read data from the file into a buffer.
Using the write function to write the content of the buffer to the standard output.
Closing the file descriptor after reading is complete using the close function.

## Installation
TODO - How to install your project? npm install? make? make re?
Fork from my git repo or download zip file to your local machine

## Usage
TODO - How does it work?
Used C programming language to run this program
```
./my_project argument1 argument2
```
