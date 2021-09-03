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
const int N=1e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,A[N],x,y,en[N],ex[N],cnt[N],c[N],inv[N],T,q,t[4*N];
vvpii freq;
vvi a;
vi euler,vec;int tree_builder[N],height[N];
void dfs1(int u,int p=-1,int h=0){
  vec[T]=u;
  euler.pb(u);
	en[u]=T++;
  height[u]=h;
	for(auto i:a[u]){
    if(i!=p)dfs1(i,u,h+1);
    if(i!=p)euler.pb(u);
	}
  vec[T]=u;
	ex[u]=T++;
}
void build(int v=1, int tl=0, int tr=euler.size()-1) {
    if (tl == tr) {
        t[v] = euler[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v]=(height[t[v*2]]<height[t[v*2+1]]?t[v*2]:t[v*2+1]);
    }
}
//queries
int sum(int l, int r,int v=1, int tl=0, int tr=euler.size()-1) {
    if (l > r) 
        return inf;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int s1= sum( l, min(r, tm),v*2, tl, tm);
    int s2= sum(max(l, tm+1), r,v*2+1, tm+1, tr );
    if(s1==inf)return s2;
    if(s2==inf)return s1;
    return (height[s1]<height[s2])?s1:s2;
}
int lca(int a,int b){
  a=en[a],b=en[b];
  if(b<a)swap(a,b);
  return sum(a,b);
}
int block=450;
class Q{
  public:
  int l,r,id,type;int LCA;
  pair<int, int> toPair() const {
		return make_pair(l / block, r*(((l/block) & 1)?-1:1));
	}
};
bool operator<(const Q &a,const Q &b){
  return a.toPair()<b.toPair();
}
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
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
int answer=1;
void ad(int i){
  int val=vec[i];
  if(cnt[val]==0){
    for(auto j:freq[A[val]])
      c[j.F]+=j.S,
      answer=mul(answer,mul(c[j.F]+1,inv[c[j.F]-j.S+1]));
  }
  if(cnt[val]==1){
    for(auto j:freq[A[val]])
      c[j.F]-=j.S,
      answer=mul(answer,mul(c[j.F]+1,inv[c[j.F]+j.S+1]));
  }
  cnt[val]++;
  cnt[val]%=2;
}
void re(int i){
  int val=vec[i];
  if(cnt[val]==0){
    for(auto j:freq[A[val]])
      c[j.F]+=j.S,
      answer=mul(answer,mul(c[j.F]+1,inv[c[j.F]-j.S+1]));
  }
  if(cnt[val]==1){
    for(auto j:freq[A[val]])
      c[j.F]-=j.S,
      answer=mul(answer,mul(c[j.F]+1,inv[c[j.F]+j.S+1]));
  }
  cnt[val]++;
  cnt[val]%=2;
}
int f(int val){
  int temp=answer;
    for(auto j:freq[A[val]])
      temp=mul(temp,mul(c[j.F]+j.S+1,inv[c[j.F]+1]));
    return temp;
}
void solve(){
  answer=1;fill(cnt,cnt+N,0);
  fill(en,en+N,0);
  fill(ex,ex+N,0);
  fill(height,height+N,0);
  fill(t,t+4*N,0);
  fill(A,A+N,0);
  fill(c,c+N,0);
  cin>>n;a.clear();a.resize(n+1);
  rep(i,1,n-1){
    cin>>x>>y;
    a[x].pb(y);
    a[y].pb(x);
  }
  T=0;
  rep(i,1,n)cin>>A[i];vec.clear();euler.clear();
  vec.resize(2*n+100);
  dfs1(1);
  build();
  cin>>q;
  vector<int>ans(q,1);
  vector<Q>qu(q);
  vpii input;
  rep(i,1,q){
    cin>>x>>y;
    input.pb(x,y);
  }
  rep(i,1,q){
    int L,R;
    x=input[i-1].F,y=input[i-1].S;int type=0;
    if(en[x]>en[y])swap(y,x);
    if(lca(x,y)==x){
      L=en[x],R=en[y];
    }
    else{
      L=ex[x],R=en[y];
      type=1;
    }
    qu[i-1]=Q{L,R,i-1,type,lca(x,y)};
  }
  sort(all(qu));
  int cur_l=0,cur_r=-1;
  rep(i,0,q-1){
    int L=qu[i].l;int R=qu[i].r;
    while (cur_l > L) {
        cur_l--;
        ad(cur_l);
    }
    while (cur_r < R) {
        cur_r++;
        ad(cur_r);
    }
    while (cur_l < L) {
        re(cur_l);
        cur_l++;
    }
    while (cur_r > R) {
        re(cur_r);
        cur_r--;
    }
    ans[qu[i].id]=mul(ans[qu[i].id],answer);
    if(qu[i].type==1)ans[qu[i].id]=f(qu[i].LCA);
  }
  for(auto &i:ans)cout<<i<<"\n";
}
int32_t main()
{
  ibs;cti;
  freq.resize(N);
  freq[1]={{1,0}};
  inv[1]=inv[0]=1;
  rep(i,2,N-1){
    inv[i] = (M - (((M/i) * 1LL *inv[M % i])  % M)) % M;
    if(freq[i].empty()==1){
      freq[i].emplace_back(i,1);
      for(int j=i<<1;j<N;j+=i){
        int cnt= 0;int ori=j;
        while((ori%i)==0)ori/=i,cnt++;
        freq[j].emplace_back(i,cnt);
      }
    }
  }
  // solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){T=0;/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}