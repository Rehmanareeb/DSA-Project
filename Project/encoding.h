// Filename: Huffman.h

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <typeinfo>

class HuffTree
{
public:
    int value;
    char letter;
    HuffTree *Left_Tree;
    HuffTree *Right_Tree;

    HuffTree(int user_value, char c);
};

class Compare
{
public:
    bool operator()(HuffTree *a, HuffTree *b);
};

std::vector<std::pair<int, char>> Finding_Frequency_of_each_element(std::string string_to_be_encoded);
void Print(std::priority_queue<HuffTree *, std::vector<HuffTree *>, Compare> q);
HuffTree *makeTree(std::vector<std::pair<int, char>> &frequency);
void Getting_The_values_for_each_character(HuffTree *root, std::string empty_string, std::map<char, std::string> &vtr);
std::string Decoding_The_encoded_(HuffTree *tree, std::string encoded, int &index);

#endif // HUFFMAN_H
