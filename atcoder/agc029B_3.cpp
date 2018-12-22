#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n, ans;
int a[Maxn], pow2[35];
multiset<int> s;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        s.insert(a[i]);
    }
    pow2[0] = 1;
    for(int i = 1; i < 31; ++i) pow2[i] = pow2[i-1]<<1;
    sort(a, a+n);

    for(int i = n-1; i; --i)
    {
        if(s.find(a[i]) == s.end()) continue;
        s.erase(s.find(a[i]));
        // a[i] < val <= 2*a[i] <= 2e9 < 2^31
        int val = *upper_bound(pow2, pow2+31, a[i]);
        if(s.find(val-a[i]) != s.end())
        {
            ans++;
            s.erase(s.find(val-a[i]));
        }
    }
    cout << ans << endl;
    return 0;
}
