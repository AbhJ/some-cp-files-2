//Coded by Abhijay Mitra (AbJ) on 2021 / 02 / 10 in 17 : 57 : 05
//title - D_Fafa_and_Ancient_Alphabet.cpp
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
const int M = 1e9+7 ; // Mulo
const double Pi = 3.14159265;
#define F first
#define S second
int n, m, a[N], b[N], ans1 = 0, ans2 = 1;
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
ll sub(ll a,ll b){
  return ((a%M)-(b%M)+M)%M;
}
void solve(){
	cin >> n >> m;
	rep(i, 1, n)cin >> a[i];
	rep(i, 1, n)cin >> b[i];
	rep(i, 1, n){
		if(a[i] == 0 and b[i] != 0){
			//beat
			ans1 = add(ans1, mul(mul(ans2,  m - b[i]), powM(m, M - 2)));
			//ok
			ans2 = mul(ans2, mul(1, powM(m, M - 2)));
		}
		if(a[i] != 0 and b[i] == 0){
			ans1 = add(ans1, mul(mul(ans2, a[i] - 1), powM(m, M - 2)));
			ans2 = mul(ans2, mul(1, powM(m, M - 2)));
		}
		if(a[i] != 0 and b[i] != 0){
			if(a[i] < b[i]){
				ans2 = 0;
			}
			if(a[i] > b[i]){
				ans1 = add(ans1, ans2);
				ans2 = 0;
			}
			if(a[i] == b[i]){

			}
		}
		if(a[i] == 0 and b[i] == 0){
			ans1 = add(ans1, mul(ans2, mul(mul(mul(m, sub(m, 1)), powM(2, M - 2)), powM(mul(m, m), M - 2))));
			ans2 = mul(ans2, mul(1, powM(m, M - 2)));
		}
	}
	cout << ans1;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<endl;}
  return 0;
}