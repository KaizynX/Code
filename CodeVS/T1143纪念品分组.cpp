#include<iostream>
#include<algorithm>
#include <cstdio> 
using namespace std;
int main()
{
    int w,n,ans=0;
    int a[30000];
    scanf("%d%d",&w,&n);
    for(int i=0;i<n;i++)
       scanf("%d",&a[i]);
    sort(a,a+n);
    int l=0,r=n-1;
    while(l<=r)
    {
        if(a[l]+a[r]<=w){l++;r--;}
        else r--;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}
