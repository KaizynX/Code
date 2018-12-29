#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 2e5+7;

int L, n;
int a[Maxn];
long long ans;
stack<int> ni, sh;

inline int dis(int x, int y)
{
    return x < y ? y-x : L-x+y;
}

void dfs(int now, int cnt, long long sum)
{
    if(cnt >= n)
    {
        ans = max(ans, sum);
        return;
    }
    int dni = dis(now, ni.top()), dsh = dis(sh.top(), now), tmp;
#ifdef DEBUG
    printf("%d ni:%d %d sh:%d %d\n", cnt, ni.top(), dni, sh.top(), dsh);
#endif
    if(dni >= dsh)
    {
        tmp = ni.top();
        ni.pop();
        dfs(tmp, cnt+1, sum+dni);
        ni.push(tmp);
    }
    if(dsh >= dni)
    {
        tmp = sh.top();
        sh.pop();
        dfs(tmp, cnt+1, sum+dsh);
        sh.push(tmp);
    }
}

int main()
{
    cin >> L >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) sh.push(a[i]);
    for(int i = n; i >= 1; --i) ni.push(a[i]);
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
