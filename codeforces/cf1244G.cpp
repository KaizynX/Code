#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int n;
long long k;
int a[N];

int main()
{
    cin >> n >> k;
    long long sum = 1ll*n*(n+1)/2;
    if (k < sum) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) a[i] = i;
    int l = 1, r = n, lmid = (n+1)/2, rmid = (n+2)/2;
    while (l < lmid && r > rmid) {
        if (a[r]-a[l]+sum <= k) {
            sum += a[r]-a[l];
            swap(a[l], a[r]);
            ++l; --r;
        } else {
            break;
        }
    }
    if (sum < k) {
        while (l < lmid && a[r]-a[l]+sum > k) ++l;
        while (r > rmid && a[r]-a[l]+sum > k) --r;
        sum += a[r]-a[l];
        swap(a[l], a[r]);
    }

    cout << sum << endl;
    for (int i = 1; i <= n; ++i)
        cout << i << " \n"[i==n];
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " \n"[i==n];
    return 0;
}
