/*
GFG Link - https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1?page=1&category[]=prefix-sum&sortBy=submissions
*/

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(N). - Using Hash_Map
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int>mpp;
	    mpp[0] = -1;
	    
	    int sum = 0 , maxi = 0,rem;
	    
	    for(int i=0;i<n;i++)
	    {
	       // sum krte jaana ek ek element ka 
	        sum = sum+arr[i];
	       // phr uska remainder nikalna hai 
	        rem = sum % k;

	        
	       // if rem hamare -ve aata hai to usko positive bnane ke lie hum k add kr denge uske 
	        if(rem<0) rem =rem+k;	 
	        
	       // hum check krenge ki wo mpp me hai ki nhi , agr nhi hai to usko add krenge with uski index 
	       //or agr milta hai to 
	        if(mpp.count(rem))
	        {
	           // final index - initial index , so get maximum length
	            maxi = max(maxi,i - mpp[rem]);
	            continue;
	        }
	            mpp[rem] = i;       // insert rem in map along with its index value 
	    }
	    return maxi;
	    
	}
};