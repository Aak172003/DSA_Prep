class TrieNode
{
public:
    char data;
    // Array of 26 size which data type is TrieNode
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    // Constructor
    TrieNode(char d)
    {
        this->data = d;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        this->isTerminal = false;
    }
};

class Solution
{
public:
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

        int index = ch - 'a';

        TrieNode *child;

        // Present
        if (root->children[index] != NULL)
        {
            // hr ek new node represent child
            child = root->children[index];
        }
        // Not Presenet
        else
        {
            child = new TrieNode(ch);
            root->childCount++;
            root->children[index] = child;
        }

        // call reccursion
        insertWord(child, word.substr(1));
    }

    void fincCommonPrefix(string firstStr, string &ans, TrieNode *root)
    {
        if (root->isTerminal)
            return;

        for (int i = 0; i < firstStr.length(); i++)
        {
            char ch = firstStr[i];

            if (root->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }

            if (root->isTerminal)
                break;
        }
    }

    string longestCommonPrefix(vector<string> &str)
    {

        TrieNode *root = new TrieNode('/');

        for (int i = 0; i < str.size(); i++)
        {
            insertWord(root, str[i]);
        }

        string ans = "";
        string first = str[0];
        fincCommonPrefix(first, ans, root);
        return ans;
    }
};