//Coded by Abhijay Mitra (AbJ) on 2021 / 03 / 06 in 12 : 28 : 47
//title - D_TV_Shows.cpp
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
// const double Pi = M_PI;
#define F first
#define S second
int n, x, y, taka;vpii v;
class inter{
	public:
	int l, r, id;
	void input(int x, int y, int i){
		l = x, r = y, id = i;
	}
};
class cmp{
	public:
	bool operator()(const inter &a, const inter &b){
		return a.l < b.l;
	}
};
int mul(int a,int b){
  return ((a)*(b))%M;
}
int add(int a,int b){
  a+=b;
  if(a>=M)a-=M;
  return a;
}
void solve(){
	cin >> n >> x >> y;
	inter a[n];
	rep(i, 0, n - 1){
		int A, B;
		cin >> A >> B;
		a[i].input(A, B, i);
	}
	cmp ok;
	sort(a, a + n, ok);
	multiset<int>s;
	s.insert(a[0].r);
	taka = add(x, mul(y, (a[0].r - a[0].l)));
	rep(i, 1, n - 1){
		int tmp;
		if(*s.begin() >= a[i].l)
			tmp = add(x, mul(y, (a[i].r - a[i].l)));
		if(*s.begin() < a[i].l){
			int r1 = *prev(s.lower_bound(a[i].l));
			if((a[i].l - r1) * y < x){
				tmp = mul(a[i].r - r1, y);
				s.erase(prev(s.lower_bound(a[i].l)));
			}
			else
				tmp = add(x, mul(y, (a[i].r - a[i].l)));
		}
		taka = add(tmp, taka);
		s.insert(a[i].r);
	}
	cout << taka;
}
int32_t main()
{
  ibs;cti;
  solve();return 0;
  int xx=0;
  int t;cin>>t;while(t--){/*xx++;cout<<"Case "<<xx<<": "*/;solve();cout<<"\n";}
  return 0;
}