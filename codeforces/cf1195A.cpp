#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;

int n, k;
int a[Maxn];

int main()
{
    cin >> n >> k;
    for(int i = 1, tmp; i <= n; ++i)
    {
        cin >> tmp;
        a[tmp]++;
    }
    int cnt = 0;
    for(int i = 1; i <= k; ++i)
        cnt += a[i]&1;
    cnt -= n&1;
    cout << n-cnt/2 << endl;
    return 0;
}
