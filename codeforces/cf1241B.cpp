#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int q, n;
string s, t;
int vis[128];

int main()
{
    cin >> q;
    while (q--) {
        int flag = 0;
        cin >> s >> t;
        for (int i = 'a'; i <= 'z'; ++i) vis[i] = 0;
        for (char c : s) vis[c] = 1;
        for (char c : t) {
            if (vis[c]) flag = 1;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
