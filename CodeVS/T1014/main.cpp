#include <iostream>
//#include <algorithm>
#include<cstdio>
using namespace std;
int a[20005]={0};
int main()
{
    freopen("data.in","r",stdin);
    int  v ,n,x,j;

    cin>>v>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(j=v;j>=x;j--){
            a[j]=max(a[j-x]+x,a[j]);
        }
    }
    cout<<v-a[v]<<endl;
    return 0;
}
