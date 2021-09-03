//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 03 in 21 : 06 : 14
//title - C_1D_Sokoban.cpp
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
int n, m, x;
int f(vi box, vi pos, set<int>sp){
	if(box.empty() or pos.empty())
		return 0;
	vi su((int)box.size() + 1);
	int ans = 0;
	su[(int)box.size() - 1] = sp.count(box[(int)box.size() - 1]);
	per(i, (int)box.size() - 2, 0){
		su[i] = su[i + 1] + (sp.count(box[i]) == 1);
	}
	int cnt_box = 0,last_pos = 0;
	rep(i, 0, (int)pos.size() - 1){
		while(cnt_box <= (int)box.size() - 1 and box[cnt_box] <= pos[i] + cnt_box)
			cnt_box++;
		while(last_pos <= (int)pos.size() - 1 and pos[last_pos] < pos[i] + cnt_box)
			last_pos++;
		ans = max(ans, last_pos - i + su[cnt_box]);
	}
		//j is last box taken
	return ans;
}
void solve(){
	cin >> n >> m;
	vi l_box, r_box, l_pos, r_pos;
	set<int>spr, spl;
	rep(i, 1, n){
		cin >> x;
		if(x < 0)
			l_box.pb(- x);
		if(x > 0)
			r_box.pb(x);
	}
	rep(i, 1, m){
		cin >> x;
		if(x < 0)
			l_pos.pb(- x),
			spl.insert(- x);
		if(x > 0)
			r_pos.pb(x),
			spr.insert(x);
	}
	reverse(all(l_box));
	reverse(all(l_pos));
	cout << f(l_box, l_pos, spl) + f(r_box, r_pos, spr);
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}