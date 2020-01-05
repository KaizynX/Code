#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int T, n;
string s, t;
vector<int> p;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        p.clear();
        cin >> n >> s >> t;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) p.push_back(i);
        }
        if (p.size() == 0 || (p.size() == 2 && s[p[0]] == s[p[1]] && t[p[0]] == t[p[1]])) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
