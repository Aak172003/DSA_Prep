/*
GFG Link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&category[]=prefix-sum&sortBy=submissions
*/


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        
     /*  This problem can be solved by using Sliding window.
        (we can use sliding window since it is told in question that it contains non- negative integers)
        
        note:- if the question would have mentioned  that it contains -ve integers ,
//               then we would not able to use sliding window.
    */

        int left=0;
        int right=0;
        
        // long long because during adding element , may be it exceed the integer range 
        long long currentsum=0;

        //  suppose if given s = 0 , so we retrun {-1}
        if(s==0)
             return {-1};
           
            
       while(right<=n) 
    /*    
      note :- one can tell why left<=right condition is used .
              It is used because  in the problem it is stated that: In case of multiple subarrays,
              return the subarray indexes which comes first on moving from left to right.
    */
       {
        // if current less than s to hum i ko wohi rkehge o index pr
        // then j ko bdhate jaenge or current sum me add krte jaenge 
        // until it not exceed the give sum s

         if (currentsum>s)
           {
              currentsum -= arr[left];
               left++;
           }
        //    if s se bda hota hai current sum to hum piche left ko 
        // bdha kr current sum me substract kr denge
           else if(currentsum < s)
           {
               currentsum += arr[right];
               ++right;
           }
           else return {left+1,right}; 
       }

       return {-1};
    }
};