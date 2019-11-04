#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int t, n, r, p, s, res;
char ans[N];
string str;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> r >> p >> s >> str;
        res = 0;
        for (int i = 0; i < n; ++i) {
            char c = str[i];
            ans[i] = 0;
            if (c == 'P') {
                if (s) {
                    ++res;
                    --s;
                    ans[i] = 'S';
                }
            }
            if (c == 'R') {
                if (p) {
                    ++res;
                    --p;
                    ans[i] = 'P';
                }
            }
            if (c == 'S') {
                if (r) {
                    ++res;
                    --r;
                    ans[i] = 'R';
                }
            }
        }
        if (res < (n+1)/2) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            if (ans[i]) cout << ans[i];
            else {
                if (s) {
                    --s;
                    cout << 'S';
                } else if (p) {
                    --p;
                    cout << 'P';
                } else if (r) {
                    --r;
                    cout << 'R';
                }
            }
        }
        cout << endl;
    }
    return 0;
}
