#include <iostream>
#include <cstdio>
using namespace std;
int n,ans=0;
//±©¡¶«ÛΩ‚TLE
int chuan(int num,int cur)
{
    if(cur==n+1)cur=1;
    if(cur==0)cur=n;
    if(num==0)
    {
        if(cur==1)ans++;
        return 0;
    }
    chuan(num-1,cur+1);
    chuan(num-1,cur-1);
}

int main()
{
    int m;
    scanf("%d%d",&n,&m);
    chuan(m,1);
    printf("%d\n",ans);
    return 0;
}
