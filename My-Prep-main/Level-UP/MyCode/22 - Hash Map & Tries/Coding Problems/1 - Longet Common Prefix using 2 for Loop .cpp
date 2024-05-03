class Solution
{
public:
    string longestCommonPrefix(vector<string> &str)
    {

        //                                Approach - 1 using Two for Loop

        string ans = "";
        // if(str.size()==NULL)return ans;

        //     0         1       2
        // ["flower","flow","flight"]
        for (int i = 0; i < str[0].size(); i++)
        {
            char ch = str[0][i];
            bool match = true;

            for (int j = 1; j < str.size(); j++)
            {
                if (str[j].size() < i || ch != str[j][i])
                {
                    match = false;
                    break;
                }
            }

            if (match == false)
                break;
            else
            {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};