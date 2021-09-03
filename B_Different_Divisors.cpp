//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 19 in 21 : 09 : 28
//title - B_Different_Divisors.cpp
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
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
vi prim;int p[N];
void gen_primes(const int N) {
  int i,j;
  for(i=0;i<1e6+1;i++) p[i] = 1;
  for(i=2;i<=(int)sqrt(1e6+1);i++)
  if (p[i])
  for(j=i;j*i<1e6+1;j++) p[i*j] = 0;
  rep(i, 2, 1e6+1 - 1)if(p[i] == 1)prim.pb(i);
}
void solve(){
	int x;
	cin >> x;
	cout << *upper_bound(all(prim), x) * *lower_bound(all(prim), x + *upper_bound(all(prim), x));
}
int32_t main()
{
  ibs;cti;
  gen_primes(N);
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}