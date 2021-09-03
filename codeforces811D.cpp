//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 21 in 17 : 49 : 38
//title - D_Vladik_and_Favorite_Game.cpp
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
#include <bits/stdc++.h>
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
using vi = std::vector<char>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=1e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, lswap, uswap, d[N][N];char a[N][N];
int x, y;int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
pii f(char c){
	cout << c;
	cout << "\n";
	cout.flush();
	int x;int y;
	cin >> x >> y;
	return pii{x, y};
}
void solve(){
	cin >> n >> m;
	rep(i, 1, n)
		rep(j, 1, m)
			cin >> a[i][j],
			d[i][j] = inf;
	d[1][1] = 0;
	queue<pii>q;
	q.push(pii{1, 1});
	while(q.empty() == 0){
		pii now = q.front();
		q.pop();
		rep(k, 0, 3){
			int X = now.F + dx[k], Y = now.S + dy[k];
			if(X < 1 or X > n or Y < 1 or Y > m)
				continue;
			if(d[X][Y] != inf)
				continue;
			if(a[X][Y] == '*')
				continue;
			d[X][Y] = d[now.F][now.S] + 1;
			q.push(pii{X, Y});
		}
		if(a[now.F][now.S] == 'F')
			x = now.F, y = now.S;
	}
	string v;
	while(pii{x, y} != pii{1, 1}){
		rep(k, 0, 3){
			int X = x + dx[k], Y = y + dy[k];
			if(X < 1 or X > n or Y < 1 or Y > m)
				continue;
			if(d[X][Y] == inf)
				continue;
			if(a[X][Y] == '*')
				continue;
			if(d[X][Y] == d[x][y] - 1){
				if(X == x - 1){
					v += "D";
				}
				else if(X == x + 1){
					v += "U";
				}
				if(Y == y - 1){
					v += "R";
				}
				else if(Y == y + 1){
					v += "L";
				}
				x = X, y = Y;
				break;
			}
		}
	}
	assert((pii{x, y} == pii{1, 1}));
	reverse(all(v));
	for(auto i = v.begin(); i != v.end(); i = next(i)){
		if(lswap == 1 and ((*i) == 'L' or (*i) == 'R'))
			(*i) = 'R' + 'L' - (*i);
		if(uswap == 1 and ((*i) == 'U' or (*i) == 'D'))
			(*i) = 'D' + 'U' - (*i);
		pii tmp = f((*i));
		int X = tmp.F, Y = tmp.S;
		if(pii{x, y} == pii{X, Y}){
			if((*i) == 'L' or (*i) == 'R'){
				assert(y == 1);
				lswap = 1;

			}
			if((*i) == 'U' or (*i) == 'D'){
				assert(x == 1);
				uswap = 1;
			}
			i = prev(i);
		}
		x = X, y = Y;
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