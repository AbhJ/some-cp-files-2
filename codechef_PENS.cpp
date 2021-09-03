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
const int N=1e7+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,k;string s,S[N];vi get_pen_from_sub_mask;
void f(int mask,int par){
  if(get_pen_from_sub_mask[mask]!=0)return;
  get_pen_from_sub_mask[mask]=par;
  rep(i,0,19){
    if((1LL<<i)&mask){
      f(mask^(1LL<<i),par);
    }
  }
}
void solve(){
  cin>>n>>k>>s;
  rep(i,1,k)cin>>S[i];
  get_pen_from_sub_mask=vi(N,0);
  rep(i,1,k){
    int mask=0;
    for(auto j:S[i]){
      mask|=(1LL<<(j-'a'));
    }
    // get_pen_from_sub_mask[mask]=i;
    // for (int s=mask; s; s=(s-1)&mask){
    //   if(get_pen_from_sub_mask[s]==0)get_pen_from_sub_mask[s]=i;
    // }
    f(mask,i);
  }
  vpii ans;int cnt=0,l=0;
  int mask=0;
  rep(i,0,n-1){
    mask|=(1LL<<(s[i]-'a'));
    if(get_pen_from_sub_mask[mask]==0){
      ans.pb(cnt,i-1);
      mask=(1LL<<(s[i]-'a'));
    }
    cnt=get_pen_from_sub_mask[mask];
  }
  ans.pb(cnt,n-1);
  rep(i,0,n-1){
    cout<<ans[l].F<<" ";
    if(i==ans[l].S)l++;
  }
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  /*,cout<<"\n"*/;
  // cout<<"\n";
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<":\n"*/;solve();cout<<"\n";}
  return 0;
}