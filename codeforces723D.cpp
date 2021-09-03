//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 05 in 08 : 16 : 19
//title - D_Lakes_in_Berland.cpp
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
const int N=5e1+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
// we don't have to increase number of connected components erase all
int parent[N * N],ind[N * N], no[N][N];
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = rand();
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        parent[b] = a;
    }
}
int n, m, k;char a[N][N];
void dfs(int x, int y){
	if(a[x][y] != '.' or no[x][y] == 1)return;
	no[x][y] = 1;
	rep(k, 0, 3){
		int X = x + dx[k], Y = y + dy[k];
		if(X >= 1 and X <= n and Y >= 1 and Y <= m)
			dfs(X, Y);
	}
}
int ok(int x, int y){
	return (x >= 1 and x <= n and y >= 1 and y <= m and no[x][y] == 0 and a[x][y] == '.');
}
map<int, pair<int, vpii>>ma;
void solve(){
	cin >> n >> m >> k;
	rep(i, 1, n)rep(j, 1, m)make_set(i * m + j);
	rep(i, 1, n)rep(j, 1, m)cin >> a[i][j];
	rep(i, 1, n)rep(j, 1, m)dfs(i, m), dfs(i, 1), dfs(n, j), dfs(1, j);
	rep(i, 1, n)rep(j, 1, m)rep(k, 0, 3)if(ok(i, j) and ok(i +dx[k], j + dy[k]))
	union_sets((i * m + j), ((i + dx[k]) * m + (j + dy[k])));
	rep(i, 1, n)rep(j, 1, m)if(ok(i, j))(ma[find_set(i * m + j)].S).pb(mp(i, j)), ma[find_set(i * m + j)].F++;
	int taka = 0;
	vector<pair<int, vpii>>M;
	for(auto &[x, y]: ma)M.pb(y);
	sort(all(M));
	while(M.size() > k){
		vpii v = (M.begin()) -> S;
		for(auto &[x, y]: v)a[x][y] = '*';
		taka += (M.begin()) -> F;
		M.erase(M.begin());
	}
	cout << taka;
	cout << "\n";
	rep(i, 1, n){
		rep(j, 1, m)cout << a[i][j];
		cout << "\n";
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}