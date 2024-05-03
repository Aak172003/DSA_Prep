
#include <iostream>
using namespace std;

#define PI 3.14 // -- > This is a macros ,
/*
Macros can be constant , through out the program

Macros ->  jo ki ek piece of code hai program ka ,
jo ki replaced by value of macros
without using any memory space

*/

int main()
{

    int r = 5;

    double pi = 3.14; // This will take a memory size of 8 byte

    double area = PI * r * r; // Here we use Macros

    cout << "Area is " << area << endl;

    return 0;
}