#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k, tot;
char sex[N];
int mmp[N], vis[N];
map<int, int> mp;
vector<int> parents[N];

inline int get_id(int x)
{
    if (mp.count(x)) return mp[x];
    mmp[++tot] = x;
    return mp[x] = tot;
}

void getp(int x, int d, int v)
{
    vis[x] += v;
    if (d >= 5) return;
    for (int i : parents[x])
        getp(i, d+1, v);
}

bool check(int x, int d)
{
    if (vis[x]) return false;
    if (d >= 5) return true;
    for (int i : parents[x])
        if (!check(i, d+1)) return false;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x;
        x = get_id(x);
        cin >> sex[x];
        cin >> y;
        if (y != -1) {
            y = get_id(y);
            sex[y] = 'M';
            parents[x].emplace_back(y);
        }
        cin >> y;
        if (y != -1) {
            y = get_id(y);
            sex[y] = 'F';
            parents[x].emplace_back(y);
        }
    }
    cin >> k;
    for (int i = 1, x, y, flag; i <= k; ++i) {
        cin >> x >> y;
        x = get_id(x);
        y = get_id(y);
        if (sex[x] == sex[y]) {
            cout << "Never Mind" << endl;
            continue;
        }
        getp(x, 1, 1);
        flag = check(y, 0);
        getp(x, 1, -1);
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
