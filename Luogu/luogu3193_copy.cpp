/*
 * @Author: Kaizyn
 * @Date: 2020-03-29 20:20:40
 * @LastEditTime: 2020-03-29 20:21:51
 */
#include<bits/stdc++.h>
using namespace std;
inline int read(){
    char ch = getchar(); int u = 0, f = 1;
    while (!isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
    while (isdigit(ch)) { u = (u << 1) + (u << 3) + ch - 48; ch = getchar(); }
    return u * f;
}
const int maxn = 5050;
int f[maxn][30], n, m, k;
int nxt[maxn], match[maxn][50];
char md[maxn];
inline void Kmp(){ 
    nxt[0] = -1;
    for (int i = 1; i <= m; ++i){
        int j = nxt[i - 1];
        while (j != -1 && md[j + 1] != md[i]) j = nxt[j];
        nxt[i] = j + 1;
    }
    nxt[0] = 0;
    for (int i = 0; i < m; ++i){
        for (int j = '0'; j <= '9'; ++j){
            int temp = i;
            while (md[temp + 1] != j && temp > 0) temp = nxt[temp];
            if (md[temp + 1] == j) temp++;
            if (temp < m) match[i][temp]++;
        }   
    }
}
class MARTIX{
public:
    int mr[23][23];
    MARTIX(){ memset(mr, 0, sizeof(m)); }   
    void pr(){ for (int i = 0; i <= m; i++, cerr << endl) for (int j = 0; j <= m; ++j) cerr << mr[i][j] << " "; }
    MARTIX operator * (MARTIX B){
        MARTIX Rtn;
        memset(Rtn.mr, 0, sizeof(Rtn.mr));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                for (int p = 0; p < m; ++p)
                    { (Rtn.mr[i][j] += mr[i][p] * B.mr[p][j]) %= k; }
        return Rtn;
    }
}F, G;

inline MARTIX ksm(MARTIX A, int pw){
    MARTIX Rtn;
    for (int i = 0; i <= m; ++i)
        Rtn.mr[i][i] = 1;
    for (; pw; pw >>= 1, A = A * A)
        if (pw & 1) Rtn = Rtn * A;
    return Rtn;
}
signed main(){

    n = read(), m = read(), k = read(); scanf("%s", md + 1);

    Kmp();

    F.mr[0][0] = 1;
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= m; ++j)
            G.mr[i][j] = match[i][j];
    G = ksm(G, n); 
    F = F * G;
    int ans = 0;

    for (int i = 0; i < m; ++i) { (ans += F.mr[0][i]) %= k; }
    printf("%d", ans);
    for (int i = 0; i <= m; ++i) cout << nxt[i] << " \n"[i==m];
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << match[i][j] << " \n"[j==m];
        }
    }
    return 0;
}