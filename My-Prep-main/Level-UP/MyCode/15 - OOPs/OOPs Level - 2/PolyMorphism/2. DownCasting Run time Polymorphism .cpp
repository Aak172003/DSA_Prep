
#include <iostream>
using namespace std;

class Human
{
public:
    void speak()
    {
        cout << "The human is speaking" << endl;
    }
};

class Dog : public Human
{
public:
    void speak()
    {
        cout << "The dog is barking " << endl;
    }
};

int main()
{
    /*
   Dog* dog1 = new Human();
   dog1->speak();

   This will give error sometimes ,
   actually iska answer kuch compiler support krte hai or kuch nhi
   */

    // But if we want answer -> type casting krdo

    // Dog *dog1 = (Dog *)new Human();
    // dog1->speak();

    // By Default jis class ka Pointer bna hai ussi class ka function call ho jaega

    Dog *h2 = (Dog *)new Human();
    h2->speak();

    // But if i want to call function from child class
    // so make parent class as virtual

    Dog *h2 = (Dog *)new Human();
    h2->speak();

    return 0;
}
