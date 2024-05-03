#include <iostream>
using namespace std;

//                         Type - 1 -> to store values

class Student
{
public:
    int age;
    string name;
    int rollno;
};

int main()
{
    Student s1;
    s1.age = 20;
    s1.name = "Aakash";
    s1.rollno = 5;

    cout << "the age is : " << s1.age << endl;
    cout << "the name is  : " << s1.name << endl;
    cout << "the rollno : " << s1.rollno << endl;
    return 0;
}

//                           Type - 2 -> to store value ,by using Parameter
class Student
{
public:
    int age;
    string name;
    int rollno;

    void details(int a, string b, int c)
    {
        this->age = a;
        this->name = b;
        this->rollno = c;
    }
};

int main()
{
    Student s1;
    s1.details(15, "Aman", 2);

    cout << "the age is : " << s1.age << endl;
    cout << "the name is  : " << s1.name << endl;
    cout << "the rollno : " << s1.rollno << endl;
    return 0;
}
