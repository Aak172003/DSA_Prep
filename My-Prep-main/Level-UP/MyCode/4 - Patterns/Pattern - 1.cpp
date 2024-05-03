#include<iostream>
using namespace std;

int main()

{
// patterns

        /*// pattern 1
            for(int row=0; row<3; row++){
                for(int col=0; col<5; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */
        
        /*// pattern 2
            int n;
            cin>>n;
            for(int row=0; row<n; row++){
                for(int col=0; col<n; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */

        /*// pattern 3
            int n;
            cin>>n;
            for(int row=0; row<3; row++){
                for(int col=0; col<5; col++){
                    if(row==0 || row==n-1){
                        cout<<"*";
                    }
                    else{
                        if(col==0 || col==4){
                            cout<<"*";
                        }
                        else{
                            cout<<" ";
                        }
                    }
                }
                cout<<'\n';
            }
        */
                
        /*// pattern 4
            int rowCount;
            int colCount;
            cin>>rowCount;
            cin>>colCount;
            for(int i=0; i<rowCount; i++){
                for(int j=0; j<colCount; j++){
                    if(i==0 || i==rowCount-1){
                        cout<<"*";
                    }
                    else{
                        if(j==0 || j==colCount-1){
                            cout<<"*";
                        }
                        else{
                            cout<<" ";
                        }
                    }
                }
                cout<<'\n';
            }
        */

        /*// pattern 4    half pyramid
            int n;
            cin>>n;
            for(int row=0; row<n; row++){
                for(int col=0; col<row+1; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */
        
        /*// pattern 5    inverted half pyramid
            int n;
            cin>>n;
            for(int row=0; row<n; row++){
                for(int col=0; col<n-row; col++){
                    cout<<'*';
                }
                cout<<'\n';
            }
        */

        /*// pattern 6    half pyramid with numbers
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                for(int j=0; j<i+1; j++){
                    cout<<j+1;
                }
                cout<<'\n';
            }
        */

        /*// pattern 7
            int n;
            cin>>n;
            for(int i=0; i<n; i++){
                for(int j=0; j<n-i; j++){
                    cout<<j+1;
                }
                cout<<'\n';
            }
        */

    return 0;
}