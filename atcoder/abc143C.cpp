#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, res = 1;
string s;

int main()
{
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) continue;
        else ++res;
    }
    cout << res << endl;
    return 0;
}
