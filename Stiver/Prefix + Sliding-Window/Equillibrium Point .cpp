/*
GFG Link - https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1?page=1&category[]=prefix-sum&sortBy=submissions
*/


class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        
        // Prefix sum 
        
        
        int exactsum = 0;
        // Phle hum Poora sum nikal lenge 
        for(int i=0;i<n;i++)
        {
            exactsum +=a[i];
        }
        
        int lsum = 0;
        int rsum = exactsum;
        int i=0;
        
        // then hum do sum lenge lsum , rsum ,
        // rsum meexactsum daal denge 
        // Phr loop chalenge i = 0 se aakhri tk , i = 0 se hm ek ek value lsum me add krenge or rsum me substract
        
        // if kahi lsum or rsum equal hote hai to wohi hume i+1 return krna pdega 
        
        while(i<n)
        {
            lsum = lsum + a[i];
            if(lsum==rsum)
            {
                return i+1;                
            }
            
            rsum = rsum - a[i];
            i++;
        }
        return -1;
    }

};