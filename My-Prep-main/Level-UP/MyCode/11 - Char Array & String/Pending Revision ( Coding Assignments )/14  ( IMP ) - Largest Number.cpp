/*

*/

class Solution {
public:
      
    // Way 1                                      Best for Single digit numbers 

    string largestNumber(vector<int>& nums) {
       vector<string>ans;
        // sb elements ko maine string me krdia 
        for(auto str : nums)
        {
            ans.push_back(to_string(str));
        }
        
        // Fenerally by default sort function sort the elements in ascending order 
        sort(ans.begin(), ans.end);
        string result = "";
        for(int i= ans.size()-1; i >= 0; i--)
        {
            result = result + ans[i];
        }

        return result; 
    }

    
    // Way - 2                                      Best for mor than 1 digit number 
    
    // Comparator for sort in decreasing order 
    // Comparator for sort in decreasing order 
    static bool myComp(string a , string b)
    {
        // both string add to make higher values 
        string value1 = a + b;
        string value2 = b + a;
        return value1 > value2;
    }
    string largestNumber(vector<int>& nums) {

        vector<string>ans;
        // sb elements ko maine string me krdia 
        for(auto str : nums)
        {
            ans.push_back(to_string(str));
        }
        
        // Fenerally by default sort function sort the elements in ascending order 
        sort(ans.begin(), ans.end(), myComp);

        // Important condition -> [0,0] after sort max element is on first index 
        // if first element is 0 , it means maximum value is 0
        if(ans[0]=="0")return "0";
        
        string result = "";
        
        for(auto str : ans)
        {
            result = result + str;
        }

        return result;   
    }
    
};