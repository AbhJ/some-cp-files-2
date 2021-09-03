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
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,d,a[N][5];
class E{
  public:
  int u;int v;int w;
};
bool operator<(const E &a,const E &b){
  return b.w<a.w;
}
int f(int x, int y){
  int ans=0;
  rep(i,0,d-1){
    ans+=abs(a[x][i]-a[y][i]);
  }
  return ans;
}
vector<E>edge;
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
int cost;
int F(){
  rep(i,1,n)make_set(i);
  sort(all(edge));int U,V;
  for(auto &e:edge){
    U=e.u,V=e.v;
    if(find_set(U)!=find_set(V))
      cost+=e.w,
      U=e.u,V=e.v,
      union_sets(U,V);
  }
  return cost;
}
set<int> best,worst;
int solve(){
  cin>>n>>d;
  rep(i,1,n)rep(j,0,d-1){
    cin>>a[i][j];
  }
  rep(mask,0,(1<<d)-1){
    vpii v;
    rep(i,1,n){
      int cost=0;
      rep(j,0,d-1){
        if((1<<j)&mask)cost+=a[i][j];
        else cost-=a[i][j];
      }
      v.pb(pii{cost,i});
    }
    sort(all(v));
    best.insert(v[v.size()-1].S);
    worst.insert(v[v.size()-1-(v.size()-1)].S);
  }
  rep(i,1,n)for(auto j:best)if(j!=i)edge.pb(E{i,j,f(i,j)});
  rep(i,1,n)for(auto j:worst)if(j!=i)edge.pb(E{i,j,f(i,j)});
  return F();
}
int32_t main()
{
  ibs;cti;
  // cout<<solve();return 0;
  int xx=0;
  int t=1;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;cout<<solve();cout<<endl;}
  return 0;
}