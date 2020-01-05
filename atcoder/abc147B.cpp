#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    int res = 0, l = 0, r = (int)s.length()-1;
    while (l < r) {
        res += s[l] != s[r];
        ++l; --r;
    }
    cout << res << endl;
    return 0;
}

