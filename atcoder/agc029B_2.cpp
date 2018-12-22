#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 2e5+7;

int n, ans;
int a[Maxn], vis[Maxn], pow2[35];

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    pow2[0] = 1;
    for(int i = 1; i < 31; ++i) pow2[i] = pow2[i-1]<<1;
    sort(a, a+n);
#ifdef DEBUG
    for(int i = 0; i < n; ++i) cout << a[i] << " ";
    cout << endl;
#endif
    for(int i = n-1; i; --i)
    {
        if(vis[i]) continue;
        // a[i] < val <= 2*a[i]
        int val = *upper_bound(pow2, pow2+31, a[i]);
        if(!val) continue; // val = 2^31
        int head = lower_bound(a, a+i, val-a[i])-a,
            tail = upper_bound(a, a+i, val-a[i])-a;
#ifdef DEBUG
        cout << val << " " << head << " " << tail << endl;
#endif
        for(int j = head; j < tail; ++j)
            if(!vis[j] && a[j] == val-a[i])
            {
                vis[j] = vis[i] = 1;
                ans++;
#ifdef DEBUG
                cout << "j:" << j << endl;
#endif
                break;
            }
    }
    cout << ans << endl;
    return 0;
}
