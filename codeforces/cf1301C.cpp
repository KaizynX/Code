#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int testcase = 1;
int n, m;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m;
        long long res = 1ll*n*(n+1)/2;
        if (!m) { cout << 0 << endl; continue; }
        int zero = n-m;
        int part = zero/(m+1);
        if (!part) { cout << res-n+m << endl; continue; }
        int rest = zero-part*(m+1);
        res -= (m+1ll-rest)*part*(part+1)/2 + (part+1ll)*(part+2ll)*rest/2;
        cout << res << endl;
    }
    return 0;
}

