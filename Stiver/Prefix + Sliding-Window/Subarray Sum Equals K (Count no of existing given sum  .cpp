/*
Leetcode Link - https://leetcode.com/problems/subarray-sum-equals-k/
YouTube Link - https://youtu.be/MHocw0bP1rA

*/
// Solution - I (Brute force, TLE) -


/*
Since we are very obedient person and don't want to do anything extra from our side.
So, we will try to generate the sum of each subarray and if matches with k , then increment our answer.
Like, this is the most basic thing we can do.
Time Complexity --> O(n ^ 2) // where n is the size of the array
Space Complexity --> O(1) // we are not using anything extra from our side

*/

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size(); // taking the size of the array
        
        int ans = 0; // ans variable to store our count
        
        for(int i = 0; i < n; i++) // traverse from the array
        {
            int sum = arr[i]; // provide sum with arr[i]
            
            if(sum == k) // if element itself equal to k, then also increment count
                ans++;
            
            for(int j = i + 1; j < n; j++) // now moving forward,
            {
                sum += arr[j]; // add elements with sum
                
                if(sum == k) // if at any point they become equal to k
                    ans++; // increment answer
            }
            
        }
        
        return ans; // and at last, return answer
    }
};



// Solution - II (Optimise Approach) -


class Solution {

public:
    int subarraySum(vector<int>& arr, int k) 
    {
        int sum =0,result = 0;
        
        int n = arr.size(); // take the size of the array
        
        int prefix[n]; // make a prefix array to store prefix sum

        // put first value into prefix sum
        prefix[0] = arr[0]; // for element at index at zero, it is same
        
        // making our prefix array , via adding cureent element + Previous element
        for(int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        
        unordered_map<int,int> mp; // declare an unordered map
        
        int ans = 0; // to store the number of our subarrays having sum as 'k'
        
        for(int i = 0; i < n; i++) // traverse from the prefix array
        {
            if(prefix[i] == k) // if it already becomes equal to k, then increment ans
                ans++;
            
            // now, as we discussed find whether (prefix[i] - k) present in map or not
            if(mp.find(prefix[i] - k) != mp.end())
            {

     // if founf , give its mp ki value ( Frequency ) , this add into ans , if value frequency 2 times means add 2 times
     // if key - k exist , so mp[prefix[i]-k] ki frequency value ans me add           
                ans += mp[prefix[i] - k]; // if yes, then add it our answer
                
            }
            
            // If not found , Means our aim is to put that value into map
            mp[prefix[i]]++; // put prefix sum into our map
        }
        
        return ans; // and at last, return our answer
    }
};