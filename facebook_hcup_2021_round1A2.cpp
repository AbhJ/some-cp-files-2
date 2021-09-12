

/**
 * @author      : abhj
 * @created     : Sunday Sep 12, 2021 15:40:05 IST
 * @filename    : b.cpp
 */

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
const int N    =     2e6 + 10;
const int M    =     1e9 + 7;

int n;
string s;

void solve() {
	cin >> n >> s;
	function <vi (string)> f = [&] (string s) -> vi {
		reverse (s.begin(), s.end());
		vi c1 (n), c2 (n);
		int ty1 = 1, ty2 = 0, ans1 = 0, ans2 = 0;
		for (int i = 0; i < n; i++) {
			if (ty1 == 0 and s[i] == 'O') {
				ty1 = 1;
				ans1++;
			}
			else if (ty1 == 1 and s[i] == 'X') {
				ty1 = 0;
				ans1++;
			}
			if (ty2 == 0 and s[i] == 'O') {
				ty2 = 1;
				ans2++;
			}
			else if (ty2 == 1 and s[i] == 'X') {
				ty2 = 0;
				ans2++;
			}
			c1[i] = ans1;
			c2[i] = ans2;
		}
		if (c1 > c2)
			swap (c1, c2);
		reverse (c1.begin(), c1.end());
		return c1;
	};
	vi v, p, dp (n + 1), c = f (s);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (
			(s[i] == 'O' and (v.empty() == 1 or s[v.back()] == 'X'))
			or
			(s[i] == 'X' and (v.empty() == 1 or s[v.back()] == 'O'))
		)
			v.pb (i);
		if (s[i] == 'O' or s[i] == 'X')
			p.pb (i);
	}
	v.erase (v.begin());
	v.pb (n);
	vi nextWeirdPos (n);
	for (int i = n - 1; i > - 1; i--) {
		dp[i] = dp[i + 1] + c[i];
		if (s[i] != 'F')
			nextWeirdPos[i] = i;
		else
			nextWeirdPos[i] = (i == n - 1 ? n : nextWeirdPos[i + 1]);
	}
	for (int i = 0; i < n; i++) {
		int nextProb = *lower_bound (v.begin(), v.end(), i);
		if (nextWeirdPos[i] == nextProb) {
			// cout << nextProb << " ";
			// cout << dp[i] - (n - i) << " ";
			if (nextProb != n)
				ans += dp[i] - (*next (v.rbegin()) - i);
			else
				ans += dp[i];
		}
		else
			ans += dp[i];
		ans %= M;
		// cout << ans << " ";
		// cout << dp[i] << " ";
	}
	cout << ans;
}
int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t, x = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++x << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
