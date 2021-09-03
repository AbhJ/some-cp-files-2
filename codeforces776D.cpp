//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 20 in 23 : 44 : 42
//title - D_The_Door_Problem.cpp
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
int n, m, x, ed_co[N], co[N], vis[N], A[N], F;vpii a[N];vi sw[N];
void dfs(int u){
	for(auto &[i, ty]: a[u]){
		if(vis[i] == 0){
			if(ty == 1)
				co[i] = co[u],
				vis[i] = 1,
				dfs(i);
			else
				co[i] = co[u] ^ 1,
				vis[i] = 1,
				dfs(i);
		}
		else{
			if(ty == 1 and co[i] != co[u])
				F = 1;
			else if(ty == 0 and co[i] != (co[u] ^ 1))
				F = 1;
		}
	}
}
void solve(){
	cin >> n >> m;
	rep(i, 1, n)
		cin >> ed_co[i];
	rep(i, 1, m){
		cin >> x;
		rep(j, 1, x){
			cin >> A[j];
			sw[A[j]].pb(i);
		}
	}
	rep(i, 1, n){
		a[sw[i][0]].pb(pii{sw[i][1], ed_co[i]}),
		a[sw[i][1]].pb(pii{sw[i][0], ed_co[i]});
	}
	//node is switch
	//edge is room
	rep(i, 1, m){
		if(vis[i] == 0){
			vis[i] = 1, dfs(i);
		}
	}
	cout << (F ? "NO" : "YES");
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}