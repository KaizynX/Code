#include <iostream>

using namespace std;

int main()
{
    int tree[10001]={0};
    int l,m,x,y,ans=0;
    cin>>l>>m;
    for(int i=0;i<=l;i++)tree[i]=1;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        if(x>y)swap(x,y);
        for(int j=x;j<=y;j++)tree[j]=0;
    }
    for(int i=0;i<=l;i++)
    {
        if(tree[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
