#include <iostream>

using namespace std;
const int maxn=16;
int tree[maxn][2],nw[maxn];
int nh,ah,aw;

int h(int i)
{
    nh++;
    if(tree[i][0]!=0)
    {
        nw[nh]++;
        h(tree[i][0]);
    }
    if(tree[i][1]!=0)
    {
        nw[nh]++;
        h(tree[i][1]);
    }
    ah=max(ah,nh);
    nh--;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=1;j++)
            cin>>tree[i][j];
    tree[0][0]=1;
    tree[0][1]=0;
    nw[0]=1;
    h(tree[0][0]);
    for(int i=0;i<=n;i++)
    {
        aw=max(aw,nw[i]);
    }
    cout<<aw<<" "<<ah<<endl;
    return 0;
}
