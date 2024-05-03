#include<iostream>
using namespace std;

// Yaha start variable ko humne optional bna dia hai , agr user ne function calling ke time pr ,
// start nhi pss kia to by default mai start ki position =0 se start krunga 

void print(int arr[], int n  , int start = 0) 
{
    for(int i = start; i<n; i++) 
    {
        cout << arr[i] << endl;
    }
}

int main() {

    int arr[5] = {1,4,7,8,9};
    int size = 5;

    print(arr, size);   // 3rd parameter is optional 
    // Agr hum calling ke time pr nhi dete to wo default poora le leta hai

    cout << endl;
    print(arr, size, 2);   // isme humne start ki location dia hai that is not default item 


    return 0;
}