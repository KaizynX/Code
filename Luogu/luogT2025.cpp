#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int n;
double ans;

struct Node
{
    int x, y, z;
    bool operator < (const Node &b) const { return z < b.z; }
} a[Maxn];

inline double dis(int i, int j)
{
    double x = (double)a[i].x-a[j].x,
           y = (double)a[i].y-a[j].y,
           z = (double)a[i].z-a[j].z;
    return sqrt(x*x+y*y+z*z);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
    sort(a+1, a+n+1);
    for(int i = 1; i < n; ++i)
        ans += dis(i, i+1);
    printf("%.3f\n", ans);
    return 0;
}
