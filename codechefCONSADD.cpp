//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 15 in 09 : 34 : 14
//title - Consecutive_Adding.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, m, x, a[N][N], b[N][N], p[N][N];
void hor(int i){
	rep(j, 1, m)
		a[i][j] = '1' + '0' - a[i][j];
}
void ver(int j){
	rep(i, 1, n)
		a[i][j] = '1' + '0' - a[i][j];
}
int ch(){
	rep(i, 1, n){
		rep(j, 1, m)
			cout << a[i][j];
		cout << "\n";
	}
	rep(i, 1, n){
		rep(j, 1, m)
			cout << b[i][j];
		cout << "\n";
	}
	rep(i, 1, n)
		rep(j, 1, m)
			if(a[i][j] != b[i][j])
				return 0;
	return 1;
}
void solve(){
	cin >> n >> m >> x;
	rep(i, 1, n)
		rep(j, 1, m)
			cin >> a[i][j];
	rep(i, 1, n)
		rep(j, 1, m)
			cin >> b[i][j];
	rep(i, 1, n)
		rep(j, 1, m)
			p[i % x][j % x] += a[i][j] - b[i][j];
	rep(i, 0, x - 1)
		rep(j, 0, x - 1)
			if(p[i][j] + p[0][0] != p[i][0] + p[0][j]){
				cout << "No";
				rep(i, 0, x - 1)
					rep(j, 0, x - 1)
						p[i][j] = 0;
				return;
			}
	cout << "Yes";
	rep(i, 0, x - 1)
		rep(j, 0, x - 1)
			p[i][j] = 0;
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