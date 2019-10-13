#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int t, res;
string str;

int main()
{
    cin >> t;
    while (t--) {
        res = 0;
        cin >> str;
        for (int i = 0, cnt0 = 0; i < str.length(); ++i) {
            if (str[i] == '0') {
                ++cnt0;
            } else {
                ++res; // 1
                if (i+1 < str.length() && str[i+1] == '0') ++res; // 2
                for (int j = i, val = 0; j < str.length(); ++j) {
                    val = val*2+(str[j]-'0');
                    if (val < 3) continue;
                    if (cnt0+j-i+1 >= val) ++res;
                    else break;
                }
                cnt0 = 0;
            }
        }
        cout << res << endl;
    }
    return 0;
}
