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
        set<int> res;
        for (int i = n+1; i; --i) res.insert(n/i);
        cout << res.size() << endl;
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

