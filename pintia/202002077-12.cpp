#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n;

struct Node
{
    int i, p, t;
    friend bool operator < (const Node &n1, const Node &n2) {
        if (n1.p != n2.p) return n1.p > n2.p;
        if (n1.t != n2.t) return n1.t > n2.t;
        return n1.i < n2.i;
    }
} a[N];

int main()
{
    cin >> n;
    for (int i = 1, k; i <= n; ++i) {
        a[i].i = i;
        cin >> k;
        for (int j = 1, id, pr; j <= k; ++j) {
            cin >> id >> pr;
            a[id].p += pr;
            ++a[id].t;
            a[i].p -= pr;
        }
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        printf("%d %.2f\n", a[i].i, a[i].p/100.0);
    }
    return 0;
}
