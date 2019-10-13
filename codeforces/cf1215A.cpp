#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e2+7;

int n, a1, a2, k1, k2;

int main()
{
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int sum = a1*(k1-1)+a2*(k2-1);
    cout << max(0, n-sum) << " ";
    if (k1 > k2) swap(k1, k2), swap(a1, a2);
    int cnt = min(a1, n/k1), res = cnt;
    n -= cnt*k1;
    cnt = min(a2, n/k2);
    res += cnt;
    n -= cnt*k2;
    cout << res << endl;
    return 0;
}
