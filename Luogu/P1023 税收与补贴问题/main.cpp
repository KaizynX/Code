#include <iostream>
#include <cstdio>
#define NO "NO SOLUTION\n"
using namespace std;
const int maxn=1000;

int maxv,v0,s0,pos;
int v[maxn],s[maxn],m[maxn];

int main()
{
    scanf("%d%d%d",&maxv,&v0,&s0);
    while(v[pos]!=-1 || s[pos]!=-1)
    {
        pos++;
        scanf("%d%d",v+pos,s+pos);
        m[pos]=(v[pos]-v0)*s[pos];
    }
    return 0;
}
