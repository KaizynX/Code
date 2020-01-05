#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m, t, top;
int h[N];
pair<int, int> stk[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int res = 0;
    char c;
    for (int i = 1, len; i <= n; ++i) {
        top = 0;
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == 'F') ++h[j];
            else h[j] = 0;

            len = 0;
            while (top && stk[top].first >= h[j]) {
                len += stk[top].second;
                res = max(res, stk[top].first*len);
                --top;
            }
            stk[++top] = {h[j], len+1};
        }
        len = 0;
        while (top) {
            len += stk[top].second;
            res = max(res, stk[top].first*len);
            --top;
        }
    }
    cout << 3*res << endl;
    return 0;
}

