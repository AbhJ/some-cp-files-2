//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 26 in 00 : 00 : 38
//title - B_Partial_Replacement.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, k, cnt = 1;
string s;
// int dp[N][N];
// int f(deque<int>v, int firs, int last){
// 		if(dp[firs][last] != 0)
// 			return dp[firs][last];
// 		if(last - firs < k + 1 and v.empty() == 1)
// 			return 0;
// 		if(v.empty() == 1){
// 			return inf;
// 		}
// 		if(v.size() == 2 and v.back() - v.front() < k + 1)
// 			return 0;
// 		deque<int>v1 = v, v2 = v;
// 		v1.pop_front(), v2.pop_back();
// 		return dp[firs][last] = 1LL + min(f(v1, v.front(), last), f(v2, firs, v.back()));
// }
// deque<int>v;
// void solve(){
// 	cin >> n >> k >> s;v = deque<int>();
// 	memset(dp, 0, sizeof dp);
// 	rep(i, 0, s.length() - 2 + 1){
// 		if(s[i] == '*'){
// 			v.pb(i);
// 		}
// 	}
// 	if(v.size() <= 2)
// 		cout << v.size();
// 	else{
// 		int la = v.back(), fi = v.front();
// 		v.pop_back();
// 		v.pop_front();
// 		cout << 2 + f(v, fi, la);
// 	}
// }
void solve2(){
	cin >> n >> k >> s;vpii v;
	rep(i, 0, s.length() - 2 + 1){
		if(s[i] == '*'){
			v.pb(pii{i, 0});
		}
	}
	if(v.size() <= 2)
		cout << v.size();
	else{
		v[0].S = 1;
		rep(i, 0, (int)v.size() - 1){
			auto &[x, y] = *prev(lower_bound(all(v), pii{v[i].F + k + 1, 0}));
			if(v[i].S == 1){
				y = 1;
				if(x != v[i].F)
					cnt++;
			}
		}
		cout << cnt + (prev(v.end()) -> S != 1);
		cnt = 1;
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve2();cout<<"\n";}
  return 0;
}