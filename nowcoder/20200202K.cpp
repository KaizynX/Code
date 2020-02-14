#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int INF = 2e9;

int n, res = INF;
int a1, a2, b1, b2;

inline int calc(int a, int b)
{
    return a ? b/a+(b%a != 0): INF;
}

inline bool check(int mid)
{
    for (int i = 0; i <= mid; ++i) {
        if (1ll*a1*mid+1ll*i*(i+1)/2 >= b1 &&
            1ll*a2*mid+1ll*(mid-i)*(mid-i+1)/2 >= b2)
            return true;
    }
    return false;
}

int main()
{
    cin >> a1 >> a2 >> n;
    for (int i = 1, l, r, mid; i <= n; ++i) {
        cin >> b1 >> b2;
        l = 1; r = min(res, max(calc(a1, b1), calc(a2, b2)));
        while (l < r) {
            mid = (l+r)>>1;
            if (check(mid)) r = mid;
            else l = mid+1;
        }
        if (check(l)) res = min(res, l);
    }
    cout << res << endl;
    return 0;
}
