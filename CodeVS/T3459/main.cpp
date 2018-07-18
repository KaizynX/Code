#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,a[100],b[20000]={0},ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)b[a[i]+a[j]]++;
        }
    }
    for(int i=0;i<=20000;i++)
    {
        if(b[i])
        {
            for(int j=0;j<n;j++)
            {
                if(i==a[j])ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
