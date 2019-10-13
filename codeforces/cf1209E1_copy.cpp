#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 12;
const int MAXM = 2000;
int a[MAXN + 5][MAXM + 5], n, m;
int f[1<<MAXN], g[1<<MAXN], h[1<<MAXN], lg[1<<MAXN];
int lowbit(int x) {return x & -x;}
struct node{
    int key, id;
    friend bool operator < (node a, node b) {
        return a.key > b.key;
    }
}arr[MAXM + 5];
bool tag[MAXM + 5];
void solve() {
    scanf("%d%d", &n, &m);
    for(int j=1;j<=m;j++)
        tag[j] = false, arr[j].key = 0, arr[j].id = j;
    for(int i=0;i<n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d", &a[i][j]), arr[j].key = max(arr[j].key, a[i][j]);
    sort(arr + 1, arr + m + 1);
    for(int i=1;i<=m&&i<=n;i++)
        tag[arr[i].id] = true;
    int tot = (1<<n);
    for(int j=0;j<tot;j++) f[j] = 0;
    for(int j=0;j<n;j++) lg[1<<j] = j;
    // f[] - last, h[] - now
    // for col
    for(int i=1;i<=m;i++) {
        if( !tag[i] ) continue;
        // h and f make dp[2][]
        for(int j=0;j<tot;j++) h[j] = 0;
        // rotate n times
        for(int j=1;j<=n;j++) {
            // g is tmp
            for(int k=0;k<tot;k++)
                g[k] = f[k];
            // for states
            for(int k=0;k<tot;k++) {
                // p is that not be chosen
                int p = (tot - 1)^k;
                // get every that not be chosen
                while( p ) {
                    // x == 1<<y
                    int x = lowbit(p), y = lg[x];
                    // choose y'th from col i
                    g[k|x] = max(g[k|x], g[k] + a[y][i]);
                    p -= x;
                }
            }
            // rotate
            int tmp = a[0][i];
            for(int k=0;k<n-1;k++)
                a[k][i] = a[k + 1][i];
            a[n - 1][i] = tmp;

            for(int j=0;j<tot;j++)
                h[j] = max(h[j], g[j]), g[j] = 0;
        }
        // h and f make dp[2][]
        for(int j=0;j<tot;j++) f[j] = h[j];
    }
    printf("%d\n", f[tot - 1]);
}
int main() {
    int t; scanf("%d", &t);
    while( t-- ) solve();
}
