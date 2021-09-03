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
const int N=2e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,a[N],b[N],dp[N];pii pos[N];
//pos type
//enter 1
//exit 0
//-1
bool possible(int L,int R){
  int k=(R-L+1)/2;
  //k+1 length of interval per i
  rep(i,L,R){
    int j=i+k;
    if(j>R)break;
    if(pos[i].F!=pos[j].F and pos[i].S!=-1 and pos[j].S!=-1)return 0;
    if(pos[j].S==1)return 0;
    if(pos[i].S==0)return 0;
  }
  return 1;
}
int solve(){
  cin>>n;fill(pos,pos+N,pii(0,-1));
  rep(i,1,n)cin>>a[i]>>b[i];
  rep(i,1,n){
    if(a[i]!=-1){
      if(pos[a[i]].F!=0)return 0;
      pos[a[i]]={i,1};
    }
    if(b[i]!=-1){
      if(pos[b[i]].F!=0)return 0;
      pos[b[i]]={i,0};
    }
    if(a[i]!=-1 and b[i]!=-1 and a[i]>=b[i])return 0;
  }
  //R is ending pos
  dp[0]=1;
  rep(R,2,2*n){
    per(L,R-1,1){
      if(dp[L-1] and possible(L,R)){dp[R]=1;break;}
    }
  }
  return dp[2*n];
}
int32_t main()
{
  ibs;cti;
  solve()?(cout<<"Yes"):(cout<<"No");return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}