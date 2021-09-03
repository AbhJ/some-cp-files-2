//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 05 in 20 : 20 : 34
//title - C_Fence_Painting.cpp
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
int a[N], b[N], n, c[N], m, ans[N], vis[N], F;vi col[N], painter_having_color[N], must[N];
void solve(){
	cin >> n >> m;
	F = 0;
	rep(i, 1, n)cin >> a[i];
	rep(i, 1, n)cin >> b[i];
	rep(i, 1, m)cin >> c[i];
	rep(i, 1, n)col[i].clear();
	rep(i, 1, n)must[i].clear();
	rep(i, 1, n)painter_having_color[i].clear();
	fill(ans + 1, ans + 1 + m, 0);
	fill(vis + 1, vis + 1 + n, 0);
	rep(i, 1, n){
		col[b[i]].pb(i);
		if(a[i] != b[i])
			must[b[i]].pb(i);
	}
	rep(i, 1, m)painter_having_color[c[i]].pb(i);
	int x = - 1;
	per(i, m, 1){
		if(must[c[i]].empty() == 0){
			//someone has to get
			//c[i] is colour he wants
			//must[c[i]] is the index of the person wanting
			ans[i] = must[c[i]].back();
			must[c[i]].pop_back();
		}
		else if(col[c[i]].empty() == 0){
			//here a[j] = b[j]
			ans[i] = col[c[i]].back();
		}
		else
			ans[i] = ans[m];
	}
	rep(i, 1, m)if(ans[i] == 0){
		cout << "NO";
		return;
	}
	per(i, n, 1)if(must[i].empty() != 1){
		cout << "NO";
		return;
	}
	cout << "YES\n";
	rep(i, 1, m)
		cout << ans[i] << " ";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}