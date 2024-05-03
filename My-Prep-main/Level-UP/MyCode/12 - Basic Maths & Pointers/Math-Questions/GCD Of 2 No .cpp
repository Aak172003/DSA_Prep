/*
GFG Link - https://practice.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1
*/
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	    // if dono me se koi bhi zero hoga, to hum uska
        // alternate wali value return krdenge 
	    if(A==0)return B;
	    if(B==0)return A;
	    
	    while(A>0 && B>0)
	    {
	        if(A>B)
	        {
	            A = A - B;
	        }
	        else
	        {
	            B = B - A;
	        }
	    }
        // if dono me se koi bhi zero hoga, to hum uska
        // alternate wali value return krdenge 
	    return A ==0 ? B : A; 
	      
	} 
};