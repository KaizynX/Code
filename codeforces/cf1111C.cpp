#include <bits/stdc++.h>

using namespace std;

const int Maxn = 30;
const int Maxk = 1e5+7;

int n, k, A, B;
int a[Maxk];

long long dp(int cur, int l, int r) // (l, r]
{
    int lpos = upper_bound(a+1, a+k+1, l)-a,   // a[lpos] > l
        rpos = upper_bound(a+1, a+k+1, r)-a-1, // a[rpos] <= r
        num = rpos-lpos+1;
    long long now = (num ? 1ll*B*num*(1<<cur): A);
    if(!num || !cur) return now;
    else return min(now, dp(cur-1, l, (l+r)/2)+dp(cur-1, (l+r)/2, r));
}

int main()
{
    cin >> n >> k >> A >> B;
    for(int i = 1; i <= k; ++i)
        cin >> a[i];
    sort(a+1, a+k+1);
    cout << dp(n, 0, 1<<n) << endl;
    //system("pause");
    return 0;
}