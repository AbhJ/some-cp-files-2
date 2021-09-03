//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 21 in 18 : 55 : 16
//title - B_Restore_Modulo.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, a[N];
void solve(){
	cin >> n;
	rep(i, 1, n)
		cin >> a[i];
	int s = a[1];
	if(*max_element(a + 1, a + 1 + n) == *min_element(a + 1, a + 1 + n)){
		cout << 0;
		return;
	}
	int m = *max_element(a + 1, a + 1 + n) + 1;
	if(n == 1){
		cout << 0;
		return;
	}
	vi v;
	rep(i, 2, n){
		v.pb(a[i] - a[i - 1]);
	}
	int mm = *max_element(all(v)) - *min_element(all(v));
	int d = *max_element(all(v));
	if(mm == 0){
		cout << 0;
		return;
	}
	rep(i, 2, n){
		if(a[i] != ((a[i - 1] + d) % mm)){
			cout << - 1;
			return;
		}
	}
	if(a[1] >= mm){
		cout << - 1;
		return;
	}
	cout << mm << " " << d;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}