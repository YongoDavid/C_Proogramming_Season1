# Welcome to My Ngram
My Ngram is a program developed to count the number of occurrences per character in one or more input texts.
Inspired by the concept of n-grams in computational linguistics, the program extracts contiguous sequences of characters
and provides a count of each unique character found in the input.

## Task
The task is to create a program called my_ngram that counts the number of occurrences per character in a given text or texts.
The challenge lies in efficiently processing the input text"s".
Also implementing the character counting algorithm while ensuring correctness and performance.

## Description
My Ngram is implemented in C and utilizes basic file I/O and string processing techniques.
The program reads input text"s" provided as command-line arguments and counts the occurrences of each character using an array-based approach.
Characters are treated as unsigned char values, allowing for a total of 128 possible characters to be counted.
The program excludes the double quote (") character from counting.
Once the character counts are calculated, the program prints each character along with the number of times it appears, in alphabetical order.

## Installation
To install My Ngram, follow these steps:
a.Clone this repository to your local machine:
    ```bash
    git clone https://github.com/your_username/my_ngram.git
    ```
b.Navigate to the project directory:
    ```bash
    cd my_ngram
    ```
c.Compile the program using the provided Makefile:
    ```bash
    make
    ```
## Usage
To use My Ngram, follow these steps:
a.Compile the program as instructed in the Installation section.
b.Run the program with the following command:
    ```bash
    ./my_ngram text [text2, text3]
    ```
Replace `text`, `text2`, `text3`, etc. with the text or texts you want to analyze. The program will display each character along with the number of times it appears, in alphabetical order.

### The Core Team
