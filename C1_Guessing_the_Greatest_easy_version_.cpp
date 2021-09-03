//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 18 in 20 : 27 : 58
//title - C1_Guessing_the_Greatest_easy_version_.cpp
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
int n;map<pii, int>a;
int q(int l, int r){
	if(l == r)return inf;
	if(a.count(pii{l, r}))return a[pii{l, r}];
	cout << "? " << l << " " << r << "\n";
	cout.flush();
	cin >> a[pii{l, r}];
	cout.flush();
	return a[pii{l, r}];
}
void solve(){
	cin >> n;
	int l = 1, r = n, bam = 0;
	if(q(1, q(1, n)) == q(1, n))r = q(1, n), bam = 1;
	else l = q(1, n);
	if(q(1, n) == 1)l = q(1, n);
	//ba hate khela
	if(bam == 1){
		while(r - l > 1){
			int m = ((l + r) >> 1);
			if(q(m, q(1, n)) == q(1, n))l = m;
			else r = m;
		}
		cout << "! " << l;
		cout.flush();
	}
	//dan hate khela
	else {
		while(r - l > 1){
			int m = ((l + r) >> 1);
			if(q(q(1, n), m) == q(1, n))r = m;
			else l = m;
		}
		cout << "! " << r;
		cout.flush();
	}
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}