
/*
 LeetCode Link https://leetcode.com/problems/sqrtx/


Brute force Approach is

for(int i=0;i<n;i++)
{
    if(n*n==target)
    return i 
}

ki 1 se le kr given (n) tk ka square nikalte jaa 
js point pr value equal hojae jiska hume square root nikalna hai 

So wo hi hamara answer hoga 
*/


// Approach 2             
//  Note If Question says  -  long long int floorSqrt(long long int x) 
//  So Hume saare variable hume long long me krna pdega 


class Solution {
public:
    int mySqrt(int x) 
    {
      int start=0, end=x,ans; 

      long long mid ;  //long long due to some of test cases overflows integer limit.

        while(start<=end)
        {             
            mid=(start+end)/2;

            if(mid*mid==x) return mid;     //if the 'mid' value gives the result,simply return it.

            else if(mid*mid<x)
            {             
                start=mid+1;  //if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
                ans=mid;      //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value. 
            }

            else end=mid-1;  //if 'mid' value encountered gives greater result, we simply discard all the values greater than mid. 
        }
        return ans;   
    }
};

