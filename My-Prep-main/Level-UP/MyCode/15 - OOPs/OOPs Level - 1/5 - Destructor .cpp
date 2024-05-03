#include <iostream>
using namespace std;

class Animal
{
public:
    // By deafult ye private hota hai , public lgane se phle
    int age;
    int weight;
    string name;

    // Parematerised Constructor
    Animal()
    {
        cout << "Parematerised Constructor called" << endl;
    }

    ~Animal()
    {
        cout << "I am Destructor " << endl;
    }
};

int main()
{
    // Object bnat hi Constructor will automaticall called ,
    // Ab chae wo object dynamically Create hua ho ya static

    // static Object -> static Object khatm hone pr Destructor automaticall Call
    Animal Dog;

    // Dynamic Object -> Dynamic object me delete keyword ko use krke object Constructor ko call krega
    Animal *Cat = new Animal();
    delete Cat;

    return 0;
}
