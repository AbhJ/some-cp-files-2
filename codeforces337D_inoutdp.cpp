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
#define timer cerr << "Time elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC << " sec \n";
#define deb(x) cout<<"\n["<<#x<<" = "<<x<<"]\n";
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
int n,m,d,p[N],marked[N],in[N],out[N],x,cnt,y;vi a[N];
void dfs1(int u,int p=-1){
  if(marked[u]!=1)in[u]=-inf;
  for(auto i:a[u])if(i!=p){
    dfs1(i,u);
    in[u]=max(in[u],1+in[i]);
  }
}
void dfs2(int u,int p=-1){
  int ma1=-inf,ma2=-inf;if(marked[u] and out[u]<0)out[u]=0;
  for(auto i:a[u])if(i!=p){
    if(ma1<=in[i])ma2=ma1,ma1=in[i];
    else if(ma2<in[i])ma2=in[i];
  }
  for(auto i:a[u])if(i!=p){
    int cur_ma=ma1;
    if(in[i]==ma1)cur_ma=ma2;
    out[i]=max(2+cur_ma,1+out[u]);
    dfs2(i,u);
  }
}
void solve(){
  cin>>n>>m>>d;
  rep(i,1,m){
    cin>>p[i];
    marked[p[i]]=1;
  }
  rep(i,1,n-1){
    cin>>x>>y;
    a[x].pb(y);
    a[y].pb(x);
  }
  dfs1(1);
  if(marked[1]==0)out[1]=-inf;
  dfs2(1);
  rep(i,1,n)if(in[i]<=d and out[i]<=d)cnt++;
  cout<<cnt;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}