#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

int n;
vector<string> v[7];

struct Node
{
    vector<int> vec;
    Node(){ vec = vector<int>(26, 0); }
    friend Node operator + (const Node &n1, const Node &n2) {
        Node res;
        for (int i = 0; i < 26; ++i)
            res.vec[i] = n1.vec[i]+n2.vec[i];
        return res;
    }
    friend Node operator - (const Node &n1, const Node &n2) {
        Node res;
        for (int i = 0; i < 26; ++i)
            res.vec[i] = n1.vec[i]-n2.vec[i];
        return res;
    }
    Node operator += (const Node &node) { return *this = *this+node; }
    Node operator -= (const Node &node) { return *this = *this-node; }
} cnt[N];

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

    query(1, n, v[3]);
    for (string s : v[3]) {
        for (char c : s) {
            ++cnt[s.length()].vec[c-'a'];
        }
    }
    for (int i = n/2; i < n; ++i) {
        cnt[i] -= cnt[i+1];
    }
    for (int i = n; i > n/2; --i) {
        cnt[i] -= cnt[i-1];
    }
    // cnt[i] n-i+1 && i
    for (int i = n/2+1; i <= n; ++i) {
        if (n-i < n/2) --cnt[i].vec[res[n-i]-'a'];
        for (int j = 0; j < 26; ++j)
            if (cnt[i].vec[j]) res += char('a'+j);
    }

    cout << "! " << res << endl;
    return 0;
}
