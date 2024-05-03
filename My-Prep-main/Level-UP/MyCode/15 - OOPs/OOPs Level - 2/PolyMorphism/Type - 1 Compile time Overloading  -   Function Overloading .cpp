
#include <iostream>
using namespace std;

class Function_Overloading
{
public:
    /*
    Function Overloading -> means same function name ko hum create kr skte hai ,
    without expecti error

    bs hume uska signature change krke function bnana hai


    SOME RULES :
    1 - Different No of Paremeter
    2 - Different Types of Parameter
    3 - But not differ in return type

    */
    int sum(int a, int b)
    {
        return a + b;
    }

    int sum(int a, float b)
    {
        return a + b;
    }

    int sum(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{

    Function_Overloading Fun;
    cout << "the sum is   : " << Fun.sum(5, 10.5f) << endl;
    return 0;
}
