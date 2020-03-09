#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int testcase = 1;
int n;
int a[N], vis[N];
set<pii> s;
string str;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> str;

        s.clear();
        memset(a, 0, sizeof(int)*(n+3));
        memset(vis, 0, sizeof(int)*(n+3));
        if (str[0] == '<') s.insert({0, 0}), vis[0] = 1;
        if (str.back() == '>') s.insert({0, n-1}), vis[n-1] = 1;
        for (int i = 1; i < n-1; ++i) {
            if (str[i-1] == '>' && str[i] == '<')
                s.insert({0, i});
        }
        for (int i = 1; i <= n; ++i) {
            pii u = *s.begin();
            s.erase(u);
            int p = u.second;
            a[p] = i;
            if (p && !vis[p-1] && str[p-1] == '>')
                s.insert({u.first+1, p-1}), vis[p-1] = 1;
            if (p < n-1 && !vis[p+1] && str[p] == '<')
                s.insert({u.first+1, p+1}), vis[p+1] = 1;
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];

        s.clear();
        memset(a, 0, sizeof(int)*(n+3));
        memset(vis, 0, sizeof(int)*(n+3));
        if (str[0] == '<') s.insert({0, 0}), vis[0] = 1;
        if (str.back() == '>') s.insert({0, n-1}), vis[n-1] = 1;
        for (int i = 1; i < n-1; ++i) {
            if (str[i-1] == '>' && str[i] == '<')
                s.insert({0, i});
        }
        for (int i = 1; i <= n; ++i) {
            pii u = *s.rbegin();
            s.erase(u);
            int p = u.second;
#ifdef DEBUG
            cout << p << " \n"[i==n];
#endif
            a[p] = i;
            if (p && !vis[p-1] && str[p-1] == '>')
                s.insert({u.first-1, p-1}), vis[p-1] = 1;
            if (p < n-1 && !vis[p+1] && str[p] == '<')
                s.insert({u.first-1, p+1}), vis[p+1] = 1;
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}
