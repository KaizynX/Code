#include <bits/stdc++.h>
#define DEBUG

using namespace std;

string s;
int k;
long long ans;

inline int solve(string str)
{
    int res = 0, cnt = 1;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == str[i-1]) {
            ++cnt;
        } else {
            res += cnt/2;
            cnt = 1;
        }
    }
    return res+cnt/2;
}

int main()
{
    cin >> s >> k;
    if (k&1) {
        int x = solve(s), y = solve(s+s+s);
        ans = (1ll*(y-x)*k+(x-y)+x*2)/2;
    } else {
        int x = solve(s+s), y = solve(s+s+s+s);
        ans = 1ll*(y-x)*k/2+2*x-y;
    }
    cout << ans << endl;
    return 0;
}
