#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int T, n;
int a[N];
map<int, int> mp;

int main()
{
    cin >> T;
    while (T--) {
        mp.clear();
        cin >> n;
        int res = n+1;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (mp.count(a[i])) res = min(res, i-mp[a[i]]+1);
            mp[a[i]] = i;
        }
        cout << (res == n+1 ? -1 : res) << endl;
    }
    return 0;
}
