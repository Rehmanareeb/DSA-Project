
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <typeinfo>
using namespace std;

class HuffTree
{
public:
    int value;
    char letter;
    HuffTree *Left_Tree;
    HuffTree *Right_Tree;

    HuffTree(int user_value, char c)
    {
        value = user_value;
        letter = c;
        Left_Tree = nullptr;
        Right_Tree = nullptr;
    }
};

class Compare
{
public:
    bool operator()(HuffTree *a, HuffTree *b)
    {
        if (a->value > b->value)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

vector<pair<int, char>> Finding_Frequency_of_each_element(string string_to_be_encoded)
{
    map<int, char> frequency;
    for (int i = 0; i < string_to_be_encoded.size(); i++)
    {
        frequency[string_to_be_encoded[i]]++;
    }
    vector<pair<int, char>> v;
    for (int i = 0; i < string_to_be_encoded.size(); i++)

    {
        if (frequency[string_to_be_encoded[i]] != 0)
        {
            v.push_back(make_pair(frequency[string_to_be_encoded[i]], string_to_be_encoded[i]));
            frequency[string_to_be_encoded[i]] = 0;
        }
    }

    return v;
}

void Print(priority_queue<HuffTree *, vector<HuffTree *>, Compare> q)
{
    while (!q.empty())
    {
        cout << q.top()->letter << " " << q.top()->value << endl;
        q.pop();
    }
    cout << endl;
}

HuffTree *makeTree(vector<pair<int, char>> &frequency)
{

    priority_queue<HuffTree *, vector<HuffTree *>, Compare> q;
    for (int i = 0; i < frequency.size(); i++)
    {
        HuffTree *temp = new HuffTree(frequency[i].first, frequency[i].second);
        q.push(temp);
    }
    // Print(q);

    // Summing the two smallest elements and forming the new node and continuing this process.
    while (q.size() > 1)
    {

        // what I am doing here is getting the first two smallest nodes here of the huffman tree
        // and then adding both of thier values and then making a new node and then pushing it back to the queue.
        HuffTree *left = q.top();
        q.pop();

        HuffTree *right = q.top();
        q.pop();

        // For now I am taking any chracter.
        HuffTree *new_node = new HuffTree(left->value + right->value, '/');
        new_node->Left_Tree = left;
        new_node->Right_Tree = right;
        q.push(new_node);
    }

    return q.top();
}
/*vector<pair<char, string>> &vtr*/

void Getting_The_values_for_each_character(HuffTree *root, string empty_string, map<char, string> &vtr)
{
    if (root == nullptr)
    {
        cout << "The tree is empty" << endl;
        return;
    }
    if (root->letter != '/')
    {
        vtr[root->letter] = empty_string;
        return;
    }
    else
    {
        Getting_The_values_for_each_character(root->Left_Tree, empty_string + "0", vtr);
        Getting_The_values_for_each_character(root->Right_Tree, empty_string + "1", vtr);
    }
}

string Decoding_The_encoded_(HuffTree *tree, string encoded, int &index)
{
    string decoded = "";
    while (index < encoded.size())
    {
        if (tree->letter != '/')
        {
            decoded += tree->letter;
            index++; // increment index here
            return decoded;
        }
        else if (encoded[index] == '0')
        {
            if (tree->Left_Tree != nullptr)
            {
                tree = tree->Left_Tree;
            }
            else
            {
                decoded += tree->letter; // add this line
                return decoded;
            }
        }
        else if (encoded[index] == '1')
        {
            if (tree->Right_Tree != nullptr)
            {
                tree = tree->Right_Tree;
            }
            else
            {
                decoded += tree->letter; // add this line
                return decoded;
            }
        }
        index++; // increment index here
    }
    // If the encoded string ends with a character that is not followed by a '0' or '1',
    // return the decoded string.
    return decoded;
}

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

