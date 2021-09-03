//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 21 in 15 : 58 : 10
//title - Task.cpp
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
const int N=10e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N][N], b[N][N], r[N], c[N], taka;priority_queue<vi>q;
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
void solve(){
	cin >> n;q = priority_queue<vi>();taka = 0;
	rep(i, 1, n)
		rep(j, 1, n)
			cin >> a[i][j];
	rep(i, 1, n)
		rep(j, 1, n)
			cin >> b[i][j];
	rep(i, 1, n)
		make_set(i),
		make_set(i + n);
	rep(i, 1, n)
		cin >> r[i];
	rep(i, 1, n)
		cin >> c[i];
	rep(i, 1, n)
		rep(j, 1, n)
			if(a[i][j] == - 1)
				q.push({b[i][j], i, j}),
				taka += b[i][j];
	while(q.empty() == 0){
		vi v = q.top();
		q.pop();
		if(find_set(v[1]) != find_set(n + v[2]))
			taka -= v[0],
			union_sets(v[1], n + v[2]);
	}
	cout << taka;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){xx++;cout<<"Case #"<<xx<<": ";solve();cout<<"\n";}
  return 0;
}