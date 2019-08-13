#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kL = 1e6+7;
const int kM[3] = { 1217, 1627, 2179 };
const unsigned long long kMM[3] = { 0, 4294967291, 3221225473 };

int n;
string res, str;
unsigned long long pre_h[3], bac_h[3], base_kM[3];

int main()
{
    cin >> n >> res;
    for(int i = 2, p; i <= n; ++i) {
        cin >> str;
        p = 0;
        for(int j = 0; j < 3; ++j) {
            pre_h[j] = 0;
            bac_h[j] = 0;
            base_kM[j] = 1;
        }
        for(int j = 0, cnt; j < min(str.length(), res.length()); ++j) {
            cnt = 0;
            for(int k = 0; k < 3; ++k) {
                pre_h[k] = pre_h[k]*kM[k]+str[j];
                bac_h[k] = bac_h[k]+res[res.length()-1-j]*base_kM[k];
                base_kM[k] *= kM[k];
                if (k) {
                    pre_h[k] %= kMM[k];
                    bac_h[k] %= kMM[k];
                    base_kM[k] %= kMM[k];
                }
                cnt += (pre_h[k] == bac_h[k]);
            }
            if (cnt == 3) p = j+1;
        }
        res += str.substr(p);
    }
    cout << res << endl;
    return 0;
}
