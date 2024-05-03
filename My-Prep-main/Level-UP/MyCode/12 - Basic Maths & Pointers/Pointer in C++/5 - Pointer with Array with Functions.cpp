#include<iostream>
using namespace std;

int main () {

    int arr[10] = {23, 122, 41, 67};

   // arr or &arr[0] both represent first index address 
    cout <<" address of first memory block is " << arr << endl; 
    cout << arr[0] << endl;
    cout <<" address of first memory block is " << &arr[0] << endl;


    cout << "4th " << *arr << endl;     // Return array ka first index value 
    cout << "5th " << *arr + 1 << endl;  // return 1st index value via *arr , than add 1 to this value 

    cout << "6th " << *(arr + 1) << endl;  
    // in 6th , arr means represent first index address ,
    // and here +1 means data type ka size ek brr add hojaega , 
    // means point to next index

    cout << "7th " << *(arr) + 1 << endl;  // same as line 15

    cout << "8th " << arr[2] << endl;
    //             Or 
    cout << "9th " << *(arr+2) << endl;

   // Another way of accessing 
   int i = 3;
   cout << i[arr] << endl;   // same as arr[i] , where i = 3 
   
   // how i find size of array 
   int temp[10] = {1,2};  // size give 40 Beacuse , 10 elements hoskte hai , or hr ek element 4 byte lega 
   cout << sizeof(temp) << endl;


   cout << " 1st index pr jo value hai int type ki wo kitne size ka hai " <<  sizeof(*temp) << endl;
   cout << " Temo kitne size ka address store krta hai " <<  sizeof(&temp) << endl;

   int *ptr = &temp[0];  
   // 1st index ka address ptr naam ke pointer ko dia jo ki int type ka hai
   cout << sizeof(ptr) << endl ;
   cout << sizeof(*ptr) << endl ;
   cout << sizeof(&ptr) << endl ;  
// same as line 42 because ptr ki value ek address type ka hai , jiska size 8 hota hai hamesha 


   int a[20] = {1,2,3,5};
   // All are way to access Address , give same result

   cout << " ->" << &a[0] << endl; 
   cout << &a << endl;   
   cout << a << endl;


   int *p = &a[0];
   cout << p << endl;
   cout << *p << endl;

   cout << "-> " << &p << endl;

   int arr[10];

    int *ptr = &arr[0];
    cout << ptr << endl;
    ptr = ptr + 1;   
    // means array ke address me same data type ka size or add hojaega one times
    cout << ptr << endl;
    
    return  0;
}