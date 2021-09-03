//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 03 in 18 : 36 : 11
//title - D_Kilani_and_the_Game.cpp
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
// #define int long long int
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
// const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int num, p, s, n, m, S[N], dp[N][N], cn[N];queue<pii>q[N];string a[N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int dis(pii x, pii y){
	return (abs(x.F - y.F) + abs(x.S - y.S));
}
void solve(){
	cin >> n >> m >> p;
	rep(i, 0, p - 1)cin >> S[i];
	rep(i, 1, n){
		cin >> a[i];
		a[i] = '#' + a[i];
		rep(j, 1, m){
			if(a[i][j] == '#')dp[i][j] = 1;
			if((a[i][j] != '.') and (a[i][j] != '#'))
				dp[i][j] = 1, q[a[i][j] - '1'].push(mp(i, j)), cn[a[i][j] - '1']++;
		}
	}
	while(1){
		int cnt_tot = 0, cnt = 0;
		rep(i, 0, p - 1){
			cnt = 0;
			pii P;
			if(q[i].empty() == 0)P = q[i].front();
			rep(j, 1, S[i]){
				queue<pii>Q;
				if(q[i].empty())break;
				while(q[i].empty() == 0){
					cnt_tot++;
					int x = q[i].front().F, y = q[i].front().S;
					q[i].pop();
					int F = 0, tmp = 0;
					rep(k, 0, 3){
						int X = x + dx[k], Y = y + dy[k];
						if(X >= 1 and X <= n and Y >= 1 and Y <= m and (dp[X][Y] != 1)){
							Q.push(mp(X, Y));
							dp[X][Y] = 1;
							cn[i]++;
						}
					}
				}
				q[i] = Q;
			}
		}
		if(cnt_tot == 0)break;
	}
	rep(i, 0, p - 1)cout << cn[i] << " ";
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}