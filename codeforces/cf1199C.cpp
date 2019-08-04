#include <bits/stdc++.h>

using namespace std;

const int Maxn = 4e5+7;

int n, I, c;
int a[Maxn], b[Maxn], s[Maxn];

int main()
{
    cin >> n >> I;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int k = I*8/n, K = 1;
    if(k >= 30)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 1; i <= k; ++i) K *= 2;
    sort(a+1, a+n+1);
    b[++c] = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(a[i] == a[i-1]) b[c]++;
        else b[++c] = 1;
    }
    /*
    cout << K << endl;
    for(int i = 1; i <= c; ++i) cout << b[i] << " ";
    cout << endl;
    */
    if(c <= K)
    {
        cout << 0 << endl;
        return 0;
    }
    int res = 0;
    for(int i = 1; i <= c; ++i) s[i] = s[i-1]+b[i];
    for(int l = 1; l+K-1 <= n; ++l)
        res = max(res, s[l+K-1]-s[l-1]);
    cout << n-res << endl;
    return 0;
}
