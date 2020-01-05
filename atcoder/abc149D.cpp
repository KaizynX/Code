#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k, r, s, p;
int a[N];
string str;

int main()
{
    cin >> n >> k >> r >> s >> p >> str;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'r') {
            if (i-k >= 0 && str[i-k] == 'r' && !a[i-k]) {
                a[i] = 1;
            } else {
                res += p;
            }
        } else if (str[i] == 's') {
            if (i-k >= 0 && str[i-k] == 's' && !a[i-k]) {
                a[i] = 1;
            } else {
                res += r;
            }
        } else if (str[i] == 'p') {
            if (i-k >= 0 && str[i-k] == 'p' && !a[i-k]) {
                a[i] = 1;
            } else {
                res += s;
            }
        }
    }
    cout << res << endl;
    return 0;
}


