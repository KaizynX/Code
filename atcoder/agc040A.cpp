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
    str = '>'+str+'<';
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == '>' && str[i+1] == '<') {
            a[i] = 0;
            flag[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!flag[i]) continue;
        for (int j = i-1; j >= 0; --j) {
            if (flag[j]) break;
            int tmp = a[j+1]+(str[j+1] == '<' ? -1: 1);
            if (!a[i] || !cmp(j+1)) a[j] = tmp;
            else a[j] = min(a[j], tmp);
        }
        for (int j = i+1; j < n; ++j) {
            if (flag[j]) break;
            int tmp = a[j-1]+(str[j] == '<' ? 1: -1);
            if (!a[j] || !cmp(j)) a[j] = tmp;
            else a[j] = min(a[j], tmp);
        }
    }
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        cout << flag[i] << " \n"[i==n-1];
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " \n"[i==n-1];
    }
#endif
    cout << sum << endl;
    return 0;
}
