#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, k, m;
int a[Maxn];

int main()
{
    cin >> n >> k >> m;
    long long sum = 0;
    for(int i = 0; i < n; ++i)
        cin >> a[i], sum += a[i];
    sort(a, a+n);
        double ans = double(sum+min(m, k*n))/n;
        for(int i = 0; i < min(m, n-1); ++i)
        {
            sum -= a[i];
            double cur = (double)(sum+min(m-i-1, k*(n-i-1)))/(n-i-1);
            ans = max(ans, cur);
        }
        cout << ans << endl;
    //system("pause");
    return 0;
}