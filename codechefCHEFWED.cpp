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
const int N=1e3+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int a[N],n,k;vvi f,dp,cnt;
int F(int l=1,int r=n){
  int cost=cnt[l][r];
  if(l==r)return 0;
  if(dp[l][r]!=-1)return dp[l][r];
  rep(i,l,r-1){
    int c1=dp[l][i],c2=dp[i+1][r];
    if(c1==-1)c1=F(l,i);
    if(c2==-1)c2=F(i+1,r);
    cost=min(cost,k+c1+c2);
  }
  return dp[l][r]=cost;
}
void solv(){
  //k==1
  rep(i,1,n)cin>>a[i];
  int ma=*max_element(a+1,a+1+n);
  vi f(ma+1,0);
  int cnt=1,c=0;
  rep(i,1,n){
    f[a[i]]++;
    if(f[a[i]]==2)f=vi(ma+1,0),cnt++,f[a[i]]=1;
  }
  f= vi(ma+1,0);
  rep(i,1,n)f[a[i]]++;
  rep(i,1,100)if(f[i]>1)c+=f[i];
  cout<<min(cnt,c+1);
}

void solver(){
  //large input
  cin>>k;
  if(k==1){solv();return;}
  rep(i,1,n)cin>>a[i];int ma=*max_element(a+1,a+1+n);
  // dp=vvi(n+1,vi(n+1,0));
  cnt=vvi(n+1,vi(n+1,0));
  rep(i,1,n){
    //starting at i
    vi f(ma+1,0);
    rep(j,i,n)f[a[j]]++;
    rep(j,1,ma)if(f[j]>1)cnt[i][n]+=f[j];
    per(j,n-1,i){
      if(f[a[j+1]]==2)
        cnt[i][j]=cnt[i][j+1]-2;
      else if(f[a[j+1]]==1)
        cnt[i][j]=cnt[i][j+1];
      else cnt[i][j]=cnt[i][j+1]-1;
      f[a[j+1]]--;
    }
  }
  // rep(l,2,n)
  //   rep(i,1,n){
  //     int j=i+l-1;
  //     if(j>n)break;
  //     dp[i][j]=min(dp[i][j-1]+(cnt[i][j]-cnt[i][j-1]),
  //               k+dp[i][j-1]);
  //   }
  // cout<<k+dp[1][n];
  vi dp(n+1,1e18);
  dp[0]=0;
  rep(i,2,n){
  	rep(j,1,i-1){
  		int cost=dp[j-1]+cnt[j][i]+k;
  		dp[i]=min(dp[i],cost);
  	}
  }
  cout<<dp[n];
}
//7 15
void solve(){
  //O(n*n*n)
  cin>>n;
  if(n>800)
  {solver();return;}
  cin>>k;
  rep(i,1,n)cin>>a[i];int ma=*max_element(a+1,a+1+n);
  dp=vvi(n+1,vi(n+1,-1));
  cnt=vvi(n+1,vi(n+1,0));
  rep(i,1,n){
    //starting at i
    vi f(ma+1,0);
    rep(j,i,n)f[a[j]]++;
    rep(j,1,ma)if(f[j]>1)cnt[i][n]+=f[j];
    per(j,n-1,i){
      if(f[a[j+1]]==2)
        cnt[i][j]=cnt[i][j+1]-2;
      else if(f[a[j+1]]==1)
        cnt[i][j]=cnt[i][j+1];
      else cnt[i][j]=cnt[i][j+1]-1;
      f[a[j+1]]--;
    }
  }
  cout<<k+F();
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