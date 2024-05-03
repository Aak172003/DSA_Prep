
#include <iostream>
using namespace std;

void swap1(int a, int b)
{

    a = a * b; // a = 5 * 6 = 30
    b = a / b; // b = 30 / 6 = 5
    //  now b is 5
    a = a / b; // a = 30 / 5 = 6

    // OR

    a = a + b; // a = 5 + 6 = 11
    b = a - b; // b = 11 -5 = 6
    //  now b is 5
    a = a + b; // a = 30 / 5 = 6

    cout << "value of a is : " << a << endl;
    cout << "value of b is : " << b << '\n';
}

void swap2(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "value of a is : " << a << endl;
    cout << "value of b is : " << b << '\n';
}

// Swapping With XOR without using any extra variable
void swap3(int a, int b)
{
    // lets say
    // a = 5-> 0 1 0 1 b = 6-> 0 1 1 0

    a = a ^ b;
    // a = 5 -> 0 1 0 1
    // b = 6 -> 0 1 1 0
    // XOR   -> 0 0 1 1   = a

    b = a ^ b;
    // a = 0 0 1 1
    // b = 0 1 1 0
    // XOR     0 1 0 1 = 5 = b

    a = a ^ b;
    // a = 0 0 1 1
    // b = 0 1 0 1
    // XOR     0 1 1 0  = 6 = a

    cout << "value of a is : " << a << endl;
    cout << "value of b is : " << b << '\n';
}

int main()
{

    int a = 5;
    int b = 6;
    swap1(a, b);
    swap2(a, b);
    swap3(a, b);

    return 0;
}