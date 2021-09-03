//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 02 in 20 : 16 : 55
//title - B_Berland_Crossword.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int u, r, l, d, n, U, D, L, R;
void update(int i, int j){
	if(i == 1 and u == 0)
		return;
	if(i == n and d == 0)
		return;
	if(j == 1 and l == 0)
		return;
	if(j == n and r == 0)
		return;
	if(i == 1)
		u--;
	if(i == n)
		d--;
	if(j == 1)
		l--;
	if(j == n)
		r--;
}
void solve(){
	cin >> n >> u >> r >> d >> l;
	vpii v;
	v.pb(pii{1, n});
	v.pb(pii{1, 1});
	v.pb(pii{n, n});
	v.pb(pii{n, 1});
	rep(ma, 0, 15){
		U = u, D = d, R = r, L = l;
		rep(i, 0, 3)
			if((1LL << i) & ma)
				update(v[i].F, v[i].S);
		if(l <= n - 2 and r <= n - 2 and u <= n - 2 and d <= n - 2){
			cout << "YES";
			return;
		}
		u = U, d = D, l = L, r = R;
	}
	cout << "NO";
	return;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}