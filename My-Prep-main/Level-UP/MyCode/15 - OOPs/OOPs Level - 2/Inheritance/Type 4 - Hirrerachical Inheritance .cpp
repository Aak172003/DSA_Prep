
#include <iostream>
using namespace std;

// In hirrerachical -> 1 parent , 2 child

class Car
{
public:
    int age;
    string color;
    string name;

    void speedup()
    {
        cout << "Speed Bdhao Bhai " << endl;
    }

    void breakup()
    {
        cout << "Break Lgao Bhai " << endl;
    }
};

// child1 is a child of car
class child1 : public Car
{
};

// Child2 is a child of car
class child2 : public Car
{
};

int main()
{
    // Object creation via static  (static me . ka use )

    child1 scorpio;
    scorpio.age = 20;
    cout << "the scorpio age : " << scorpio.age << endl;
    scorpio.speedup();

    child2 fortuner;
    fortuner.breakup();

    // Object creation using Dynamically  (Dynamically me -> ka use )

    child1 *mahindra = new child1();

    mahindra->name = "XUV";
    cout << "The name of Mahindra : " << mahindra->name << endl;

    mahindra->breakup();

    return 0;
}
