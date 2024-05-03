#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }

    int fact = n*factorial(n-1);
    return fact;

}
int main()
{
    int n;
    cout<<"Enter Input no"<<endl;
    cin>>n;
    int fact = factorial(n);
    cout<<"Your output is :"<< fact;
    return 0;
}