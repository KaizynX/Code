#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int mx = 0;
    map<int, int> mp;
    friend istream& operator >> (istream &is, Node &node) {
        int n;
        is >> n;
        for (int i = 0, e, c; i < n; ++i) {
            is >> e >> c;
            node.mp[e] = c;
            node.mx = max(e, node.mx);
        }
        return is;
    }
} divv, divvv, shang, yushu;

inline void f()
{
    for (auto it = divv.mp.begin(); it != divv.mp.end(); ++it)
        it->second *= 10;
    shang.mx = divv.mx-divvv.mx;
    for (int i = divv.mx; i >= divvv.mx; --i) {
        if (!divv.mp.count(i) || !divv.mp[i]) continue;
        int tmp = divv.mp[i]/divvv.mp[divvv.mx];
        if (!tmp) continue;
        shang.mp[i-divvv.mx] = tmp;
        for (auto p : divvv.mp)
            divv.mp[p.first+divvv.mx] -= tmp*p.second;
    }
    for (int i = divvv.mx-1; i >= 0; --i) {
        if (!divv.mp.count(i) || !divv.mp[i]) continue;
        yushu.mx = max(yushu.mx, i);
        yushu.mp[i] = divv.mp[i];
    }
}

inline void print(const Node &node)
{
    vector<pair<int, double>> tmp;
    for (auto p : node.mp)
        if (p.second) {
            tmp.emplace_back(p);
        }
    if (!tmp.size()) {
        cout << "0 0 0.0" << endl;
        return;
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp.size() << " ";
    for (int i = 0; i < (int)tmp.size(); ++i)
        cout << tmp[i].first << " " << tmp[i].second/10.0 << " \n"[i+1==(int)tmp.size()];
}

int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    cin >> divv >> divvv;
    f();
    print(shang); print(yushu);
    return 0;
}
