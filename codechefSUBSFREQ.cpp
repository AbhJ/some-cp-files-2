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
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
// void build(int a[], int v=1, int tl=1, int tr=n) {
//     if (tl == tr) {
//         t[v] = a[tl];
//     } else {
//         int tm = (tl + tr) / 2;
//         build(a, v*2, tl, tm);
//         build(a, v*2+1, tm+1, tr);
//         t[v] = t[v*2] + t[v*2+1];
//     }
// }
// //queries
// int sum(int l, int r,int v=1, int tl=1, int tr=n ) {
//     if (l > r) 
//         return 0;
//     if (l == tl && r == tr)
//         return t[v];
//     int tm = (tl + tr) / 2;
//     return sum( l, min(r, tm),v*2, tl, tm)
//            + sum(max(l, tm+1), r,v*2+1, tm+1, tr );
// }
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int n,a[N];
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
int f[N],b[N];
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  return (f[n]*mul(b[r],b[n-r])%M)%M;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
  map<int,int>m;
  cin>>n;vi ans(n+1,0);vector<map<int,int>>dp(n+1),f(n+1),b(n+1);
  rep(i,1,n)cin>>a[i],m[a[i]]++;
  sort(a+1,a+1+n);
  // for(auto i=m.begin();i!=m.end();i++){
  //   int cnt=0;
  //   for(int f=1;f<=i->S;f++){
  //     int ans=1;int ok=0;
  //     for(auto j=m.begin();j!=i;j++){
  //       int x=0;
  //       //smaller numbers must have strictly lower frequencies
  //       rep(c,0,f-1){
  //         x=add(x,C(j->S,c));
  //       }
  //       ans=mul(ans,x);
  //     }
  //     for(auto j=next(i);j!=m.end();j++){
  //       int x=0;
  //       //bigger numbers must have lower frequencies
  //       rep(c,0,f){
  //         x=add(x,C(j->S,c));
  //       }
  //       ans=mul(ans,x);
  //     }
  //     cnt=add(cnt,mul(C(i->S,f),ans));
  //   }
  //   ans[i->F]=cnt;
  // }
  for(auto i=m.begin();i!=m.end();i++){
    int ans=1;
    dp[i->F][0]=1;
    rep(c,1,i->S)dp[i->F][c]=add(dp[i->F][c-1],C(i->S,c));
    if(i==m.begin())
      rep(c,0,i->S)
        f[i->F][c]=dp[i->F][c];
    else{
      f[i->F]=f[prev(i)->F];
      auto z=(f[prev(i)->F].rbegin());
      rep(c,0,i->S)
        if(c>z->F){
          f[i->F][c]=mul(dp[i->F][c],z->S);
        }
        else f[i->F][c]=mul(dp[i->F][c],f[prev(i)->F][c]);
      auto x=dp[i->F].rbegin();
      rep(c,i->S+1,z->F)
        f[i->F][c]=mul(dp[i->F][c],x->S);
    }
  }
  for(auto i=m.rbegin();i!=m.rend();i++){
    if(i==m.rbegin())
      rep(c,0,i->S)
        b[i->F][c]=dp[i->F][c];
    else{
      b[i->F]=b[prev(i)->F];
      auto z=(b[prev(i)->F].rbegin());
      rep(c,0,i->S)
        if(c>z->F){
          b[i->F][c]=mul(dp[i->F][c],z->S);
        }
        else b[i->F][c]=mul(dp[i->F][c],b[prev(i)->F][c]);
      auto x=dp[i->F].rbegin();
      // rep(c,x->F+1,prev(i)->S)
      //   cout<<"F",b[i->F][c]=mul(b[prev(i)->F][c],x->S);
      for(auto tmp=b[i->F].begin();tmp!=b[i->F].end();tmp++){
        if(tmp->F>x->F)tmp->S=mul(tmp->S,x->S);
      }
    }
    if(i->F==4){
    cout<<i->F<<"\n";
      for(auto j:b[i->F])cout<<j.F<<" "<<j.S<<"\n";
    }
  }
  for(auto i=m.begin();i!=m.end();i++){
    int cnt=0;
    // if(i->F!=2)continue;
    for(int ff=1;ff<=i->S;ff++){
      int ans=1;int ok=0;
      if(i!=m.begin())ans=mul(ans,prev(f[prev(i)->F].upper_bound(ff-1))->S);
      if(next(i)!=m.end())ans=mul(ans,prev(b[next(i)->F].upper_bound(ff))->S);
      cnt=add(cnt,mul(C(i->S,ff),ans));
      // cout<<ff<<" "<<ans<<"\n";
    }
    ans[i->F]=cnt;
  }
  rep(i,1,n)cout<<ans[i]<<" ";
}
/*

1
5
3 3 4 5 5

*/

int32_t main()
{
  ibs;cti;
  calc_fact();
  // solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}