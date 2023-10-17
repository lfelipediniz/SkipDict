# SkipLists Dictionary

The SkipLists Dictionary Project aims to develop mechanisms for managing a dictionary containing definitions of words or idiomatic expressions (entries) provided by users. This dictionary is designed to support operations such as insertion, removal, modification, and retrieval of words, as well as the printing of all entries beginning with a character specified by the user. It is a tool that leverages the SkipLists data structure as its primary ally, enabling incredibly fast manipulation for the desired operations.

## Getting Started

To use SkipDict, follow the instructions below:

### Prerequisites

- GCC (GNU Compiler Collection)
- Make

### Installation

1. Clone the repository

    ```bash
    git clone https://github.com/lfelipediniz/SkipDict.git
    ```

2. Navigate to the project directory

    ```bash
    cd SkipDict
    ```

### Usage

1. Compile and run the program using the provided Makefile

    ```bash
    make
    ```

2. Execute the program (with either of the two commands)

    ```bash
    make run
    ```

3. To delete the generated files run

    ```bash
    make clean
    ```

### Explaining the use in more detail

The program input is structured by specifying the operation to be performed, followed by one or two strings of characters, depending on the required operation. Operations should adhere to the following input configuration

1. Insert the word and its definition

    ```bash
    insercao srr1 str2
    ```

2. Change word definition

    ```bash
    alteracao str1 str2
    ```

3. Remove word

    ```bash
    remocao str1 
    ```
4. Search word

    ```bash
    busca str1 
    ```

5. Print all words starting with the letter "ch1" and their definitions

    ```bash
    impressao ch1 
    ```



## Test case

<table align="center">
<thead>
<tr>
<th>Input</th>
<th>Output</th>
</tr>
</thead>
<tbody>
<tr>
<td>insercao trauliteiro pessoa rude<br>
remocao cliche<br>
insercao cliche acao ou fala previsivel devido ao uso excessivo<br>
busca trauliteiro <br>
alteracao cliche palavra ou frase utilizada em exessso <br>
insercao cessionario pessoa beneficiada com a cessao <br>
impressao c <br>
</td>
<td> 
OPERCAO INVALIDA <br>
trauliteiro pessoa rude<br>
cessionario pessoa beneficiada com a cessao <br>
cliche palavra ou frase utilizada em excesso <br>
</td>
</table>

Project for the course ["Algorithm and Data Structure"](https://uspdigital.usp.br/jupiterweb/obterDisciplina?sgldis=SSC0902) at the Institute of Mathematics and Computer Science, University of Sao Paulo



