//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 25 in 08 : 43 : 15
//title - Prime_Tuples.cpp
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
int p[N], ans[N];
vi a;
void gen_primes() {
  for(int i=0;i<N;i++){
    p[i]=true;
  }
  p[0]=false;
  p[1]=false;
  for(int j=2;j*j<N;j++){
    if(p[j]){
      for(int i=j*j;i<N;i+=j){
        p[i]=false;
      }
    }
  }
  rep(i, 2, N - 1)if(p[i] == 1)a.pb(i);
  rep(i, 2, N - 1){
	  if(p[i] and p[i - 2])ans[i] = ans[i - 1] + 1;
	  else ans[i] = ans[i - 1];
  }
}
void solve(int n){
	cout << ans[n];
}
int32_t main()
{
  ibs;cti;
  gen_primes();
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){int n;cin >> n;/*xx++;cout<<"Case "<<xx<<": "*/;solve(n);cout<<endl;}
  return 0;
}