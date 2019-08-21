#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kM = 998244353;

int n, ans = 1;
string s;
int a[4], b[4];

inline int GetId(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    if (c == 'B') return 2;
}

int main()
{
    cin >> n >> s;
    a[0] =  n;
    for (int i = 0, p, q; i < s.length(); ++i) {
        p = GetId(s[i]);
        q = 0;
        ++b[p];
        // b[j] < b[p], then j has in a group
        for (int j = 0; j < 3; ++j) {
            if (b[j] > b[p]) {
                ++q;
            }
        }
        ++b[p];
        ans = int(1ll*ans*a[q]%kM);
        // the sizeof this group is q+1
        a[q]--;
        a[q+1]++;
    }
    cout << ans << endl;
    return 0;
}
