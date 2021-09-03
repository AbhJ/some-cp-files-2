//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 19 in 23 : 21 : 05
//title - B_Sad_powers.cpp
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
set<int> s, not_s;vi tot;
void powerNumbers(){
    rep(i, 2, N - 1){
		s.insert(i * i);
		if(s.count(i) != 0)
			continue;
		int tmp = i;
		while(i * i <= N * N * N / tmp)
			tmp *= i * i,
			not_s.insert(tmp);
	}
	for(auto &j: not_s)
		tot.pb(j);
}
int l, r;
void solve(){
	cin >> l >> r;
	cout << upper_bound(all(tot), r) - lower_bound(all(tot), l) + (int)sqrt(r) - (int)sqrt(l - 1);
}
int32_t main()
{
  ibs;cti;
  powerNumbers();
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}