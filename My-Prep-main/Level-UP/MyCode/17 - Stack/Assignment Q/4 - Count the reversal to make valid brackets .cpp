/*
Gfg Link - https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
Ytube for Approach - 1 ( https://youtu.be/aZTAa6nccp4 )
*/
int countRev(string s)
{
    // Approach - 1 without using stack

    if (s.size() % 2 != 0)
        return -1;
    int open = 0, close = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
            open++;
        else
        {
            if (open > 0)
                open--;
            else
                close++;
        }
    }

    return (open + 1) / 2 + (close + 1) / 2;

    // Approach - 2 Using Stack

    if (s.size() % 2 != 0)
        return -1;
    int count = 0;

    stack<char> st;
    // Remove valid brackets from string using stack
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            st.push(s[i]);
        else
        {
            if (!st.empty() && st.top() == '{')
                st.pop();
            else
            {
                st.push(s[i]);
            }
        }
    }

    // if stack i not empty still , count reversal
    while (!st.empty())
    {
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        if (ch1 == ch2)
            count = count + 1;
        else
            count = count + 2;
    }
    return count;
}
