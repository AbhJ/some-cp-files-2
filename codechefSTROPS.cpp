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
const int N=20 + 10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, ans;string s;
int f(string a, string b){
	int n = a.length();
	if(b.length() != a.length())return 0;
	vvi dp(n + 1, vi(n + 1)), op(n + 1, vi(n + 1));
	vi pa(n + 1), pb(n + 1);
	a = '#' + a;
	b = '#' + b;
	rep(i, 1, n){
		pa[i] = pa[i - 1] + a[i] - '0';
		pb[i] = pb[i - 1] + b[i] - '0';
		if(a[i] == b[i]){
            op[i][i] = 1;
		    dp[i][i] = 1;
        }
	}
    if(pa[n] != pb[n])return 0;
	rep(l, 2, n)
		rep(i, 1, n){
			int j = i + l - 1;
			if(j >= n + 1)break;
			if(op[i + 1][j - 1] or i + 1 == j){
				op[i][j] = ((a[i] == b[j]) and (b[i] == a[j]));
			}
		}
	rep(l, 2, n)
		rep(i, 1, n){
			int j = i + l - 1;
			if(j >= n + 1)break;
			dp[i][j] = ((op[i][j]) and ((pa[j] - pa[i - 1]) & 1 ^ 1))
						or
					   (dp[i + 1][j] and (a[i] == b[i]))
					   	or
					   (dp[i][j - 1] and (a[j] == b[j])); 
		}
	return dp[1][n];
}
void solve(){
	cin >> s;
	n = s.length();
	s = '#' + s;
	vi pa(n + 1);
	rep(i, 1, n){
		pa[i] = pa[i - 1] + s[i] - '0';
	}
	ans = 0;
	int ans = 0, tmp = 0;
	rep(len, 1, n){
		set<string>se;
		rep(i, 1, n){
			int F = 0;
			if(i + len - 1 >= n + 1)break;
			for(auto &st: se){
				if(f(st, s.substr(i, len))){
					F = 1;break;
				}
			}
			if(F == 0){
				se.insert(s.substr(i, len));
			}
		}
        ans += se.size();
	}
	cout << ans;
}
int32_t main()
{
  ibs;cti;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}