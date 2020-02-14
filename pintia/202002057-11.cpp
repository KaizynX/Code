#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n, g, k, p;

struct Node
{
    int mk, rk;
    string mail;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.mk == n2.mk ? n1.mail < n2.mail : n1.mk > n2.mk;
    }
} a[N];

int main()
{
    cin >> n >> g >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].mail >> a[i].mk;
        if (a[i].mk >= g) p += 50;
        else if (a[i].mk >= 60) p += 20;
    }
    sort(a+1, a+n+1);
    a[1].rk = 1;
    for (int i = 2; i <= n; ++i) {
        a[i].rk = (a[i].mk == a[i-1].mk ? a[i-1].rk : i);
    }
    cout << p << endl;
    for (int i = 1; i <= n; ++i) {
        if (a[i].rk > k) break;
        cout << a[i].rk << " " << a[i].mail << " " << a[i].mk << endl;
    }
    return 0;
}
