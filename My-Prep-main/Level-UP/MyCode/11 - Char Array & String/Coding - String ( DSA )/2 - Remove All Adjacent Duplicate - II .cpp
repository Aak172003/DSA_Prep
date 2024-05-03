/*
LeetCode Link - https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/
*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st; 
        //store {char, count};
        //  count is the continuous count of char previously encountered;

        int size = s.length();
        for(int i=0; i<size; i++)
        {
            // if not empty , and top ke char ki bt ho rhi hai ,
            //  element == current element , so increase count 
            if(!st.empty() && s[i] == st.top().first)
            { 
               st.top().second++;
            }
            else
            {//insert new char with count 1
                st.push({s[i], 1});
            }
            
            // if current element has size == 3 , then pop the current elemet
            if(st.top().second == k){ 
                st.pop();
            }
        } 

        string res = "";
        while(!st.empty())
        { 
            //recovering remaining string from stack

            // res.append(Nooftimes , character)
            res.append(st.top().second, st.top().first);
            // cout<<"res is "<<res<<endl;
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};