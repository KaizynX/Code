#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;

int n;
long long m;
int a[N];
long long sum[N];

// all >= x
inline long long count(int x)
{
    long long cnt = 0;
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(a+1, a+n+1, x-a[i])-a;
        cnt += n-p+1;
    }
    return cnt;
}

inline long long calc(int x)
{
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(a+1, a+n+1, x-a[i])-a;
        res += sum[n]-sum[p-1]+(n-p+1ll)*a[i];
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    // reverse(a+1, a+n+1);
    for (int i = 1; i <= n+1; ++i) sum[i] = sum[i-1]+a[i];
    // int l = 2*a[n], r = 2*a[1];
    int l = 2*a[1], r = 2*a[n];
    while (l < r) {
        int mid = (l+r+1)>>1;
        if (count(mid) >= m) l = mid;
        else r = mid-1;
    }
    long long cnt = count(l), res = calc(l);
#ifdef DEBUG
    cout << l << " " << cnt << " " << res << endl;
#endif
    cout << res-(cnt-m)*l << endl;
    return 0;
}
