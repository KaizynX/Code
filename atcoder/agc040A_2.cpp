#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 5e5+7;
const int INF = 1e9;

string str;
int a[N], flag[N];

inline bool cmp(int i)
{
    return str[i] == '<' ? a[i-1] < a[i] : a[i-1] > a[i];
}

int main()
{
    cin >> str;
    int n = str.length()+1;
    long long sum = 0;
    for (int i = 0, cnt = 0; i < n; ++i) {
        a[i] = max(a[i], cnt);
        if (i < (int)str.length() && str[i] == '<') {
            ++cnt;
        } else {
            cnt = 0;
        }
    }
    for (int i = str.length()-1, cnt = 0; i >= -1; --i) {
        a[i+1] = max(a[i+1], cnt);
        if (i >= 0 && str[i] == '>') {
            ++cnt;
        } else {
            cnt = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
