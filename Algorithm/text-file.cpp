// #include <iostream>
// #include <dirent.h>
// #include <string.h>
// #include <sys/stat.h>
// #include <fstream>
// #include "encoding.h"

// using namespace std;

// int Checking_For_Text_Files()
// {
//     int txtFileCount = 0;
//     DIR *d;
//     struct dirent *dir;
//     struct stat fileStat;
//     d = opendir(".");

//     if (d)
//     {
//         while ((dir = readdir(d)) != NULL)
//         {
//             if (strstr(dir->d_name, ".txt") != NULL)
//             {
//                 if (stat(dir->d_name, &fileStat) == 0)
//                 {
//                     if (S_ISREG(fileStat.st_mode))
//                     {
//                         txtFileCount++;
//                     }
//                 }
//             }
//         }
//         closedir(d);
//     }

//     // Print the number of text files found
//     if (txtFileCount == 0)
//     {
//         std::cout << "No text files found in the current directory." << std::endl;
//     }
//     else
//     {
//         std::cout << "Found " << txtFileCount << " text file(s) in the current directory." << std::endl;
//     }

//     // Open the directory again to read the files
//     d = opendir(".");
//     if (d)
//     {
//         while ((dir = readdir(d)) != NULL)
//         {
//             if (strstr(dir->d_name, ".txt") != NULL)
//             {
//                 if (stat(dir->d_name, &fileStat) == 0)
//                 {
//                     if (S_ISREG(fileStat.st_mode))
//                     {
//                         std::ifstream file(dir->d_name);
//                         if (file.is_open())
//                         {
//                             std::cout << "Contents of " << dir->d_name << ":\n";
//                             std::string line;
//                             while (std::getline(file, line))
//                             {
//                                 // Encode the line using the Huffman encoding algorithm
//                                 vector<pair<int, char>> frequency = Finding_Frequency_of_each_element(line);
//                                 HuffTree *tree = makeTree(frequency);
//                                 map<char, string> vtr;
//                                 Getting_The_values_for_each_character(tree, "", vtr);

//                                 // Display the encoded content
//                                 std::string encoded = "";
//                                 for (char c : line)
//                                 {
//                                     encoded += vtr[c];
//                                 }
//                                 std::cout << "Encoded content: " << encoded << '\n';
//                             }
//                             file.close();
//                         }
//                         else
//                         {
//                             std::cout << "Unable to open file " << dir->d_name << std::endl;
//                         }
//                     }
//                 }
//             }
//         }
//         closedir(d);
//     }

//     return 0;
// }
#include <iostream>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include "encoding.h"

using namespace std;

HuffTree hufftree;
Compare compare;

string ReadFile(const string &filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        ostringstream content;
        content << file.rdbuf();
        file.close();
        return content.str();
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
        return "";
    }
}

void EncodeAndPrint(const string &content)
{
    vector<pair<int, char>> word_frequency = Finding_Frequency_of_each_element(content);
    sort(word_frequency.begin(), word_frequency.end());

    map<char, string> vtr;
    HuffTree *tree = makeTree(word_frequency);

    Getting_The_values_for_each_character(tree, "", vtr);

    cout << endl;
    cout << "The values for each of the characters are:" << endl;

    for (auto i : vtr)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;
    string encoded_string = "";

    for (auto i : content)
    {
        encoded_string += vtr[i];
    }

    cout << "The original content is:\n"
         << content << endl;
    cout << "The encoded content is:\n"
         << encoded_string << endl;
}

int Checking_For_Text_Files()
{
    int txtFileCount = 0;
    DIR *d;
    struct dirent *dir;
    struct stat fileStat;
    d = opendir(".");

    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            if (strstr(dir->d_name, ".txt") != NULL)
            {
                if (stat(dir->d_name, &fileStat) == 0)
                {
                    if (S_ISREG(fileStat.st_mode))
                    {
                        txtFileCount++;

                        // Read the content of each text file
                        cout << "Contents of " << dir->d_name << ":\n";
                        string fileContent = ReadFile(dir->d_name);
                        if (!fileContent.empty())
                        {
                            cout << fileContent << endl;

                            // Encode and print the content using Huffman algorithm
                            EncodeAndPrint(fileContent);
                        }
                    }
                }
            }
        }
        closedir(d);
    }

    // Print the number of text files found
    if (txtFileCount == 0)
    {
        cout << "No text files found in the current directory." << endl;
    }
    else
    {
        cout << endl; // Separate the file contents from the count
        cout << "Found " << txtFileCount << " text file(s) in the current directory." << endl;
    }

    return 0;
}
