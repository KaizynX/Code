#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double esp = 1e-1;

struct Node
{
    int mx = 0;
    map<int, double> mp;
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

inline bool zero(const double &x) { return abs(x) < esp; }

inline void print(const Node &node)
{
    vector<pair<int, double>> tmp;
    for (auto p : node.mp)
        if (!zero(p.second)) {
            tmp.emplace_back(p);
        }
    if (!tmp.size()) {
        cout << "0 0 0.0" << endl;
        return;
    }
    reverse(tmp.begin(), tmp.end());
    cout << tmp.size() << " ";
    for (int i = 0; i < (int)tmp.size(); ++i)
        cout << tmp[i].first << " " << tmp[i].second << " \n"[i+1==(int)tmp.size()];
}

inline void f()
{
    shang.mx = divv.mx-divvv.mx;
    for (int i = divv.mx; i >= divvv.mx; --i) {
        double tmp = divv.mp[i]/divvv.mp[divvv.mx];
        shang.mp[i-divvv.mx] = tmp;
        for (auto p : divvv.mp)
            divv.mp[i-divvv.mx+p.first] -= tmp*p.second;
#ifdef DEBUG
        print(divv);
#endif
    }
    for (int i = divvv.mx-1; i >= 0; --i) {
        // if (!divv.mp.count(i) || zero(divv.mp[i])) continue;
        yushu.mx = max(yushu.mx, i);
        yushu.mp[i] = divv.mp[i];
    }
}

int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(1);
    cin >> divv >> divvv;
    f();
    print(shang); print(yushu);
    return 0;
}
