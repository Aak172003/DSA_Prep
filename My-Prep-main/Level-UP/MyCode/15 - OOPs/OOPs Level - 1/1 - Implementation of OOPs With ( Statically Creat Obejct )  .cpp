
#include <iostream>
using namespace std;

class Animal
{
public:
    // State or Properties
    int age;
    string name;

    // Behaviour or Functions
    void eat()
    {
        cout << "The dog eats the bhojan" << endl;
    }

    void Sleep()
    {
        cout << "Dog Going to always Sleep" << endl;
    }
};

int main()
{
    // How Object is Created

    // Statically Create Object
    Animal Dog;
    Dog.age = 20;
    Dog.name = "Fluppy";
    cout << "The age of Animal : " << Dog.age << endl;
    cout << "The age of Animal : " << Dog.name << endl;

    // If we call any Behaviour so , simply call a funtion

    Dog.eat();
    Dog.Sleep();

    return 0;
}