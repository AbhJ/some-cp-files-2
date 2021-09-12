

/**
 * @author      : abhj
 * @created     : Sunday Sep 12, 2021 14:32:51 IST
 * @filename    : c.cpp
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
const int N    =     5e1 + 10;

int n, m, a, b;

void solve() {
	cin >> n >> m >> a >> b;
	int compDif = abs (b - a);
	if (compDif > (n + m - 1) * 999) {
		cout << "Impossible\n";
		return;
	}
	if (min (a, b) < (n + m - 1)) {
		cout << "Impossible\n";
		return;
	}
	cout << "Possible\n";
	vvi A (n, vi (m, 1));
	A[0][m - 1] = b - (n + m - 1) + 1;
	A[0][0] = a - (n + m - 1) + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	int t, x = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++x << ": ";
		solve();
	}
	return 0;
}
