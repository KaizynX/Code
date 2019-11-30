#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e2+7;
const int d[5] = { 0, 1, 0, -1, 0 };

int T, r, c, k, sum;
int a[N][N], res[N][N];
vector<char> mark;

inline void f(int x, int y, int mk) {
    queue<pair<int, int>> q;
    q.push({x, y});
    res[x][y] = mk;
    int now = 1, num = sum/k+(mk < sum%k), nx, ny;
    while (now < num && q.size()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            nx = cur.first+d[i];
            ny = cur.second+d[i+1];
            if (nx < 1 || ny < 1 || nx > r || ny > c || res[nx][ny] != -1)
                continue;
            res[nx][ny] = mk;
            if (a[nx][ny] && ++now >= num) break;
            q.push({nx, ny});
        }
    }
}

inline void filll(int x, int y, int mk) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int nx, ny;
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            nx = cur.first+d[i];
            ny = cur.second+d[i+1];
            if (nx < 1 || ny < 1 || nx > r || ny > c || res[nx][ny] != -1)
                continue;
            res[nx][ny] = mk;
            q.push({nx, ny});
        }
    }
}

inline void print()
{
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
#ifdef DEBUG
            cout << (res[i][j] == -1 ? ' ' : mark[res[i][j]]);
#else
            cout << mark[res[i][j]];
#endif
        }
        cout << endl;
    }
}

int main()
{
    char ch;
    for (ch = 'a'; ch <= 'z'; ++ch) mark.push_back(ch);
    for (ch = 'A'; ch <= 'Z'; ++ch) mark.push_back(ch);
    for (ch = '0'; ch <= '9'; ++ch) mark.push_back(ch);
    cin >> T;
    while (T--) {
        sum = 0;
        cin >> r >> c >> k;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                cin >> ch;
                a[i][j] = (ch == 'R' ? 1 : 0);
                sum += a[i][j];
                res[i][j] = -1;
            }
        }
        int mk = 0;
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (res[i][j] != -1) continue;
                if (a[i][j]) f(i, j, mk++);
            }
        }
#ifdef DEBUG
        print();
#endif
        for (int i = 1; i <= r; ++i)
            for (int j = 1; j <= c; ++j)
                if (res[i][j] != -1)
                    filll(i, j, res[i][j]);
        print();
    }
    return 0;
}
