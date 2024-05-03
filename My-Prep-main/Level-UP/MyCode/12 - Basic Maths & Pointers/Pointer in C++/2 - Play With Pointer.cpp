#include<iostream>
using namespace std;

int main () {

    //pointer to int is created, and pointing to some garbage address

    /* 
    int *p;
    cout << *p << endl;   -->Return some Garbage Value 
    */

    /*
    int *p = 0;   // Aisa Pointer bnaya jo memory me exist hi nhi krti
    cout << *p << endl; Gives Segmentation Fault
    */

    /*
    int i = 5;
    int *q = &i;
    cout << q << endl;
    cout << *q << endl;

    //                 Or 

    int *p = 0;
    p = &i;
    cout << p << endl;
    cout << *p << endl;

    */
   

   int num = 5;
   int a = num;  // a naam ke variable me humne num daal dia 
   cout << "a before " << num << endl;  //  num = 5
   a++;
   cout << "a after " << num << endl;  // num = 5
   /* Beacuse humne num ki value ( copy form me dia hai , 
      so a pr updation num pr koi effect nhi daalega)
   */


   int *p  = &num;
   cout << "before " << num << endl;  // num = 5
   (*p)++;  // p pointer me jo value hai , us address pr jo value hai usme jaakr updation , means effect on original value 
   cout << "after " << num << endl;  // num  =6

    //copying a pointer
   int *q = p;  // jbki p ka address q me daala hai
   cout << p <<" - " << q << endl;  // p me jo valu hai
   cout << *p <<" - " << *q << endl;  
   // jbki p ka address q me daala hai to
   // *p , *q give same result 


   //important concept
   int i = 3;
   int *t = &i;

   cout <<  (*t)++ << endl;
   // Or 
   *t = *t +1;   // isme t ki value ek address hai us  address ki value pr jaakr uski value update 
   
    cout << *t << endl;
    cout << " before t " << t << endl;
    t = t + 1;  
    /* t store adress , so if we add 1 on t 
    suppose t=100 address, if t=t+1 , means that is not t=100+1 - No 
    here ye hoga ki +1 ka mtlb jis type ka array hai utne 
    size ka add krega jisse ki wo next element ko point kre  
    */
    cout << " after t " << t << endl;


    return 0;
}