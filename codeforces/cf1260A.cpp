#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1, c, sum; i <= n; ++i) {
        cin >> c >> sum;
        long long res = 0;
        for (int i = 1; i <= sum%c; ++i) {
            res += 1ll*(sum/c+1)*(sum/c+1);
        }
        for (int i = sum%c+1; i <= c; ++i) {
            res += 1ll*(sum/c)*(sum/c);
        }
        cout << res << endl;
    }
    return 0;
}
