#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
string s;

int main()
{
    cin >> n >> s;
    int step = (n-11)/2, cnt8 = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '8') {
            ++cnt8;
        } else {
            if (cnt8 <= step) ++cnt;
        }
    }
    if (cnt8 <= step || cnt > step) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
