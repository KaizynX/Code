#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kM = 998244353;

int n, P = 1, res = 1;
int cnt[8];
string s;

int main()
{
    cin >> n >> s;
    for (int i = 2; i <= n; ++i)
        P = (P*i)%kM;
    for (int i = 0, now; i < s.length(); ++i) {
        if (s[i] == 'R') now = 1;
        else if (s[i] == 'G') now = 2;
        else if (s[i] == 'B') now = 4;
        
        if (cnt[7-now]) {
            res = int(1ll*res*cnt[7-now]%kM);
            --cnt[7-now];
        } else {
            int flag = 0;
            for (int j = 1; j <= 4; j <<= 1) {
                if (now == j) continue;
                if (cnt[j]) {
                    flag = 1;
                    res = int(1ll*res*cnt[j])%kM;
                    ++cnt[j+now];
                    --cnt[j];
                    break;
                }
            }
            if (!flag) ++cnt[now];
        }
        // cout << i << " " << res << endl;
    }
    cout << 1ll*res*P%kM << endl;
    return 0;
}
