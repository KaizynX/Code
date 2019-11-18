#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int k, n, cnt;
int p[N];
string s, t;

int main()
{
    cin >> k;
    while (k--) {
        cin >> n >> s >> t;
        cnt = 0;
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[i]) continue;
            p[cnt++] = i;
            if (cnt > 2) {
                flag = 0;
                break;
            }
        }
        if (!flag || cnt == 1) {
            cout << "No" << endl;
        } else if (!cnt) {
            cout << "Yes" << endl;
        } else {
            cout << (s[p[0]] == s[p[1]] && t[p[0]] == t[p[1]] ? "Yes" : "No") << endl;
        }
    }
    return 0;
}
