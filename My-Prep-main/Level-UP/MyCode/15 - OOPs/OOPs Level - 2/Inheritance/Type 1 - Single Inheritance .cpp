#include <iostream>
using namespace std;

class Car
{
public:
    string name;
    int weight;
    int age;

    void speedup()
    {
        cout << "Speeding up" << endl;
    }

    void breakup()
    {
        cout << "Break Mardo" << endl;
    }
};

// Dog is a Animal
// Scorpio is a Car
class Scorpio : public Car
{

    // Means car class me jo jo variable hai publically un sb ko public form
    // me maine Scorpio class me daal dia hai
};

int main()
{
    // Object creation via static  (static me . ka use )
    Scorpio car1;
    car1.speedup();
    car1.age = 15;
    car1.name = "Tata Motors";

    cout << "The name : " << car1.name << endl
         << "The age :" << car1.age << endl;

    // Object creation using Dynamically  (Dynamically me -> ka use )
    Scorpio *car2 = new Scorpio();

    car2->age = 20;
    car2->name = "Tech Mahindra";

    cout << "The name : " << car2->name << endl
         << "The age :" << car2->age << endl;

    car2->breakup();

    return 0;
}
