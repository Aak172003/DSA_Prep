
#include <iostream>
using namespace std;

class Human
{
public:
    virtual void speak()
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
    // Statically created object
    // Dog d1;
    // d1.speak();

    // Dynamically created object
    // (all member function as well as data member is accessed by -> operator )

    // Normal Case
    Human *h1 = new Human();
    h1->speak();

    Dog *d1 = new Dog();
    d1->speak();

    return 0;
}
