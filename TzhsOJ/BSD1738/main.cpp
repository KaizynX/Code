#include <iostream>

using namespace std;

int main()
{
    char a[256],cur;
    int n=0,sumb=0,sums=0;
    while(cin>>a[++n]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='(')sums++;
        if(a[i]=='[')sumb++;
        if(a[i]==')')
        {
            if(cur=='[')
            {
                cout<<"Wrong"<<endl;
                return 0;
            }
            sums--;
        }
        if(a[i]==']')
        {
            if(cur=='(')
            {
                cout<<"Wrong"<<endl;
                return 0;
            }
            sumb--;
        }
        cur=a[i];
    }
    if(sumb==0&&sums==0)cout<<"OK"<<endl;
    else cout<<"Wrong"<<endl;
    return 0;
}
