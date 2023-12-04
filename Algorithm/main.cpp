#include <encoding.h>
#include <string>

using namespace std;

// Path: encoding.cpp
int main()
{
    string string_to_be_encoded;
    cout << "Enter the string that you want to decode:" << endl;

    getline(cin, string_to_be_encoded);
    cout << "The string you entered is:" << string_to_be_encoded << endl;
    vector<pair<int, char>> word_frequency = Finding_Frequency_of_each_element(string_to_be_encoded);

    sort(word_frequency.begin(), word_frequency.end());

    map<char, string> vtr;
    HuffTree *tree = makeTree(word_frequency);

    Getting_The_values_for_each_character(tree, " ", vtr);

    cout << endl;
    cout << "The values for each of the characters are:" << endl;

    for (auto i : vtr)

    {
        cout << i.first << " " << i.second << endl;
    }

    cout << endl;
    string encoded_string = "";

    for (auto i : string_to_be_encoded)
    {
        encoded_string += vtr[i];
    }

    cout << string_to_be_encoded;
    cout << endl;
    cout << encoded_string << endl;

    string decoded_string = "";

    for (int i = 0; i < encoded_string.size();)
    {

        decoded_string += Decoding_The_encoded_(tree, encoded_string, i);
    }

    cout << "The decoded string is:" << endl;
    cout << decoded_string << endl;

    return 0;
}
