#include <bits/stdc++.h>

using namespace std;

const int kN = 5e2+7;
const int kL = 56;

int T, n;
string s1 = "COFFEE", s2 = "CHICKEN";
long long k;
long long len[kN];

string solve(int cur, long long pos, int num)
{
    // cout << cur << " " << pos << " " << num << endl;
    if (cur == 1) return s1.substr(pos-1, min(num, 7-(int)pos));
    if (cur == 2) return s2.substr(pos-1, min(num, 8-(int)pos));
    if (cur-2 >= kL || pos+num-1 <= len[cur-2])
        return solve(cur-2, pos, num);
    if (pos > len[cur-2])
        return solve(cur-1, pos-len[cur-2], num);
    return solve(cur-2, pos, len[cur-2]-pos+1)
           +solve(cur-1, 1, num-(len[cur-2]-pos+1));
}

int main()
{
    // scanf("%d", &T);
    cin >> T;
    len[1] = 6; len[2] = 7;
    for (int i = 3; i <= 57; ++i)
        len[i] = len[i-2]+len[i-1];
    while (T--) {
        // scanf("%d%lld", &n, &k);
        cin >> n >> k;
        if (n > kL) n -= (n-kL)/2*2;
        cout << solve(n, k, 10) << endl;
    }
    return 0;
}
