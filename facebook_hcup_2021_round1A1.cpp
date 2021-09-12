

/**
 * @author      : abhj
 * @created     : Saturday Sep 11, 2021 22:34:22 IST
 * @filename    : a.cpp
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

int n;
string s;

void solve() {
	cin >> n >> s;
	function <int (int)> f = [&] (int ty) -> int {
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (ty == 0 and s[i] == 'O') {
				ty = 1;
				ans++;
			}
			else if (ty == 1 and s[i] == 'X') {
				ty = 0;
				ans++;
			}
		}
		return ans;
	};
	cout << min (f (0), f (1));
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
