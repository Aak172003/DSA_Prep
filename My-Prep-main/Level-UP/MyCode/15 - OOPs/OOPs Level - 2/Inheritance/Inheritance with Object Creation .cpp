#include <iostream>
using namespace std;

class Animal {
    public:
    int age;
    int weight;
    
    void eat() 
    {
        cout<<"I am Eating the Food"<<endl;
    }
    
};

class Dog : public Animal { 

};

int main()
{
    
    Dog d1;
    d1.eat();
    cout<<endl;
    
    // How Object Created 
    
    d1.age = 20;
    d1.weight = 50;

    cout<<"Via Statically "<<endl;

    cout<<"The age is : "<<d1.age<<endl;
    cout<<"The weight is : "<<d1.weight<<endl;
    
    cout<<endl;
    
    cout<<"Via Dynamically "<<endl;
    
    Dog* d2 = new Dog();
    d2->age = 50;
    d2->weight = 60;
    cout<<"The age is : "<<d2->age<<endl;
    cout<<"The weight is : "<<d2->weight<<endl;
    

    return 0;
}
