#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;

int T;
string s;

int main()
{
    cin >> T;
    while (T--) {
        cin >> s;
        int l = 0, r = s.length()-1;
        while (l <= r && s[l] == '0') ++l;
        while (l <= r && s[r] == '0') --r;
        int cnt = 0;
#ifdef DEBUG
        cout << l << " " << r << endl;
#endif
        for (int i = l; i <= r; ++i)
            cnt += s[i] == '0';
        cout << cnt << endl;
    }
    return 0;
}
