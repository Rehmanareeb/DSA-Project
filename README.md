# File Zipping of Text-Files using Huffman encoding 

<img src = "https://www.computerhope.com/jargon/z/zip.png" width = "100"/>


---

## Description

This C++ project demonstrates Huffman encoding for text files. It includes an implementation of the Huffman algorithm for encoding and decoding text data. Additionally, the project provides functionality to discover and read text files in the current directory, allowing users to encode the contents using the Huffman algorithm.

## Huffman Encoding Features

- **Huffman Encoding**: The project contains a Huffman encoding algorithm to compress and decompress text data efficiently.
- **File Discovery**: The program can identify and display the number of text files in the current directory.
- **Read and Encode Files**: Text files found in the directory can be opened, read, and encoded using Huffman encoding.

## Installation

To compile and run this project, ensure you have a C++ compiler installed on your system. If you are using g++, you can compile the program by running the following command in the terminal:

```bash
  g++ main.cpp text-file.cpp encoding.cpp -o huffman_encoder
```

This will compile the project and create an executable file named `huffman_encoder`.

To run the program, use the following command:

```bash
./huffman_encoder.exe
```

## Usage

When you run the program, it will perform the following operations:

1. **Discover Text Files**: Display the number of text files found in the current directory.
2. **Read and Encode Files**: Open, read, and encode each text file found using the Huffman encoding algorithm.

## Huffman Encoding Algorithm

The Huffman encoding algorithm works by assigning variable-length codes to input characters based on their frequencies. The more frequent characters receive shorter codes, resulting in efficient compression.

The provided Huffman encoding algorithm includes the following components:

- **HuffTree Class**: Represents a node in the Huffman tree, storing character information and pointers to left and right child nodes.
- **Finding_Frequency_of_each_element**: Determines the frequency of each character in the input string.
- **makeTree**: Constructs the Huffman tree based on character frequencies.
- **Getting_The_values_for_each_character**: Retrieves the Huffman codes for each character in the tree.
- **Decoding_The_encoded_**: Decodes an encoded string using the Huffman tree.

## Example Usage

```cpp
#include "encoding.h"
#include "text-file.h"
#include <string>

using namespace std;

int main()
{
    
     Checking_For_Text_Files(); //A single funtion call as everything is abstracted.
    return 0;
}
```



## 👏 Acknowledgments
* Suhaib Qazi 22k-5073
* Areeb Ur Rehman Khan 22k-6003


## 🤝 Contributions

Contributions to this project are welcome! If you have ideas for improvements, bug fixes, or additional features, feel free to fork the repository, make your changes, and submit a pull request. Together, we can enhance and expand the capabilities of Huffman encoding for text data.

---

## 📄 License

[MIT](https://github.com/eli64s/readme-ai/blob/main/LICENSE)

---


## Issues
If you find any bugs or issues then just make a Pull Request. Happy coding 😀