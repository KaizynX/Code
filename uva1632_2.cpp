#include<cstdio>  
#include<iostream>

using namespace std;

const int Maxn = 1e5 + 7;
const int INF = 1<<30;

int a[Maxn];  
int b[Maxn];  
int d[2][Maxn][2];

int main()  
{  
    int i,j,n,cur,ans;  
    while(scanf("%d",&n)==1)  
    {  
        for(i=1;i<=n;i++)  
            scanf("%d%d",&a[i],&b[i]);  
        cur=0;  
        for(j=1;j<=n;j++)  
            d[0][j][0]=d[0][j][1]=(b[j]>0)?0:(INF);  
        for(i=1;i<n;i++)  
        {  
            cur^=1;  
            for(j=1;j<=n-i;j++)  
            {  
                d[cur][j][0]=min(d[cur^1][j+1][0]+a[j+1]-a[j],d[cur^1][j+1][1]+a[j+i]-a[j]);
                d[cur][j][1]=min(d[cur^1][j][0]+a[j+i]-a[j],d[cur^1][j][1]+a[j+i]-a[j+i-1]);
                d[cur][j][0]=d[cur][j][0]<b[j]?d[cur][j][0]:(INF);  
                d[cur][j][1]=d[cur][j][1]<b[j+i]?d[cur][j][1]:(INF);  
            }  
        }  
        ans=min(d[cur][1][0], d[cur][1][1]);  
        if(ans==(INF)) printf("No solution\n");  
        else printf("%d\n",ans);  
    }  
    return 0;  
}  
