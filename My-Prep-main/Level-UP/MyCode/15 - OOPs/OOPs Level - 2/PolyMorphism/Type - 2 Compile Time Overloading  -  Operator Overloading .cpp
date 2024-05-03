
#include <iostream>
using namespace std;

class operatorOverloading
{
public:
    int val;

    void operator+(operatorOverloading obj2)
    {
        // this for obj1 value
        int value1 = this->val;

        // here obj2 is an object pss hua hai  ,
        // not a pointer
        int value2 = obj2.val;

        cout << (value2 - value1) << endl;
    }
};

int main()
{
    operatorOverloading obj1, obj2;
    obj1.val = 7;
    obj2.val = 2;

    // obje1 wale object ke lie + operator ki defination ki call gyi hai ,
    // member function + operatorko class me dekha jaega
    // jisme obj2 as a input parameter pss kia gya hai
    obj1 + obj2;

    return 0;
}
