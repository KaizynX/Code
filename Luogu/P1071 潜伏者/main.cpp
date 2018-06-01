#include <iostream>
#include <cstdio>
#define NO "Failed\n"
using namespace std;
const int maxn=256;
const int maxl=100+5;

char atob[maxn],btoa[maxn],ans[maxl];
string a,b,c;

int main()
{
    cin>>a>>b>>c;
    if(a.length()<26)
    {
        cout<<NO;
        return 0;
    }
    for(int i=0;i<a.length();++i)
    {
        if(atob[a[i]]!=NULL && atob[a[i]]!=b[i])
        {
            cout<<NO;
            return 0;
        }
        if(btoa[b[i]]!=NULL && btoa[b[i]]!=a[i])
        {
            cout<<NO;
            return 0;
        }
        atob[a[i]]=b[i];
        btoa[b[i]]=a[i];
    }
    for(int i='A';i<='Z';++i)
    {
        if(btoa[i]==NULL)
        {
            cout<<NO;
            return 0;
        }
    }
    for(int i=0;i<c.length();++i)
    {
        if(atob[c[i]]==NULL)
        {
            cout<<NO;
            return 0;
        }
        ans[i]=atob[c[i]];
    }
    cout<<ans<<endl;
    return 0;
}
