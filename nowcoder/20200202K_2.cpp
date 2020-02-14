#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int INF = 2e9;

int n, a1, a2;
int b1[N], b2[N];

inline bool check(int mid)
{
    long long v1 = 1ll*a1*mid, v2 = 1ll*a2*mid, tmp = 1ll*mid*(mid+1)/2;
    for (int i = 1; i <= n; ++i)
        if (max(0ll, b1[i]-v1)+max(0ll, b2[i]-v2) <= tmp)
            return true;
    return false;
}

int main()
{
    cin >> a1 >> a2 >> n;
    for (int i = 1; i <= n; ++i) cin >> b1[i] >> b2[i];
    int l = 1, r = max(b1[1], b2[1]), mid;
    while (l < r) {
        mid = (l+r)>>1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
    return 0;
}
