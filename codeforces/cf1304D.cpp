#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int testcase = 1;
int n;
int a[N];
set<int> s;
string str;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> str;

        s.clear();
        memset(a, 0, sizeof(int)*(n+3));
        if (str[0] == '<') s.insert(0);
        if (str.back() == '>') s.insert(n-1);
        for (int i = 1; i < n-1; ++i) {
            if (str[i-1] == '>' && str[i] == '<')
                s.insert(i);
        }
        for (int i = 1; i <= n; ++i) {
            int p = *s.begin();
            s.erase(p);
            a[p] = i;
#ifdef DEBUG
            cout << p << " \n"[i==n];
#endif
            if (p && !a[p-1] && str[p-1] == '>' && (p-2 < 0 || str[p-2] == '>' || a[p-2]))
                s.insert(p-1);
            if (p < n-1 && !a[p+1] && str[p] == '<' && (p+1 >= n-1 || str[p+1] == '<' || a[p+2]))
                s.insert(p+1);
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];

        s.clear();
        memset(a, 0, sizeof(int)*(n+3));
        if (str[0] == '<') s.insert(0);
        if (str.back() == '>') s.insert(n-1);
        for (int i = 1; i < n-1; ++i) {
            if (str[i-1] == '>' && str[i] == '<')
                s.insert(i);
        }
        for (int i = 1; i <= n; ++i) {
            int p = *s.rbegin();
            s.erase(p);
            a[p] = i;
            if (p && !a[p-1] && str[p-1] == '>' && (p-2 < 0 || str[p-2] == '>' || a[p-2]))
                s.insert(p-1);
            if (p < n-1 && !a[p+1] && str[p] == '<' && (p+1 >= n-1 || str[p+1] == '<' || a[p+2]))
                s.insert(p+1);
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}

