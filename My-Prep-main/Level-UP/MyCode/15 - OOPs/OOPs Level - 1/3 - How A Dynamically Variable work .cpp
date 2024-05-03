// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class Animal
{
    // Private Modifier
private:
    int weight;

    // Public Modifier
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

    // Animal Dog;
    // Dog.age = 20;
    // Dog.name = "Fluppy";
    // cout << "The age of Animal : " << Dog.age << endl;
    // cout << "The age of Animal : " << Dog.name << endl;

    // Dynamically Created

    Animal *Dog = new Animal; // Here Dog is Object pointer to stores address
    Dog->age = 20;
    Dog->name = "Fluppy";

    cout << "1st Method to Acces the age : " << (*Dog).age << endl;
    cout << "2nd Method to Acces the name : " << (*Dog).name << endl;

    cout << "               OR              " << endl;

    cout << "1st Method to Acces the age : " << Dog->age << endl;
    cout << "2nd Method to Acces the name : " << Dog->name << endl;

    // How Access Class Behaviour

    Dog->eat();
    Dog->Sleep();

    return 0;
}