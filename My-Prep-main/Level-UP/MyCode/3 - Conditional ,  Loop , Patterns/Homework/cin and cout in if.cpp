// Important Concepts 

#include <iostream>
using namespace std;
int main() 

{
//   cin in if 
/* 
Means hum -ve , +ve , 0 kuch bhi value daale to hume "Hello World dekhne ko hi milega "
 */
  int n;
  if(cin>>n)
  {
    cout << "Hello World!\n";
  }
  return 0;
  
//   cout in if 
/*
Means hum if me kuch bhi cout daale to wo bhi print hoga or ander ka bhi execcute hoga 
  */
  if(cout<<"Hello Aakash"<<endl)
  {
    cout << "Hello World!\n";
  }
  return 0;

// cin in if 
/*
Means sbhi value ke Lie “hello” print hoga , even if value should be in +ve , -ve or 0
If we put any Special character 
Then print “hi” 
*/
  int num;
  if(cin>>num)
  {
    cout<<"hello";
  }
  else{
    cout<<"hi";
  }
  
// cout in if 
/*
In this , never execute else statement 
*/
  int num = 0;
  if(cout<<num<<endl)
  {
    cout<<"hello";
  }
  else{
    cout<<"hi";
  }
}
