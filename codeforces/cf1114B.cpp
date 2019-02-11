#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

struct Node
{
    int v, i;
    bool operator < (const Node &b) const{
        return v > b.v;
    }
} a[Maxn];

int n, m, k;
int f[Maxn];

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].v;
        a[i].i = i;
    }
    sort(a+1, a+n+1);
    long long sum = 0;
    for(int i = 1; i <= m*k; ++i)
        sum += a[i].v, f[a[i].i] = 1;
    cout << sum << endl;
    int flag = 0;
    for(int i = 1, cnt = 0; i <= n; ++i)
    {
        cnt += f[i];
        if(cnt == m)
        {
            cnt = 0;
            cout << i << " ";
            flag++;
            if(flag >= k-1) break;
        }
    }
    cout << endl;
    return 0;
}