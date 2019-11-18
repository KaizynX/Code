#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

int n, k;
long long res;

int main()
{
    scanf("%d %d", &n, &k);
    res = 1ll*n*k;
    // sum k%i (1 <= i <= n)
    // n*k - sum (k/i)*i
    for (int i = 1; i*i <= k; ++i) {
        // (k/x) == i -> i <= k/x < i+1 -> i*x <= k < (i+1)*x
        // [k/(i+1), k/i]
        if (i <= n && k/i != i) res -= k/i*i;
        int l = k/(i+1)+1, r = min(k/i+(k%i != 0), n);
        while (l <= r && k/l > i) ++l;
        while (l <= r && k/r < i) --r;
        if (l > r) continue;
#ifdef DEBUG
        cout << i << ":" << l << " " << r << endl;
#endif
        res -= 1ll*i*(l+r)*(r-l+1)/2;
    }
    cout << res << endl;
    return 0;
}
