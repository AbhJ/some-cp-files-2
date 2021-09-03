//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 04 in 12 : 51 : 08
//title - C_Floor_and_Mod.cpp
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
const int N=1e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
// (1 / 27) * 5
int a, b, ans;
void solve1(){
	cin >> a >> b;
	ans = 0;
	rep(r, 1, N - 1){
		int bs_possible = min(a / r - 1, b);
		//remove r bs that are <= r
		bs_possible -= r;
		if(bs_possible > 0)
			ans += bs_possible;
	}
	cout << ans;
}
void solve2(){
	cin >> a >> b;
	ans = 0;
	rep(r, 1, N - 1){
		//r means every b' in the range has
		//atleast r possible as
		//also
		//r is maximum r such that every b' in the range
		//shows atleast some r' * (b' + 1) <= a
		//where r <= r'
		//where b' <= b
		int L = r + 1,
		//lowest b possible is r + 1
		R = b + 1, m;
		if(R - L < 1)
			continue;
		//I want to maximise b' == R
		while(R - L > 1){
			m = (L + R >> 1);
			if((m + 1) * r <= a)
				L = m;
			else
				R = m;
		}
		// cout << L;
		if((L + 1) * r <= a)
			ans += (L - (r + 1) + 1);
	}
	cout << ans;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;
  	if(rand() & 1)
	  	solve1();
	else
		solve2();
	cout<<"\n";
  }
  return 0;
}