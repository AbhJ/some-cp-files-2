//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 21 in 19 : 20 : 04
//title - B_AGAGA_XOOORRR.cpp
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// int pos = uniform_int_distribution<int>(l,r)(rng);
#define mp         make_pair
#define rep(i,a,b) for (int i = a; i <= b; i++)
#define per(i,b,a) for (int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N], f[30], cn, pre[N], suf[N];
void solve(){
	cin >> n;
	rep(i, 0, n - 1)
		cin >> a[i];
	rep(i, 0, n - 1)
		pre[i] = pre[i - 1] ^ a[i];
	per(i, n - 1, 0)
		suf[i] = suf[i + 1] ^ a[i];
	rep(i, 0, n - 1)
		rep(j, i + 1, n - 1){
		int bam = pre[i], xo = pre[j - 1] ^ pre[i], dan = suf[j], dan_prime = xo ^ dan, bam_prime = bam ^ xo;
		if(bam == xo and xo == dan or bam == dan_prime or bam_prime == dan){
			cout << "YES";
			return;
		}
	}
	cout << "NO";
	return;
}
int32_t main()
{
  ibs;cti;
  pre[- 1] = 0;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}