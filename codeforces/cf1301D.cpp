#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
typedef pair<int, string> pis;

int n, m, k;
vector<pis> v; 

inline void walk(const int t, const string &str)
{
    int len = str.length();
    if (t*len <= k) {
        v.emplace_back(t, str);
        k -= t*len;
    } else {
        if (k/len) v.emplace_back(k/len, str);
        if (k%len) v.emplace_back(1, str.substr(0, k%len));
        k = 0;
    }
}

inline void print()
{
    cout << v.size() << endl;
    for (pis p : v) cout << p.first << " " << p.second << endl;
    exit(0);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    if (k > 4*n*m-2*n-2*m) { cout << "NO" << endl; return 0; }
    cout << "YES" << endl;
    --m; // shit
    if (m/4) walk(m/4, "RRRR");
    if (!k) print();
    if (m%4) walk(1, string(m%4, 'R'));
    if (!k) print();
    if (m/4) walk(m/4, "LLLL");
    if (!k) print();
    if (m%4) walk(1, string(m%4, 'L'));
    if (!k) print();
    for (int i = 2; i <= n; ++i) {
        walk(1, "D");
        if (!k) print();
        if (m) walk(m, "RUD");
        if (!k) print();
        if (m/4) walk(m/4, "LLLL");
        if (!k) print();
        if (m%4) walk(1, string(m%4, 'L'));
        if (!k) print();
    }
    if (n/4) walk(n/4, "UUUU");
    if (!k) print();
    if (n%4) walk(1, string(n%4, 'U'));
    if (!k) print();

    return 0;
}
