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
int ans[N];int n,m,u,v,w;
vvi a,b;
vi vis;vvi adj;
void dfs(int s){
  vis[s]=1;
  for(auto i:adj[s])if(vis[i]==0)
    vis[i]=1,dfs(i);
}
void f(int i,vi cur){
  map<int,int>F;
  if(i==m){
    if(cur.size()!=n-1)return;
    set<int>s;int cost=0;
    for(auto j:cur){
      s.insert(a[j][0]);
      s.insert(a[j][1]);
      F[a[j][0]]++;
      F[a[j][1]]++;
      cost+=a[j][2];
    }
    if(s.size()!=n)return;
    vis=vi(n+1,0);
    adj=vvi(n+1);
    for(auto j:cur)
       adj[a[j][0]].pb(a[j][1]),
       adj[a[j][1]].pb(a[j][0]);
    dfs(1);
    rep(j,1,n)if(vis[j]==0)return;
    //check graph connected
    ans[F[1]]=min(ans[F[1]],cost);
    return;
  }
  else{
    cur.pb(i);
    f(i+1,cur);
    cur.pop_back();
    f(i+1,cur);
  }
}
void solve(){
  cin>>n;
   cin>>m;
  a.resize(m);
  rep(i,1,m){
    cin>>u>>v>>w;
    a[i-1]={u,v,w};
  }
  //choose n-1 of m
  vi cur;
  f(0,cur);
  rep(i,1,n-1)cout<<ans[i]<<" ";
}
int32_t main()
{
  ibs;cti;
  fill(ans,ans+N,inf);
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}