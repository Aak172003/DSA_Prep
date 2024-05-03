/*
GFG Link - https://practice.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers5537/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
*/


class Solution
{
	public:
		long long int PowMod(long long int a,long long int b,long long int M)
		{
		    // Code here
		    long long int ans = 1;
		    while(b>0) 
		    {
		    if(b%2!=0)
		    {
		      //  Odd
		        ans = (ans*a)%M;
		    }
		    //  Even
		    a = (a*a)%M;
		    
		  //  Compulsory case , Dive the value of power
		    b>>=1; // n = n/2
		    
		        
		    }
		    return ans%M;
		}
};

