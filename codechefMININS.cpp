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
int n,a[N];
void F(){
  for(int i=2;i<n+1;i++)cout<<ceil((double)(n)/(i-1))<<" ";
}
void solve(){
  cin>>n;
  rep(i,0,n-1)cin>>a[i];
  vi v;
  int f=0;
  rep(i,0,n-1){
    if((__gcd(a[i],a[(i+1)%n]))==1)f=1;
  }
  if(f==0){F();return;}
  rep(i,0,n-1){
    if(i==0 or (__gcd(a[i],a[(i+n-1)%n]))==1){
      v.pb(1);
    }
    else v[v.size()-1]++;
  }
  if(__gcd(a[0],a[n-1])!=1)
    v[v.size()-1]+=v[0],v.erase(v.begin()+0);
  vi ans(n-1,0);
  sort(all(v),greater<int>());
  for(auto &j:v){
    rep(i,2,j){
      ans[i-2]+=ceil((double)(j)/(i-1))-1;
    }
  }
  for(auto &i:ans)cout<<i<<" ";
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}