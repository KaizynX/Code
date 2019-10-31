#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int a[N], f[N];
long long k;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> f[i];
    }
    sort(a+1, a+n+1);
    sort(f+1, f+n+1);
    reverse(a+1, a+n+1);
    long long l = 0, r = 1e12, mid, need;
    while (l < r) {
        mid = (l+r)>>1;
        need = 0;
        
        for (int i = 1; i <= n; ++i) {
            if (1ll*a[i]*f[i] <= mid) continue;
            need += a[i]-mid/f[i];
        }
        if (need <= k) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
    return 0;
}
