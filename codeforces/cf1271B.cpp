#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;

int n;
string s;
int a[N];
vector<int> res;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int t = 0; t <= 1; ++t) {
        res.clear();
        for (int i = 1; i <= n; ++i)
            a[i] = s[i-1] == 'W' ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            if (a[i] != t) {
                a[i] ^= 1;
                a[i+1] ^= 1;
                res.emplace_back(i);
            }
        }
        if (a[n] == t) {
            cout << res.size() << endl;
            for (int i : res) cout << i << ' ';
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}

