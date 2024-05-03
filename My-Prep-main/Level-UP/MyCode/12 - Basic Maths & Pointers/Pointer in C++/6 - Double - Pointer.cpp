#include<iostream>
using namespace std;

    void update(int **p2)  // for p2 ke lie 
    {
    p2 = p2 + 1;  
    // kuch change hoga  - NO

    *p2 = *p2 + 1;  // means p ka jo address hai usme uske data type ka size add hojaega bss , jo ki next elemnt ko point krega bss 
    // kuch change hoga - YES      

    **p2 = **p2 + 1; // ye hamara original value ko access krega , jisme ki after any modification our value also be changed 
    //kuch change hoga - YES
    }

   // Fr single * se kaam hojaega , because p me i ka address hai 
    void update(int *p)  // for p ke lie 
    {
        *p = (*p)  *  2;   // yaani ki p me jo value hai i ki usme hum 2 ka multiply krenge 
    }


    void increment(int **p)  
    // double ** islea kyuki jo ptr2 pass kia hai usme ptr1 ka address hai , or ptr mei ka address hai 
    {
        ++(**p);
        // Or 

        **p = **p+1;
    }
int main() 
{

    int i = 5;
    int* p = &i;
    int** p2 = &p;    
    // i ka address p me , p ka address p2 me 

    cout<< endl << endl <<" Sab sahi chal rha h " << endl << endl ;
    
    /*
    single * means jo us current pointer me value pdi hai , us value ke addrss pr jaakr jo value hai wo dena 
    Double * , means current pointer me jo value pda hai wo ek address hai pointer kaa , us address pr jaakr uski value khud ek address hai , phr us address pr jaakr print the value 
    */
    cout << i << endl;
    cout << *p << endl;

    cout << **p2 << endl;   
    // p2 me single * krte to wo p2 pinter me jo address pdha hai pointer kaa , wo us p naam ke pointer me jaakr uski value print kr dega 
    /*
    
    
    */
    cout << &i << endl;    // i ka address 
    cout << p << endl;     // p ki value jo ki , i ka address hai 
    cout << *p2 << endl;   // p2 pointer me jo value hai , us address pr jaakr jo value hai wo print , means p ka address , AND p ka address same as &i

    cout << &p << endl;  // p ka address 
    cout << p2 << endl;  // p2 ki value btenge to , usme p ka address hi hai
    cout << endl << endl;

    
    cout<< "before " << i << endl;
    cout<< "before " << p << endl;
    cout<< "before " << p2 << endl;
    update(p2);
    cout<< "after " << i << endl;
    cout<< "after " << p << endl;
    cout<< "after " << p2 << endl;
    cout << endl << endl;

    int num = 110;
    int *ptr = &num;
    int **ptr2 = &ptr;     // Double Pointer 
    increment(ptr2);       // Calling Function  
    cout << num << endl;

    return 0;
}
