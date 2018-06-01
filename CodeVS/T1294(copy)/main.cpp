#include <iostream>
#include <cstdio>
using namespace std;
int n,pd[21],used[21];
void dfs(int k)
{
    int i;
    //run 'n' times ,then out
    if(k==n)
    {
        for(int i=1;i<=n;++i)
            printf("%d ",used[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;++i)
        if(!pd[i])
        {
            pd[i]=1;//set the sign that the number had been used
            used[k+1]=i;//for instance:put '1' at the used[1]
            dfs(k+1);//run the next time
            pd[i]=0;//reset
        }
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}
