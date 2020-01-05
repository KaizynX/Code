#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k;
string s, ss;

int main()
{
    cin >> n >> k >> s;
    cout << n << endl;
    ss = s;
    for (int i = k+1; i <= n; ++i)
        ss[i-1] = ss[i-k-1];
    if (ss >= s) {
        cout << ss << endl;
        return 0;
    }

    int t = k;
    while (t) {
        if (ss[t-1] == '9') {
            ss[t-1] = '0';
        } else {
            ++ss[t-1];
        }
        for (int i = t; i <= n; i += k) {
            ss[i-1] = ss[t-1];
        }
        if (ss[t-1] != '0') {
            break;
        }
        --t;
    }
    cout << ss << endl;
    return 0;
}

