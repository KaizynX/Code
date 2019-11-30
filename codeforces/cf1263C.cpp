#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int T, n;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> res(1, 0);
        for (int i = 1; i*i <= n; ++i) {
            res.emplace_back(n/i);
            if (n/i == i) break;
            res.emplace_back(i);
        }
        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

