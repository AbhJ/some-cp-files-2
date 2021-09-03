//Coded by Abhijay Mitra
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
const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[51][51];
int n, k;
int m;
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int f(int x){
  if(x == 0)return 1;
  return mul(x, f(x - 1));
}
int parent[51],ind[51];
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
void make_set(int v) {
    parent[v] = v;
    ind[v] = 1;
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (ind[a] < ind[b])
            swap(a, b);
        ind[a] += ind[b];
        ind[b] = 0;
        parent[b] = a;
    }
}
void solve(){
  cin >> n >> m;
  int ans = 1;
  rep(i, 1, n)
    rep(j, 1, n)
      cin >> a[i][j];
  int r = 0, c = 0;
  rep(i, 1, n)make_set(i);
  //row
  rep(i, 1, n){
    rep(j, 1, n)
      if(i != j){
        int F = 1;
        rep(y, 1, n)
          if(a[i][y] + a[j][y] > m)F = 0;
      if(F)union_sets(i, j);
    }
  }
  rep(i, 1, n)ans = mul(ans, f(ind[i]));
  fill(parent + 1, parent + 1 + 50, 0);
  fill(ind, ind + 50 + 1, 0);
  rep(i, 1, n)make_set(i);
  //col
  rep(i, 1, n){
    rep(j, 1, n)
      if(i != j){
        int F = 1;
        rep(y, 1, n)
          if(a[y][i] + a[y][j] > m)F = 0;
        if(F)union_sets(i, j);
      }
  }
  rep(i, 1, n)ans = mul(ans, f(ind[i]));
  cout << mul(mul(f(r), f(c)), ans);
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}