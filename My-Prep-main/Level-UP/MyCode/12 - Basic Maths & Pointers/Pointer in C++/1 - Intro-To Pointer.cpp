#include<iostream>
using namespace std;

int main () {

    int num  = 5 ;

    cout << num << endl;

    // address of Operator - &

    cout <<" address of num is " << &num << endl;
    /*
    NOTE - Here * ptr and num both gives same result 
    */
    int *ptr = &num;

    cout << "Address is : " << ptr << endl;
    cout << "value is : " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;

    cout << "Address is : " << p2 << endl;   // Return Address 
    cout << "value is : " << *p2 << endl;    // Return Value 
    // *p means p naam ke pointer me jo value hai wo ek address hai so hume , 
    // jo value pointer me hai uske Address pr jo value hai wo print krde 

    cout << " size of integer is " << sizeof(num) << endl;
    cout << " size of pointer is " << sizeof(ptr) << endl;
    cout << " size of pointer is " << sizeof(p2) << endl;
    
    // Pointer ek variable hai jo sirf Address store krta hai , in HexaDecimal Form 
    // Pointer Always take 8 byte ( Size of pointer - 8 )


    return 0;
}