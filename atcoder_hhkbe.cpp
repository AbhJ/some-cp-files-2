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
const int N=2e3+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int h,w,dp[4][N][N];string s[N];
int f[N*N],on;
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
main(){
	cin>>h>>w;
	rep(i,0,h-1)cin>>s[i];
  rep(i,0,h-1)
		rep(j,0,w-1)
      on+=(s[i][j]=='.');
	rep(i,0,h-1)
		rep(j,0,w-1){
			if(i!=0)dp[0][i][j]=dp[0][i-1][j];
      dp[0][i][j]+=(s[i][j]=='.');
			if(s[i][j]=='#')dp[0][i][j]=0;
		}
  per(i,h-1,0)
		rep(j,0,w-1){
			if(i!=h-1)dp[1][i][j]=dp[1][i+1][j];
      dp[1][i][j]+=(s[i][j]=='.');
			if(s[i][j]=='#')dp[1][i][j]=0;
		}
  rep(i,0,h-1)
		per(j,w-1,0){
			if(j!=w-1)dp[2][i][j]=dp[2][i][j+1];
      dp[2][i][j]+=(s[i][j]=='.');
			if(s[i][j]=='#')dp[2][i][j]=0;
		}
  per(i,h-1,0)
		rep(j,0,w-1){
			if(j!=0)dp[3][i][j]=dp[3][i][j-1];
      dp[3][i][j]+=(s[i][j]=='.');
			if(s[i][j]=='#')dp[3][i][j]=0;
		}
  int ans=0;
  rep(i,0,h-1){
    rep(j,0,w-1){
      int cnt=0;
      cnt+=dp[0][i][j];
      cnt+=dp[1][i][j];
      cnt+=dp[2][i][j];
      cnt+=dp[3][i][j];
      cnt-=3;
      if(f[cnt]==0)f[cnt]=add(0LL,mul((powM(2,cnt)-1),powM(2,(on-cnt))));
      else f[cnt]=add(f[cnt],mul((powM(2,cnt)-1),(powM(2,on-cnt))));
    }
  }
  rep(i,0,N*N-1)if(f[i])ans=add(ans,(f[i]));
  cout<<ans;
  return 0;
}