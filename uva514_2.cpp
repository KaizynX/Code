#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e3 + 7;

int n;
int s[Maxn], top;
int a[Maxn];

inline bool judge()
{
    top = 0;
    int cur = 1;
    for(int i = 1; i <= n; ++i)
    {
        s[++top] = i;
        while(top && a[cur] == s[top]) { --top; ++cur; }
    }
    return top ? false : true;
}

int main()
{
    while( scanf("%d",&n) && n )
    {
        while( scanf("%d",a+1) && a[1])
        {
            for(int i = 2; i <= n; ++i) scanf("%d",a+i);
            puts( judge() == true ? "Yes" : "No");
        }
        putchar('\n');
    }
    return 0;
}
