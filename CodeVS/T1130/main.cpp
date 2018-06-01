#include <iostream>

using namespace std;
char a[20];
int main()
{
    int n=1;
    while(cin>>a[0]){
        a[n]=a[0];
        n++;
    }
    n--;
    if(a[1]=='-'){
        cout <<'-';
        if(a[n]=='0'){
            while(a[n]=='0')n--;
            for(int i=n;i>=2;i--){
                cout<<a[i];
            }
        }
 /*       if(a[n]=='0'){
            for(int i=n-1;i>=2;i--){
                cout<<a[i];
            }
*/
        else{
            for(int i=n;i>=2;i--){
                cout<<a[i];
            }
        }
    }
    else {
        if(a[n]=='0'){
            while(a[n]=='0')n--;
            for(int i=n;i>=1;i--){
                cout<<a[i];
            }
        }
        else{
            for(int i=n;i>=1;i--){
                cout<<a[i];
            }
        }
    }
    return 0;
}
