#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

int n;
int a[N], b[N], c[N<<1], d[N], nex[N];

inline void GetNext()
{
    for (int i = 2, k = 0; i < n; ++i) {
        while (k && d[k+1] != d[i]) k = nex[k];
        if (d[k+1] == d[i]) ++k;
        nex[i] = k;
    }
}

inline void KMP()
{
    for (int i = 1, j = 0, k; i <= 2*n-2; ++i) {
        while (j && c[i] != d[j+1]) j = nex[j];
        if (d[j+1] == c[i]) ++j;
        if (j == n-1) {
            k = i-n+1;
            cout << k << " " << (a[k]^b[0]) << endl;
            j = nex[j];
        }
    }
}

inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (n == 1) { cout << 0 << " " << (a[0]^b[0]) << endl; return; }
    for (int i = 1; i <= 2*n-2; ++i) c[i] = a[(i-1)%n]^a[i%n];
    for (int i = 1; i < n; ++i) d[i] = b[i-1]^b[i];
    GetNext();
    KMP();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}