/**
 * @author      : abhj
 * @created     : Thursday Sep 02, 2021 16:21:53 IST
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

int x, y;

void solve() {
	string s;
	cin >> s;
	x = stoi (s), y = s.back() - '0';
	cout << x;
	if (y < 3)
		cout << "-";
	else if (y < 7)
		;
	else
		cout << "+";
}

int32_t main() {
	ios_base::sync_with_stdio (false);
	cin.tie (0);
	solve();
	return 0;
}
