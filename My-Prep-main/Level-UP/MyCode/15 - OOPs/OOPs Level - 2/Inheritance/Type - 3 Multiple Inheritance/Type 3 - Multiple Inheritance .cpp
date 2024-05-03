#include <iostream>
using namespace std;

// class A
class A
{
public:
    int physics;

    void Multiple()
    {
        cout << "Multiple Inheritance" << endl;
    }
};

// class b
class B
{

public:
    int chemistry;
};

// classc inherit property of class A and class B
class C : public A, public B
{
public:
    int maths;
};

int main()
{
    // Object creation via static  (static me . ka use )

    C a1;
    a1.Multiple();

    a1.physics = 5;
    a1.chemistry = 10;
    a1.maths = 15;

    cout << "The physics : " << a1.physics << endl
         << "The chemistry : " << a1.chemistry << endl
         << "The maths : " << a1.maths << endl;
    cout << endl;

    return 0;
}
