//Coded by Abhijay Mitra (AbJ) on 2021 / 01 / 20 in 00 : 35 : 10
//title - C_Array_Destruction.cpp
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
int n, a[N];
multiset<int>S;
int f(int fir){
	S.erase(S.find(fir));
	int x = a[max_element(a + 1, a + 1 + 2 * n) - a];
	while(S.empty() == 0){
		int large = *S.rbegin();
		S.erase(prev(S.end()));
		int other = x - large;
		if(S.count(other) == 0)
			return 0;
		S.erase(S.find(other));
		x = large;
	}
	return 1;
}
void ok(int rem){
	rep(i, 2, n){
		cout << "\n" << *S.rbegin() << " " << rem - *S.rbegin();
		int z = rem - *S.rbegin();
		rem = *S.rbegin();
		S.erase(prev(S.end())), S.erase(S.find(z));
	}
}
void solve(){
	cin >> n;
	rep(i, 1, 2 * n)cin >> a[i];
	multiset<int>s;
	rep(i, 1, 2 * n)if(i != (max_element(a + 1, a + 1 + 2 * n) - a))s.insert(a[i]);
	S = s;
	rep(i, 1, 2 * n)if(i != (max_element(a + 1, a + 1 + 2 * n) - a)){
		if(f(a[i])){
			S = s;
			cout << "YES\n";
			S.insert(*max_element(a + 1, a + 1 + 2 * n));
			cout << *S.rbegin() + a[i] << "\n" << *S.rbegin() << " " << a[i];
			S.erase(prev(S.end())), S.erase(S.find(a[i]));
			ok(*max_element(a + 1, a + 1 + 2 * n));
			return;
		}
		S = s;
	}
	cout << "NO";
}
int32_t main()
{
  ibs;cti;
//   solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}