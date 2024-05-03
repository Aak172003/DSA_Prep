#include<iostream>
using namespace std;

void print(int *p) {

    cout << *p << endl; 

}

void update(int *p) 
{

   // Jb niche calling ke time epr value dia wo bs copy dia hai, 
   //agr wo update function me modify hota hai to wo original me nhi hoga 

   p = p + 1;   // Call by value 
   cout << "inside "<< p <<endl; 

   *p = *p + 1;  // Call by Reference 
    // Jb niche calling ke time epr value dia wo referce means address dia hai , 
   //agr wo update function me modify hota hai to wo original me bhi hoga , 
   // Because humne uska reference bhi dia hai  
}

int getSum(int *arr, int n) 
{
    // in declaration - we can also write arr[] , and *arr
    cout << endl << "Size : " << sizeof(arr) << endl;

    int sum = 0;
    for(int i=0;i<n;i++) 
    {
        sum += arr[i];
    }
    return sum;
}

int main() {

    int value = 5;
    int *p = &value;

    print(p);  // call print Function 

    cout <<" Before " << *p << endl;

    update(p);  
    // function me pointer pss krte time always hume bs uska name bhejna hai , 
    // kyuki wo variable us function me bna hai dusre fun me hum usko use krne ke lie new variable ,
    // bnana bdega 

    cout <<" After " << *p << endl;

    int arr[6] = {1,2,3,4,5,8};
    // Here we snding the array address from first element 
    cout << "Sum is " << getSum(arr ,6) << endl ; 
    //                   1 + 2 + 3 + 4 + 5 + 8  = 23
    // Here we snding the part ,of array ,
    // means array ka first index ka address na bhej rrr hum usko 3 index se bhej rhe hai 
    cout << "Sum is " << getSum(arr+3 ,3) << endl ;  
    //                   4 + 5 + 8  = 17

    cout << "Sum is " << getSum(arr ,3) << endl ;  
    //                   1 +2 + 3 = 6

    return 0;
}
