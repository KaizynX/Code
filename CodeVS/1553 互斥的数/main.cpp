#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=100005;
int N,P,a[maxn];

bool ope(int x,int y)
{
    long long res=x*P;
    if(res==y)return 1;
    return 0;
}

int main()
{
    int i;
    scanf("%d%d",&N,&P);
    for(i=1;i<=N;++i)
        scanf("%d",a+i);

    return 0;
}
