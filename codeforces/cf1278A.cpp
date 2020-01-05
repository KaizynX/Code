#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T;
string p, h;
int a[128], b[128];

inline void clear(int a[])
{
    for (int i = 'a'; i <= 'z'; ++i) a[i] = 0;
}

inline bool check()
{
    for (int i = 'a'; i <= 'z'; ++i)
        if (a[i] != b[i]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        clear(a);
        cin >> p >> h;
        int n = p.length(), m = h.length(), flag = 0;
        for (char c : p) ++a[c];
        for (int i = 0; i+n-1 < m; ++i) {
            clear(b);
            for (int j = i; j < n+i; ++j) {
                ++b[h[j]];
            }
            flag |= check();
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
