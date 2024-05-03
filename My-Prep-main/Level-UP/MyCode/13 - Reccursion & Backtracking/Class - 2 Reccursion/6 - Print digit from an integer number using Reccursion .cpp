#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void extractDigi(int num)
{
    if (num == 0)
        return;

    int digit = num % 10;
    cout << num << " iska digit is : " << digit << endl;
    num = num / 10;
    extractDigi(num);

    // int digit = abs(num % 10);
    // cout <<num << " iska digit is : " << digit << endl;
}

int main()
{
    // print array

    int n = 678;

    cout << endl
         << "The initial digit is : " << n << endl;

    cout << endl;

    extractDigi(n);

    return 0;
}