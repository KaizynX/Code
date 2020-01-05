#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

struct Node
{
    int p, v;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.p < n2.p;
    }
} a[N];

int n;
int tag[N];
priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].p;
    for (int i = 1; i <= n; ++i) cin >> a[i].v;
    sort(a+1, a+n+1);
    for (int i = 1; i < n; i *= 4) {
        for (int j = 2; j <= 4; ++j) {
            tag[i*j] = 1;
        }
    }
    long long res = 0;
    for (int i = n; i; --i) {
        if (a[i].v == -1) break;
        q.push(a[i].v);
        if (tag[i]) res += q.top(), q.pop();
    }
    cout << res << endl;
    return 0;
}

