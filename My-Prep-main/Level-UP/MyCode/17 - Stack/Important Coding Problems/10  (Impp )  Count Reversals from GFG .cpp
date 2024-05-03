

// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

int countRev(string s)
{
    if (s.length() % 2 != 0)
    {
        return -1;
    }

    int i = 0;
    stack<char> st;
    int ctr = 0;
    while (i < s.length())
    {

        if (s[i] == '{')
        {
            st.push(s[i]);
            i++;
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
                i++;
            }
            else
            {
                s[i] = '{';
                ctr++;
            }
        }
    }

    if (st.size() % 2 != 0)
    {
        return -1;
    }

    else
    {
        return ctr + (st.size() / 2);
    }
}