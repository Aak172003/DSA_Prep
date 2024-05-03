#include <iostream>
using namespace std;

// Return by Reference  - > Return hum address kr rhe hai ,
//                          jiska return type int& hoga

int &func(int a)
// isme hum return ans kr rhe hai jbki ye local variabel hai
// nums is a local variable
// int& ans  is a reference Variable
{
    int num = a;
    int &ans = num;
    // here num and ans point to the same value
    return ans;
}

// Same issue with pointer

int *fun(int n)
{
    // ptr also point to n ka address , *p is point to n ki value
    int *ptr = &n;
    return ptr;
}

void update2(int &n) // Pass By Reference
// In this Function , humne n ka reference bheja hai ,
// jiski wjh se updation or modification original me dikhega
{
    n++;
}

void update1(int n) // Pass By Value
// In this function , Hamara n ka copy jaata hai ,
// jisse ki Koi bhi updation / modification original me nhi hoga
{
    n++;
}

int main()
{

    int i = 5;
    // create a ref variable
    int &j = i;

    cout << i << endl; // i = 5
    i++;
    cout << i << endl; // i = 6
    j++;
    cout << i << endl; // i = 7
    cout << j << endl; // j = 7

    int n = 5;

    // Pass By Value - ( Call By Value )
    cout << "Before " << n << endl; //  Before 5
    update1(n);
    cout << "After " << n << endl; // After 5

    // Pass By Reference  - ( Call By Reference )
    cout << "Before " << n << endl; //  Before 5
    update2(n);
    cout << "After " << n << endl; // After 6

    // Jb hum input me call by reference ue kr skte hai ,
    // so hum return me bhi referce de skte hai
    fun(n);

    return 0;
}