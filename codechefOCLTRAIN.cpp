//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 27 in 00 : 16 : 22
//title - Jedi_Test.cpp
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
const double Pi = M_PI;
#define F first
#define S second
vi t[4 * N];int lazy[4 * N];
void f(int v,int tl,int tr){
  rotate(t[v].begin(), t[v].begin() + 3 - (lazy[v] % 3), t[v].end());
  if(tl!=tr){
    lazy[v*2]+=lazy[v];
    lazy[v*2+1]+=lazy[v];
  }
  lazy[v]=0;
}
//queries
int n, a[N], q, ty, x, l, r;
int sum(int l, int r, int v=1, int tl=1, int tr = n) {
    f(v,tl,tr);
    if (l>tr or r<tl)
        return 0;
    if (l <= tl and r >= tr)
        return t[v][(x + lazy[v]) % 3];
    int tm = (tl + tr) / 2;
    return sum( l, r,v*2, tl, tm)
           + sum(l, r,v*2+1, tm+1, tr );
}
//
void update(int l, int r, int v=1, int tl = 1, int tr = n) {
   f(v,tl,tr);
   if(l>tr or r<tl)return;
   if(l<=tl and r>=tr){
	lazy[v]++;
    f(v,tl,tr);
    return;
   }
   int tm=tl+tr>>1;
   update(l,r,v*2,tl,tm);
   update(l,r,v*2+1,tm+1,tr);
   rep(i, 0, 2)
   		t[v][i]=t[v*2][i]+t[v*2+1][i];
}
void build(int a[], int v=1, int tl=1, int tr=n) {
    if (tl == tr) {
        t[v][a[tl] % 3] = 1;
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        rep(i, 0, 2)
			t[v][i] = t[v*2][i] + t[v*2+1][i];
    }
}
void solve(){
	cin >> n;
	rep(i, 0, 4 * n)
		t[i] = vi(3),
		lazy[i] = 0;
	rep(i, 1, n)
		cin >> a[i];
	build(a);
	cin >> q;
	rep(i, 1, q){
		cin >> ty >> l >> r;
		if(ty != 1)
			cin >> x;
		if(ty == 1)
			update(l, r);
		else
			cout << sum(l, r) << "\n";
	}
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}