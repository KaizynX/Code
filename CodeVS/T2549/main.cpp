#include <iostream>

using namespace std;
int n,ans;

int dfs(int n,int i)
{
    if(n==0)
    {
        ans++;
        return;
    }
    for(int j=i;j<=n;j++)
    {
        if(n-j>=0)dfs(n-j,j);
    }
}

int main()
{
    cin>>n;
    dfs(n,1);
    cout<<ans<<endl;
}
