//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 23 in 22 : 12 : 28
//title - C_Fillomino_2.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=5e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], b[N][N], c[N];
int dx[4]={0,1,1,0},dy[4]={-1,0,0,1};
void f(){
}
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> a[i],
		c[a[i]] = i;
	rep(i, 1, n){
		int z = a[i] - 1;
		int x = i;
		int y = i,
		zz = 0;
		int X, Y;
		queue<pii>q;
		q.emplace(x, y);
		b[x][y] = a[i];
		while(z != 0 and zz++ < (2e6 / n) and q.empty() == 0){
			x = (q.front()).F;
			y = (q.front()).S;
			q.pop();
			rep(k, 0, 3){
				X = x + dx[k], Y = y + dy[k];
				if(X >= 1 and X <= n and Y >= 1 and Y <= n and X > Y and b[X][Y] == 0 and z != 0){
					b[X][Y] = a[i];
					q.emplace(X, Y);
					z--;
					break;
					// x = X, y = Y;
				}
			}
		}
	}
	rep(i, 1, n)
		rep(j, 1, i){
			if(b[i][j] == 0){
				cout << - 1;
				return;
			}
		}
	rep(i, 1, n){
		rep(j, 1, i)
			cout << b[i][j] << " ";
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}