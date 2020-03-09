#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int testcase = 1;
int n;
int a[N];
string s;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> testcase;
    while (testcase--) {
        cin >> n >> s;
        memset(a, 0, sizeof(int)*(n+3));
        int p = 1;
        for (int i = n-2, j, last = i; i >= 0; --i) {
            if (s[i] == '>') continue;
            for (int k = last; k > i+1 ; --k) a[k] = p++;
            j = i;
            while (j-1 >= 0 && s[j-1] == '<') --j;
            for (int k = j; k <= i+1; ++k) a[k] = p++;
            i = j;
            last = i-1;
        }
        for (int i = n-1; i >= 0; --i) if (!a[i]) a[i] = p++;
        for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];

        memset(a, 0, sizeof(int)*(n+3));
        p = 1;
        for (int i = 0, j, last = 0; i < n-1; ++i) {
            if (s[i] == '<') continue;
            j = i;
            while (j+1 < n-1 && s[j+1] == '>') ++j;
            for (int k = j+1; k > i; --k) a[k] = p++;
            for (int k = last; k <= i; ++k) a[k] = p++;
            i = j;
            last = j+2;
        }
        for (int i = 0; i < n; ++i) if (!a[i]) a[i] = p++;
        for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
    }
    return 0;
}

