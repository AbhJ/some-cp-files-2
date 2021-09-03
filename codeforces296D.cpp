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
int n,d[N];vvi A,a;
int mul(int a,int b){
  return ((a)*(b));
}
int add(int a,int b){
  a+=b;
  // if(a>=M)a-=M;
  return a;
}
vvi p(vvi a,vvi b){
  vvi x=b;
  rep(i,0,n-1)
    rep(j,0,n-1)
      rep(k,0,n-1)
        x[i][j]=min(x[i][j],add(a[i][k],b[k][j]));
  return x;
}
// vvi a;
//this return pow(A,x) where A is matrix
vvi matrix_power_final(vvi A, int x){
  vvi result(n,vi(n,0));
  rep(i,0,n-1)result[i][i]=1;
  while(x){
    if (x&1)result = p(result , A);
    A = p(A , A);
    x = x / 2;
  }
  return result;
}
int cnt=1,ans;
int f(vvi A){
  vvi a=matrix_power_final(A,n);
  int an=0;
  rep(i,0,n-1)
    rep(j,0,n-1)if(a[i][j]!=inf and i!=j)
      an+=a[i][j];
  // rep(i,0,n-1){
  //   rep(j,0,n-1)cout<<a[i][j]<<" ";
  //   cout<<"\n";
  // }
  return an;
}
void solve(){
  cin>>n;A.resize(n);fill(all(A),vi(n,0LL));
  rep(i,0,n-1)
    rep(j,0,n-1)
      cin>>A[i][j];
  stack<int>s;
  rep(i,0,n-1)cin>>d[i];
  per(I,n-1,0){
    ans=0;
    rep(i,0,n-1)
      rep(j,0,n-1)
          A[i][j]=min(A[i][j],add(A[i][d[I]-1],A[d[I]-1][j]));
    rep(i,I,n-1)
      rep(j,I,n-1)
        ans=add(ans,A[d[i]-1][d[j]-1]);
    s.push(ans);
  }
  while(s.empty()==0){cout<<s.top()<<" ";s.pop();}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}