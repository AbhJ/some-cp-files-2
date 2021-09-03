//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 30 in 12 : 38 : 54
//title - C_Multiple_Sequences.cpp
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
#include <bits/stdc++.h>
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
const int N=4e5+10;
const int inf = /*0x3f3f3f3f*/1e18+10;
const ll M = 998244353 ; // Mulo
// const int M = 1e9+7 ; // Mulo
// const double Pi = M_PI;
#define F first
#define S second
int f[N], b[N], n, m, ans = 0, tmp = 1, g[N];vvi v;
int F(int v, int d){
	int cnt = 0;
	while(v % d == 0)
		v /= d, cnt++;
	return cnt;
}
vvi prime_vector_sieve(){
  vvi prime(N);
  for(int i = 2;i < N; ++i)if(prime[i].empty())
        for(int j = i; j < N; j += i){
            prime[j].push_back(F(j, i)),
			g[j] *= pow(i, j / i);
        }
  return prime;
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
ll powM(ll b, int p) {
  ll r=1;
  for(; p; b=b*b%M, p/=2)
    if(p&1)
      r=r*b%M;
  return r;
}
void calc_fact(){
  f[0]=b[0]=1;
  rep(i,1,N-1){
    f[i]=mul(f[i-1],i);
    b[i]=powM(f[i],M-2);
  }
}
int C(int n,int r){
  assert(n<N);assert(r<N);
  if(r>n)return 0;
  return (f[n]*mul(b[r],b[n-r])%M)%M;
}
void solve(){
	cin >> n >> m;
	rep(i, 1, m){
			int x = i, cnt = 0;
			rep(j, 2, sqrt(x)){
				if(x % j != 0)
					continue;
				while(x % j == 0)
					cnt++, x /= j;
				tmp = mul(tmp, C(n + cnt - 1, cnt));
				cnt = 0;
			}
			ans = add(ans, mul(tmp, (x != 1 ? C(n + 1 - 1, 1) : 1)));
			tmp = 1;
	}
	cout << ans;
	ans = 0;
}
int32_t main()
{
  ibs;cti;
  memset(g, 1, sizeof g);
  v = prime_vector_sieve();
  calc_fact();
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case #"<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}