#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e2+7;

int n, m, k;
vector<int> v[3];
vector<pair<int, int> > vv;

#ifdef DEBUG
void print()
{
    cout << "////////" << endl;
    for (int i = 0; i < (int)vv.size(); ++i) {
        cout << "[" << vv[i].first << ", " << vv[i].second << "]" << endl;
    }
    cout << "////////" << endl;
}
#endif

int main()
{
    while (cin >> n >> m >> k) {
        for (int i = 0; i < 3; ++i) v[i].clear();
        vv.clear();
        for (int i = 1, a, s; i <= n; ++i) {
            cin >> a >> s;
            if (s <= 4) v[0].push_back(a);
            else if (s <= 6) v[1].push_back(a);
            else v[2].push_back(a);
        }
        if (min(k, (int)v[0].size()) <= m) {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i < 3; ++i) {
            sort(v[i].begin(), v[i].end());
            // reveres(v[i].begin(), v[i].end());
        }
        
        for (int i = 0; i <= m; ++i) {
            vv.push_back(make_pair(v[0].back(), 0));
            v[0].pop_back();
        }
        #ifdef DEBUG
        print();
        #endif
        int p = m;
        k -= m+1;
        while (k > 0 && p >= 0 && v[1].size() && vv[p].first < v[1].back()) {
            vv[p] = make_pair(v[1].back(), 1);
            --k; --p;
            v[1].pop_back();
        }
        sort(vv.begin(), vv.end());
        #ifdef DEBUG
        print();
        #endif
        p = 0;
        while (k > 0 && p <= m && v[2].size() && vv[p].first < v[2].back() && v[0].size()) {
            if (vv[p].second) {
                v[0].pop_back();
                vv[p] = make_pair(v[2].back(), 2);
                --k; ++p;
                v[2].pop_back();
            } else {
                if (k < 2) break;
                v[0].pop_back();
                vv[p] = make_pair(v[2].back(), 2);
                k -= 2; ++p;
                v[2].pop_back();
            }
        }
        sort(vv.begin(), vv.end());
        #ifdef DEBUG
        print();
        #endif
        cout << vv.front().first << endl;
    }
    return 0;
}
