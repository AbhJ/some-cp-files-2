//Coded by Abhijay Mitra (AbJ) on 2021 / 05 / 01 in 17 : 41 : 48
//title - C_MAD_TEAM.cpp
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
#include <bits/stdc++.h>
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int N=3e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int cnt, n, z, a[N][6];
int f(int val){
	//er theke better or equal try korbo
	vvi dp (n + 1, vi((1LL << 5), inf));
	dp[0][0] = 0;
	rep(i, 1, n){
		int ma = 0;
		rep(j, 1, 5)
			if(a[i][j] >= val)
				ma |= (1LL << (j - 1));
		assert(ma < (1LL << 5));
		dp[i] = dp[i - 1];
		rep(j, 0, (1LL << 5) - 1)
			dp[i][j | ma] = min(dp[i][j | ma], dp[i - 1][j] + 1);
	}
	return (dp[n][(1LL << 5) - 1] <= 3);
}
void solve(){
	cin >> n;
	rep(i, 1, n)
		rep(j, 1, 5)
			cin >> a[i][j];
	int l = 0, r = 1e9, m;
	while(r > l){
		m = ((l + r + 1LL) >> 1LL);
		if(f(m))
			l = m;
		else
			r = m - 1;
	}
	cout << l;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}