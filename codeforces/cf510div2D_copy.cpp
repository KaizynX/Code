#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e6 + 5;

int n; long long t;
long long a[maxn], sum[maxn], b[maxn];

int C[maxn], cnt;

int lowbit(int x) {
	return x & -x;
}

void Add(int x) {
	for (int i = x; i <= cnt; i += lowbit(i)) C[i] ++;
}

int Q(int x) {
	int cur = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) cur += C[i];
	return cur;
}

int main(void) {
	scanf("%d%lld", &n, &t);
	for (int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
	sum[1] = a[1]; 
	for (int i = 2; i <= n; ++ i) sum[i] = sum[i - 1] + a[i];
	
	for (int i = 1; i <= n; ++ i) b[i] = sum[i]; b[n] = 0;
	sort(b + 1, b + 1 + n);
	cnt = unique(b + 1, b + 1 + n) - (b + 1);
	long long Ans = 0;
	for (int i = 1; i <= n; ++ i) {
		int idx = lower_bound(b + 1, b + 1 + cnt, sum[i - 1]) - b;
		Add(idx);
		idx = upper_bound(b + 1, b + 1 + cnt, sum[i] - t) - b - 1;
		Ans += Q(idx);
	}
	cout << 1ll * (n * (n + 1ll))/2 - Ans << endl;
	return 0;
}

