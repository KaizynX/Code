#include <iostream>

using namespace std;

int main()
{
    char a[256],b;
    int n=0,sum=0;
    while(cin>>b)
    {
        if(b=='@')break;
        a[++n]=b;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]=='(')sum++;
        if(a[i]==')')sum--;
        if(sum<0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    if(sum==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
