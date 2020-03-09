#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int testcase = 1;
int n;
int a[N];
set<int> sma, big;
string str;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> str;
        int l, r, p;

        sma.clear();
        big.clear();
        memset(a, 0, sizeof(int)*(n+3));
        if (str[0] == '<') sma.insert(0);
        else big.insert(0);
        if (str.back() == '>') sma.insert(n-1);
        else big.insert(n-1);
        for (int i = 1; i < n-1; ++i) {
            if (str[i-1] == '>' && str[i] == '<')
                sma.insert(i);
            if (str[i-1] == '<' && str[i] == '>')
                big.insert(i);
        }
        l = 1, r = n;
        while (l <= r) {
            p = *sma.begin();
            sma.erase(p);
            if (!a[p]) {
                a[p] = l++;
                if (p && !a[p-1] && str[p-1] == '>')
                    sma.insert(p-1);
                if (p < n-1 && !a[p+1] && str[p] == '<')
                    sma.insert(p+1);
            }
            if (l-1 >= r) break;
            p = *big.rbegin();
            big.erase(p);
            if (!a[p]) {
                a[p] = r--;
                if (p && !a[p-1] && str[p-1] == '<')
                    big.insert(p-1);
                if (p < n-1 && !a[p+1] && str[p] == '>')
                    big.insert(p+1);
            }
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];

        sma.clear();
        big.clear();
        memset(a, 0, sizeof(int)*(n+3));
        if (str[0] == '<') sma.insert(0);
        else big.insert(0);
        if (str.back() == '>') sma.insert(n-1);
        else big.insert(n-1);
        for (int i = 1; i < n-1; ++i) {
            if (str[i-1] == '>' && str[i] == '<')
                sma.insert(i);
            if (str[i-1] == '<' && str[i] == '>')
                big.insert(i);
        }
        l = 1, r = n;
        while (l <= r) {
            p = *sma.rbegin();
            sma.erase(p);
            if (!a[p]) {
                a[p] = l++;
                if (p && !a[p-1] && str[p-1] == '>')
                    sma.insert(p-1);
                if (p < n-1 && !a[p+1] && str[p] == '<')
                    sma.insert(p+1);
            }
            if (l-1 >= r) break;
            p = *big.begin();
            big.erase(p);
            if (!a[p]) {
                a[p] = r--;
                if (p && !a[p-1] && str[p-1] == '<')
                    big.insert(p-1);
                if (p < n-1 && !a[p+1] && str[p] == '>')
                    big.insert(p+1);
            }
        }
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}
