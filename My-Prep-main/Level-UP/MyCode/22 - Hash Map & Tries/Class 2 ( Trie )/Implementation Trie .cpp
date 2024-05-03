#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;

    // Array of 26 size which data type is TrieNode
    TrieNode *children[26];
    bool isTerminal;

    // Constructor
    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        // isTerminal depends on string ke last character pr
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{
    // cout << " Inserting " << word << endl;

    // Base Case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];

    // convert char se index
    // if saara string small ltter me hoga tb ch - 'a' krenge otherwise ch - 'A' krte
    // a aaya a-a = 0th index
    // b aaya b-a = 1st index
    // c aaya c-a = 2nd index
    // d aaya d-a = 3rd index
    int index = ch - 'a';

    TrieNode *child;

    // Present
    if (root->children[index] != NULL)
    {
        // hr ek new node represent child
        child = root->children[index];

        // means child point to next element in sequence
    }
    // Not Presenet
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    // call reccursion
    insertWord(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    // present
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // Not Present
        return false;
    }
    // call reccursion
    return searchWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('-');

    // string s1 = "Aakash";

    insertWord(root, "coding");
    insertWord(root, "code");
    insertWord(root, "coder");
    insertWord(root, "codehelp");
    insertWord(root, "baba");
    insertWord(root, "baby");
    insertWord(root, "babu");
    insertWord(root, "shona");

    // for(int i = 0 ;i <s1.length();i++)
    // {
    //     cout<<i<<" substr pr "<<s1.substr(i)<<endl;
    // }

    cout << "result is : " << searchWord(root, "codehelp") << endl;
    cout << "Searching " << endl;
    if (searchWord(root, "xxx"))
    {
        cout << "String Present" << endl;
    }
    else
    {
        cout << "String Absent " << endl;
    }

    return 0;
}