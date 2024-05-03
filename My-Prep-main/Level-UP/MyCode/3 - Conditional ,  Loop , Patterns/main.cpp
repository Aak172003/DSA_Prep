#include<iostream>
using namespace std;

int main()

{
conditionals

        /*// if 
            int score;
            cout<<"Enter the score"<<'\n';
            cin>>score;
            if(score<300){
                cout<<"India wins\n";
            }
            cout<<"Pakistan wins\n";
        */


        /*// if-else

            int score;
            cout<<"Enter the score"<<'\n';
            cin>>score;
            if(score<300){
                cout<<"India wins\n";
            }
            else{
                cout<<"Pakistan wins\n";
            }
        */


 multiple conditions
            // int marks;
            // cin>>marks;
            
            /*// nested if-else
                if(marks>=90){
                    cout<<"A grade";
                }
                else{
                    if(marks>=80){
                        cout<<"B grade";
                    }
                    else{
                        if(marks>=60){
                            cout<<"C grade";
                        }
                        else{
                            if(marks>=40){
                                cout<<"D grade";
                            }
                            else{
                                cout<<"F grade";
                            }
                        }
                    }
                }
            */

else if Ladder is better than nested if else

            /*// else if Ladder 
                if(marks>=90){
                    cout<<"A grade";
                }
                else if(marks>=80){
                    cout<<"B grade";
                }
                else if(marks>=60){
                    cout<<"C grade";
                }
                else if(marks>=40){
                    cout<<"D grade";
                }
                else{
                    cout<<"F grade";
                }
            */
        
        /*// example
            int broNum;
            cin>>broNum;
            if(broNum==0){
                cout<<"Baat ban jayegi\n";
            }
            else{
                cout<<"Baat nahi banegi\n";
            }
        */


loops
    // for loop
        /*
        for(int i=0; i<5; i++){
            cout << "Love Babbar" <<'\n';
        }
        */

        /*
        for(int i=0; i<5; i++){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=5; i>0; i--){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=1; i<=10; i++){
            cout << 2*i <<'\n';
        }
        */
        
        /*
        for(int i=0; i<=5; i=i+2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=1; i<=5; i=i+2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=1; i<10; i=i*2){
            cout << i <<'\n';
        }
        */

        /*
        for(int i=100; i>0; i=i/2){
            cout << i <<'\n';
        }
        */

        /*
        Multiple Condtion in For Loop 

        for(int i=5; (i>=0 && i<=10); i++){
            cout << i <<'\n';
        }
        */

What is necessary Terms in terms of For Loop

        // what terms are necessary
            /*for(int i=0; i<5; i++){
                cout << i <<'\n';
            }
            */

            /*// removing initialization
            int i=0;
            for( ; i<5; i++){
                cout << i <<'\n';
            }
            */

            /*
            removing condition

            int i=0;
            for( ; ; i++){
                if(i<5){
                    cout << i <<'\n';
                }
            }
            */
            
            /*
            removing updatation
                // unlimited loop if break is not used
                int i=0;
                for( ; ; )
                {
                    if(i<5){
                        cout << i <<'\n';
                        i++;
                    }
                }
                */
    return 0;
}