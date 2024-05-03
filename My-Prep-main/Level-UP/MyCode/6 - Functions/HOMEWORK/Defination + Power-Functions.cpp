
#include <iostream>
using namespace std;

int main() {
    // 1nd Time Calculate 
    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans=ans*a;
    }
    cout<<"Answer is :"<<ans<<endl;
    
    //  2nd Time Calculate 
    int c,d;
    cin>>c>>d;
    ans=1;
    for(int i=1;i<=d;i++)
    {
        ans=ans*c;
    }
    cout<<"Answer is :"<<ans<<endl;
    
    //  3rd Time Calculate
    Same Repeat Code 
    
    //  4rth Time Calculate 
    Same Repeat Code 

    return 0;
}

//                                       Original Way of use Function  Use Function

//  Hr new new power nikalne ke lie int main me new variable bna kr function ko call krna pdega 

// Powers Function

#include <iostream>
using namespace std;
int power(int a,int b)
{
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans=ans*a;
    }
    return ans ;
}

int main() {
    // 1nd Time Calculate 
    int a,b;
    cin>>a>>b;
    int ans = power(a,b);
    cout<<"Answer is :"<<ans<<endl;
    

    return 0;
}

//                               For Multiple Inputes in Function call

// Powers Function

#include <iostream>
using namespace std;
int power()
{
    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=1;i<=b;i++)
    {
        ans=ans*a;
    }
    return ans ;
}
int main() {
    // 1nd Time Calculate 
    
    int ans = power();
    cout<<"Answer is :"<<ans<<endl;
    int result = power();
    cout<<"Answer is :"<<result<<endl;
    
    // We can use same variable but without again initialise 
    
    ans = power();
    cout<<"Answer is :"<<ans<<endl;
    
    return 0;

}
