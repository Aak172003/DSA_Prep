/*
LeetCode Link - https://leetcode.com/problems/valid-parentheses/description/
*/

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st; // taking stack for keep tracking the order of the brackets..

        for (auto i : s) // iterate over each and every elements
        {
            // if elements comes likes opening , so just push into stack
            if (i == '(' or i == '{' or i == '[')
                st.push(i);

            // if lets suppose elemets comes like closing , so just checking ,
            // that particular elemets just opposite of stack top elements
            else
            {
                // lets opposite elements is not opposite of stack top elements , then simply return false
                if ((st.empty() || st.top() == '(' and i != ')') || (st.top() == '{' and i != '}') || (st.top() == '[' and i != ']'))
                    return false;
                // if particualr elemets is opposite of stack top elements , jo just pop it

                st.pop();
            }
        }
        // Here check str is empty or not
        return st.empty();

        /*
        APPROACH - 2 
        */
         

        stack<char> st;
        for (auto &ch : s)
        {
            // if during iterating , encounter ( , [ , { then need to push into stack
            // Otherwise goes to check further condition

            if (ch == ')' or ch == '}' or ch == ']')
            {
                // if stack me phle se kuch nhi daala , or direct ')' ,  '}' , ']' so this return false 
                if (st.size() == 0)
                    return false;
                
                // but if phle se kuch hai 
                if (ch == ')')
                {
                    // if stack ke phle pr '(' hai to pop krlenge ,
                    //  otherwise return false krdenge '(' iske alava or kuch mila to 
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                
                // if stack ke phle pr '{' hai to pop krlenge ,
                //  otherwise return false krdenge '{' iske alava or kuch mila to 
                else if (ch == '}')
                {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }

                // if stack ke phle pr '[' hai to pop krlenge ,
                //  otherwise return false krdenge '[' iske alava or kuch mila to 
                else if (ch == ']')
                {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
            else
                st.push(ch);
        }
        // if st.size == 0  , means return true 
        if(st.size()==0)return true;
        return st.size() == 0;
    }
};
