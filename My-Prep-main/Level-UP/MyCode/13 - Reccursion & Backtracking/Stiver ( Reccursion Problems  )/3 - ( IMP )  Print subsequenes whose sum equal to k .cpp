/*
**** Print Subsequence whose sum is equal to k 
( By Recursion )

In this Problem our approach is similar to Pint all subsequences ,Because hum saare subsequence nikalnge then hr subsequence ko add kreneg if after addition .
Sum is equal to k , so put these elements into data Structure which store result 

Pattern – 1 (Print all subsequence whose sum equal to k)
Pattern – 2 (Print Only 1st subsequence, whose sum equal to k)
Pattern – 3 (Print count -> No of subsequence whose sum is equal k)

*/

// P-1
#include<bits/stdc++.h>
using namespace std;

void prinst(int i, vector<int> &ds , int initialsum , int originalsum , int arr[], int n)
{
    // if reach i at the end 
    
    if(i==n)
    {
        // so jo datastructre me daalte time hum s me add kr rhe the 
        // if initialsum == originalsum then print therese and return 
        if(initialsum == originalsum)
        {
            for(auto it : ds)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // Include ->  ds me daalne ka or sum me add krene ka , 
    // then aage index ke lie call marne ka 
    ds.push_back(arr[i]);
    initialsum = initialsum + arr[i];
    prinst(i+1, ds, initialsum, originalsum, arr, n);
    
    
// Exclude -> phle initialsum me jo add hua hai usko substract then pop , 
    // then call Exclude function
    
    initialsum  = initialsum - arr[i];
    ds.pop_back();
    
    prinst(i+1, ds, initialsum, originalsum, arr, n);  
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    // given sum
    int sum = 2;
    vector<int> ds;
    
    // (index , data structure , initial sum , given sum , given array , size)
    prinst(0, ds, 0, sum, arr, n);

    return 0;
}


P-2
// 1 - Way ( take a bool variable initial false , if first subsequence sum is equal to original sum , then make 
// A condition


if(initialsum == originalsum && acknowledge == false)
        {
            acknowledge = true;
            for(auto it : ds)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }

Now acknowledge mark true , so never go inside function because bool mark true ;



P-3

// For part 3 -> make count variable in main and pass this count by refernce 
// (means with & operator)

if(initialsum == originalsum)
count++;
return;


