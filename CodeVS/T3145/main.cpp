#include <iostream>
using namespace std;
void move1(int n, char A, char B, char C);
int main()
{
    int n,step=1;
    cin>>n;
    for(int i=1;i<=n;i++)step*=2;
    cout<<step-1<<endl;
    move1(n,'A','B','C');
    return 0;
}
void move1(int n, char A, char B, char C)
{
    if(n==1){
        cout<<"from "<<A<<" to "<<C<<endl;
        return;
    }
    move1(n-1,A,C,B);
    cout<<"from "<<A<<" to "<<C<<endl;
    move1(n-1,B,A,C);
}
