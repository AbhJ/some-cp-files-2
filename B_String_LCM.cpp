//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 14 in 21 : 33 : 35
//title - D_Program.cpp
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <numeric>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <climits>
#include <queue>
#include <cmath>
#include <stack>
#include <cctype>
#include <bitset>
// #include <bits/stdc++.h>
#define double long double
#define int long long int
#define ll int
#define ibs ios_base::sync_with_stdio(false)
#define cti cin.tie(0)
#define bp __builtin_popcount
#define pb emplace_back
#define koto_memory(a) cout<<(sizeof(a)/1048576.0)<<" MB";
#define res(v) sort(all(v)),v.erase(unique(all(v)), v.end());
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
#define deb(x) cout<<endl<<"["<<#x<<" = "<<x<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int l[N], r[N], a[N], b[N], rmi[N], rma[N], lmi[N], lma[N], n, m;string s;
void solve(){
	cin >> n >> m;
	cin >> s;
	s = '#' + s;
	rep(i, 1, n)l[i] = l[i - 1] + (s[i] == '-');
	rep(i, 1, n)r[i] = r[i - 1] + (s[i] == '+');
	lma[0] = rma[n + 1] = 0;
	rmi[n + 1] = lmi[0] = 0;
	l[n + 1] = r[n + 1] = 0;
	rep(i, 1, n)a[i] = r[i] - l[i];
	rep(i, 1, n)lma[i] = max(a[i], lma[i - 1]);
	rep(i, 1, n)lmi[i] = min(a[i], lmi[i - 1]);
	per(i, n, 1)l[i] = l[i + 1] + (s[i] == '-');
	per(i, n, 1)r[i] = r[i + 1] + (s[i] == '+');
	rep(i, 1, n)b[i] = r[i] - l[i];
	per(i, n, 1)rma[i] = max({rma[i + 1] + (s[i] == '+') - (s[i] == '-'), 0LL});
	per(i, n, 1)rmi[i] = min({rmi[i + 1] + (s[i] == '+') - (s[i] == '-'), 0LL});
	// rep(i, 1, n)cout << rma[i] << " ";
	rep(i, 1, m){
		int L, R;
		cin >> L >> R;
		int lef_ma = - inf, rig_ma = - inf, left_mi = inf, rig_mi = inf;
		lef_ma = lma[L - 1], left_mi = lmi[L - 1];
		rig_ma = rma[R + 1] + a[L - 1], rig_mi = a[L - 1] + rmi[R + 1];
		if(L == 1 and R == n)
			cout << 1;
		else
			cout << max(lef_ma, rig_ma) - min(left_mi, rig_mi) + 1;
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();}
  return 0;
}