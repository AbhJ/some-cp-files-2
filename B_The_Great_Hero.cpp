//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 07 in 20 : 06 : 43
//title - B_The_Great_Hero.cpp
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
const double Pi = 3.14159265;
#define F first
#define S second
int A, B, n, a[N], b[N], p[N];
bool cmp(int x, int y){
	return a[x] < a[y];
}
void solve(){
	cin >> A >> B >> n;
	rep(i, 1, n)cin >> a[i];
	rep(i, 1, n)cin >> b[i];
	iota(p + 1, p + 1 + n, 1);
	sort(p + 1, p + 1 + n, cmp);
	rep(pos, 1, n){
		int i = p[pos];
		int fight = (b[i] + A - 1) / A;
		if((B + a[i] - 1) / a[i] >= fight and B > 0)
			B -= fight * a[i],
			b[i] = 0;
	}
	rep(i, 1, n){
		if(b[i] > 0){
			cout << "NO";
			return;
		}
	}
	cout << "YES";
	return;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}