#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kL = 1e6+7;
const int kM1 = 1331;
const int kM2 = 2179;

int n;
string res, str;
unsigned long long pre_h1, pre_h2, bac_h1, bac_h2, base_kM1, base_kM2;

int main()
{
    cin >> n >> res;
    for(int i = 2, p; i <= n; ++i) {
        cin >> str;
        p = 0;
        pre_h1 = pre_h2 = bac_h1 = bac_h2 = 0;
        base_kM1 = 1, base_kM2 = 1;
        for(int j = 0; j < min(str.length(), res.length()); ++j) {
            pre_h1 = pre_h1*kM1+str[j];
            pre_h2 = pre_h2*kM2+str[j];
            bac_h1 = bac_h1+res[res.length()-1-j]*base_kM1;
            bac_h2 = bac_h2+res[res.length()-1-j]*base_kM2;
            base_kM1 *= kM1;
            base_kM2 *= kM2;
            if (pre_h1 == bac_h1 && pre_h2 == bac_h2) p = j+1;
        }
        res += str.substr(p);
    }
    cout << res << endl;
    return 0;
}
