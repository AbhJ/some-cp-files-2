//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 21 in 02 : 34 : 31
//title - E_Don_t_Be_a_Subsequence.cpp
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
const int N=2e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
string s;int n, dp[50][N];
int f(string str1, string str2, int m, int n){
	if(m == - 1)return 1;
	if(n == - 1)return 0;
	if(dp[m][n] != - 1)return dp[m][n];
	return dp[m][n] = (str1[m] == str2[n] ? f(str1, str2, m - 1, n - 1) : f(str1, str2, m, n - 1));
}
int ok(string a){
	memset(dp, - 1, sizeof(dp));
	return f(a, s, a.length() - 1, n - 1);
}
bitset<26>tmp, mask[N / 26][26];
int comp_set, print_a[N], t;
void solve(){
	cin >> s;
	n = s.length();
	per(i, n - 1, 0){
		mask[t][s[i] - 'a'] = tmp;
		bitset<26>old = tmp;
		tmp[s[i] - 'a'] = 1;
		//mask [t][s[i] - 'a'] means what was the
		// conditon of the previous
		// mask before s[i - 'a'] entered in the t th full sets
		if(tmp.to_ullong() + 1LL == (1LL << 26)){
			t += 1;
			tmp = bitset<26>(0);
		}
	}
	string ans;
	while(t != - 1){
		int last_charac;
		if(print_a[t] == 1)ans += 'a', last_charac = 'a';
		else {
			rep(i, 0, 25){
				if(tmp[i] == 0){
					ans += (char)('a' + i);
					last_charac = (char)('a' + i);
					break;
				}
			}
		}
		tmp = mask[t - 1][last_charac - 'a'];
		t--;
	}
	cout << ans;

}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}