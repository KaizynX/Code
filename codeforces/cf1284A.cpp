#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m, q, y;
string s[N], t[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < m; ++i) cin >> t[i];
    cin >> q;
    while (q--) {
        cin >> y;
        y--;
        cout << s[y%n]+t[y%m] << endl;
    }
    return 0;
}
