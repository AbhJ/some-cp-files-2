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
#define deb(k) cout<<endl<<"["<<#k<<" = "<<k<<"]"<<endl;
using vi = std::vector<int>;
using vvi = std::vector<vi>;
using pii = std::pair<int,int>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(k)     k.begin(), k.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, k, a[N];
void solve(){
  cin >> n >> k;
  rep(i, 1, n)cin >> a[i];
  rep(i, 1, n){
	  if(k == 0)break;
	  k--;
	  int lg = log2(a[i]);
	  a[i] ^= (1 << lg);
	  int ok = 0;
	  rep(j, i + 1, n)
	  	if((a[j] ^ (1 << lg)) < a[j]){
		  	a[j] ^= (1 << lg),
			ok = 1;
			break;
		}
	  if(ok == 0)a[n] ^= (1 << lg);
	//   int j = i;
	  while(a[i] <= 0 and i != n)i++;
	//   if(j != i)
  }
if(k & 1 == 0 and n <= 2)
		a[n] ^= 1 << 0, a[n - 1] ^= 1 << 0;
  	rep(i, 1, n)cout << a[i] << " ";
}
int32_t main()
{
  ibs;cti;
  // solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}