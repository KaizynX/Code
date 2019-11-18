#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int b[N];
map<int, set<int>> p;

struct Node
{
    int v, b, l, r;
} a[N];

bool cmpa(const Node &x, const Node &y) { return x.v < y.v; }
bool cmpb(const Node &x, const Node &y) { return x.b < y.b; }

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].v, a[i].id = i;
    for (int i = 1; i <= n; ++i) cin >> b[i], a[i].b = b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i) {
        if (a[i].v > b[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (a[i+1].v <= b[i]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        p[a[i].v].insert(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (p[a[i].v].find(a[i].id) != p[a[i].v].end()) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
