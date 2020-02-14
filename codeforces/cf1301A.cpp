#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int testcase = 1;
string a, b, c;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> a >> b >> c;
        int flag = 1;
        for (int i = 0; i < (int)a.length(); ++i) {
            if (a[i] == c[i] || b[i] == c[i]) continue;
            flag = 0;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
