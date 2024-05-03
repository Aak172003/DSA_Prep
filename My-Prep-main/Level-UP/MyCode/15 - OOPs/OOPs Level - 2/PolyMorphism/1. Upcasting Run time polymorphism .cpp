
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

    // Up Casting Example
    // By Default jis class ka Pointer bna hai ussi class ka function call ho jaega

    Human *h2 = new Dog();
    h2->speak();

    // But if i want to call function from child class
    // so make parent class as virtual
    Human *h2 = new Dog();
    h2->speak();

    return 0;
}
