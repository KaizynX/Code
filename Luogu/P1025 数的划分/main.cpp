#include <iostream>
#include <cstdio>
using namespace std;

int n,k,ans;

void solve(int cur,int last,int rest)
{
    if(cur>=k)
    {
        if(rest>=last)
            ans++;
        return;
    }
    for(int i=last;i<=rest;++i)
        solve(cur+1,i,rest-i);
}

int main()
{
    cin>>n>>k;
    solve(1,1,n);
    printf("%d\n",ans);
    return 0;
}
