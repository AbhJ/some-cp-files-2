//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 29 in 19 : 03 : 33
//title - C_Nezzar_and_Symmetric_Array.cpp
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
#define rep(i,a,b) for (int i = a; i <= b; i++, i++)
#define per(i,b,a) for (int i = b; i >= a; i--, i--)
#define all(x)     x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;

// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, a[N], b[N], p[N]; map<int, int>m;
void solve(){
	cin >> n;m.clear();
	rep(i, 1, 2 * n)cin >> b[i], m[b[i]]++, i--;
	sort(b + 1, b + 1 + 2 * n);
	int cnt = 1, koto = 2;
	a[2 * n] = p[2 * n] = (b[2 * n]) / (2 * n);
	for(auto &[x, y]: m)if((y & 1) or (x & 1)){
		cout << "NO";
		return;
	}
	// cout << a[2 * n] << " ";
	int last = a[2 * n];
	per(i, 2 * n - 2, 1){
		a[i] = (b[i] - 2 * p[i + 2]) / (2 * n - koto);
		koto += 2;
		if(a[i] >= last){
			cout << "NO";
			return;
		}
		p[i] = p[i + 2] + a[i];
		last = a[i];
		// cout << a[i] << " ";
	}
	per(i, 2 * n, 1){
		if(a[i] < 0 or a[i] == 0){
			cout << "NO";
			return;
		}
	}
	cout << "YES";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}