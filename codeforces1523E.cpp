#include "bits/stdc++.h"
#define int          long long int
#define mp           make_pair
#define pb           emplace_back
#define F            first
#define S            second
using vi       =     std::vector<int>;
using vvi      =     std::vector<vi>;
using pii      =     std::pair<int, int>;
using vpii     =     std::vector<pii>;
using vvpii    =     std::vector<vpii>;
using namespace std;
const int inf  =     1e18 + 10;
const int N    =     1e5 + 10;
const int M    =     1e9 + 7;
int add(int a, int b) {
	a += b;
	return (a >= M ? a - M : a);
}
int mul(int a, int b) {
	return (a * b) % M;
}
int sub(int a, int b) {
	return (a - b + M) % M;
}
int powM(int b, int p) {
	int r = 1;
	for (; p; b = mul(b, b), p >>= 1)
		if (p & 1)
			r = mul(r, b);
	return r;
}
int invM(int x) {
	return powM(x, M - 2);
}
int f[N], b[N];
void binomialCoeff() {
	f[0] = 1;
	for (int i = 1; i <= N - 1; i++)
		f[i] = mul(f[i - 1], i);
	b[N - 1] = powM(f[N - 1], M - 2);
	for (int i = N - 2; i >= 0; i--)
		b[i] = mul(b[i + 1], i + 1);
}
int C(int n, int r) {
	// if (n <= 0 or r <= 0)
	// 	return 0;
	return (r > n ? 0LL : (f[n] * mul(b[r], b[n - r]) % M) % M);
}
int n, k, taka;
void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		taka = add(taka, mul(C(n - (k - 1) * (i - 1), i), invM(C(n, i))));
	}
	cout << add(taka, 1);
	// add 1 because 1st step has probability 1 of occurrence
	taka = 0;
}
int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	binomialCoeff();
	int t; cin >> t;
	while (t--) {
		solve(); cout << "\n";
	}
	return 0;
}