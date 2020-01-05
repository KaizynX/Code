#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, k;
string s;
char a[128];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> s;
    for(int i = 0; i < k; ++i) {
        char c;
        cin >> c;
        a[c] = 1;
    }
    long long res = 0;
    for (int i = 0, cnt = 0; i < n; ++i) {
        if (a[s[i]]) ++cnt;
        if (i == n-1 || !a[s[i]]) {
            res += 1ll*cnt*(cnt+1)/2;
            cnt = 0;
        }
    }
    cout << res << endl;
    return 0;
}

