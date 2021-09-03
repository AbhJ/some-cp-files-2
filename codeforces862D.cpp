//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 02 in 18 : 57 : 24
//title - D_Mahmoud_and_Ehab_and_the_binary_string.cpp
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
int n, o, one, zero;map<pii, int>m;
int f(int l, int r){
	if(m.count(pii{l, r}))return m[pii{l, r}];
	cout << "? " << string(l - 1, '0') << string(r - l + 1, '1') << string(n - r, '0');
	cout << "\n";
	cout.flush();
	cin >> m[pii{l, r}];
	cout.flush();
	return m[pii{l, r}] = o - m[pii{l, r}];
}
void solve(){
	cin >> n;
	cout.flush();
	int l = 1, r = n, m;
	cout << "? " << string(n, '0');
	cout << "\n";
	cout.flush();
	cin >> o;
	cout.flush();
	while(one == 0 or zero == 0){
		m = ((l + r) >> 1);
		if(f(l, m) == m - l + 1){
			one = m;
			l = m + 1;
		}
		else {
			if(f(l, m) == l - m - 1)
				zero = m,
				l = m + 1;
			else
				r = m;
		}
	}
	cout << "! " << zero << " " << one;
	cout.flush();
}
int32_t main()
{
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}