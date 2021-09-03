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
int n, a[N], k;
void solve(){
	vector<queue<int>>v(32);
	priority_queue<pii>q;
	cin >> n;cin >> k;
	rep(i, 1, n)cin >> a[i];
	rep(i, 1, n)rep(j, 0, 31)if((1 << j) & a[i])v[j].push(i);
	rep(j, 1, n)
		per(i, 31, 0)if(v[i].empty() == 0 and v[i].front() == j){
			while(!(v[i].size() < 2) and k != 0){
				// cout << 1;
				k--;
				v[i].pop();
				v[i].pop();
			}
			if(v[i].size() == 1 and v[i].front() != n and k != 0){
				v[i].pop();
				v[i].push(n);
				// cout << -2;
				k--;
			}
			if(k == 0)break;
	}
	rep(i, 1, n)a[i] = 0;
	rep(i, 0, 31){
		while(v[i].empty() == 0)
			a[v[i].front()] |= 1 << i,
			v[i].pop();
    }
	int cn = 0;
	rep(i, 1, n)cn += !!a[i];
	if((k & 1) == 1 and cn == 1){
		a[n] ^= 1;
		a[n - 1] ^= 1;
		rep(i, 1, n)cout << a[i] << " ";
		return;
	}
  	rep(i, 1, n)cout << a[i] << " ";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}