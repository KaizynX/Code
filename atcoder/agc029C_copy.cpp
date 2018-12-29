#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n;

ll a[210000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int l = 0;
	int r = n + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
        // first ����λ��, second ������λ����ֵ
		vector<pair<ll, int> > vv;
		int fl = 0;
		for (int i = 1; i < n; ++i) {
            // ��� a[i] > a[i-1] ��������0,���ı�
            // ��� a[i] == a[i-1] ��Ҫ��1
            // ��� a[i] < a[i-1] ��Ҫɾ��ĩβ��,�ټ�1
			if (a[i] <= a[i - 1]) {
                // ֻ��һ��,ûʲô�üӵ�
				if (mid == 1) {
					fl = 1;
					break;
				}
                // ɾ������ĳ���
				while (!vv.empty() && vv.back().first >= a[i])
					vv.pop_back();
                // ��ǰλ����λ�� [0, a[i]-1]
				int cur = a[i] - 1;
                // mid �� [0, mid-1] ������� mid-1 ��Ҫ��λ
				while (cur >= 0 && (vv.size() && vv.back().first == cur && vv.back().second == mid - 1))
					vv.pop_back(), --cur;
                // ��λ������
				if (cur < 0) {
					fl = 1;
					break;
				}
                // ���浱ǰ״̬
				if (vv.empty() || vv.back().first < cur)
					vv.push_back(make_pair(cur, 1));
				else // +1
					vv.back().second += 1;
			}
		}
		if (!fl)
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
	return 0;
}
