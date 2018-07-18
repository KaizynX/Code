#include <iostream>
//nearly TLE
using namespace std;
int n,k,res;

void dfs(int t,int last,int sum)
{
    if(t==k)
    {
        if(sum==n)res++;
        return;
    }
    for(int i=last;i<=n-sum;++i)
    {
        dfs(t+1,i,sum+i);
    }
}

int main()
{
    cin>>n>>k;
    dfs(0,1,0);
    cout<<res<<endl;
    return 0;
}
