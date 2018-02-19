#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m;cin>>n>>m;
    int a[100001];
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);
    int num=0;
    for(int i=0;i<n;++i){
        if(m>=a[i]){
            m-=a[i];
            num++;
        }else break;
    }
    cout<<num;
    return 0;
}
