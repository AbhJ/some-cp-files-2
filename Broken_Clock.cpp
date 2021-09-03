#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#ifdef DEBUG
#define int_hello long long
#else
#define int_hello __int128
#endif // DEBUG
const int_hello bck11 = 15709090909091;
const int_hello mod = 12*60*60* (int_hello)1e9;
int let_us_check(int xx, int_hello a, int_hello b, int_hello c) {
    int_hello konta = (((b-a) * bck11) % mod + mod) % mod;
    if ((708 * konta - c + b) % mod == 0) {
        ll n = konta % (ll)1e9;konta /= 1e9;ll s = konta % 60;
        konta /= 60;ll koita = konta % 60;ll h = konta / 60;
        cout << "Case #" << xx << ": " << h << " " << koita << " " << s << " " << n << "\n";
        return true;
    }
    else return false;
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	 cout.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int koita_test;cin >> koita_test;
    for (int xx = 1; xx <= koita_test; xx++) {
        ll ta, tb, tc;
        cin >> ta >> tb >> tc;
        int_hello a = ta, b = tb, c = tc;
        if (let_us_check(xx, a, b, c) || let_us_check(xx, a, c, b) || let_us_check(xx, b, a, c) || let_us_check(xx, b, c, a) || let_us_check(xx, c, a, b) || let_us_check(xx, c, b, a));
        else
            cerr << "Problem" << "\n";
    }
    return 0;
}