#include <iostream>
using namespace std;
/*
this is only work when we put value , no involvemnt of user input

in C++ , when an integer literal starts with a leading 0 ,
//  it is interpretrd as an Octal ( Base 8 )
value . In case of int a = 0647 ,  the value is an octal value that
represent decimal value 423
( 0 x 8^3 + 6 x 8^2 + 4 x 8^1 + 7 x 8^0 ) = 423

*/

int main()
{
    int num = 0100; // interpretted as an octal number
    int num2 = num;
    cout << num << ' ' << num2 << '\n';

    // if user 0647 dega to cin read as 647 , no conversion occur
    // no conversion as cin reads 0100 as 100
    cin >> num;
    num2 = num;
    cout << num << ' ' << num2 << '\n';
    return 0;
}
