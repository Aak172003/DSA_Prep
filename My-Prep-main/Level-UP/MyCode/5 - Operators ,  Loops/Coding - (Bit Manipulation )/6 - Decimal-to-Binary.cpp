
#include <iostream>
#include <math.h>
using namespace std;

int main() {

    //  By Using Division Method 

    int n;
    cin>>n;
    int binaryno = 0;
    int i = 0;
    while(n>0)
    {
        // from this we find remainder 
        int rem = n%2;
        binaryno =(rem *pow(10,i))+binaryno;
        n = n/2;
        i++;
    }
    cout<<binaryno<<endl;


    // By using Bitwise Operator 
    
    int n;
    cin>>n;
    int ans=0;
    int i=0;;
    while(n!=0)
    {
        /* THE NEXT LINE IS USED TO FIND LAST BIT 1 OR 0 HAI ? 
         then bit use hone ke bdd ek brr right shift krdenge */
        
        // Niche Wali line apne ko last bit ka and krke 1 se -> 0 aaya ki 1 , wo dega ,
        //  Then Our Aim is to reverse the these bits 

        int rem = n&1;  
        
        // Use to Find a reverse value , 
        // niche wali line se apna jo ans hai usme hamaara bit store in reverse Form          
        ans =(rem *pow(10,i))+ans;
        
        // Right Shift
        n=n>>1;   // means num/2
        i++;
    }
    cout<<ans<<endl;
}
