#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int m, n, T, t[2];

struct Node
{
    int dif, tim;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.tim < n2.tim;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    while (m--) {
        cin >> n >> T >> t[0] >> t[1];
        for (int i = 1; i <= n; ++i) cin >> a[i].dif;
        for (int i = 1; i <= n; ++i) cin >> a[i].tim;
        sort(a+1, a+n+1);
        a[n+1].tim = T+1;
        int res = 0;
        long long sum = 0;
        for (int i = 1, j = 1; i <= n; i = j) {
            while (j <= n && a[j].tim == a[i].tim) {
                sum += t[a[j].dif];
                ++j;
            }
            // [i, j)
            if (sum < a[j].tim) res = j-1;
        }
        cout << res << endl;
    }
    return 0;
}

