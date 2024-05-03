#include <iostream>
using namespace std;

class Fruit
{
public:
    string name;
    int age;

    void Tasty()
    {
        cout << "Umm Very Tasty" << endl;
    }
};

// Mango is a Fruit
class Mango : public Fruit
{
public:
    int weight;

    // Means car me jo jo variable hai publically un sb ko public form
    // me maine Scorpio class me daal dia hai
};

class Alfango : public Mango
{
public:
    int sugarlevel;
};

int main()
{
    // Object creation via static  (static me . ka use )

    Alfango a1;
    a1.Tasty();

    a1.age = 15;
    a1.sugarlevel = 20;
    a1.name = "Alfango";

    cout << "The name : " << a1.name << endl;
    cout << "The age : " << a1.age << endl;
    cout << "The sugar level : " << a1.sugarlevel << endl;
    cout << endl;

    // Object creation using Dynamically  (Dynamically me -> ka use )

    Alfango *a2 = new Alfango();

    a2->age = 20;
    a2->name = "Banana";

    cout << "The name : " << a2->name << endl;
    cout << "The age :" << a2->age << endl;

    a2->Tasty();

    return 0;
}
