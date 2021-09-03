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
const int N=2e6;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n,dp[N],F[N],p[N];
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
int mul1(int a,int b){
  return ((a)*(b));
}
int add1(int a,int b){
  a+=b;
  // if(a>=M)a-=M;
  return a;
}
ll sub1(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
int f(int n){
  int pos=(lower_bound(p,p+N,n)-p);
  int ans=0;
  if(pos!=0)ans=add(ans,F[pos-1]);
  //we were to take n<=p[pos]
  ans=add(ans,mul(mul((n-p[pos-1]),pos),pos));
  return ans;
}
int solve(int z){
  int left,right;
  cin>>left;cin>>right;
  cout<<sub(f(right),f(left-1));
  return -1;
}
int32_t main()
{
  ibs;cti;
  dp[1]=F[1]=p[1]=1;
  F[-1]=0;
  rep(i,2,N-1){
    dp[i]=1+dp[i-dp[dp[i-1]]];
    p[i]=p[i-1]+dp[i];
    F[i]=add(F[i-1],add(0,mul(i,mul(i,dp[i]))));
  }
  int xx=0;
  // int t;t=3e6;while(t--){xx++;f(xx);cout<<endl;}
  int t;cin>>t;while(t--){ /*cout<<*/solve(xx);cout<<endl;}
  return 0;
}