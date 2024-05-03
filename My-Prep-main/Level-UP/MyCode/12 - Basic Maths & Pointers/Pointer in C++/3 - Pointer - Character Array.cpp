#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

/*
Cout kaimplementation Array or character ke case me differently implemented hai
Array ke case me hume address de rha hai
but Character ke case me wo hum poora content de rha hai 
*/
    cout << arr << endl;
    //attention here
    cout << ch << endl;   // ye hume poora character de dega 
    
    char *c = &ch[0];
    //prints entire string
    cout << c << endl;

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;


    return 0;
}