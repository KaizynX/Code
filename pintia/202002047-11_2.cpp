#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m, tot;
int vis[N];
int sex[N];
string mmp[N];
map<string, int> mp;
vector<int> parents[N];

inline int get_id(const string &x)
{
    if (mp.count(x)) return mp[x];
    mmp[++tot] = x;
    return mp[x] = tot;
}

void getp(int x, int d, int v)
{
    vis[x] += v;
    if (d >= 5) return;
    for (int i : parents[x])
        getp(i, d+1, v);
}

bool check(int x, int d)
{
    if (vis[x]) return false;
    if (d >= 5) return true;
    for (int i : parents[x])
        if (!check(i, d+1)) return false;
    return true;
}

int main()
{
    string s1, s2, s3, s4;
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> s1 >> s2;
        x = get_id(s1);
        if (s2.length() > 4 && s2.substr(s2.length()-4, 4) == "sson") {
            sex[x] = 0;
            parents[x].emplace_back(get_id(s2.substr(0, s2.length()-4)));
        } else if (s2.length() > 7 && s2.substr(s2.length()-7, 7) == "sdottir") {
            sex[x] = 1;
            parents[x].emplace_back(get_id(s2.substr(0, s2.length()-7)));
        } else {
            sex[x] = s2.back() == 'f';
            // parents[x].emplace_back(get_id(s2.substr(0, s2.length()-1)));
        }
    }
    cin >> m;
    for (int i = 1, x, y; i <= m; ++i) {
        cin >> s1 >> s2 >> s3 >> s4;
        if (!mp.count(s1) || !mp.count(s3)) { cout << "NA" << endl; continue; }
        x = mp[s1]; y = mp[s3];
        if (sex[x] == sex[y]) {
            cout << "Whatever" << endl;
            continue;
        }
        getp(x, 2, 1);
        cout << (check(y, 2) ? "Yes" : "No") << endl;
        getp(x, 2, -1);
    }
    return 0;
}
