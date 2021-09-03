//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 03 in 05 : 57 : 57
//title - D_Dima_and_Bacteria.cpp
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
int n, m, k, x[N], y[N], z[N], id[N], A[N], pre[N];
vvi a;
int parent[N],ind[N];
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
int dp[501][501];
void solve(){
	cin >> n >> m >> k;
	rep(i, 1, k)cin >> A[i];
	a.resize(k + 1);
	rep(i, 1, k)pre[i] = A[i] + pre[i - 1];
	rep(i, 1, n)make_set(i);
	rep(i, 1, m){
		cin >> x[i] >> y[i] >> z[i];
		if(z[i] == 0)union_sets(x[i], y[i]);
	}
	set<int>s;
	int cnt = 0;
	rep(i, 1, k){
		s.clear();
		rep(j, cnt + 1, cnt + A[i])
			s.insert(find_set(j)),
			id[j] = i;
		cnt = cnt + A[i];
		if(s.size() != 1){
			cout << "No";
			return;
		}
	}
	rep(i, 1, k)rep(j, 1, k)if(i != j)dp[i][j] = inf;
	rep(i, 1, m){
		x[i] = id[x[i]];
		y[i] = id[y[i]];
		dp[x[i]][y[i]] = dp[y[i]][x[i]] = min(dp[x[i]][y[i]], z[i]);
	}
	for (int K = 1; K <= k; ++K) {
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= k; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][K] + dp[K][j]);
			}
		}
	}
	cout << "Yes\n";
	rep(i, 1, k){
		rep(j, 1, k){
			if(dp[i][j] == inf)cout << - 1;
			else cout << dp[i][j];
			cout << " ";
		}
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