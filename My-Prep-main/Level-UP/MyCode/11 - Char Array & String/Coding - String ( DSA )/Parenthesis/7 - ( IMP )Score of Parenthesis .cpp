
/*
LeetCode Link - https://leetcode.com/problems/score-of-parentheses/description/

Youtubre for First Bitch - https://www.youtube.com/watch?v=BwF9yyUY3SA
*/



class Solution {
public:
    int scoreOfParentheses(string s) {

      /*
      Using a Stack
      Approach - 1 ( TC - O(N) , SC - O(N))
      */

        stack<int>st;
        
        int score = 0;
        for(int i=0;i<S.length();i++)
        // if "(" encounter , so score push into stack , 
        // or Final score is also 0
            if (S[i] == '(') {
                st.push(score);
                score = 0;
            }

            // if encounter ")" then 
            else {
                score = score+  st.top() + max(score, 1);
                st.pop();
            }
        return score;

// ******************************************************************************************

        /*
        
        // Approach - 2 (TC - O(N) , SC - O(1))
        
        */

        int depth = 0, res = 0;
        
        for(int itr = 0; itr < s.size(); itr++)
        {
            // '(' Aane se '(' depth++ , , or niche check krte rhna ki usse prev wala
            //  uske opposite mil jaega to , depth--
            if(s[itr] == '(') depth++;
            else depth--;
            
			// we need to add the 2^depth, when we are getting any pair like ()
            if(s[itr] == ')' && s[itr-1] == '('){
                res += pow(2, depth);
            }            
        }
        return res;
    }
};