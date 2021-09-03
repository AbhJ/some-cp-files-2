//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 12 in 2021-01-13 13:02:39
//title - Chef_and_Ants.cpp
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
#define tiACmer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec "<<endl;
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
int n, m;
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
map<int, int>ma, f;
void solve(){
	ma.clear();
	f.clear();
	cin >> n;
	int ans = 0;
	vpii a[n + 1];
	rep(i, 1, n){
		cin >> m;
		rep(j, 1, m){
			int c;
			cin >> c;
			ma[abs(c)]++;
			a[i].pb(pii {abs(c), sgn(c)});
		}
		sort(all(a[i]));
	}
	rep(j, 1, n){
		f.clear();
		for(auto &[x, y]: a[j])f[y]++;
		for(auto &i: a[j]){
			f[i.S]--;
			if(ma[i.F] > 1)
				if(i.S == - 1)
					ans += f[- 1];
				else
					ans += f[1];
			else
				if(i.S == - 1)
					ans += f[1];
				else
					ans += f[- 1];
		}
	}
	for(auto &[x, y]: ma) ans += (y > 1);
	ma.clear();
	cout << ans;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}