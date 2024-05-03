
#include <iostream>

using namespace std;

int main()
{
    // const int x = 5; // x is constant

    // // initialization can be done
    // // But but we can't reassign a value
    // x = 10;
    // cout << x << endl;

    // *******************************************************************************

    // 2. pointers without Const

    // int *a = new int;
    // *a = 2;
    // cout << "a address is : " << a << endl;
    // cout << "a value is : " << *a << endl;

    // // Means mai pointer ko kahi or point krwa skta hu  ,
    // // But kisi pointer ki value change nhi kr skta

    // int b = 20;
    // a = &b;
    // cout << "a address is : " << a << endl;
    // cout << "a value is : " << *a << endl;

    // *******************************************************************************

    // 3. Const with pointer( here pointer me address , we can't also change )

    // const int *a = new int(5); // initialise value
    //                    OR
    // int const *a = new int(5); // initialise value

    // *a = 2;  -> give error re-assign error

    // cout << "a address is : " << a << endl;
    // cout << "a value is : " << *a << endl;

    // // Means mai pointer ko kahi or point krwa skta hu  ,
    // // But kisi pointer ki value change nhi kr skta

    // int b = 20;
    // a = &b;

    // cout << "a address is : " << a << endl;
    // cout << "a value is : " << *a << endl;

    // *******************************************************************************

    // 3. pointer Constant but its poiner jisko point kr rha hai ,
    // us address ki value can change

    int *const a = new int(5); // initialise value

    *a = 2; //-> give error re-assign error

    cout << "a address is : " << a << endl;
    cout << "a value is : " << *a << endl;

    // Give Error -> can't assign pointer again

    // int b = 20;
    // a = &b;

    return 0;
}
