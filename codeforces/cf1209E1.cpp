#include <bits/stdc++.h>

using namespace std;

const int N = 4;
const int M = 1e2+7;
const int INF = 1e9;

int t, n, m, res;

struct Node
{
    int x, y, v;
    Node() {}
    Node(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}
    // bool operator < (const Node &nex) const { return v > nex.v; }
};

bool cmpv(const Node &a, const Node &b) { return a.v > b.v; }
bool cmpy(const Node &a, const Node &b) { return a.y < b.y; }

vector<Node> vec, choose;

int main()
{
    cin >> t;
    while (t--) {
        res = 0;
        vec.clear();
        choose.clear();
        cin >> n >> m;
        for (int i = 1, tmp; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> tmp;
                vec.push_back({ i, j, tmp });
            }
        }
        // nth_element(vec.begin(), vec.begin()+n, vec.end());
        sort(vec.begin(), vec.end(), cmpv);
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i].v < vec[n-1].v) break;
            choose.push_back(vec[i]);
            if (i < n) res += vec[i].v;
        }
        sort(choose.begin(), choose.end(), cmpy);
        if (n == 4 && choose.size() == 4 && 
            abs(choose[0].x-choose[1].x) != abs(choose[2].x-choose[3].x) &&
            choose[0].y == choose[1].y && choose[2].y == choose[3].y && choose[0].y != choose[2].y)
        {
            int change = -INF;
            for (int i = 4; i < vec.size() && vec[i].v == vec[4].v; ++i) {
                if (vec[i].y != vec[0].y && vec[i].y != vec[2].y) {
                    change = max(change, vec[4].v-vec[3].v);
                } else if (vec[i].y == vec[0].y) {
                    change = max(change, vec[i].v-min(vec[2].v, vec[3].v));
                } else if (vec[i].y == vec[2].y) {
                    change = max(change, vec[i].v-min(vec[0].v, vec[1].v));
                }
            }
            res += change;
        }
        cout << res << endl;
    }
    return 0;
}
