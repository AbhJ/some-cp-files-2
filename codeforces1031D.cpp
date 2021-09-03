//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 10 in 17 : 18 : 38
//title - D_Minimum_path.cpp
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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, dp[N][N], k, la;char a[N][N];vpii s;string S;
void solve(){
	cin >> n >> k;
	rep(i, 1, n)
		rep(j, 1, n)
			cin >> a[i][j];
	//dp[i][j] min number of transformationto reach i, j with a only
	rep(i, 1, n)
		rep(j, 1, n)
			dp[i][j] = min(!(j != 1 and i == 1) ? dp[i - 1][j] : inf, !(i != 1 and j == 1) ? dp[i][j - 1] : inf) + (a[i][j] != 'a');
	rep(di, 1, 2 * n - 1){
		int cost = inf;
		vpii tmp;
		rep(i, 1, n){
			//di = i + j - 1
			int j = di - i + 1;
			if(j < 1 or j > n)
				continue;
			if(dp[i][j] <= k)
				tmp.pb(pii{i, j});
		}
		if(tmp.empty() == 0)
			s = tmp, la = di, S += 'a';
	}
	if(la != 0){
		S = string(la, 'a');
	}
	if(la == 0){
		if(k != 0)
			S = 'a';
		else
			S = a[1][1];
		la = 1;
		s.pb(pii{1, 1});
	}
	rep(di, la + 1, 2 * n - 1){
		vpii tm;char mi = 'z' + 1;
		for(auto [i, j]: s){
			char rig = 'z' + 1, dow = 'z' + 1;
			if(i + 1 != n + 1)
				dow = a[i + 1][j];
			if(j + 1 != n + 1)
				rig = a[i][j + 1];
			if(dp[i][j] >= k){
				mi = min({mi, dow, rig});
			}
		}
		S += (char)mi;
		for(auto [i, j]: s){
			char rig = 'z' + 1, dow = 'z' + 1;
			if(i + 1 != n + 1)
				dow = a[i + 1][j];
			if(j + 1 != n + 1)
				rig = a[i][j + 1];
			if(dp[i][j] >= k){
				if(dow == mi)
					tm.pb(pii{i + 1, j}),
					a[i + 1][j] = (char)'z' + 1;
				if(rig == mi)
					tm.pb(pii{i, j + 1}),
					a[i][j + 1] = (char)'z' + 1;
			}
		}
		s = tm;
	}
	cout << S;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}