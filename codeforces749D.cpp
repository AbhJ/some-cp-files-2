//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 11 in 09 : 01 : 15
//title - D_Leaving_Auction.cpp
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], b[N], hi[N], q, k, l[N], cnt, vis[N];
vi v[N];
set<pii>s;
void solve(){
	cin >> n;
	rep(i, 1, n){
		cin >> a[i] >> b[i];
		v[a[i]].pb(b[i]);
	}
	rep(i, 1, n)if(v[i].empty() == 0){
		hi[i] = v[i].back();
	}
	rep(i, 1, n)if(hi[i] != 0){
		s.insert({hi[i], i});
	}
	cin >> q;
	while(q--){
		cin >> k;
		rep(i, 1, k){
			cin >> l[i];
			if(hi[l[i]] != 0)
				s.erase({hi[l[i]], l[i]});
		}
		if(s.empty() == 1){
			cout << 0 << " " << 0;
		}
		if((int)s.size() == 1){
			cout << s.rbegin() -> S << " " << *v[s.rbegin() -> S].begin();
		}
		if((int)s.size() >= 2){
			int las = s.rbegin() -> S;
			int sec = next(s.rbegin()) -> S;
			cout << las << " " << *lower_bound(all(v[las]), hi[sec]);
		}
		cout << "\n";
		rep(i, 1, k)
			if(hi[l[i]] != 0)
				s.insert({hi[l[i]], l[i]});
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}