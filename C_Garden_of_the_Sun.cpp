//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 25 in 11 : 37 : 49
//title - C_Garden_of_the_Sun.cpp
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
const int N=5e2+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, m, a[N][N];char c[N][N];
void printer(){
	rep(i, 0, n - 1){
		rep(j, 0, m - 1)
			cout << c[i][j];
		cout << "\n";
	}
}
void solve(){
	cin >> n >> m;
	if(n == 1){
		cout << string(m, 'X') + "\n";
	}
	rep(i, 0, n - 1)
		cin >> c[i];
	if(n == 1)
		return;
	rep(j, 0, m / 3){
		int col = (j * 3) + (m % 3 == 0);
		rep(i, 0, n - 1)
			c[i][col] = 'X';
		if(col + 2 < m){
			int ok = 0;
			if(!(c[1][col + 1] == '.' and c[1][col + 2] == '.'))
				c[1][col + 1] = c[1][col + 2] = 'X';
			else
				c[0][col + 1] = c[0][col + 2] = 'X';
		}
	}
	printer();
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case X"<<xx<<": "*/;solve();}
  return 0;
}