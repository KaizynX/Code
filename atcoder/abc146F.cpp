#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
int nex[N];
string s;
vector<int> res;

int main()
{
    cin >> n >> m >> s;
    nex[n] = n;
    for (int i = n-1; i >= 0; --i) {
        if (s[i] == '1') nex[i] = nex[i+1];
        else nex[i] = i;
    }
    int p = n;
    while (p) {
        int q = max(0, p-m);
        q = nex[q];
        if (p == q) {
            cout << -1 << endl;
            return 0;
        }
        res.emplace_back(p-q);
        p = q;
    }
    reverse(res.begin(), res.end());
    for (int i : res) cout << i << " ";
    cout << endl;
    return 0;
}
