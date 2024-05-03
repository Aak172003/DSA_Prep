
#include <iostream>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;

        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(TrieNode *root, string word)
{

    cout << "now word is : " << word << endl;

    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }

    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

void storeSuggestion(TrieNode *curr, vector<string> &temp, string &prefix)
{
    if (curr->isTerminal)
    {
        temp.push_back(prefix);
    }

    // Give choices
    for (char ch = 'a'; ch < 'z'; ch++)
    {
        int index = ch - 'a';
        TrieNode *next = curr->children[index];

        if (next != NULL)
        {
            // if child exist
            prefix.push_back(ch);
            storeSuggestion(next, temp, prefix);

            prefix.pop_back();
        }
    }
}

vector<vector<string>> getSuggestion(TrieNode *root, string want)
{

    TrieNode *prev = root;
    vector<vector<string>> output;
    string prefix = "";

    for (int i = 0; i < want.size(); i++)
    {
        char ch = want[i];

        int index = ch - 'a';
        TrieNode *curr = prev->children[index];

        if (curr == NULL)
        {
            break;
        }
        else
        {
            // iske ander saare suggestions store krke launag
            vector<string> temp;
            prefix.push_back(ch);
            storeSuggestion(curr, temp, prefix);

            output.push_back(temp);
            prev = curr;
        }
    }

    return output;
}

int main()
{

    TrieNode *root = new TrieNode('/');
    vector<string> v;
    v.push_back("codehelp");
    v.push_back("coding");
    v.push_back("crax");
    v.push_back("coder");

    string want = "cod";

    for (int i = 0; i < v.size(); i++)
    {
        insertWord(root, v[i]);
    }

    vector<vector<string>> ans = getSuggestion(root, want);
    cout << endl
         << "Printing thr answer :  " << endl
         << endl;

    if (ans.size())
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Sorry not found any suggestion ";

    return 0;
}