// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}

int nCr(int n,int r)
{
    int num = factorial(n);
    int denom = factorial(r)*factorial(n-r);
    
    int ans = (num/denom);
    return ans;
    
}
int main() {
    int n,r;
    cout<<"Enter n and r :"<<endl;
    cin>>n>>r;
 
    int result = nCr(n,r);
    cout<<"The result is :"<<result<<endl;
   


    return 0;
}