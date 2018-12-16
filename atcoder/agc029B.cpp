#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n;
int a[Maxn], co[Maxn], vis[Maxn];
set<int> pow2;

bool check(int cur)
{
    for(int i = 1; i <= n; ++i)
    {
        if(vis[i] || i == cur) continue;
        if(pow2.find(a[i]+a[cur]) == pow2.end()) continue;
        vis[i] = true;
        if(!co[i] || check(co[i]))
        {
            co[i] = cur;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= 30; ++i) pow2.insert(1<<i);
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        memset(vis, 0, sizeof vis);
        if(check(i)) ++ans;
    }
    printf("%d\n", ans/2);
    return 0;
}
