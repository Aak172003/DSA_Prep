#include <iostream>
using namespace std;

class Animal
{
    // int age;       // the size is  : 4
    // int apple;     // the size is  : 4
    // string name ;  // the size is  : 32
    // char aaja;     // the size is  : 1
};

int main()
{
    // How Object is Created
    cout << "the size is : " << sizeof(Animal) << endl;

    return 0;
}

// OutPut :

// If empty class : the size is  : 1