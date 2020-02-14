#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e4+7;

int n, m, tot, sum;
int cnt[N];
string mmp[N];
map<string, int> mp;

inline int get_id(const string &s)
{
    if (mp.count(s)) return mp[s];
    mmp[++tot] = s;
    return mp[s] = tot;
}

int main()
{
    string str;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        get_id(str);
    }
    cin >> m;
    for (int i = 1, a; i <= m; ++i) {
        cin >> str >> a;
        cnt[get_id(str)] += a;
        sum += a;
    }
    vector<string> res;
    for (int i = n+1; i <= tot; ++i) {
#ifdef DEBUG
        cout << mmp[i] << " " << cnt[i] << endl;
#endif
        if (cnt[i]*m > sum)
            res.emplace_back(mmp[i]);
    }
    if (res.empty()) {
        cout << "Bing Mei You" << endl;
        return 0;
    }
    sort(res.begin(), res.end());
    for (string s : res) cout << s << endl;
    return 0;
}
