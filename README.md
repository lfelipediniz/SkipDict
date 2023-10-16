# DictionaryManipulation

This project aims to develop mechanisms for manipulating a dictionary with word or idiomatic expression definitions (entries) provided by users. Your dictionary should support the operations of insertion, removal, modification, and search for words, as well as the printing of all entries starting with a character defined by the user.

## Table of Contents
- [DictionaryManipulation](#dictionarymanipulation)
  - [Table of Contents](#table-of-contents)
  - [Description](#description)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)

## Description

The objective of this project is to implement a dictionary data structure using skip lists. The dictionary allows users to perform the following operations:

- `insert str1 str2`: Inserts the word `str1` with the definition `str2` into the dictionary.
- `alter str1 str2`: Modifies the definition of the word `str1` to `str2`.
- `remove str1`: Removes the word `str1` from the dictionary.
- `search str1`: Prints the definition of the word `str1`.
- `print ch1`: Prints all words starting with the character `ch1`, followed by their respective definitions in alphabetical order.

Some important points to consider:
- Operations that cannot be completed in some cases are marked as "OPERACAO INVALIDA". For example, trying to alter, remove, or search for non-existent words in the dictionary or inserting a duplicate word.
- If no words start with `ch1`, and the user requests the printing of all words starting with that character, the program should print "NAO HA PALAVRAS INICIADAS POR ch1."

A dictionary entry can have a word with a maximum of 50 characters and a definition of up to 140 characters, including spaces.

## Getting Started

Follow these instructions to set up and use the DictionaryManipulation project.

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. Clone the repository

```bash
git clone https://github.com/your-username/DictionaryManipulation.git
