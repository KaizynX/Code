#include <iostream>

using namespace std;
int a[10]={0};
int main()
{
    int n,m,n1=1,i;
    cin>>n>>m;
    if(n==0)cout<<"0";
    for(i=1;i<=7;i++){
        n1*=m;
        if(n1>n){
            i--;
            n1/=m;
            break;
        }
    }
    for(int j=1;j<=i+1;j++){
        a[j]=n/n1;
        n-=a[j]*n1;
        n1/=m;
    }
    for(int j=1;j<=i+1;j++){
        if(a[j]==10)cout<<"A";
        else if(a[j]==11)cout<<"B";
        else if(a[j]==12)cout<<"C";
        else if(a[j]==13)cout<<"D";
        else if(a[j]==14)cout<<"E";
        else if(a[j]==15)cout<<"F";
        else cout<<a[j];
    }
    cout<<endl;
    return 0;
}
