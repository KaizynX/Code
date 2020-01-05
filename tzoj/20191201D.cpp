#include <bits/stdc++.h>

using namespace std;

int a, b;
int dp[] = {0,3,1,2,2,1,3,2,3,3,2,4,3,4,4,3};

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> a >> b) {
        if (a > b) swap(a, b);
        b -= a;
        if (b <= 10) cout << dp[b] << endl;
        else {
            int res = (b-5)/5;
            b -= 5*res;
            cout << res+dp[b] << endl;
        }
    }
    return 0;
}

