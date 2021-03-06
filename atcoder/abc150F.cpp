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
    int k = -1, j = 0;
    nex[0] = -1;
    while (j < n-1) {
        if (k == -1 || d[k] == d[j]) {
            ++k; ++j;
            nex[j] = (d[k] == d[j] ? nex[k] : j);
        } else {
            k = nex[k];
        }
    }
    /*
    for (int i = 2, k = 0; i <= n; ++i) {
        while (k && d[k+1] != d[i]) k = nex[k];
        if (d[k+1] == d[i]) ++k;
        nex[i] = k;
    }
    */
}

inline void KMP()
{
    int i = 0, j = 0, k, len = n-1;
    while (i < 2*n-2) {
        if (j == -1 || c[i] == d[j]) {
            ++i; ++j;
        } else {
            j = nex[j];
        }
        if (j == len) {
            k = i-len;
            cout << k << " " << (a[k]^b[0]) << endl;
            j = nex[j];
        }
    }
    /*
    for (int i = 1, j = 0, k; i < 2*n; ++i) {
        while (j && c[i] != d[j+1]) j = nex[j];
        if (d[j+1] == c[i]) ++j;
        if (j == n) {
            k = i-n;
            cout << k << " " << (a[k]^b[0]) << endl;
            j = nex[j];
        }
    }
    */
}

inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    if (n == 1) { cout << 0 << " " << (a[0]^b[0]) << endl; return; }
    for (int i = 0; i < 2*n-2; ++i) c[i] = a[i%n]^a[(i+1)%n];
    for (int i = 0; i+1 < n; ++i) d[i] = b[i]^b[i+1];
    GetNext();
    // KMP();
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