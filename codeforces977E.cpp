//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 01 in 12 : 06 : 10
//title - E_Cyclic_Components.cpp
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
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int vis[N], n, m, x, y, com, k, ok[N]; vi a[N];int koita;
int parent[N],ind[N];
set<int>S, tot;
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
void dfs(int u, set<int> &tmp, int p = - 1){
	if((int)a[u].size() == 2)tmp.insert(u);
	tot.insert(u);
	for(int &i: a[u]){
		if(vis[i] == 0)vis[i] = 1, dfs(i, tmp, u);
		else if(vis[i] == 1 and i != p)k++, S = tmp;
	}
	vis[u] = 2;
}
int F;
void dfs2(int u){
	if(F == 0)return;
	if((int)a[u].size() != 2){k = 0; F = 0; ok[find_set(u)] = 1;return;}
	for(int &i: a[u]){
		if(vis[i] == 0)vis[i] = 1, dfs2(i);
	}
}
void solve(){
	cin >> n;cin >> m;rep(i, 1, n)make_set(i);
	rep(i, 1, m)cin >> x >> y,
	a[x].pb(y), a[y].pb(x), union_sets(x, y);
	rep(i, 1, n){
		F = 1;
		if(vis[i] == 0 and ok[find_set(i)] == 0){
			k = 1;
			vis[i] = 1;
			dfs2(i);
			koita += k;
		}
		continue;
		k = 0;tot.clear();
		set<int>F;
		if(vis[i] != 2)vis[i] = 1, dfs(i, F), vis[i] = 2;
		if(k == 1 and tot == S)koita++;
	}
	cout << (int)koita;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}