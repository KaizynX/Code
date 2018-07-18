#include<iostream>
using namespace std;
int main()
{
    int i,n,m,p,q,s;
    cin>>n>>m;
    int a[n];
    for(i=0; i<n; i++)
        a[i]=1;
    p=0;
    for(q=1; q<=n-1; q++)
    {
        for(i=p; i<m+p; i++)
        {
            s=i%n;
            if(a[s]==0)
                p++;
        }
        i=(i-1)%n;
        a[i]=0;
        p=i+1;
    }
    for(i=0; i<n; i++)
        if(a[i]==1)
            cout<<i+1<<endl;
    return 0;
}
