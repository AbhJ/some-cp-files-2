//Coded by Abhijay Mitra (AbJ) on 2021 / 04 / 04 in 04 : 54 : 28
//title - C_Balance_the_Bits.cpp
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
#define all(x) x.begin(), x.end()
using namespace std;
const int N=2e6+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
// const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int n, c0, c1, tmp;string a, b, s1, s2;
int pos(string s){
	rep(i, 0, n - 1)
		if(s[i] == '(')
			tmp++;
		else{
			tmp--;
			if(tmp < 0){
				tmp = 0;
				return 0;
			}
		}
	if(tmp != 0){
		tmp = 0;
		return 0;
	}
	return 1;
}
void solve(){
	cin >> n >> a;
	rep(i, 0, n - 1){
		if(a[i] == '0'){
			if(c0)
				s1 += ')',
				s2 += '(';
			else
				s2 += ')',
				s1 += '(';
			c0 ^= 1;
		}
		else{
			if(i == n - 1 or (c1 == 0 and i != 0)){
				s1 += ')',
				s2 += ')';
			}
			else{
				s1 += '(',
				s2 += '(';
			}
			c1 ^= 1;
		}
	}
	if(pos(s1) and pos(s2))
		cout << "YES\n" << s1 << "\n" << s2;
	else
		cout << "NO";
	s1.clear(), s2.clear();
	c1 = 0, c0 = 0;
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}