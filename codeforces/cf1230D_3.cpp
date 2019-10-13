#include <bits/stdc++.h>

using namespace std;

const int N = 7e3+7;

int n, m;
int vis[N];
long long res;

struct Node
{
    int b;
    long long a;
    bool operator < (const Node &cp) const {
        return a < cp.a;
    }
} s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i].a;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> s[i].b;
    }
    sort(s+1, s+n+1);
    for (int i = 1; i < n; ++i) {
        if (s[i].a != s[i+1].a) continue;
        while (i < n && s[i+1].a == s[i].a) ++i;
        for (int j = 1; j <= i; ++j) {
            if ((s[i].a|s[j].a) == s[i].a) {
                if (!vis[j]) res += s[j].b;
                vis[j] = 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}
