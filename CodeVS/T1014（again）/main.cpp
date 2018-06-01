#include <iostream>

using namespace std;

int main()
{
    int v,n,b,a[20005]={0},res=0;
    cin>>v>>n;
    for(int i=0;i<n;i++)
    {
        cin>>b;
        for(int j=v;j>=b;j--)
        {
            a[j]=max(a[j],a[j-b]+b);
        }
    }
    cout<<v-a[v]<<endl;
    return 0;
}
