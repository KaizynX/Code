#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int q, n;
long long k;
string str;

int main()
{
    cin >> q;
    while (q--) {
        cin >> n >> k >> str;
        int j = 0;
        for (int i = 0, cnt = 0; i < n; ++i) {
            if (str[i] == '1') {
                ++cnt;
            } else {
                if (k >= cnt) {
                    k -= cnt;
                    ++j;
                    putchar('0');
                } else {
                    for ( ; j < i-k; ++j) putchar('1');
                    putchar('0');
                    for (j = i-k+1; j <= i; ++j) putchar('1');
                    for (j = i+1; j < n; ++j) putchar(str[j]);
                    break;
                }
            }
        }
        for ( ; j < n; ++j) putchar('1');
        putchar('\n');
    }
    return 0;
}
