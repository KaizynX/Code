#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
string a, b;
int mp[128][128];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) continue;
        res += mp[b[i]][a[i]];
        ++mp[a[i]][b[i]];
    }
    cout << res << endl;
    return 0;
}
