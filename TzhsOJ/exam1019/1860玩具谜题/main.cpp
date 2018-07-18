#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn=1000000+5;//???

int n,m,side[maxn];//0--in  1---out
string name[maxn];

int main()
{
    int i,dir,num,cur=1;//0--left  1---right
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d",&side[i]);
        cin>>name[i];
    }
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&dir,&num);
        if(side[cur]==0&&dir==0 || side[cur]==1&&dir==1)//right
        {
            cur-=num;
            if(cur<=0)
            {
                cur+=-(cur/n)*n+n;
            }
        }
        else
        {
            cur+=num;
            cur%=n;
            if(cur==0)cur=n;
        }
    }
    cout<<name[cur]<<endl;
    return 0;
}
