#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int n, m, ans;
int cnt[Maxn];

int main()
{
    cin >> n >> m;
    for(int i = 1, a; i <= n; ++i)
    {
        cin >> a;
        cnt[a]++;
        if(cnt[a] >= 3)
        {
            cnt[a] -= 3;
            ans++;
        }
    }
    for(int i = 1; i <= 1e6-2; ++i)
    {
        int num = min(cnt[i], min(cnt[i+1], cnt[i+2]));
        for(int j = i; j <= i+2; ++j)
            cnt[i] -= num;
        ans += num;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}