//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 18 in 20 : 11 : 05
//title - B_Eastern_Exhibition.cpp
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
const int N=1e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, x[N], y[N], X, Y, taka = - 1, ans;map<int, set<pii>>m;
int d(int i, int j){
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}
void solve(){
	cin >> n;taka = 1;
	rep(i, 1, n){
		cin >> x[i] >> y[i];
	}
	sort(x + 1, x + 1 + n);
	sort(y + 1, y + 1 + n);
	X = x[n >> 1], Y = x[((n >> 1) + 1)];
	if(n & 1)taka = 1;
	else taka = Y - X + 1;
	X = y[n >> 1], Y = y[((n >> 1) + 1)];
	if(n & 1)taka = 1;
	else taka *= Y - X + 1;
	cout << taka;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}