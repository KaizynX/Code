#include <iostream>
#include <algorithm>
using namespace std;
struct cow
{
    int x;
    int y;
}a[5001];

int cmp(cow a,cow b)
{
    return a.x<b.x;
}
int main()
{
    int n,m,p=0;
    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>a[i].x>>a[i].y;
    sort(a,a+m,cmp);
    for(int i=0;i<m;i++){
        if(n>a[i].y){
            n-=a[i].y;
            p=p+a[i].x*a[i].y;
        }else{
            p=p+n*a[i].x;
            break;
        }
    }
    cout<<p;
    return 0;
}
