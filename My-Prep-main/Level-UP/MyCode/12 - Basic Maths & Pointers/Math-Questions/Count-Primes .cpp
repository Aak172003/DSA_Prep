/*
Leetcode Link - https://leetcode.com/problems/count-primes/description/
*/

/*
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/
class Solution {
public: 
    //     -------------------------------    Approach - 1 ------------------------------------
    //                                     (Naive Approch )
    /*
    TC - O(N^2)
    */
      bool isPrime(int n)
      {
          if(n==0 || n==1)
          {
              return false;
          }
          for(int i=2;i<n;i++)
          {
              if(n%i!=0)return false;
          }
          return true;
      }
  
    int countPrimes(int n) {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(isPrime(i))count++;
        }
        return count; 

    //-------------------------------    Approach - 2  ------------------------------------
    //                             ( SIEVE OF Eratosthenes)

    /*
    TC - O(N*LOG(LOGN))
    */

    int countPrimes(int n) {

        if(n==0)return 0;

        vector<bool>prime(n,true);
        prime[0] = prime[1]=false;

        int ans = 0;

        for(int i=2;i<n;i++)
        {
            if(prime[i])ans++;

            int j = 2*i;
            while(j<n)
            {
                prime[j] = false;
                j= j+i;    // go to multiples of i 
            }
        }

        return ans;
    }
    
};




