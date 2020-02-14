#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

int n;
vector<string> v[7];

inline void query(int l, int r, vector<string> &vec)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();
    string str;
    vec.clear();
    for (int i = 0, len = r-l+1; i < (len+1)*len/2; ++i) {
        cin >> str;
        sort(str.begin(), str.end());
        vec.emplace_back(str);
    }
    sort(vec.begin(), vec.end());
}

inline void intersect(const vector<string> &big, const vector<string> &sma, vector<string> &res)
{
    res.clear();
    for (auto b = big.begin(), s = sma.begin(); b != big.end(); ++b) {
        if (s == sma.end() || *b != *s) {
            res.emplace_back(*b);
        } else {
            ++s;
        }
    }
}

inline char differ(const string &s1, const string &s2)
{
    vector<int> cnt(26, 0);
    for (char c : s1) ++cnt[c-'a'];
    for (char c : s2) {
        if (!cnt[c-'a']) return c;
        else --cnt[c-'a'];
    }
    return ' ';
}

inline string solve(vector<string> &vec, const int len)
{
    sort(vec.begin(), vec.end(),
        [](const string &s1, const string s2){ return s1.length() < s2.length(); });
    string res = vec.front();
    for (int i = 1; i < (int)vec.size() && (int)vec[i].length() <= len; ++i)
        res += differ(vec[i-1], vec[i]);
    return res;
}

#ifdef DEBUG
inline void print(const vector<string> &vec)
{
    for (string s : vec)
        cout << s << " ";
    cout << endl;
}
#endif

int main()
{
    cin >> n;
    if (n <= 3) {
        string res;
        for (int i = 1; i <= n; ++i) {
            cout << "? " << i << " " << i << endl;
            cout.flush();
            char c;
            cin >> c;
            res += c;
        }
        cout << "! " << res << endl;
        return 0;
    }
    query(1, n/2, v[0]);
    query(1, n/2-1, v[1]);
    intersect(v[0], v[1], v[2]);
    string res = solve(v[2], n/2);
    reverse(res.begin(), res.end());
    // v[4] [n/2+1, n]
    // v[5] [n/2, n]
    query(1, n, v[3]);
    intersect(v[3], v[1], v[4]);
    intersect(v[3], v[0], v[5]);
    intersect(v[4], v[5], v[6]);
#ifdef DEBUG
    print(v[4]);
    print(v[5]);
    print(v[6]);
    cout << solve(v[6], n-n/2+1) << endl;
#endif
    res += solve(v[6], n-n/2+1).substr(1);
    cout << "! " << res << endl;
    return 0;
}
