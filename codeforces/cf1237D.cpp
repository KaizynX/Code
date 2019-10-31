#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int n, head, tail;
int a[N], c[N];
pair<int, int> q[N<<1];

int main()
{
    cin >> n;
    int maxa = 0, mina = 1e9;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    if (mina*2 >= maxa) {
        for (int i = 1; i <= n; ++i)
            cout << -1 << " \n"[i==n];
        return 0;
    }

    for (int i = 0; i < 2*n; ++i) {
        while (head < tail && q[head+1].first > a[i%n]*2) {
            ++head;
            c[q[head].second%n] = (i-q[head].second)%n;
        }
        while (head < tail && q[tail].first <= a[i%n]) {
            --tail;
        }
        q[++tail] = { a[i%n], i };
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i)
        cout << c[i] << " \n"[i==n-1];
#endif
    for (int i = 0; i < n; ++i) {
        if (!c[i]) continue;
        for (int j = i-1; !c[(j+n)%n]; --j) c[(j+n)%n] = c[(j+1+n)%n]+1;
    }
    for (int i = 0; i < n; ++i) {
        cout << c[i] << " \n"[i==n-1];
    }
    return 0;
}
