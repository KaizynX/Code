#include <iostream>

using namespace std;

int main()
{
    int m,s,c;//木板最大的数目M ,牛棚的总数S 和 牛的总数C
    cin>>m>>s>>c;
    int a[201],b[201];
    for(int i=1;i<=c;++i)cin>>a[i];
    //排序a
    for(int i=2;i<=c;++i){
        for(int j=1;j<=c;++j){
            if(a[i]<a[j])swap(a[i],a[j]);
        }
    }
    int out=a[c]-a[1]+1;
    for(int i=2;i<=c;++i)b[i]=a[i]-a[i-1]-1;
    int big=0,flag,time=0;
    while(time<m-1){
        for(int i=2;i<=c;++i){
            if(b[i]>big){
                big=b[i];
                flag=i;
            }
        }
        out-=b[flag];
        b[flag]=0;
        time++;
        big=0;
    }
    cout<<out;
    return 0;
}
