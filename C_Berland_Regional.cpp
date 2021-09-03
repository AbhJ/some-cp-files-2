//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 29 in 22 : 34 : 34
//title - C_Berland_Regional.cpp
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.rbegin(), x.rend()
using namespace std;
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int k, n, u[N], s[N], an[N], ans, fin[N], koita[N], cn, cnz[N];vi v[N];
void f(int ann, int z){
	an[z] += ann;
	rep(j, 1, sqrt(z))
		if(z % j == 0){
			an[j] = ann;
			if(j * j != z)
				an[z / j] = ann;
		}
}
void solve(){
	cin >> n;
	rep(i, 1, n)
		v[i].clear();
	rep(i, 1, n)
		cin >> u[i];
	rep(i, 1, n)
		cin >> s[i],
		v[u[i]].pb(s[i]),
		koita[u[i]] = (int)v[u[i]].size();
	rep(i, 1, n)if(koita[i] != 0){
		sort(all(v[i]));
		cn = (int)v[i].size();
		rep(j, 1, cn - 1)
			v[i][j] += v[i][j - 1];
		rep(j, 1, cn)
			cnz[j] += v[i][((cn / j) * j) - 1];
	}
	int z = - inf;
	rep(i, 1, n)if(koita[i] != 0)
		z = max(z, koita[i]);
	rep(i, 1, n)
		if(i > z)
			cout << 0 << " ";
		else
			cout << cnz[i] << " ";
	ans = 0;
	cn = 0;
	memset(an, 0, sizeof an);
	memset(cnz, 0, sizeof cnz);
	memset(koita, 0, sizeof koita);
	memset(fin, 0, sizeof fin);
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}