#include <iostream>
#include <algorithm>
using namespace std;
 struct xd{
    int a,b;
 };
 bool cmp(xd x1,xd x2){
    return x1.a<=x2.a;
 }
int main()
{
    int n;
    cin>>n;
    xd p[n];
    for(int i=1;i<=n;++i){
        cin>>p[i].a>>p[i].b;
        if(p[i].a>p[i].b)
            swap(p[i].a,p[i].b);
    }
    sort(p+1,p+n+1,cmp);
    int ans=1;
    int lf=p[n].a;
    for(int i=n-1;i>0;--i){
        if(p[i].b<=lf){
            ans++;
            lf=p[i].a;
        }
    }
    cout<<ans;
    return 0;
}
